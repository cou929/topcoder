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
class StrangeComputer {
public:
  int setMemory(string mem)
  {
    int ret = 0;
    char c = '0';

    for (int i=0; i<mem.size(); i++)
      if (mem[i] != c)
	{
	  ret++;
	  c = mem[i];
	}

    return ret;
  }
   

};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
