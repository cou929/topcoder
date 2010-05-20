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

string solve(vector <string> board) {
  int i, j, n = board.size();

  for (i=0; i<n; i++)
    for (j=0; j<n; j++)
      if (board[i][j] != board[n-1-i][n-1-j])
        return "NO";

  return "YES";
}

int main(void) {
  int i, n = 3;
  string line;
  vector <string> board;

  for (i=0; i<n; i++) {
    cin >> line;
    board.push_back(line);
  }

  cout << solve(board) << endl;

  return 0;
}
