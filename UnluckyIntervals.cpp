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
#include <queue>
#include <stack>
using namespace std;
class UnluckyIntervals {
public:
  vector <int> getLuckiest(vector <int> luckySet, int n) {
    vector <int> ret;
    set <pair <long long, long long> > candidates;
    
    luckySet.push_back(0);
    sort(luckySet.begin(), luckySet.end());

    for (int i=0; i<luckySet.size()-1; i++) {
      candidates.insert(make_pair(0, luckySet[i+1]));
      if (luckySet[i+1] - luckySet[i] == 1) continue;
      long long left = luckySet[i] + 1, right = luckySet[i+1] - 1;
      long long len = right - left + 1;
      long long lim = min(len/2, (long long)n-1);
      for (long long j=0; j<=lim; j++) {
        long long c = len - j - 1;
        for (int k=0; k<j; k++)
          c += (len - k - 1) - (j - k) + 1;
        candidates.insert(make_pair(c, left + j));
        candidates.insert(make_pair(c, right - j));
      }
    }

    int j=0;
    for (set <pair <long long, long long> >::iterator i=candidates.begin(); i!=candidates.end() && j<n; i++, j++)
      ret.push_back(i->second);

    if (ret.size() < n) {
      int N = n - ret.size();
      for (int i=0; i<N; i++)
        ret.push_back(luckySet[luckySet.size()-1]+i+1);
    }
    
    return ret;
  }
   
  // BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case ==5)) test_case_5(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; int Arr2[] = {3, 1, 2, 4, 5, 6 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, getLuckiest(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {5, 11, 18}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; int Arr2[] = {5, 11, 18, 1, 4, 6, 10, 2, 3 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, getLuckiest(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {7, 13, 18}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; int Arr2[] = {7, 13, 18, 14, 17, 8, 12, 1, 6 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, getLuckiest(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1000, 1004, 4000, 4003, 5000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 19; int Arr2[] = {1000, 1004, 4000, 4003, 5000, 4001, 4002, 1001, 1003, 1002, 4004, 4999, 1, 999, 4005, 4998, 2, 998, 4006 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, getLuckiest(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {1000000000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; int Arr2[] = {1000000000, 1, 999999999, 2, 999999998, 3, 999999997, 4 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, getLuckiest(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {1000000000, 999999998, 999999996, 999999995, 999999994, 999999992, 999999989, 499999996, 499999994, 499999993, 499999991, 499999990, 499999989, 499999987, 2, 4, 6, 8, 9, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; int Arr2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 499999987, 499999988, 499999989, 499999990, 499999991, 499999992, 499999993, 499999994, 499999995, 499999996, 999999989, 999999992, 999999993, 999999994, 999999995, 999999996, 999999997, 999999998, 999999999, 1000000000, 999999990, 999999991, 11, 499999986, 499999997, 999999988, 12, 499999985, 499999998, 999999987, 13, 499999984, 499999999, 999999986, 14, 499999983, 500000000, 999999985, 15, 499999982, 500000001, 999999984, 16, 499999981, 500000002, 999999983, 17, 499999980, 500000003, 999999982, 18, 499999979, 500000004, 999999981, 19, 499999978, 500000005, 999999980, 20, 499999977, 500000006, 999999979, 21, 499999976, 500000007, 999999978, 22, 499999975, 500000008, 999999977, 23, 499999974, 500000009, 999999976, 24, 499999973, 500000010, 999999975, 25, 499999972, 500000011, 999999974, 26, 499999971, 500000012, 999999973, 27, 499999970, 500000013, 999999972}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, getLuckiest(Arg0, Arg1)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
UnluckyIntervals ___test;
___test.run_test(-1);
}
// END CUT HERE 
