// BEGIN CUT HERE
// END CUT HERE
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
using namespace std;
class TheContest {
public:
  vector <string> getSchedule(int N, int M) {
    vector <string> ret;

    return ret;
  }
  // BEGIN CUT HERE
#include <ctime>
  double start_time; string timer()
  { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
  template<typename T> ostream& operator<<(ostream& os, const vector<T>& v)
  { os << "{ ";
    for(typename vector<T>::const_iterator it=v.begin(); it!=v.end(); ++it)
      os << '\"' << *it << '\"' << (it+1==v.end() ? "" : ", "); os << " }"; return os; }
  void verify_case(const vector <string>& Expected, const vector <string>& Received) {
    bool ok = (Expected == Received);
    if(ok) cerr << "PASSED" << timer() << endl;  else { cerr << "FAILED" << timer() << endl;
      cerr << "\to: " << Expected << endl << "\tx: " << Received << endl; } }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, TheContest().getSchedule(N, M));}
  int main(){

    CASE(0)
      int N = 3; 
    int M = 3; 
    string __[] = {"123", "231", "312" };
	  vector <string> _(__, __+sizeof(__)/sizeof(*__)); 
    END
      CASE(1)
      int N = 4; 
    int M = 4; 
    string __[] = {"1234", "2143", "3412", "4321" };
	  vector <string> _(__, __+sizeof(__)/sizeof(*__)); 
    END
      CASE(2)
      int N = 4; 
    int M = 6; 
    string __[] = {"123456", "214365", "345612", "436521" };
	  vector <string> _(__, __+sizeof(__)/sizeof(*__)); 
    END
      CASE(3)
      int N = 5; 
    int M = 3; 
    string __[] = {"123", "214", "345", "451", "532" };
	  vector <string> _(__, __+sizeof(__)/sizeof(*__)); 
    END
      CASE(4)
      int N = 28; 
    int M = 40; 
    string __[] = {"123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcde", "21436587A9CBEDGFIHKJMLONQPSRUTWVYXaZcbed", "34127856BC9AFGDEJKHINOLMRSPQVWTUZaXYdebc", "43218765CBA9GFEDKJIHONMLSRQPWVUTaZYXedcb", "56781234DEFG9ABCLMNOHIJKTUVWPQRSbcdeXYZa", "65872143EDGFA9CBMLONIHKJUTWVQPSRcbedYXaZ", "78563412FGDEBC9ANOLMJKHIVWTURSPQdebcZaXY", "87654321GFEDCBA9ONMLKJIHWVUTSRQPedcbaZYX", "9ABCDEFG12345678PQRSTUVWXYZabcdeHIJKLMNO", "A9CBEDGF21436587QPSRUTWVYXaZcbedIHKJMLON", "BC9AFGDE34127856RSPQVWTUZaXYdebcJKHINOLM", "CBA9GFED43218765SRQPWVUTaZYXedcbKJIHONML", "DEFG9ABC56781234TUVWPQRSbcdeXYZaLMNOHIJK", "EDGFA9CB65872143UTWVQPSRcbedYXaZMLONIHKJ", "FGDEBC9A78563412VWTURSPQdebcZaXYNOLMJKHI", "GFEDCBA987654321WVUTSRQPedcbaZYXONMLKJIH", "HIJKLMNOPQRSTUVWXYZabcde123456789ABCDEFG", "IHKJMLONQPSRUTWVYXaZcbed21436587A9CBEDGF", "JKHINOLMRSPQVWTUZaXYdebc34127856BC9AFGDE", "KJIHONMLSRQPWVUTaZYXedcb43218765CBA9GFED", "LMNOHIJKTUVWPQRSbcdeXYZa56781234DEFG9ABC", "MLONIHKJUTWVQPSRcbedYXaZ65872143EDGFA9CB", "NOLMJKHIVWTURSPQdebcZaXY78563412FGDEBC9A", "ONMLKJIHWVUTSRQPedcbaZYX87654321GFEDCBA9", "PQRSTUVWXYZabcde9ABCDEFGHIJKLMNO12345678", "QPSRUTWVYXaZcbedA9CBEDGFIHKJMLON21436587", "RSPQVWTUZaXYdebcBC9AFGDEJKHINOLM34127856", "SRQPWVUTaZYXedcbCBA9GFEDKJIHONML43218765" };
	  vector <string> _(__, __+sizeof(__)/sizeof(*__)); 
    END

      }
  // END CUT HERE
};
// BEGIN CUT HERE
int main() {
TheContest ___test;
___test.run_test(-1);
}
// END CUT HERE 
