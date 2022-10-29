#include "Vector.h"
#include "Matrix.h"
#include "TrMatrix.h"
#include "TapeMatrix.h"
#include <iostream>
int main()
{
  //int n = 3;
  //TDynamicVector<int> a(n), c(n);
  //for (int i = 0; i < n; i++)
  //  a[i] = i + 2;
  //TDynamicVector<int> b = a;
  //c = a + b;
  //std::cout << c<<std::endl;
  //c = c + 1;
  //std::cout << c << std::endl;

  //for (auto i = c.begin(); i != c.end(); ++i)
  //  std::cout << *i << ' ';
  //std::cout << std::endl << std::endl;

  //TDynamicMatrix<int> A(3);
  //TDynamicMatrix<int> B(3);
  //for (int i = 0; i < n; i++)
  //  for (int j = 0; j < n; j++)
  //    A[i][j] = i + 2 - j;
  //B = A;
  //std::cout << B;

  //TDynamicMatrix<int> C = A;
  //std::cout << C;
  //
  //C = C + A*2;

  //TDynamicMatrix<int> D(C);
  //std::cout << D;

  //D = C * A;
  //std::cout << D;

  //a = D * c;
  //std::cout << a;

  /*TTrMatrix<int> X(4),Y(4);
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
      if (i >= j)
      {
        X[i][j] = i + j;
        Y[i][j] = i - j + 5;
      }
  std::cout << X << std::endl << Y << std::endl;
  TTrMatrix<int> Z(4);
  Z = X + Y;

  TTrMatrix<int> V(Z);
  std::cout << V << std::endl;

  Z = X * Y;
  std::cout << Z;*/

  TTapeMatrix<int> G(4, 2);
  std::cin >> G;
  std::cout << G;
  return 0;
}