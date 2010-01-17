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
class GymTraining {
public:
  int trainingTime(int needToTrain, int minPulse, int maxPulse, int trainChange, int restChange)
  {
    int pulse = maxPulse - minPulse;
    int now = 0;
    int ret = 0;
    int trained = 0;

    if (pulse < trainChange)
      return -1;

    while (trained < needToTrain)
      {
	ret++;
	if (now + trainChange <= pulse)
	  {
	    now += trainChange;
	    trained++;
	  }
	else
	  {
	    now = min(now - restChange, 0);
	  }
      }
    return ret;
  }
};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
