#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <utility>
#include <set>
#include <cctype>
#include <queue>
#include <stack>
using namespace std;
class FourBlocksEasy {
public:
  int maxScore(vector <string> grid)
  {
    int ret = 0;

    for (int i=0; i<grid[0].size(); i++)
      {
	if (grid[0][i] == '.')
	  {
	    if (grid[1][i] == '.' && (i+1 < grid[0].size() && grid[0][i+1] == '.' && grid[1][i+1] == '.'))
	      {
		grid[0][i] = '4';
		grid[1][i] = '4';
		grid[0][i+1] = '4';
		grid[1][i+1] = '4';
	      }
	    else
	      {
		grid[0][i] = '1';
		if (grid[1][i] == '.')
		  grid[1][i] = '1';
	      }
	  }
	else
	  {
	    if (grid[1][i] == '.')
	      grid[1][i] = '1';
	  }
      }

    for (int i=0; i<grid[0].size(); i++)
      ret += (grid[0][i] - '0') + (grid[1][i] - '0');

    return ret;
  }
   

};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
