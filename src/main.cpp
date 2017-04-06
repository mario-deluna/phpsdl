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
        
        // add the init SDL Constants
        extension.add(Php::Constant("PHPSDL_INIT_TIMER", PHPSDL_INIT_TIMER));
        extension.add(Php::Constant("PHPSDL_INIT_AUDIO", PHPSDL_INIT_AUDIO));
        extension.add(Php::Constant("PHPSDL_INIT_VIDEO", PHPSDL_INIT_VIDEO));
        extension.add(Php::Constant("PHPSDL_INIT_JOYSTICK", PHPSDL_INIT_JOYSTICK));
        extension.add(Php::Constant("PHPSDL_INIT_HAPTIC", PHPSDL_INIT_HAPTIC));
        extension.add(Php::Constant("PHPSDL_INIT_GAMECONTROLLER", PHPSDL_INIT_GAMECONTROLLER));
        extension.add(Php::Constant("PHPSDL_INIT_EVENTS", PHPSDL_INIT_EVENTS));
        extension.add(Php::Constant("PHPSDL_INIT_NOPARACHUTE", PHPSDL_INIT_NOPARACHUTE));
        extension.add(Php::Constant("PHPSDL_INIT_EVERYTHING", PHPSDL_INIT_EVERYTHING));

        /**
         * SDL INIT
         */
        extension.add<PHPSDL_Init>("SDL_Init", {
            Php::ByVal("flag", Php::Type::Numeric)
        });

        
        /**
         * SDL Window
         */
        Php::Class<PHPSDLWindow> sdlWindow("SDLWindow");

        sdlWindow.method<&PHPSDLWindow::__construct>("__construct", Php::Public, {
            Php::ByVal("string", Php::Type::String),
        });

        sdlWindow.method<&PHPSDLWindow::__destruct>("__destruct");

        // add the class
        extension.add(std::move(sdlWindow));
        
        // return the extension module
        return extension.module();
    }
}
