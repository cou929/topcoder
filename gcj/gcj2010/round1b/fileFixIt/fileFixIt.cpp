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

vector <string> split(const string _s, const string del) {
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

int solve(vector <string> src, vector <string> dst) {
  int ret = 0;
  set <string> created;
  int i, j, k;

  for (i=0; i<src.size(); i++) {
    vector <string> s = split(src[i], "/");
    for (j=1; j<s.size(); j++) {
      string path = "/";
      for (k=1; k<=j; k++)
        path += s[k] + '/';
      path.erase(path.end()-1);
      created.insert(path);
    }
  }

  for (i=0; i<dst.size(); i++) {
    vector <string> s = split(dst[i], "/");
    for (j=1; j<s.size(); j++) {
      string path = "/";
      for (k=1; k<=j; k++)
        path += s[k] + '/';
      path.erase(path.end()-1);

      if (created.find(path) == created.end()) {
        created.insert(path);
        ret++;
      }
    }
  }

  return ret;
}

int main(void) {
  int probNum, i, j;
  string line;

  cin >> probNum;

  for (i=0; i<probNum; i++) {
    int N, M;
    vector <string> src, dst;
    cin >> N >> M;
    cin.ignore();
    for (j=0; j<N; j++) {
      getline(cin, line);
      src.push_back(line);
    }
    for (j=0; j<M; j++) {
      getline(cin, line);
      dst.push_back(line);
    }
    cout << "Case #" << i + 1 << ": " << solve(src, dst) << endl;
  }

  return 0;
}
