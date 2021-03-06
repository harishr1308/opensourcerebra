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
    if(fn.substr(fn.find_last_of(".") + 1) == "txt" && fn[0]=='f')
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
 fstream tcfile;
 tfile.open("tnofcorrectfilelist.txt",fstream::in|fstream::out|fstream::trunc);
 tcfile.open("tnoferrorfilelist.txt",fstream::in|fstream::out|fstream::trunc); 
 for(int p=0;p<files.size();p++)
 {
  string temp = files[p];
  cout<<temp<<" is open"<<endl;
//fileT1234567890c or fileT1234567890e
  if(temp[15]=='c')
  {
  	for(int i=4;i<15;i++)
  	{
  		tfile<<temp[i];
  	}
  	tfile<<endl;
  }
  else if(temp[15]=='e')
  {
  	for(int i=4;i<15;i++)
  	{
  		tcfile<<temp[i];
  	}
  	tcfile<<endl;
  }
  cout<<file.good()<<endl;
 }
 tfile.close();
// system("g++ tnofcfilelistsort.cpp && ./a.out");
// system("g++ tnofefilelistsort.cpp && ./a.out");
return 0;
}