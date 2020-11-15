#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include "PathfinderInterface.h"
using namespace std;

  const int X_SIZE = 5;
  const int Y_SIZE = 5;
  const int Z_SIZE = 5;
  const int BACKGROUND = 1;
  const int WALL = 0;
  const int TEMPORARY = 2; // Used to show this path has been explored
	const int PATH = 3;
	
	

class Pathfinder: public PathfinderInterface
{

public:
    Pathfinder() {
				for(int i = 0; i < Z_SIZE; i++) {
   for(int j = 0; j < Y_SIZE; j++) {
      for(int k = 0; k < X_SIZE; k++) {
					maze[k][j][i] = 1;
				
      }
   }
	}
		}
    virtual ~Pathfinder() {}

    string toString() const;
		
    void createRandomMaze();
    bool importMaze(string file_name);
    vector<string> solveMaze();

protected:
	bool findPath(int maze[X_SIZE][Y_SIZE][Z_SIZE], int x, int y, int z);
	vector<string> solution;
	int maze[X_SIZE][Y_SIZE][Z_SIZE]; // To hold values

};