#include <string>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

class Bonuses {
public:
  vector <int> getDivision(vector <int> points) {
    vector <int> ret(points.size());
    unsigned int i, j, tmp;
    int totalPoint = 0;
    int restPoint = 100;
    int sort[points.size()];

    for(i=0; i<points.size(); i++)
      {
	totalPoint += points[i];
	sort[i] = i;
      }

    for(i=0; i<points.size(); i++)
      {
	ret[i] = (int)((double)points[i] / (double)totalPoint * 100.0);
	restPoint -= ret[i];
      }

    for(i=1; i<points.size(); i++)
      for(j=i; j>0 && points[sort[j-1]] >= points[sort[j]]; j--)
	{
	  tmp = sort[j];
	  sort[j] = sort[j-1];
	  sort[j-1] = tmp;
	}

    for(i=points.size()-1; restPoint > 0; i--, restPoint--)
      ret[sort[i]]++;


    return ret;
  }

 
  // BEGIN CUT HERE
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }

private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
  void test_case_0() { int Arr0[] = {1,2,3,4,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 6,  13,  20,  27,  34 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getDivision(Arg0)); }
  void test_case_1() { int Arr0[] = {5,5,5,5,5,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 17,  17,  17,  17,  16,  16 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getDivision(Arg0)); }
  void test_case_2() { int Arr0[] = {485, 324, 263, 143, 470, 292, 304, 188, 100, 254, 296,
				     255, 360, 231, 311, 275,  93, 463, 115, 366, 197, 470}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 8,  6,  4,  2,  8,  5,  5,  3,  1,  4,  5,  4,  6,  3,  5,  4,  1,  8,  1,  6,  3,  8 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getDivision(Arg0)); }

  // END CUT HERE

};

// BEGIN CUT HERE
int main() {
Bonuses ___test;
___test.run_test(-1);
}
// END CUT HERE
