#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ImageDithering
{
private:
public:
	int count(string dithered, vector<string> screen);
};

int ImageDithering::count(string dithered, vector <string> screen)
{
	int i = 0, j = 0, k = 0;
	int count = 0;
	
	for(i=0; i<screen.size(); i++)
	{
		j = 0;
		while(screen[i][j] != '\0')
		{
			for(k=0; k<dithered.size(); k++)
			{
				if(screen[i][j] == dithered[k])
					count++;
			}
			j++;
		}
	}

	return count;
}
