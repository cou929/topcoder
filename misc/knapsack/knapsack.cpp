// knapsack.cpp

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 組み合わせを生成するための combinations という名前のクラス
// 例えば 3C2 (3つの中から2つとる組み合わせ) だと、{1, 2}, {1, 3}, {2, 3} という数字の列を生成する。
// 再帰というちょっと難しい概念を使っているので、わからなかったら無視しといてください。
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

// combinations ここまで、
// ここから下がmain

int main(void)
{
  // 各アイテムの価値と重さ
  int values[6] = {10, 13, 10, 16, 2, 3};
  int weights[6] = {3, 5, 4, 7, 2, 4};

  // 全ての組み合わせを入れるためのベクター（c++特有の配列みたいなやつ）
  vector <vector <int> > combs;

  // combinationsというクラスを使って、全ての組み合わせを作っている。
  combinations *c = new combinations;
  for (int i=1; i<=6; i++) 
    {
      vector <vector <int> > v;
      c->calc(6, i);
      v = c->get();
      combs.insert(combs.end(), v.begin(), v.end());
    }

  // ここから下では、combsに入っているそれぞれの組み合わせについて、価値と重さを計算し、その時点のベストの解だったら表示している。

  int maxi = 0; //価値の最大値を保存しておくための変数

  for (int i=0; i<combs.size(); i++) 
    {
      int value = 0;
      int weight = 0;

      // ここで袋の中のアイテムの価値と重さの合計を出している。
      for (int j=0; j<combs[i].size(); j++)
	{
	  value += values[combs[i][j]-1];
	  weight += weights[combs[i][j]-1];
	}

      // もし現在の組み合わせの重さが14以下で、かつ価値がmaxi以上だったら、
      // アイテム番号と価値を表示する。
      // coutは、c言語のprintfのようなものだと思ってください
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
