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
	timePassed = 0;
	point = 0;
	gameOver = false;
	_gameState.newGame();
}

void Game::game_rendering()
{
	Image::clearScreen(render);
	//draw bg
	drawBackground();
	drawGrid();
	drawUI();

	drawCurBlock();
	drawGridBlock();

	drawNextBlock();
	drawScore();
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
				default:
					break;
				}
			}
			else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RETURN)
			{
				game_restart();
			}
		}
	
}

void Game::drawUI()
{
	Image::CreateAndDrawTexture(render, UI_path, 160, 720, 400, 20);
}

void Game::drawCurBlock()
{
	int pos_x = 0;
	int pos_y = 0;
	for (int i = 0; i < Block::nTiles; i++)
	{
		pos_x = GridStartPosX + _gameState.getCurBlockPosition(i).Column * BlockW;
		pos_y = GridStartPosY + _gameState.getCurBlockPosition(i).Row * BlockH;
		if(pos_x >= GridStartPosX && pos_y >= GridStartPosY)
			Image::CreateAndDrawTexture(render, _gameState.getCurBlockFilePath(), BlockW, BlockH, pos_x, pos_y);
	}
}

void Game::drawGridBlock()
{
	int pos_x = 0;
	int pos_y = 0;
	int blockID = 0;
	for(int r = 0; r < GameGrid::rows; r++)
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
