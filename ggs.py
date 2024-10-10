n = 1000

isPrime = [True for i in range(n+1)]

prime = set()
res = []
i =2 
while (i*i <= n ):
    if isPrime[i] == True:
        for j in range( i*i, n+1 , i):
            isPrime[j] = False
    i+= 1

for num in range( 2, n+1):
    if isPrime[num] == True:
        # print(num)
        prime.add(num)
print(prime)
sorted_prime_list = sorted(prime)
print(sorted_prime_list)
for nnumber in sorted_prime_list:
    req = n- nnumber
    if( nnumber *2 > n) :
        break
    if req in sorted_prime_list:
        res.append([nnumber, req])

print(res)