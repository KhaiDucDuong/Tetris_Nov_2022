#pragma once
#include <SDL.h>
#include<SDL_ttf.h>
#include <string>
#include <iostream>
#include "Image.h"

class Text
{
private:
	static bool LoadFont(TTF_Font*& font, const std::string fontPath, int fontSize);
	static void createTextTexture(SDL_Renderer* render, SDL_Texture*& tex, TTF_Font* font, const std::string text, SDL_Color color);
	static void drawText(SDL_Renderer* render, SDL_Texture* tex, const int& w, const int& h, const int& pos_x, const int& pos_y);

public:
	static void createAndDrawText(SDL_Renderer* render, const std::string fontPath, int fontSize, const std::string text, const int& w, const int& h, const int& pos_x, const int& pos_y);
	static void createAndDrawText(SDL_Renderer* render, const std::string fontPath, int fontSize, const std::string text, const int& w, const int& h, const int& pos_x, const int& pos_y, SDL_Color &color);
};

