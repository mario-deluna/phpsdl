/**
 * PHP SDL Extension 
 * @author: Mairo Döring
 */

/**
 *  Header
 */
#include "phpsdl_window.h"
#include <iostream>

/**
 *  PHP Constructor
 *  @param Php::Parameters &parameters
 */
void PHPSDLWindow::__construct(Php::Parameters &parameters)
{
	std::string _title = parameters[0].stringValue();
    
    _widht = parameters[3];
    _height = parameters[4];

	// create the window
	_window = SDL_CreateWindow(
        _title.c_str(),
        parameters[1], // posx
        parameters[2], // posy
        _widht, _height,
        SDL_WINDOW_SHOWN
    );
}

/**
 *  PHP Destructor
 */
void PHPSDLWindow::__destruct()
{
    if (_window != nullptr)
    {
        SDL_DestroyWindow( _window );
    }
}
