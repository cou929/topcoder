#include <stdio.h>

#define N 6


int main(void)
{
  int c, i, j, k, l, m, n, o;
  int values[N] = {10, 13, 10, 16, 2, 3};
  int weights[N] = {3, 5, 4, 7, 2, 4};
  int maxi = 0;



  for (i=0; i<combs.size(); i++) 
    {
      int value = 0;
      int weight = 0;

      for (j=0; j<combs[i].size(); j++)
	{
	  value += values[combs[i][j]-1];
	  weight += weights[combs[i][j]-1];
	}

      if (weight <= 14 && value > maxi)
	{
	  maxi = value;
	  cout << "items: ";
	  for (j=0; j<combs[i].size(); j++)
	    cout << combs[i][j] << " ";
	  cout << "\n" << "value: " << maxi << "\n";
	}
    }

  return 0;
}
