#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <utility>
#include <set>
#include <cctype>
#include <queue>
#include <stack>
#include <fstream>
#include <cstring>

using namespace std;

const int N_MAX = 1120;
bool primes[N_MAX];

bool isPrime(int n) {
  if (n < 2)
    return false;

  if (n != 2 && n % 2 == 0)
    return false;

  int s = (int)sqrt(n);

  for (int i=3; i<=s; i++)
    if (n % i == 0)
      return false;

  return true;
}

void generatePrimes(const int maxi) {
  memset(primes, true, sizeof(primes));
  primes[0] = primes[1] = false;

  for (int i=2; i*i<=maxi; i++) {
    if (isPrime(i))
      for (int j=2; j*i<maxi; j++)
        primes[i*j] = false;
  }

  return;
}

int run(const int n, const int k) {
  int i, j, l;
  int dp[n+1][k+1];
  memset(dp, 0, sizeof(dp));

  for (i=0; i<N_MAX; i++)
    if (primes[i] && i <= n) {
      dp[i][0] = 1;
      for (l=k-1; l>=0; l--)
        for (j=0; j<=n; j++)
          if (dp[j][l] != 0 && j+i <= n && !(l == 0 && j == i))
            dp[j+i][l+1] += dp[j][l];
    }

  return dp[n][k-1];
}

int main(int argc, char ** argv) {
  int n, k;
  generatePrimes(N_MAX);
 
  while (1) {
    cin >> n >> k;
    cin.ignore();

    if (n == 0 && k == 0)
      break;

    cout << run(n, k) << endl;
  }

  return 0;
}

