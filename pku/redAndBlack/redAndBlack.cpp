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

using namespace std;

int run(int w, int h, vector <string> map) {
  int ret = 0;
  int i, j;
  queue <pair <int, int> > q;
  int visited[50][50];
  memset(visited, 0, sizeof(visited));
  int dirx[4] = {1, 0, -1, 0};
  int diry[4] = {0, 1, 0, -1};
  
  for (i=0; i<h; i++)
    for (j=0; j<w; j++)
      if (map[i][j] == '@') {
        q.push(make_pair(i, j));
        visited[i][j] = 1;
        break;
      }

  while (!q.empty()) {
    int curx = q.front().first;
    int cury = q.front().second;
    q.pop();

    visited[curx][cury] = 1;

    for (i=0; i<4; i++) {
      int nextx = curx + dirx[i];
      int nexty = cury + diry[i];
      if (0 <= nextx && nextx < h && 0 <= nexty && nexty < w &&
          map[nextx][nexty] == '.' && visited[nextx][nexty] == 0) {
        visited[nextx][nexty] = 1;
        q.push(make_pair(nextx, nexty));
      }
    }
  }

  for (i=0; i<h; i++)
    for (j=0; j<w; j++)
      if (visited[i][j] == 1)
        ret++;

  return ret;
}

int main(int argc, char ** argv) {
  int width, height;
  int i;
  string line;

  while (1)
    {
      vector <string> map;

      cin >> width >> height;
      cin.ignore();

      if (width == 0 && height == 0) break;

      for (i=0; i<height; i++) {
        getline(cin, line);
        map.push_back(line);
      }

      int result = run(width, height, map);
      cout << result << endl;
    }

  return 0;
}
