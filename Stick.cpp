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
class Stick {
public:
  int pieces(int x)
  {
    int ret = 0;
    vector <int> nums;
    nums.push_back(64); nums.push_back(32); nums.push_back(16);
    nums.push_back(8); nums.push_back(4); nums.push_back(2); nums.push_back(1);

    for (int i=0; i<nums.size(); i++)
      {
	if (x >= nums[i])
	  {
	    x -= nums[i];
	    ret++;
	  }
	if (x == 0)
	  break;
      }

    return ret;
  }
   

};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
