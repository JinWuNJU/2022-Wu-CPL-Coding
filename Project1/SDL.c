//
// Created by 20663 on 2022/12/21.
//
#include <stdio.h>
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL_image.h"


SDL_Window *Window = NULL;
SDL_Renderer *Renderer = NULL;
/*看清楚  SDL_Rect的声明!!!!!!
在copy函数调用的时候要加'&'!!!!!!
*/
SDL_Surface *MainBackGroundSurface = NULL;
SDL_Texture *MainBackGroundTexture = NULL;
SDL_Rect MainBackGroundRect;

SDL_Surface *MiniBackGroundSurface = NULL;
SDL_Texture *MiniBackGroundTexture = NULL;
SDL_Rect MiniBackGroundRect;

TTF_Font *ScoreFont = NULL;
SDL_Surface *ScoreSurface = NULL;
SDL_Texture *ScoreTexture = NULL;
SDL_Rect ScoreRect;
SDL_Color FontColor = {125, 115, 225, 155};

void PLAY();
void QUIT();
void LOAD();
void PAINTSCORE();

int SDL_main(int argc, char *argv[])
{

    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    Window = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 920, 800, SDL_WINDOW_SHOWN);
    Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED);
    /// @brief 与Rect相同,直接定义,最后再取地址
    /// @param argc
    /// @param argv
    /// @return
    SDL_Event MainEvent;
    LOAD();
    SDL_RenderClear(Renderer);
    SDL_RenderCopy(Renderer, MainBackGroundTexture, NULL, &MainBackGroundRect);
    SDL_RenderPresent(Renderer);
    PAINTSCORE();
    while (SDL_WaitEvent(&MainEvent))
    {
        switch (MainEvent.type)
        {
            case SDL_QUIT:
                QUIT();
                break;
            case SDL_KEYDOWN:
                switch (MainEvent.key.keysym.sym)
                {
                    case SDLK_RETURN:
                    case SDLK_s:
                        PLAY();
                        break;
                    case SDLK_ESCAPE:
                        QUIT();
                        break;
                    case SDLK_h:
                        PAINTSCORE();
                        break;
                    default:
                        break;
                }
                break;
            case SDL_MOUSEBUTTONDOWN:
                printf("(%d,%d)\n", MainEvent.button.x, MainEvent.button.y);
                break;
            case SDL_MOUSEBUTTONUP:
                printf("(%d,%d)\n", MainEvent.button.x, MainEvent.button.y);
                break;
            default:
                break;
        }
    }

    QUIT();
}

void LOAD()
{
    MainBackGroundSurface = IMG_Load("IMAGE/ddddd.jpg");
    MainBackGroundTexture = SDL_CreateTextureFromSurface(Renderer, MainBackGroundSurface);
    MainBackGroundRect.x = 0;
    MainBackGroundRect.y = 0;
    MainBackGroundRect.h = MainBackGroundSurface->h;
    MainBackGroundRect.w = MainBackGroundSurface->w;
    MiniBackGroundSurface = IMG_Load("IMAGE/fffff.png");
    MiniBackGroundTexture = SDL_CreateTextureFromSurface(Renderer, MiniBackGroundSurface);
    MiniBackGroundRect.x = 0;
    MiniBackGroundRect.y = 0;
    MiniBackGroundRect.h = MiniBackGroundSurface->h;
    MiniBackGroundRect.w = MiniBackGroundSurface->w;
    ScoreFont = TTF_OpenFont("IMAGE/DroidSerif-Bold.ttf", 50);
}
void PLAY()
{
    printf("You Are In The PLay UI!\n");
    SDL_RenderClear(Renderer);
    SDL_RenderCopy(Renderer, MiniBackGroundTexture, NULL, &MiniBackGroundRect);
    SDL_RenderPresent(Renderer);
}

void PAINTSCORE()
{
    char *s[10];
    s[1] = "qwert";
    char a[10][19];
    sprintf(a[1], "qwert");
    ScoreSurface = TTF_RenderUTF8_Blended(ScoreFont, a[1], FontColor);
    ScoreTexture = SDL_CreateTextureFromSurface(Renderer, ScoreSurface);
    ScoreRect.x = 0;
    ScoreRect.y = 0;
    ScoreRect.h = ScoreSurface->h;
    ScoreRect.w = ScoreSurface->w;
    SDL_RenderClear(Renderer);
    SDL_RenderCopy(Renderer, ScoreTexture, NULL, &ScoreRect);
    SDL_RenderPresent(Renderer);
}
void QUIT()
{
    SDL_FreeSurface(MainBackGroundSurface);
    SDL_FreeSurface(MiniBackGroundSurface);
    SDL_FreeSurface(ScoreSurface);

    SDL_DestroyTexture(MainBackGroundTexture);
    SDL_DestroyTexture(MiniBackGroundTexture);
    SDL_DestroyTexture(ScoreTexture);

    TTF_CloseFont(ScoreFont);

    SDL_DestroyWindow(Window);
    SDL_DestroyRenderer(Renderer);

    SDL_Quit();
}