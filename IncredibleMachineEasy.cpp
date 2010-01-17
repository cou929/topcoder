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
using namespace std;
class IncredibleMachineEasy {
public:
  double gravitationalAcceleration(vector <int> height, int T)
  {
    double d = 0;
    for (int i=0; i<height.size(); i++)
      d += sqrt(height[i] * 2);

    return  d*d / (double)(T*T);
  }
   

};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
