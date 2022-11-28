#include "Text.h"

bool Text::LoadFont(TTF_Font*& font, const std::string fontPath, int fontSize)
{
	font = NULL;
	font = TTF_OpenFont(fontPath.c_str(), fontSize);
	if (!font)
	{
		std::cout << "Cannot load font " << fontPath << "\n";
		return false;
	}
	return true;
}


void Text::createTextTexture(SDL_Renderer* render, SDL_Texture*& tex, TTF_Font * font, const std::string text, SDL_Color color)
{
	SDL_Surface* surface = NULL;
	surface = TTF_RenderText_Solid(font, text.c_str(), color);
	if (!surface)
	{
		std::cout << "Cannto load surface from font!\n";
	}
	else
	{
		tex = SDL_CreateTextureFromSurface(render, surface);
		if (!tex)
		{
			std::cout << "Cannot create texture from Font " << SDL_GetError() << " !!!\n";
		}
	}

	SDL_FreeSurface(surface);
}

void Text::drawText(SDL_Renderer* render, SDL_Texture* tex, const int& w, const int& h, const int& pos_x, const int& pos_y)
{
	SDL_Rect rect;
	rect.w = w;
	rect.h = h;
	rect.x = pos_x;
	rect.y = pos_y;
	SDL_RenderCopy(render, tex, NULL, &rect);
}

void Text::createAndDrawText(SDL_Renderer* render, const std::string fontPath, int fontSize, const std::string text, const int& w, const int& h, const int& pos_x, const int& pos_y)
{
	TTF_Font *font = NULL;
	SDL_Texture* tex = NULL;

	if (LoadFont(font, fontPath, fontSize))
	{
		Uint8 r = 255;
		Uint8 g = 255;
		Uint8 b = 255;
		Uint8 a = 255;

		SDL_Color color = {r, g, b, a};
		createTextTexture(render, tex, font, text, color);
		drawText(render, tex, w, h, pos_x, pos_y);
	}

	TTF_CloseFont(font);
	SDL_DestroyTexture(tex);
}

void Text::createAndDrawText(SDL_Renderer* render, const std::string fontPath, int fontSize, const std::string text, const int& w, const int& h, const int& pos_x, const int& pos_y, SDL_Color& color)
{
	TTF_Font* font = NULL;
	SDL_Texture* tex = NULL;

	if (LoadFont(font, fontPath, fontSize))
	{
		createTextTexture(render, tex, font, text, color);
		drawText(render, tex, w, h, pos_x, pos_y);
	}

	TTF_CloseFont(font);
	SDL_DestroyTexture(tex);
}
