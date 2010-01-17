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

class DocumentSearch {
public:
  int nonIntersecting(vector <string> doc, string search)
  {
    int i, j, k;
    int ret = 0;
    string s = "";

    for (i=0; i<doc.size(); i++)
      s += doc[i];

    for (i=0; i<s.size(); i++)
      {
	if (s[i] == search[0])
	  {
	    bool found = true;
	    for (k=1; k<search.size(); k++)
	      {
		if (s[i+k] != search[k])
		  {
		    found = false;
		    break;
		  }
	      }

	    if (i+search.size() >= s.size())
	      found = false;

	    if (found)
	      {
		ret++;
		i += k-1;
	      }
	  }
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


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
