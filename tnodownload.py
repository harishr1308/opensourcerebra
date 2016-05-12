import requests
from requests.auth import HTTPBasicAuth
url = ''
usr = ""
pas = ''
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
			wp = open(str(filecount)+".txt","w")
			wp.write(r.text.encode('utf8','ignore'))
			wp.close()
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
	wp = open(str(filecount)+".txt","w")
	wp.write(r.text.encode('utf8','ignore'))
	wp.close()
	count = 0
	print filecount,"is created"
	filecount+=1
	name = ""
 # print r.text
