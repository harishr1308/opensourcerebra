import language_check
import glob   
import os

def replace_last(source_string, replace_what, replace_with):
    head, sep, tail = source_string.rpartition(replace_what)
    return head + replace_with + tail

tool = language_check.LanguageTool('en-UK')
path = './../files/ferror/*.txt'   
files=glob.glob(path)
 
for file in files:     
	f1=open(file, 'r')  
	filename = os.path.basename(file)
	outputpath = './../files/flangcorr/'
	filename = replace_last(filename,'e','l')
	text = f1.read()
	print filename
	text.encode('utf8','ignore')
	#text.encode('\"', 'ignore')
	matches = tool.check(text)
	print len(matches)
	# q = len(matches)
	# for x in range(0,q):
	# 	matches[x].fromy, matches[x].fromx
	# 	print (matches[x])
	# print (matches[1])
	outputpath += filename
	temp = language_check.correct(text,matches);
	f2 = open(outputpath,'w')
	f2.write(temp);
	f2.close();
	f1.close();
