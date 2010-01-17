#include <string>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

class Workshop {
public:
	int pictureFrames(vector <int> pieces) {
		int i, j, k;
        int ret = 0;

        for(i=0; i<pieces.size(); i++)
            for(j=i+1; j<pieces.size(); j++)
                for(k=j+1; k<pieces.size(); k++)
                    ret += compare(pieces[i], pieces[j], pieces[k]);

        return ret;
    }

    int compare(int a, int b, int c)
    {
        if(a+b <= c)
            return 0;
        if(b+c <= a)
            return 0;
        if(c+a <= b)
            return 0;
        return 1;
    }
};
