//c++ GoL
/*This will create a grid that can be filled with pixels by clicking the grid's empty spots
 *once the program is started, the drawn pixels will populate the grid based on a set of rules
 *each pixel can see it's neighbors, and decides whether to activate or deactivate, depending on how many neighbors it has
 *if an inactive pixel has exactly 3 neighbors, it will activate
 *once the program can be paused or reset
 * need: class to place images on screen,
 * class to handle user clicks and input
 * class to handle each pixel
 * maybe a class to handle the entire set of pixels
 * class to handle how a pixel decides what to do
 */

#include "Screen.h"

//create a screen
Screen* screen = new Screen;

int main(int argc, char* argv[]){
	//initialize the program
	if(!screen->init()){
		return -1;
	}

	//fetch any images stored on the computer that the program will use
	if(!screen->getMedia()){
		return -2;
	}

	//allow text input and run the main loop
	SDL_StartTextInput();
	screen->loop();
	SDL_StopTextInput();

	delete screen;
	return 0;
}
