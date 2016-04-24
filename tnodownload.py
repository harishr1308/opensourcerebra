import requests
from requests.auth import HTTPBasicAuth
url = "http://www.dictate.it/bosi/sitetools/LetterManager/tools/getFilesComparison/getLetterData"
usr = 'Username'
pas = 'Password'
with open('todownloadtno.txt') as fp:
 for line in fp:
  name = line.rstrip('\n')
  print name
  key_value = {'instr':name}
  r = requests.post(url, auth=HTTPBasicAuth(usr, pas), data=key_value)
  fp = open(name+".txt","w")
  fp.write(r.text)
  fp.close()
  print r.text
