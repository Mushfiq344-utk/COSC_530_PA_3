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

plt.bar([p - width*1.5 for p in x], reg, width, label='reg')
plt.bar([p - width*0.5 for p in x], ur4, width, label='ur4')
plt.bar([p + width*0.5 for p in x], ae4, width, label='ae4')
plt.bar([p + width*1.5 for p in x], sse, width, label='sse')

plt.xticks(x, sizes)
plt.xlabel("Array Size (N)")
plt.ylabel("Average Execution Time (ms)")
plt.title("Dot Product Performance Comparison")
plt.legend()
plt.grid(axis='y', linestyle='--', alpha=0.6)

# Save PDF
plt.tight_layout()
plt.savefig("dotprod_performance.pdf")

# Show the graph
plt.show()
