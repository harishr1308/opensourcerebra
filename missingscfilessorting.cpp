#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cstdlib>
using namespace std;
int l=0;
#define a textfile[l]  
#define b textfile[l+1]
#define c textfile[l+2]
#define d textfile[l+3]
#define e textfile[l+4]

int length;

bool myfunction (string i, string j) {
  return (i==j);
}

vector<string> readingfile(fstream &temp, int &nooflines)
{
  vector<string> lines;
  if (temp.good())
   {
     l=0;
     length=0;
     temp.seekg (0, temp.end);
     length = temp.tellg();
     temp.seekg (0, temp.beg);
     char * buffer = new char [length];
     //cout << "Reading " << length << " characters... ";
     // read data as a block:
     temp.read (buffer,length);
     string textfile(buffer);
     //cout<<textfile<<endl;
     string line;
     nooflines=0;
     for(;l<length;l++)
      {
       if(a=='\n'  && l<length-1)
       {
         lines.push_back(line);nooflines++;
         line="";
       }
       else if(l==length-1)
       {
         lines.push_back(line);nooflines++;
         line="";
       }
       else 
       {
       line+=textfile[l];
       }
      }
     delete[] buffer;
     cout<<endl;
     textfile="";
    }
    else
    {
      cout<<"End of file reached for some reason"<<endl;
    }
  return lines;
}

vector<string> sortingfiles(vector<string> v)
{
  vector<string>::iterator it;
  vector<string> myvector (v.size());
  it=unique_copy (v.begin(),v.end(),myvector.begin());   
  sort (myvector.begin(),it);                         
  it=unique_copy (myvector.begin(), it, myvector.begin(), myfunction);
  myvector.resize( distance(myvector.begin(),it) );
  sort(myvector.begin(),myvector.end());
  return myvector;
}

void writingfiles(string name,vector<string> &v, int &nooflines)
{
 fstream temp;
 temp.open("temp4.txt",fstream::in|fstream::out|fstream::trunc);
 for(int q=0;q<nooflines;q++)
      temp<<v[q]<<endl;
  temp.close();
  remove(name.c_str());
  if(rename("temp4.txt",name.c_str()));
  else
    perror( "Error renaming file" );
  remove("temp4.txt");
}

int main() 
{
 fstream tfile3;

 string filename3="missingtnoserrorfilelist.txt";
 
 tfile3.open(filename3.c_str(),fstream::in|fstream::out);

 int nooffile3list=0;

 vector<string> scfilelist;

 scfilelist=readingfile(tfile3,nooffile3list);

 scfilelist=sortingfiles(scfilelist);

 writingfiles(filename3,scfilelist,nooffile3list);
 
  return 0;
}
