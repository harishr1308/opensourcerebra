rm ../files/compiledfcorrectedfiles.txt
cat ../files/fcorrect/* > compiledfcorrectedfiles.txt
mv compiledfcorrectedfiles.txt ../files/

echo "Fcorrected files are compiled"
chmod +x compwfiles.sh
./compwfiles.sh
