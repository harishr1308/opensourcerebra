
void filelist(string filename,string filecheck)
{
 vector<string> files;
 files = openfilenametype(filecheck); // or pass which dir to open
 fstream file;
 fstream tfile;
 tfile.open(filename.c_str(),fstream::in|fstream::out|fstream::trunc);
 for(int z=0;z<files.size();z++)
 {
  string temp = files[z];
  //T1234567890
  //cout<<temp<<"\t"<<endl;
  tfile<<GetTnoFromString(temp);
  tfile<<endl;
  //cout<<file.good()<<endl;
 }
 tfile.close();
}

vector<string> uniquesort(vector<string> v ,int &nooflines)
{
  vector<string>::iterator it;
  vector<string> myvector (v.size());
  it=unique_copy (v.begin(),v.end(),myvector.begin());   
  sort (myvector.begin(),it);                         
  it=unique_copy (myvector.begin(), it, myvector.begin(), stringequal);
  myvector.resize( distance(myvector.begin(),it) );
  nooflines = distance(myvector.begin(),it);
  sort(myvector.begin(),myvector.end());
  return myvector;
}

vector<string> readingfilelinebyline(fstream &temp, int &nooflines)
{
  vector<string> lines;
  if (temp.good())
   {
     l=0;
     string textfile = returnfilecontents(temp);
     string line;
     nooflines=0;
     for(;l<textfile.length();l++)
      {
       if(conditionchecking(textfile,l,"\n")==true && l<textfile.length()-1)
       {
         lines.push_back(line);nooflines++;
         line="";
       }
       else if(l==textfile.length()-1)
       {
         line+=textfile[l];
         lines.push_back(line);nooflines++;
         line="";
         break;
       }
       else 
       {
       line+=textfile[l];
       }
      }
     // delete[] buffer;
     cout<<endl;
     textfile="";
    }
    else
    {
      cout<<"End of file reached for some reason"<<endl;
    }
return lines;
}

vector<string> updatetnovector(fstream &tempfile,int &nooflines)
{
  vector<string> temp;
  if (tempfile.good())
   {
     l=0;
     string textfile = returnfilecontents(tempfile);
     string line;
     nooflines=0;
     for(;l<textfile.length();l++)
      {
       if(conditionchecking(textfile,l,"\n")==true && l<textfile.length()-1)
       {
        if(l!=0)
        {
         if(conditionchecking(textfile,l,"\nT")==true)
         {
          temp.push_back(line);nooflines++;
          line=""; 
         }
         else if(conditionchecking(textfile,l,"\n\n")==true)
         {
          continue;
         }  
        }
        else
        {
          continue;
        }
       }
       else if(l==textfile.length()-1)
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
     // delete[] buffer;
     textfile="";
    }
  else
    {
      // cout<<"End of file"<<k<<" reached for some reason"<<endl;
      cout<<"End of file reached for some reason"<<endl;
    }
  // k++;
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
 filelist   = updatetnovector(file,nooffilelist);
 cout<<filename<<" list vector updated"<<endl;
 filelist1 = updatetnovector(file1,nooffilelist1);
 cout<<filename1<<" list vector updated"<<endl;
 missingfile(tfile,filelist,filelist1);
 cout<<outputfile<<" is created"<<endl;
 tfile.close();
 file.close();
 file1.close();
}

void writingfiles(string name,vector<string> &v, int &nooflines)
{
 fstream temp;
 temp.open("temp4.txt",fstream::in|fstream::out|fstream::trunc);
 for(int q=0;q<nooflines;q++)
     if(v[q].length()>2)
        temp<<v[q]<<endl;
  filerename(temp,"temp4.txt",name.c_str());
}

void sortfile(string filename)
{
  fstream tfile;
  tfile.open(filename.c_str(),fstream::in|fstream::out);
  int nooflines=0;
  vector<string> filelist;
  filelist = readingfilelinebyline(tfile,nooflines);
  filelist = uniquesort(filelist,nooflines);
  sort(filelist.begin(),filelist.end());
  writingfiles(filename,filelist,nooflines);
}

void tnosplit(string filenamingconvention,string tnonamingconvention, string endtno)
{
 vector<string> files;
 files = openfilenametype(filenamingconvention); // pass what kind of files you want to open
 fstream file;
 string tempfilename = "temp.txt";
 for(int p=0;p<files.size();p++)
 {
  string temp = files[p];
  file.open(temp.c_str(),fstream::in|fstream::out);
  cout<<temp<<" is open"<<endl;
  if (file.good())
   { 
    string textfile = returnfilecontents(file);
    
    string tname;
    fstream tfile;
    vector<string> tnolist;
    tfile.open(tempfilename.c_str(),fstream::in|fstream::out|fstream::trunc);
    l=0;
    for(;l<textfile.length()-skip(tnonamingconvention)+1;l++)
     {
      if(conditionchecking(textfile,l,tnonamingconvention)==true)
       {
        string t = GetTnoFromString(textfile,l);
        tfile<<t;
        l+=skip(t);
        int chk=0;
        t+=".txt";
        string tn = t;
        t = "";
        for(int n=0;n<tnolist.size();n++)
         {
          if(tnolist[n]==tn) 
            {
              chk=1;
              break;
            }
         }
        if(chk==0)
         {
           tnolist.push_back(tn);
           tname=tn;
           filerenamereopennew(tfile,tempfilename,tname);
         }
         else
         {
         	chk=0;
         }
       }
        else if(conditionchecking(textfile,l,endtno)==true)
        {
          tfile<<endtno;
          l+=skip(endtno);
          tfile.close();
          remove(tempfilename.c_str());
          tfile.open(tempfilename.c_str(),fstream::in|fstream::out|fstream::trunc);
        }
        else
        { 
          tfile<<a;
        }  
      }
      while(l<textfile.length())
      {
        tfile<<a;
        l++;
      }
      cout<<endl;
      tfile.close();
    }
    else
    {
      cout<<"End of file reached for some reason"<<endl;
    }
    file.close();
  }
  remove(tempfilename.c_str());
}

void returnaudiolinks(string filenamingconvention, string urltype, string endurl)
{
 vector<string> files;
 files = openfilenametype(filenamingconvention); // or pass which dir to open
 fstream file;
 fstream tfile;
 cout<<"Returning Audio Links"<<endl;
 fstream tcfile;
 int check;
 tfile.open("tnoaudiolist.txt",fstream::in|fstream::out|fstream::trunc);
 tcfile.open("tnomissingaudiolist.txt",fstream::in|fstream::out|fstream::trunc);
 for(int p=0;p<files.size();p++)
 {
  check=0;
  string temp = files[p];
  file.open(temp.c_str(),fstream::in|fstream::out);
  cout<<temp<<" is open"<<endl;
  // cout<<file.good()<<endl;
  if(file.good())
   { 
    string textfile = returnfilecontents(file);
    cout<<textfile.length()<<endl;
    for(int z=0;z<textfile.length();z++)
     {
     	cout<<z<<"\t";
	    if(conditionchecking(textfile,z,urltype)==true)
	      {
	      	cout<<"conditon satisfied"<<endl;
	      	z+=skip(endurl);
	      	check=1;
	      	while(conditionchecking(textfile,z,endurl)==false)
	      	{
	      		tfile<<textfile[z];
	      		cout<<textfile[z];
	      		z++;
	      	}
	      	tfile<<"\n";
	      	cout<<endl;
	      	break;
	      }
	    else if (conditionchecking(textfile,z,urltype)==false)
	    {
	      	for(int y=0;y<urltype.length();y++)
	 			cout<<textfile[y+z];
	 		cout<<endl;
	    }
	    cout<<textfile[z];
	  }
      // delete[] buffer;
      // cout<<endl;
     }
    else
      cout<<"End of file reached for some reason"<<endl;
    file.close();
    if (check==0)
    {
      tcfile<<GetTnoFromString(temp)<<endl;
      cout<<GetTnoFromString(temp)<<endl;
    }
  }
  tcfile.close();
  tfile.close();
  cout<<"tnoaudiolist is created"<<endl;
  cout<<"tnomissingaudiolist is created"<<endl;
}

void removetags(string filenamingconvention, string endfile)
{
	vector<string> files;
	int l;
	files = openfilenametype(filenamingconvention); // or pass which dir to open
	fstream file;
	string tempfilename = "temp2.txt";
	for(int p=0;p<files.size();p++)
	{
		string temp = files[p];
		file.open(temp.c_str(),fstream::in|fstream::out);
		cout<<temp<<" is open"<<endl;
		// cout<<file.good()<<endl;
		if (file.good())
		{ 
			l=0;
			string textfile = returnfilecontents(file);
			string tname;
			fstream tfile;
			tfile.open(tempfilename.c_str(),fstream::in|fstream::out|fstream::trunc);

			for(;l<textfile.size()-skip(endfile)+1;l++)
			{
				if(conditionchecking(textfile,l,"<p>")==true)
				{
					string tn = "file" + GetTnoFromString(temp);
					cout<<"printing filename : "<<tn<<endl;
					l+=skip("<p>");
					tname = tn;
					tn = "";
					for(;l<textfile.size();l++)
					{
						if(conditionchecking(textfile,l,"<")==true)
						{
							if (conditionchecking(textfile,l,"</")==false)
							{// it is not /
								tfile<<" ";
								while(conditionchecking(textfile,l,">")==false)
								{
									l++;
								}
							}
							else
							{// it is /
								if (conditionchecking(textfile,l,"</p>")==true)
								{
									l+=skip("</p>");
									tfile<<"\n";
									cout<<"para done"<<endl;
									break;    
								}
								else
								{
									while(conditionchecking(textfile,l,">")==false)
									{
										l++;
									}
								}
							}
						}
						else if(conditionchecking(textfile,l,"&nbsp;")==true && conditionchecking(textfile,l-1," &nbsp;")==false && conditionchecking(textfile,l,"&nbsp; ")==false)
						{
							l+=skip("&nbsp;")-1;
							tfile<<' ';
						}
						else if(conditionchecking(textfile,l,"&nbsp;")==true &&	(( conditionchecking(textfile,l-1," &nbsp;")==false || conditionchecking(textfile,l-1,"&nbsp; ")==false	)))
						{

							l+=skip("&nbsp;")-1;
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

				else if(conditionchecking(textfile,l,">content:<")==true)
				{
					// tfile.close();
					string tnerror = tname+"e.txt";
					filerenamereopenold(tfile,tempfilename,tnerror);
				}
				else if(conditionchecking(textfile,l,endfile)==true)
				{
					cout<<"all data entered"<<endl;
					// tfile.close();
					string tncorrect = tname+"c.txt";
					filerename(tfile,tempfilename,tncorrect);
				}
				else
				{
					continue;
				}
			}
			cout<<endl;
		}
		else
		cout<<"End of file reached for some reason"<<endl;

		file.close();
	}
	remove("temp2.txt");
	remove("c.txt");
	remove("e.txt");
}

void wordcheck(string outputfilenamingconvention)
{
 vector<string> files;
 files = openfilenametype(outputfilenamingconvention); // or pass which dir to open
 fstream file;
 string tempfilename = "temp4.txt";
 for(int p=0;p<files.size();p++)
 {
  string temp = files[p];
  file.open(temp.c_str(),fstream::in|fstream::out);
  cout<<temp<<" is open"<<endl;
  if (file.good())
   { 
    l=0;
    string textfile = returnfilecontents(file);
    string line;
    fstream tfile;
    tfile.open(tempfilename.c_str(),fstream::in|fstream::out|fstream::trunc);
    vector<string> lines;
    int nooflines=0;
    for(;l<textfile.length();l++)
    {
      if(conditionchecking(textfile,l,"\n")==true)
      {
        line+="\n";
        lines.push_back(line);nooflines++;
        line="";
      }
      else if(conditionchecking(textfile,l," ")==true)
      {
        cout<<"extra space encountered"<<endl;
      }
      else 
      {
       line+=textfile[l];
      }
      if(l>textfile.length())
      {
       break;
      }      
    }
    for(int q=0;q<nooflines;q++)
    {
      if(lines[q].size()<2)
      {
        cout<<"encountered extra new line"<<endl;
      }
      else
      {
        tfile<<lines[q];
      }
    }
    filerename(tfile,tempfilename,temp);
    cout<<endl;
    textfile="";
    }
    else
    {
      cout<<"End of file reached for some reason"<<endl;
    }
    file.close();
  }
  remove(tempfilename.c_str());
}

void getwords(string filenamingconvention, string outputfilenamingconvention)
{
 vector<string> files;
 files = openfilenametype(filenamingconvention); // or pass which dir to open
 fstream file;
 string tempfilename = "temp3.txt";
 for(int p=0;p<files.size();p++)
 {
  string temp = files[p];
  file.open(temp.c_str(),fstream::in|fstream::out);
  cout<<temp<<" is open"<<endl;
  if (file.good())
   { 
    l=0;
    string textfile = returnfilecontents(file);
    string tname;
    fstream tfile;
    tfile.open(tempfilename.c_str(),fstream::in|fstream::out|fstream::trunc);
    for(;l<textfile.length();l++)
    {
      if (l<(textfile.length()-1))
      {
        if(conditionchecking(textfile,l,".")==true)
        {
          if(conditionchecking(textfile,l,". ")==true)
          {
            if(conditionchecking(textfile,l,". \n")==true)
            {
              tfile<<"\n";l+=skip(". \n")-1;
            }
            else
            {
              tfile<<"\n";l++;
            }
          } 
          else if (conditionchecking(textfile,l,".$")==true || conditionchecking(textfile,l-1,"$.$")==true)
          {
            tfile<<".";
          }
          else if (conditionchecking(textfile,l,".\n")==true)
          {
            tfile<<"\n";l++;
          }
          else
          {
            tfile<<"\n";
          } 
        }
        else if (conditionchecking(textfile,l," ")==true)
        {
          tfile<<"\n";
        }
        else if (conditionchecking(textfile,l,"$.")==true)
        {
          tfile<<a;
          if(conditionchecking(textfile,l,"$.$")==true)
            {
              tfile<<b<<c;
              if (conditionchecking(textfile,l,"$.$$")==true)
              {
                tfile<<d;
                if(conditionchecking(textfile,l,"$.$$.")==true)
                {
                  tfile<<"\n";
                  l+=skip("$.$$.")-1;
                }
                else
                {
                  l+=skip("$.$$")-1;
                }
              }
              else if (conditionchecking(textfile,l,"$.$.")==true)
              {
                tfile<<"\n";
                l+=skip("$.$.")-1;
              }
              else
              {
                l+=skip("$.$")-1;
              }
            }
          else if (conditionchecking(textfile,l,"$. ")==true)
            {
              if(conditionchecking(textfile,l-1,"\n$. ")==false)
              {
                tfile<<"\n";
                l+=skip("$. ")-1;
              }
              else
              {
                tfile<<b<<"\n";
                l+=skip("$. ")-1;
              }
            }
          else
          {
            l+=skip("$.")-1;
          }
        }
        else if (conditionchecking(textfile,l,"\n")==true)
        {
          tfile<<"\n";
        }
        else if (conditionchecking(textfile,l,"? ")==true || conditionchecking(textfile,l,"?\n")==true)
        {
          tfile<<"?\n";
        }
        else if (conditionchecking(textfile,l,": ")==true ||conditionchecking(textfile,l,":\n")==true)
        {
          tfile<<":\n";
        }
        else if (conditionchecking(textfile,l,"! ")==true ||conditionchecking(textfile,l,"!\n")==true)
        {
         tfile<<"!\n"; 
        }
        else
        { 
          //cout<<"not fullstop"<<endl;
          if (conditionchecking(textfile,l-1," ")==false)
          {
            tfile<<textfile[l];
          }
          else if (conditionchecking(textfile,l," ")==true )
          {
            tfile<<"\n";
          }
        }  
      }   
      if(l>=(textfile.length()-1))
      {
        if (conditionchecking(textfile,l,".")==false && conditionchecking(textfile,l," ")==false && conditionchecking(textfile,l,"\n")==false)
        {
          tfile<<a;
        }
        string tn="w";
        tn+=GetTnoAndSuffixFromString(temp);
        tname=tn;
        tn="";
        filerename(tfile,tempfilename,tname);
         break;
      }
    }
      cout<<endl;
      textfile="";
    }
    else
    {
      cout<<"End of file reached for some reason"<<endl;
    }
    file.close();
  }
  remove(tempfilename.c_str());
  wordcheck(outputfilenamingconvention);
}

void sfilecheck(string outputfilenamingconvention)
{
 vector<string> files;
 int z=0;
 files = openfilenametype(outputfilenamingconvention); // or pass which dir to open
 fstream file;
 string tempfilename = "temp4.txt";
 for(int p=0;p<files.size();p++)
 {
  string temp = files[p];
  file.open(temp.c_str(),fstream::in|fstream::out);
  cout<<temp<<" is open"<<endl;
  if (file.good())
   { 
    l=0;
    string textfile = returnfilecontents(file);
    string tname;
    fstream tfile;
    tfile.open(tempfilename.c_str(),fstream::in|fstream::out|fstream::trunc);
    z=0;
    for(;l<textfile.length();l++)
    {
      if(conditionchecking(textfile,l,"  ")==true)
      {
       z=1;
       while(conditionchecking(textfile,l,"\n")==false)
       {
         if(conditionchecking(textfile,l," ")==true && conditionchecking(textfile,l+z," ")==true)
         {
           z++;
         }
         else
         {
           tfile<<" ";
           if(checkincrement(l,textfile.length(),z)!=2)
           {
           	l+=z;
           }
           break;
         }
        }
      }
      if (conditionchecking(textfile,l,"\n ")==true || conditionchecking(textfile,l," \n")==true)
      {
        tfile<<"\n";
        l+=skip("\n ")-1;
      }
      else
      {
        tfile<<textfile[l];
      }
    }
    filerename(tfile,tempfilename,temp);
    cout<<endl;
    textfile="";
    }
    else
    {
      cout<<"End of file reached for some reason"<<endl;
    }
    file.close();
  }
  remove(tempfilename.c_str());
}

void sfilecheck_blank(string outputfilenamingconvention, string blank)
{
 vector<string> files;
 files = openfilenametype(outputfilenamingconvention); // or pass which dir to open
 fstream file;
 string tempfilename = "temp4.txt";
 for(int p=0;p<files.size();p++)
 {
  string temp = files[p];
  file.open(temp.c_str(),fstream::in|fstream::out);
  cout<<temp<<" is open"<<endl;
  cout<<file.good()<<endl;
  if (file.good())
   { 
    l=0;
    string textfile = returnfilecontents(file);
    string tname;
    string line;
    fstream tfile;
    tfile.open(tempfilename.c_str(),fstream::in|fstream::out|fstream::trunc);
    vector<string> lines;
    int nooflines=0;
    for(;l<textfile.length();l++)
    {
      if(conditionchecking(textfile,l,"</s>")==true)
      {
        line+="</s>";
        lines.push_back(line);nooflines++;
        line="";
        if(checkincrement(l,textfile.length(),skip("</s>")-1)!=2)
           {
           	l+=skip("</s>")-1;
           }
      }
      else 
      {
	     line+=textfile[l];
      }
      if(l>textfile.length())
      {
	     break;
      }      
    }
    //  <s> .</s>\n
    //  0123456789
    for(int q=0;q<nooflines;q++)
    {
      if(lines[q].size()<=skip(blank))
      {
        cout<<"encountered "<<blank<<endl;
      }
      else
      {
        tfile<<lines[q];
      }
    }
    filerename(tfile,tempfilename,temp);
    cout<<endl;
    textfile="";
    }
    else
    {
      cout<<"End of file reached for some reason"<<endl;
    }
    file.close();
  }
  remove(tempfilename.c_str());
}

void sfilecheck_space(string outputfilenamingconvention)
{
 vector<string> files;
 files = openfilenametype(outputfilenamingconvention); // or pass which dir to open
 fstream file;
 string tempfilename = "temp4.txt";
 for(int p=0;p<files.size();p++)
 {
  string temp = files[p];
  file.open(temp.c_str(),fstream::in|fstream::out);
  cout<<temp<<" is open"<<endl;
  if (file.good())
   { 
    l=0;
    string textfile = returnfilecontents(file);
    string tname;
    string line;
    fstream tfile;
    tfile.open(tempfilename.c_str(),fstream::in|fstream::out|fstream::trunc);
    vector<string> lines;
    int nooflines=0;
    for(;l<textfile.length();l++)
    {
      if(conditionchecking(textfile,l,"</s>")==true)
      {
        if(conditionchecking(textfile,l-1," </s>")==false)
            line+=" </s>";
        else 
            line+="</s>";
        lines.push_back(line);nooflines++;
        line="";
        if(checkincrement(l,textfile.length(),skip("</s>")-1)!=2)
           {
           	l+=skip("</s>")-1;
           }
      }
      else 
      {
       line+=textfile[l];
      }
      if(l>textfile.length())
      {
       break;
      }      
    }
    //  <s> .</s>\n
    //  0123456789
    string te;
    for(int q=0;q<nooflines;q++)
    {
      te = lines[q];
      for(int r=0;r<te.length()-skip("</s>")+1;r++)
      {
        if(conditionchecking(te,r,"</s>")==true && conditionchecking(te,r,"</s> ")==false)
        {
          te.insert(r+3,1,' ');break;
        }
      }
      for(int r=1;r<te.length()-skip("</s>")+1;r++)
      {
        if(conditionchecking(te,r," </s>")==false && conditionchecking(te,r,"</s>")==true)
        {
          te.insert(r-1,1,' ');break;
        }
      }  
      lines[q]=te;
      tfile<<lines[q];
      te="";
    }
    filerename(tfile,tempfilename,temp);
    cout<<endl;
    textfile="";
    }
    else
    {
      cout<<"End of file reached for some reason"<<endl;
    }
    file.close();
  }
  remove(tempfilename.c_str());
}

void putsfiletags(string filenamingconvention, string outputfilenamingconvention)
{
	vector<string> files;
	files = openfilenametype(filenamingconvention); // or pass which dir to open
	fstream file;
	string tempfilename = "temp3.txt";
	for(int p=0;p<files.size();p++)
	{
	string temp = files[p];
	file.open(temp.c_str(),fstream::in|fstream::out);
	cout<<temp<<" is open"<<endl;
	if (file.good())
	{ 
		l=0;
		string textfile = returnfilecontents(file);
		string tname;
		fstream tfile;
		tfile.open(tempfilename.c_str(),fstream::in|fstream::out|fstream::trunc);
		tfile<<"<s> ";
		for(;l<textfile.length();l++)
		{
		if (l<(textfile.length()-1))
		{
		if(conditionchecking(textfile,l,".")==true)
		{
		if(conditionchecking(textfile,l,". ")==true)
		{
		if(conditionchecking(textfile,l,". \n")==false)
		{
			tfile<<".</s>\n<s> ";
			//l++;
			if(checkincrement(l,textfile.length(),1)!=2)
			{
				l++;
			}
		}
		else
		{
			tfile<<".</s>\n<s> ";
			//l+=2;
			if(checkincrement(l,textfile.length(),2)!=2)
			{
				l+=2;
			}
		}
		} 
		else if (conditionchecking(textfile,l,".$")==true || conditionchecking(textfile,l-1,"$.")==true)
		{
		tfile<<".";
		}
		else if (conditionchecking(textfile,l,".\n")==true)
		{
		tfile<<".</s>\n<s> ";
		//l++;
		if(checkincrement(l,textfile.length(),1)!=2)
		{
		l++;
		}
		}
		else
		{
		tfile<<".</s>\n<s> ";
		} 
		}
		else if (conditionchecking(textfile,l,"$.")==true)
		{
		tfile<<a;
		if(conditionchecking(textfile,l,"$.$")==true)
		{
		tfile<<b<<c;
		if (conditionchecking(textfile,l,"$.$$")==true)
		{
		tfile<<d;
		if(conditionchecking(textfile,l,"$.$$.")==true)
		{
		tfile<<".</s>\n<s> ";
		if(checkincrement(l,textfile.length(),skip("$.$$.")-1)!=2)
		{
		l+=skip("$.$$.")-1;
		}
		// l+=skip("$.$$.")-1;
		}
		else
		{
		// l+=skip("$.$$")-1;
		if(checkincrement(l,textfile.length(),skip("$.$$")-1)!=2)
		{
		l+=skip("$.$$")-1;
		}
		}
		}
		else if (conditionchecking(textfile,l,"$.$.")==true)
		{
		tfile<<".</s>\n<s> ";
		// l+=skip("$.$.")-1;
		if(checkincrement(l,textfile.length(),skip("$.$.")-1)!=2)
		{
		l+=skip("$.$.")-1;
		} 
		}
		else
		{
		// l+=skip("$.$")-1;
		if(checkincrement(l,textfile.length(),skip("$.$")-1)!=2)
		{
		l+=skip("$.$")-1;
		}

		}
		}
		else if (conditionchecking(textfile,l,"$. ")==true)
		{
		if(conditionchecking(textfile,l-1,"\n$. ")==true)
		{
		tfile<<".</s>\n<s> ";
		// l+=skip("$. ")-1;
		if(checkincrement(l,textfile.length(),skip("$. ")-1)!=2)
		{
		l+=skip("$. ")-1;
		}

		}
		else
		{
		tfile<<b<<c;
		// l+=skip("$. ")-1;
		if(checkincrement(l,textfile.length(),skip("$. ")-1)!=2)
		{
		l+=skip("$. ")-1;
		}

		}
		}
		else if (conditionchecking(textfile,l,"$.\n")==true)
		{
		tfile<<".</s>\n<s>";
		}
		else
		{
		// l++;
		if(checkincrement(l,textfile.length(),1)!=2)
		{
		l++;
		}

		}
		}
		else if (conditionchecking(textfile,l,"\n")==true)
		{
		tfile<<".</s>\n<s> ";
		}
		else if (conditionchecking(textfile,l,"? ")==true || conditionchecking(textfile,l,"?\n")==true)
		{
		tfile<<"?</s>\n<s> ";
		}
		else if (conditionchecking(textfile,l,": ")==true ||conditionchecking(textfile,l,":\n")==true)
		{
		tfile<<":</s>\n<s> ";
		}
		else if (conditionchecking(textfile,l,"! ")==true ||conditionchecking(textfile,l,"!\n")==true)
		{
		tfile<<"!</s>\n<s> "; 
		}
		else
		{ 
		//cout<<"not fullstop"<<endl;
		if(l<textfile.length()-1)
		tfile<<textfile[l];
		}  
		}   
		if(l==(textfile.length()-1))
		{
		//cout<<"last char"<<endl;
		if (conditionchecking(textfile,l,".")==false && conditionchecking(textfile,l," ")==false && conditionchecking(textfile,l,"\n")==false)
		{
		tfile<<a;
		}
		tfile<<".</s>";
		string tn="s";
		tn+=GetTnoAndSuffixFromString(temp);
		cout<<"This is your file which gets created : "<<tn<<endl;
		cout<<"This is what gets returned from the function : "<<GetTnoAndSuffixFromString(temp)<<endl;
		tname=tn;
		tn="";
		filerename(tfile,tempfilename,tname);
		break;
		}
		if(l>(textfile.length()-1))
		{
		//cout<<"last char"<<endl;
		tfile<<".</s>";
		string tn="s";
		tn+=GetTnoAndSuffixFromString(temp);
		cout<<"This is your file which gets created : "<<tn<<endl;
		cout<<"This is what gets returned from the function : "<<GetTnoAndSuffixFromString(temp)<<endl;
		tname=tn;
		tn="";
		filerename(tfile,tempfilename,tname);
		break;
		}
		}
		cout<<endl;
		textfile="";
		}
		else
		{
		cout<<"End of file reached for some reason"<<endl;
		}
		file.close();
	}
	remove(tempfilename.c_str());
	sfilecheck(outputfilenamingconvention);
	sfilecheck_blank(outputfilenamingconvention,"<s> .</s>\n");
	sfilecheck_space(outputfilenamingconvention);
}