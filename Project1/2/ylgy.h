//
// Created by 29846 on 2022/12/17.
//

#ifndef YLGY_YLGY_H
#define YLGY_YLGY_H

#include "windows.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"//图片包
#include "SDL2/SDL_ttf.h"//字体包
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "SDL2/SDL_mixer.h"

int isRecover(int i, int floor);
void Rule();
void HotModel();
void HotEnd();
void Pause();
void PauseAndGoMusic(int judge);
void Load();
void PlayMusic();
void Play();
void Move(int i, int floor);
void HotMove(int m, int floor);
void MoveOut();
void Quit();
void paintEach(int x, int y, SDL_Surface *surface);
void Paint(int x, int y, int val, int judge);
void PaintBlack(int x, int y);
void RandomFun();
void randomSort();
void Recant();
void HotRecant();
void printTime();
void RandomAgain();
void gameOverWin();
void gameOverLose();
void reStart();

#endif //YLGY_YLGY_H
