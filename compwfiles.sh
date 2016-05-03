rm ../words/compiledwcorrectedfiles.txt
cat ../words/wcorrect/* > compiledwcorrectedfiles.txt
mv compiledwcorrectedfiles.txt ../words/

echo "Wcorrected files are compiled"

rm ../words/compiledwerrorfiles.txt
cat ../words/werror/* > compiledwerrorfiles.txt
mv compiledwerrorfiles.txt ../words/

echo "Werror files are compiled"
