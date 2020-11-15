#include "Pathfinder.h"
using namespace std;


string Pathfinder::toString() const{
        stringstream ss;
        for(int i = 0; i < Z_SIZE; i++){
					if(i!=0){
						ss << '\n';
						ss << '\n';
					}
            for(int j = 0; j < Y_SIZE; j++){
							if(j!=0){
								ss << '\n';
							}
                for(int k = 0; k < X_SIZE; k++){
                    ss << maze[k][j][i];
										if (k != 4){
											ss << ' ';
										}
                }
            }
        }
				ss<< '\n';
        return ss.str();

}
void Pathfinder::createRandomMaze() {
        //Creates the array
        for(int i = 0; i < Z_SIZE; i++){
            for(int j = 0; j < Y_SIZE; j++){
                for(int k = 0; k < X_SIZE; k++){
                    maze[k][j][i] = rand() % 2;
                }
            }
        }
        maze[0][0][0] = 1;
        maze[4][4][4] = 1;
}

bool Pathfinder::importMaze(string file_name) {
   	
	int value_counter = 0;
        //cout << "importMaze from "<<file_name<<endl;
        ifstream test_file (file_name.c_str());
				 string line;
//The While loop counts the number of lines there are. Later, we compare it to what they should be.
				 while(getline(test_file, line)) {
					 value_counter++;
//This checks for any non 0 or 1's
					for(int s = 0; s < line.length(); s++){
					 if(isalpha(line.at(s))) {
							return false;
					 }												
					}
				 }

				         //Checks the number of input lines to ensure the input file has the correct amount
				if(value_counter != ((Y_SIZE * Z_SIZE))+(Z_SIZE-1)){
					return false;
				}
				 
			test_file.close();
			ifstream file (file_name.c_str());
        if (file.is_open()) {
            string line;
            for (int i = 0; i < Z_SIZE; i++) {
							if(i!=0){
							getline(file, line);
							}
                for (int j = 0; j < Y_SIZE; j++) {
                    getline(file, line);
                    stringstream ss(line);
                    for (int k = 0; k < X_SIZE; k++) {
                        int value;
                        ss >> value;
												if ( (value != 0 && value != 1 )){
													return false;
												} 
                        //cout << "[" << k << "][" << j << "][" << i << "]=" << value << endl;
                      		maze[k][j][i] = value;
												}
                    }
                }
            }
						file.close();
					
				
				//Checks to see if we can start and end the maze
				if(maze[0][0][0] != 1 || maze[X_SIZE-1][Y_SIZE-1][Z_SIZE-1] != 1){
					return false;
				}
				
        return true;
}

vector<string> Pathfinder::solveMaze() {
	solution.clear();
        findPath(maze, 0,0,0);
        for(auto s:solution) {
            //cout << s <<endl;
        } 
	for(int i = 0; i < Z_SIZE; i++) {
   for(int j = 0; j < Y_SIZE; j++) {
      for(int k = 0; k < X_SIZE; k++) {
        if(maze[k][j][i] == 2 || maze[k][j][i] == 3){
					maze[k][j][i] = BACKGROUND;
				}
      }
   }
	}
        return solution;
}


bool Pathfinder::findPath(int maze[X_SIZE][Y_SIZE][Z_SIZE], int x, int y, int z) {
	if( x < 0 || y < 0 || z < 0 || x >= X_SIZE || y >= Y_SIZE || z >= Z_SIZE ) {
  	return false;
  } else if (maze[x][y][z] != BACKGROUND) {
    return false;
  } else if (x==X_SIZE-1 && y==Y_SIZE-1 && z==Z_SIZE-1) {
    	maze[x][y][z] = PATH;
      string tempString = ("("+ to_string(x) +", " + to_string(y) + ", " + to_string(z) + ")");
      solution.insert(solution.begin(), tempString);
      return true;
    } else {
            //Recursive Part
		maze[x][y][z] = PATH;
    if (findPath(maze,x - 1, y, z) || findPath(maze,x + 1, y, z) ||
      	findPath(maze,x, y - 1, z) || findPath(maze,x, y + 1, z) ||
        findPath(maze,x, y, z - 1) || findPath(maze,x, y, z + 1)) {

        string tempString = ("("+ to_string(x) +", " + to_string(y) + ", " + to_string(z) + ")");
      	solution.insert(solution.begin(), tempString);
        return true;

            } else {
                maze[x][y][z] = TEMPORARY;
                return false;
            }
        }
}

