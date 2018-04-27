#include "Swarm.h"

Swarm::Swarm() {

}

Swarm::~Swarm() {

}

//blankLife: inserts false into each spot of the life array
void Swarm::blankLife(){
	for(int row = 0; row < NUMBEROFROWS; row++){
		for(int col = 0; col < NUMBEROFCOLUMNS; col++){
			sLife[col][row] = false;
		}
	}
}

//blankNext: inserts false into each spot of the next array
void Swarm::blankNext(){
	for(int row = 0; row < NUMBEROFROWS; row++){
		for(int col = 0; col < NUMBEROFCOLUMNS; col++){
			sNext[col][row] = false;
		}
	}
}

//getCellState: takes a column and a row and returns the bool found there, used by rendering to get which squares to make visible
bool Swarm::getCellState(int whatColumn, int whatRow){
	return sLife[whatColumn][whatRow];
}

//countLiveNeighbors: takes a position in the 2-d array and determines how many adjacent values (up, down, left, right, and diagonals) are true
int Swarm::countLiveNeighbors(int column, int row){
	//make a number to hold how many surrounding Cells are alive(true)
	int numNeighbors = 0;

	//check the 8 surrounding cells for life, making sure to not check outside the bounds of the array
	if(sLife[column+1][row] && column < NUMBEROFCOLUMNS-1){
		numNeighbors++;
	}
	if(sLife[column-1][row] && column > 0){
		numNeighbors++;
	}
	if(sLife[column][row+1] && row < NUMBEROFROWS-1){
		numNeighbors++;
	}
	if(sLife[column][row-1] && row > 0){
		numNeighbors++;
	}
	if(sLife[column+1][row+1] && column < NUMBEROFCOLUMNS-1 && row < NUMBEROFROWS-1){
		numNeighbors++;
	}
	if(sLife[column-1][row-1] && column > 0 && row > 0){
		numNeighbors++;
	}
	if(sLife[column+1][row-1] && column < NUMBEROFCOLUMNS-1 && row > 0){
		numNeighbors++;
	}
	if(sLife[column-1][row+1] && column > 0 && row < NUMBEROFROWS-1){
		numNeighbors++;
	}

	//return the final number of neighbors
	return numNeighbors;
}

//check each Cell for its surroundings and change it according to the rules
void Swarm::getNextCellState(){
	for(int y = 0; y < NUMBEROFROWS; y++){
		for(int x = 0; x < NUMBEROFCOLUMNS; x++){
			//if the Cell is active
			if(sLife[x][y]){
				switch(countLiveNeighbors(x, y)){
				//if the Cell has 2 or 3 live neighbors, let it live
				case 2:
					sNext[x][y] = true;
					break;
				case 3:
					sNext[x][y] = true;
					break;
				///* enabling this will cause the cells to take hold and propogate as if a petri dish colony
				case 4:
					sNext[x][y] = true;
					break;
				//*/
				//if it has less than 2 or more than 3, make it die
				default:
					sNext[x][y] = false;
					break;
				}
			}

			//if the Cell is inactive
			else{
				//if it has exactly 3 neighbors, revive it
				if(countLiveNeighbors(x, y) == 3){
					sNext[x][y] = true;
				}
			}
		}
	}
}

//
void Swarm::updateCells(){
	for(int y = 0; y < NUMBEROFROWS; y++){
		for(int x = 0; x < NUMBEROFCOLUMNS; x++){
			sLife[x][y] = sNext[x][y];
		}
	}
}

//setCells: used to test, sets some of the life array to true
void Swarm::setCells(int col, int row){
	sLife[col][row] = true;
}
