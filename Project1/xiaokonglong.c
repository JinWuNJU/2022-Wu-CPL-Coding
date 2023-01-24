//
// Created by 20663 on 2022/12/27.
//
#include<stdio.h>
#include<stdbool.h>
#include"SDL2\SDL.h"
#include "SDL2\SDL_main.h"
#include"SDL2\SDL_ttf.h"
#include"SDL2\SDL_mixer.h"
#include"SDL2\SDL_image.h"

#define WindowWidth  500
#define WindowHeight  400

bool IsQuit = false;

SDL_Rect greenrect;
int speed = 1;
int CurrentWindowWidth = WindowWidth;
int CurrentWindowHeight = WindowHeight;

void EventHandle(SDL_Event *event){
    while (SDL_PollEvent(event)){
        if(event->type == SDL_QUIT){
            IsQuit = true;
        }

//        else if(event->type == SDL_WINDOWEVENT){
//            if(event->window.event == SDL_WINDOWEVENT_RESIZED){
//                SDL_Log("window resized %d %d",event->window.data1,event->window.data2);
//            }
//        }

        else if(event->type == SDL_KEYDOWN){
            SDL_Log("KeyDown : %s", SDL_GetKeyName(event->key.keysym.sym));
            if(event->key.keysym.scancode == SDL_SCANCODE_COMMA &&
            event->key.keysym.mod &KMOD_SHIFT){
                SDL_Log("<");
            }
        }
        else if(event->type == SDL_KEYUP){
            SDL_Log("KeyUp : %s", SDL_GetKeyName(event->key.keysym.sym));
        }
//        else if(event->type == SDL_MOUSEMOTION){
//            SDL_Log("MouseMotion : (%d %d)",event->motion.x,event->motion.y);
//        }
        else if(event->type == SDL_MOUSEBUTTONDOWN){
            SDL_Log("Press (%d %d)\n",event->button.x,event->button.y);
            SDL_Log("button %d\n",event->button.button);
        }
        else if(event->type == SDL_MOUSEBUTTONUP){
            SDL_Log("Release (%d %d)\n",event->button.x,event->button.y);
        }
        else if(event->type == SDL_MOUSEWHEEL){
            SDL_Log("Wheeling : x=%d y=%d",event->wheel.x,event->wheel.y);
        }

        //不建议：
        //1.速度慢
        //2.两帧之间容易漏操作
//        int mousex,mousey;
//        Uint32 button = SDL_GetMouseState(&mousex,&mousey);
//        if((button & SDL_BUTTON(SDL_BUTTON_LEFT)) && (button & SDL_BUTTON(SDL_BUTTON_RIGHT))){
//            SDL_Log("left and right are both pressed");
//        }


//
//        const Uint8 *key = SDL_GetKeyboardState(NULL);
//        if(key[SDL_SCANCODE_D]){
//            SDL_Log("You pressed D");
//        }



    }
}
void ClearScreen(SDL_Renderer *renderer){
    SDL_SetRenderDrawColor(renderer,0,0,0,0);
    SDL_RenderClear(renderer);
}

void RenderPresent(SDL_Renderer *renderer){
    SDL_RenderPresent(renderer);
}

void LogicUpdate(SDL_Window *window){
    SDL_GetWindowSize(window,&CurrentWindowWidth,&CurrentWindowHeight);//使得拉伸时让程序知道拉伸使得尺寸改变
    CurrentWindowHeight-=speed;
    CurrentWindowWidth-=speed;
    SDL_SetWindowSize(window,CurrentWindowWidth,CurrentWindowHeight);
}


void Render(SDL_Renderer *renderer){
    ClearScreen(renderer);
    
    SDL_SetRenderDrawColor(renderer,0,255,0,255);
    SDL_RenderDrawRect(renderer,&greenrect);


    RenderPresent(renderer);
}

//游戏结束时的判定：
//SDL_SetWindowAlwaysOnTop(window,SDL_FALSE);
//SDL_ShowSimpleMessageBox("游戏结束","玩家已经死亡",NULL);
//SDL_SetWindowResizable(window,SDL_FALSE);

int main(int argc,char *argv[]){




    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    //int x=0;
    IMG_Init(IMG_INIT_JPG|IMG_INIT_PNG);//初始化


    greenrect.w=50;
    greenrect.h=50;
    greenrect.x=(WindowWidth-greenrect.w)/2;
    greenrect.y=(WindowHeight-greenrect.h)/2;

    SDL_Window *Window=SDL_CreateWindow("hello!",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,WindowWidth,WindowHeight,SDL_WINDOW_SHOWN|SDL_WINDOW_ALWAYS_ON_TOP|SDL_WINDOW_RESIZABLE);

    SDL_SetWindowMinimumSize(Window,50,50);//设置最小窗口尺寸
    SDL_SetWindowMaximumSize(Window,1000,1000);

    SDL_Renderer *Renderer=SDL_CreateRenderer(Window,-1,SDL_RENDERER_ACCELERATED);
    //SDL_SetRenderDrawColor(Renderer,0,0,0,255);
    // RGBA ~ Red Green Blue Alpha


    TTF_Font *font = TTF_OpenFont("resources/JetBrainsMono-Regular.ttf",20);
    if(!font){
        SDL_Log("OpenFont Failed!");
    }
    SDL_Color fontcolor = {255,255,255,255};
    SDL_Surface *blendSurface = TTF_RenderUTF8_Blended(font,"hello world 你好",fontcolor);
    SDL_Texture *blendTexture = SDL_CreateTextureFromSurface(Renderer,blendSurface);
    SDL_Rect blendrect = {0,250,blendSurface->w,blendSurface->h};
    SDL_FreeSurface(blendSurface);



    //简单的绘制图形(方法一)
//    SDL_Surface *surface = IMG_Load("resources/liuhan.png");
//    SDL_Texture *texture = SDL_CreateTextureFromSurface(Renderer,surface);
//    int w=surface->w,h=surface->h;
//    SDL_FreeSurface(surface);

//(方法二)
SDL_Texture *texture = IMG_LoadTexture(Renderer,"resources/liuhan.png");
    int w,h;
    SDL_QueryTexture(texture,NULL,NULL,&w,&h);





//    SDL_Texture *newtexture= SDL_CreateTexture(Renderer,SDL_PIXELFORMAT_RGBA8888,SDL_TEXTUREACCESS_STATIC|SDL_TEXTUREACCESS_TARGET,
//                                               WindowWidth,WindowHeight);

//    SDL_SetTextureBlendMode(texture,SDL_BLENDMODE_BLEND);
//    SDL_SetTextureAlphaMod(texture,20);//设置texture透明度
//    SDL_SetTextureColorMod(texture,255,0,0);




    SDL_Event event;//类似于Rect

    SDL_Rect ScreenRect;

    //SDL_GetDisplayBounds(0,&ScreenRect);//得到屏幕的尺寸

    //int direction = 1;

    // SDL_SetWindowBordered(Window,false);//不显示边框
    // SDL_SetWindowMouseGrab(Window,true);//控制使鼠标在窗口内
    // SDL_Rect rect={100,100,10,10};
    // SDL_SetWindowMouseRect(Window,&rect);//进一步压缩鼠标的活动空间



    // SDL_FlashWindow(Window,SDL_FLASH_BRIEFLY);//小窗闪烁(注意焦点)

    SDL_SetRenderDrawBlendMode(Renderer,SDL_BLENDMODE_BLEND);//允许绘制透明色,必要步骤
    int degree =0;

    while(!IsQuit){
        EventHandle(&event);

        //LogicUpdate(Window);

        //Render(Renderer);

        ClearScreen(Renderer);


        //SDL_SetRenderTarget(Renderer,newtexture);

        SDL_Rect destrect;
        destrect.x=0,destrect.y=0;
        destrect.w=w,destrect.h=h;
        SDL_RenderCopyEx(Renderer,texture,NULL,&destrect,degree,NULL,SDL_FLIP_NONE);

        SDL_RenderCopy(Renderer,blendTexture,NULL,&blendrect);



        //SDL_SetRenderTarget(Renderer,NULL);
        //SDL_RenderCopy(Renderer,newtexture,NULL,NULL);

        SDL_RenderPresent(Renderer);


        degree++;














//        if(x+WindowWidth>=ScreenRect.w){
//            direction=-1;
//        }
//        else if(x<0){
//            direction=1;
//        }
//        x+=10*direction;
//
//        SDL_SetRenderDrawColor(Renderer,0,50,128,255);
//        SDL_RenderClear(Renderer);//使用绘图颜色清除当前呈现目标
//
//        SDL_RenderPresent(Renderer);
//
//        SDL_SetRenderDrawColor(Renderer,255,0,0,255);
//        SDL_Rect rect1={50,50,25,25};
//        SDL_RenderDrawRect(Renderer,&rect1);
//        SDL_RenderPresent(Renderer);
//
//        SDL_SetRenderDrawColor(Renderer,0,255,0,255);
//        SDL_Rect rect2={60,60,25,25};
//        SDL_RenderDrawRect(Renderer,&rect2);
//        SDL_RenderPresent(Renderer);
//
//        SDL_SetRenderDrawColor(Renderer,125,200,255,255);
//        SDL_RenderFillRect(Renderer,&rect1);
//        SDL_RenderPresent(Renderer);
//
//        SDL_RenderFillRect(Renderer,&rect2);
//        SDL_RenderPresent(Renderer);
//
//
//        //SDL_SetWindowPosition(Window,x,SDL_WINDOWPOS_CENTERED);
//
//        //SDL_RenderPresent(Renderer);





        SDL_Delay(60);
    }
    TTF_CloseFont(font);
    TTF_Quit();
    IMG_Quit();
    //SDL_DestroyTexture(newtexture);
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(Renderer);
    SDL_DestroyWindow(Window);
    SDL_Quit();
    return 0;
}

