// knapsack2.c

#include <stdio.h>

#define N 20
#define WEIGHT_LIMIT 8

//  int values[N] = {10, 13, 10, 16, 2, 3};
//  int weights[N] = {3, 5, 4, 7, 2, 4};

int values[N];
int weights[N];

int path[N];
int index = 0;
int max = 0;

int r(int step)
{
  step--;
  if (step == -1)
    {
      int v = 0, w = 0;
      int i;
      for (i=0; i<N; i++)
	{
	  if (path[i] == 1)
	    {
	      v += values[i];
	      w += weights[i];
	    }
	}

      if (max < v)
	{
	  max = v;
	  printf("value: %d\nweight: %d\n", v, w);
	}

      // print result
      printf("%d: ", index++);
      for (i=0; i<N; i++)
	printf("%d ", path[i]);
      printf("\n");

      int ret = 1;
      if (w >= WEIGHT_LIMIT)
	ret = 0;
      
      return ret;
    }
  else
    {
      int result;

      path[N-step-1] = 0;
      result = r(step);
      if (result == 0)
      	return 1;

      path[N-step-1] = 1;
      result = r(step);
      if (result == 0)
      	return 1;
    }
}

int main(void)
{
  int i;
  for (i=0; i<N; i++)
    {
      values[i] = 1;
      weights[i] = 1;
    }

  r(N);

  return 0;
}
