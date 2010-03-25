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
class AgeEncoding {
public:
  double getRadix(int age, string candlesLine) {
    double ret = 0;
    int i, j;
    int n = candlesLine.size();
    int one_num = count(candlesLine.begin(), candlesLine.end(), '1');

    if (one_num == 0) return -1;
    if (candlesLine[n-1] == '1')
      if (age == 1)
        if (one_num == 1) return -2;
        else return -1;
      else
        if (one_num == 1) return -1;
    
    double left = 0, right = 100;
    for (i=0; i<1000; i++) {
      ret = (left + right) * 0.5;
      double ans = 0;
      double B = 1;

      for (j=n-1; j>=0; j--) {
        ans += (candlesLine[j] - '0') * B;
        B *= ret;
      }

      if (ans > age)
        right = ret;
      else
        left = ret;
    }

    return ret;
  }
   

};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
