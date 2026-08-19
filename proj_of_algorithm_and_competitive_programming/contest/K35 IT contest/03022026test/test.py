n,q= map(int, input().split())
a = list (map(float,input().split()))
a.sort(reverse=True)
q = float ( 100-q)/100.0
ans = 0.0
for i in range (2,n,3):
    if a [i-1] + a[i-2] < (a[i] + a[i-1] + a[i-2])* q:
        ans += a[i-1] + a[i-2]
    else:
        ans += (a[i-1] + a[i-2])*q
        i -= 1
    if i +3 > n -1:
        if i + 1 <= n -1:
            ans += a[i+1] * q
        if i + 2 <= n - 1:
            ans += a[i+2] * q
print(int(ans))