#ifndef SCREEN_H_
#define SCREEN_H_

#include "SDL2/SDL.h"
#include <iostream>

#include "Texture.h"
#include "Swarm.h"
#include "Input.h"

using std::cout;
using std::endl;

class Screen {
public:
	Screen();
	~Screen();

	//initialize sdl and the program
	bool init();

	//get any images the program uses
	bool getMedia();

	//cycle through the program, making updates to the screen
	void loop();
	void render();

	//shut the program down
	void close();

	//define window dimensions
	static const int SCREEN_WIDTH = 911;
	static const int SCREEN_HEIGHT = 656;

	//declare window and renderer
	SDL_Renderer* sRenderer;
	SDL_Window* sWindow;

	//define framerate
	static const int FRAMERATE = 50; //in milliseconds per frame

	//make an event to catch user actions
	SDL_Event sAction;

private:
	//create an instance of the swarm and input
	Swarm swarm;
	Input input;

	//create a texture for the background image
	Texture background;

	//make a bool to control when the loop ends
	bool sLoop;
	bool sRunning;
};

#endif /* SCREEN_H_ */
