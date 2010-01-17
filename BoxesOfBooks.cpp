#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

class BoxesOfBooks {
  int boxes(vector <int> weights, int maxWeight)
  {
    int i = 0;
    int counter = 1;
    int n = maxWeight;

    if (weights.size() == 0)
      return 0;

    while (i<weights.size())
      {
	if (n >= weights[i])
	  {
	    n -= weights[i];
	    i++;
	  }
	else
	  {
	    counter++;
	    n = maxWeight;
	  }
      }

    return counter;
  }

   

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
