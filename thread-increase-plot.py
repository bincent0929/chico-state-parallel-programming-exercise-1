import matplotlib.pyplot as plt

runtimes = {1: 11.677,2:7.859,3:4.057,4:4.031}

x = list(runtimes.keys())
y = list(runtimes.values())

plt.plot(x, y, 'o-')
plt.xlabel('Number of Threads')
plt.ylabel('Runtime (seconds)')
plt.title('Runtime vs Number of Threads')
plt.grid(True)

plt.xticks(list(runtimes.keys()))

plt.savefig('runtime-threads-graph.svg')
