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
Php::Value PHPSDL_PollEvent()
{
    SDL_Event event;
    
    if (SDL_PollEvent(&event))
    {
        Php::Value event_return;
        
        event_return[0] = (int) event.type;
        
        switch (event.type) {
            case SDL_KEYDOWN:
            case SDL_KEYUP:
                
                event_return[1] = event.key.keysym.sym;
                
                break;
                
            default:
                
                break;
        }
        
        return event_return;
    }
    
    return nullptr;
}

