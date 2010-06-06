#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
template <class T> inline string itos(T n) {return (n)<0?"-"+itos(-(n)):(n)<10?(string)("")+(char)('0'+(n)):itos((n)/10)+itos((n)%10);}

int case_number;
#define printg case_number++, printf("Case #%d: ",case_number), printf
#define gout case_number++, printf("Case #%d: ",case_number), cout

string board[60];

void main2(void){
	int N,K,player,i,j,k,l;
	int dx[]={1,1,0,-1},dy[]={0,1,1,1};
	
	scanf("%d%d",&N,&K);
	REP(i,N){
		string tmp,tmp2;
		cin >> tmp;
		REP(j,N) if(tmp[j] == '.') tmp2 += tmp[j];
		REP(j,N) if(tmp[j] != '.') tmp2 += tmp[j];
		board[i] = tmp2;
	}
	
	int mask = 0;
	REP(player,2){
		char ch = ((player == 0) ? 'R' : 'B');
		REP(i,N) REP(j,N) REP(k,4){
			bool bad = false;
			REP(l,K){
				int x = i + dx[k] * l, y = j + dy[k] * l;
				if(x < 0 || x >= N || y < 0 || y >= N || board[x][y] != ch) {bad = true; break;}
			}
			if(!bad) mask |= (1<<player);
		}
	}
	
	if(mask == 0) gout << "Neither" << endl;
	if(mask == 3) gout << "Both" << endl;
	if(mask == 1) gout << "Red" << endl;
	if(mask == 2) gout << "Blue" << endl;
}

int main(void){
	int number_of_test_cases,i;
	scanf("%d",&number_of_test_cases);
	REP(i,number_of_test_cases) main2();
	return 0;
}
