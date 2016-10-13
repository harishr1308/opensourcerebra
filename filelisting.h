#include <fstream>
#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
#include <dirent.h>
#include <cstdlib>
using namespace std;

bool conditionchecking(string f1, string f2)
{
	int check=0;
	for(int i=0;i<f2.length();i++)
	{
		if (f2[i]==f1[i])
			continue;
		else if(f2[i]=='$')
			continue;
		else if(f2[i]!=f1[i])
			{
				check=1;
				break;
			}
	}
	if (check==0) return true;
	else return false;
}

vector<string> open(string f2,string path = ".") 
{
 DIR*    dir;
 dirent* pdir;
 vector<string> files;
 dir = opendir(path.c_str());
 while (pdir = readdir(dir))
  {
    string fn = pdir->d_name;
    if(fn.substr(fn.find_last_of(".") + 1) == "txt" && conditionchecking(fn,f2))
      files.push_back(fn);
  }
 return files;
}

string GetTnoFromString(string tno)
{
	string temp;
	for(int i=0;i<tno.length();i++)
	{
		if(tno[i]=='T')
		{
			for(int j=0;j<11;j++,i++)
			{
				temp+=tno[i];
			}
			break;
		}
	}
	return temp;
}

void filelist(string filename,string filecheck)
{
 vector<string> files;
 files = open(filecheck); // or pass which dir to open
 fstream file;
 fstream tfile;
 tfile.open(filename.c_str(),fstream::in|fstream::out|fstream::trunc);
 for(int p=0;p<files.size();p++)
 {
  string temp = files[p];
  //T1234567890
  cout<<temp<<"\t"<<endl;
  // for(int i=0;i<temp.length()-4;i++)
  //   {
  //     tfile<<temp[i];
  //   }
  tfile<<GetTnoFromString(temp);
  tfile<<endl;
  //cout<<file.good()<<endl;
 }
 tfile.close();
}