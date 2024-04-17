#ifndef S21_MATRIX_OOP_H
#define S21_MATRIX_OOP_H

#define S21_PRECISION 1e-10
#include <cmath>
#include <iostream>

class S21Matrix {
public:
  S21Matrix() noexcept;
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix &other) noexcept;
  S21Matrix(S21Matrix &&other) noexcept;
  ~S21Matrix() noexcept;

  bool EqMatrix(const S21Matrix &other) const noexcept;
  void SumMatrix(const S21Matrix &other);
  void SubMatrix(const S21Matrix &other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix &other);
  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();

  S21Matrix operator+(const S21Matrix &other) const;
  S21Matrix operator-(const S21Matrix &other) const;
  S21Matrix operator*(const S21Matrix &other) const;
  S21Matrix operator*(double n) const;
  friend S21Matrix operator*(double n, const S21Matrix &m);
  bool operator==(const S21Matrix &other) const noexcept;
  S21Matrix &operator=(const S21Matrix &other) noexcept;
  S21Matrix &operator=(S21Matrix &&other) noexcept;
  S21Matrix operator+=(const S21Matrix &other);
  S21Matrix operator-=(const S21Matrix &other);
  S21Matrix operator*=(const S21Matrix &other);
  S21Matrix operator*=(double n);
  double &operator()(int i, int j);

  int GetRow();
  int GetCol();

  void SetRow(int n);
  void SetCol(int n);

private:
  int rows_, cols_;
  double **matrix;
  void New_matrix_without_row_column(const S21Matrix &A, int ii, int jj,
                                     S21Matrix &new_matrix);
  void DeleteMatrix();
  void CreateMatrix(int row, int col);
  void CalcDeterminant(double *det);
  bool CorrectCheck() const;
};

#endif
