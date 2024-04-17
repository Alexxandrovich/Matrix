#include "s21_googletest.h"

TEST(EqMatrix, test1) {
  S21Matrix A(3, 2);
  S21Matrix B(3, 2);

  A(0, 0) = 1.0;
  A(0, 1) = -4231.3245;
  A(1, 0) = 5323.09;
  A(1, 1) = 54325.89;
  A(2, 0) = 0;
  A(2, 1) = -0.12355659;

  B(0, 0) = 1.0;
  B(0, 1) = -4231.3245;
  B(1, 0) = 5323.09;
  B(1, 1) = 54325.89;
  B(2, 0) = 0;
  B(2, 1) = -0.12355659;

  ASSERT_TRUE(A.EqMatrix(B));
}

TEST(EqMatrix, test2) {
  S21Matrix A(3, 2);

  A(0, 0) = 1.0;
  A(0, 1) = -4231.3245;
  A(1, 0) = 5323.09;
  A(1, 1) = 54325.89;
  A(2, 0) = 0;
  A(2, 1) = -0.12355659;

  S21Matrix B = A;

  ASSERT_TRUE(A.EqMatrix(B));
}

TEST(EqMatrix, test3) {
  S21Matrix A(3, 2);
  S21Matrix B(2, 3);

  A(0, 0) = 1.0;
  A(0, 1) = -4231.3245;
  A(1, 0) = 5323.09;
  A(1, 1) = 54325.89;
  A(2, 0) = 0;
  A(2, 1) = -0.12355659;

  B(0, 0) = 1.0;
  B(0, 1) = 4231.3245;
  B(0, 2) = 5323.09;
  B(1, 0) = 54325.89;
  B(1, 1) = 0;
  B(1, 2) = -0.12355659;

  ASSERT_FALSE(A.EqMatrix(B));
}

TEST(EqMatrix, test4) {
  S21Matrix A(1, 1);
  S21Matrix B = A;

  A(0, 0) = 1.0;
  B(0, 0) = 1.0;

  ASSERT_TRUE(A.EqMatrix(B));
}

TEST(EqMatrix, test5) {
  S21Matrix A(2, 2);
  S21Matrix B;

  A(0, 0) = 1.0;
  A(0, 1) = -4231.3245;
  A(1, 0) = 5323.09;
  A(1, 1) = 54325.89;

  B = A;

  ASSERT_TRUE(A.EqMatrix(B));
}

TEST(SumMatrix, test1) {
  S21Matrix A(3, 2);
  S21Matrix B(3, 2);

  A(0, 0) = -1.0;
  A(0, 1) = 4231.3245;
  A(1, 0) = -5323.09;
  A(1, 1) = -54325.89;
  A(2, 0) = 0;
  A(2, 1) = 0.12355659;

  B(0, 0) = 1.0;
  B(0, 1) = -4231.3245;
  B(1, 0) = 5323.09;
  B(1, 1) = 54325.89;
  B(2, 0) = 0;
  B(2, 1) = -0.12355659;

  A.SumMatrix(B);

  ASSERT_DOUBLE_EQ(0, A(0, 0));
  ASSERT_DOUBLE_EQ(0, A(0, 1));
  ASSERT_DOUBLE_EQ(0, A(1, 0));
  ASSERT_DOUBLE_EQ(0, A(1, 1));
  ASSERT_DOUBLE_EQ(0, A(2, 0));
  ASSERT_DOUBLE_EQ(0, A(2, 1));
}

TEST(SumMatrix, test2) {
  S21Matrix A(2, 2);
  S21Matrix B(2, 2);

  A(0, 0) = -1.3;
  A(0, 1) = 4;
  A(1, 0) = 0.53;
  A(1, 1) = 9.87;

  B(0, 0) = 1;
  B(0, 1) = 1;
  B(1, 0) = 1;
  B(1, 1) = 1;

  A.SumMatrix(B);

  ASSERT_DOUBLE_EQ(-0.3, A(0, 0));
  ASSERT_DOUBLE_EQ(5, A(0, 1));
  ASSERT_DOUBLE_EQ(1.53, A(1, 0));
  ASSERT_DOUBLE_EQ(10.87, A(1, 1));
}

TEST(SumMatrix, test3) {
  S21Matrix A(2, 2);
  S21Matrix B(3, 2);

  A(0, 0) = -1.3;
  A(0, 1) = 4;
  A(1, 0) = 0.53;
  A(1, 1) = 9.87;

  ASSERT_ANY_THROW(A.SumMatrix(B));
}

TEST(SubMatrix, test1) {
  S21Matrix A(3, 2);
  S21Matrix B(3, 2);

  A(0, 0) = 1.0;
  A(0, 1) = -4231.3245;
  A(1, 0) = 5323.09;
  A(1, 1) = 54325.89;
  A(2, 0) = 0;
  A(2, 1) = -0.12355659;

  B(0, 0) = 1.0;
  B(0, 1) = -4231.3245;
  B(1, 0) = 5323.09;
  B(1, 1) = 54325.89;
  B(2, 0) = 0;
  B(2, 1) = -0.12355659;

  A.SubMatrix(B);

  ASSERT_DOUBLE_EQ(0, A(0, 0));
  ASSERT_DOUBLE_EQ(0, A(0, 1));
  ASSERT_DOUBLE_EQ(0, A(1, 0));
  ASSERT_DOUBLE_EQ(0, A(1, 1));
  ASSERT_DOUBLE_EQ(0, A(2, 0));
  ASSERT_DOUBLE_EQ(0, A(2, 1));
}

TEST(SubMatrix, test2) {
  S21Matrix A(2, 2);
  S21Matrix B(2, 2);

  A(0, 0) = -1.3;
  A(0, 1) = 4;
  A(1, 0) = 0.53;
  A(1, 1) = 9.87;

  B(0, 0) = 1;
  B(0, 1) = 1;
  B(1, 0) = 1;
  B(1, 1) = 1;

  A.SubMatrix(B);

  ASSERT_DOUBLE_EQ(-2.3, A(0, 0));
  ASSERT_DOUBLE_EQ(3, A(0, 1));
  ASSERT_DOUBLE_EQ(-0.47, A(1, 0));
  ASSERT_DOUBLE_EQ(8.87, A(1, 1));
}

TEST(SubMatrix, test3) {
  S21Matrix A(2, 2);
  S21Matrix B(2, 2);

  A(0, 0) = -1.3;
  A(0, 1) = 4;
  A(1, 0) = 0.53;
  A(1, 1) = 9.87;

  B = A;

  A.SubMatrix(B);

  ASSERT_DOUBLE_EQ(0, A(0, 0));
  ASSERT_DOUBLE_EQ(0, A(0, 1));
  ASSERT_DOUBLE_EQ(0, A(1, 0));
  ASSERT_DOUBLE_EQ(0, A(1, 1));
}

TEST(SubMatrix, test4) {
  S21Matrix A(3, 2);
  S21Matrix B(4, 5);

  A(0, 0) = 1.0;
  A(0, 1) = -4231.3245;
  A(1, 0) = 5323.09;
  A(1, 1) = 54325.89;
  A(2, 0) = 0;
  A(2, 1) = -0.12355659;

  ASSERT_ANY_THROW(A.SubMatrix(B));
}

TEST(MulNumber, test1) {
  S21Matrix A(3, 3);
  A(0, 0) = 0;
  A(0, 1) = 1.445;
  A(0, 2) = 23.5;
  A(1, 0) = -3;
  A(1, 1) = 10;
  A(1, 2) = -81;
  A(2, 0) = 0;
  A(2, 1) = 423.90;
  A(2, 2) = 43;

  double number = 2.65;
  S21Matrix B = A;

  A.MulNumber(number);

  ASSERT_DOUBLE_EQ(A(0, 0), B(0, 0) * number);
  ASSERT_DOUBLE_EQ(A(0, 1), B(0, 1) * number);
  ASSERT_DOUBLE_EQ(A(0, 2), B(0, 2) * number);
  ASSERT_DOUBLE_EQ(A(1, 0), B(1, 0) * number);
  ASSERT_DOUBLE_EQ(A(1, 1), B(1, 1) * number);
  ASSERT_DOUBLE_EQ(A(1, 2), B(1, 2) * number);
  ASSERT_DOUBLE_EQ(A(2, 0), B(2, 0) * number);
  ASSERT_DOUBLE_EQ(A(2, 1), B(2, 1) * number);
  ASSERT_DOUBLE_EQ(A(2, 2), B(2, 2) * number);
}

TEST(MulNumber, test2) {
  S21Matrix A(3, 3);
  A(0, 0) = 0;
  A(0, 1) = 1.445;
  A(0, 2) = 25423.5;
  A(1, 0) = -3;
  A(1, 1) = 1420;
  A(1, 2) = -81;
  A(2, 0) = 0;
  A(2, 1) = -423.90;
  A(2, 2) = 43;

  double number = 0.01;
  S21Matrix B = A;

  A.MulNumber(number);

  ASSERT_DOUBLE_EQ(A(0, 0), B(0, 0) * number);
  ASSERT_DOUBLE_EQ(A(0, 1), B(0, 1) * number);
  ASSERT_DOUBLE_EQ(A(0, 2), B(0, 2) * number);
  ASSERT_DOUBLE_EQ(A(1, 0), B(1, 0) * number);
  ASSERT_DOUBLE_EQ(A(1, 1), B(1, 1) * number);
  ASSERT_DOUBLE_EQ(A(1, 2), B(1, 2) * number);
  ASSERT_DOUBLE_EQ(A(2, 0), B(2, 0) * number);
  ASSERT_DOUBLE_EQ(A(2, 1), B(2, 1) * number);
  ASSERT_DOUBLE_EQ(A(2, 2), B(2, 2) * number);
}

TEST(MulMatrix, test1) {
  S21Matrix A(2, 3);
  S21Matrix B(3, 2);

  A(0, 0) = 1.2;
  A(0, 1) = -1.5;
  A(0, 2) = 2.39;
  A(1, 0) = 43.21;
  A(1, 1) = 0;
  A(1, 2) = -10.3;

  B(0, 0) = 3.4;
  B(0, 1) = -1.65;
  B(1, 0) = 0;
  B(1, 1) = 1;
  B(2, 0) = 0;
  B(2, 1) = -9742.2;

  A.MulMatrix(B);

  ASSERT_DOUBLE_EQ(A(0, 0), 4.08);
  ASSERT_DOUBLE_EQ(A(0, 1), -23287.338);
  ASSERT_DOUBLE_EQ(A(1, 0), 146.914);
  ASSERT_DOUBLE_EQ(A(1, 1), 100273.3635);
  ASSERT_EQ(A.GetRow(), 2);
  ASSERT_EQ(A.GetCol(), 2);
}

TEST(MulMatrix, test2) {
  S21Matrix A(2, 3);
  S21Matrix B(2, 3);

  ASSERT_ANY_THROW(A.MulMatrix(B));
}

TEST(MulMatrix, test3) {
  S21Matrix A(2, 2);
  S21Matrix B(2, 2);

  A(0, 0) = 1;
  A(0, 1) = 2;
  A(1, 0) = 3;
  A(1, 1) = 4;

  B(0, 0) = 5;
  B(0, 1) = 6;
  B(1, 0) = 7;
  B(1, 1) = 8;

  A.MulMatrix(B);

  ASSERT_DOUBLE_EQ(A(0, 0), 19);
  ASSERT_DOUBLE_EQ(A(0, 1), 22);
  ASSERT_DOUBLE_EQ(A(1, 0), 43);
  ASSERT_DOUBLE_EQ(A(1, 1), 50);
  ASSERT_EQ(A.GetRow(), 2);
  ASSERT_EQ(A.GetCol(), 2);
}

TEST(Transpose, test1) {
  S21Matrix A(2, 2);
  A(0, 0) = 1;
  A(0, 1) = 2;
  A(1, 0) = 3;
  A(1, 1) = 4;

  S21Matrix B = A.Transpose();
  ASSERT_DOUBLE_EQ(B(0, 0), 1);
  ASSERT_DOUBLE_EQ(B(0, 1), 3);
  ASSERT_DOUBLE_EQ(B(1, 0), 2);
  ASSERT_DOUBLE_EQ(B(1, 1), 4);
  ASSERT_EQ(B.GetRow(), A.GetCol());
  ASSERT_EQ(B.GetCol(), A.GetRow());
}

TEST(Transpose, test2) {
  S21Matrix A(2, 3);
  A(0, 0) = 1;
  A(0, 1) = 2;
  A(0, 2) = 3;
  A(1, 0) = 4;
  A(1, 1) = 5;
  A(1, 2) = 6;

  S21Matrix B = A.Transpose();
  ASSERT_DOUBLE_EQ(B(0, 0), 1);
  ASSERT_DOUBLE_EQ(B(0, 1), 4);
  ASSERT_DOUBLE_EQ(B(1, 0), 2);
  ASSERT_DOUBLE_EQ(B(1, 1), 5);
  ASSERT_DOUBLE_EQ(B(2, 0), 3);
  ASSERT_DOUBLE_EQ(B(2, 1), 6);
  ASSERT_EQ(B.GetRow(), A.GetCol());
  ASSERT_EQ(B.GetCol(), A.GetRow());
}

TEST(Transpose, test3) {
  S21Matrix A(1, 5);
  A(0, 0) = 1;
  A(0, 1) = 2;
  A(0, 2) = 3;
  A(0, 3) = 4;
  A(0, 4) = 5;

  S21Matrix B = A.Transpose();
  ASSERT_DOUBLE_EQ(B(0, 0), 1);
  ASSERT_DOUBLE_EQ(B(1, 0), 2);
  ASSERT_DOUBLE_EQ(B(2, 0), 3);
  ASSERT_DOUBLE_EQ(B(3, 0), 4);
  ASSERT_DOUBLE_EQ(B(4, 0), 5);
  ASSERT_EQ(B.GetRow(), A.GetCol());
  ASSERT_EQ(B.GetCol(), A.GetRow());
}

TEST(Determinant, test1) {
  S21Matrix A(4, 4);
  A(0, 0) = 0;
  A(0, 1) = 1;
  A(0, 2) = 2;
  A(0, 3) = 3;
  A(1, 0) = 4;
  A(1, 1) = 5;
  A(1, 2) = 62;
  A(1, 3) = 7;
  A(2, 0) = 81;
  A(2, 1) = 9;
  A(2, 2) = 10;
  A(2, 3) = 11;
  A(3, 0) = 12;
  A(3, 1) = 13;
  A(3, 2) = 14;
  A(3, 3) = 15;

  double result = A.Determinant();
  ASSERT_DOUBLE_EQ(-98112, result);
}

TEST(Determinant, test2) {
  S21Matrix A(4, 4);
  A(0, 0) = 0;
  A(0, 1) = 1;
  A(0, 2) = 2;
  A(0, 3) = 3;
  A(1, 0) = 4;
  A(1, 1) = 5.43;
  A(1, 2) = 62;
  A(1, 3) = 7;
  A(2, 0) = 18;
  A(2, 1) = 9;
  A(2, 2) = 10;
  A(2, 3) = 11;
  A(3, 0) = 12;
  A(3, 1) = 13;
  A(3, 2) = 14.98;
  A(3, 3) = 15;

  double result = A.Determinant();
  ASSERT_DOUBLE_EQ(-13287.2444, result);
}

TEST(Determinant, test3) {
  S21Matrix A(5, 5);
  A(0, 0) = 0;
  A(0, 1) = 1;
  A(0, 2) = 2;
  A(0, 3) = 3;
  A(0, 4) = 1;
  A(1, 0) = 4;
  A(1, 1) = 5.43;
  A(1, 2) = 62;
  A(1, 3) = 7;
  A(1, 4) = 1;
  A(2, 0) = 18;
  A(2, 1) = 9;
  A(2, 2) = 10;
  A(2, 3) = 11;
  A(2, 4) = 1;
  A(3, 0) = 12;
  A(3, 1) = 13;
  A(3, 2) = 14.98;
  A(3, 3) = 15;
  A(3, 4) = 1;
  A(4, 0) = 1;
  A(4, 1) = 1;
  A(4, 2) = 1;
  A(4, 3) = 1;
  A(4, 4) = 1;

  double result = A.Determinant();
  ASSERT_DOUBLE_EQ(-13291.4584, result);
}

TEST(Determinant, test4) {
  S21Matrix A(3, 3);
  A(0, 0) = 1;
  A(0, 1) = 2;
  A(0, 2) = 3;
  A(1, 0) = 4;
  A(1, 1) = 5;
  A(1, 2) = 6;
  A(2, 0) = 7;
  A(2, 1) = 8;
  A(2, 2) = 9;

  double result = A.Determinant();
  ASSERT_DOUBLE_EQ(0, result);
}

TEST(Determinant, test5) {
  S21Matrix A(2, 2);
  A(0, 0) = -12.43;
  A(0, 1) = 23;
  A(1, 0) = 4;
  A(1, 1) = 51;

  double result = A.Determinant();
  ASSERT_DOUBLE_EQ(-725.93, result);
}

TEST(Determinant, test6) {
  S21Matrix A(1, 1);
  A(0, 0) = -12.43;

  double result = A.Determinant();
  ASSERT_DOUBLE_EQ(-12.43, result);
}

TEST(CalcComplements, test1) {
  S21Matrix A(3, 3);
  A(0, 0) = 1;
  A(0, 1) = 2;
  A(0, 2) = 3;
  A(1, 0) = 0;
  A(1, 1) = 4;
  A(1, 2) = 2;
  A(2, 0) = 5;
  A(2, 1) = 2;
  A(2, 2) = 1;

  S21Matrix B = A.CalcComplements();
  ASSERT_DOUBLE_EQ(0, B(0, 0));
  ASSERT_DOUBLE_EQ(10, B(0, 1));
  ASSERT_DOUBLE_EQ(-20, B(0, 2));
  ASSERT_DOUBLE_EQ(4, B(1, 0));
  ASSERT_DOUBLE_EQ(-14, B(1, 1));
  ASSERT_DOUBLE_EQ(8, B(1, 2));
  ASSERT_DOUBLE_EQ(-8, B(2, 0));
  ASSERT_DOUBLE_EQ(-2, B(2, 1));
  ASSERT_DOUBLE_EQ(4, B(2, 2));
}

TEST(CalcComplements, test2) {
  S21Matrix A(4, 4);
  A(0, 0) = 21;
  A(0, 1) = 1;
  A(0, 2) = 2;
  A(0, 3) = 3;
  A(1, 0) = 4;
  A(1, 1) = 10;
  A(1, 2) = 46;
  A(1, 3) = 78;
  A(2, 0) = 23;
  A(2, 1) = 11;
  A(2, 2) = 224;
  A(2, 3) = 356;
  A(3, 0) = 1;
  A(3, 1) = 0;
  A(3, 2) = 0;
  A(3, 3) = 1;

  S21Matrix B = A.CalcComplements();
  ASSERT_DOUBLE_EQ(1734, B(0, 0));
  ASSERT_DOUBLE_EQ(1258, B(0, 1));
  ASSERT_DOUBLE_EQ(2516, B(0, 2));
  ASSERT_DOUBLE_EQ(-1734, B(0, 3));

  ASSERT_DOUBLE_EQ(-202, B(1, 0));
  ASSERT_DOUBLE_EQ(4698, B(1, 1));
  ASSERT_DOUBLE_EQ(-531, B(1, 2));
  ASSERT_DOUBLE_EQ(202, B(1, 3));

  ASSERT_DOUBLE_EQ(26, B(2, 0));
  ASSERT_DOUBLE_EQ(-976, B(2, 1));
  ASSERT_DOUBLE_EQ(254, B(2, 2));
  ASSERT_DOUBLE_EQ(-26, B(2, 3));

  ASSERT_DOUBLE_EQ(1298, B(3, 0));
  ASSERT_DOUBLE_EQ(-22762, B(3, 1));
  ASSERT_DOUBLE_EQ(-56554, B(3, 2));
  ASSERT_DOUBLE_EQ(36204, B(3, 3));
}

TEST(CalcComplements, test3) {
  S21Matrix A(2, 2);
  A(0, 0) = 1.56;
  A(0, 1) = 2;
  A(1, 0) = 3.33;
  A(1, 1) = 4.24;

  S21Matrix B = A.CalcComplements();
  ASSERT_DOUBLE_EQ(4.24, B(0, 0));
  ASSERT_DOUBLE_EQ(-3.33, B(0, 1));
  ASSERT_DOUBLE_EQ(-2, B(1, 0));
  ASSERT_DOUBLE_EQ(1.56, B(1, 1));
}

TEST(Inverse, test1) {
  S21Matrix A(3, 3);
  A(0, 0) = 2;
  A(0, 1) = 5;
  A(0, 2) = 7;
  A(1, 0) = 6;
  A(1, 1) = 3;
  A(1, 2) = 4;
  A(2, 0) = 5;
  A(2, 1) = -2;
  A(2, 2) = -3;

  S21Matrix B = A.InverseMatrix();

  ASSERT_DOUBLE_EQ(1, B(0, 0));
  ASSERT_DOUBLE_EQ(-1, B(0, 1));
  ASSERT_DOUBLE_EQ(1, B(0, 2));
  ASSERT_DOUBLE_EQ(-38, B(1, 0));
  ASSERT_DOUBLE_EQ(41, B(1, 1));
  ASSERT_DOUBLE_EQ(-34, B(1, 2));
  ASSERT_DOUBLE_EQ(27, B(2, 0));
  ASSERT_DOUBLE_EQ(-29, B(2, 1));
  ASSERT_DOUBLE_EQ(24, B(2, 2));
}

TEST(Inverse, test2) {
  S21Matrix A(5, 5);
  A(0, 0) = 0;
  A(0, 1) = 1;
  A(0, 2) = 2;
  A(0, 3) = 3;
  A(0, 4) = 1;
  A(1, 0) = 4;
  A(1, 1) = 5.43;
  A(1, 2) = 62;
  A(1, 3) = 7;
  A(1, 4) = 1;
  A(2, 0) = 18;
  A(2, 1) = 9;
  A(2, 2) = 10;
  A(2, 3) = 11;
  A(2, 4) = 1;
  A(3, 0) = 12;
  A(3, 1) = 13;
  A(3, 2) = 14.98;
  A(3, 3) = 15;
  A(3, 4) = 1;
  A(4, 0) = 1;
  A(4, 1) = 1;
  A(4, 2) = 1;
  A(4, 3) = 1;
  A(4, 4) = 1;

  S21Matrix B = A.InverseMatrix();
  B.MulMatrix(A);

  ASSERT_NEAR(1, B(0, 0), S21_PRECISION);
  ASSERT_NEAR(0, B(0, 1), S21_PRECISION);
  ASSERT_NEAR(0, B(0, 2), S21_PRECISION);
  ASSERT_NEAR(0, B(0, 3), S21_PRECISION);
  ASSERT_NEAR(0, B(0, 4), S21_PRECISION);

  ASSERT_NEAR(0, B(1, 0), S21_PRECISION);
  ASSERT_NEAR(1, B(1, 1), S21_PRECISION);
  ASSERT_NEAR(0, B(1, 2), S21_PRECISION);
  ASSERT_NEAR(0, B(1, 3), S21_PRECISION);
  ASSERT_NEAR(0, B(1, 4), S21_PRECISION);

  ASSERT_NEAR(0, B(2, 0), S21_PRECISION);
  ASSERT_NEAR(0, B(2, 1), S21_PRECISION);
  ASSERT_NEAR(1, B(2, 2), S21_PRECISION);
  ASSERT_NEAR(0, B(2, 3), S21_PRECISION);
  ASSERT_NEAR(0, B(2, 4), S21_PRECISION);

  ASSERT_NEAR(0, B(3, 0), S21_PRECISION);
  ASSERT_NEAR(0, B(3, 1), S21_PRECISION);
  ASSERT_NEAR(0, B(3, 2), S21_PRECISION);
  ASSERT_NEAR(1, B(3, 3), S21_PRECISION);
  ASSERT_NEAR(0, B(3, 4), S21_PRECISION);

  ASSERT_NEAR(0, B(4, 0), S21_PRECISION);
  ASSERT_NEAR(0, B(4, 1), S21_PRECISION);
  ASSERT_NEAR(0, B(4, 2), S21_PRECISION);
  ASSERT_NEAR(0, B(4, 3), S21_PRECISION);
  ASSERT_NEAR(1, B(4, 4), S21_PRECISION);
}

TEST(Inverse, test3) {
  S21Matrix A(3, 3);
  A(0, 0) = 1;
  A(0, 1) = 2;
  A(0, 2) = 3;
  A(1, 0) = 4;
  A(1, 1) = 5;
  A(1, 2) = 6;
  A(2, 0) = 7;
  A(2, 1) = 8;
  A(2, 2) = 9;

  ASSERT_ANY_THROW(A.InverseMatrix());
}

TEST(Inverse, test4) {
  S21Matrix A(2, 2);
  A(0, 0) = 1;
  A(0, 1) = 2;
  A(1, 0) = 3;
  A(1, 1) = 4;

  S21Matrix B = A.InverseMatrix();

  ASSERT_DOUBLE_EQ(-2, B(0, 0));
  ASSERT_DOUBLE_EQ(1, B(0, 1));
  ASSERT_DOUBLE_EQ(1.5, B(1, 0));
  ASSERT_DOUBLE_EQ(-0.5, B(1, 1));
}

TEST(Inverse, test5) {
  S21Matrix A(4, 4);
  A(0, 0) = -1;
  A(0, 1) = 2;
  A(0, 2) = 7;
  A(0, 3) = 9;
  A(1, 0) = 1;
  A(1, 1) = 0;
  A(1, 2) = 0;
  A(1, 3) = 0;
  A(2, 0) = 47;
  A(2, 1) = 13;
  A(2, 2) = 17;
  A(2, 3) = 21;
  A(3, 0) = 22;
  A(3, 1) = 7;
  A(3, 2) = 1;
  A(3, 3) = 3;

  S21Matrix B = A.InverseMatrix();

  ASSERT_DOUBLE_EQ(0, B(0, 0));
  ASSERT_DOUBLE_EQ(1, B(0, 1));
  ASSERT_DOUBLE_EQ(0, B(0, 2));
  ASSERT_DOUBLE_EQ(0, B(0, 3));

  ASSERT_DOUBLE_EQ(-5.0 / 23.0, B(1, 0));
  ASSERT_DOUBLE_EQ(-121.0 / 23.0, B(1, 1));
  ASSERT_DOUBLE_EQ(2.0 / 23.0, B(1, 2));
  ASSERT_DOUBLE_EQ(1.0 / 23.0, B(1, 3));

  ASSERT_DOUBLE_EQ(-18.0 / 23.0, B(2, 0));
  ASSERT_DOUBLE_EQ(-379.0 / 46.0, B(2, 1));
  ASSERT_DOUBLE_EQ(19.0 / 46.0, B(2, 2));
  ASSERT_DOUBLE_EQ(-25.0 / 46.0, B(2, 3));

  ASSERT_DOUBLE_EQ(53.0 / 69.0, B(3, 0));
  ASSERT_DOUBLE_EQ(1061.0 / 138.0, B(3, 1));
  ASSERT_DOUBLE_EQ(-47.0 / 138.0, B(3, 2));
  ASSERT_DOUBLE_EQ(19.0 / 46.0, B(3, 3));
}

TEST(Inverse, test6) {
  S21Matrix A(2, 3);
  A(0, 0) = 1;
  A(0, 1) = 2;
  A(0, 2) = 3;
  A(1, 0) = 4;
  A(1, 1) = 3;
  A(1, 2) = 4;

  ASSERT_ANY_THROW(A.InverseMatrix());
}

TEST(Operator_plus, test1) {
  S21Matrix A(3, 2);
  S21Matrix B(3, 2);

  A(0, 0) = -1.0;
  A(0, 1) = 4231.3245;
  A(1, 0) = -5323.09;
  A(1, 1) = -54325.89;
  A(2, 0) = 0;
  A(2, 1) = 0.12355659;

  B(0, 0) = 1.0;
  B(0, 1) = -4231.3245;
  B(1, 0) = 5323.09;
  B(1, 1) = 54325.89;
  B(2, 0) = 0;
  B(2, 1) = -0.12355659;

  S21Matrix C = A + B;

  ASSERT_DOUBLE_EQ(0, C(0, 0));
  ASSERT_DOUBLE_EQ(0, C(0, 1));
  ASSERT_DOUBLE_EQ(0, C(1, 0));
  ASSERT_DOUBLE_EQ(0, C(1, 1));
  ASSERT_DOUBLE_EQ(0, C(2, 0));
  ASSERT_DOUBLE_EQ(0, C(2, 1));
}

TEST(Operator_plus, test2) {
  S21Matrix A(3, 2);
  S21Matrix B(3, 2);

  A(0, 0) = -1.0;
  A(0, 1) = 4231.3245;
  A(1, 0) = -5323.09;
  A(1, 1) = -54325.89;
  A(2, 0) = 0;
  A(2, 1) = 0.12355659;

  B(0, 0) = 1.0;
  B(0, 1) = -4231.3245;
  B(1, 0) = 5323.09;
  B(1, 1) = 54325.89;
  B(2, 0) = 0;
  B(2, 1) = -0.12355659;

  S21Matrix C = B;

  S21Matrix D = A + B + C;

  ASSERT_TRUE(D.EqMatrix(C));
}

TEST(Operator_minus, test1) {
  S21Matrix A(3, 2);
  S21Matrix B(3, 2);

  A(0, 0) = 1.0;
  A(0, 1) = -4231.3245;
  A(1, 0) = 5323.09;
  A(1, 1) = 54325.89;
  A(2, 0) = 0;
  A(2, 1) = -0.12355659;

  B(0, 0) = 1.0;
  B(0, 1) = -4231.3245;
  B(1, 0) = 5323.09;
  B(1, 1) = 54325.89;
  B(2, 0) = 0;
  B(2, 1) = -0.12355659;

  S21Matrix C = A - B;

  ASSERT_DOUBLE_EQ(0, C(0, 0));
  ASSERT_DOUBLE_EQ(0, C(0, 1));
  ASSERT_DOUBLE_EQ(0, C(1, 0));
  ASSERT_DOUBLE_EQ(0, C(1, 1));
  ASSERT_DOUBLE_EQ(0, C(2, 0));
  ASSERT_DOUBLE_EQ(0, C(2, 1));
}

TEST(Operator_minus, test2) {
  S21Matrix A(3, 2);
  S21Matrix B(3, 2);

  A(0, 0) = 1.0;
  A(0, 1) = -4231.3245;
  A(1, 0) = 5323.09;
  A(1, 1) = 54325.89;
  A(2, 0) = 0;
  A(2, 1) = -0.12355659;

  B(0, 0) = 1.0;
  B(0, 1) = -4231.3245;
  B(1, 0) = 5323.09;
  B(1, 1) = 54325.89;
  B(2, 0) = 0;
  B(2, 1) = -0.12355659;

  S21Matrix C = A - B - B;

  ASSERT_DOUBLE_EQ(-1, C(0, 0));
  ASSERT_DOUBLE_EQ(4231.3245, C(0, 1));
  ASSERT_DOUBLE_EQ(-5323.09, C(1, 0));
  ASSERT_DOUBLE_EQ(-54325.89, C(1, 1));
  ASSERT_DOUBLE_EQ(0, C(2, 0));
  ASSERT_DOUBLE_EQ(0.12355659, C(2, 1));
}

TEST(Operator_multy, test1) {
  S21Matrix A(2, 2);
  S21Matrix B(2, 2);

  A(0, 0) = 1;
  A(0, 1) = 2;
  A(1, 0) = 3;
  A(1, 1) = 4;

  B(0, 0) = 1;
  B(0, 1) = 0;
  B(1, 0) = 0;
  B(1, 1) = 1;

  S21Matrix C = 2 * A * B;

  ASSERT_DOUBLE_EQ(2, C(0, 0));
  ASSERT_DOUBLE_EQ(4, C(0, 1));
  ASSERT_DOUBLE_EQ(6, C(1, 0));
  ASSERT_DOUBLE_EQ(8, C(1, 1));
}

TEST(Operator_multy, test2) {
  S21Matrix A(2, 2);
  S21Matrix B(2, 2);

  A(0, 0) = 1;
  A(0, 1) = 2;
  A(1, 0) = 3;
  A(1, 1) = 4;

  B(0, 0) = 1;
  B(0, 1) = 0;
  B(1, 0) = 0;
  B(1, 1) = 1;

  S21Matrix C = A * B * 2;

  ASSERT_DOUBLE_EQ(2, C(0, 0));
  ASSERT_DOUBLE_EQ(4, C(0, 1));
  ASSERT_DOUBLE_EQ(6, C(1, 0));
  ASSERT_DOUBLE_EQ(8, C(1, 1));
}

TEST(Operator_multy, test3) {
  S21Matrix A(2, 2);
  S21Matrix B(2, 2);
  S21Matrix C(2, 2);

  A(0, 0) = 1;
  A(0, 1) = 2;
  A(1, 0) = 3;
  A(1, 1) = 4;

  B(0, 0) = 1;
  B(0, 1) = 0;
  B(1, 0) = 0;
  B(1, 1) = 1;

  C(0, 0) = 5;
  C(0, 1) = 6;
  C(1, 0) = 7;
  C(1, 1) = 8;

  S21Matrix D = A * B * C;

  ASSERT_DOUBLE_EQ(D(0, 0), 19);
  ASSERT_DOUBLE_EQ(D(0, 1), 22);
  ASSERT_DOUBLE_EQ(D(1, 0), 43);
  ASSERT_DOUBLE_EQ(D(1, 1), 50);
  ASSERT_EQ(D.GetRow(), 2);
  ASSERT_EQ(D.GetCol(), 2);
}

TEST(Operator_equal, test1) {
  S21Matrix A(2, 2);
  S21Matrix B(2, 2);
  A(0, 0) = 1;
  A(0, 1) = 2;
  A(1, 0) = 3;
  A(1, 1) = 4;

  B = A;

  ASSERT_TRUE(A == B);
}

TEST(Operator_equal, test2) {
  S21Matrix A(2, 2);
  S21Matrix B(2, 2);
  A(0, 0) = 1;
  A(0, 1) = 2;
  A(1, 0) = 3;
  A(1, 1) = 4;

  B = A;
  B(0, 0) = -1;

  ASSERT_FALSE(A == B);
}

TEST(Operator_plus_equal, test1) {
  S21Matrix A(3, 2);
  S21Matrix B(3, 2);

  A(0, 0) = -1.0;
  A(0, 1) = 4231.3245;
  A(1, 0) = -5323.09;
  A(1, 1) = -54325.89;
  A(2, 0) = 0;
  A(2, 1) = 0.12355659;

  B(0, 0) = 1.0;
  B(0, 1) = -4231.3245;
  B(1, 0) = 5323.09;
  B(1, 1) = 54325.89;
  B(2, 0) = 0;
  B(2, 1) = -0.12355659;

  A += B;

  ASSERT_DOUBLE_EQ(0, A(0, 0));
  ASSERT_DOUBLE_EQ(0, A(0, 1));
  ASSERT_DOUBLE_EQ(0, A(1, 0));
  ASSERT_DOUBLE_EQ(0, A(1, 1));
  ASSERT_DOUBLE_EQ(0, A(2, 0));
  ASSERT_DOUBLE_EQ(0, A(2, 1));
}

TEST(Operator_plus_equal, test2) {
  S21Matrix A(3, 2);
  S21Matrix B(3, 2);

  A(0, 0) = -1.0;
  A(0, 1) = 4231.3245;
  A(1, 0) = -5323.09;
  A(1, 1) = -54325.89;
  A(2, 0) = 0;
  A(2, 1) = 0.12355659;

  B(0, 0) = 1.0;
  B(0, 1) = -4231.3245;
  B(1, 0) = 5323.09;
  B(1, 1) = 54325.89;
  B(2, 0) = 0;
  B(2, 1) = -0.12355659;

  A += B - A;

  ASSERT_DOUBLE_EQ(B(0, 0), A(0, 0));
  ASSERT_DOUBLE_EQ(B(0, 1), A(0, 1));
  ASSERT_DOUBLE_EQ(B(1, 0), A(1, 0));
  ASSERT_DOUBLE_EQ(B(1, 1), A(1, 1));
  ASSERT_DOUBLE_EQ(B(2, 0), A(2, 0));
  ASSERT_DOUBLE_EQ(B(2, 1), A(2, 1));
}

TEST(Operartir_minus_equal, test1) {
  S21Matrix A(3, 2);
  S21Matrix B(3, 2);

  A(0, 0) = -1.0;
  A(0, 1) = 4231.3245;
  A(1, 0) = -5323.09;
  A(1, 1) = -54325.89;
  A(2, 0) = 0;
  A(2, 1) = 0.12355659;

  B(0, 0) = -1.0;
  B(0, 1) = 4231.3245;
  B(1, 0) = -5323.09;
  B(1, 1) = -54325.89;
  B(2, 0) = 0;
  B(2, 1) = 0.12355659;

  A -= B;

  ASSERT_DOUBLE_EQ(0, A(0, 0));
  ASSERT_DOUBLE_EQ(0, A(0, 1));
  ASSERT_DOUBLE_EQ(0, A(1, 0));
  ASSERT_DOUBLE_EQ(0, A(1, 1));
  ASSERT_DOUBLE_EQ(0, A(2, 0));
  ASSERT_DOUBLE_EQ(0, A(2, 1));
}

TEST(Operator_minus_equal, test2) {
  S21Matrix A(3, 2);
  S21Matrix B(3, 2);

  A(0, 0) = -1.0;
  A(0, 1) = 4231.3245;
  A(1, 0) = -5323.09;
  A(1, 1) = -54325.89;
  A(2, 0) = 0;
  A(2, 1) = 0.12355659;

  B(0, 0) = 1.0;
  B(0, 1) = -4231.3245;
  B(1, 0) = 5323.09;
  B(1, 1) = 54325.89;
  B(2, 0) = 0;
  B(2, 1) = -0.12355659;

  A -= -2 * B - B - A;

  ASSERT_DOUBLE_EQ(B(0, 0), A(0, 0));
  ASSERT_DOUBLE_EQ(B(0, 1), A(0, 1));
  ASSERT_DOUBLE_EQ(B(1, 0), A(1, 0));
  ASSERT_DOUBLE_EQ(B(1, 1), A(1, 1));
  ASSERT_DOUBLE_EQ(B(2, 0), A(2, 0));
}

TEST(Operator_multy_equal, test1) {
  S21Matrix A(2, 2);
  S21Matrix B(2, 2);

  A(0, 0) = 1;
  A(0, 1) = 2;
  A(1, 0) = 3;
  A(1, 1) = 4;

  B(0, 0) = 1;
  B(0, 1) = 0;
  B(1, 0) = 0;
  B(1, 1) = 1;

  B *= A * 2;

  ASSERT_DOUBLE_EQ(2, B(0, 0));
  ASSERT_DOUBLE_EQ(4, B(0, 1));
  ASSERT_DOUBLE_EQ(6, B(1, 0));
  ASSERT_DOUBLE_EQ(8, B(1, 1));
}

TEST(Operator_multy_equal, test2) {
  S21Matrix A(2, 2);
  S21Matrix B(2, 2);

  A(0, 0) = 1;
  A(0, 1) = 2;
  A(1, 0) = 3;
  A(1, 1) = 4;

  B(0, 0) = 1;
  B(0, 1) = 0;
  B(1, 0) = 0;
  B(1, 1) = 1;

  B *= 10;

  ASSERT_DOUBLE_EQ(10, B(0, 0));
  ASSERT_DOUBLE_EQ(0, B(0, 1));
  ASSERT_DOUBLE_EQ(0, B(1, 0));
  ASSERT_DOUBLE_EQ(10, B(1, 1));
}

TEST(SetRow, test1) {
  S21Matrix A(2, 2);
  A(0, 0) = 1;
  A(0, 1) = 2;
  A(1, 0) = 3;
  A(1, 1) = 4;

  S21Matrix B = std::move(A);
  B.SetRow(4);

  ASSERT_EQ(4, B.GetRow());
  ASSERT_EQ(2, B.GetCol());
  ASSERT_DOUBLE_EQ(1, B(0, 0));
  ASSERT_DOUBLE_EQ(2, B(0, 1));
  ASSERT_DOUBLE_EQ(3, B(1, 0));
  ASSERT_DOUBLE_EQ(4, B(1, 1));
  ASSERT_DOUBLE_EQ(0, B(2, 0));
  ASSERT_DOUBLE_EQ(0, B(2, 1));
  ASSERT_DOUBLE_EQ(0, B(3, 0));
  ASSERT_DOUBLE_EQ(0, B(3, 1));
}

TEST(SetRow, test2) {
  S21Matrix A(2, 2);
  A(0, 0) = 1;
  A(0, 1) = 2;
  A(1, 0) = 3;
  A(1, 1) = 4;

  A.SetRow(1);

  ASSERT_EQ(1, A.GetRow());
  ASSERT_EQ(2, A.GetCol());
  ASSERT_DOUBLE_EQ(1, A(0, 0));
  ASSERT_DOUBLE_EQ(2, A(0, 1));
}

TEST(SetRow, test3) {
  S21Matrix A(2, 2);
  A(0, 0) = 1;
  A(0, 1) = 2;
  A(1, 0) = 3;
  A(1, 1) = 4;

  ASSERT_ANY_THROW(A.SetRow(0));
}

TEST(SetCol, test1) {
  S21Matrix A(2, 2);
  A(0, 0) = 1;
  A(0, 1) = 2;
  A(1, 0) = 3;
  A(1, 1) = 4;

  S21Matrix B = std::move(A);
  B.SetCol(4);

  ASSERT_EQ(2, B.GetRow());
  ASSERT_EQ(4, B.GetCol());
  ASSERT_DOUBLE_EQ(1, B(0, 0));
  ASSERT_DOUBLE_EQ(2, B(0, 1));
  ASSERT_DOUBLE_EQ(0, B(0, 2));
  ASSERT_DOUBLE_EQ(0, B(0, 3));
  ASSERT_DOUBLE_EQ(3, B(1, 0));
  ASSERT_DOUBLE_EQ(4, B(1, 1));
  ASSERT_DOUBLE_EQ(0, B(1, 2));
  ASSERT_DOUBLE_EQ(0, B(1, 3));
}

TEST(SetCol, test2) {
  S21Matrix A(2, 2);
  A(0, 0) = 1;
  A(0, 1) = 2;
  A(1, 0) = 3;
  A(1, 1) = 4;

  A.SetCol(1);

  ASSERT_EQ(2, A.GetRow());
  ASSERT_EQ(1, A.GetCol());
  ASSERT_DOUBLE_EQ(1, A(0, 0));
  ASSERT_DOUBLE_EQ(3, A(1, 0));
  ASSERT_ANY_THROW(A(1, 1));
}

TEST(SetCol, test3) {
  S21Matrix A(2, 2);
  A(0, 0) = 1;
  A(0, 1) = 2;
  A(1, 0) = 3;
  A(1, 1) = 4;

  ASSERT_ANY_THROW(A.SetCol(0));
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
