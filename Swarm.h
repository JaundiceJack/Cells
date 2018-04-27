#ifndef SWARM_H_
#define SWARM_H_

#include <vector>
#include <iostream>
#include <cstring>

using std::vector;
using std::cout;
using std::endl;

class Swarm {
public:
	Swarm();
	~Swarm();

	//fill the array with false to blank it
	void blankLife();
	void blankNext();

	//get the state at a given coord
	bool getCellState(int whatColumn, int whatRow);
	void getNextCellState();

	//once the program ticks over, set the sLife values to the sNext values
	void updateCells();

	//count the number of live Cells surrounding the given Cell
	int countLiveNeighbors(int column, int row);

	//take 2 coordinates and set the sell there to true
	void setCells(int col, int row);


	//the number of Cells in each row and the number of rows
	static const int NUMBEROFCOLUMNS = 180;
	static const int NUMBEROFROWS = 120;

	//an array of the Cells' current states
	bool sLife[NUMBEROFCOLUMNS][NUMBEROFROWS];

	//an array of the Cells' next state after the tick
	bool sNext[NUMBEROFCOLUMNS][NUMBEROFROWS];
};

#endif /* SWARM_H_ */
