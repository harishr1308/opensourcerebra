import requests
from requests.auth import HTTPBasicAuth
url = "http://www.dictate.it/bosi/sitetools/LetterManager/tools/getFilesComparison/getLetterData"
usr = 'Cerebra_NM'
pas = 'C3r$br@555'
with open('todownloadtno.txt') as fp:
 for line in fp:
  name = line.rstrip('\n')
  print name
  key_value = {'instr':name}
  r = requests.post(url, auth=HTTPBasicAuth(usr, pas), data=key_value)
  fp = open(name+".txt","w")
  fp.write(r.text.encode('utf8','ignore'))
  fp.close()
  print r.text
