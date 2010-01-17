#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

class DiskSpace
{
public:
	int minDrives(vector<int> used, vector<int> total)
	{
		int i;
		int max = -1;
		int index = 0;
		
		for(i=0; i<used.size(); i++)
		{
			if(max <= total[i] - used[i])
			{
				max = total[i] - used[i];
				index = i;
			}
		}
		
		return index + 1;
	}
};
