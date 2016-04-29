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

chmod +x model_gen.sh
./model_gen.sh
