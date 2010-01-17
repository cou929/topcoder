#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

class RunLengthEncoding {
public:
  string decode(string text)
  {
    int i;
    int length = 0;
    string ret;

    for (i=0; i<text.size(); i++)
      {
	if (text[i] >= '0' && text[i] <= '9')
	  {
	    int tmp = 0;
	    while (text[i] >= '0' && text[i] <= '9')
	      {
		tmp = tmp * 10 + (text[i] - '0');
		i++;
	      }

	    length += tmp;

	    if (length > 50)
	      return "TOO LONG";

	    for (int j=0; j<tmp; j++)
	      ret.push_back(text[i]);
	  }
	else
	  {
	    ret.push_back(text[i]);
	    length++;
	  }

	if (length > 50)
	  return "TOO LONG";
      }

    return ret;
  }

   

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
