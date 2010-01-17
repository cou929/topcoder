// BEGIN CUT HERE
// END CUT HERE
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
#include <cfloat>

using namespace std;

class CarBuyer {
public:
  double lowestCost(vector <string> cars, int fuelPrice, int annualDistance, int years)
  {
    double ret = DBL_MAX;

    for (int i=0; i<cars.size(); i++)
      {
	int purchase = 0;
	int tax = 0;
	int fuel = 0;
	sscanf(cars[i].c_str(), "%d %d %d", &purchase, &tax, &fuel);

	double t = (double)purchase + (double)tax * years + (double)fuelPrice * annualDistance * years / fuel;
	if (t < ret)
	  ret = t;
      }

    return ret;
  }

   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { string Arr0[] = {"10000 50 50","12000 500 10","15000 100 65","20000 20 80","25000 10 90"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 5000; int Arg3 = 2; double Arg4 = 10500.0; verify_case(0, Arg4, lowestCost(Arg0, Arg1, Arg2, Arg3)); }
  void test_case_1() { string Arr0[] = {"10000 50 50","12000 500 10","15000 100 65","20000 20 80","25000 10 90"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; int Arg2 = 25000; int Arg3 = 10; double Arg4 = 45200.0; verify_case(1, Arg4, lowestCost(Arg0, Arg1, Arg2, Arg3)); }
  void test_case_2() { string Arr0[] = {"8426 774 19","29709 325 31","30783 853 68","20796 781 3"
					,"27726 4 81","20788 369 69","17554 359 34","12039 502 24"
					,"6264 230 69","14151 420 65","25115 528 70","22234 719 55"
					,"2050 926 40","18618 714 29","173 358 57"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 33; int Arg2 = 8673; int Arg3 = 64; double Arg4 = 254122.44444444444; verify_case(2, Arg4, lowestCost(Arg0, Arg1, Arg2, Arg3)); }

  // END CUT HERE

};

// BEGIN CUT HERE
int main() {
CarBuyer ___test;
___test.run_test(-1);
}
// END CUT HERE 
