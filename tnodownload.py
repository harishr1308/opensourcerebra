import requests
from requests.auth import HTTPBasicAuth
url = "URL"
usr = 'Username'
pas = 'Password'
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