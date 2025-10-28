import matplotlib.pyplot as plt

matrix_sizes = [4, 8, 16, 64, 256, 512, 1024]
iterative = [0.000006, 0.000016, 0.000037, 0.001517, 0.079521, 0.569056, 4.286127]
recursive = [0.000005, 0.000013, 0.000080, 0.001946, 0.135039, 0.973545, 7.744055]
strassen = [0.000093, 0.000109, 0.000762, 0.026786, 0.859512, 5.949624, 41.652202]

plt.figure(figsize=(8,5))
plt.plot(matrix_sizes, iterative, 'r-o', label="Iterative")
plt.plot(matrix_sizes, recursive, 'g-o', label="Recursive")
plt.plot(matrix_sizes, strassen, 'b-o', label="Strassen")

plt.title("Matrix Multiplication Performance Comparison")
plt.xlabel("Matrix Size (n × n)")
plt.ylabel("Execution Time (seconds)")
plt.legend()
plt.grid(True)
plt.show()
