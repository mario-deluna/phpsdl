/**
 * PHP SDL Extension 
 * @author: Mairo Döring
 */

/**
 *  Header
 */
#include "phpsdl_window.h"

void PHPSDL_CreateWindow()
{
    SDL_Window *window = SDL_CreateWindow(
        "SDL Window",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        800, 600,
        SDL_WINDOW_SHOWN
    );
}