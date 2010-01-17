// knapsack.cpp

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class combinations {
private:
  vector <vector <int> > result;
  int n;
  int m;
public:
  combinations(){};
  int calc(int _n, int _m);
  void r(int l, int r, vector <int> &v);
  int print();
  vector <vector <int> > get();
};

void combinations::r(int l, int r, vector <int> &v)
{
  for (int i=l; i<=r; i++)
    {
      v.push_back(i);

      if (r == n)
	result.push_back(v);
      else
	this->r(i+1, r+1, v);

      v.pop_back();
    }
}

int combinations::calc(int _n, int _m)
{
  n = _n;
  m = _m;
  vector <int> tmp;
  r(1, n-m+1, tmp);

  return 0;
}

vector <vector <int> > combinations::get()
{
  return result;
}



int main(void)
{
  int values[6] = {10, 13, 10, 16, 2, 3};
  int weights[6] = {3, 5, 4, 7, 2, 4};

  vector <vector <int> > combs;

  combinations *c = new combinations;
  for (int i=1; i<=6; i++) 
    {
      vector <vector <int> > v;
      c->calc(6, i);
      v = c->get();
      combs.insert(combs.end(), v.begin(), v.end());
    }


  int maxi = 0;

  for (int i=0; i<combs.size(); i++) 
    {
      int value = 0;
      int weight = 0;

      for (int j=0; j<combs[i].size(); j++)
	{
	  value += values[combs[i][j]-1];
	  weight += weights[combs[i][j]-1];
	}

      if (weight <= 14 && value > maxi)
	{
	  maxi = value;
	  cout << "items: ";
	  for (int j=0; j<combs[i].size(); j++)
	    cout << combs[i][j] << " ";
	  cout << "\n" << "value: " << maxi << "\n";
	}
    }

  return 0;
}
