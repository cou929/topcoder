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
class UnderscoreJustification {
public:
  string justifyLine(vector <string> words, int width) {
    string ret = words[0];
    int word_length = 0;
    int spaces = words.size() - 1;
    int underscores = 0;
    int rest_underscores = 0;

    for (int i=0; i<words.size(); i++)
      word_length += words[i].size();

    underscores = (width - word_length) / spaces;
    rest_underscores = (width - word_length) % spaces;

    vector <int> space_nums(spaces, underscores);

    for (int i=1; i<words.size(); i++)
      if (rest_underscores > 0 && 'a' <= words[i][0] && words[i][0] <= 'z') {
        space_nums[i-1]++;
        rest_underscores--;
      }

    for (int i=space_nums.size()-1; i>=0; i--)
      if (rest_underscores > 0 && space_nums[i] == underscores) {
        space_nums[i]++;
        rest_underscores--;
      }

    for (int i=1; i<words.size(); i++) {
      string space(space_nums[i-1], '_');
      ret += space;
      ret += words[i];
    }

    return ret;
  }
   

};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
