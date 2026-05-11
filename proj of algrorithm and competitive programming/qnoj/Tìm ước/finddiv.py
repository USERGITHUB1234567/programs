import sys

def max_power_in_factorial(n: int, p: int) -> int:
    ans = 0
    power = p
    while power <= n:
        ans += n // power
        # tránh overflow bằng cách kiểm tra trước khi nhân
        if power > n // p:
            break
        power *= p
    return ans

def main():
    data = list(map(int, sys.stdin.read().strip().split()))
    t = data[0]
    idx = 1
    out = []
    for _ in range(t):
        n = data[idx]; p = data[idx+1]; idx += 2
        out.append(str(max_power_in_factorial(n, p)))
    print("\n".join(out))

if __name__ == "__main__":
    main()
