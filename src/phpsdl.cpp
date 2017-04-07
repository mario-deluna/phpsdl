/**
 * PHP SDL Extension
 * @author: Mairo Döring
 */

/**
 *  Header
 */
#include "phpsdl.h"

/**
 *  SDL_Init
 */
Php::Value PHPSDL_Init(Php::Parameters &params)
{
    Php::Value flag = params[0];

    return SDL_Init((int)flag);
}

/**
 * Quit SDL
 */
void PHPSDL_Quit()
{
    SDL_Quit();
}

/**
 *  my_return_value_function()
 */
// void my_return_value_function()
// {
//     if (SDL_Init(SDL_INIT_VIDEO) != 0)
//     {
//         std::cerr << "SDL failed to initialize." << SDL_GetError() << std::endl;
//     }

//     SDL_Window *window = SDL_CreateWindow(
//         "SDL Window",
//         SDL_WINDOWPOS_UNDEFINED,
//         SDL_WINDOWPOS_UNDEFINED,
//         800, 600,
//         SDL_WINDOW_SHOWN
//     );

//     SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);

//     while(1) {

//         SDL_Event event;
    
//         if (SDL_PollEvent(&event))
//         {
//             switch (event.type) {
//                 default:
//                     break;
//             }
//         }

//         SDL_SetRenderDrawColor(renderer, 0, 0, 200, 255);
//         SDL_RenderClear(renderer);
        
//         SDL_Rect rect;
        
//         rect.w = 120;
//         rect.h = 120;
//         rect.x = 200;
//         rect.y = 200;
        
//         SDL_SetRenderDrawColor(renderer, 200, 0, 200, 255);
//         SDL_RenderFillRect(renderer, &rect);
        
//         SDL_RenderPresent(renderer);
//     }
// }
