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

long long toInt(string s) {long long r = 0; istringstream ss(s); ss >> r; return r;}
string toStr(int n) {ostringstream ss; ss << n; return ss.str();}

vector <long long> split(const string _s, const string del) {
  vector <long long> ret;
  string s = _s;

  while (!s.empty())
    {
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

string solve(int N, int K, int B, int T, vector <long long> xs, vector <long long> vs) {
  string ret = "IMPOSSIBLE";
  int swapCount = 0;
  int i, j;
  int n = xs.size();
  vector <long long> goals;
  int c = 0;

  for (i=0; i<n; i++) {
    long long t = xs[i] + vs[i] * T;
    if (t < B)
      t = -1;
    goals.push_back(t);
  }

  if (n - count(goals.begin(), goals.end(), -1) < K)
    return ret;

  reverse(goals.begin(), goals.end());
  int done[n];
  for (i=0; i<n; i++)
    done[i] = -1;

  for (i=0; i<n; i++) {
    if (goals[i] == -1)
      continue;
    if (c >= K)
      break;
    
    int next = -1;
    for (j=0; j<=i; j++)
      if (done[j] != -1)
        next = j;

    int localcount = 0;
    if (next != -1)
      localcount = max(done[next], 0);

    for (j=next+1; j<i; j++)
      if (goals[j] == -1)
        localcount++;

    done[i] = localcount;
    swapCount += localcount;
    c++;
  }

  ret = toStr(swapCount);

  return ret;
}

int main(void) {
  int probNum, i;
  string line;

  cin >> probNum;

  for (i=0; i<probNum; i++) {
    int N, K, B, T;
    vector <long long> xs, vs;
    cin >> N >> K >> B >> T;
    cin.ignore();
    getline(cin, line);
    xs = split(line, " ");
    getline(cin, line);
    vs = split(line, " ");

    cout << "Case #" << i + 1 << ": " << solve(N, K, B, T, xs, vs) << endl;
  }

  return 0;
}
