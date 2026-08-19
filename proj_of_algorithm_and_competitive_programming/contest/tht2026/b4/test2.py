import sys

# Tăng giới hạn đệ quy cho các cây có dạng đường thẳng
sys.setrecursionlimit(200000)

def solve():
    input_data = sys.stdin.read().split()
    if not input_data: return
    n = int(input_data[0])
    if n == 1:
        print(1)
        return
    
    adj = [[] for _ in range(n + 1)]
    for i in range(1, n):
        u = int(input_data[2*i - 1])
        v = int(input_data[2*i])
        adj[u].append(v)
        adj[v].append(u)
    
    parent = [-1] * (n + 1)
    depths = [0] * (n + 1)
    bfs_order = []
    
    # BFS để xác định cha, độ sâu và thứ tự duyệt
    queue = [1]
    parent[1] = 0
    head = 0
    while head < len(queue):
        u = queue[head]
        head += 1
        bfs_order.append(u)
        for v in adj[u]:
            if parent[v] == -1:
                parent[v] = u
                depths[v] = depths[u] + 1
                queue.append(v)
    
    post_order = bfs_order[::-1]
    parent[1] = -1
    max_d = max(depths)
    
    h = [0] * (n + 1)
    memo = {}

    def get_f(k):
        if k in memo: return memo[k]
        # Reset trạng thái h bằng độ sâu ban đầu
        for i in range(1, n + 1): h[i] = depths[i]
        
        count = 0
        for u in post_order:
            if h[u] == depths[u] + k:
                count += 1
                h[u] = -10**9 # Đã được bao phủ
            p = parent[u]
            if p != -1:
                if h[u] > h[p]: h[p] = h[u]
        
        if h[1] >= 0: count += 1
        memo[k] = count
        return count

    def compute_sum(L, R, fL, fR):
        if fL == fR:
            return (R - L + 1) * fL
        if L + 1 == R:
            return fL + fR
        mid = (L + R) // 2
        f_mid = get_f(mid)
        return compute_sum(L, mid, fL, f_mid) + compute_sum(mid + 1, R, f_mid, fR)

    # Tính tổng f(k) từ k=1 đến max_d
    res = compute_sum(1, max_d, get_f(1), get_f(max_d))
    # Với k > max_d, f(k) luôn bằng 1
    res += (n - max_d)
    
    print(res)

solve()