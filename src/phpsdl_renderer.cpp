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
#include <SDL2/SDL_image.h>

/**
 * --------------
 * == RENDERER ==
 * --------------
 */

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
 * Copy a texture
 */
void PHPSDLRenderer::copy(Php::Parameters &parameters)
{
    Php::Value object = parameters[0];
    
    // make sure its a SDL Texture
    if (!object.instanceOf("SDLTexture")) throw Php::Exception("First argument must be an instance of SDLTexture.");
    
    // cast the PHP object back into a C++ class
    PHPSDLTexture *texture = (PHPSDLTexture *)object.implementation();
    
    SDL_Rect rect;
    
    rect.x = (double) parameters[1];
    rect.y = (double) parameters[2];
    rect.w = (double) parameters[3];
    rect.h = (double) parameters[4];
    
    SDL_RenderCopy(_renderer, texture->getTexture(), NULL, &rect);
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


/**
 * --------------
 * == TEXTURES  ==
 * --------------
 */
void PHPSDLTexture::__construct(Php::Parameters &parameters)
{
    Php::Value object = parameters[0];
    
    // make sure its a SDL Renderer
    if (!object.instanceOf("SDLRenderer")) throw Php::Exception("First argument must be an instance of SDLRenderer.");
    
    // cast the PHP object back into a C++ class
    PHPSDLRenderer *renderer = (PHPSDLRenderer *)object.implementation();
    
    // the path
    std::string path = parameters[1];
    
    IMG_Init(IMG_INIT_PNG);
    
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    
    _texture = SDL_CreateTextureFromSurface(renderer->getRenderer(), loadedSurface);
    
    SDL_FreeSurface(loadedSurface);
}

/**
 * PHP Destructor
 */
void PHPSDLTexture::__destruct()
{
    //    if (_window != nullptr)
    //    {
    //        SDL_DestroyWindow( _window );
    //    }
}



