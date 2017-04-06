/**
 * PHP SDL Extension
 * 
 * @author: Mairo Döring
 */

/**
 *  Libraries used.
 */
#include <phpcpp.h>
#include <SDL2/SDL.h>

// import
#include "phpsdl.h"
#include "phpsdl_window.h"

// Symbols are exported according to the "C" language
extern "C" 
{
    // export the "get_module" function that will be called by the Zend engine
    PHPCPP_EXPORT void *get_module()
    {
        // create extension
        static Php::Extension extension("phpsdl","1.0");
        
        // add the SDL Constants
        extension.add(Php::Constant("PHPSDL_INIT_TIMER", PHPSDL_INIT_TIMER));


//         const int PHPSDL_INIT_TIMER             = SDL_INIT_TIMER;
// const int PHPSDL_INIT_AUDIO             = SDL_INIT_AUDIO;
// const int PHPSDL_INIT_VIDEO             = SDL_INIT_VIDEO;
// const int PHPSDL_INIT_JOYSTICK          = SDL_INIT_JOYSTICK;
// const int PHPSDL_INIT_HAPTIC            = SDL_INIT_HAPTIC;
// const int PHPSDL_INIT_GAMECONTROLLER    = SDL_INIT_GAMECONTROLLER;
// const int PHPSDL_INIT_EVENTS            = SDL_INIT_EVENTS;
// const int PHPSDL_INIT_NOPARACHUTE       = SDL_INIT_NOPARACHUTE;
// const int PHPSDL_INIT_EVERYTHING        = SDL_INIT_EVERYTHING;

        // SDL init
        extension.add<PHPSDL_Init>("SDL_Init", {
            Php::ByVal("flag", Php::Type::Numeric)
        });

        // SDL Window
        extension.add<PHPSDL_CreateWindow>("SDL_CreateWindow");
        
        // return the extension module
        return extension.module();
    }
}
