#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

class SpiralRoute {
public:
  vector <int> thronePosition(int width, int length)
  {
    int i, j;
    bool past[5000][5000];
    int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int direction = 0;
    int x = 0, y = 0; 

    for (i=0; i<width; i++)
      for (j=0; j<length; j++)
	past[i][j] = true;

    past[x][y] = false;

    while (1)
      {
	bool found = false;
	for (i=0; i<4; i++)
	  {
	    int tx = x + dir[direction][0];
	    int ty = y + dir[direction][1];
	    if (tx >= 0 && ty >= 0 && tx < width && ty < length && past[tx][ty])
	      {
		x += dir[direction][0];
		y += dir[direction][1];
		past[x][y] = false;
		found = true;
		break;
	      }
	    else
	      {
		direction = (direction + 1) % 4;
	      }
	  }

	if (!found)
	  break;
      }

    vector <int> ret;
    ret.push_back(x);
    ret.push_back(y);

    return ret;
  }

   

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
