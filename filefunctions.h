// #include "headerfiles.h"

bool checkchar(char temp)
{
	if((temp>=97) && (temp<=122))
			return true;
	else return false;
}

bool checkCHAR(char temp)
{
	if((temp>=65) && (temp<=90))
			return true;
	else return false;
}

bool checknumber(char temp)
{
	if ((temp>=48) && (temp<=57))
		return true;
	else return false;
}

bool checkchari(char temp) //similar to strcmpi and yes i have no idea why i wrote this and yes it works on a character basis
{
	if(checkCHAR(temp) || checkchar(temp))
			return true;
	else return false;
}

bool stringequal (string z, string y)
{
  return (z==y);
}

int checkincrement(int l, int size, int to_be_incremented)
{
	if(l+to_be_incremented < size)
		return 0;
	else if(l+to_be_incremented == size)
		return 1;
	else
		return 2;
}

// bool iequals(string temp1,string temp2)
// {
// 	if(temp.length() == temp2.length())
// 	{
// 	   for(int i=0;i<temp2.length();i++)
// 	   {
// 	       if(temp[i]==temp2[i])
// 	            continue;
// 	        else if (temp[i]==touppercase(temp2[i]))
// 	            continue;
// 	        else if (temp[i]==tolowercase(temp2[i]))
// 	            continue;
// 	        else if(checknumber(temp[i]) && temp2[i]=)
// 	        else
// 	        {
// 	            cout<<"Strings are not the same"<<endl;
// 	            return false;
// 	        }
// 	   }
// 	}
// 	else
// 	{
// 		cout<<"strings are not the same"<<endl;
// 		return false;
// 	}
// 	return true;
// }

char uppercase(char temp)
{
	if (checkchar(temp))
		return char(int(temp)-97+65);
	else return temp;
}

char lowercase(char temp)
{
	if (checkCHAR(temp))
		return char(int(temp)+97-65);
	else return temp;
}


// bool stringconditionchecking(string textfile, int pos, string tocheck)
// {
// 	string temp;
// 	for(int i=pos;pos<tocheck.length();i++)
// 	{
// 		temp+=textfile[i];
// 	}
// 	if(iequals(temp,tocheck))
// 		return true;
// 	else return false;
// }

int skip(string temp)
{
	return temp.length();
}

bool conditionchecking(string textfile, string tocheck)
{
	int check=0;
	//cout<<textfile<<"\t"<<tocheck<<endl;
	for(int z=0;z<tocheck.length();z++)
	{
		if (tocheck[z]==textfile[z])
			continue;
		else if(checkchari(tocheck[z])==true && checkchari(textfile[z])==true)
		{
			if(tocheck[z]==uppercase(textfile[z]))
				continue;
			else if(tocheck[z]==lowercase(textfile[z]))
				continue;
			else
				{
					check=1;break;
				}

		}
		else if(tocheck[z]=='$')
			{	//cout<<textfile[z];
				if(checknumber(textfile[z])==true)
					continue;
				else
				{
					//cout<<"The Naming convention used without pos wrong\t"<<textfile<<endl;
					check=1;break;
				}
		    }
		else if(tocheck[z]=='#')
			{
				if(checkchari(textfile[z]))
					continue;
				else
				{
					//cout<<"The Naming convention used without pos wrong\t"<<textfile<<endl;
					check=1;break;
				}
			}
		else if(tocheck[z]!=textfile[z])
			{
				check=1;
				break;
			}
	}
	//cout<<endl;
	if (check==0) return true;
	else return false;
}

bool conditionchecking( string textfile, int pos, string tocheck)
{
	int check=0;
	string stringwindow;
	for(int z=pos;z<tocheck.length()+pos;z++)
	{
		stringwindow+=textfile[z];
	}
	//cout<<stringwindow<<"\t"<<pos<<"\t"<<tocheck<<"\t"<<tocheck.length()<<endl;
	for(int z=0;z<tocheck.length();z++)
	{
		if (tocheck[z]==stringwindow[z])
			continue;
		else if(checkchari(tocheck[z])==true && checkchari(stringwindow[z])==true)
		{
			if(tocheck[z]==uppercase(stringwindow[z]))
				continue;
			else if(tocheck[z]==lowercase(stringwindow[z]))
				continue;
			else
			{
				//cout<<"completely different characters\t"<<tocheck[z]<<"\t"<<stringwindow[z]<<endl;
				check=1;
				break;
			}
		}
		else if(tocheck[z]=='$')
			{
				if(checknumber(stringwindow[z]))
					continue;
				else 
				{
					//cout<<"The Naming convention used is wrong\t"<<stringwindow<<"\t"<<pos<<"\t"<<tocheck<<"\t"<<tocheck.length()<<endl;
					check=1;
					break;
				}
		    }
		else if(tocheck[z]=='#')
			{
				if(checkchari(stringwindow[z]))
					continue;
				else
				{
					//cout<<"The Naming convention used is wrong\t"<<stringwindow<<"\t"<<pos<<"\t"<<tocheck<<"\t"<<tocheck.length()<<endl;
					check=1;
					break;
				} 
			}
		else if(tocheck[z]!=stringwindow[z])
			{
				check=1;
				break;
			}
		else
		{
			cout<<tocheck[z]<<"\t"<<stringwindow[z]<<"\t unable to compare"<<endl;
		}
	}
	if (check==0) return true;
	else return false;
}

void filerenamereopennew(fstream &file,string oldname,string newname)
{
	file.close();
	//remove(newname.c_str());
	if(rename(oldname.c_str(),newname.c_str())==0)
	{
		cout<<"File is renamed as : "<<newname<<endl;
	}  
	else
	{
		fprintf(stderr, "Renaming File %s\n", newname.c_str());
		perror("");
	}
	file.open(newname.c_str(),fstream::in|fstream::out|fstream::app);
	cout<<newname<<" is reopened"<<endl;
	remove(oldname.c_str());
}

void filerenamereopenold(fstream &file,string oldname,string newname)
{
	file.close();
	//remove(newname.c_str());
	if(rename(oldname.c_str(),newname.c_str())==0)
	  cout<<"File is renamed as : "<<newname<<endl;
	else
	{
	   	fprintf(stderr, "Renaming File %s\n", newname.c_str());
		perror("");
	}
	cout<<newname<<" is created"<<endl;
	remove(oldname.c_str());
	file.open(oldname.c_str(),fstream::in|fstream::out|fstream::trunc);
	cout<<oldname<<" is reopened"<<endl;
}

void filerename(fstream &file,string oldname,string newname)
{
	file.close();
	//remove(newname.c_str());
	if(rename(oldname.c_str(),newname.c_str())==0)
	{
		cout<<"File is renamed as : "<<newname<<endl;
	}  
	else
	{
		fprintf(stderr, "Renaming File %s\n", newname.c_str());
		perror("");
	}
	cout<<newname<<" is created"<<endl;
	remove(oldname.c_str());
}

string returnfilecontents(fstream &file)
{
    file.seekg (0, file.end);
    int length = file.tellg();
    file.seekg (0, file.beg);
    char * buffer = new char [length];
    file.read (buffer,length);
    string textfile(buffer);
    delete[] buffer;
    return textfile;
}

vector<string> openfilenametype(string tocheck,string path = ".") 
{
 DIR*    dir;
 dirent* pdir;
 vector<string> files;
 dir = opendir(path.c_str());
 while (pdir = readdir(dir))
  {
    string fn = pdir->d_name;
    if(fn.substr(fn.find_last_of(".") + 1) == "txt" && conditionchecking(fn,tocheck)==true)
      files.push_back(fn);
  }
  sort(files.begin(),files.end());
 return files;
}

string GetTnoFromString(string tno)
{
	string temp;
	for(int z=0;z<tno.length();z++)
	{
		if(tno[z]=='T')
		{
			for(int y=0;y<SIZE_OF_TNO;y++,z++)
			{
				temp+=tno[z];
			}
			break;
		}
	}
	return temp;
}

string GetTnoFromString(string tno,int pos)
{
	string temp;
	for(int z=pos;z<tno.length();z++)
	{
		if(tno[z]=='T')
		{
			for(int y=0;y<SIZE_OF_TNO;y++,z++)
			{
				temp+=tno[z];
			}
			break;
		}
	}
	return temp;
}

string GetTnoSuffixFromString(string tno)
{
	string temp;
	int check=0;
	for(int z=0;z<tno.length();z++)
	{
		if(tno[z]=='T')
		{
			check=1;
			z+=SIZE_OF_TNO;
		}
		if(check==1)
			temp+=tno[z];
	}
	return temp;
}

string GetTnoAndSuffixFromString(string filename)
{
	string temp;
	temp+=GetTnoFromString(filename);
	temp+=GetTnoSuffixFromString(filename);
	return temp;
}