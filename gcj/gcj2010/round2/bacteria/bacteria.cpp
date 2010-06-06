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
#include <fstream>
#include <cstring>
#include <numeric>

using namespace std;

bool dead(vector <vector <int> > &grid) {
  for (int i=0; i<grid.size(); i++)
    for (int j=0; j<grid[0].size(); j++)
      if (grid[i][j] == 1)
        return false;
  return true;
}

bool inRange(int x, int y, int n, int m) {
  if (0 <= x && x < n && 0 <= y && y < m)
    return true;
  return false;
}

int solve(vector <vector <int> > arg) {
  int ret = 0;
  int i, j, k;
  int xmax = 0, ymax = 0;

  for (i=0; i<arg.size(); i++) {
    xmax = max(xmax, max(arg[i][0], arg[i][2]));
    ymax = max(ymax, max(arg[i][1], arg[i][3]));
  }
  xmax++, ymax++;

  vector <vector <int> > grid(ymax, vector <int> (xmax, 0));

  for (i=0; i<arg.size(); i++) {
    int left = min(arg[i][0], arg[i][2]), top =min(arg[i][1], arg[i][3]), right = max(arg[i][0], arg[i][2]), bottom = max(arg[i][1], arg[i][3]);
    for (j=left; j<=right; j++)
      for (k=top; k<=bottom; k++)
        grid[k][j] = 1;
  }

  vector <vector <int> > tmp = grid;

  while (!dead(grid)) {
    ret++;
    for (i=0; i<grid.size(); i++)
      for (j=0; j<grid[0].size(); j++) {
        int left = (!inRange(i-1, j, grid.size(), grid[0].size()) || grid[i-1][j] == 0) ? 0 : 1;
        int top = (!inRange(i, j-1, grid.size(), grid[0].size()) || grid[i][j-1] == 0) ? 0 : 1;
        if (grid[i][j] == 0 && left == 1 && top == 1)
          tmp[i][j] = 1;
        else if (grid[i][j] == 1 && left == 0 && top == 0)
          tmp[i][j] = 0;
        else
          tmp[i][j] = grid[i][j];
      }
    grid = tmp;
  }

  return ret;
}

int main(void) {
  int probNum, i, j, lineNum, x1, y1, x2, y2;

  cin >> probNum;

  for (i=0; i<probNum; i++) {
    vector <vector <int> > arg;
    cin >> lineNum;
    for (j=0; j<lineNum; j++) {
      cin >> x1 >> y1 >> x2 >> y2;
      vector <int> tmp;
      tmp.push_back(x1-1);
      tmp.push_back(y1-1);
      tmp.push_back(x2-1);
      tmp.push_back(y2-1);
      arg.push_back(tmp);
    }

    cout << "Case #" << i + 1 << ": " << solve(arg) << endl;
  }

  return 0;
}
