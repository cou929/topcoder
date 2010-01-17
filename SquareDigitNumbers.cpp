#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

class SquareDigitNumbers {
   public:
   int getNumber(int n)
  {
    unsigned int i;
    int num = n+1;
    int place = 1;
    int digit = 0;
    int mod = 0;
    int ret = 0;

    while (1)
      {
	if (num <= 1)
	  break;

	mod = num % 4;
	if (mod == 0)
	  digit = 9;
	else if (mod == 1)
	  digit = 0;
	else if (mod == 2)
	  digit = 1;
	else if (mod == 3)
	  digit = 4;

	ret += digit * place;

	num = (int)((double)num / 4 + 0.9);
	place *= 10;
      }

    return ret;
   }

   

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
