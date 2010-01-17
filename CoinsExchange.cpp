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

class CoinsExchange {
public:
  int countExchanges(int G1, int S1, int B1, int G2, int S2, int B2)
  {
int ret = 0;

while (G1 < G2) {
if (S1 >= 11) {
S1 -= 11;
G1++;
ret++; 
}
else if (B1 >= 11) {
B1 -= 11;
S1++;
ret++;
}
else
return -1;
}

while (S1 < S2) {
if (G1 > G2) {
G1--;
S1 += 9;
ret++; 
}
else if (B1 >= 11) {
B1 -= 11;
S1++;
ret++;
}
else
return -1;
}

while (B1 < B2) {
if (G1 > G2) {
G1--;
S1 += 9;
ret++; 
}
else if (S1 > S2) {
S1--;
B1 += 9;
ret++;
}
else
return -1;
}
return ret;
  }

   

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
