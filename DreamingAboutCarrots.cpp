#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

class DreamingAboutCarrots {
public:
  int gcd(int a, int b)
  {
    if (a % b == 0)
      return b;
    else
      return gcd(b, a%b);
  }

  int carrotsBetweenCarrots(int x1, int y1, int x2, int y2)
  {
    int num = gcd(max(abs(x2-x1), abs(y2-y1)), min(abs(x2-x1), abs(y2-y1)));
    num = (num) ? num : 1;
    int incx = abs(x2-x1) / num;
    int length = abs(x2 - x1) -1;
    return length / incx;
  }

   

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
