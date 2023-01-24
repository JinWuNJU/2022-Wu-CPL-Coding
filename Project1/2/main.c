//
// Created by 29846 on 2022/12/12.
//
#include "ylgy.h"

#define window_width 504//窗口的宽度
#define window_height 900//窗口的高度
#define startX1 137
#define startX2 363
#define startY1 715
#define startY2 775
#define width 60//图片宽度
#define height 60//图片高度
#define NUM 135
//建立全局图片，纹理，渲染器

SDL_Event MainEvent;
SDL_Event PlayEvent;
SDL_Event PauseEvent;
SDL_Event RuleEvent;
SDL_Event HotEvent;

SDL_Window *Window = NULL;//创建窗口
SDL_Renderer *Renderer = NULL;//创建渲染器

int DownButtonX;//鼠标点击横坐标0
int DownButtonY;//鼠标点击纵坐标
int UpButtonX;//鼠标松开横坐标
int UpButtonY;//鼠标松开纵坐标

time_t startTime;
time_t endTime;
time_t tempTime;
time_t Temp;
double length = 225;
int isHot;//hot音乐是否开启
int deleteCount;//检测消除方块的组数
int judgeMusic = 1;//判断是否播放
int isReturn;//判断是否返回
int isHotEnd;//判断是否是狂热状态刚结束的时候
int judgeHotDelete;//判断要进行撤回的上一步操作是否是狂热操作
int isPause;
int timeJudge;
char timeChar[20];
int judgeMap = NUM;
int judgeColumn;
int judgeRecant;
int judgeDelete;
int ColumnLocation[7][2] = {{27,730},{91,730},{155,730},{219,730},{283,730},{347,730},{411,730}};//记录放置框七个位置的左上角坐标，为定值，不做修改

struct MAP {
    int situation[7][32];//第1,2,3层为地图中心的卡片，5为最上方（！= 最上层）的一条卡片，6 为下方移出的图片
    int column[7];
}OldMap,CurMap;
int Location[7][32][2];
int blockLocation[9][2];
SDL_Surface *MainSurface = NULL;
//以上位主页面
SDL_Surface *PlaySurface = NULL;
//以上为游戏页面
SDL_Surface *RoleSurface[11] = {NULL};
//游戏图片
SDL_Surface *LoseSurface = NULL;
//失败图片
SDL_Surface *WinSurface = NULL;
//成功图片
SDL_Surface *recantSurface = NULL;
//撤回显示图片
SDL_Surface *GoingSurface = NULL;
//进行图标
SDL_Surface *PauseSurface = NULL;
//暂停图标
SDL_Surface *pauseXMSurface = NULL;
//暂停熊猫头图标
Mix_Music *BackSound = NULL;
Mix_Music *HotSound = NULL;
//加载音乐
SDL_Surface *musicGo = NULL;
SDL_Surface *musicPause = NULL;
//加载音乐暂停和播放图片
SDL_Surface *blockSurface = NULL;
//充能方块
SDL_Surface *blackSurface = NULL;
//黑色蒙板
SDL_Surface *ruleSurface = NULL;
//游戏说明
TTF_Font *timeFont = NULL;
//主函数
int SDL_main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);//初始化SDL的Video子系统/子系统初始化标志
    Window = SDL_CreateWindow("原了个原new", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, window_width, window_height, SDL_WINDOW_SHOWN);//显示窗口，w为宽，h为高
    Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);//创建渲染器
    SDL_EventState(SDL_MOUSEMOTION, SDL_IGNORE);//忽视鼠标移动带来的事件处理与内存占用

    if (TTF_Init()) {
        SDL_Log("no response in main");
        return 1;
    }

    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

    Load();//加载各个封面，图片，字体
    paintEach(0, 0, MainSurface);
    SDL_RenderPresent(Renderer);
    PlayMusic();//放音乐

    while (SDL_WaitEvent(&MainEvent))
    {
        paintEach(0, 0, MainSurface);
        SDL_RenderPresent(Renderer);
        switch (MainEvent.type) {
            case SDL_QUIT:
                Quit();
                break;
            case SDL_KEYDOWN:
                switch (MainEvent.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        Quit();
                        break;
                    default:
                        break;
                }
                break;
            case SDL_MOUSEBUTTONDOWN:
                DownButtonX = MainEvent.button.x;
                DownButtonY = MainEvent.button.y;
                printf("(%d,%d)\n",DownButtonX,DownButtonY);
                break;
            case SDL_MOUSEBUTTONUP:
                UpButtonX = MainEvent.button.x;
                UpButtonY = MainEvent.button.y;
                printf("(%d,%d)\n",UpButtonX,UpButtonY);
                if (UpButtonX > startX1 && UpButtonX < startX2 && UpButtonY > startY1 && UpButtonY < startY2)
                    Play();
                else if (UpButtonX > 150 && UpButtonX < 330 && UpButtonY > 305 && UpButtonY < 370)
                    Rule();
                break;
            default:
                break;
        }
    }

    Quit();
}
void Rule() {
    while(1) {
        paintEach(100, 150, ruleSurface);
        SDL_RenderPresent(Renderer);
        while (SDL_PollEvent(&RuleEvent)) {
            switch (RuleEvent.type) {
                case SDL_QUIT:
                    Quit();
                case SDL_KEYDOWN:
                    switch (RuleEvent.key.keysym.sym) {
                        case SDLK_ESCAPE:
                            return;
                        default:
                            break;
                    }
                    break;
                case SDL_MOUSEBUTTONUP:
                    return;
                default:
                    break;
            }
        }
    }
}

void PauseAndGoMusic(int judge) {
    if (judge)
        Mix_PauseMusic();
    else
        Mix_ResumeMusic();
}

void PlayMusic() {
    //加载音乐
    BackSound = Mix_LoadMUS("PicturePackage/liyue.mp3");
    Mix_PlayMusic(BackSound, -1);
}

void HotModel() {
    SDL_Surface *HotSurface = IMG_Load("PicturePackage/hot.png");
    paintEach(50, 300, HotSurface);
    SDL_RenderPresent(Renderer);//显示hot页面
    SDL_Delay(2000);
    int m = 150;
    while (m--) {
        while(SDL_PollEvent(&HotEvent));
    }
    Paint(0, 0, 0, 0);
    SDL_FreeSurface(HotSurface);
}

void HotEnd() {
    SDL_Surface *binSurface = IMG_Load("PicturePackage/binbin.jpg");
    paintEach(50, 300, binSurface);
    SDL_RenderPresent(Renderer);//显示hot页面
    SDL_Delay(2000);
    int m = 150;
    while (m--) {
        while(SDL_PollEvent(&HotEvent));
    }
    Paint(0, 0, 0, 0);
    SDL_FreeSurface(binSurface);
}

void Load() {
    MainSurface = IMG_Load("PicturePackage/BackGround.png");
    //加载封面图片
    paintEach(0, 0, MainSurface);
    SDL_RenderPresent(Renderer);
    //打印封面
    //加载游戏图片
    PlaySurface = IMG_Load("PicturePackage/model_play2.png");
    //加载人物图片
    for (int i = 1; i < 10; ++i) {
        char temp[30];
        sprintf(temp, "PicturePackage/role(%d).jpg", i);
        RoleSurface[i] = IMG_Load(temp);
    }
    //加载失败图片
    LoseSurface = IMG_Load("PicturePackage/Lose.png");
    //加载成功图片
    WinSurface = IMG_Load("PicturePackage/Win.jpg");
    //加载撤回显示图片
    recantSurface = IMG_Load("PicturePackage/recant.jpg");
    //加载字体
    timeFont = TTF_OpenFont("PicturePackage/font.ttf",45);
    //加载进行图片
    GoingSurface = IMG_Load("PicturePackage/start.jpg");
    //加载暂停图片和显示熊猫头
    PauseSurface = IMG_Load("PicturePackage/pause.jpg");
    pauseXMSurface = IMG_Load("PicturePackage/pauseXM.jpg");
    //加载音乐播放和暂停图标
    musicGo = IMG_Load("PicturePackage/MusicGo.png");
    musicPause = IMG_Load("PicturePackage/MusicPause.jpg");
    //加载充能方块
    blockSurface = IMG_Load("PicturePackage/block.png");
    //加载黑色蒙板
    blackSurface = IMG_Load("PicturePackage/black.png");
    //加载游戏说明
    ruleSurface = IMG_Load("PicturePackage/rule.jpg");
    //加载地图坐标
    //加载充能方块坐标
    for (int i = 0; i < 9; ++i) {
        blockLocation[i][0] = 158 + i * 25;
        blockLocation[i][1] = 696;
    }
    //使用移出方块技能后的位置
    for (int i = 0; i < 3; ++i) {
        Location[6][i][0] = 100 + i * 120;
        Location[6][i][1] = 620;
    }
    //加载最上方的人物坐标
    for (int i = 0; i < 13; ++i) {
        Location[5][i][0] = 140 + i * 4;
        Location[5][i][1] = 170;
    }
    for (int i = 13; i < 27; ++i) {
        Location[5][i][0] = 310 - (i - 13) * 4;
        Location[5][i][1] = 170;
    }
    //加载第五层
    for (int i = 0; i < 25; ++i) {
        Location[4][i][0] = 100 + i % 5 * 60;
        Location[4][i][1] = 300 + i / 5 * 60;
    }
    //加载第四层
    for (int i = 0; i < 2; ++i) {
        Location[3][i][0] = 70 + i % 2 * 60;
        Location[3][i][1] = 330;
        Location[3][i + 2][0] = 310 + i % 2 * 60;
        Location[3][i + 2][1] = 330;
        Location[3][i + 4][0] = 70 + i % 2 * 60;
        Location[3][i + 4][1] = 510;
        Location[3][i + 6][0] = 310 + i % 2 * 60;
        Location[3][i + 6][1] = 510;
    }
    for (int i = 8; i < 12; ++i) {
        Location[3][i][0] = 190 + i % 2 * 60;
        Location[3][i][1] = 390 + (i - 8) / 2 * 60;
    }
    //加载第三层
    int x = 10;
    int y = 240;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            Location[2][j + i * 4][0] = x + j % 2 * 60;
            Location[2][j + i * 4][1] = y + j / 2 * 60;
        }
        x += 180;
    }
    x = 100;
    y = 360;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 4; ++j) {
            Location[2][j + i * 4 + 12][0] = x + j % 2 * 60;
            Location[2][j + i * 4 + 12][1] = y + j / 2 * 60;
        }
        x += 180;
    }
    x = 10;
    y = 480;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            Location[2][j + i * 4 + 20][0] = x + j % 2 * 60;
            Location[2][j + i * 4 + 20][1] = y + j / 2 * 60;
        }
        x += 180;
    }
    //加载第二层
    x = 40;
    y = 240;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 2; ++j) {
            Location[1][j + i * 2][0] = x;
            Location[1][j + i * 2][1] = y + j * 60;
        }
        x += 180;
    }
    for (int i = 6; i < 9; ++i) {
        Location[1][i][0] = 130 + i % 3 * 90;
        Location[1][i][1] = 390;
    }
    for (int i = 9; i < 16; ++i) {
        Location[1][i][0] = 40 + i % 9 * 60;
        Location[1][i][1] = 510;
    }
    //加载第一层（最顶层）
    for (int i = 0; i < 8; ++i) {
        Location[0][i][0] = 130 + i % 4 * 60;
        Location[0][i][1] = 240 + i / 4 * 60;
    }
    for (int i = 8; i < 16; ++i) {
        Location[0][i][0] = 100 + i / 12 * 240;
        Location[0][i][1] = 360 + i % 4 * 60;
    }
    for (int i = 16; i < 19; ++i) {
        Location[0][i][0] = 220;
        Location[0][i][1] = 390 + i % 4 * 60;
    }
    for (int i = 19; i < 23; ++i) {
        Location[0][i][0] = 40 + i % 19 * 120;
        Location[0][i][1] = 480;
    }
}

void Play() {
    startTime = SDL_GetTicks();
    SDL_RenderClear(Renderer);
    paintEach(0, 0, PlaySurface);
    SDL_RenderPresent(Renderer);
    //初始化地图
    randomSort();

    while (judgeMap && judgeColumn < 7) {
        Paint(0, 0, 0, 0);
        if (deleteCount == 9 && !isHot) {
            HotModel();
            isHot = 1;
        }
        if (isHotEnd) {
            HotEnd();
            isHotEnd = 0;
        }
        while (SDL_PollEvent(&PlayEvent) && judgeMap && judgeColumn < 7) {
            switch (PlayEvent.type) {
                case SDL_QUIT:
                    Quit();
                    break;
                case SDL_KEYDOWN:
                    switch (PlayEvent.key.keysym.sym) {
                        case SDLK_ESCAPE:
                            reStart();
                            return;
                        default:
                            break;
                    }
                    break;
                case SDL_MOUSEBUTTONUP:
                    UpButtonX = PlayEvent.button.x;
                    UpButtonY = PlayEvent.button.y;
                    printf("(%d,%d)\n",UpButtonX,UpButtonY);
                    if (UpButtonY < 180 && UpButtonY > 120 && UpButtonX < 140 && UpButtonX > 80) {
                        PauseAndGoMusic(judgeMusic);
                        judgeMusic = 1 - judgeMusic;
                    }
                    else if (UpButtonY < 105 && UpButtonY > 45 && UpButtonX < 140 && UpButtonX > 80) {
                        reStart();
                        return;
                    }
                    else if (UpButtonY < 180 && UpButtonY > 120 && UpButtonX < 70 && UpButtonX > 10) {
                        Pause();
                        if (isReturn) {
                            isReturn = 0;
                            return;
                        }
                    }
                    else if (UpButtonY < 870 && UpButtonY > 817 && UpButtonX < 144 && UpButtonX > 51)
                        MoveOut();
                    else if (UpButtonY < 870 && UpButtonY > 817 && UpButtonX < 296 && UpButtonX > 207)
                        if (judgeHotDelete)
                            HotRecant();
                        else
                            Recant();
                    else if (UpButtonY < 870 && UpButtonY > 817 && UpButtonX < 452 && UpButtonX > 360)
                        RandomAgain();
                    else {
                        int judgeP = 1;
                        for (int i = 0; i < 7 && judgeP; ++i) {
                            for (int j = 0; j < 32; ++j) {
                                if ((UpButtonX - Location[i][j][0]) < width && UpButtonX > Location[i][j][0] &&
                                    UpButtonY > Location[i][j][1] && (UpButtonY - Location[i][j][1]) < height &&
                                    !isRecover(j, i) && CurMap.situation[i][j]) {
                                    if (!isHot)
                                        Move(j, i);
                                    else
                                        HotMove(j, i);
                                    judgeP = 0;
                                    break;
                                }
                            }
                        }
                    }
                    break;
                default:
                    break;
            }
        }
    }
    if (judgeColumn) {
        gameOverLose();
        return;
    }
    else
        gameOverWin();
}

void Pause() {
    isPause = 1;
    while (isPause) {
        Paint(0, 0, 0, 0);
        while (SDL_PollEvent(&PauseEvent) && isPause) {
            switch (PauseEvent.type) {
                case SDL_QUIT:
                    Quit();
                    break;
                case SDL_KEYDOWN:
                    switch (PauseEvent.key.keysym.sym) {
                        case SDLK_ESCAPE:
                            Quit();
                            return;
                        default:
                            break;
                    }
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    break;
                case SDL_MOUSEBUTTONUP:
                    UpButtonX = PauseEvent.button.x;
                    UpButtonY = PauseEvent.button.y;
                    printf("(%d,%d)\n",UpButtonX,UpButtonY);
                    if (UpButtonY < 180 && UpButtonY > 120 && UpButtonX < 70 && UpButtonX > 10)
                        isPause = 0;
                    else if (UpButtonY < 180 && UpButtonY > 120 && UpButtonX < 140 && UpButtonX > 80) {
                        PauseAndGoMusic(judgeMusic);
                        judgeMusic = 1 - judgeMusic;
                    }
                    else if (UpButtonY < 105 && UpButtonY > 45 && UpButtonX < 140 && UpButtonX > 80) {
                        isReturn = 1;
                        reStart();
                        return;
                    }
                    break;
                default:
                    break;
            }
        }
    }
}

int isRecover(int i, int floor) {
    int x = Location[floor][i][0];
    int y = Location[floor][i][1];
    if (floor == 6 || floor == 0)
        return 0;
    if (floor == 5) {
        for (int j = 0; j < 32; ++j) {
            if (abs(x - Location[5][j][0]) < 60 && i > j && CurMap.situation[5][j])
                return 1;
        }
        return 0;
    }
    for (int k = 0; k < floor; ++k)
        for (int j = 0; j < 32; ++j)
            if (abs(x - Location[k][j][0]) < 60 && abs(y - Location[k][j][1]) < 60 && CurMap.situation[k][j])
                return 1;
    return 0;
}
//初始化地图
void randomSort() {
    int name = 0;
    for (int i = 0; i < 23; ++i)
        OldMap.situation[0][i] = CurMap.situation[0][i] = name++ % 9 + 1;
    for (int i = 0; i < 16; ++i)
        OldMap.situation[1][i] = CurMap.situation[1][i] = name++ % 9 + 1;
    for (int i = 0; i < 32; ++i)
        OldMap.situation[2][i] = CurMap.situation[2][i] = name++ % 9 + 1;
    for (int i = 0; i < 12; ++i)
        OldMap.situation[3][i] = CurMap.situation[3][i] = name++ % 9 + 1;
    for (int i = 0; i < 25; ++i)
        OldMap.situation[4][i] = CurMap.situation[4][i] = name++ % 9 + 1;
    for (int i = 0; i < 27; ++i)
        OldMap.situation[5][i] = CurMap.situation[5][i] = name++ % 9 + 1;
    for (int i = 0; i < 3; ++i)
        CurMap.situation[6][i] = 0;
    //循环100次，分三组
    RandomFun();
    OldMap = CurMap;
    Paint(0, 0, 0, 0);
}

void RandomFun() {
    OldMap = CurMap;
    srand(time(NULL));
    for (int i = 0; i < 80; ++i) {
        int loc1 = rand() % 23;
        int loc2 = rand() % 16;
        int temp = CurMap.situation[0][loc1];
        CurMap.situation[0][loc1] = CurMap.situation[1][loc2];
        CurMap.situation[1][loc2] = temp;
    }
    for (int i = 0; i < 80; ++i) {
        int loc1 = rand() % 23;
        int loc3 = rand() % 32;
        int temp = CurMap.situation[0][loc1];
        CurMap.situation[0][loc1] = CurMap.situation[2][loc3];
        CurMap.situation[2][loc3] = temp;
    }
    for (int i = 0; i < 80; ++i) {
        int loc2 = rand() % 16;
        int loc3 = rand() % 25;
        int temp = CurMap.situation[1][loc2];
        CurMap.situation[1][loc2] = CurMap.situation[4][loc3];
        CurMap.situation[4][loc3] = temp;
    }
    for (int i = 0; i < 80; ++i) {
        int loc1 = rand() % 27;
        int loc2 = rand() % 12;
        int temp = CurMap.situation[5][loc1];
        CurMap.situation[5][loc1] = CurMap.situation[3][loc2];
        CurMap.situation[3][loc2] = temp;
    }
    for (int i = 0; i < 80; ++i) {
        int loc1 = rand() % 32;
        int loc4 = rand() % 25;
        int temp = CurMap.situation[2][loc1];
        CurMap.situation[2][loc1] = CurMap.situation[4][loc4];
        CurMap.situation[4][loc4] = temp;
    }
}

void HotMove(int m, int floor) {
    judgeRecant = 1;
    judgeDelete = 0;
    OldMap = CurMap;
    int name = CurMap.situation[floor][m];
    CurMap.situation[floor][m] = 0;
    int judgeP = 2;
    for (int i = 0; i < 7 && judgeP; ++i) {
        for (int j = 0; j < 32 && judgeP; ++j) {
            if (CurMap.situation[i][j] == name) {
                CurMap.situation[i][j] = 0;
                judgeP--;
                if (i == 6) {
                    for (int k = j; k < 2; ++k)
                        CurMap.situation[i][k] = CurMap.situation[i][k + 1];
                    CurMap.situation[i][2] = 0;
                }
            }
        }
    }
    if (!judgeP) {
        judgeHotDelete = 3;
        judgeMap -= 3;
        return;
    }
    for (m = 0; m < 7; ++m)
        if (CurMap.column[m] == name)
            break;
    if (judgeP == 1){
        judgeMap -= 2;
        judgeColumn--;
        judgeHotDelete = 2;
        for (int k = m; k < 6; ++k)
            CurMap.column[k] = CurMap.column[k + 1];
        for (int k = judgeColumn; k <= 6; ++k)
            CurMap.column[k] = 0;
        return;
    }else{
        judgeMap -= 1;
        judgeHotDelete = 1;
        judgeColumn -= 2;
        for (int k = m; k <= 6; ++k)
            CurMap.column[k] = CurMap.column[k + 2];
        for (int k = judgeColumn; k <= 6; ++k)
            CurMap.column[k] = 0;
    }
}

void Move(int i, int floor) {
    //floor为层数
    judgeMap--;
    judgeColumn++;
    judgeHotDelete = 0;
    judgeRecant = 1;
    printf("judgeMap=%d\n",judgeMap);
    //复制一遍状态
    OldMap = CurMap;
    //找到放置框的第一个空位,并存放
    //让指定位置为0，即消除指定图片
    int j;
    for (j = 0; j < 7; ++j) {
        if (!CurMap.column[j])
            break;
    }//j即是放置框的第一个空位
    int val = CurMap.situation[floor][i];
    CurMap.situation[floor][i] = 0;//保存被移动的方块
    //如果floor = 6 的话
    if (floor == 6) {
        for (int k = i; k < 2; ++k)
            CurMap.situation[floor][k] = CurMap.situation[floor][k + 1];
        CurMap.situation[floor][2] = 0;
    }
    //空出方块将移入放置框的位置
    int judge = 0;
    judgeDelete = 0;
    int m = 0;
    for (; m < j; ++m) {
        if (CurMap.column[m] == val) {
            for (int n = j; n > m + 1; --n) {
                CurMap.column[n] = CurMap.column[n - 1];
                judge = 1;
            }
            CurMap.column[m + 1] = 0;
            break;
        }
    }
    //确定方块移入的位置
    int place = judge ? m + 1 : j;
    //动态移动入框
    double x = Location[floor][i][0];
    double y = Location[floor][i][1];
    double dx = (ColumnLocation[place][0] - x) / 45.0;
    double dy = (ColumnLocation[place][1] - y) / 45.0;
    while (abs((int) x - ColumnLocation[place][0]) >= 5 || abs((int) y - ColumnLocation[place][1]) >= 5) {
        int IntX = (int) x;
        int IntY = (int) y;
        Paint(IntX, IntY, val, 1);
        x += dx;
        y += dy;
    }
    //保存
    CurMap.column[place] = val;
    Paint(0, 0, 0, 0);
    SDL_Delay(200);
    //检测是否满三个
    int n = m + 1;
    if (n >= j || !CurMap.column[n + 1]) {
        return;
    }
    for (; n < m + 3; ++n) {
        if ((CurMap.column[n] != CurMap.column[m]) || !CurMap.column[n])
            break;
    }
    if (n < m + 3) {
        return;
    }
    if (n == m + 3) {
        deleteCount++;
        judgeDelete = 1;
        judgeColumn -= 3;
        for (int k = m; k <= j - 3; ++k)
            CurMap.column[k] = CurMap.column[k + 3];
        for (int k = j - 2; k <= j; ++k)
            CurMap.column[k] = 0;
    }
    if (judgeMap == 0)
        judgeRecant = 0;
    Paint(0, 0, 0, 0);
}

void MoveOut() {
    int j;
    for (j = 0; j < 3; ++j) {
        if (!CurMap.situation[6][j])
            break;
    }//j即是移出位置的第一个空位
    if (judgeColumn == 0 || j == 3)
        return;
    else if (j == 0) {
        int k = judgeColumn >= 3 ? judgeColumn - 3 : 0;
        for (int i = k; i < judgeColumn; ++i) {
            CurMap.situation[6][j + i - k] = CurMap.column[i];
            CurMap.column[i] = 0;
        }
        judgeMap += judgeColumn - k;
        judgeColumn -= judgeColumn - k;
    } else if (j == 1) {
        int k = judgeColumn >= 2 ? judgeColumn - 2 : 0;
        for (int i = k; i < judgeColumn; ++i) {
            CurMap.situation[6][j + i - k] = CurMap.column[i];
            CurMap.column[i] = 0;
        }
        judgeMap += judgeColumn - k;
        judgeColumn -= judgeColumn - k;
    } else if (j == 2) {
        int k = judgeColumn >= 1 ? judgeColumn - 1 : 0;
        for (int i = k; i < judgeColumn; ++i) {
            CurMap.situation[6][j + i - k] = CurMap.column[i];
            CurMap.column[i] = 0;
        }
        judgeMap += judgeColumn - k;
        judgeColumn -= judgeColumn - k;
    }
    printf("judgeMap = %d\n", judgeMap);
}

void HotRecant() {
    if (!judgeRecant) {
        paintEach(0, 0, recantSurface);
        SDL_RenderPresent(Renderer);
        SDL_Delay(1000);
        Paint(0, 0, 0, 0);
        return;
    }
    CurMap = OldMap;
    judgeColumn += 3 - judgeHotDelete;
    judgeMap += judgeHotDelete;
    judgeRecant = 0;
    Paint(0, 0, 0, 0);
}

void Recant() {
    if (!judgeRecant && judgeMap == NUM)
        return;
    if (!judgeRecant) {
        paintEach(0, 0, recantSurface);
        SDL_RenderPresent(Renderer);
        SDL_Delay(1000);
        Paint(0, 0, 0, 0);
        return;
    }

    CurMap = OldMap;
    int j;
    for (j = 0; j < 7; ++j) {
        if (!CurMap.column[j])
            break;
    }//j即是放置框的第一个空位
    judgeColumn = j;
    if (judgeDelete)
        deleteCount--;

    judgeMap++;
    judgeRecant--;
    Paint(0, 0, 0, 0);
}

void RandomAgain() {
    RandomFun();
    Paint(0, 0, 0, 0);
}

void paintEach(int x, int y, SDL_Surface *surface) {
    SDL_Texture *Texture = SDL_CreateTextureFromSurface(Renderer, surface);
    SDL_Rect Rect = {x,y, surface -> w, surface -> h};
    SDL_RenderCopy(Renderer, Texture, NULL, &Rect);
    SDL_DestroyTexture(Texture);
}

void PaintBlack(int x, int y) {
    SDL_Texture *blackTexture = SDL_CreateTextureFromSurface(Renderer, blackSurface);
    //改变透明度
    SDL_SetTextureBlendMode(blackTexture, SDL_BLENDMODE_BLEND);
    SDL_SetTextureAlphaMod(blackTexture, 100);
    SDL_Rect blackRect = { x, y, width, height};
    SDL_RenderCopy(Renderer, blackTexture, NULL, &blackRect);
    SDL_DestroyTexture(blackTexture);
}

void Paint(int x, int y, int val, int judge) {
    SDL_RenderClear(Renderer);
    paintEach(0, 0, PlaySurface);
    for (int i = 6; i >= 0; --i) {
        for (int j = 31; j >= 0; --j) {
            int roleName = CurMap.situation[i][j];
            if (roleName) {
                paintEach(Location[i][j][0], Location[i][j][1], RoleSurface[roleName]);
                if (isRecover(j, i))
                    PaintBlack(Location[i][j][0], Location[i][j][1]);
            }
        }
    }

    for (int i = 0; i < 7; ++i) {
        int roleName = CurMap.column[i];
        if (roleName)
            paintEach(ColumnLocation[i][0], ColumnLocation[i][1], RoleSurface[roleName]);
    }

    //画充能方块
    for (int i = 0; i < deleteCount && !isHot; ++i)
        paintEach(blockLocation[i][0], blockLocation[i][1], blockSurface);

    if ((int) length && isHot) {
        length -= 0.6;
        SDL_SetRenderDrawColor(Renderer, 255, 242, 0, 255);
        SDL_Rect rect = {blockLocation[0][0], blockLocation[0][1], (int) length, blockSurface->h};
        SDL_RenderDrawRect(Renderer, &rect);
        SDL_RenderFillRect(Renderer, &rect);
    }
    if ((int) length == 0){
        isHot = 0;
        length = 255;
        deleteCount = 0;
        isHotEnd = 1;
    }

    if (isPause) {
        paintEach(10, 120, PauseSurface);
        paintEach(390, 80, pauseXMSurface);
    }
    else
        paintEach(10, 120, GoingSurface);

    if (judgeMusic)
        paintEach(80, 120, musicGo);
    else
        paintEach(80, 120, musicPause);

    if (judge)
        paintEach(x, y, RoleSurface[val]);

    printTime();
    SDL_RenderPresent(Renderer);
}

void printTime() {
    int timeInterval;
    if (isPause) {
        tempTime = SDL_GetTicks();
        timeInterval = (int) (endTime - startTime - Temp) / 1000;
        timeJudge = 1;
    } else {
        if(timeJudge) {
            timeJudge = 0;
            Temp += tempTime - endTime;//计算暂停的总时间
        }
        endTime = SDL_GetTicks();
        timeInterval = (int) (endTime - startTime - Temp) / 1000;
    }
    if (timeFont == NULL) {
        SDL_Log("font can't be found\n");
        return;
    }
    SDL_Color fontColor = {0, 0, 0, 255};
    sprintf(timeChar, "%.2d:%.2d:%.2d", timeInterval / 3600, timeInterval / 60 % 60, timeInterval % 60);
    SDL_Surface *timeSurface = TTF_RenderUTF8_Blended(timeFont, timeChar, fontColor);
    paintEach(170, 120, timeSurface);
    SDL_FreeSurface(timeSurface);
}

void gameOverWin() {
    SDL_RenderClear(Renderer);
    paintEach(0, 0, WinSurface);
    SDL_RenderPresent(Renderer);
    SDL_Delay(2000);
    reStart();
}

void gameOverLose() {
    SDL_RenderClear(Renderer);
    paintEach(0, 0, LoseSurface);
    SDL_RenderPresent(Renderer);
    SDL_Delay(2000);
    reStart();
}

void reStart() {
    //归零
    for (int i = 0; i < 7; ++i) {
        OldMap.column[i] = CurMap.column[i] = 0;
    }
    isHot = 0;
    deleteCount = 0;
    judgeRecant = 0;
    judgeHotDelete = 0;
    isPause = 0;
    Temp = 0;
    timeJudge = 0;
    judgeMusic = 1;
    judgeColumn = 0;
    judgeMap = NUM;
    paintEach(0, 0, MainSurface);
    SDL_RenderPresent(Renderer);
    PlayMusic();
}

void Quit(){
    //free图片内存，防止内存泄露
    SDL_FreeSurface(MainSurface);
    SDL_FreeSurface(PlaySurface);
    SDL_FreeSurface(WinSurface);
    SDL_FreeSurface(LoseSurface);
    SDL_FreeSurface(recantSurface);
    SDL_FreeSurface(blockSurface);
    SDL_FreeSurface(blackSurface);
    SDL_FreeSurface(GoingSurface);
    SDL_FreeSurface(PauseSurface);
    SDL_FreeSurface(pauseXMSurface);
    SDL_FreeSurface(ruleSurface);
    SDL_FreeSurface(musicPause);
    SDL_FreeSurface(musicGo);
    for (int i = 0; i < 11; ++i) {
        SDL_FreeSurface(RoleSurface[i]);
    }
    TTF_CloseFont(timeFont);//关闭字体
    Mix_FreeMusic(BackSound);
    Mix_FreeMusic(HotSound);
    Mix_Quit();
    SDL_DestroyWindow(Window);
    SDL_DestroyRenderer(Renderer);
    SDL_Quit();//退出程序
}









