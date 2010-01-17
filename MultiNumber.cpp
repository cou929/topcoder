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
class MultiNumber {
public:
  int toInt(string s) {int r = 0; istringstream ss(s); ss >> r; return r;}
  string toStr(int n) {ostringstream ss; ss << n; return ss.str();}
  string check(int number)
  {
    string ret = "NO";
    string n = toStr(number);

    for (int i=1; i<n.size(); i++)
      {
	string left = n.substr(0, i);
	string right = n.substr(i);

	int productL = 1, productR = 1;

	for (int j=0; j<left.size(); j++)
	  productL *= left[j] - '0';

	for (int j=0; j<right.size(); j++)
	  productR *= right[j] - '0';

	if (productL == productR)
	  {
	    ret = "YES";
	    break;
	  }
      }

    return ret;
  }
   

};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
