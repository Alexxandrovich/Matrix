# Matrix

Реализация библиотеки для работы с матрицами.

## Операции над матрицами

В данной библиотеки реализованы следующие операции:
| Операция    | Описание   | Исключительные ситуации |
| ----------- | ----------- | ----------- |
| `bool EqMatrix(const Matrix& other)` | Проверяет матрицы на равенство между собой |  |
| `void SumMatrix(const Matrix& other)` | Прибавляет вторую матрицы к текущей | различная размерность матриц |
| `void SubMatrix(const Matrix& other)` | Вычитает из текущей матрицы другую | различная размерность матриц |
| `void MulNumber(const double num)` | Умножает текущую матрицу на число |  |
| `void MulMatrix(const Matrix& other)` | Умножает текущую матрицу на вторую | число столбцов первой матрицы не равно числу строк второй матрицы |
| `Matrix Transpose()` | Создает новую транспонированную матрицу из текущей и возвращает ее |  |
| `Matrix CalcComplements()` | Вычисляет матрицу алгебраических дополнений текущей матрицы и возвращает ее | матрица не является квадратной |
| `double Determinant()` | Вычисляет и возвращает определитель текущей матрицы | матрица не является квадратной |
| `Matrix InverseMatrix()` | Вычисляет и возвращает обратную матрицу | определитель матрицы равен 0 |

Помимо реализации данных операций реализованы кострукторы и деструктор:
| Метод    | Описание   |
| ----------- | ----------- |
| `Matrix()` | Базовый конструктор, инициализирующий матрицу некоторой заранее заданной размерностью |  
| `Matrix(int rows, int cols)` | Параметризированный конструктор с количеством строк и столбцов | 
| `Matrix(const Matrix& other)` | Конструктор копирования |
| `Matrix(Matrix&& other)` | Конструктор переноса |
| `~Matrix()` | Деструктор |

А также перегружены следующие операторы:
| Оператор    | Описание   | Исключительные ситуации |
| ----------- | ----------- | ----------- |
| `+`      | Сложение двух матриц  | различная размерность матриц |
| `-`   | Вычитание одной матрицы из другой | различная размерность матриц |
| `*`  | Умножение матриц и умножение матрицы на число | число столбцов первой матрицы не равно числу строк второй матрицы |
| `==`  | Проверка на равенство матриц (`EqMatrix`) | |
| `=`  | Присвоение матрице значений другой матрицы | |
| `+=`  | Присвоение сложения (`SumMatrix`)   | различная размерность матриц |
| `-=`  | Присвоение разности (`SubMatrix`) | различная размерность матриц |
| `*=`  | Присвоение умножения (`MulMatrix`/`MulNumber`) | число столбцов первой матрицы не равно числу строк второй матрицы |
| `(int i, int j)`  | Индексация по элементам матрицы (строка, колонка) | индекс за пределами матрицы |


