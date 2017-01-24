#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>


int main(int argc, char *argv[])
{
    if( SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) !=0 )
    {
        std::cout << "SDL Init Failed! " << SDL_GetError() << std::endl;
        return 1;
    }

    if( IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG )
    {
        std::cout << "SDL_Image Init Failed! " << IMG_GetError() <<std::endl;
        SDL_Quit();
        return 1;
    }

    if( TTF_Init() != 0 )
    {
        std::cout << "SDL_TTF Init Failed! " << TTF_GetError() << std::endl;
        IMG_Quit();
        SDL_Quit();
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);
    if (!window)
    {
        std::cout << "SDL Window Creation Failed! " << SDL_GetError() << std:: endl;
        TTF_Quit();
        IMG_Quit();
        SDL_Quit();
        return 1;
    }
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    if(!renderer)
    {
        std::cout << "SDL Renderer Creation Failed! " << SDL_GetError() << std:: endl;
        TTF_Quit();
        IMG_Quit();
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }


    //bool quit = false;
    enum State
    {
        STATE_MENU,
        STATE_QUIT,
        STATE_PLAYING
    };

    State gameState = STATE_MENU;


    //start render loop

    while(gameState != STATE_QUIT)
    {
        //start event handler

        SDL_Event event;

        //react to input based on game state
        switch(gameState)
        {
        case STATE_MENU:
            std::cout << "Entered menu state" << std::endl;

            while( SDL_PollEvent(&event) )
            {
                switch(event.type)
                {
                case SDL_QUIT:
                        gameState = STATE_QUIT;
                        break;

                case SDL_KEYDOWN:
                    switch(event.key.keysym.sym)
                    {
                        case SDLK_q:
                        gameState = STATE_QUIT;
                        break;

                        case SDLK_1:
                        gameState = STATE_MENU;
                        std::cout << "Changed to menu state" << std::endl;
                        break;

                        case SDLK_2:
                        gameState = STATE_PLAYING;
                        std::cout << "Changed to playing state" << std::endl;
                        break;
                    }
                }
            }
            break;

        case STATE_PLAYING:
            std::cout << "Entered playing state" << std::endl;

            while( SDL_PollEvent(&event) )
            {
                switch(event.type)
                {
                case SDL_QUIT:
                        gameState = STATE_QUIT;
                        break;

                case SDL_KEYDOWN:
                    switch(event.key.keysym.sym)
                    {
                        case SDLK_q:
                        gameState = STATE_QUIT;
                        break;

                        case SDLK_1:
                        gameState = STATE_MENU;
                        std::cout << "Changed to menu state" << std::endl;
                        break;

                        case SDLK_2:
                        gameState = STATE_PLAYING;
                        std::cout << "Changed to playing state" << std::endl;
                        break;
                    }
                }
            }

            break;
        }


        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);

    }


    //Cleanup
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    TTF_Quit();
    SDL_Quit();
}
