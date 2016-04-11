
if [ ! -d "$DIRECTORY/../tno" ]; then
	mkdir ../tno \;
fi

find ./ -type f -name "T*.txt" -exec mv {} ./../tno \;
if [ ! -d "$DIRECTORY/../files" ]; then
	mkdir ../files \;
	mkdir ../files/fcorrect \;
	mkdir ../files/ferror \;
fi

find ./ -type f -name "file*c.txt" -exec mv {} ./../files/fcorrect \;

find ./ -type f -name "file*e.txt" -exec mv {} ./../files/ferror \;

if [ ! -d "$DIRECTORY/../sfile" ]; then
	mkdir ../sfile \;
	mkdir ../sfile/scorrect \;
	mkdir ../sfile/serror \;
fi

find ./ -type f -name "s*c.txt" -exec mv {} ./../sfile/scorrect \;

find ./ -type f -name "s*e.txt" -exec mv {} ./../sfile/serror \;

find ./ -type f -name "tnoaudiolist.txt" -exec mv {} ./../ \;

find ./ -type f -name "tnolist.txt" -exec mv {} ./../ \;
