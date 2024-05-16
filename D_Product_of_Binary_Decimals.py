for n in[*map(int,open(0))][1:]:
 for i in range(32,1,-1):
  i=int(f'{i:b}')
  while n%i<1:n//=i
 print('YNEOS'[n>1::2])