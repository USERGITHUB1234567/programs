n, s = map(int, input().split())
a = [0] + list(map(int, input().split()))
# nhân đôi mảng (không nhân thêm phần tử giả 0)
a = a + a[1:]

l = 1
r = 0
total = 0
INF = 10**18
ans = INF

# r tăng dần, dùng chỉ số 1-based như code gốc
while r < len(a) - 1:
    r += 1
    total += a[r]

    # đảm bảo cửa sổ không dài hơn n (vì mảng vòng)
    while r - l + 1 > n:
        total -= a[l]
        l += 1

    # thu nhỏ trái nếu vẫn thỏa >= s
    while l <= r and total - a[l] >= s:
        total -= a[l]
        l += 1

    if total >= s:
        ans = min(ans, r - l + 1)

if ans == INF:
    print(-1)
else:
    print(ans)
