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
class HexagonalBattlefieldEasy {
public:
  vector <string> splits(const string _s, const string del) {
    vector <string> ret;
    string s = _s;

    while (!s.empty()) {
      size_t pos = s.find(del);
      string sub = "";
      sub = s.substr(0, pos);
      ret.push_back(sub);
      if (pos != string::npos)
        pos += del.size();
      s.erase(0, pos);
    }

    return ret;
  }

  int table[7][7];
  int N;
  int ret;

  pair <int, int> searchStart() {
    int len = N*2-1;
    for (int i=0; i<len; i++)
      for (int j=0; j<len; j++)
        if (table[i][j] == 0)
          return make_pair(i, j);
    return make_pair(-1, -1);
  }

  bool isInRange(int x, int y) {
    if (0 <= x && x < N*2-1 && 0 <= y && y < N*2-1)
      return true;
    return false;
  }

  int r(pair <int, int> pos) {
    int curx = pos.first, cury = pos.second;
    int dirx[6] = {1, 0, -1, -1, 0, 1};
    int diry[6] = {0, -1, -1, 0, 1, 1};

    for (int i=0; i<6; i++) {
      int nextx = curx + dirx[i], nexty = cury + diry[i];
      if (isInRange(nextx, nexty) && table[nextx][nexty] == 0) {
        table[curx][cury] = table[nextx][nexty] = 1;

        pair <int, int> tmp = searchStart();
        if (tmp.first != -1)
          r(tmp);
        else
          ret++;

        table[curx][cury] = table[nextx][nexty] = 0;
      }
    }

    return 0;
  }

  int countArrangements(vector <int> X, vector <int> Y, int _N) {
    ret = 0;
    N = _N;
    memset(table, 0, sizeof(table));
    vector <string> black_list;
    black_list.push_back("");
    black_list.push_back("20");
    black_list.push_back("30 40 41");
    black_list.push_back("40 50 60 51 61 62");

    vector <string> tmp = splits(black_list[N-1], " ");
    for (int i=0; i<tmp.size(); i++) {
      int a = tmp[i][0] - '0', b = tmp[i][1] - '0';
      table[a][b] = 1, table[b][a] = 1;
    }

    for (int i=0; i<X.size(); i++)
      table[X[i] + N-1][Y[i] + N-1] = 1;

    pair <int, int> t = searchStart();
    if (t.first != -1)
      r(t);
    else
      ret++;

    return ret;
  }
   

};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
