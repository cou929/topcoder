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
struct item {
    char label;
    int score;
    int finish_runner;
    int sixth_score;
};

bool cmp(const item & left, const item & right) {
    bool ret;
    if (left.score == right.score) {
        if (left.sixth_score != -1 && right.sixth_score != -1) {
            ret = left.sixth_score < right.sixth_score;
        } else if (left.sixth_score == -1 && right.sixth_score != -1) {
            ret = false;
        } else if (left.sixth_score != -1 && right.sixth_score == -1) {
            ret = true;
        } else {
            ret = left.label < right.label;
        }
    } else {
        ret = left.score < right.score;
    }

    return ret;
}

class CrossCountry {
public:

    string scoreMeet(int numTeams, string finishOrder) {
        string ret;
        map <char, int> runner_num;
        map <char, int> score;
        map <char, int> sixth;
        vector <item> order;
        int i;

        for (i=0; i<finishOrder.size(); i++) {
            if (runner_num[finishOrder[i]] < 5)
                score[finishOrder[i]] += i+1;
            else if (runner_num[finishOrder[i]] == 5)
                sixth[finishOrder[i]] = i+1;
            runner_num[finishOrder[i]] += 1;
        }

        for (map <char, int>::iterator it=score.begin(); it!=score.end(); it++) {
            item tmp;
            tmp.label = it->first;
            tmp.score = it->second;
            tmp.finish_runner = runner_num[it->first];
            if (sixth.find(it->first) != sixth.end())
                tmp.sixth_score = sixth[it->first];
            else
                tmp.sixth_score = -1;

            order.push_back(tmp);
        }

        sort(order.begin(), order.end(), cmp);
        
        for (i=0; i<numTeams; i++) {
            if (order[i].finish_runner > 4)
                ret += order[i].label;
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
    void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { 
        int Arg0 = 2; 
        string Arg1 = "AABBABBABBA"; 
        string Arg2 = "AB"; 
        verify_case(0, Arg2, scoreMeet(Arg0, Arg1)); }
    void test_case_1() { 
        int Arg0 = 3; 
        string Arg1 = "CCCBBBBBAAACC"; 
        string Arg2 = "BC"; 
        verify_case(1, Arg2, scoreMeet(Arg0, Arg1)); }
    void test_case_2() { 
        int Arg0 = 4; 
        string Arg1 = "ABDCBADBDCCDBCDBCAAAC"; 
        string Arg2 = "BDCA"; 
        verify_case(2, Arg2, scoreMeet(Arg0, Arg1)); }
    void test_case_3() { 
        int Arg0 = 10; 
        string Arg1 = "BDHCEAJBIDBCCHGCBDJEBAAHEGAGGADHGIECJEHAEBDADJCDHG"; 
        string Arg2 = "BCDAHEG"; 
        verify_case(3, Arg2, scoreMeet(Arg0, Arg1)); }
    void test_case_4() { 
        int Arg0 = 3; 
        string Arg1 = "BABCAABABAB"; 
        string Arg2 = "AB"; 
        verify_case(4, Arg2, scoreMeet(Arg0, Arg1)); }
    void test_case_5() { 
        int Arg0 = 2; 
        string Arg1 = "AABBABBABBA"; 
        string Arg2 = "AB"; 
        verify_case(5, Arg2, scoreMeet(Arg0, Arg1)); }
    void test_case_6() { 
        int Arg0 = 2; 
        string Arg1 = "AABBABBABBA"; 
        string Arg2 = "AB"; 
        verify_case(6, Arg2, scoreMeet(Arg0, Arg1)); }

    // END CUT HERE

};
// BEGIN CUT HERE
int main() {
    CrossCountry ___test;
    ___test.run_test(-1);
}
// END CUT HERE 
