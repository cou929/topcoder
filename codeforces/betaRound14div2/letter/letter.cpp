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

vector <string>  solve(vector <string> grid) {
  vector <string> ret;
  int lefttopx = 1000, lefttopy = 1000, rightbottomx = 0, rightbottomy = 0;
  int i, j;

  for (i=0; i<grid.size(); i++)
    for (j=0; j<grid[0].size(); j++)
      if (grid[i][j] == '*') {
        lefttopx = min(lefttopx, i);
        lefttopy = min(lefttopy, j);
        rightbottomx = max(rightbottomx, i);
        rightbottomy = max(rightbottomy, j);
      }

  for (i=lefttopx; i<=rightbottomx; i++) {
    string tmp;
    for (j=lefttopy; j<=rightbottomy; j++)
      tmp.push_back(grid[i][j]);
    ret.push_back(tmp);
  }
  
  return ret;
}

int main(void) {
  int n, m, i, j;
  vector <string> grid;

  cin >> n >> m;
  cin.ignore();

  for (i=0; i<n; i++) {
    string tmp;
    getline(cin, tmp);
    grid.push_back(tmp);
  }

  vector <string> res = solve(grid);

  for (i=0; i<res.size(); i++) {
    for (j=0; j<res[0].size(); j++)
      cout << res[i][j];
    cout << endl;
  }

  return 0;
}
