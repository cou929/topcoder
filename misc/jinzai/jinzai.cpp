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

double getrusageSec() {
  struct rusage t;
  struct timeval s;
  getrusage(RUSAGE_SELF, &t);
  s = t.ru_utime;
  return s.tv_sec + (double)s.tv_usec*1e-6;
}

vector <string> run(vector <string> input)
{
  vector <string> ret = input;
  queue <pair <int, int> > q;
  int come_from[input.size()][input[0].size()][2];
  int startx = 0, starty = 0, goalx = 0, goaly = 0;
  int dirx[4] = {1, 0, -1, 0};
  int diry[4] = {0, 1, 0, -1};

  memset(come_from, -1, sizeof(come_from));

  for (int i=0; i<input.size(); i++)
    for (int j=0; j<input[0].size(); j++)
      if (input[i][j] == 'S')
        startx = i, starty = j;
      else if (input[i][j] == 'G')
        goalx = i, goaly = j;

  q.push(make_pair(startx, starty));

  while (!q.empty()) {
    pair <int, int> cur = q.front();
    q.pop();
    int curx = cur.first, cury = cur.second;

    if (curx == goalx && cury == goaly)
      break;

    for (int i=0; i<4; i++) {
   int nextx = curx + dirx[i];
   int nexty = cury + diry[i];

      if (0 <= nextx && nextx < input.size() && 0 <= nexty && nexty < input[0].size() &&
          come_from[nextx][nexty][0] == -1 && (input[nextx][nexty] != '*' && input[nextx][nexty] != 'S')) {
        q.push(make_pair(nextx, nexty));
        come_from[nextx][nexty][0] = curx;
        come_from[nextx][nexty][1] = cury;
      }
    }
  }

  int x = goalx, y = goaly;
  while (1) {
    if (x == -1) break;
    if (ret[x][y] == ' ')
      ret[x][y] = '$';
    x = come_from[x][y][0];
    y = come_from[x][y][1];
  }

  return ret;
}

int main(int argc, char ** argv) {
  if (argc != 2) {
    cout << "Usage " << argv[0] << " <input file name>\n";
    return 0;
  }

  ifstream file (argv[1]);
  string line;
  vector <string> input;
  vector <string> result;

  while (!file.eof()) {
    getline(file, line);
    input.push_back(line);
  }

  double t1 = getrusageSec();
  result = run(input);
  double t2 = getrusageSec();

  for (int i=0; i<result.size(); i++) {
    for (int j=0; j<result[0].size(); j++)
      cout << result[i][j];
    cout << endl;
  }

  cout << t2 - t1 << " sec" << endl;

  return 0;
}
