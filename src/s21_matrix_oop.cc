#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() noexcept : rows_(0), cols_(0), matrix(nullptr) {}

S21Matrix::S21Matrix(int rows, int cols) {
  if (rows <= 0 || cols <= 0) {
    throw "Not correct dimensions !";
  }

  rows_ = rows;
  cols_ = cols;

  matrix = new double *[rows_];
  for (int i = 0; i < rows_; i++) {
    matrix[i] = new double[cols_]{0};
  }
}

S21Matrix::S21Matrix(const S21Matrix &other) noexcept {
  rows_ = other.rows_;
  cols_ = other.cols_;
  CreateMatrix(rows_, cols_);

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix[i][j] = other.matrix[i][j];
    }
  }
}

S21Matrix::S21Matrix(S21Matrix &&other) noexcept
    : rows_(other.rows_), cols_(other.cols_), matrix(other.matrix) {
  other.rows_ = 0;
  other.cols_ = 0;
  other.matrix = nullptr;
}

S21Matrix::~S21Matrix() noexcept {
  for (int i = 0; i < rows_; i++) {
    delete[] matrix[i];
  }

  delete[] matrix;
}

bool S21Matrix::EqMatrix(const S21Matrix &other) const noexcept {
  bool status = true;

  if (CorrectCheck() && other.CorrectCheck() && rows_ == other.rows_ &&
      cols_ == other.cols_) {
    for (int i = 0; i < rows_ && status; i++) {
      for (int j = 0; j < cols_ && status; j++) {
        if (fabs(matrix[i][j] - other.matrix[i][j]) > S21_PRECISION)
          status = !status;
      }
    }
  } else {
    status = !status;
  }

  return status;
}

void S21Matrix::SumMatrix(const S21Matrix &other) {
  if (!CorrectCheck() || !other.CorrectCheck()) {
    throw "Not correct matrix !";
  }

  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw "Different dimension !";
  }

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix[i][j] += other.matrix[i][j];
    }
  }
}

void S21Matrix::SubMatrix(const S21Matrix &other) {
  if (!CorrectCheck() || !other.CorrectCheck()) {
    throw "Not correct matrix !";
  }

  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw "Different dimension !";
  }

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix[i][j] -= other.matrix[i][j];
    }
  }
}

void S21Matrix::MulNumber(const double num) {
  if (!CorrectCheck()) {
    throw "Not correct matrix !";
  }

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix[i][j] *= num;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix &other) {
  if (!CorrectCheck() || !other.CorrectCheck()) {
    throw "Not correct matrix !";
  }

  if (cols_ != other.rows_)
    throw "Not correct dimensions !";

  S21Matrix m = S21Matrix(rows_, other.cols_);

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < other.cols_; j++) {
      for (int k = 0; k < cols_; k++) {
        m.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
      }
    }
  }

  *this = std::move(m);
}

S21Matrix S21Matrix::Transpose() {
  if (!CorrectCheck()) {
    throw "Not correct matrix !";
  }

  S21Matrix result(cols_, rows_);

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      result.matrix[j][i] = this->matrix[i][j];
    }
  }

  return result;
}

S21Matrix S21Matrix::CalcComplements() {
  if (!CorrectCheck()) {
    throw "Not correct matrix !";
  }

  if (rows_ != cols_ || rows_ == 1)
    throw "Not right dimensions!";

  double det = 0;
  int flag;
  S21Matrix result = S21Matrix(rows_, cols_);
  S21Matrix m = S21Matrix(rows_ - 1, cols_ - 1);

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      New_matrix_without_row_column(*this, i, j, m);
      m.CalcDeterminant(&det);

      if ((i + j) % 2)
        flag = -1;
      else
        flag = 1;
      result.matrix[i][j] = flag * det;
    }
  }

  return result;
}

double S21Matrix::Determinant() {
  double result = 0;
  CalcDeterminant(&result);

  return result;
}

void S21Matrix::CalcDeterminant(double *result) {
  if (!CorrectCheck()) {
    throw "Not correct matrix !";
  }

  if (rows_ != cols_)
    throw "Not right dimensions!";

  double det = 0;
  if (rows_ == 1) {
    *result = matrix[0][0];
  } else if (rows_ == 2) {
    *result = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
  } else {
    int flag = 1;
    S21Matrix m = S21Matrix(rows_ - 1, cols_ - 1);
    for (int j = 0; j < cols_; j++) {
      New_matrix_without_row_column(*this, 0, j, m);
      m.CalcDeterminant(result);
      det += matrix[0][j] * (*result) * flag;
      flag *= -1;
    }

    *result = det;
  }
}

void S21Matrix::New_matrix_without_row_column(const S21Matrix &A, int ii,
                                              int jj, S21Matrix &new_matrix) {
  int m = -1, n;
  for (int i = 0; i < A.rows_; i++) {
    if (i != ii) {
      m++;
      n = 0;
      for (int j = 0; j < A.cols_; j++) {
        if (j != jj) {
          new_matrix.matrix[m][n++] = A.matrix[i][j];
        }
      }
    }
  }
}

S21Matrix S21Matrix::InverseMatrix() {
  double det = 0;
  CalcDeterminant(&det);

  if (rows_ != cols_ || rows_ == 1 || fabs(det) < S21_PRECISION)
    throw "Error inverse !";

  S21Matrix new_matrix = CalcComplements();
  S21Matrix result = new_matrix.Transpose();

  result.MulNumber(1 / det);

  return result;
}

S21Matrix S21Matrix::operator+(const S21Matrix &other) const {
  S21Matrix result = *this;
  result.SumMatrix(other);

  return result;
}

S21Matrix S21Matrix::operator-(const S21Matrix &other) const {
  S21Matrix result = *this;
  result.SubMatrix(other);

  return result;
}

S21Matrix S21Matrix::operator*(const S21Matrix &other) const {
  S21Matrix result = *this;
  result.MulMatrix(other);

  return result;
}

S21Matrix S21Matrix::operator*(double n) const {
  S21Matrix result = *this;
  result.MulNumber(n);

  return result;
}

S21Matrix operator*(double n, const S21Matrix &m) {
  S21Matrix result = m;
  result.MulNumber(n);

  return result;
}

bool S21Matrix::operator==(const S21Matrix &other) const noexcept {
  return EqMatrix(other);
}

S21Matrix &S21Matrix::operator=(const S21Matrix &other) noexcept {
  if (this != &other) {
    DeleteMatrix();
    CreateMatrix(other.rows_, other.cols_);

    rows_ = other.rows_;
    cols_ = other.cols_;

    for (int i = 0; i < other.rows_; i++) {
      for (int j = 0; j < other.cols_; j++) {
        matrix[i][j] = other.matrix[i][j];
      }
    }
  }
  return *this;
}

void S21Matrix::DeleteMatrix() {
  for (int i = 0; i < rows_; i++) {
    delete[] matrix[i];
  }

  delete[] matrix;
}

void S21Matrix::CreateMatrix(int row, int col) {
  matrix = new double *[row];
  for (int i = 0; i < row; i++) {
    matrix[i] = new double[col]{0};
  }
}

S21Matrix &S21Matrix::operator=(S21Matrix &&other) noexcept {
  if (this != &other) {
    DeleteMatrix();

    rows_ = other.rows_;
    cols_ = other.cols_;
    matrix = other.matrix;

    other.matrix = nullptr;
    other.rows_ = 0;
    other.cols_ = 0;
  }

  return *this;
}

S21Matrix S21Matrix::operator+=(const S21Matrix &other) {
  SumMatrix(other);
  return *this;
}

S21Matrix S21Matrix::operator-=(const S21Matrix &other) {
  SubMatrix(other);
  return *this;
}

S21Matrix S21Matrix::operator*=(const S21Matrix &other) {
  MulMatrix(other);
  return *this;
}

S21Matrix S21Matrix::operator*=(double n) {
  MulNumber(n);
  return *this;
}

double &S21Matrix::operator()(int i, int j) {
  if ((i >= 0 && i < rows_) && (j >= 0 && j < cols_))
    return matrix[i][j];

  throw "Index is out of bounds !";
}

int S21Matrix::GetRow() { return rows_; }

int S21Matrix::GetCol() { return cols_; }

void S21Matrix::SetRow(int n) {
  if (n <= 0)
    throw "Not correct dimension !";

  if (n != rows_) {
    S21Matrix m(n, cols_);

    int k = int(fmin(rows_, n));

    for (int i = 0; i < k; i++) {
      for (int j = 0; j < cols_; j++) {
        m(i, j) = matrix[i][j];
      }
    }

    *this = std::move(m);
  }
}

void S21Matrix::SetCol(int n) {
  if (n <= 0)
    throw "Not correct dimension !";

  if (n != cols_) {
    S21Matrix m(rows_, n);

    int k = int(fmin(cols_, n));

    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < k; j++) {
        m(i, j) = matrix[i][j];
      }
    }

    *this = std::move(m);
  }
}

bool S21Matrix::CorrectCheck() const {
  bool status = true;

  if (matrix == nullptr) {
    status = false;
  } else if (cols_ <= 0 || rows_ <= 0) {
    status = false;
  } else {
    for (int i = 0; i < rows_ && status; i++) {
      if (matrix[i] == nullptr) {
        status = false;
      }
    }
  }

  return status;
}
