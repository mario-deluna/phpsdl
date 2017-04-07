//
//  phpsdl_event.cpp
//  phpsdl
//
//  Created by Mario Döring on 07.04.17.
//  Copyright © 2017 Mario Döring. All rights reserved.
//

#include "phpsdl_event.h"

/**
 * Pump events
 */
void PHPSDL_PumpEvents()
{
    SDL_PumpEvents();
}

/**
 * Poll events
 */
Php::Value PHPSDL_PollEvent(Php::Parameters &parameters)
{
    SDL_Event event;
    
    if (SDL_PollEvent(&event))
    {
        return event.type
    }
    
    return nullptr;
}
