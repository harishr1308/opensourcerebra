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

void missingfileprocedure(string filename, string filename1, string outputfile)
{
 fstream file;
 fstream file1;
 file.open(filename.c_str(),fstream::in|fstream::out);
 file1.open(filename1.c_str(),fstream::in|fstream::out);
 int nooffilelist=0;
 int nooffilelist1=0;
 vector<string> filelist;
 vector<string> filelist1;
 fstream tfile;
 //fstream tfile1;
 tfile.open(outputfile.c_str(),fstream::in|fstream::out|fstream::trunc);
 filelist   = updatevector(file,nooffilelist);
 cout<<filename<<" list vector updated"<<endl;
 filelist1 = updatevector(file1,nooffilelist1);
 cout<<filename1<<" list vector updated"<<endl;
 missingfile(tfile,filelist,filelist1);
 cout<<outputfile<<" is created"<<endl;
 tfile.close();
 file.close();
 file1.close();
}

int main() 
{

  missingfileprocedure("todownloadtno.txt","tnolist.txt","missingtnolist.txt");
  missingfileprocedure("tnolist.txt","tnofcorrectfilelist.txt","missingtnofcorrectfilelist.txt");
  missingfileprocedure("tnolist.txt","tnoferrorfilelist.txt","missingtnoferrorfilelist.txt");
  missingfileprocedure("tnoferrorfilelist.txt","tnoserrorfilelist.txt","missingtnoserrorfilelist.txt");
  missingfileprocedure("tnofcorrectfilelist.txt","tnoscorrectfilelist.txt","missingtnoscorrectfilelist.txt");

 return 0;
}
