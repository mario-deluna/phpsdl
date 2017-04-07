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
 * SDL Window class
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
     * PHP constructors
     */
    void __construct(Php::Parameters &parameters);
    void __destruct();
};

#endif /* phpsdl_renderer_h */
