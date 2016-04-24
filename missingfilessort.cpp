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
       if(a=='\n' && l<length-1)
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
 fstream tfile;
 fstream tfile1;
 fstream tfile2;
 fstream tfile3;
 fstream tfile4;

 string filename="missingtnolist.txt";
 string filename1="missingtnofcorrectfilelist.txt";
 string filename2="missingtnoferrorfilelist.txt";
 string filename3="missingtnoserrorfilelist.txt";
 string filename4="missingtnoscorrectfilelist.txt";
 
 tfile.open(filename.c_str(),fstream::in|fstream::out);
 tfile1.open(filename1.c_str(),fstream::in|fstream::out);
 tfile2.open(filename2.c_str(),fstream::in|fstream::out);
 tfile3.open(filename3.c_str(),fstream::in|fstream::out);
 tfile4.open(filename4.c_str(),fstream::in|fstream::out);

 int nooffilelist=0;
 int nooffile1list=0;
 int nooffile2list=0;
 int nooffile3list=0;
 int nooffile4list=0;

 vector<string> filelist;
 vector<string> fcfilelist;
 vector<string> fefilelist;
 vector<string> scfilelist;
 vector<string> sefilelist;

 filelist=readingfile(tfile,nooffilelist);
 fcfilelist=readingfile(tfile1,nooffile1list);
 fefilelist=readingfile(tfile2,nooffile2list);
 scfilelist=readingfile(tfile3,nooffile3list);
 sefilelist=readingfile(tfile4,nooffile4list);

 filelist=sortingfiles(filelist);
 fcfilelist=sortingfiles(fcfilelist);
 fefilelist=sortingfiles(fefilelist);
 scfilelist=sortingfiles(scfilelist);
 sefilelist=sortingfiles(sefilelist);

 writingfiles(filename,filelist,nooffilelist);
 writingfiles(filename1,fcfilelist,nooffile1list);
 writingfiles(filename2,fefilelist,nooffile2list);
 writingfiles(filename3,scfilelist,nooffile3list);
 writingfiles(filename4,sefilelist,nooffile4list);
 
// system("g++ missingfcfilessorting.cpp && ./a.out");
// system("g++ missingfefilessorting.cpp && ./a.out");
// system("g++ missingscfilessorting.cpp && ./a.out");
// system("g++ missingsefilessorting.cpp && ./a.out");
// system("g++ missingtnofilessorting.cpp && ./a.out");

  return 0;
}
