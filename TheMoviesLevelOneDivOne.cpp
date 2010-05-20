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
#include <numeric>
using namespace std;
class TheMoviesLevelOneDivOne {
public:
  long long find(int n, int m, vector <int> row, vector <int> seat) {
    long long ret = 0;
    int i, j;
    set <long long> rows;

    for (i=0; i<row.size(); i++)
      rows.insert(row[i]);

    for (set <long long>::iterator i=rows.begin(); i!=rows.end(); i++) {
      vector <long long> s;
      s.push_back(0);
      s.push_back(m+1);
      for (j=0; j<row.size(); j++)
        if (row[j] == *i)
          s.push_back(seat[j]);
      sort(s.begin(), s.end());

      for (j=1; j<s.size(); j++)
        ret += max(0LL, s[j] - s[j-1] - 1 - 1);
    }

    ret += ((long long)n - rows.size()) * ((long long)m - 1LL);

    return ret;
  }
   

};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
