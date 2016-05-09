import glob   
import os
from collections import Counter
def replace_last(source_string, replace_what, replace_with):
    head, sep, tail = source_string.rpartition(replace_what)
    return head + replace_with + tail


def count(input_path,output_path,replace_with,replace_what):
	files=glob.glob(input_path)
	 
	for file in files:     
		wordlist = []
		#f1=open(file, 'r')
		with open(file) as f1:
			filename = os.path.basename(file)
			print filename , "is open"
			filename = replace_last(filename,replace_with,replace_what)
			outputpath = output_path
			for line in f1:
				word = line.rstrip('\n')
				wordlist.append(word)
			wordcountlist = Counter(wordlist)
			# print wordcountlist
			outputpath += filename
			f2 = open(outputpath,'w')
			# f2.write(wordcountlist);
			wordline = []
			for item,value in wordcountlist.iteritems():
				strin = item + '$$$' + str(value) + '\n'
				wordline.append(strin)
			wordline.sort()
			for wordc in wordline:
				f2.write(wordc);
			f2.close();
			f1.close();

count('./../words/werror/*.txt','./../words/werrorcount/','e','ecount')
count('./../words/wcorrect/*.txt','./../words/wcorrectcount/','c','ccount')
