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
 * PHP Destructor
 */
void PHPSDLRenderer::__destruct()
{
//    if (_window != nullptr)
//    {
//        SDL_DestroyWindow( _window );
//    }
}

/**
 * Clear
 */
void PHPSDLRenderer::clear()
{
    SDL_RenderClear(_renderer);
}

/**
 * Present
 */
void PHPSDLRenderer::present()
{
    SDL_RenderPresent(_renderer);
}

/**
 * Set color
 */
void PHPSDLRenderer::setDrawColor(Php::Parameters &parameters)
{
    Php::Value r = parameters[0];
    Php::Value g = parameters[1];
    Php::Value b = parameters[2];
    Php::Value a = parameters[3];
    
    SDL_SetRenderDrawColor(_renderer, (int) r, (int) g, (int) b, (int) a);
}

/**
 * Draw rect
 */
void PHPSDLRenderer::drawRect(Php::Parameters &parameters)
{
    SDL_Rect rect;
    
    rect.x = (double) parameters[0];
    rect.y = (double) parameters[1];
    rect.w = (double) parameters[2];
    rect.h = (double) parameters[3];
    
    SDL_RenderFillRect(_renderer, &rect);
}





