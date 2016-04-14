rm ../sfile/compiledscorrectedfiles.txt
cat ../sfile/scorrect/* > compiledscorrectedfiles.txt
mv compiledscorrectedfiles.txt ../sfile/
echo "S files are compiled"
echo "Compiling F files"
chmod +x compffiles.sh
./compffiles.sh
