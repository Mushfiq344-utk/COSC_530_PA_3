import matplotlib.pyplot as plt

# Data
sizes = [32768, 65536, 131072, 262144]
reg = [0.04683, 0.09250, 0.18700, 0.36950]
ur4 = [0.04633, 0.09233, 0.18483, 0.36933]
ae4 = [0.01150, 0.02333, 0.04733, 0.09433]
sse = [0.01150, 0.02300, 0.04650, 0.09266]

# Bar chart settings
x = range(len(sizes))
width = 0.22

plt.figure(figsize=(12, 6))

# Custom colors
c_reg = "#ff7f0e"   # orange
c_ur4 = "#2ca02c"   # green
c_ae4 = "#d62728"   # red
c_sse = "#1f77b4"   # blue

plt.bar([p - width*1.5 for p in x], reg, width, label='reg', color=c_reg)
plt.bar([p - width*0.5 for p in x], ur4, width, label='ur4', color=c_ur4)
plt.bar([p + width*0.5 for p in x], ae4, width, label='ae4', color=c_ae4)
plt.bar([p + width*1.5 for p in x], sse, width, label='sse', color=c_sse)

plt.xticks(x, sizes)
plt.xlabel("Array Size")
plt.ylabel("Avg Time (ms)")
plt.title("Comparing Performance of Different Types of Dot Product")
plt.legend()
plt.grid(axis='y', linestyle='--', alpha=0.6)

plt.tight_layout()
plt.savefig("dotprod_performance.pdf")
plt.show()