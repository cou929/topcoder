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

vector <int> split(const string _s, const string del = " ");
int toInt(string s) {int r = 0; istringstream ss(s); ss >> r; return r;}

const int INF = 1000;

int run(vector <vector <int> > schedules) {
  int ret = INF;
  int n = schedules.size();
  vector <set <int> > dp(n, set <int>());
  int i, j;

  for (i=0; i<n; i++)
    dp[i].insert(i);

  for (i=1; i<=30; i++) {
    set <int> this_day;
    vector <int> index;
    for (j=0; j<n; j++)
      if (find(schedules[j].begin(), schedules[j].end(), i) != schedules[j].end()) {
        this_day.insert(dp[j].begin(), dp[j].end());
        index.push_back(j);
      }
    for (j=0; j<index.size(); j++)
      dp[index[j]] = this_day;

    if (this_day.size() == n) {
      ret = i;
      break;
    }
  }

  if (ret == INF) ret = -1;

  return ret;
}

int main(int argc, char ** argv) {
  string line;
  int n;
  int i;

  while (1) {
    cin >> n;
    cin.ignore();

    if (n == 0) break;

    vector <vector <int> > schedules;

    for (i=0; i<n; i++) {
      getline(cin, line);
      vector <int> tmp = split(line, " ");
      tmp.erase(tmp.begin(), tmp.begin() + 1);
      sort(tmp.begin(), tmp.end());
      schedules.push_back(tmp);
    }

    int result = run(schedules);

    cout << result << endl;
  }

  return 0;
}

vector <int> split(const string _s, const string del) {
  vector <int> ret;
  string s = _s;

  while (!s.empty()) {
      size_t pos = s.find(del);
      string sub = "";
      sub = s.substr(0, pos);
      ret.push_back(toInt(sub));
      if (pos != string::npos)
      	pos += del.size();
      s.erase(0, pos);
    }

  return ret;
}
