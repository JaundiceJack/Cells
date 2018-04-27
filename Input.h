/* the purpose of input is to take user actions like mouse clicks on the screen and translate it to a reaction on the screen
*/

#ifndef INPUT_H_
#define INPUT_H_

#include "SDL2/SDL.h"

class Input {
public:
	Input();
	~Input();

	//get the start and pause presses
	bool getStartClick(SDL_Event* userAction);
	bool getPauseClick(SDL_Event* userAction);
	bool getClearClick(SDL_Event* userAction);
	SDL_Point getCellClick(SDL_Event* userAction);

private:
	//these are the positions and sizes of the 3 buttons
	const SDL_Rect iStart = {438, 614, 35, 34};
	const SDL_Rect iPause = {494, 614, 34, 34};
	const SDL_Rect iClear = {380, 614, 37, 34};
	const SDL_Rect iCells = {5, 5, 901, 601};
};

#endif /* INPUT_H_ */
