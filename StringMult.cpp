#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

class StringMult {
   public:
   string times(string sFactor, int iFactor)
  {
    unsigned int i;
    string ret = "";

    if (iFactor == 0)
      return "";
    else if (iFactor < 0)
      {
	reverse(sFactor.begin(), sFactor.end());
	iFactor *= -1;
      }

    for (i=0; i<iFactor; i++)
      ret += sFactor;

    return ret;
   }

   

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
