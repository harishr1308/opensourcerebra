mkdir files
cd files
mkdir fcorrect
mkdir ferror
> compiledfcorrectedfiles.txt
cd ..
mkdir sfile
cd sfile
mkdir scorrect
mkdir serror
> compiledscorrectedfiles.txt
cd ..
mkdir tno
mkdir html
cd html
g++ tnosplit.cpp
./a.out

echo "Welcome! Ganesh's area of running code starts..."
echo "Creating the basic language model..."
ngt -i=../sfile/compiledscorrectedfiles.txt -n=7 -o=train.www
tlm -tr=train.www -n=7 -lm=LinearWittenBell -o=train.arpa
rm train.www
cd ..
mkdir models
cd html
echo "Moving the language model (ARPA) into /models"
mv train.arpa ../models
echo "Basic language model done."

echo "POStagging the compiledfcorrectedfiles.txt..."
cd ..
cd files
mv compiledfcorrectedfiles.txt ../stanford-postagger/
cd ..
cd stanford-postagger
./stanford-postagger.sh models/english-left3words-distsim.tagger compiledfcorrectedfiles.txt > poscompiledfcorrectedfiles.txt
mv compiledfcorrectedfiles.txt ../files/
mv poscompiledfcorrectedfiles.txt ../files/

echo "Creating the POStagged language model..."
cd ..
cd files
ngt -i=poscompiledfcorrectedfiles.txt -n=7 -o=train.www
tlm -tr=train.www -n=7 -lm=LinearWittenBell -o=postaggedtrain.arpa
rm train.www
rm poscompiledfcorrectedfiles.txt
echo "Moving the language model (ARPA) into /models"
mv postaggedtrain.arpa ../models/
cd ..
cd html
echo "POStagged language model done."



