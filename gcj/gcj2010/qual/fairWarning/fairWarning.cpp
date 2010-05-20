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

int toLL(string s) {long long r = 0; istringstream ss(s); ss >> r; return r;}
string toStr(int n) {ostringstream ss; ss << n; return ss.str();}

vector <string> splits(const string _s, const string del) {
  vector <string> ret;
  string s = _s;

  while (!s.empty())
    {
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

long long gcd(const long long _a, const long long _b) {
  long long a = max(_a, _b);
  long long b = min(_a, _b);

  if (b == 0)
    return 0;

  while (b) {
    long long tmp = a % b;
    a = b;
    b = tmp;
  }

  return a;
}

string solve(long long N, vector <string> t) {
  string ret;
  int i, j;
  
  vector <long long> tt;
  vector <long long> diffs;

  for (i=0; i<N; i++)
    tt.push_back(toLL(t[i]));

  tt.erase(unique(tt.begin(), tt.end()), tt.end());

  for (i=0; i<tt.size()-1; i++)
    diffs.push_back(abs(tt[i] - tt[i+1]));

  long long T = 0;
  if (diffs.size() >= 2) {
    T = gcd(diffs[0], diffs[1]);
    for (i=3; i<diffs.size(); i++)
      T = gcd(diffs[i], T);
  } else {
    T = diffs[0];
  }

  if (diffs.size() > 1 && count(diffs.begin(), diffs.end(), diffs[0]) == diffs.size())
    return "0";

  if (T == 1 || T == 0)
    return "0";
  
  long long aaa = 1000000000000000000LL;

  for (i=0; i<N; i++)
    aaa = min(aaa, T - (tt[i] % T));

  if (T == 1 || T == 0)
    return "0";

  ret = toStr(T - (tt[0] % T));

  return ret;
}

int main(void) {
  int probNum, i;

  cin >> probNum;
  cin.ignore();

  for (i=0; i<probNum; i++) {
    long long n;
    vector <string> t;
    string line;
    getline(cin, line);

    t = splits(line, " ");
    n = toLL(t[0]);
    t.erase(t.begin(), t.begin() + 1);
    //    cout << line << endl;
    cout << "Case #" << i + 1 << ": " << solve(n, t) << endl;
  }

  return 0;
}
