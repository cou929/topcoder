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
class TheEncryptionDivTwo {
public:
  string encrypt(string message) {
    string ret;
    map <char, char> m;
    int counter = 0;

    for (int i=0; i<message.size(); i++)
      if (m.find(message[i]) != m.end()) {
        ret += m[message[i]];
      } else {
        m[message[i]] = 'a' + counter++;
        ret += m[message[i]];
      }

    return ret;
  }
   

};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
