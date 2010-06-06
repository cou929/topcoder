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

map <char, string> pattern;

bool check(int x, int y, int n, vector <string> &board) {
  int i, j;
  for (i=0; i<n; i++) {
    char cur = board[x+i][y];
    if (i > 0)
      if (cur == board[x+i-1][y])
        return false;
    for (j=0; j<n; j++) {
      if (board[x+i][y+j] == '.')
        return false;
      if (board[x+i][y+j] != cur)
        return false;
      cur = ((cur - '0') + 1) % 2 + '0';
    }
  }

  return true;
}

void cut(int x, int y, int n, vector <string> &board) {
  int i, j;
  for (i=0; i<n; i++)
    for (j=0; j<n; j++)
      board[x+i][y+j] = '.';
  return;
}

vector <pair <int, int> >  solve(vector <string> board) {
  vector <pair <int, int> > ret;
  int most = min(board.size(), board[0].size());
  int i, j, k;

  for (i=most; i>=1; i--) {
    int num = 0;
    for (j=0; j<=board.size()-i; j++) {
      for (k=0; k<=board[0].size()-i; k++) {
        if (check(j, k, i, board)) {
          cut(j, k, i, board);
          num++;
        }
      }
    }

    if (num > 0)
      ret.push_back(make_pair(i, num));
  }

  return ret;
}

bool inRange(int x, int y, int n, int m) {
  if (0 <= x && x < n && 0 <= y && y < m)
    return true;
  return false;
}

vector <vector <int> > search(vector <string> &board, vector <vector <int> > dp, int x, int y, int n, int m) {
  vector <vector <int> > ret = dp;
  int i, j;

  for (i=0; i<n; i++)
    for (j=0; j<m; j++) 
      if (inRange(x + i, y + j, board.size(), board[0].size())) {
        if (ret[x + i][y + j] == 0)
          continue;
        if (x + i == 0 || y + j == 0) {
          if (ret[x + i][y + j] != 0)
            ret[x + i][y + j] = 1;
        } else {
          if (board[x + i][y + j] == board[x + i - 1][y + j - 1] &&
              board[x + i][y + j] != board[x + i - 1][y + j] &&
              board[x + i][y + j] != board[x + i][y + j - 1] &&
              board[x + i][y + j] > 0 && board[x + i - 1][y + j - 1] > 0 && board[x + i - 1][y + j] > 0 && board[x + i][y + j - 1] > 0)
            ret[x + i][y + j] = min(ret[x + i - 1][y + j - 1], min(ret[x + i - 1][y + j], ret[x + i][y + j - 1])) + 1;
          else
            ret[x + i][y + j] = 1;
        }
      }

  return ret;
}

vector <pair <int, int> >  solve2(vector <string> board) {
  vector <pair <int, int> > ret;
  map <int, int> memo;
  int n = board.size(), m = board[0].size();
  vector <vector <int> > dp(n, vector <int> (m, 1));
  set <vector <int> > pos;
  int i, j, k;

  dp = search(board, dp, 0, 0, n, m);

  for (i=0; i<n; i++)
    for (j=0; j<m; j++) {
      vector <int> tmp;
      tmp.push_back(-dp[i][j]);
      tmp.push_back(i);
      tmp.push_back(j);
      pos.insert(tmp);
    }
      
  while (!pos.empty()) {
    set <vector <int> >::iterator i = pos.begin();
    int len = -(*i)[0];
    int x = (*i)[1] - len + 1, y = (*i)[2] - len + 1;

    memo[(*i)[0]]++;

    pos.erase(pos.begin());

    vector <vector <int> > original = dp;

    for (j=0; j<len; j++)
      for (k=0; k<len; k++)
        if (x + j < n && y + k < m)
          dp[x + j][y + k] = 0;

    dp = search(board, dp, x, y, len*2, len*2);

//     for (int ll=0; ll<dp.size(); ll++) {
//       for (int lll=0; lll<dp[0].size(); lll++)
//         cout << dp[ll][lll];
//       cout << endl;
//     }
//     cout << endl;

    for (j=0; j<len*2; j++)
      for (k=0; k<len*2; k++) 
        if (inRange(x + j, y + k, n, m))
          if (dp[x + j][y + k] != original[x + j][y + k]) {
            vector <int> tmp;
            tmp.push_back(-original[x + j][y + k]);
            tmp.push_back(x + j);
            tmp.push_back(y + k);
            set <vector <int> >::iterator ti = pos.find(tmp);
            if (ti != pos.end()) {
              pos.erase(ti);
              if (dp[x + j][y + k] != 0) {
                tmp[0] = -dp[x + j][y + k];
                pos.insert(tmp);
              }
            }
          }
  }

  for (map <int, int>::iterator i=memo.begin(); i!=memo.end(); i++)
    ret.push_back(make_pair(-i->first, i->second));

  return ret;
}

int main(void) {
  int probNum, i, j, k;
  string line;

  pattern['0'] = "0000";
  pattern['1'] = "0001";
  pattern['2'] = "0010";
  pattern['3'] = "0011";
  pattern['4'] = "0100";
  pattern['5'] = "0101";
  pattern['6'] = "0110";
  pattern['7'] = "0111";
  pattern['8'] = "1000";
  pattern['9'] = "1001";
  pattern['A'] = "1010";
  pattern['B'] = "1011";
  pattern['C'] = "1100";
  pattern['D'] = "1101";
  pattern['E'] = "1110";
  pattern['F'] = "1111";

  cin >> probNum;

  for (i=0; i<probNum; i++) {
    int N, M;
    vector <string> board;
    cin >> N >> M;
    cin.ignore();

    for (j=0; j<N; j++) {
      string tmp;
      getline(cin, line);
      for (k=0; k<M/4; k++)
        tmp += pattern[line[k]];
      board.push_back(tmp);
    }

    vector <pair <int, int> > res = solve2(board);
    cout << "Case #" << i + 1 << ": " << res.size() << endl;
    for (j=0; j<res.size(); j++)
      cout << res[j].first << " " << res[j].second << endl;
  }

  return 0;
}
