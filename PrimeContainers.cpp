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

  bool isPrime(int n) {
    if (n < 2)
      return false;

    if (n != 2 && n % 2 == 0)
      return false;

    int s = (int)sqrt(n);

    for (int i=3; i<=s; i++)
      if (n % i == 0)
        return false;

    return true;
  }

class PrimeContainers {
public:
  int containerSize(int N) {
    int ret = 0;

    while (N > 0) {
      if (isPrime(N))
        ret++;
      N /= 2;
    }

    return ret;
  }
   

};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
