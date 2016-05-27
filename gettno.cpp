#include "headerfiles.h"

int main()
{
	//system("g++ todownloadfilessort.cpp && ./a.out"); // sorts the todownloadtno.txt
	sortfile("todownloadtno.txt");
	system("python tnodownload.py"); // downloads all the files
	

	tnosplit("$","T$$$$$$$$$$","</table>"); //parameter definitions are as follows filenamingconvention  tnonamingconvention and the final tag which distinguishes each file
	filelist("tnolist.txt","T$$$$$$$$$$");
	sortfile("tnolist.txt");
	

	missingfileprocedure("todownloadtno.txt","tnolist.txt","missingtnolist.txt");
    sortfile("missingtnolist.txt");


	returnaudiolinks("T$$$$$$$$$$","\'http","\'"); // parameter definitions are as follows filenamingconvention  typeofurl whether its www or \http etc and finally how the url is enclosed in single ' or "
	

	removetags("T$$$$$$$$$$","</table>"); // parameter definitions are as follows filenamingconvention and the final tag which distinguishes each file
	filelist("tnofcorrectfilelist.txt","fileT$$$$$$$$$$c");
	sortfile("tnofcorrectfilelist.txt");
 	
	missingfileprocedure("tnolist.txt","tnofcorrectfilelist.txt","missingtnofcorrectfilelist.txt");
  	sortfile("missingtnofcorrectfilelist.txt");
  

	filelist("tnoferrorfilelist.txt","fileT$$$$$$$$$$e");
	sortfile("tnoferrorfilelist.txt");
 	
	missingfileprocedure("tnolist.txt","tnoferrorfilelist.txt","missingtnoferrorfilelist.txt");
  	sortfile("missingtnoferrorfilelist.txt");
  

 	return 0;
}