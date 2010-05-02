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
#include <cout.hpp>

using namespace std;

int time2min(string time) {
  int h, m;
  sscanf(time.c_str(), "%02d:%02d", &h, &m);
  return h * 60 + m;
}

pair <int, int> makeTime(string line) {
  char from[10], to[10];
  sscanf(line.c_str(), "%s %s", from, to);
  return make_pair(time2min(string(from)), time2min(string(to)));
}

pair <int, int> run(vector <vector <pair <int, int> > > timetable, int turn) {
  pair <int, int> ret(make_pair(0, 0));
  int n = timetable[0].size(), m = timetable[1].size();
  int which = 0;
  int time = 0;
  int i;

  while (timetable[0].size() > 0 || timetable[1].size() > 0) {
    if (timetable[0].size() > 0 && (timetable[1].size() == 0 || (timetable[0][0].first <= timetable[1][0].first))) {
      ret.first++;
      which = 0;
      time = timetable[0][0].second;
      timetable[0].erase(timetable[0].begin());
    } else if (timetable[1].size() > 0 && (timetable[0].size() == 0 || (timetable[0][0].first > timetable[1][0].first))) {
      ret.second++;
      which = 1;
      time = timetable[1][0].second;
      timetable[1].erase(timetable[1].begin());
    }

    while (1) {
      bool flg = true;
      for (i=0; i<timetable[(which+1)%2].size(); i++)
        if (timetable[(which+1)%2][i].first >= time + turn) {
          flg = false;
          time = timetable[(which+1)%2][i].second;
          timetable[(which+1)%2].erase(timetable[(which+1)%2].begin() + i);
          which = (which+1) % 2;
          break;
        }
      if (flg) break;
    }
  }

  return ret;
}

int main(void) {
  string line, from, to;
  int i, j;
  int probNum, t, n, m;

  cin >> probNum;

  for (i=0; i<probNum; i++) {
    vector <vector <pair <int, int> > > timetable(2);

    cin >> t >> n >> m; cin.ignore();
    for (j=0; j<n; j++) {
      getline(cin, line);
      timetable[0].push_back(makeTime(line));
    }
    for (j=0; j<m; j++) {
      getline(cin, line);
      timetable[1].push_back(makeTime(line));
    }

    sort(timetable[0].begin(), timetable[0].end());
    sort(timetable[1].begin(), timetable[1].end());

    pair <int, int> res = run(timetable, t);
    cout << "Case #" << i+1 << ": " << res.first << " " << res.second << endl;
  }

  return 0;
}
