//
//  phpsdl_renderer.hpp
//  phpsdl
//
//  Created by Mario Döring on 07.04.17.
//  Copyright © 2017 Mario Döring. All rights reserved.
//

#ifndef phpsdl_renderer_h
#define phpsdl_renderer_h

#include <phpcpp.h>
#include <SDL2/SDL.h>

/**
 * SDL Renderer class
 * ---
 */
class PHPSDLRenderer : public Php::Base
{
private:
    // the renderer itself
    SDL_Renderer *_renderer = nullptr;
    
public:
    
    /**
     * c++ constructors
     */
    PHPSDLRenderer() {}
    virtual ~PHPSDLRenderer() {}
    
    /**
     * access
     */
    inline SDL_Renderer *getRenderer() { return _renderer; }
    
    /**
     * PHP constructors
     */
    void __construct(Php::Parameters &parameters);
    void __destruct();
    
    
    /**
     * Drawing
     */
    void clear();
    void present();
    void copy(Php::Parameters &parameters);
    void setDrawColor(Php::Parameters &parameters);
    void drawRect(Php::Parameters &parameters);
};

/**
 * SDL Texture class
 * ---
 */
class PHPSDLTexture : public Php::Base
{
private:
    // the renderer itself
    SDL_Texture * _texture = nullptr;
    
public:
    
    /**
     * c++ constructors
     */
    PHPSDLTexture() {}
    virtual ~PHPSDLTexture() {}
    
    /**
     * access
     */
    inline SDL_Texture *getTexture() { return _texture; }
    
    /**
     * PHP constructors
     */
    void __construct(Php::Parameters &parameters);
    void __destruct();
};

#endif /* phpsdl_renderer_h */
