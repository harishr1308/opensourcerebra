#include "filelisting.h"

int main()
{
	filelist("tnolist.txt","T");
	filelist("tnofcorrectfilelist.txt","fileT$$$$$$$$$$c");
	filelist("tnoferrorfilelist.txt","fileT$$$$$$$$$$e");
	filelist("tnoscorrectfilelist.txt","sT$$$$$$$$$$c");
	filelist("tnoserrorfilelist.txt","sT$$$$$$$$$$e");
}