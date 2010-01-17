#include <string>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

class StreetParking {
	public:
	int freeParks(string street) {
        int i;
        int count = 0;

        for(i=0; i<street.size(); i++)
            {
                if(street[i] != '-')
                    continue;
                if(street[i+1] == 'S' || street[i+1] == 'B')
                    continue;
                if(street[i+2] == 'B')
                    continue;
                if(i>0)
                    if(street[i-1] == 'S')
                        continue;
                count++;
                
            }
        return count;
	}
};
