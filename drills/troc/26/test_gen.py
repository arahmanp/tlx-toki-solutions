import sys
n = m = 199
miss = (1, 2)   # ganti ke (1, 2) untuk kasus kedua
print(n, m)
for i in range(1, n+1):
    print(*[-1 if (i,j)==miss else 10**9 for j in range(1, m+1)])
