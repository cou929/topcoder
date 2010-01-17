#include <string>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

class CeyKaps {
	public:
	string decipher(string typed, vector <string> switches) {
		int i, j;
		string ret;
		char c;
		char sw[2];
		
		for(i=0; i<typed.size(); i++)
		{
			c = typed[i];
			for(j=0; j<switches.size(); j++)
			{
				sw[0] = switches[j][0];
				sw[1] = switches[j][2];
				if(sw[0] == c)
					c = sw[1];
				else if(sw[1] == c)
					c = sw[0];
			}
			ret.push_back(c);
		}
		return ret;
	}
};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
