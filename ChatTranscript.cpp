#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

class ChatTranscript {
public:
  int howMany(vector <string> transcript, string name)
  {
    int i, j;
    int counter = 0;
    string::iterator it;

    for (i=0; i<transcript.size(); i++)
      {
	int flg = 0;

	it = find(transcript[i].begin(), transcript[i].end(), ':');

	if (transcript[i].begin() + name.size() != it)
	  continue;

	for (j=0; j<name.size(); j++)
	  if (transcript[i][j] != name[j])
	    {
	      flg = 1;
	      break;
	    }

	if (flg == 0)
	  counter++;
      }
    return counter;
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
