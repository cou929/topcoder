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

typedef struct path
{
  int step;
  string pos;
};

class CaptureThemAll {
public:
  bool inRange(string pos)
  {
    if ('a' <= pos[0] && pos[0] <= 'h' && '1' <= pos[1] && pos[1] <= '8')
      return true;
    return false;
  }

  int r(string start, string goal)
  {
    int ret = 0;
    int rdir[8] = {-2, -2, -1, 1, 2, 2, -1, 1};
    int cdir[8] = {-1, 1, 2, 2, -1, 1, -2, -2};
    queue <path> q;
    path s;

    s.step = 0;
    s.pos = start;
    q.push(s);

    while (!q.empty())
      {
	path current = q.front();
	q.pop();

	if (current.pos == goal)
	  {
	    ret = current.step;
	    break;
	  }

	for (int i=0; i<8; i++)
	  {
	    char r = current.pos[0] + rdir[i];
	    char c = current.pos[1] + cdir[i];
	    string s;
	    s = r;
	    s += c;
	    if (inRange(s))
	      {
		path tmp;
		tmp.step = current.step + 1;
		tmp.pos = s;
		q.push(tmp);
	      }
	  }
      }

    return ret;
  }

  int fastKnight(string knight, string rook, string queen)
  {
    int k2r = 0, k2q = 0, r2q = 0;
    k2r = r(knight, rook);
    k2q = r(knight, queen);
    r2q = r(rook, queen);

    return min(k2r + r2q, k2q + r2q);
  }
   

};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
