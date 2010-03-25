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
int w, h;

bool isInRange(int x, int y) {
  if (0 <= x && x < h && 0 <= y && y < w)
    return true;
  return false;
}

string maxstring(string a, string b) {
  if (a.size() == b.size())
    return max(a, b);
  else if (a.size() > b.size())
    return a;
  else
    return b;
}

string run(const vector <string> &matrix) {
  string ret = "";
  int i, j;
  vector <vector <string> > dp(h, vector <string> (w, ""));

  for (i=0; i<h; i++)
    for (j=0; j<w; j++) {
      if ('0' <= matrix[i][j] && matrix[i][j] <= '9') {
        string a, b;
        if (isInRange(i-1, j))
          a = dp[i-1][j];
        if (isInRange(i, j-1))
          b = dp[i][j-1];
        if (a[0] == '0') a.erase(a.begin(), a.begin()+1);
        if (b[0] == '0') b.erase(b.begin(), b.begin()+1);
        dp[i][j] = maxstring(a, b) + matrix[i][j];
        ret = maxstring(ret, dp[i][j]);
      }
    }

  return ret;
}

int main(int argc, char ** argv) {
  string line;
  int i;

  while (1) {
    cin >> w >> h;
    cin.ignore();
    
    if (w == 0 && h == 0) break;

    vector <string> matrix;

    for (i=0; i<h; i++) {
      getline(cin, line);
      matrix.push_back(line);
    }

    string result = run(matrix);

    cout << result << endl;
  }

  return 0;
}
