#include "Screen.h"

Screen::Screen() {
	sRenderer = NULL;
	sWindow = NULL;
	sLoop = true;
	sRunning = false;
}

Screen::~Screen() {
	close();
}

//init: starts sdl, makes a renderer and window, sets up basic program functions
bool Screen::init(){
	//start sdl
	if(SDL_Init(SDL_INIT_VIDEO) < 0){
		cout << "SDL failed to start." << endl;
		cout << "SDL Error: " << SDL_GetError() << endl;
		return false;
	}

	//make a window
	sWindow = SDL_CreateWindow("GOL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if(sWindow == NULL){
		cout << "SDL failed to create a window." << endl;
		cout << "SDL Error: " << SDL_GetError() << endl;
		SDL_Quit();
		return false;
	}

	//make a renderer
	sRenderer = SDL_CreateRenderer(sWindow, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
	if(sRenderer == NULL){
		cout << "SDL failed to create a renderer." << endl;
		cout << "SDL Error: " << SDL_GetError() << endl;
		SDL_DestroyWindow(sWindow);
		SDL_Quit();
		return false;
	}

	//initialize renderer draw color
	SDL_SetRenderDrawColor(sRenderer, 0, 0, 0, 255);

	//return true upon successful initialization
	return true;
}

//getMedia: fetch any images used on the computer
bool Screen::getMedia(){
	if(!background.loadImageFromFile(sRenderer, "Debug\\images\\background.png")){
		cout << "Background failed to load." << endl;
		return false;
	}

	return true;
}

//loop: iterate over the program, getting user input and changing the screen
void Screen::loop(){
	//get the swarm before entering the loop
	swarm.blankLife();
	swarm.blankNext();

	//make unsigned ints to hold how long the program has been running and limit updates to the screen
	unsigned int currentTime;
	unsigned int lastTime = 0;

	//start the loop
	while(sLoop){
		//set the current time to the number of milliseconds since starting
		currentTime = SDL_GetTicks();

		//get input
		while(SDL_PollEvent(&sAction) != 0){
			//if x or escape are pressed, program will exit
			if(sAction.type == SDL_QUIT || (sAction.type == SDL_KEYDOWN && sAction.key.keysym.sym == SDLK_ESCAPE)){
				sLoop = false;
			}

			//if the stop button is pressed,
			if(input.getPauseClick(&sAction)){
				sRunning = false;
			}

			//if the start button is pressed,
			if(input.getStartClick(&sAction)){
				sRunning = true;
			}

			//if the clear button is pressed,
			if(input.getClearClick(&sAction)){
				sRunning = false;
				swarm.blankLife();
				swarm.blankNext();
			}

			//get the cell clicks
			SDL_Point cellClick = input.getCellClick(&sAction);
			if(cellClick.x != -1){
				swarm.setCells(cellClick.x, cellClick.y);
			}
		}

		//make any changes
		if(currentTime > lastTime+FRAMERATE){
			//place updates on the screen
			render();

			//check that the program's not paused and updated the cells
			if(sRunning){
				swarm.getNextCellState();
				swarm.updateCells();
			}

			//update the time before next iteration
			lastTime = currentTime;
		}
	}
}

//render: place the images made by the program in the buffer to be rendered
void Screen::render(){
	//clear out the previous render
	SDL_RenderClear(sRenderer);
	//place the background on the screen
	background.render(sRenderer, 0, 0);

	//set the color to green
	SDL_SetRenderDrawColor(sRenderer, 0, 255, 0, 255);

	//draw green squares where a Cell is active
	for(int rows = 0; rows < swarm.NUMBEROFROWS; rows++){
		for(int cols = 0; cols < swarm.NUMBEROFCOLUMNS; cols++){
			//if the Cell here is active, draw a green square at it's point
			if(swarm.getCellState(cols, rows)){
				SDL_Rect cellSquare = {cols*5+5, rows*5+5, 5, 5};
				SDL_RenderFillRect(sRenderer, &cellSquare);
			}
		}
	}

	//set the color to black (background)
	SDL_SetRenderDrawColor(sRenderer, 0, 0, 0, 255);

	SDL_RenderPresent(sRenderer);
}

//close: shuts the program down
void Screen::close(){
	//get rid of renderer and window
	SDL_DestroyRenderer(sRenderer);
	SDL_DestroyWindow(sWindow);

	//shut down SDL
	if(SDL_WasInit(SDL_INIT_VIDEO)){
		SDL_Quit();
	}
}
