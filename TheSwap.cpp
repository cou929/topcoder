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

class TheSwap {
public:
  int findMax(int n, int k)
  {
    int i, j;
    int counter = 0;
    vector <int> num;
    int maxi=0, index=0;
    int ret = 0;

    while (n > 0)
      {
	int tmp = n%10;
	num.insert(num.begin(), tmp);
	n = n/10;
      }

    if (num.size() == 1)
      return -1;

    for (i=0; i<num.size()-1; i++)
      {
	if (counter >= k)
	  break;

	maxi = num[i];
	index = i;
	for (j=i; j<num.size(); j++)
	  {
	    if (maxi < num[j] || (index != i && maxi <= num[j]))
	      {
		maxi = num[j];
		index = j;
	      }
	  }

	if (index != i && (i != 0 || num[index] != 0))
	  {
	    int tmp = num[i];
	    num[i] = num[index];
	    num[index] = tmp;
	    counter++;
	  }
      }

    map <int, int> m;
    map <int, int>::iterator it;
    int flg = 0;
    for (i=0; i<num.size(); i++)
      m[num[i]]++;
    for (it=m.begin(); it!=m.end(); it++)
      if (it->second >= 2)
	{
	  flg = 1;
	  break;
	}

    if (counter < k && 	flg == 1)
      counter = k;

    if (counter < k)
      {
	if (num[num.size()-1] != 0 || num.size() != 2)
	  {
	    int tmp = k - counter;
	    counter = k;
	    if (tmp % 2 == 1)
	      {
		int tmp2 = num[num.size()-1];
		num[num.size()-1] = num[num.size()-2];
		num[num.size()-2] = tmp2;
	      }
	  }
      }

    if (counter < k)
      return -1;


    for (i=0; i<num.size(); i++)
      {
	ret *= 10;
	ret += num[i];
      }

    return ret;
  }

   

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
