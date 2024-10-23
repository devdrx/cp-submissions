import hashlib

key = 'ckczppom'

i = 1

while True:
    s = key + str(i)
    hash = hashlib.md5(s.encode()).hexdigest()
    if hash[:6] == '000000':
        break
    i += 1

print(i)