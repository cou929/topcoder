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

class RoomNumber {
public:
  int numberOfSets(int roomNumber)
  {
    int i;
    map <int, int> c;
    map <int, int>::iterator it;
    int ret = 0;

    while (roomNumber)
      {
	int n;
	n = roomNumber % 10;
	roomNumber /= 10;

	c[n]++;
      }

    for (it=c.begin(); it!=c.end(); it++)
      {
	int n = 0;
	if (it->first == 6 || it->first == 9)
	  n = (c[6] + c[9]) / 2 + 0.9;
	else
	  n = it->second;
	if (ret < n)
	  ret = n;
      }

    return ret;
  }

   

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
