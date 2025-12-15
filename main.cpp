#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
using namespace std;

int main(int, char**) {
    // sdl初始化
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        cerr<<"SDL init error: "<<SDL_GetError()<<endl;
        return 1;
    }
    // 创建窗口
    SDL_Window *window = SDL_CreateWindow("hello world", 100, 100, 800, 600, SDL_WINDOW_SHOWN);

    // 创建渲染器
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) != (IMG_INIT_PNG | IMG_INIT_JPG)) {
        cerr<<"SDL image init error: "<<IMG_GetError()<<endl;
        return 1;
    }
    SDL_Texture *texture = IMG_LoadTexture(renderer, "assets/image/bg.png");

    // 渲染循环
    while(true) {
        SDL_Event event;
        if (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                break;
            }
        }
        SDL_RenderClear(renderer);
        // 画一个长方形
        SDL_Rect rect = {100, 100, 200, 200};
        SDL_SetRenderDrawColor(renderer, 255,0,0,255);

        SDL_RenderFillRect(renderer, &rect);
        SDL_SetRenderDrawColor(renderer, 0,0,0,255);

        // 画图片
        SDL_Rect dstrect = {200, 200, 300, 400};
        SDL_RenderCopy(renderer, texture, NULL, &dstrect);
        // 展示
        SDL_RenderPresent(renderer);

    }
    // 清理图片资源
    SDL_DestroyTexture(texture);
    IMG_Quit();

    // 清理并退出
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}