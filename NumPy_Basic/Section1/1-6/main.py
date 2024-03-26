import numpy as np

np.random.seed(1)
print("Random number generator 1\n")
arr1 = np.random.rand(10)
print(arr1)

print()

print("Random number generator 2\n")
np.random.seed(1)
arr2 = np.random.rand(20)
print(arr2)