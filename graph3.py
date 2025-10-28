import matplotlib.pyplot as plt

n = [2, 5, 10, 20, 50]
recursive = [0.000007, 0.000007, 0.000009, 0.000118, 109.95]
iterative = [0.000008, 0.000007, 0.000006, 0.000007, 0.000008]
memo = [0.000007, 0.000004, 0.000008, 0.000006, 0.000007]
bottom_up = [0.000005, 0.000005, 0.000008, 0.000007, 0.000005]

plt.figure(figsize=(8,5))
plt.plot(n, recursive, 'r-o', label="Recursive")
plt.plot(n, iterative, 'g-o', label="Iterative")
plt.plot(n, memo, 'b-o', label="Memoization (Top-Down)")
plt.plot(n, bottom_up, 'm-o', label="Bottom-Up DP")

plt.title("Fibonacci Method Execution Time Comparison")
plt.xlabel("n (Fibonacci Term)")
plt.ylabel("Execution Time (seconds)")
plt.yscale("log")  # Because recursive grows exponentially
plt.legend()
plt.grid(True)
plt.show()
