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
#define INF 2000000000
vector <int> protein;
vector <int>  carbs;
vector <int> fat;
vector <int>  calorie;
class HealthFood {
public:
  vector <int> selectMeals(vector <int> _protein, vector <int> _carbs, vector <int> _fat, vector <string> dietPlans) {
    calorie.clear();
    vector <int> ret;
    protein = _protein;
    carbs = _carbs;
    fat = _fat;
    int i, j;

    for (i=0; i<protein.size(); i++)
      calorie.push_back(protein[i] * 5 + carbs[i] * 5 + fat[i] * 9);

    for (i=0; i<dietPlans.size(); i++) {
      vector <int> plan;
      for (j=0; j<protein.size(); j++)
        plan.push_back(j);

      for (j=0; j<dietPlans[i].size(); j++) {
        plan = calc(dietPlans[i][j], plan);
        if (plan.size() == 1)
          break;
      }
      ret.push_back(plan[0]);
    }

    return ret;
  }

  vector <int> calc(char c, vector <int> can) {
    if (c == 'C')
      return get_most(carbs, can, true);
    else if (c == 'c')
      return get_most(carbs, can, false);
    else if (c == 'P')
      return get_most(protein, can, true);
    else if (c == 'p')
      return get_most(protein, can, false);
    else if (c == 'F')
      return get_most(fat, can, true);
    else if (c == 'f')
      return get_most(fat, can, false);
    else if (c == 'T')
      return get_most(calorie, can, true);
    else if (c == 't')
      return get_most(calorie, can, false);
  }

  vector <int> get_most(vector <int> seq, vector <int> idx, bool isMax) {
    vector <int> ret;
    int i;
    int most = (isMax) ? 0 : INF;

    for (i=0; i<idx.size(); i++) {
      if (isMax) {
        if (seq[idx[i]] > most) {
          most = seq[idx[i]];
          ret.clear();
          ret.push_back(idx[i]);
        } else if (seq[idx[i]] == most) {
          most = seq[idx[i]];
          ret.push_back(idx[i]);
        }
      } else {
        if (seq[idx[i]] < most) {
          most = seq[idx[i]];
          ret.clear();
          ret.push_back(idx[i]);
        } else if (seq[idx[i]] == most) {
          most = seq[idx[i]];
          ret.push_back(idx[i]);
        }
      }
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
  }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { 
    int Arr0[] = {3, 4}; 
    vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arr1[] = {2, 8}; 
    vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    int Arr2[] = {5, 2}; 
    vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
    string Arr3[] = {"P", "p", "C", "c", "F", "f", "T", "t"}; 
    vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); 
    int Arr4[] = { 1,  0,  1,  0,  0,  1,  1,  0 }; 
    vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); 
    verify_case(0, Arg4, selectMeals(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { 
    int Arr0[] = {3, 4, 1, 5}; 
    vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arr1[] = {2, 8, 5, 1}; 
    vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    int Arr2[] = {5, 2, 4, 4}; 
    vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
    string Arr3[] = {"tFc", "tF", "Ftc"}; 
    vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); 
    int Arr4[] = { 3,  2,  0 }; 
    vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); 
    verify_case(1, Arg4, selectMeals(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { 
    int Arr0[] = {18, 86, 76,  0, 34, 30, 95, 12, 21}; 
    vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arr1[] = {26, 56,  3, 45, 88,  0, 10, 27, 53}; 
    vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    int Arr2[] = {93, 96, 13, 95, 98, 18, 59, 49, 86}; 
    vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
    string Arr3[] = {"f", "Pt", "PT", "fT", "Cp", "C", "t", "",
                     "cCp", "ttp", "PCFt", "P", "pCt", "cP", "Pc"}
    ; 
    vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); 
    int Arr4[] = { 2,  6,  6,  2,  4,  4,  5,  0,  5,  5,  6,  6,  3,  5,  6 }; 
    vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); 
    verify_case(2, Arg4, selectMeals(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { 
    int Arr0[] = {3, 4}; 
    vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arr1[] = {2, 8}; 
    vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    int Arr2[] = {5, 2}; 
    vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
    string Arr3[] = {"P", "p", "C", "c", "F", "f", "T", "t"}; 
    vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); 
    int Arr4[] = { 1,  0,  1,  0,  0,  1,  1,  0 }; 
    vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); 
    verify_case(3, Arg4, selectMeals(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { 
    int Arr0[] = {3, 4}; 
    vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    int Arr1[] = {2, 8}; 
    vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    int Arr2[] = {5, 2}; 
    vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
    string Arr3[] = {"P", "p", "C", "c", "F", "f", "T", "t"}; 
    vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); 
    int Arr4[] = { 1,  0,  1,  0,  0,  1,  1,  0 }; 
    vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); 
    verify_case(4, Arg4, selectMeals(Arg0, Arg1, Arg2, Arg3)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
  HealthFood ___test;
  ___test.run_test(-1);
}
// END CUT HERE 
