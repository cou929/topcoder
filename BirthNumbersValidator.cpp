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
class BirthNumbersValidator {
public:
  int toInt(string s) {int r = 0; istringstream ss(s); ss >> r; return r;}
  long long toLong(string s) {long long r = 0; istringstream ss(s); ss >> r; return r;}

  vector <string> validate(vector <string> test)
  {
    vector <string> ret;

    int d[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector <int> days(d, d+12);

    for (int i=0; i<test.size(); i++)
      {
	long long all = toLong(test[i]);
	int year = toInt(test[i].substr(0, 2));
	int month = toInt(test[i].substr(2, 2));
	int day = toInt(test[i].substr(4, 2));

	if (year >= 7)
	  year += 1900;
	else
	  year += 2000;

	if (!((0 < month && month < 13) || (50 < month && month < 63)))
	  {
	    ret.push_back("NO");
	    continue;
	  }

	if (month > 50)
	  month -= 50;

	int limit = days[month-1];
	if (month == 2 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))
	  limit++;

	if (!(0 < day && day <= limit))
	  {
	    ret.push_back("NO");
	    continue;
	  }

	if (all % 11 != 0)
	  {
	    ret.push_back("NO");
	    continue;
	  }

	ret.push_back("YES");
      }

    return ret;
  }
   

};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
