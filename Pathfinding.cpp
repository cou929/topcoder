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

using namespace std;

class Pathfinding {
public:
  set <pair<int, int> > visited;
  queue <pair <pair<int, int>, int> > q;
  int lx, ux, ly, uy;
  pair <int, int> goal;

  int bfs(int a, int b)
  {
    pair <pair <int, int>, int> cur;
    pair <int, int> t(a, b);
    pair <pair <int, int>, int> s(t, 0);
    q.push(s);
    visited.insert(t);

    while (!q.empty()) 
      {
	cur = q.front();
	q.pop();

	if (cur.first == goal)
	  break;
	
	pair <int, int> tmp;
	if (cur.first.second % 2 == 0)
	  {
	    tmp.first = cur.first.first+1;
	    tmp.second = cur.first.second;
	  }
	else
	  {
	    tmp.first = cur.first.first-1;
	    tmp.second = cur.first.second;
	  }

	if (lx <= tmp.first && tmp.first <= ux && ly <= tmp.second && tmp.second <= uy && visited.find(tmp) == visited.end())
	  {
	    visited.insert(tmp);
	    pair<pair<int, int>, int> t(tmp, cur.second+1);
	    q.push(t);
	  }

	if (cur.first.first % 2 == 0)
	  {
	    tmp.first = cur.first.first;
	    tmp.second = cur.first.second+1;
	  }
	else
	  {
	    tmp.first = cur.first.first;
	    tmp.second = cur.first.second-1;
	  }

	if (lx <= tmp.first && tmp.first <= ux && ly <= tmp.second && tmp.second <= uy && visited.find(tmp) == visited.end())
	  {
	    visited.insert(tmp);
	    pair<pair<int, int>, int> t(tmp, cur.second+1);
	    q.push(t);
	  }
      }

    return cur.second;
  }

  int getDirections(int x, int y)
  {
    goal.first = x;
    goal.second = y;

    if (x > 0)
      {
	ux = x + 2;
	lx = -2;
      }
    else if (x < 0)
      {
	ux = 2;
	lx = x - 2;
      }
    else
      {
	ux = x + 2;
	lx = x - 2;
      }

    if (y > 0)
      {
	uy = y + 2;
	ly = -2;
      }
    else if (y < 0)
      {
	uy = 2;
	ly = y - 2;
      }
    else
      {
	uy = y + 2;
	ly = y - 2;
      }

    return bfs(0, 0);
  }

   

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
