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
 file.open("tnolist.txt",fstream::in|fstream::out);
  if (file.good())
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
       if(a=='.'&& b=='t' && c=='x' && d=='t' && e=='\n')
       {
         line+=".txt\n";
         lines.push_back(line);nooflines++;
         line="";
         l+=4;
       }
       else if(a=='.'&& b=='t' && c=='x' && d=='t' && e!='\n')
       {
         line+=".txt\n";
         lines.push_back(line);nooflines++;
         line="";
         l+=3;
       }
       else 
       {
	     line+=textfile[l];
       }
      }
     sort(lines.begin(),lines.end());
     for(int q=0;q<nooflines;q++)
     	tfile<<lines[q];
     tfile.close();
     file.close();
     remove("tnolist.txt");
     if(rename("temp4.txt","tnolist.txt"));
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
  system("g++ Tnoaudio.cpp && ./a.out");
  return 0;
}
