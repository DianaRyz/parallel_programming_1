import numpy as np


def verify(filename1, filename2, filenameres):
    matrix1 = np.loadtxt(filename1)
    matrix2 = np.loadtxt(filename2)
    result = np.loadtxt(filenameres)

    result_python = np.dot(matrix1, matrix2)

    if np.array_equal(result_python, result):
        print(f'Результаты совпадают!')
    else:
        print(f'Результаты не совпадают!')

if __name__ == "__main__":
    sizes = [100, 200, 400, 600, 800, 1000]
    for i in sizes:
        print(f"Размер {i}: ")
        verify(f"matrix_{i}x{i}.txt", f"matrix_{i}x{i}_1.txt", f"D:/parallel programming/result/res_{i}.txt")
    