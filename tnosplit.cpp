#include <fstream>
#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <dirent.h>
using namespace std;

vector<string> open(string path = ".") 
{
 DIR*    dir;
 dirent* pdir;
 vector<string> files;
 dir = opendir(path.c_str());
 while (pdir = readdir(dir))
  {
    string fn = pdir->d_name;
    if(fn.substr(fn.find_last_of(".") + 1) == "txt" && (fn[0]>=48 && fn[0]<=57))
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
    file.seekg (0, file.end);
    int length = file.tellg();
    file.seekg (0, file.beg);
    char * buffer = new char [length];
    //cout << "Reading " << length << " characters... ";
    // read data as a block:
    file.read (buffer,length);
    string textfile(buffer);
    //cout<<textfile<<endl;
    string tname;
    fstream tfile;
    vector<string> tnolist;
    tfile.open("temp.txt",fstream::in|fstream::out|fstream::trunc);
    char a,b,c,d,e,f,g,h,i,j,k;
    int l=0;
    for(;l<textfile.size()-10;l++)
     {
      a = textfile[l];
      b = textfile[l+1];
      c = textfile[l+2];
      d = textfile[l+3];
      e = textfile[l+4];
      f = textfile[l+5];
      g = textfile[l+6];
      h = textfile[l+7];
      i = textfile[l+8];
      j = textfile[l+9];
      k = textfile[l+10];
      if(a=='T' && (b>=48 && b<=57) && (c>=48 && c<=57) && (d>=48 && d<=57) && (e>=48 && e<=57) && (f>=48 && f<=57) && (g>=48 && g<=57) && (h>=48 && h<=57) && (i>=48 && i<=57) && (j>=48 && j<=57) && (k>=48 && k<=57) )
       {
        string t;
        int m=0;
        for(;m<11;m++)
         {
           //t[m]=textfile[l+m];
           t+=textfile[l+m];
           tfile<<textfile[l+m];
           //cout<<l+m<<"\t"<<textfile[l+m]<<endl;
         }
        l+=m-1;
        int chk=0;
        t+=".txt";
        string tn = t;
        t = "";
        cout<<"printing tn : "<<tn<<endl;
        //cout<<"displaying vector contents :"<<endl;
        for(int n=0;n<tnolist.size();n++)
         {
          //cout<<tnolist[n]<<"\n";
          if(tnolist[n]==tn) 
            {
              chk=1;
              break;
            }
         }
         cout<<"printing chk : "<<chk<<endl;
        if(chk==0)
         {
           tnolist.push_back(tn);
           tname=tn;
           cout<<"tname is found as : "<<tname<<endl;
           //cout<<endl;
           tfile.close();
           if(rename("temp.txt",tname.c_str()))
              cout<<"File is renamed as : "<<tname<<endl;
           else
            {
              perror( "Error renaming file" );
            }
           tfile.open(tname.c_str(),fstream::in|fstream::out|fstream::app);
           cout<<"tfile is reopened"<<endl;
         }
         else
         {
         	chk=0;
         }
       }
        else if(a=='<' && b=='/' && c=='t' && d=='a' && e=='b' && f=='l' && g=='e' && h=='>')
        {
          //cout<<"</table>"<<endl;
          //cout<<endl;
          //cout<<l<<endl;
          int m;
          for(m=0;m<=7;m++)
          {
            tfile<<textfile[l+m];
            //cout<<l+m<<"\t"<<textfile[l+m]<<endl;
          }
          l+=m;
         // cout<<endl;
          cout<<"all data entered"<<endl;
          tfile.close();
          remove("temp.txt");
          tfile.open("temp.txt",fstream::in|fstream::out|fstream::trunc);
        }
        else
        { 
          //cout<<"else condition"<<endl;
          tfile<<textfile[l];
          //cout<<l<<"\t"<<textfile[l]<<endl;
        }  
      }
      // ...buffer contains the entire file...
      while(l<textfile.size())
      {
        tfile<<textfile[l];
        //cout<<l<<"\t"<<textfile[l]<<endl;
        l++;
      }
      delete[] buffer;
      cout<<endl;
      tfile.close();
      
    }
    else
    {
      cout<<"End of file reached for some reason"<<endl;
    }
    file.close();
  }
  remove("temp.txt");
  //system("g++ tnolisting.cpp && ./a.out");
  return 0;
}
