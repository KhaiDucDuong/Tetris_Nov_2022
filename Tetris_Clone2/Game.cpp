#include "Game.h"

Game::Game(const int level)
{
	window = NULL;
	render = NULL;

	gameOver = true;
	exitGame = true;
	point = 0;
	this->level = level;
	timeTillDrop = 3000 / fps / (level * 2);
	timePassed = 0;

	music = new Music();
	musicPaths[0] = "res/music/Fly Away.mp3";
	musicPaths[1] = "res/music/New Day.mp3";
	musicPaths[2] = "res/music/Tetris.mp3";
	musicPaths[3] = "res/music/I Really Want to Stay at Your House.mp3";
}

void Game::init()
{
	//init SDL_Video and SDL_Events (SDL_Events is automatically inited when init SDL_Video)
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		std::cout << "Video failed to init!!!\n";
		return;
	}
	else
	{
		window = SDL_CreateWindow("SDL_Tetris", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, ScreenW, ScreenH, NULL);
		if (!window)
		{
			std::cout << "Cannot create window!\n";
			return;
		}
		else
		{
			render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
			if (!render)
			{
				std::cout << "Cannot create renderer!\n";
				return;
			}
		}

		if (TTF_Init() == -1)
			std::cout << "SDL_ttf failed to init!!!\n";

		if (SDL_Init(SDL_INIT_AUDIO) < 0)
			std::cout << "Audio failed to inti!!!\n";
		else
		{
			if (music->loadMusic(musicPaths[0]))
			{
				curSongIndex = 0;
				music->playMusic();
			}
		}	
	}

	gameOver = false;
	exitGame = false;
}

void Game::game_loop()
{
	while (!exitGame)
	{
		game_logic();
		game_rendering();
	}
}

void Game::game_quit()
{
	TTF_Quit();
	Mix_CloseAudio();
	SDL_DestroyRenderer(render);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Game::game_logic()
{
	game_events();
	if (!gameOver)
	{

		if (timePassed == timeTillDrop)
		{
			timePassed = 0;
			_gameState.MoveDown(point);
		}
		else
			timePassed++;

	}

	gameOver = _gameState.getGameOver();
}

void Game::game_restart()
{
	point = 0;
	gameOver = false;
	level = 5;
	resetSpeed();
	_gameState.newGame();
}

void Game::game_rendering()
{
	Image::clearScreen(render);

	drawBackground();
	drawGrid();
	drawUI();

	drawCurBlock();
	drawGridBlock();

	drawNextBlock();
	drawScore();
	drawLevelDifficulty();
	drawMusic();
	drawLogo();

	if (gameOver)
		drawGameOver();
	Image::updateScreen(render);
}

void Game::game_events()
{
	SDL_Event event;

		if (SDL_PollEvent(&event))
		{
			if (!gameOver)
			{
				switch (event.type)
				{
				case SDL_QUIT:
				{
					gameOver = true;
					exitGame = true;
					break;
				}
				case SDL_KEYDOWN:
				{
					switch (event.key.keysym.sym)
					{
					case SDLK_UP:
					{
						_gameState.RotateCW();
						break;
					}
					case SDLK_z:
					{
						_gameState.RotateCCW();
						break;
					}
					case SDLK_DOWN:
					{
						_gameState.MoveDown(point);
						//avoid double drop
						timePassed = 0;
						break;
					}
					case SDLK_LEFT:
					{
						_gameState.MoveLeft();
						break;
					}
					case SDLK_RIGHT:
					{
						_gameState.MoveRight();
						break;
					}
					case SDLK_SPACE:
					{
						_gameState.hardDrop(point);
						break;
					}
					default:
						break;
					}
				}
				case SDL_MOUSEBUTTONDOWN:
				{
					if (event.button.button == SDL_BUTTON_LEFT)
					{
						//check if user clicked on difficulty arrows
						//left arrow
						if (event.button.x >= 435 && event.button.x <= 470 && event.button.y >= 480 && event.button.y <= 515)
						{
							if (level > 1)
							{
								level--;
								resetSpeed();
							}
						}
						//right arrow
						else if (event.button.x >= 490 && event.button.x <= 525 && event.button.y >= 480 && event.button.y <= 515)
						{
							if (level < 15)
							{
								level++;
								resetSpeed();
							}
						}
						//check if user clicked on music UI
						//left arrow
						else if(event.button.x >= 430 && event.button.x <= 460 && event.button.y >= 600 && event.button.y <= 630)
						{
							previousSong();
						}
						//play - pause button
						else if (event.button.x >= 465 && event.button.x <= 495 && event.button.y >= 600 && event.button.y <= 630)
						{
							if (music->isMusicPaused())
								music->resumeMusic();
							else
								music->pauseMusic();
						}
						//right arrow
						else if (event.button.x >= 500 && event.button.x <= 530 && event.button.y >= 600 && event.button.y <= 630)
						{
							nextSong();
						}
					}
				}
				default:
					break;
				}
			}
			else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RETURN)
			{
				game_restart();
			}
			else if (event.type == SDL_QUIT)
			{
				gameOver = true;
				exitGame = true;
			}
		}
	
}

void Game::resetSpeed()
{
	timeTillDrop = 3000 / fps / (level * 2);
	timePassed = 0;
}

void Game::drawUI()
{
	Image::CreateAndDrawTexture(render, UI_path, 160, 720, 400, 20);
}

void Game::drawCurBlock()
{
	//because the display grid only has 20 rows and the grid we created has 22 rows (top 2 rows are used to check if game over - condition is top 2 rows always must be empty)
	//so we don't want to draw any block on the top 2 rows and will only draw them when all of the blocks are located from the third rows upward
	bool draw = true;
	for (int i = 0; i < Block::nTiles; i++)
		if (_gameState.getCurBlockPosition(i).Row < 2)
		{
			draw = false;
			break;
		}

		if(draw)
	{
		int pos_x = 0;
		int pos_y = 0;
		for (int i = 0; i < Block::nTiles; i++)
		{
			pos_x = GridStartPosX + _gameState.getCurBlockPosition(i).Column * BlockW;
			pos_y = GridStartPosY + _gameState.getCurBlockPosition(i).Row * BlockH;
			Image::CreateAndDrawTexture(render, _gameState.getCurBlockFilePath(), BlockW, BlockH, pos_x, pos_y);
		}
	}
	
}

void Game::drawGridBlock()
{
	int pos_x = 0;
	int pos_y = 0;
	int blockID = 0;
	for(int r = 2; r < GameGrid::rows; r++)
		for (int c = 0; c < GameGrid::columns; c++)
		{
			if (_gameState.GetGridValue(r, c) != 0)
			{
				pos_x = GridStartPosX + c * BlockW;
				pos_y = GridStartPosY + r * BlockH;
				blockID = (_gameState.GetGridValue(r, c));
				Image::CreateAndDrawTexture(render, _gameState.getBlockFilePath(blockID), BlockW, BlockH, pos_x, pos_y);
			}
		}
}

void Game::drawNextBlock()
{
	Text::createAndDrawText(render, font_path, fontSize, "Next block:", 100, 75, ScoreStartPosX - 12, 205 - 12);
	int pos_x = 0;
	int pos_y = 0;
	for (int i = 0; i < Block::nTiles; i++)
	{
		pos_x = NextBlockStartPosX + _gameState.getNextBlockPosition(i).Column* UIBlockW;
		pos_y = NextBlockStartPosY + _gameState.getNextBlockPosition(i).Row * UIBlockH;
		if (pos_x >= GridStartPosX && pos_y >= GridStartPosY)
			Image::CreateAndDrawTexture(render, _gameState.getNextBlockFilePath(), UIBlockW, UIBlockH, pos_x, pos_y);
	}
}

void Game::drawGameOver()
{
	SDL_Color color = { 204, 0, 153, 255 };
	Text::createAndDrawText(render, font_path, fontSize, "GAME OVER :(", 300, 200, 140, 205, color);
	Text::createAndDrawText(render, font_path, fontSize, "Press ENTER to play again", 400, 125, 90, 440, color);
}

void Game::drawMusic()
{
	Text::createAndDrawText(render, font_path, fontSize, "Music:", 75, 50, 442, 540);
	Image::CreateAndDrawTexture(render, leftArrow_path, 30, 30, 430, 600);
	Image::CreateAndDrawTexture(render, rightArrow_path, 30, 30, 500, 600);
	Image::CreateAndDrawTexture(render, playButton_path, 30, 30, 465, 600);
}


void Game::drawBackground()
{
	Image::CreateAndDrawTexture(render, bg_path);
}

void Game::drawGrid()
{
	Image::CreateAndDrawTexture(render, grid_path, 360, 720, 20, 20);
}

void Game::drawScore()
{
	Text::createAndDrawText(render, font_path, fontSize, "Score:", 75, 50, ScoreStartPosX, ScoreStartPosY);
	Text::createAndDrawText(render, font_path, fontSize, std::to_string(point) , 105, 55, PointStartPosX, PointStartPosY);
}

void Game::drawLevelDifficulty()
{
	Text::createAndDrawText(render, font_path, fontSize, "Level difficulty:", 100, 50, 430, 360);
	Text::createAndDrawText(render, font_path, fontSize, std::to_string(level), 105, 55, 430, 420);
	Image::CreateAndDrawTexture(render, leftArrow_path, 35, 35, 435, 480);
	Image::CreateAndDrawTexture(render, rightArrow_path, 35, 35, 490, 480);
}

void Game::drawLogo()
{
	Image::CreateAndDrawTexture(render, tetrisLogo_path, 100, 40, 432, 635);
}

void Game::previousSong()
{
	if (curSongIndex == 0)
		curSongIndex = nSongs - 1;
	else
		curSongIndex--;

	music->loadMusic(musicPaths[curSongIndex]);
	music->playMusic();
}

void Game::nextSong()
{
	curSongIndex = (curSongIndex + 1) % nSongs;

	music->loadMusic(musicPaths[curSongIndex]);
	music->playMusic();
}

