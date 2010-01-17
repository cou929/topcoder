#include <string>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

class Twain {
public:
  string getNewSpelling(int year, string phrase) {
    string ret = "";
    int i;

    ret = phrase;

    for(i=1; i<=year; i++)
      ret = convert(i, ret);

    return ret;
  }

  string convert(int year, string phrase)
  {
    string ret;
    switch(year)
      {
      case 1:
	ret = year1(phrase);
	break;
      case 2:
	ret = year2(phrase);
	break;
      case 3:
	ret = year3(phrase);
	break;
      case 4:
	ret = year4(phrase);
	break;
      case 5:
	ret = year5(phrase);
	break;
      case 6:
	ret = year6(phrase);
	break;
      case 7:
	ret = year7(phrase);
	break;
      }
    return ret;
  }

  string year1(string phrase)
  {
    string ret;
    int i;

    for(i=0; i<phrase.size(); i++)
      {
	if(phrase[i] == 'x')
	  if(i == 0 || phrase[i-1] == ' ')
	    {
	      ret.push_back('z');
	      continue;
	    }
	  else
	    {
	      ret.push_back('k');
	      ret.push_back('s');
	      continue;
	    }

	ret.push_back(phrase[i]);
      }

    return ret;
  }

  string year2(string phrase)
  {
    string ret;
    int i;

    for(i=0; i<phrase.size(); i++)
      {
	if(phrase[i] == 'y')
	  {
	    ret.push_back('i');
	    continue;
	  }

	ret.push_back(phrase[i]);
      }
 
    return ret;
  }

  string year3(string phrase)
  {
    string ret;
    int i;

    for(i=0; i<phrase.size(); i++)
      {
	if(phrase[i] == 'c')
	  if(phrase[i+1] == 'e' || phrase[i+1] == 'i')
	    {
	      ret.push_back('s');
	      continue;
	    }

	ret.push_back(phrase[i]);
      }

    return ret;
  }

  string year4(string phrase)
  {
    string ret;
    int i;
    int offset;

    for(i=0; i<phrase.size(); i++)
      {
	if(phrase[i] == 'c')
	  {
	    offset = 1;
	    while(phrase[i+offset] == 'c')
	      offset++;
	    if(phrase[i+offset] == 'k')
	      continue;
	  }

	ret.push_back(phrase[i]);
      }

    return ret;
  }

  string year5(string phrase)
  {
    string ret;
    int i;

    for(i=0; i<phrase.size(); i++)
      {
	if(i==0 || phrase[i-1] == ' ')
	  if(phrase[i] == 's' && phrase[i+1] == 'c' && phrase[i+2] == 'h')
	    {
	      ret.push_back('s');
	      ret.push_back('k');
	      i += 2;
	      continue;
	    }

	if(phrase[i] == 'c')
	  if(i+2 <= phrase.size() && phrase[i+1] == 'h')
	    {
	      if(phrase[i+2] == 'r')
		{
		  ret.push_back('k');
		  i++;
		  continue;
		}
	    }
	  else if(i == phrase.size() || phrase[i+1] != 'h')
	    {
	      ret.push_back('k');
	      continue;
	    }

	ret.push_back(phrase[i]);
      }

    return ret;
  }

  string year6(string phrase)
  {
    string ret;
    int i;

    for(i=0; i<phrase.size(); i++)
      {
	if(i==0 || phrase[i-1] == ' ')
	  if(phrase[i] == 'k' && phrase[i+1] == 'n')
	    {
	      ret.push_back('n');
	      i++;
	      continue;
	    }

	ret.push_back(phrase[i]);
      }

    return ret;
  }

  string year7(string phrase)
  {
    string ret;
    int i;
    int offset;

    for(i=0; i<phrase.size(); i++)
      {
	if(phrase[i] == phrase[i+1])
	  if(phrase[i] != 'a' && phrase[i] != 'i' && phrase[i] != 'u' && phrase[i] != 'e' && phrase[i] != 'o')
	    {
	      offset = 2;
	      while(phrase[i] != phrase[i+offset])
		offset++;
	      ret.push_back(phrase[i]);
	      i += offset;
	      continue;
	    }

	ret.push_back(phrase[i]);
      }

    return ret;
  }

};
