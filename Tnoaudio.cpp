#include <fstream>
#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <dirent.h>
using namespace std;
int l=0;
#define a textfile[l]  //<  <
#define b textfile[l+1]//p  /
#define c textfile[l+2]//>  p
#define d textfile[l+3]//   > 
#define e textfile[l+4]

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
 fstream tcfile;
 tfile.open("temp2.txt",fstream::in|fstream::out|fstream::trunc);
 tcfile.open("tnomissingaudiolist.txt",fstream::in|fstream::out|fstream::trunc);
 for(int p=0;p<files.size();p++)
 {
  string temp = files[p];
  file.open(temp.c_str(),fstream::in|fstream::out);
  cout<<temp<<" is open"<<endl;
  cout<<file.good()<<endl;
  if (file.good())
   { 
    //cout<<"if file"<<endl;
    // get length of file:
    l=0;
    file.seekg (0, file.end);
    int length = file.tellg();
    file.seekg (0, file.beg);
    char * buffer = new char [length];
    //cout << "Reading " << length << " characters... ";
    // read data as a block:
    file.read (buffer,length);
    string textfile(buffer);
    cout<<"printing textfile"<<endl;
    //cout<<textfile<<endl;
    int check = 0;
    for(;l<textfile.size()-5;l++)
     {
      if(a=='\'' && b=='h' && c=='t' && d=='t' && e=='p')
      {
      	l++;
      	check=1;
      	while(a!='\'')
      	{
      		tfile<<a;l++;
      	}
      	tfile<<"\n";
      	break;
      }
     }
      delete[] buffer;
      cout<<endl;
     }
    else
      cout<<"End of file reached for some reason"<<endl;
    file.close();
    if (check==0)
       tcfile<<"Audio file link is missing : " << temp << endl;
  }
  tcfile.close();
  tfile.close();
  if(rename("temp2.txt","tnoaudiolist.txt"))
     cout<<"File is renamed as : tnoaudiolist"<<endl;
  else
     perror( "Error renaming file" );
  remove("temp2.txt");
  return 0;
}
