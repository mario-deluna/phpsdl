//
//  phpsdl_renderer.cpp
//  phpsdl
//
//  Created by Mario Döring on 07.04.17.
//  Copyright © 2017 Mario Döring. All rights reserved.
//

#include "phpsdl_renderer.h"
#include "phpsdl_window.h"
#include <SDL2/SDL.h>

/**
 *  PHP Constructor
 *  @param Php::Parameters &parameters
 */
void PHPSDLRenderer::__construct(Php::Parameters &parameters)
{
    Php::Value object = parameters[0];
    
    // make sure its a SDL Window
    if (!object.instanceOf("SDLWindow")) throw Php::Exception("First argument must be an instance of SDLWindow.");
    
    // cast the PHP object back into a C++ class
    PHPSDLWindow *window = (PHPSDLWindow *)object.implementation();
    
    // assign the renderer
   _renderer = SDL_CreateRenderer(window->getWindow(), -1, SDL_RENDERER_PRESENTVSYNC);
}

/**
 *  PHP Destructor
 */
void PHPSDLRenderer::__destruct()
{
//    if (_window != nullptr)
//    {
//        SDL_DestroyWindow( _window );
//    }
}
