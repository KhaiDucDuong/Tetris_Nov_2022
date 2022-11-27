#pragma once
#include<SDL.h>
#include <SDL_image.h>
#include <string>

class Image
{
public:
private:
	//use SDL_Surface to load an img file and make an SDL_Texture from SDL_surface
	static void CreateTexture(SDL_Renderer *render, SDL_Texture *&tex, std::string imgPath);
	//load img directly into SDL_Texture
	static void CreateTextureDirectly(SDL_Renderer* render, SDL_Texture*& tex, std::string imgPath);
	//draw a fullscreen img loaded in SDL_Texture to SDL_renderer
	static void drawTexture2Screen(SDL_Renderer* render, SDL_Texture* tex);
	//draw an img loaded in SDL_Texture to SDL_renderer
	static void drawTexture2Screen(SDL_Renderer *render, SDL_Texture *tex, const int &pos_x, const int &pos_y);
	//draw an img loaded in SDL_Texture to SDL_renderer with a specific width and height
	static void drawTexture2Screen(SDL_Renderer* render, SDL_Texture* tex, const int &w, const int &h, const int& pos_x, const int& pos_y);
public:
	//clear SDL_renderer
	static void clearScreen(SDL_Renderer* render);
	//update 
	static void updateScreen(SDL_Renderer* render);

	//draw a full screen img
	static void CreateAndDrawTexture(SDL_Renderer* render, std::string imgPath);

	//draw an img at a given position
	static void CreateAndDrawTexture(SDL_Renderer* render, std::string imgPath, const int& pos_x, const int& pos_y);

	//draw an img with a given size and position
	static void CreateAndDrawTexture(SDL_Renderer* render, std::string imgPath, const int& w, const int& h, const int& pos_x, const int& pos_y);
};

