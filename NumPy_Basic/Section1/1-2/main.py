import numpy as np

arr1 = np.array([1, 2, 3, 4, 5], dtype=float)
print(arr1, arr1.dtype)

arr2 = np.array([1.1, 2.2, 3.3, 4.4, 5.5], dtype=int)
print(arr2, arr2.dtype)

arr3 = np.array([1, 2.2, 3, 4.5, 6], dtype=int)
print(arr3, arr3.dtype)

arr4 = np.array([1, 2, 3, 4, 5])
print(arr4, arr4.dtype)
arr4 = arr4.astype(np.float32)
print(arr4, arr4.dtype)

arr5 = np.array([[1, 2], [3.3, "4.4"]])
print(arr5, arr5.dtype)
arr5 = arr5.astype(np.float32)
print(arr5, arr5.dtype)
