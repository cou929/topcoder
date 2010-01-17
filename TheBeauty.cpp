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

class TheBeauty {
   public:
   int find(int n)
  {
    map <int, int> c;
    map <int, int>::iterator it;
    int counter = 0;

    while (n > 0)
      {
	int tmp = n%10;
	c[tmp]++;
	n = n/10;
      }

    for (it=c.begin(); it!=c.end(); it++)
      counter++;

    return counter;
   }

   

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
