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
#include "phpsdl_renderer.h"
#include "phpsdl_event.h"

// Symbols are exported according to the "C" language
extern "C" 
{
    // export the "get_module" function that will be called by the Zend engine
    PHPCPP_EXPORT void *get_module()
    {
        // create extension
        static Php::Extension extension("phpsdl","1.0");
        
        // add the init SDL Constants
        extension.add(Php::Constant("SDL_INIT_TIMER", PHPSDL_INIT_TIMER));
        extension.add(Php::Constant("SDL_INIT_AUDIO", PHPSDL_INIT_AUDIO));
        extension.add(Php::Constant("SDL_INIT_VIDEO", PHPSDL_INIT_VIDEO));
        extension.add(Php::Constant("SDL_INIT_JOYSTICK", PHPSDL_INIT_JOYSTICK));
        extension.add(Php::Constant("SDL_INIT_HAPTIC", PHPSDL_INIT_HAPTIC));
        extension.add(Php::Constant("SDL_INIT_GAMECONTROLLER", PHPSDL_INIT_GAMECONTROLLER));
        extension.add(Php::Constant("SDL_INIT_EVENTS", PHPSDL_INIT_EVENTS));
        extension.add(Php::Constant("SDL_INIT_NOPARACHUTE", PHPSDL_INIT_NOPARACHUTE));
        extension.add(Php::Constant("SDL_INIT_EVERYTHING", PHPSDL_INIT_EVERYTHING));

        /**
         * SDL Main
         */
        // init
        extension.add<PHPSDL_Init>("SDL_Init", {
            Php::ByVal("flag", Php::Type::Numeric)
        });
        
        // quit
        extension.add<PHPSDL_Quit>("SDL_Quit");
        
        // get ticks
        extension.add<PHPSDL_GetTicks>("SDL_GetTicks");
        
        // delay
        extension.add<PHPSDL_Delay>("SDL_Delay", {
            Php::ByVal("delay", Php::Type::Numeric)
        });
        
        
        /**
         * SDL Events
         * ----------
         */
        extension.add(Php::Constant("SDL_QUIT", PHPSDL_QUIT));
        
        // pump events
        extension.add<PHPSDL_PumpEvents>("SDL_PumpEvents");
        
        // pump events
        extension.add<PHPSDL_PollEvent>("SDL_PollEvent");
        
        
        /**
         * SDL Window
         * ----------
         */
        Php::Class<PHPSDLWindow> sdlWindow("SDLWindow");

        sdlWindow.method<&PHPSDLWindow::__construct>("__construct", Php::Public, {
            Php::ByVal("string", Php::Type::String),
        });

        sdlWindow.method<&PHPSDLWindow::__destruct>("__destruct");

        // add the class
        extension.add(std::move(sdlWindow));
        
        /**
         * SDL Renderer
         * ------------
         */
        Php::Class<PHPSDLRenderer> sdlRenderer("SDLRenderer");
        
        sdlRenderer.method<&PHPSDLRenderer::__construct>("__construct", Php::Public, {
            Php::ByVal("window", Php::Type::Object),
        });
        
        sdlRenderer.method<&PHPSDLRenderer::__destruct>("__destruct");
        
        // clear
        sdlRenderer.method<&PHPSDLRenderer::clear>("clear");
        
        // present
        sdlRenderer.method<&PHPSDLRenderer::present>("present");
        
        // set color
        sdlRenderer.method<&PHPSDLRenderer::setDrawColor>("setDrawColor", Php::Public, {
            Php::ByVal("r", Php::Type::Numeric),
            Php::ByVal("g", Php::Type::Numeric),
            Php::ByVal("b", Php::Type::Numeric),
            Php::ByVal("a", Php::Type::Numeric),
        });
        
        // set color
        sdlRenderer.method<&PHPSDLRenderer::drawRect>("drawRect", Php::Public, {
            Php::ByVal("x", Php::Type::Numeric),
            Php::ByVal("y", Php::Type::Numeric),
            Php::ByVal("w", Php::Type::Numeric),
            Php::ByVal("h", Php::Type::Numeric),
        });
        
        // add the class
        extension.add(std::move(sdlRenderer));
        
        // return the extension module
        return extension.module();
    }
}
