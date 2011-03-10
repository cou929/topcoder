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

int dirx[] = {0, 1, 0, -1, 0};  // k, l, j, h, .
int diry[] = {1, 0, -1, 0, 0};
char label[] = {'k', 'l', 'j', 'h', '.'};

bool inRange(int x, int y, int h, int w) {
  return (0 <= x && x < h && 0 <= y && y < w) ? true : false;
}

int decideNextMove(int t, vector <string> field, vector <string> prev) {
  int ret = 0;
  return ret;
}

vector <string> getNextStep(vector <string> field, vector <string> prev, int next) {
  vector <string> ret = field;
  pair <int, int> player;
  vector <pair <int, int> > enemies;
  int i, j, h = field.size(), w = field[0].size();

  for (i=0; i<h; i++)
    for (j=0; j<w; j++)
      if (field[i][j] == '@')
        player = make_pair(i, j), ret[i][j] = ' ';
      else if (field[i][j] != '#' && field[i][j] != '.')
        enemies.push_back(make_pair(i, j)), ret[i][j] = ' ';

  ret[player.first + dirx[next]][player.second + diry[next]] = '@';

  int n = enemies.size();

  if (field[enemies[0].first][enemies[0].second] == prev[enemies[0].first][enemies[0].second]) { // initial step
    for (i=0; i<n; i++) {
      int x = enemies[i].first, y = enemies[i].second;
      for (j=0; j<4; j++)
        if (inRange(x + dirx[j], y + diry[j], h, w) && field[x + dirx[j]][y + diry[j]] != '#') {
          ret[x + dirx[j]][y + diry[j]] = field[x][y];
          break;
        }
    }
  } else {
    for (i=0; i<n; i++) {
      if (field[enemies[i].first][enemies[i].second] == 'V') {
        ;
      }
    }
  }

  return ret;
}

int checkPosition(vector <string> field, vector <string> prev) {
  int ret = 0;
  return ret;
}

pair <string, int> solve(int t, vector <string> field) {
  pair <string, int> ret = make_pair("", 0);
  vector <string> prev = field;

  while (t-- > 0) {
    int next = decideNextMove(t, field, prev);
    prev = field;
    field = getNextStep(field, prev, next);
    if (checkPosition(field, prev))
      ret.first += label[next], ret.second++;
  }

  return ret;
}

int main(void) {
  int t, w, h;
  vector <string> field;
  string s;

  cin >> t;
  cin >> w >> h;

  while (cin >> s)
    field.push_back(s);

  pair <string, int> ret = solve(t, field);
  cout << ret.first << " " << ret.second << endl;

  return 0;
}
