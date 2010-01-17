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
class Underprimes {
public:
  bool isPrime(int n)
  {
    if (n < 2)
      return false;

    if (n != 2 && n % 2 == 0)
      return false;

    int s = sqrt(n);

    for (int i=3; i<=s; i++)
      if (n % i == 0)
	return false;

    return true;
  }

  int howMany(int A, int B)
  {
    vector <int> primes;
    int ret = 0;

    for (int i=2; i<=50000; i++)
      if (isPrime(i))
	primes.push_back(i);

    for (int i=A; i<=B; i++)
      {
	int count = 0;
	int t = i;
	while (t != 1)
	  {
	    bool flg = false;
	    for (int j=0; j<primes.size(); j++)
	      if (t % primes[j] == 0)
		{
		  t /= primes[j];
		  count++;
		  flg = true;
		  break;
		}

	    if (!flg)
	      {
		count = 0;
		break;
	      }
	  }

	if (isPrime(count))
	  ret++;
      }

    return ret;
  }
   

};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
