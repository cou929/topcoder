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
#include <numeric>
// BEGIN CUT HERE
#include "cout.hpp"
// END CUT HERE 
using namespace std;
class InternetSecurity {
public:
  vector <string> split(const string _s, const string del) {
    vector <string> ret;
    string s = _s;

    while (!s.empty())
      {
        size_t pos = s.find(del);
        string sub = "";
        sub = s.substr(0, pos);
        ret.push_back(sub);
        if (pos != string::npos)
          pos += del.size();
        s.erase(0, pos);
      }

    return ret;
  }

  vector <string> determineWebsite(vector <string> address, vector <string> keyword, vector <string> dangerous, int threshold) {
    int i, k;
    int n = address.size();
    vector <string> ret;
    vector <vector <string> > keywords;
    vector <bool> is_danger(n, false);
    vector <int> result_indexes;
    set <string> dangerous_set;

    for (i=0; i<n; i++)
      keywords.push_back(split(keyword[i], " "));

    for (i=0; i<dangerous.size(); i++)
      dangerous_set.insert(dangerous[i]);

    while (1) {
      bool exist = false;

      for (i=0; i<n; i++)
        if (!is_danger[i]) {
          int counter = 0;

          for (set <string>::iterator j=dangerous_set.begin(); j!=dangerous_set.end(); j++)
            if (find(keywords[i].begin(), keywords[i].end(), *j) != keywords[i].end())
              counter++;

          if (counter >= threshold) {
            exist = true;
            result_indexes.push_back(i);
            is_danger[i] = true;
            for (k=0; k<keywords[i].size(); k++)
              dangerous_set.insert(keywords[i][k]);
          }
        }

      if (!exist)
        break;
    }
    
//     vector <vector <string> > split_words;
//     vector <int> dangerous_points(n, 0);
//     vector <bool> checked(n, false);
//     vector <string> dangerous_words = dangerous;
//     vector <int> result_indexes;
    
//     for (i=0; i<n; i++)
//       split_words.push_back(split(keyword[i], " "));

//     while (dangerous_words.size() > 0) {
//       vector <string> new_words;
//       for (i=0; i<n; i++)
//         for (j=0; j<dangerous_words.size(); j++)
//           if (!checked[i] && find(split_words[i].begin(), split_words[i].end(), dangerous_words[j]) != split_words[i].end())
//             dangerous_points[i]++;

//       for (i=0; i<n; i++)
//         if (!checked[i] && dangerous_points[i] >= threshold) {
//           result_indexes.push_back(i);
//           checked[i] = true;
//           for (j=0; j<split_words[i].size(); j++)
//             if (find(dangerous_words.begin(), dangerous_words.end(), split_words[i][j]) == dangerous_words.end())
//               new_words.push_back(split_words[i][j]);
//         }

//       dangerous_words.clear();
//       dangerous_words = new_words;
//     }

//     cout << split_words << endl;
//     cout << dangerous_points << endl;

    sort(result_indexes.begin(), result_indexes.end());
    for (i=0; i<result_indexes.size(); i++)
      ret.push_back(address[result_indexes[i]]);

    return ret;
  }
   
  // BEGIN CUT HERE
public:
	void run_test(int Case) { 
    if ((Case == -1) || (Case == 0)) test_case_0();
    if ((Case == -1) || (Case == 1)) test_case_1();
    if ((Case == -1) || (Case == 2)) test_case_2();
    if ((Case == -1) || (Case == 3)) test_case_3();
    if ((Case == -1) || (Case == 4)) test_case_4();
    if ((Case == -1) || (Case == 5)) test_case_5();
  }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { 
    string Arr0[] = {"www.topcoder.com",
                     "www.sindicate_of_evil.com",
                     "www.happy_citizens.com"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    string Arr1[] = {"hack encryption decryption internet algorithm",
                     "signal interference evil snake poison algorithm",
                     "flower baloon topcoder blue sky sea"}; 
    vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    string Arr2[] = {"hack","encryption","decryption","interference","signal","internet"}; 
    vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
    int Arg3 = 3; 
    string Arr4[] = {"www.topcoder.com", "www.sindicate_of_evil.com" }; 
    vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); 
    verify_case(0, Arg4, determineWebsite(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { 
    string Arr0[] = {"brokenlink","flowerpower.net","purchasedomain.com"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    string Arr1[] = {"broken","rose tulips","cheap free domain biggest greatest"}; 
    vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    string Arr2[] = {"biggest","enemy","hideout"}; 
    vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
    int Arg3 = 2; 
    string Arr4[] = { }; 
    vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); 
    verify_case(1, Arg4, determineWebsite(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { 
    string Arr0[] = {"a..a.ab.","...aa.b"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    string Arr1[] = {"a bc def","def ghij klmno"}; 
    vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    string Arr2[] = {"a","b","c","d","e"}; 
    vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
    int Arg3 = 1; 
    string Arr4[] = {"a..a.ab.", "...aa.b" }; 
    vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); 
    verify_case(2, Arg4, determineWebsite(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { 
    string Arr0[] = {"www.tsa.gov"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    string Arr1[] = {"information assurance signal intelligence research"}; 
    vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    string Arr2[] = {"signal","assurance","penguin"}; 
    vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
    int Arg3 = 2; 
    string Arr4[] = {"www.tsa.gov" }; 
    vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); 
    verify_case(3, Arg4, determineWebsite(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { 
    string Arr0[] = {"www.topcoder.com",
                     "www.sindicate_of_evil.com",
                     "www.happy_citizens.com"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    string Arr1[] = {"hack encryption decryption internet algorithm",
                     "signal interference evil snake poison algorithm",
                     "flower baloon topcoder blue sky sea"}; 
    vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    string Arr2[] = {"hack","encryption","decryption","interference","signal","internet"}; 
    vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
    int Arg3 = 3; 
    string Arr4[] = {"www.topcoder.com", "www.sindicate_of_evil.com" }; 
    vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); 
    verify_case(4, Arg4, determineWebsite(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { 
    string Arr0[] = {"crpvclcvrmqj.lohiu_tguslsypperijpqucgkl._vttp", "d", "pg_oiwjsppylafhwbalx", "tia_gxjckjueqe._fyladhry", "iuyrskfrcd_aqvrfzrkisxu.nuddoloowdmthv", "evdnursnvjsmavbnlcx", "bsszbvcolav_lrytyelwwkyisfmxzncu", "loueb_ult_aaggdzugmez_fz._xmz_oevhrzsjlm.r.cm", "hims_lmakmeqlizbzzffccaulctznmlnyxk.hxab", "fdoq.thvdjqjfsxujinju_wdtjyeacdbkprg", "v", "wj.beeoisvx.nr", "ysbr", "g.uszfmzk_j_ivagrj_w.gsjhophdhzwbrld_aoswl", "b_omm.orvcihagng_ikhlfjaa.v", "i_yx_diydnzirppa", "ob.qttgaowbkbxjd.dwdytrpuiirjldc_k_ogek_ammw", "nkdjs", "_glhmnyvpum.qy_nfokotxxxkmnqlnowrultclscou", "had.qfece_ds_xkvtzhxy", "ar_crifcwbyqxwqos._zahbv.hpybvopreycbibgach.yg", "awdhykzhzpzuuircxdakhjeci_tgegqups.tpfesnaro", "mrdfgbgvpgep_vxtyh_xubrejilcxcfp", "kapslcmry_dyeumatxecvacsbqi", "pvwma_", "hzxmrathtqtv", "tqsntqqnh.mdwoglp.tbbjnbyizgvwy_rov.nuuukgivzi", "ae_bucbalonqc_ltgyvn_qora.cbic", "mbnfxmyfdciqelkadjlfscjrczpypuuh", "ldttb_.trh", "avcprsekuzoibhfkhqgy__s__lhuysm", "ke_sxioudbibucuvxwggyddhzgt_khvpzbvhsdeym_y_", "gaoebwj.aejhznifgacnsail", "qqvbysd_bdhqibrosexkuzjv_kkqvdadzf_nvvvnljojscfs", "ddmedlcikttoopztdcbqcbuo", "cxwmcwjqrxjcnp", "yc", "uckybo._pmcm", "jxzdtuhdr", "_hpmkuts", "p", "safkpjptlf_.sfud_wjmxyb", "uzxtpp_wyfslfyj", "k_bnzwtisjimtwnsnwaye.i.wwpjynllo", "eejdoclniybbcbdyvwpk.wk", ".uqcwvoomzg.tbjcfsqjqo", "gxzd_zmsjwfnrtyahjwbc", "vmbqnd.ptdkteuvj.pwdkpeydxn.mu", "hceahiailvukdzny.skiqewzsqwafyyypuzm_vrpxaoefxine", "zw_hcowohabqo_dwtkagepfjn.dkegdy.shhda.rib.by.jco"}; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
    string Arr1[] = {"jy sc lhu ep dqiny hu xb vw st l fb", "yq wu evi ze sc xg bs dqiny hu yv xb vw bb fb twhk", "pf yq jy ymh wu evi p fc i xg ty yv vw zk st bb qa", "ymh xg nn ko hu yv xb ezane bb fb c twqxjah jj d e", "drt ymh xg ty lhu jks st", "pf yq ymh cqolud wa lhu ep hu xb ezane utot us", "bs ko lhu ep ig dqiny xb mzi vw st l qa fb sth dux", "evi ze fc zf ko ep hu xb ezane qa db zs luu gn y h", "cqolud csi bs ep l tr ao ir r jztz nj", "jy ymh p fc bs dqiny yv vw st ezane bb utot", "pf ov ymh wu ezane y n dux kaw nj q zs jj h r ifkj", "p csi fc xg lhu hu yv xb vw ezane qa twhk", "pf aupo xg bs wa lhu xb twhk dux mrq mdy h r", "ze hrhtynxt ty yv xb st qa utot twhk", "yq fpe cqolud evi ze aupo nn ep mzi vw bb", "jy ze nn fb tr hb vz bj xctnumc oj kaw dz mdy n ir", "yq gtq jy evi xg nn ko ig hu fb jj nvk vz gn qrt", "ze aupo lhu ig hu yv mzi byph c sth", "yq ze aupo fc zf bs ko dqiny yv mzi", "evi w nn ep yv st bb utot tr luu zs oj dz us zp uv", "gtq jy ze csi fc i ty dqiny mzi l fb twhk", "ov x aupo xg ko lhu hu bb utot", "pf yq x csi ig yv xb vw qa fb zp xlvt db hrw", "gtq ze aupo xg ty lhu dqiny bb fb", "csi xg xb mzi st a zs sth", "jy bs wa zk st bb d y vos luu mdy we mrq gn", "evi fc nn ko ig hu mzi zk utot twhk", "gtq ymh evi hu yv xb vw st", "gtq jy ze aupo fc nn ko qa", "ov cqolud evi ze qnw xg bs ko yv xb vw qa", "ov jy cqolud evi ty lhu ep ig vw st ezane bb qa fb", "evi bs dqiny xb ezane", "yq jy x evi ze fc zf bs ty xb fb ao zp vos dz jj", "cqolud fc nn bs yv vw st", "jy xb vw ezane twhk", "yq ze xg ko mzi", "jy evi ko yv vw ssm c dux a luu ohuawv", "yq wu evi aupo csi fc zf ko ty dqiny hu mzi st fb", "yq fpe jy wu fc sc xg dqiny yv mzi bb utot fb", "w aupo csi ko lhu ig yv xb mzi l qa", "pf ze aupo hrhtynxt ko lhu ep yv st bb qa fb bptyc", "yq fpe w hrhtynxt qnw xg ep ig xb mzi vw bb qa", "ov gtq wu ze bs ko ig vw bb fb", "jy aupo xg ko dqiny yv twqxjah ir a hrw q we d nj", "evi bs ko ig hu mzi vos trzh hb ypm dz y dux ifkj", "pf aupo zf nn yv l qa fb xctnumc we", "yq wu cqolud nn ko qa", "gtq jy w sc ty lhu dqiny vw st twhk twqxjah", "pf cqolud fevrmewzar aupo bs bb qa ir", "yq kh fc sc bs ty ep dqiny xb vw bb fb"}; 
    vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    string Arr2[] = {"g", "pf", "yq", "ov", "tn", "s", "jy", "x", "rr", "wu", "t", "kh", "tg", "p", "oc", "ze", "w", "ru", "m", "lt", "fc", "i", "zf", "ln", "sc", "xg", "nn", "bs", "wa", "ko", "ty", "kc", "ga", "ep", "ig", "on", "hu", "yv", "xb", "ym", "vw", "zk", "st", "dh", "bb", "l", "qa", "mu", "fb", "z"}; 
    vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
    int Arg3 = 11; 
    string Arr4[] = {"crpvclcvrmqj.lohiu_tguslsypperijpqucgkl._vttp", "d", "pg_oiwjsppylafhwbalx", "tia_gxjckjueqe._fyladhry", "evdnursnvjsmavbnlcx", "bsszbvcolav_lrytyelwwkyisfmxzncu", "loueb_ult_aaggdzugmez_fz._xmz_oevhrzsjlm.r.cm", "fdoq.thvdjqjfsxujinju_wdtjyeacdbkprg", "v", "wj.beeoisvx.nr", "ysbr", "b_omm.orvcihagng_ikhlfjaa.v", "i_yx_diydnzirppa", "ob.qttgaowbkbxjd.dwdytrpuiirjldc_k_ogek_ammw", "had.qfece_ds_xkvtzhxy", "ar_crifcwbyqxwqos._zahbv.hpybvopreycbibgach.yg", "mrdfgbgvpgep_vxtyh_xubrejilcxcfp", "hzxmrathtqtv", "ldttb_.trh", "avcprsekuzoibhfkhqgy__s__lhuysm", "gaoebwj.aejhznifgacnsail", "uckybo._pmcm", "jxzdtuhdr", "_hpmkuts", "p", "safkpjptlf_.sfud_wjmxyb", "k_bnzwtisjimtwnsnwaye.i.wwpjynllo", "eejdoclniybbcbdyvwpk.wk", "vmbqnd.ptdkteuvj.pwdkpeydxn.mu", "zw_hcowohabqo_dwtkagepfjn.dkegdy.shhda.rib.by.jco"}; 
    vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); 
    verify_case(5, Arg4, determineWebsite(Arg0, Arg1, Arg2, Arg3)); }




  // END CUT HERE

};
// BEGIN CUT HERE
int main() {
InternetSecurity ___test;
___test.run_test(-1);
}
// END CUT HERE 
