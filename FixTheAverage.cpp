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

class FixTheAverage {
   public:
   double add(vector <double> list, double target)
  {
    int i;
    double sum=0;

    for (i=0; i<list.size(); i++)
      sum += list[i];

    return target*(list.size() + 1) - sum;
   }

   

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
