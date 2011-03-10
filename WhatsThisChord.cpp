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
class WhatsThisChord {
public:
  vector <string> notes;

  string getChord(string chord, int offset) {
    int pos = 0;
    int i;
    for (i=0; i<notes.size(); i++)
      if (chord == notes[i]) {
        pos = i;
        break;
      }
    return notes[(pos + offset) % notes.size()];
  }

  void next(vector <string> &chords) {
    for (int i=0; i<chords.size(); i++)
      chords[i] = getChord(chords[i], 1);
    return;
  }

  bool isSame(vector <string> v, set <string> s) {
    bool ret = true;
    if (v.size() != s.size())
      return false;
    for (int i=0; i<v.size(); i++)
      if (s.find(v[i]) == s.end())
        ret = false;
    return ret;
  }

  string classify(vector <int> chord) {
    string ret;
    vector <string> stdTurning;
    set <string> playedChords;
    vector <string> major;
    vector <string> minor;
    int i;

    notes.clear();
    notes.push_back("C");
    notes.push_back("C#");
    notes.push_back("D");
    notes.push_back("D#");
    notes.push_back("E");
    notes.push_back("F");
    notes.push_back("F#");
    notes.push_back("G");
    notes.push_back("G#");
    notes.push_back("A");
    notes.push_back("A#");
    notes.push_back("B");

    stdTurning.push_back("E");
    stdTurning.push_back("A");
    stdTurning.push_back("D");
    stdTurning.push_back("G");
    stdTurning.push_back("B");
    stdTurning.push_back("E");

    major.push_back("C");
    major.push_back("E");
    major.push_back("G");

    minor.push_back("C");
    minor.push_back("D#");
    minor.push_back("G");

    for (i=0; i<chord.size(); i++)
      if (chord[i] != -1)
        playedChords.insert(getChord(stdTurning[i], chord[i]));

    if (playedChords.size() != 3)
      return ret;

    for (i=0; i<12; i++, next(major), next(minor)) {
      if (isSame(major, playedChords)) {
        ret = major[0] + " Major";
        break;
      } else if (isSame(minor, playedChords)) {
        ret = major[0] + " Minor";
        break;
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
    if ((Case == -1) || (Case == 5)) test_case_5();
    if ((Case == -1) || (Case == 6)) test_case_6();
    if ((Case == -1) || (Case == 7)) test_case_7();
    if ((Case == -1) || (Case == 8)) test_case_8();
    if ((Case == -1) || (Case == 9)) test_case_9();
  }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { 
    int Arr0[] = {-1, 3, 2, 0, 1, 0}; 
    vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    string Arg1 = "C Major"; 
    verify_case(0, Arg1, classify(Arg0)); }
	void test_case_1() { 
    int Arr0[] = {3,2,0,0,0,3}; 
    vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    string Arg1 = "G Major"; 
    verify_case(1, Arg1, classify(Arg0)); }
	void test_case_2() { 
    int Arr0[] = {-1,0,2,2,1,0}; 
    vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    string Arg1 = "A Minor"; 
    verify_case(2, Arg1, classify(Arg0)); }
	void test_case_3() { 
    int Arr0[] = {-1,4,3,1,2,1}; 
    vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    string Arg1 = "C# Major"; 
    verify_case(3, Arg1, classify(Arg0)); }
	void test_case_4() { 
    int Arr0[] = {8,10,10,9,8,8}; 
    vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    string Arg1 = "C Major"; 
    verify_case(4, Arg1, classify(Arg0)); }
	void test_case_5() { 
    int Arr0[] = {0,0,0,0,0,0}; 
    vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    string Arg1 = ""; 
    verify_case(5, Arg1, classify(Arg0)); }
	void test_case_6() { 
    int Arr0[] = {-1,-1,4,-1,-1,7}; 
    vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    string Arg1 = ""; 
    verify_case(6, Arg1, classify(Arg0)); }
	void test_case_7() { 
    int Arr0[] = {-1, -1, 2, 0, 1, 0}; 
    vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    string Arg1 = "C Major"; 
    verify_case(7, Arg1, classify(Arg0)); }
	void test_case_8() { 
    int Arr0[] = {-1, 3, 2, 0, 1, 0}; 
    vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    string Arg1 = "C Major"; 
    verify_case(8, Arg1, classify(Arg0)); }
	void test_case_9() { 
    int Arr0[] = {-1, 3, 2, 0, 1, 0}; 
    vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    string Arg1 = "C Major"; 
    verify_case(9, Arg1, classify(Arg0)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
WhatsThisChord ___test;
___test.run_test(-1);
}
// END CUT HERE 
