#include <fstream>
#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
#include <dirent.h>
#include <cstdlib>
using namespace std;

vector<string> open(string path = ".") 
{
 DIR*    dir;
 dirent* pdir;
 vector<string> files;
 dir = opendir(path.c_str());
 while (pdir = readdir(dir))
  {
    string fn = pdir->d_name;
    if(fn.substr(fn.find_last_of(".") + 1) == "txt" && fn[0]=='T')
      files.push_back(fn);
  }
 return files;
}

int main() 
{
 vector<string> files;
 files = open(); // or pass which dir to open
 fstream file;
 fstream tfile;
 tfile.open("tnolist.txt",fstream::in|fstream::out|fstream::trunc);
 for(int p=0;p<files.size();p++)
 {
  string temp = files[p];
  //T1234567890
  for(int i=0;i<11;i++)
  	{
  		tfile<<temp[i];
  	}
  	tfile<<endl;
  cout<<file.good()<<endl;
 }
 tfile.close();
 //system("g++ tnolistsort.cpp && ./a.out");
 //system("g++ tag.cpp && ./a.out");
return 0;
}