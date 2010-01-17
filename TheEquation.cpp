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

class TheEquation {
   public:
   int leastSum(int X, int Y, int P)
  {
    int i, j;

    for (i=2; i<=2*P; i++)
      {
	for (j=1; j<i; j++)
	  {
	    if ((X*j + Y*(i-j)) % P == 0)
	      return i;
	  }
      }
   }

   

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
