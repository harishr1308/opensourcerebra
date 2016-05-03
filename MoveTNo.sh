find ./ -type f -name "T*.txt" -exec mv {} ./../tno \;
echo "All t files are moved to ../tno"

find ./ -type f -name "w*c.txt" -exec mv {} ./../words/wcorrect \;
echo "All WordCorrected files are moved to ../words/wcorrect"
find ./ -type f -name "w*e.txt" -exec mv {} ./../words/werror \;
echo "All WordError files are moved to ../words/werror"

find ./ -type f -name "file*c.txt" -exec mv {} ./../files/fcorrect \;
echo "All FileCorrected files are moved to ../files/fcorrect"
find ./ -type f -name "file*e.txt" -exec mv {} ./../files/ferror \;
echo "All FileError files are moved to ../files/ferror"

find ./ -type f -name "s*c.txt" -exec mv {} ./../sfile/scorrect \;
echo "All SCorrected files are moved to ../sfile/scorrect"
find ./ -type f -name "s*e.txt" -exec mv {} ./../sfile/serror \;
echo "All SError files are moved to ../sfile/scorrect"

find ./ -type f -name "tnoaudiolist.txt" -exec mv {} ./../ \;
echo "All tnoaudiolist file is moved ../"
find ./ -type f -name "tnomissingaudiolist.txt" -exec mv {} ./../ \;
echo "All tnomissingaudiolist file is moved ../"

find ./ -type f -name "tnolist.txt" -exec mv {} ./../ \;
echo "All tnolist file is moved ../"
find ./ -type f -name "missingtnolist.txt" -exec mv {} ./../ \;
echo "All missingtnolist file is moved ../"


find ./ -type f -name "tnoscorrectfilelist.txt" -exec mv {} ./../ \;
echo "All tnoscorrectfilelist file is moved ../"
find ./ -type f -name "tnoserrorfilelist.txt" -exec mv {} ./../ \;
echo "All tnoserrorfilelist file is moved ../"

find ./ -type f -name "tnofcorrectfilelist.txt" -exec mv {} ./../ \;
echo "All tnofcorrectfilelist file is moved ../"
find ./ -type f -name "tnoferrorfilelist.txt" -exec mv {} ./../ \;
echo "All tnoferrorfilelist file is moved ../"

find ./ -type f -name "missingtnoscorrectfilelist.txt" -exec mv {} ./../ \;
echo "All missingtnoscorrectfilelist file is moved ../"
find ./ -type f -name "missingtnoserrorfilelist.txt" -exec mv {} ./../ \;
echo "All missingtnoserrorfilelist file is moved ../"

find ./ -type f -name "missingtnofcorrectfilelist.txt" -exec mv {} ./../ \;
echo "All missingtnofcorrectfilelist file is moved ../"
find ./ -type f -name "missingtnoferrorfilelist.txt" -exec mv {} ./../ \;
echo "All missingtnoferrorfilelist file is moved ../"



echo "Compiling S files"
chmod +x compsfiles.sh
./compsfiles.sh
