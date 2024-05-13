import random
import os

def generate_matrix(rows, cols):
    matrix = [[random.randint(1, 100) for _ in range(cols)] for _ in range(rows)]
    return matrix

def write_matrix_to_file(matrix, filename):
    with open(filename, 'w') as file:
        for row in matrix:
            file.write('\t'.join(map(str, row)) + '\n')

if __name__ == "__main__":
    rows = int(input("Введите количество строк: "))
    cols = int(input("Введите количество столбцов: "))

    filename = f"matrix_{rows}x{cols}.txt"
    count = 1
    while os.path.exists(filename):
        filename = f"matrix_{rows}x{cols}_{count}.txt"
        count += 1

    matrix = generate_matrix(rows, cols)
    write_matrix_to_file(matrix, filename)
    print(f"Матрица размером {rows}x{cols} записана в файл {filename}")
