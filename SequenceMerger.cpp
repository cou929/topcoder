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
#include <numeric>
// BEGIN CUT HERE
#include "cout.hpp"
// END CUT HERE 
using namespace std;
class SequenceMerger {
public:
  vector <vector <long long> >pseqs;

  vector <int> getVal(vector <string> seqs, vector <int> positions) {
    vector <int> ret;
    pseqs.clear();
    int i, j;
    int n = seqs.size(), m = positions.size();

    // parse
    for (i=0; i<n; i++) {
      istringstream sin(seqs[i]);
      char type;
      vector <long long> tmp;
      sin >> type;
      if (type == 'A' || type == 'G') {
        long long A, B, C;
        sin >> A >> B >> C;
        tmp.push_back(A), tmp.push_back(B), tmp.push_back(C);
        pseqs.push_back(tmp);
      } else {
        long long l;
        while (sin >> l)
          tmp.push_back(l);
        sort(tmp.begin(), tmp.end());
        pseqs.push_back(tmp);
      }
    }

    // binary search
    for (i=0; i<m; i++) {
      int left = 0, right = 1000000000;
      while (left < right - 1) {
        int mid = (left + right) / 2;
        int counter = 0;
        for (j=0; j<n; j++) {
          if (seqs[j][0] == 'A') {
            long long x = (mid - pseqs[j][0]) / pseqs[j][1];
            counter += min(x, pseqs[j][2]-1);
          } else if (seqs[j][0] == 'G') {
            long long x = log(mid / pseqs[j][0]) / log(pseqs[j][1]);
            counter += min(x, pseqs[j][2]-1);
          } else {
            int k = 0;
            while (pseqs[j][k] < mid)
              counter++, k++;
          }
        }
        if (counter >= positions[i])
          right = mid;
        else
          left = mid;
      }
      if (right > 1000000000) ret.push_back(-1);
      else ret.push_back(right);
    }

    return ret;
  }
   
  // BEGIN CUT HERE
public:
	void run_test(int Case) { 
    if ((Case == -1) || (Case == 0)) test_case_0();
    if ((Case == -1) || (Case == 1)) test_case_1();
    if ((Case == -1) || (Case == 2)) test_case_2();
    if ((Case == -1) || (Case == 3)) test_case_3();
    if ((Case == -1) || (Case == 4)) test_case_4();
    if ((Case == -1) || (Case == 5)) test_case_5();
    if ((Case == -1) || (Case == 6)) test_case_6();
  }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { 
    string Arr0[] = {"E 1 1000000000 1000000001"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arr1[] = {1,2,3,4}; 
    vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    int Arr2[] = {1, 1000000000, -1, -1 }; 
    vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
    verify_case(0, Arg2, getVal(Arg0, Arg1)); }
	void test_case_1() { 
    string Arr0[] = {"A 1 1 10", "G 1 2 4"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arr1[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15}; 
    vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    int Arr2[] = {1, 1, 2, 2, 3, 4, 4, 5, 6, 7, 8, 8, 9, 10, -1 }; 
    vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
    verify_case(1, Arg2, getVal(Arg0, Arg1)); }
	void test_case_2() { 
    string Arr0[] = {"A 1000000000 1000000000 1000000000","G 100000000000000000 1000000000000 100000000000000", "E 1000000000000000 10000000 10 1111"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arr1[] = {1,2,3,4,5,6,7,8,9,10}; 
    vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    int Arr2[] = {10, 1111, 10000000, 1000000000, -1, -1, -1, -1, -1, -1 }; 
    vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
    verify_case(2, Arg2, getVal(Arg0, Arg1)); }
	void test_case_3() { 
    string Arr0[] = {"G 1 1 999999999", "E 2"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arr1[] = {1,999999999,1000000000}; 
    vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    int Arr2[] = {1, 1, 2 }; 
    vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
    verify_case(3, Arg2, getVal(Arg0, Arg1)); }
	void test_case_4() { 
    string Arr0[] = {"A 100 341 1524", "G 1 3 45235", "E 653 87 12341 8785 123 543"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arr1[] = {100000,1,10,10000,100,1000}; 
    vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    int Arr2[] = {-1, 1, 441, -1, 28403, 334621 }; 
    vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
    verify_case(4, Arg2, getVal(Arg0, Arg1)); }
	void test_case_5() { 
    string Arr0[] = {"E 1 1000000000 1000000001"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arr1[] = {1,2,3,4}; 
    vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    int Arr2[] = {1, 1000000000, -1, -1 }; 
    vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
    verify_case(5, Arg2, getVal(Arg0, Arg1)); }
	void test_case_6() { 
    string Arr0[] = {"E 1 1000000000 1000000001"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arr1[] = {1,2,3,4}; 
    vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    int Arr2[] = {1, 1000000000, -1, -1 }; 
    vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
    verify_case(6, Arg2, getVal(Arg0, Arg1)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
SequenceMerger ___test;
___test.run_test(-1);
}
// END CUT HERE 
