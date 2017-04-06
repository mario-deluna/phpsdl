/**
 * PHP SDL Extension 
 * @author: Mairo Döring
 */

/**
 *  Header
 */
#include "phpsdl_window.h"

/**
 *  PHP Constructor
 *  @param Php::Parameters &parameters
 */
void PHPSDLWindow::__construct(Php::Parameters &parameters)
{
	Php::Value title = parameters[0];

	// assign the title
	_title = title.stringValue();

	// create the window
	_window = SDL_CreateWindow(
        _title.c_str(),
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        _widht, _height,
        SDL_WINDOW_SHOWN
    );

    SDL_Event event;
    
    if (SDL_PollEvent(&event))
    {

    }

    SDL_Delay(5000);
}

/**
 *  PHP Destructor
 */
void PHPSDLWindow::__destruct()
{
	// nothing todo
}