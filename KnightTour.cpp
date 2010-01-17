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

using namespace std;

class KnightTour {
public:
  vector <string> cells;

  bool visitAllCell(void)
  {
    map <string, int> cellCount;
    bool ret = true;

    for (int i=0; i<cells.size(); i++)
      cellCount[cells[i]]++;

    if (cellCount.size() != 36)
      ret = false;

    return ret;
  }

  bool correctMove(string from, string to)
  {
    bool ret = false;
    int col = abs(from[0] - to[0]);
    int row = abs(from[1] - to[1]);

    if ((col == 2 && row == 1) || (col == 1 && row == 2))
      ret = true;

    return ret;
  }

  string checkTour(vector <string> _cells)
  {
    cells = _cells;

    if (!visitAllCell())
      return "Invalid";

    for (int i=0; i<cells.size()-1; i++)
      if (!correctMove(cells[i], cells[i+1]))
	return "Invalid";

    if (!correctMove(cells[cells.size()-1], cells[0]))
      return "Invalid";

    return "Valid";
  }

   
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { string Arr0[] = {"A1", "B3", "A5", "C6", "E5", "F3",
					"D2", "F1", "E3", "F5", "D4", "B5",
					"A3", "B1", "C3", "A2", "C1", "E2",
					"F4", "E6", "C5", "A6", "B4", "D5",
					"F6", "E4", "D6", "C4", "B6", "A4",
					"B2", "D1", "F2", "D3", "E1", "C2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Valid"; verify_case(0, Arg1, checkTour(Arg0)); }
  void test_case_1() { string Arr0[] = {"A1", "C2", "E3", "F5", "D4", "B3",
					"A1", "C2", "E3", "F5", "D4", "B3", 
					"A1", "C2", "E3", "F5", "D4", "B3", 
					"A1", "C2", "E3", "F5", "D4", "B3", 
					"A1", "C2", "E3", "F5", "D4", "B3", 
					"A1", "C2", "E3", "F5", "D4", "B3"}
    ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Invalid"; verify_case(1, Arg1, checkTour(Arg0)); }
  void test_case_2() { string Arr0[] = {"D4", "F5", "D6", "B5", "A3", "B1", 
					"D2", "F1", "E3", "D1", "F2", "E4", 
					"F6", "D5", "B6", "A4", "B2", "C4", 
					"A5", "C6", "E5", "F3", "E1", "C2", 
					"A1", "B3", "C5", "E6", "F4", "E2", 
					"C3", "A2", "C1", "D3", "B4", "A6"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Invalid"; verify_case(2, Arg1, checkTour(Arg0)); }
  void test_case_3() { string Arr0[] = {"D4", "F5", "D6", "B5", "A3", "B1", 
					"D2", "F1", "E3", "D1", "F2", "E4", 
					"F6", "D5", "B6", "A4", "B2", "C4", 
					"A5", "C6", "E5", "F3", "E1", "C2", 
					"A1", "B3", "C5", "A6", "B4", "A2", 
					"C3", "E2", "C1", "D3", "F4", "E6"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Valid"; verify_case(3, Arg1, checkTour(Arg0)); }
  void test_case_4() { string Arr0[] = {"C5", "D3", "F2", "D1", "B2", "A4", 
					"B6", "D5", "C3", "E4", "F6", "B3", 
					"A1", "C2", "E1", "F3", "E5", "C6", 
					"A5", "C4", "A3", "B1", "D2", "F1", 
					"E3", "F5", "D6", "B5", "D4", "E6", 
					"F4", "E2", "C1", "A2", "B4", "A6"}
    ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Invalid"; verify_case(4, Arg1, checkTour(Arg0)); }

  // END CUT HERE

};

// BEGIN CUT HERE
int main() {
KnightTour ___test;
___test.run_test(-1);
}
// END CUT HERE 
