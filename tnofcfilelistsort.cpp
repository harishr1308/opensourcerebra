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

int main() 
{
 fstream file;
 fstream tfile;
 file.open("tnofcorrectfilelist.txt",fstream::in|fstream::out);
  if (tfile.good())
   {
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
     sort(lines.begin(),lines.end());
     for(int q=0;q<nooflines;q++)
     	tfile<<lines[q]<<endl;
     tfile.close();
     file.close();
     remove("tnofcorrectfilelist.txt");
     if(rename("temp4.txt","tnofcorrectfilelist.txt"));
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
  remove("temp4.txt");
  return 0;
}
