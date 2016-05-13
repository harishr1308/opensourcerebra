//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//YEAR: 2015-16
//AUTHOR: Cerebra Interns
//PROGRAM: Checks for <p> & </p> tags around "originalcontent" & "content" data
//NOTES: 
//1.Make a directory called "tno" and put all your T[tno].txt files there!
//2.Send the tnolist.txt file as a commandline argument to this program. (Does not internally read the filenames because flexibility in feeding filenames to the program is necessary).
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

static const size_t npos = -1;

//Handles all kinds of line endings (\n, \r, \r\n):
istream& safeGetline(istream& is, string& t)
{
    t.clear();

    // The characters in the stream are read one-by-one using a std::streambuf.
    // That is faster than reading them one-by-one using the std::istream.
    // Code that uses streambuf this way must be guarded by a sentry object.

    istream::sentry se(is, true);
    streambuf* sb = is.rdbuf();

    for(;;) {
        int c = sb->sbumpc();
        switch (c) {
        case '\n':
            return is;
        case '\r':
            if(sb->sgetc() == '\n')
                sb->sbumpc();
            return is;
        case EOF:
            // Also handle the case when the last line has no line ending
            if(t.empty())
                is.setstate(ios::eofbit);
            return is;
        default:
            t += (char)c;
        }
    }
}

int main(int argc, char *argv[]) {
	if(argc != 2){
		cout << "Required: \n1. Make a DIR called \"tno\" and put all your files there!\n2. Pass a tnolist.txt file as a command line argument" << endl;
	}
	else{
    	int number_of_lines = 0;
		string line;

//Takes in the argv[1], the first command line argument as the filename and opens it: 
		string filename = argv[1];
		ifstream myFile(filename.c_str());

//Counts the number of lines in the tnolist.txt file:
    	while (getline(myFile, line))
        	++number_of_lines;

//Prints the count of lines, i.e the total number of files to be checked:
    	cout << "Total number of files to be checked is... " << number_of_lines << endl;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Goes back to the beginning of the file:
    	myFile.clear();
    	myFile.seekg(0, ios::beg);

//Declaring & Initalizing a few important flags and variables:
        bool originalContentFlag = false, contentFlag = false;
        int strLength, result;
        string tempString;
        string ocString = ">originalcontent:<";
        string cString = ">content:<";
        string tString = "</table>";
    	string readLine, tnoPath;

//Reads each tno file mentioned in the tnolist.txt and operates on it:
    	while(getline(myFile, readLine)){
    		cout << "Adding <p> tags around \"OriginalContent\" & \"Content\" in file... " << readLine << ".txt" << endl;

    		tnoPath = "tno/" + readLine + ".txt";
    		ifstream tnoFile(tnoPath.c_str()); //Currently opened tno file
            ofstream tempFile("tno/temp.txt", ios::app); //A temporary file to handle the insertion process

            originalContentFlag = false;
            contentFlag = false;
            number_of_lines = 0;
            line.empty();

//IMPORTANT: The following while loop is the most important code:
//1. Checks line after line for keywords: To see if "orginialcontent", "content" data is present!             
//2. When one of the following is encountered: "orginialcontent", "content" & "</table>", a corresponding <p> or </p> tag is added in its proximity.
//3. Keeps a count of the number of lines in the file to print it for verfication later.
            while(!safeGetline(tnoFile, line).eof()){
                size_t found = line.find(ocString);
                if(found != npos){
                    originalContentFlag = true;
                    strLength = line.length();
                    for(int i = 0; i < strLength - 18; i++){
                        tempString = line.substr(i, 18);
                        if(tempString == ocString){
                            line.insert(i+17, "<p>");
                            break;
                        }
                    }
                }

                found = line.find(cString);
                if(found != npos){
                    contentFlag = true;
                    strLength = line.length();
                    for(int i = 0; i < strLength - 10; i++){
                        tempString = line.substr(i, 10);
                        if(tempString == cString){
                            line.insert(i+1, "</p>");
                            line.insert(i+13, "<p>");
                            break;
                        }
                    }
                }

                found = line.find(tString);
                if(found != npos){
                    strLength = line.length();
                    for(int i = 0; i <= strLength - 8; i++){
                        tempString = line.substr(i, 8);
                        if(tempString == tString){
                            line.insert(i, "</p>");
                            break;
                        }
                    }
                }

                tempFile << line << "\n";
                ++number_of_lines;
            }

//Printing some messages to check the status of everything:
            cout << "Number of lines in the file... " << number_of_lines << endl;
            if(originalContentFlag == true)
                cout << "\"orginialcontent\" data found!" << endl;
            else
                cout << "\"orginialcontent\" data not found!" << endl;

            if(contentFlag == true)
                cout << "\"content\" data found!" << endl;
            else
                cout << "\"content\" data not found!" << endl;

            if(remove(tnoPath.c_str()) != 0)
                    perror("ERROR: Temporary file could not be deleted!");
            else
                    puts("SUCCESS: Temporary file deleted!");

            result = rename("tno/temp.txt", tnoPath.c_str());
            if (result == 0)
                puts ("SUCCESS: Temporary file renamed!");
            else
                perror("ERROR: Temporary file not renamed!");
    	}    
	}
return 0;
}