#include <string>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

class Justifier {
	public:
	vector <string> justify(vector <string> textIn) {
        int i, j;
        int maxSize = 0;
        vector <string> ret(textIn.size());

        for(i=0; i<textIn.size(); i++)
            {
                if(maxSize < textIn[i].size())
                    maxSize = textIn[i].size();
            }

        for(i=0; i<textIn.size(); i++)
            {
                ret[i] = "";
                for(j=0; j<maxSize - textIn[i].size(); j++)
                    ret[i] += " ";
                ret[i] += textIn[i];
            }
        return ret;
	}
};
