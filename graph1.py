import matplotlib.pyplot as plt

# Input sizes (example)
n = [100, 200, 400, 800, 1600]

# Example times (in seconds, replace with your measured data)
bubble = [0.002, 0.009, 0.036, 0.145, 0.580]
selection = [0.0018, 0.008, 0.032, 0.128, 0.510]
insertion = [0.001, 0.005, 0.020, 0.081, 0.324]
merge = [0.0005, 0.001, 0.0025, 0.0055, 0.011]
quick = [0.0004, 0.0009, 0.002, 0.004, 0.009]

plt.figure(figsize=(8,5))
plt.plot(n, bubble, 'r-o', label="Bubble Sort")
plt.plot(n, selection, 'g-o', label="Selection Sort")
plt.plot(n, insertion, 'b-o', label="Insertion Sort")
plt.plot(n, merge, 'm-o', label="Merge Sort")
plt.plot(n, quick, 'c-o', label="Quick Sort")

plt.title("Sorting Algorithm Performance Comparison")
plt.xlabel("Number of Elements (n)")
plt.ylabel("Execution Time (seconds)")
plt.legend()
plt.grid(True)
plt.show()
