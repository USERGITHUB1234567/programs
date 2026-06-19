import time
st=time.time()
for i in range(1000000000):
    continue
en=time.time()
ans=en-st
print(f"execution time:{ans:.4f}")