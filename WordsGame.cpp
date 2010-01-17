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
class WordsGame {
public:
  int minimumSwaps(vector <string> grid, string word) {
    vector <string> candidates;
    int ret = INT_MAX;

    string sorted_word = word;
    sort(sorted_word.begin(), sorted_word.end());
    for (int i=0; i<grid.size(); i++) {
      string s1, s2, sorted_s1, sorted_s2;
      for (int j=0; j<grid.size(); j++) {
        s1 += grid[i][j];
        s2 += grid[j][i];
      }

      sorted_s1 = s1;
      sorted_s2 = s2;
      sort(sorted_s1.begin(), sorted_s1.end());
      sort(sorted_s2.begin(), sorted_s2.end());

      if (sorted_s1 == sorted_word)
        candidates.push_back(s1);
      if (sorted_s2 == sorted_word)
        candidates.push_back(s2);
    }

    for (int i=0; i<candidates.size(); i++) {
      int swap_count = 0;

      for (int j=0; j<word.size(); j++) {
        if (word[j] != candidates[i][j]) {
          int pos = 0;
          for (int k=j+1; k<word.size(); k++)
            if (candidates[i][k] == word[j])
              pos = k;
          char tmp = candidates[i][j];
          candidates[i][j] = word[j];
          candidates[i][pos] = tmp;
          swap_count++;
        }
      }

      if (candidates[i] == word)
        ret = min(ret, swap_count);
    }

    if (ret == INT_MAX)
      ret = -1;

    return ret;
  }
   
  // BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"TZNIUhIvjkCoAwYwMajKTZcRwVDklAccDwYTYRDnPlyRMzftz", "aUHYVaWwSKSEaubYDdazImUQELhBdNGTSpbMjTuxzcsnlEJuq", "tJbjwekWCAMJsfaHVUdZPMzcNifPyTHMdhCdSWbAWqnTcJIHj", "yOVMpbZHiDIfrxTucWFUupiMKJnbrnuulmmHeyXRtSveHIqoO", "minJtupHVBsDCGjLleBrwRmpnLGIxzlrZZhptITiUljxgrfjS", "SASbnBrymdBZJnldcKhnaVEwoAEIolexeEFkteASDnCWNMPNR", "WXodyFcegpDqeWFQpzDMDjPbsCcjjCyjWvDFQwSIrENRmeqFq", "FrGOvisNrWnZClXgdkxLfQslsuAlJrAHCaNRynnbTZESrgkvw", "iTasLPwBuVQdThiEWpMhsipnkTlxbYpqHTvELDiGbUaTuVFlI", "BKstAxijlnNLCuzPhZMwVmbTvagHprqfeIcdyGXUQOERSYJko", "wKrKKjbYlTMHvRcAWDDiFvbZtETIuEBbvzrOobFOoHdrCGgiI", "ffiQSwartIBVGpfdAVloGnlncIliHDWDhSYnigPtllbGGsXLU", "XRGGjkfqkGJOCVCbnqUSEXkwaKRaHVJZPnRsULlZeAkOOflxM", "CZpeeqtfvZLgsIpkLZmklHjuAsoiBBvvkBRDthVDSIMULwtix", "pEMXqRYaLmzwZzqqCGmGvSJfPAsfnjqfTASLYoWPYzWIMXsRP", "GteiugQxPEoHMYHZXoTNqcfFQVKaRtKpLrVqTifFxaZaGTROq", "kzNBZmVIJexgjiWxLMdlrKhjxGQdzOoKpxpMSjhUuSqkHZosK", "KIDpGxTGcMgFmSwNtBTvrBnzOxYcWhjmxkBiVJyYhsKlXvPwo", "YYcwITniBinSYZIjMruwYhKeIPnIUiNPNdqIFuYlXbipbRGNS", "dyBPPKFhnOvfjgJgjgZyFzOIywNWGFnSmeVuFmzMCzzqGDjsA", "DdiuMNjjRxfcDQkCrCXWKbIbtGXHYJTgIyvFzVZHBickmpoQU", "zYnSrZMwWvNIvXguEbfxRNLoouXTjZrXrMSssqUwyugGMOCaJ", "qIRWiLuqsorOpKBkeLqQhEtnYMGOkHtNYlnPgMBQOLTghAsFm", "oRlHTDRdKuPHCLKdTAzdqfQnHFcajeOJuVuvBEtLIrVbpKPro", "xZkEWJKlhfgZDaEfLNnFiIHOwIViHKhstYqlbdRCVshulaghy", "sZWmmfoYAyPAVJOjxEpTtYgYpZFTHwRiqJeedAcfwHODkclES", "AwbZDIOFQCGvWcNxBIOmjtDRKLetzxSLgWmRfzoWJgpYXxVhg", "lzUxcHNvpUplYymQrxeqKgdFUBLphQZyXOJxTrqzpPwtCUkLu", "OihoJnEKXYLxwDZUhvAYWJXzIIBqURPCoPIOGOGeqAuegkJEN", "BOtVCciNejEhZjRBcHccIPramuXIwLgwfUGxctsvdXDskmJNU", "rcsDXvCrMcXfHsVllFUfnxAKgTeUtdinOHjkjpmKQmBNfBICZ", "QqeUNCLoDReFETrPDfLCedMejdCoXqIBwfpJKcQykUUhUiQBJ", "MydrAWzaFXaeBPPtjPEgDyBRKFtKcaskUNZiSHOVLePMboSpZ", "civNBldYYSKruNvhSQOeRLeknHKxkpwVRbJShNaTgaoGbYgiz", "jqXRkUAMUwdWhdAyGSXITWVFuRsuSGVYzFceAlwgaGQxqFEfw", "PatalXlkTQQMkEDTInMbcCRrPvqgsbDGKLDQzxdkcaeobHxyE", "RymToAmwIsPgpkUgFhStaUCVdBKMgoazjsDpfBMBKNxjntyDH", "NYWtsEHIZlPBWAoWJsCPXraxsPtisUMIMjLnpsvuHFRtCqkQM", "uoXqRSPkNJrgVmeSxXvEaoYWpdRviMkAiXRMVFrjjhYTNlQqX", "IcncxGDkaqFHMeGjNjiArGoutQVzHubhBILgDPENZDIknuGfS", "UhSvzyxjoPLcfosyaywaMkTmlspCKcUWcCttNfLqnsSJCLJUY", "bFcChpJWqroITUQCITIOLqSVfVrqCsXRJgRNSYNsNJryBPruH", "hmSgQzevGgrYHvMxXwNupAxSwnYHAWmaVitQqSxXfDtERyPhd", "gWLygYgrfFFJUMulOYPXQOqmIEfVUmYtADihgGphvImRFhWfH", "HeehEtyvyHeIrBSpntsBUDvPBVvNoPCFFcgMmQCEAdHLlWojk", "nCtFfMUcxhGOZCnoQmCjWTwKXmHpzIdQaqiksCHJGAJimCtyV", "LfCnFrGMznUhsFyZjilRDeNMuGSHYfxEGoawDkepmkfjNQjWi", "ZnjkdohJbadWmOtstcsDjFuyKfOXXkFOnGuyaakoMHAeMSxnh", "eJszbOvLdLrXXthZmltVgaFVuMJVCXfobRxnZUJrsSFVIdISZ"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "gaRQHGjsdUpyTVowklBYCxqLtMNOczJXPirIEnSZevmfAbKuh"; int Arg2 = 48; verify_case(0, Arg2, minimumSwaps(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"UjcKhVsIPCdbtkeLupwmADnTZvrYWfqGaOSFXMREiQlNxJgByz", "VysGANFqKZyogqqZmjiaMsWFZSpIPJoBovrfwslcygDsXIehhX", "GMhjJzWwwMLjQZFEpqouJTnCbAuidmRatbXqAdhhwDYCUwcxqw", "JkUdUmCwayBTpRqPbpnjikTVlcJMkvmryeBtgEOXJgjzIasOid", "qZspDekJHRPrFbyNtdacfxUiMVlnhBIYuACzmvwKLEGoQSWTjO", "PENtlaKCxNxXPDgeNkZACfaCNrKHBnggGfkNEEYaytheyjynbC", "UYlLDBnTvePGRpgjAbtOkNJVZmaduwhzCiHXcMrKsQfSqEoyFW", "ZdmcxBwzsTlkiYNuOUJyRAvFKCXebjWDVqaLQPMhpHSfGEtnog", "uQgAweFaXyvqxMVzmNfblEOHdpBsGKTtCZRhUIWJoYkjnrDcSL", "PbxtzYBlfNAcXkxSvyZsVDqibeFdxETQURqHffrjNWfkwwqQAF", "fvIrmibkMsNJcAuVLwKqRYHWUQatzXZgEPloTdGODhxySCnjpB", "WEyWOxnwqVzinCJcaiqFJTEVfXLvEjVjYUFzBrAVXhWnwCSiUP", "CehclQyMYtZdokaKTNWEuxBAnmJpRrIijsOUgVzvfwXqDLGbHP", "AbyxJgtoBQrUiloQZOZuHCsOCPJwfqpzGSaoCWzRNHiDCmHDlS", "HxwEBInjGPKVNMdiJlhXLsWrApfDgCSOeqycvkZuoztYQRbUam", "HVPGJUFCOXYsaugILnytrEbTxpAiKmMDWkwdQjohcvflNRqSZB", "TdyJoBblKeWVGgZnKroguymJGTJfDbQnWYWdFVxEBKwXAdXLAE", "JfAYFhxGjafhdAxUJVbJwRdqjTmneIXaqgVZTnsnufsqeYjJqA", "ihGUmzbNopLstgdlXAqanxDcuBfeOYTFjKQVyEISkCrHPJvMZR", "MWnsqryCyTvMtJwfPrKoIKgerogRvdIiXjjAVbdSGFoeQLsqXR", "lmKEEVngxjoLbyLwMlKtAVfrbWCYYYpWaqKTjCugUvkyVSOBpe", "nIiBRuhSQzmbfJnovdiJzSReZmXSkPFFXFKTbMmbslrsCwqHNI", "gFnABEfAdYJSSyYVaLJrOxzuvpkmQamFMqSSOHEeGRlMOyZydz", "IKJpoxUEQHTaOjMYcvmniLZydfWNqDCBPrkegbzsRXVGhFSAlw", "raUMuFldHfAoLRzwmZqXtsWbyYPjeExNBpOgkTSiCVvnQJGIhc", "PSwNTPNkyVJOXOAXwnRsFsTJTgWePgecDozzUYBqRgUGXzySyQ", "GDUqPGKvPZJIpZqgnNyEKxYIOkuumSTcivBEkcufoTJPbAyDdP", "jRYGPlCfyYbrrYWyxbOLEkmOPBVenttaAveRndsnoehdYgIwxi", "DuoIXJhKvRLGYNEkjQgCAnMZlBOSxrtVWUmaiwfzeHdPbFcqyp", "DnsmHNRLeFrGPVfiAJUZOopdTWbazxKljEyQvBtCgwIMucYSqX", "fkdcLtTklKUHEgxEQxQMFoDYBMwOUjOhLnGCeKbsvSzMsXTOLw", "VtjQPrGezLmgHsODEfXnlURpJAYivkNcxduTqKCaSyFoWMbhwI", "UOHDMVAasfBsXbfRAtQRKltTZIpfocuIDPPlPbeuvFGaVjgqeC", "jLHoThVeqKGQdXuRtAzYNWPOUDvwspxnIJcfkFmZigMrBlSabE", "dVOovYuNCnUjEyJZKmMzfhawkxBRispgWqbHFQPlItATXSDLGr", "qhyBCeKIroXZcraVsMykykTeFoskgLOrusJyJPSloNZARubwHz", "MhcvkbHuvaiYFLtYjiUrRpPBcyDQqYAGHTnYOJLSPZidRCBHGL", "WGVGfGgtgiLIodTuifzztwhoyXmTyRenGfalMYnkgQEfWqXYmF", "XtiJDiDJYGmLqjratHEnKnACkNKVerbBcRByISBxwCrIhqQuqI", "cUJVOSWQpLsFymahwTAPuMblkBItqEjzDovegRZGYrnHXNKxfC", "yJLvYmwOVhGZgeCcoKIFbpPDsWUNTSdzxQauHnrjBMqXAERitk", "WJzgXikUuTmRfyvOPrdAlEVnZDYFBwHQhxoMCNtjqbLaepKscG", "KJEtoNGBlUACxiQYSIFZmfTDbrpLhsvzMXeVWPcnauqgydRHjw", "JDjlKQyZPjYglkmjSsZjfWTFcFBDPGRUBdlARIQuWSGBrVOgVf", "yKjHfwAbvoUChMYeViqczOELRnQDTalkIuXGJBsrmxpNtgPWFZ", "SBnIgUhkyeeoptPwVLGzztyohxnzwssaYYlpJWLPurWjJZvruD", "slIWqZvyuzKypZTLzjwysnmQdELCqWeniAXmAqPMRTSzJagECp", "UQtMoRlKGbIryVfDFimaWBsLdPeCgAhcJjSxnvXzYZpHTqkENw", "XhKfaAJUQIoZbkesRLuCpSMHWtEiBgryqmcPznxVYwOvdNDjFG", "IqSHJBrERVThuyNsWkoUjGbYwZACDiaPOgflLFnmQctvdMzeKx"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "ZoSGdDCFEWTVxkiulYHOmgzNwqABQXJbaLspvIUjhtenrMRycf"; int Arg2 = -1; verify_case(1, Arg2, minimumSwaps(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"cdf",
                                        "bca",
                                        "agf"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "abc"; int Arg2 = 1; verify_case(2, Arg2, minimumSwaps(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"xSZB",
                                        "gbHk",
                                        "kbgH",
                                        "WFSg"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "bkHg"; int Arg2 = 2; verify_case(3, Arg2, minimumSwaps(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"eKUNGHktLB",
                                        "EtBFDndTlG",
                                        "RRFHmjwrDs",
                                        "eKYsHlYhlu",
                                        "ljxyJSwTds",
                                        "dUQToyWHvl",
                                        "azDPWRwioE",
                                        "EARdktoDBh",
                                        "dmIqcGSvCE",
                                        "wXypNQEMxz"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "oDmWcJHGNk"; int Arg2 = 6; verify_case(4, Arg2, minimumSwaps(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"ab",
                                        "bA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "aB"; int Arg2 = -1; verify_case(5, Arg2, minimumSwaps(Arg0, Arg1)); }

  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
WordsGame ___test;
___test.run_test(-1);
}
// END CUT HERE 
