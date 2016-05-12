import requests
from requests.auth import HTTPBasicAuth
url = 'http://www.dictate.it/bosi/sitetools/LetterManager/tools/getLetterData'
usr = "Cerebra_NM"
pas = 'C3r$br@555'
filecount = 1;
filenocount = 0;
name = ""
with open('todownloadtno.txt') as fp:
	count = 0
	for line in fp:
		filenocount +=1
		name += line.rstrip('\n')
		print filenocount , line.rstrip('\n')
		if count>50:
			key_value = {'instr':name}
			r = requests.post(url, auth=HTTPBasicAuth(usr, pas), data=key_value)
			fp = open(str(filecount)+".txt","w")
			fp.write(r.text.encode('utf8','ignore'))
			fp.close()
			count = 0
			print filecount,"is created"
			filecount+=1
			name = ""
		else:
			count+=1
			name+=','
	if name!="":
		key_value = {'instr':name}
			r = requests.post(url, auth=HTTPBasicAuth(usr, pas), data=key_value)
			fp = open(str(filecount)+".txt","w")
			fp.write(r.text.encode('utf8','ignore'))
			fp.close()
			count = 0
			print filecount,"is created"
			filecount+=1
			name = ""
 # print r.text
