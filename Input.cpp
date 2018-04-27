#include "Input.h"

Input::Input() {

}

Input::~Input() {

}


bool Input::getStartClick(SDL_Event* userAction){
	//poll for a mouse click
	if(userAction->type == SDL_MOUSEBUTTONDOWN){
		//get the position of the mouse at click
		int x, y;
		SDL_GetMouseState(&x, &y);

		//check if the start button was clicked
		if((x > iStart.x) && (x < (iStart.x+iStart.w))  && (y > iStart.y) && (y < (iStart.y+iStart.h))){
			return true;
		}
	}

	return false;
}

bool Input::getPauseClick(SDL_Event* userAction){
	//poll for a mouse click
	if(userAction->type == SDL_MOUSEBUTTONDOWN){
		//get the position of the mouse at click
		int x, y;
		SDL_GetMouseState(&x, &y);

		//check if the pause button was clicked
		if((x > iPause.x) && (x < (iPause.x+iPause.w))  && (y > iPause.y) && (y < (iPause.y+iPause.h))){
			return true;
		}
	}

	return false;
}

bool Input::getClearClick(SDL_Event* userAction){
	//poll for a mouse click
	if(userAction->type == SDL_MOUSEBUTTONDOWN){
		//get the position of the mouse at click
		int x, y;
		SDL_GetMouseState(&x, &y);

		//check if the clear button was clicked
		if((x > iClear.x) && (x < (iClear.x+iClear.w))  && (y > iClear.y) && (y < (iClear.y+iClear.h))){
			return true;
		}
	}

	return false;
}

//getCellClick: if user clicks anywhere in the grid, it will make that cell alive, here it returns an int, telling the grid which one to activate
SDL_Point Input::getCellClick(SDL_Event* userAction){
	SDL_Point whichCell = {-1, -1};

	//poll for mouse clicks
	if(userAction->type == SDL_MOUSEBUTTONDOWN){
		//allow user to move mouse while holding the button and keep setting cells (need keystates)
		//get the position of the mouse at click
		int x, y;
		SDL_GetMouseState(&x, &y);

		//check if the cell box was clicked
		if((x > iCells.x) && (x < (iCells.x+iCells.w))  && (y > iCells.y) && (y < (iCells.y+iCells.h))){
			//take the border length off the clicks to 0 the grid to the corner (makes math easier)
			x -= 5;
			y -= 5;

			//determine what cell was clicked
			int whichCol = x/5;
			int whichRow = y/5;
			whichCell.x = whichCol;
			whichCell.y = whichRow;
		}
	}

	//return the cell if successful
	return whichCell;
}

