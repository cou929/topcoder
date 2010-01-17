#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

class GrabbingTaxi {
   public:
   int minTime(vector <int> tXs, vector <int> tYs, int gX, int gY, int walkTime, int taxiTime)
  {
    int i;
    int ret = 0;
    int tmp = 0;

    ret = abs(gX)*walkTime + abs(gY)*walkTime;

    for (i=0; i<tXs.size(); i++)
      {
	tmp = (abs(tXs[i] - gX) + abs(tYs[i] - gY)) * taxiTime + (abs(tXs[i]) + abs(tYs[i]))*walkTime;
	if (tmp < ret)
	  ret = tmp;
      }
    return ret;
   }

   

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
