import numpy as np

arr = np.array([[1], [2], [3]])
print(arr)
print()
tpl = (1, 2, 3,)
arr1 = np.array(tpl)
print(arr1)
print()

arr2 = np.array([[1, 2, 3], [4, 5, 6]])
print(arr2)
print()

lst = [[[1, 2, 3], [4, 5, 6]],
[[7, 8, 9], [10, 11, 12]]]
arr3 = np.array(lst)
print(arr3)
print()

# shape
print(arr1.shape)
print(arr2.shape)
print(arr3.shape)
print()

# ndim
print(arr1.ndim)
print(arr2.ndim)
print(arr3.ndim)
print()

# size
print(arr1.size)
print(arr2.size)
print(arr3.size)