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

class ExtendedHappyNumbers {
public:
  int memo[4000000];

  long long pow(int a, int b)
  {
    long long ret = 1;
    for (int i=0; i<b; i++)
      ret *= a;

    return ret;
  }

  long long S(int n, int k)
  {
    long long ret = 0;

    while (n)
      {
	ret += pow(n % 10, k);
	n /= 10;
      }

    return ret;
  }

  long long getHappyNumber(int N, int K)
  {
    set <int> dupulicateChecker;

    dupulicateChecker.insert(N);

    while (1)
      {
	if (memo[N] != -1)
	  return memo[N];

	long long cur = S(N, K);
	if (dupulicateChecker.find(cur) != dupulicateChecker.end())
	  break;

	dupulicateChecker.insert(cur);
	N = cur;
      }

    for (set <int>::iterator it=dupulicateChecker.begin(); it!=dupulicateChecker.end(); it++)
      memo[*it] = *dupulicateChecker.begin();

    return *dupulicateChecker.begin();
  }

  long long calcTheSum(int A, int B, int K)
  {
    long long ret = 0;

    memset(memo, -1, sizeof(memo));

    for (int i=A; i<=B; i++) 
      ret += getHappyNumber(i, K);
   
    return ret;
  }

   

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
