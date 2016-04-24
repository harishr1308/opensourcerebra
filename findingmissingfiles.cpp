#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <iterator>

using namespace std;
int l=0;
#define a textfile[l]  
#define b textfile[l+1]
#define c textfile[l+2]
#define d textfile[l+3]
#define e textfile[l+4]

int length;
int k;
vector<string> updatevector(fstream &tempfile,int &nooflines)
{
  vector<string> temp;
  if (tempfile.good())
   {
     l=0;
     length=0;
     tempfile.seekg (0, tempfile.end);
     length = tempfile.tellg();
     tempfile.seekg (0, tempfile.beg);
     char * buffer = new char [length];
     //cout << "Reading " << length << " characters... ";
     // read data as a block:
     tempfile.read (buffer,length);
     string textfile(buffer);
     //cout<<textfile<<endl;
     string line;
     nooflines=0;
     for(;l<length;l++)
      {
       if(a=='\n' && l<length-1)
       {
        if(l!=0)
        {
         if(b=='T')
         {
          temp.push_back(line);nooflines++;
          line=""; 
         }
         else if(b=='\n')
         {
          continue;
         }  
        }
        else
        {
          continue;
        }
       }
       else if(l==length-1)
       {
         temp.push_back(line);nooflines++;
         line="";
       }
       else 
       {
       line+=textfile[l];
       }
      }
     sort(temp.begin(),temp.end());
     tempfile.close();
     delete[] buffer;
     cout<<endl;
     textfile="";
    }
  else
    {
      cout<<"End of file"<<k<<" reached for some reason"<<endl;
    }
  k++;
  return temp;
}

void missingfile(fstream &temp,vector<string> &vtemp, vector<string> &ftemp)
{
  vector<string> v;
  vector<string>::iterator it;
  //cout<<"it has entered the function"<<endl;
  set_difference(vtemp.begin(),vtemp.end(),ftemp.begin(),ftemp.end(),inserter(v, v.begin()));
  //cout<<"set_difference works"<<endl; 
  sort(v.begin(),v.end());
  for (it=v.begin(); it!=v.end(); ++it)
  {
    temp<<*it<<endl;
  }
}

int main() 
{
 fstream file;
 fstream file1;
 fstream file2;
 fstream file3;
 fstream file4;
 file.open("tnolist.txt",fstream::in|fstream::out);
 file1.open("tnofcorrectfilelist.txt",fstream::in|fstream::out);
 file2.open("tnoferrorfilelist.txt",fstream::in|fstream::out);
 file3.open("tnoserrorfilelist.txt",fstream::in|fstream::out);
 file4.open("tnoscorrectfilelist.txt",fstream::in|fstream::out);
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
 fstream tfile;
 fstream tfile1;
 fstream tfile2;
 fstream tfile3;
 fstream tfile4;
 tfile.open("missingtnolist.txt",fstream::in|fstream::out|fstream::trunc);
 tfile1.open("missingtnofcorrectfilelist.txt",fstream::in|fstream::out|fstream::trunc);
 tfile2.open("missingtnoferrorfilelist.txt",fstream::in|fstream::out|fstream::trunc);
 tfile3.open("missingtnoserrorfilelist.txt",fstream::in|fstream::out|fstream::trunc);
 tfile4.open("missingtnoscorrectfilelist.txt",fstream::in|fstream::out|fstream::trunc);
 filelist   = updatevector(file,nooffilelist);
 cout<<"tno list vector updated"<<endl;
 fcfilelist = updatevector(file1,nooffile1list);
 cout<<"fc list vector updated"<<endl;
 fefilelist = updatevector(file2,nooffile2list);
 cout<<"fe list vector updated"<<endl; 
 scfilelist = updatevector(file3,nooffile3list);
 cout<<"sc list vector updated"<<endl;
 sefilelist = updatevector(file4,nooffile4list);
 cout<<"se list vector updated"<<endl;

 cout<<"\nMISSING FILES COMPILED !!!"<<endl<<endl;
 missingfile(tfile1,filelist,fcfilelist);
 missingfile(tfile2,filelist,fefilelist);
 missingfile(tfile3,filelist,scfilelist);
 missingfile(tfile4,filelist,sefilelist);
 cout<<"tno missing file updated"<<endl;

 missingfile(tfile,fcfilelist,filelist);
 missingfile(tfile2,fcfilelist,fefilelist);
 missingfile(tfile3,fcfilelist,scfilelist);
 missingfile(tfile4,fcfilelist,sefilelist);
 cout<<"fc missing file updated"<<endl;
 
 missingfile(tfile,fefilelist,filelist);
 missingfile(tfile1,fefilelist,fcfilelist);
 missingfile(tfile3,fefilelist,scfilelist);
 missingfile(tfile4,fefilelist,sefilelist);
 cout<<"fe missing file updated"<<endl;
 
 missingfile(tfile,scfilelist,filelist);
 missingfile(tfile1,scfilelist,fcfilelist);
 missingfile(tfile2,scfilelist,fefilelist);
 missingfile(tfile4,scfilelist,sefilelist);
 cout<<"sc missing file updated"<<endl;
 
 missingfile(tfile,sefilelist,filelist);
 missingfile(tfile1,sefilelist,fcfilelist);
 missingfile(tfile2,sefilelist,fefilelist);
 missingfile(tfile3,sefilelist,scfilelist);
 cout<<"se missing file updated"<<endl;
 
 tfile.close();
 tfile1.close();
 tfile3.close();
 tfile4.close();

// system("g++ missingfilessort.cpp && ./a.out");
 return 0;
}
