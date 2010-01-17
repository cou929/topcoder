#include <string>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

class NumberGuesser {
public:
  int guess(string leftOver) {
    int i, j, k, n;
    int num;

    for(i=1; i<10; i++)
      {
	for(j=0; j<4; j++)
	  {

	    num = 0;
	    n = 0;
	    for(k=0; k<4; k++)
	      {
		num *= 10;
		if(k == j)
		  num += i;
		else
		  {
		    num += leftOver[n] - '0';
		    n++;
		  }
	      }

	    if(check(num))
	      return i;
	  }
      }

    return -1;
  }

  bool check(int src)
  {
    int i, j;
    int count;
    int lDigits[10], sDigits[10];
    int largeNum, smallNum;

    for(i=1; i<(9999 - src); i++)
      {
	for(j=0; j<10; j++)
	  {
	    lDigits[j] = 0;
	    sDigits[j] = 0;
	  }

	largeNum = i + src;
	smallNum = i;

	while(largeNum > 0)
	  {
	    lDigits[largeNum%10]++;
	    largeNum /= 10;
	  }

	while(smallNum > 0)
	  {
	    sDigits[smallNum%10]++;
	    smallNum /= 10;
	  }

	count = 0;
	for(j=0; j<10; j++)
	  if(lDigits[j] == sDigits[j])
	    count++;

	if(count == 10)
	  return true;
	    
      }
    return false;
  }

};
