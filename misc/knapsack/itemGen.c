#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ITEM_NUM 100

int randoms(int *dst, int mini, int maxi, int n);

int main(void)
{
  int values[ITEM_NUM];
  int weights[ITEM_NUM];
  int limit = 0;
  int mini = 5;
  int maxi = 50;

  randoms(values, mini, maxi, ITEM_NUM);
  randoms(weights, mini, maxi, ITEM_NUM);
  randoms(&limit, mini, maxi, 1);

  int i;
  for (i=0; i<ITEM_NUM; i++)
    printf("[item %2d] value: %2d, weight: %2d\n", i, values[i], weights[i]);

  printf("limit of weight is %2d\n", limit);

  return 0;
}

int randoms(int *dst, int mini, int maxi, int n)
{
  int i;

  for (i=0; i<n; i++)
    dst[i] = mini + (int)(rand() * (maxi - mini + 1.0) / (1.0 + RAND_MAX));

  return 0;
}
