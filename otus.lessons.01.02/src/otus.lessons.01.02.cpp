#include <iostream>

#include <spdlog/spdlog.h>
#include <boost/lexical_cast.hpp>
#include <SDL2/SDL.h>

#include "XY.h"
#include "queue_processor.h"

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_real_distribution<> urd(0.0, 1.0);

long window_width;
long window_height;

int main()
{
    gen.seed(std::time(nullptr));

    auto console = spdlog::stdout_logger_mt("console");
    console->info("Wellcome!");

    if (SDL_Init(SDL_INIT_VIDEO) != 0){
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_DisplayMode display;
    if(SDL_GetCurrentDisplayMode(0, &display) != 0) {
        console->error("SDL_GetCurrentDisplayMode Error: {0:x}", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    console->info("Display: width: {0}; height: {1}", display.w, display.h);

    window_width = display.w >> 1;
    window_height = display.h >> 1;

    SDL_Window *win = SDL_CreateWindow(
        "Hellow World!", 
        SDL_WINDOWPOS_CENTERED, 
        SDL_WINDOWPOS_CENTERED, 
        window_width, 
        window_height, 
        SDL_WINDOW_SHOWN//|SDL_WINDOW_FULLSCREEN_DESKTOP
    );
    if (win == nullptr){
        console->error("SDL_CreateWindow Error: {0:x}", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Surface *scr = SDL_GetWindowSurface(win);
    SDL_Surface *img = SDL_CreateRGBSurface(0, scr->w, scr->h, 32, 0, 0, 0, 0);

    auto start = std::chrono::system_clock::now();
    auto last = start;

    int count = 0;
    int last_count = count;
    double time_step = 0.0;

    SDL_Event event;

    bool run = true;
    while(run)
    {
        auto loop_start = std::chrono::system_clock::now();
        ++count;

        SDL_LockSurface(img);

        SDL_UnlockSurface(img);

        SDL_BlitSurface(img, nullptr, scr, nullptr);

        SDL_UpdateWindowSurface(win);

        while(SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT || event.type == SDL_KEYDOWN || event.type == SDL_KEYUP) {
                run = false;
            }
        }

        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> full_elapsed = end-start;
        std::chrono::duration<double> last_elapsed = end-last;
        std::chrono::duration<double> loop_elapsed = end-loop_start;
        time_step = loop_elapsed.count();

        if(!run || last_elapsed.count() >= 1) {
            int frames = count - last_count;
            double fps = ((double)frames) / last_elapsed.count();

            SDL_SetWindowTitle(win, ("Hello World! FPS: " + boost::lexical_cast<std::string>(fps)).c_str());

            console->info("[{0} / {1}]: fps: {2}", full_elapsed.count(), count, fps);

            last = end;
            last_count = count;
        }
    }

    SDL_FreeSurface(img);
    SDL_FreeSurface(scr);

    SDL_DestroyWindow(win);
    SDL_Quit();

    console->info("Goodbye!");
}
