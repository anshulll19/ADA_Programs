import matplotlib.pyplot as plt

n = [3, 4, 5]
fractional = [0.000001, 0.000002, 0.000003]  # Example times
zero_one = [0.000004, 0.000006, 0.000008]

plt.figure(figsize=(8,5))
plt.plot(n, fractional, 'b-o', label="Fractional Knapsack (Greedy)")
plt.plot(n, zero_one, 'r-o', label="0/1 Knapsack (Dynamic Programming)")

plt.title("Fractional vs 0/1 Knapsack Performance")
plt.xlabel("Number of Items (n)")
plt.ylabel("Execution Time (seconds)")
plt.legend()
plt.grid(True)
plt.show()
