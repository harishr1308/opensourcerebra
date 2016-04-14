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
#define f textfile[l+5]
#define g textfile[l+6]
#define h textfile[l+7]
#define i textfile[l+8]
#define j textfile[l+9]


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
    string tname;
    fstream tfile;
    tfile.open("temp2.txt",fstream::in|fstream::out|fstream::trunc);
  
    for(;l<textfile.size()-7;l++)
     {
      if(a=='<' && (b=='P' || b=='p') && c=='>')
       {
        string tn = "file" + temp;
        cout<<"printing tn : "<<tn<<endl;
        l+=3;
        tname = tn;
        tname.resize(15);
        tn = "";
        for(;l<textfile.size();l++)
        {
          if(a=='<')
          {
            if (b!='/')
            {// it is not /
              tfile<<" ";
              while(a!='>')
              {
                l++;
              }
            }
            else
            {// it is /
              if ((c=='p' || c=='P') && d=='>')
              {
                l+=4;
                tfile<<"\n";
                cout<<"para done"<<endl;
                break;    
              }
              else
              {
                while(a!='>')
                {
                  l++;
                }
              }
            }
          }
          else if(a=='&' && b=='n' && c=='b' && d=='s' && e=='p' && f==';' && textfile[l-1]!=' ' && g!=' ')
          {

            l+=5;
            tfile<<' ';
          }
          else if(a=='&' && b=='n' && c=='b' && d=='s' && e=='p' && f==';' && (textfile[l-1]!=' ' || g!=' '))
          {

            l+=5;
          //  tfile<<' ';
          }
          else
          {
           // cout<<"entered while loop"<<endl;
           tfile<<textfile[l];
           //cout<<textfile[l];
           //l++;
          }
        }
       }
      else if(a=='>' && b=='c' && c=='o' && d=='n' && e=='t' && f=='e' && g=='n' && h=='t' && i==':' && j=='<') //>content:<
       {
        tfile.close();
        string tnerror = tname+"e.txt";
        if(rename("temp2.txt",tnerror.c_str()))
              cout<<"File is renamed as : "<<tnerror<<endl;
           else
            {
              perror( "Error renaming file" );
            }
        remove("temp2.txt");
        tfile.open("temp2.txt",fstream::in|fstream::out|fstream::trunc);
       }
      else if(a=='<' && b=='/' && c=='t' && d=='a' && e=='b' && f=='l' && g=='e' && h=='>')
        {
          cout<<"all data entered"<<endl;
          tfile.close();
          string tncorrect = tname+"c.txt";
          if(rename("temp2.txt",tncorrect.c_str()))
              cout<<"File is renamed as : "<<tncorrect<<endl;
           else
            {
              perror( "Error renaming file" );
            }
        }
        else
        {
          continue;
        }
      }
      delete[] buffer;
      cout<<endl;
    }
    else
      cout<<"End of file reached for some reason"<<endl;
    
    file.close();
  }
  remove("temp2.txt");
  remove("c.txt");
  remove("e.txt");
  system("g++ sfile.cpp && ./a.out");
  return 0;
}