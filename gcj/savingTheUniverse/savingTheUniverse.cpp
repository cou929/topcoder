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

vector <string> engine;
vector <string> query;

int search(vector <vector <int> > &length, int pos) {
  int ret = 1001;
  int maxi = *max_element(length[pos].begin(), length[pos].end());
  int i, j;

  for (i=0; i<engine.size(); i++)
    if (length[pos][i] == maxi) {
      int tmp = 0;
      for (j=pos; j<query.size(); j++)
        if (query[j] == engine[i]) {
          tmp = 1 + search(length, j);
          break;
        }
      ret = min(ret, tmp);
    }

  return ret;
}

int run() {
  int ret;
  int i, j;
  int n = engine.size(), m = query.size();
  vector <vector <int> > length(m, vector <int> (n, 0));

  if (m == 0) return 0;

  for (i=0; i<n; i++)
    if (query[m-1] != engine[i])
      length[m-1][i] = 1;

  for (i=m-2; i>=0; i--)
    for (j=0; j<n; j++)
      if (query[i] == engine[j])
        length[i][j] = 0;
      else
        length[i][j] = length[i+1][j] + 1;

  ret = search(length, 0);

  return ret;
}

int main(void) {
  string line;
  int i, j, probNum, n;

  cin >> probNum;

  for (i=0; i<probNum; i++) {
    engine.clear(), query.clear();
    cin >> n; cin.ignore();
    for (j=0; j<n; j++) {
      getline(cin, line);
      engine.push_back(line);
    }
    cin >> n; cin.ignore();
    for (j=0; j<n; j++) {
      getline(cin, line);
      query.push_back(line);
    }
    cout << "Case #" << i+1 << ": " << run() << endl;
  }

  return 0;
}
