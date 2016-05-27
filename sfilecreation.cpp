#include "headerfiles.h"

int main()
{
	putsfiletags("fileT$$$$$$$$$$#","sT$$$$$$$$$$#");
	
	filelist("tnoscorrectfilelist.txt","sT$$$$$$$$$$c");
	sortfile("tnoscorrectfilelist.txt");
	
 	missingfileprocedure("tnofcorrectfilelist.txt","tnoscorrectfilelist.txt","missingtnoscorrectfilelist.txt");
  	sortfile("missingtnoscorrectfilelist.txt");


	filelist("tnoserrorfilelist.txt","sT$$$$$$$$$$e");
	sortfile("tnoserrorfilelist.txt");
 	

 	missingfileprocedure("tnoferrorfilelist.txt","tnoserrorfilelist.txt","missingtnoserrorfilelist.txt");
  	sortfile("missingtnoserrorfilelist.txt");
 
	return 0;
}