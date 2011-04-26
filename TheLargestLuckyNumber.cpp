#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

int toInt(string s) {int r = 0; istringstream ss(s); ss >> r; return r;}
string toStr(int n) {ostringstream ss; ss << n; return ss.str();}

class TheLargestLuckyNumber {
   public:
   int find(int n) {
     int i, j, ret = 0;
     for (i=n; i>0; i--) {
       string s = toStr(i);
       bool isLucky = true;
       for (j=0; j<s.size(); j++) {
         if (s[j] != '4' && s[j] != '7')
           isLucky = false;
       }
       if (isLucky) {
         ret = i;
         break;
       }
     }
     return ret;
   }
};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
