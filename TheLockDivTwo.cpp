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
using namespace std;
class TheLockDivTwo {
public:
  int N;

  string toStr(int n) {
    string ret;
    for (int i=0; i<N; i++)
      if (n & (1 << i))
        ret += '1';
      else
        ret += '0';
    reverse(ret.begin(), ret.end());
    return ret;
  }

  bool ok(int a, int b) {
    //if (__builtin_popcount(a ^ b) == 1) 
    if ((a & b) == a || (a & b) == b)
      return true;
    return false;
  }

  string password(int n, int k) {
    bool used[(1 << n)];
    int pre = 0;
    N = n;
    memset(used, false, sizeof(used));
    used[0] = true;

    for (int i=1; i<k; i++)
      for (int j=0; j<(1 << n); j++)
        if (!used[j] && ok(pre, j)) {
          pre = j;
          used[j] = true;
          break;
        }

    return toStr(pre);
  }
   

};



/*
  bool ok(int a, int b) {
    if (__builtin_popcount(a ^ b) == 1) 
      return true;
    return false;
  }

  string password(int n, int k) {
    bool used[(1 << n)];
    int pre = 0;
    string ret;
    memset(used, false, sizeof(used));
    used[0] = true;

    for (int i=1; i<k; i++)
      for (int j=0; j<k; j++) {
        if (!used[j] && ok(pre, j)) {
          pre = j;
          used[j] = true;

//           string s;
//           for (int k=0; k<n; k++)
//             if (pre & (1 << k))
//               s += '1';
//             else
//               s += '0';
//           reverse(s.begin(), s.end());
//           cout << s << endl;

          break;
        }
      }

    for (int i=0; i<n; i++)
      if (pre & (1 << i))
        ret += '1';
      else
        ret += '0';

    reverse(ret.begin(), ret.end());

    return ret;
  }



  int toInt(string s) {
    int ret = 0;
    for (int i=0; i<s.size(); i++) {
      if (s[s.size() - i - 1] == '1')
        ret += (int)pow((double)2, (double)i);
    }
    return ret;
  }
 */


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
