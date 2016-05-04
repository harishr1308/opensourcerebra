#include <fstream>
#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <dirent.h>
using namespace std;
int l=0;
#define a textfile[l]  
#define b textfile[l+1]
#define c textfile[l+2]
#define d textfile[l+3]
#define e textfile[l+4]

int length;

vector<string> open(string path = ".") 
{
 DIR*    dir;
 dirent* pdir;
 vector<string> files;
 dir = opendir(path.c_str());
 while (pdir = readdir(dir))
  {
    string fn = pdir->d_name;
    if(fn.substr(fn.find_last_of(".") + 1) == "txt" && fn[0]=='w')
      files.push_back(fn);
  }
 return files;
}

int main() 
{
 vector<string> files;
 files = open(); // or pass which dir to open
 fstream file;
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
    length=0;
    file.seekg (0, file.end);
    length = file.tellg();
    file.seekg (0, file.beg);
    char * buffer = new char [length];
    //cout << "Reading " << length << " characters... ";
    // read data as a block:
    file.read (buffer,length);
    string textfile(buffer);
    //cout<<textfile<<endl;
    string tname;
    string line;
    fstream tfile;
    tfile.open("temp4.txt",fstream::in|fstream::out|fstream::trunc);
    vector<string> lines;
    int nooflines=0;
    for(;l<length;l++)
    {
      if(a=='\n')
      {
        lines.push_back(line);nooflines++;
        line="";
      }
      else 
      {
       line+=textfile[l];
      }
    }
    sort(lines.begin(),lines.end());
    for(int q=0;q<nooflines;)
    { 
      int counting=0;
      string newline = lines[q];
      while(newline.compare(lines[q]) == 0 && q<nooflines)
      {
        counting++;
        //lines.erase(lines.begin()+q+1);
        cout<<"encountered duplicate line : "<<lines[q]<<endl;
        q++;
      }
      
      char buffer[50];
      snprintf(buffer, sizeof(buffer), "%d", counting);
      string str(buffer);
      newline+="$$"+str;
      tfile<<newline;
      cout<<"line modified "<<newline<<endl;
      if (q>=nooflines)
        break;
    }
    tfile.close();
    temp.insert(temp.find_last_of(".")-1,"count");
    if(rename("temp4.txt",temp.c_str()))
      cout<<"File is renamed as : "<<tname<<endl;
    else
      {
        perror( "Error renaming file" );
      }
    delete[] buffer;
    cout<<endl;
    textfile="";
    }
    else
    {
      cout<<"End of file reached for some reason"<<endl;
    }
    file.close();
  }
  remove("temp4.txt");
  return 0;
}
