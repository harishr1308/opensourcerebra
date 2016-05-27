#include <fstream>
#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <dirent.h>
using namespace std;

int l;

#define SIZE_OF_TNO 11   //T1234567890

#define a textfile[l]
#define b textfile[l+1]
#define c textfile[l+2]
#define d textfile[l+3]
#define e textfile[l+4]
#define f textfile[l+5]
#define g textfile[l+6]
#define h textfile[l+7]
#define i textfile[l+8]
#define j textfile[l+9]
#define k textfile[l+10]

bool checkchar(char); //checks if the character passed is a lowercase alphabet or not
bool checkCHAR(char); //checks if the character passed is a uppercase alphabet or not
bool checkchari(char); // checks if the character passed is an alphabet or not
bool checknumber(char); //checks if the character passed is a number or not
bool stringequal(string ,string); // compares strings basically strcmp but just returns true or false
char uppercase(char); // converts lowercase alphabet to uppercase alphabet
char lowercase(char); // converts uppercase alphabet to lowercase alphabet
int skip(string); // returns string length to any string passed to it like this skip("hello") returns 5

bool conditionchecking(string textfile, string tocheck); 
// takes in two strings say "T1234567890" and "T$$$$$$$$$$" the function returns true saying that the two strings passed is the same
// "$" basically checks if its a number
// "# checks if its an alphabet
// the string passed tocheck the length of that string is what is being compared here
// if "T123456345635537357"  is textfile and tocheck is "T" the function returns true
// if "A boy rides a bike" is the textfile and tocheck is "#" the function returns true

bool conditionchecking( string textfile, int pos, string tocheck);
// similarly another parameter exists saying pos which basiscally stands for position
// "A boy aged 12 rides a bike", 11 , "$$"  returns true
// because the 11th and 12 character of the 1st string parameter are numbers

void filerenamereopennew(fstream &file,string oldname,string newname); 
//closes the file renames it and reopens the new file
// say temp.txt is to be renamed as "tfile.txt"
// file.close happpens
// rename happens
// and tfile.txt is opened in append mode (you can continue editing where you left off)


void filerenamereopenold(fstream &file,string oldname,string newname);
//closes the file renames it and reopens the new file
// say temp.txt is to be renamed as "tfile.txt"
// file.close happpens
// rename happens
// and temp.txt is opened in trunc mode - new file (empty file)
// creates a new temp.txt
// the old temp.txt is renamed


void filerename(fstream &file,string oldname,string newname);
// renames the file and closes everything no reopening scene


string returnfilecontents(fstream &file);
// opens a file and returns a  string which has all the contents of the file

vector<string> openfilenametype(string tocheck,string path);
// this opens file name which follows a particular naming convention as well as any named file
// for eg if you pass "$" it opens all files which starts with a number
// like 1.txt 2.txt etc
// if you pass # it opens evrry file which starts with an alphabet
// if you pass T$$$$$$$$$$# we actually have a file like this eg T1234567890e.txt
// now for absolute comparison we can just pass the name of the file like "output.txt"
// code will break only when there is a # or a $ in the name of the file
// path doesnt work
// doesnt open the respective directory for some strange reason
// yes it works only in the directoty where the code exists basically "." this is given as default


string GetTnoFromString(string tno);
// get tno from string returns that part of the string
// which matches the convention string passed to it
// for eg if you pass the filename it will return a tno
// it works only for TNos
// like wposT1234567899countc.txt
// it will find T in that string and then goes for the next 11 characters(T inclusive) and will return that string
// only in case of filenames


string GetTnoFromString(string tno,int pos);
// get tno from string returns that part of the string
// which matches the convention string passed to it
// for eg if you pass the filename it will return a tno
// it works only for TNos
// like wposT1234567899countc.txt and you pass a position say 5
// it will find T in that string and then goes for the next 11 characters(T inclusive) and will return that string
// now if i pass the entire textfile to it ?
// used only in case of content of files



string GetTnoSuffixFromString(string tno);
// gets the suffix of filename
// i.e like wposT1234567899countc.txt 
// returns countc.txt


string GetTnoAndSuffixFromString(string temp);
// gets the suffix of filename
// i.e like wposT1234567899countc.txt 
// returns T1234567899countc.txt



void filelist(string filename,string filecheck);   // lists all the files
vector<string> uniquesort(vector<string> v ,int &nooflines);   // removes duplicate file names
vector<string> readingfilelinebyline(fstream &temp, int &nooflines);   // reads file line by line
vector<string> updatetnovector(fstream &tempfile,int &nooflines);   // returns a vector filled with tnos
void missingfile(fstream &temp,vector<string> &vtemp, vector<string> &ftemp); 
void missingfileprocedure(string filename, string filename1, string outputfile);
void writingfiles(string name,vector<string> &v, int &nooflines);
void sortfile(string filename);
void tnosplit(string filenamingconvention,string tnonamingconvention, string endtno);
void returnaudiolinks(string filenamingconvention, string urltype, string endurl);
void removetags(string filenamingconvention, string endfile);
void wordcheck(string outputfilenamingconvention);
void getwords(string filenamingconvention, string outputfilenamingconvention);
void sfilecheck(string outputfilenamingconvention);
void sfilecheck_blank(string outputfilenamingconvention, string blank);
void sfilecheck_space(string outputfilenamingconvention);
void putsfiletags(string filenamingconvention, string outputfilenamingconvention);

	
#include "filefunctions.h"
#include "procedures.h"