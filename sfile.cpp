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
    fstream tfile;
    tfile.open("temp3.txt",fstream::in|fstream::out|fstream::trunc);
    tfile<<"<s> ";
    for(;l<length;l++)
    {
    //  cout<<"character : "<<a<<"\t no : "<<l<<endl;
      if (l<(length-1))
      {
        //cout<<"full stop"<<endl;
        if(a=='.')
        {
          if(b==' ')
          {
            if(c!='\n')
            {
              tfile<<"</s>\n<s> ";l++;
            }
            else
            {
              tfile<<"</s>\n<s> ";l+=2;
            }
          } 
          else if ((b>=48 && b<=57) || (textfile[l-1]>=48 && textfile[l-1]<=57))
          {
            tfile<<".";

          }
          else if (b=='\n')
          {
            tfile<<"</s>\n<s> ";l++;
          }
          else
          {
            tfile<<"</s>\n<s> ";
          } 
        }
        else if ((a>=48 && a<=57) && b=='.')
        {
          tfile<<a;
          if(c>=48 && c<=57)
            {
              tfile<<b<<c;
              if (d>=48 && d<=57)
              {
                tfile<<d;
                if(e=='.')
                {
                  tfile<<"</s>\n<s> ";
                  l+=4;
                }
                else
                {
                  l+=3;
                }
              }
              else if (d=='.')
              {
                tfile<<"</s>\n<s> ";
                l+=3;
              }
              else
              {
                l+=2;
              }
            }
          else if (c==' ')
            {
              if(textfile[l-1]!='\n')
              {
                tfile<<"</s>\n<s> ";
                l+=2;
              }
              else
              {
                tfile<<b<<c;
                l+=2;
              }
            }
          else
          {
            l++;
          }
        }
        else if (a=='\n')
        {
          tfile<<"</s>\n<s> ";
        }
        else if (a=='?' && b==' ')
        {
          tfile<<"?</s>\n<s> ";
        }
        else if (a=='!' && b==' ')
        {
         tfile<<"!</s>\n<s> "; 
        }
        else
        { 
          //cout<<"not fullstop"<<endl;
          tfile<<textfile[l];
        }  
      }   
      if(l>=(length-1))
      {
        //cout<<"last char"<<endl;
        if (a!='.' && a!=' ' && a!='\n')
        {
          tfile<<a;
        }
        tfile<<"</s>";
        string tn="s";
        for(int i=4;i<temp.size();i++)
        {
          tn+=temp[i];
        }
        tname=tn;
        tn="";
        tfile.close();
        if(rename("temp3.txt",tname.c_str()))
          cout<<"File is renamed as : "<<tname<<endl;
        else
         {
           perror( "Error renaming file" );
         }
         break;
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
    file.close();
  }
  remove("temp3.txt");
  //system("g++ scheck.cpp && ./a.out");
  return 0;
}