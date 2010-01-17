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
class KnightsTour {
public:
  bool inRange(int x, int y)
  {
    bool ret = false;
    if (0<=x && x<8 && 0<=y && y<8)
      ret = true;
    return ret;
  }

  int visitedPositions(vector <string> board)
  {
    int ret = 1;
    vector <string> inaccess = board;
    int x, y;
    int dirs[8][2] = {{-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}};

    for (int i=0; i<board.size(); i++)
      for (int j=0; j<board[i].size(); j++)
	if (board[i][j] == 'K')
	  {
	    x = i;
	    y = j;
	  }

    while (1)
      {
	vector <pair <int, int> > candidates;
	vector <pair <int, pair <int, int> > > c;

	inaccess[x][y] = '*';

	for (int i=0; i<8; i++)
	  if (inRange(x+dirs[i][0], y+dirs[i][1]) && inaccess[x+dirs[i][0]][y+dirs[i][1]] != '*')
	    candidates.push_back(make_pair(x+dirs[i][0], y+dirs[i][1]));

	for (int i=0; i<candidates.size(); i++)
	  {
	    int cx = candidates[i].first;
	    int cy = candidates[i].second;
	    int accNum = 0;
	    for (int j=0; j<8; j++)
	      if (inRange(cx+dirs[j][0], cy+dirs[j][1]) && inaccess[cx+dirs[j][0]][cy+dirs[j][1]] != '*')
		accNum++;

	    c.push_back(make_pair(accNum, candidates[i]));
	  }

	sort(c.begin(), c.end());

	if (c.empty())
	  break;
	else
	  {
	    x = c[0].second.first;
	    y = c[0].second.second;
	    ret++;
	  }
      }

    return ret;
  }
   

};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
