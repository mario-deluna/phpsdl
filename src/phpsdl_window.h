/**
 * PHP Sdl window header
 */
#ifndef PHPSDL_WINDOW_H_
#define PHPSDL_WINDOW_H_

#include <iostream>
#include <phpcpp.h>
#include <SDL2/SDL.h>

/**
 * SDL Window class
 * ---
 */
class PHPSDLWindow : public Php::Base
{
private:
    std::string _title;
    int _widht = 800;
    int _height = 600;

    // the window
    SDL_Window *_window = nullptr;

public:

	/**
	 * c++ constructors
	 */
	PHPSDLWindow() {}
	virtual ~PHPSDLWindow() {}

	/**
	 * PHP constructors
	 */
	void __construct(Php::Parameters &parameters);
    void __destruct();
};

#endif /* PHPSDL_WINDOW_H_ */