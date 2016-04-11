#$DIRECTORY = "html";
if ! [ -d "$DIRECTORY/../tno" ]
then
	mkdir ../tno
fi

find ./ -type f -name "T*.txt" -exec mv {} ./../tno \;
if ! [ -d "$DIRECTORY/../files" ]
then
	mkdir ../files 
	cd ../files
	mkdir fcorrect 
	mkdir ferror 
	cd ../html
fi

find ./ -type f -name "file*c.txt" -exec mv {} ./../files/fcorrect \;

find ./ -type f -name "file*e.txt" -exec mv {} ./../files/ferror \;

if ! [ -d "$DIRECTORY/../sfile" ]
then
	mkdir ../sfile 
	cd ../sfile
	mkdir scorrect 
	mkdir serror 
	cd ../html
fi

find ./ -type f -name "s*c.txt" -exec mv {} ./../sfile/scorrect \;

find ./ -type f -name "s*e.txt" -exec mv {} ./../sfile/serror \;

find ./ -type f -name "tnoaudiolist.txt" -exec mv {} ./../ \;

find ./ -type f -name "tnolist.txt" -exec mv {} ./../ \;

chmod +x compsfiles.sh
./compsfiles.sh
