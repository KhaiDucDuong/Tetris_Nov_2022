#include "Image.h"
#include <iostream>

void Image::CreateTexture(SDL_Renderer* render, SDL_Texture*& tex, std::string imgPath)
{
    SDL_Surface* surface = NULL;
    surface = IMG_Load(imgPath.c_str());
    if (!surface)
    {
        std::cout << "Cannot create surface from " << imgPath << "!!!\n";
    }
    else
    {
        tex = SDL_CreateTextureFromSurface(render, surface);
        if (!tex)
        {
            std::cout << "Cannot create texture from " << imgPath << " " << SDL_GetError() <<" !!!\n";
        }
    }

    SDL_FreeSurface(surface);
}

void Image::CreateTextureDirectly(SDL_Renderer* render, SDL_Texture*& tex, std::string imgPath)
{
    tex  = IMG_LoadTexture(render, imgPath.c_str());
    if (!tex)
        std::cout << "Cannot create texture from " << imgPath << " " << SDL_GetError() << " !!!\n";
}

void Image::drawTexture2Screen(SDL_Renderer* render, SDL_Texture* tex)
{
    SDL_RenderCopy(render, tex, NULL, NULL);
    //tex = NULL;
}


void Image::drawTexture2Screen(SDL_Renderer* render, SDL_Texture* tex, const int& pos_x, const int& pos_y)
{
    SDL_Rect rect;
    rect.x = pos_x;
    rect.y = pos_y;
    SDL_RenderCopy(render, tex, NULL, &rect);
}

void Image::drawTexture2Screen(SDL_Renderer* render, SDL_Texture* tex, const int& w, const int& h, const int& pos_x, const int& pos_y)
{
    SDL_Rect rect;
    rect.w = w;
    rect.h = h;
    rect.x = pos_x;
    rect.y = pos_y;
    SDL_RenderCopy(render, tex, NULL, &rect);
}

void Image::clearScreen(SDL_Renderer* render)
{
    SDL_RenderClear(render);
}

void Image::updateScreen(SDL_Renderer* render)
{
    SDL_RenderPresent(render);
}

void Image::CreateAndDrawTexture(SDL_Renderer* render, std::string imgPath)
{
    SDL_Texture* tex = NULL;
    CreateTexture(render, tex, imgPath);
    drawTexture2Screen(render, tex);
    SDL_DestroyTexture(tex);
}

void Image::CreateAndDrawTexture(SDL_Renderer* render, std::string imgPath, const int& pos_x, const int& pos_y)
{
    SDL_Texture* tex = NULL;
    CreateTexture(render, tex, imgPath);
    drawTexture2Screen(render, tex, pos_x, pos_y);
    SDL_DestroyTexture(tex);
}

void Image::CreateAndDrawTexture(SDL_Renderer* render, std::string imgPath, const int& w, const int& h, const int& pos_x, const int& pos_y)
{
    SDL_Texture* tex = NULL;
    CreateTexture(render, tex, imgPath);
    drawTexture2Screen(render, tex, w, h, pos_x, pos_y);
    SDL_DestroyTexture(tex);
}
