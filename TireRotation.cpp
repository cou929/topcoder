#include <string>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

class TireRotation {
public:
	int getCycle(string initial, string current) {
		string rot = initial, tmp;
        int i, j, flagDifferent = 0;

        for(i=1; i<=4; i++)
            {
                flagDifferent = 0;

                for(j=0; j<4; j++)
                    if(rot[j] != current[j])
                        {
                            flagDifferent = 1;
                            break;
                        }
                cout << i << ": " << rot[0] << rot[1] << rot[2] << rot[3] << endl;

                if(flagDifferent == 0)
                    return i;
                else
                    {
                        cout << i << ": " << rot[0] << rot[1] << rot[2] << rot[3] << endl;
                        tmp[2] = rot[0];
                        cout << i << ": " << rot[0] << rot[1] << rot[2] << rot[3] << endl;
                        tmp[3] = rot[1];
                        cout << i << ": " << rot[0] << rot[1] << rot[2] << rot[3] << endl;
                        tmp[1] = rot[2];
                        cout << i << ": " << rot[0] << rot[1] << rot[2] << rot[3] << endl;
                        tmp[0] = rot[3];

                        cout << tmp[0] << tmp[1] << tmp[2] << tmp[3] << endl;
                        rot = tmp;
                        printf("rot: %p, tmp: %p", &rot, &tmp);
                        //for(j=0; j<4; j++)
                        //rot[j] = tmp[j];
                    }
            }

        return -1;
    }
};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
