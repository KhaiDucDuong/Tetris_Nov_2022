#include "Game.h"

Game::Game()
{
	window = NULL;
	render = NULL;
	gameOver = true;

	//_curBlock = _blockQueue.GetandUpdate();
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
	}

	gameOver = false;
}

void Game::game_loop()
{
	while (!gameOver)
	{
		game_logic();
		game_rendering();
	}
}

void Game::game_quit()
{
	SDL_Quit();
}

void Game::game_logic()
{
	game_events();


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

	Image::updateScreen(render);
}

void Game::game_events()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
		{
			gameOver = true;
			break;
		}
		default:
			break;
		}
	}
}

void Game::drawUI()
{
	Image::CreateAndDrawTexture(render, UI_path, 160, 720, 400, 20);
}

void Game::drawCurBlock()
{
	/*for (int i = 0; i < Block::nTiles; i++)
	{
		Image::CreateAndDrawTexture(render, getCurBlockFilePath(), 36, 36, 20, 20);
	}*/
}

void Game::drawGridBlock()
{

}

void Game::drawBackground()
{
	Image::CreateAndDrawTexture(render, bg_path);
}

void Game::drawGrid()
{
	Image::CreateAndDrawTexture(render, grid_path, 360, 720, 20, 20);
}






//void Game::PlaceBlock()
//{
//	for (int i = 0; i < Block::nTiles; i++)
//	{
//		Position pos = _curBlock.GetPosition(i);
//		_grid.SetGridValue(pos.Row, pos.Column, _curBlock.GetId());
//	}
//	_grid.clearRows();
//	if (IsGameOver())
//		gameOver = true;
//	else
//	{
//		_curBlock = _blockQueue.GetandUpdate();
//		//_curBlock.Reset();
//	}
//}
//
//bool Game::IsGameOver()
//{
//	return !(_grid.isRowEmpty(0) && _grid.isRowEmpty(1));
//}
//
//bool Game::blockFit()
//{
//	for (int i = 0; i < Block::nTiles; i++)
//	{
//		Position pos = _curBlock.GetPosition(i);
//		if (!_grid.isInside(pos.Row, pos.Column) || !_grid.isEmpty(pos.Row, pos.Column))
//			return false;
//	}
//	return true;
//}
//
//
//void Game::RotateCW()
//{
//	_curBlock.RotateCW();
//	if (!blockFit())
//		_curBlock.RotateCCW();
//}
//
//void Game::RotateCCW()
//{
//	_curBlock.RotateCCW();
//	if (!blockFit())
//		_curBlock.RotateCW();
//}
//
//void Game::MoveLeft()
//{
//	_curBlock.Move(0, -1);
//	if (!blockFit())
//		_curBlock.Move(0, 1);
//}
//
//void Game::MoveRight()
//{
//	_curBlock.Move(0, 1);
//	if (!blockFit())
//		_curBlock.Move(0, -1);
//}
//
//void Game::MoveDown()
//{
//	_curBlock.Move(1, 0);
//	if (!blockFit())
//		_curBlock.Move(-1, 0);
//}
//
//
//int Game::getCurBlockID()
//{
//	return _curBlock.GetId();
//}
//
//std::string Game::getBlockFilePath(const int id)
//{
//	return _blockQueue.getBlockPath(id);
//}
//
//Position Game::getCurBlockPosition(int tile)
//{
//	return _curBlock.GetPosition(tile);
//}
//
//std::string Game::getCurBlockFilePath()
//{
//	return _blockQueue.getBlockPath(_curBlock.GetId());
//}
