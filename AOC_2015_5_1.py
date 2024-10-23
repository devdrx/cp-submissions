count = 0

with open('input.txt', 'r') as f:
    for line in f:
        line = line.strip()
        req1 = False
        for i in range(len(line)-1):
            pair = line[i:i+2]
            for j in range(i+2, len(line)-1):
                pair2 = line[j:j+2]
                if pair == pair2:
                    req1 = True
                    break
        req2 = any(line[i] == line[i+2] for i in range(len(line)-2))
        count += req1 and req2
        
print(count)