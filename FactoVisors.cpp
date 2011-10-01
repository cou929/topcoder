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

class FactoVisors {
   public:

  int gcd(int _a, int _b)
  {
    int a = _a;
    int b = _b;

    while (b)
      {
	int tmp = b;
	b = a % b;
	a = tmp;
      }

    return a;
  }

  int lcm(int a, int b)
  {
    return a*b / gcd(a, b);
  }

  int getNum(vector <int> divisors, vector <int> multiples)
  {
    int i;
    int div = 0;
    int mul = 0;
    int counter = 0;

    if (divisors.size() > 1)
      {
	div = lcm(max(divisors[0], divisors[1]), min(divisors[0], divisors[1]));
	for (i=2; i<divisors.size(); i++)
	  div = lcm(max(divisors[i], div), min(divisors[i], div));
      }
    else
      div = divisors[0];

    if (multiples.size() > 1)
      {
	mul = gcd(max(multiples[0], multiples[1]), min(multiples[0], multiples[1]));
	for (i=2; i<multiples.size(); i++)
	  mul = gcd(max(multiples[i], mul), min(multiples[i], mul));
      }
    else
      mul = multiples[0];

    //    cout << div << " " << mul << " " << gcd(9, 6) << endl;

    for (i=div; i<=mul; i+=div)
      if (mul % i == 0)
	counter++;

    return counter;
  }  

   

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
