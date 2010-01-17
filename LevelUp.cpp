#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
using namespace std;

class LevelUp {
public:
  int toNextLevel(vector <int> expNeeded, int received) {
    int i;

    for(i=0; i<expNeeded.size(); i++)
      if(received <= expNeeded[i])
	break;

    if(received == expNeeded[i])
      return expNeeded[i+1] - expNeeded[i];
    else
      return expNeeded[i] - received;
  }

	


};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
