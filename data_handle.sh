cd ..
mkdir files
cd files
mkdir fcorrect
mkdir ferror
mkdir flangerr
> compiledfcorrectedfiles.txt
cd ..
mkdir sfile
cd sfile
mkdir scorrect
mkdir serror
> compiledscorrectedfiles.txt
cd ..
mkdir tno
mkdir words
cd words
mkdir wcorrect
mkdir werror
mkdir wcorrectcount
mkdir werrorcount
> compiledwcorrectedfiles.txt
> compiledwerrorfiles.txt
> compiledwcorrectedcount.txt
> compiledwerrorcount.txt

cd ..
cd opensourcerebra	
ulimit unlimited
# python tnodownload.py #if you need to download transcripts uncomment this line and make changes to the URL, username and password accordingly
 g++ tnosplit.cpp #if your file contains multiple transcripts in it
 ./a.out


# g++ tnolisting.cpp
# ./a.out
# g++ tnolistsort.cpp
# ./a.out
g++ tnoaudio.cpp
./a.out
g++ tag.cpp
./a.out
g++ words.cpp
./a.out
g++ wcheck.cpp
./a.out
g++ sfile.cpp
./a.out
g++ scheck.cpp
./a.out
g++ scheck_blank.cpp
./a.out
g++ scheck_space.cpp
./a.out
# g++ tnosfilelisting.cpp
# ./a.out
# g++ tnoscfilelistsort.cpp
# ./a.out
# g++ tnosefilelistsort.cpp
# ./a.out
# g++ tnoffilelisting.cpp
# ./a.out
g++ filelisting.cpp
./a.out
g++ tnofilessort.cpp # new file where we pass only the name of the file and it sorts it using the new header file created
./a.out

g++ findingmissingfiles.cpp
./a.out
# g++ tnofcfilelistsort.cpp
# ./a.out
# g++ tnofefilelistsort.cpp
# ./a.out
g++ missingfilessort.cpp # new file where we pass only the name of the file and it sorts it using the new header file created
./a.out
# g++ missingfcfilessorting.cpp
# ./a.out
# g++ missingfefilessorting.cpp
# ./a.out
# g++ missingscfilessorting.cpp
# ./a.out
# g++ missingsefilessorting.cpp
# ./a.out
# g++ missingtnofilessorting.cpp
# ./a.out



chmod +x MoveTNo.sh
./MoveTNo.sh

python filecheck.py
python wcount.py

cd ..


#chmod +x model_gen.sh
#./model_gen.sh
