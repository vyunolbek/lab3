#pragma once
#include "Vector.h"
template<typename T>
class TTapeMatrix : public TDynamicVector<TDynamicVector<T>>
{
protected:
  size_t rad;//радиус - кол-во ненулевых диагоналей/2 + 1
  // d c e 0 0
  // b d c e 0
  // a b d c e , r = 3, r = {a, b, d | d, c, e}
  // 0 a b d c
  // 0 0 a b d
public:
  TTapeMatrix(int size = 1, int radius = 1);
  virtual ~TTapeMatrix();
  TTapeMatrix<T>& operator*(const TTapeMatrix<T>& p);
  TTapeMatrix<T> operator+(const TTapeMatrix<T>& p);

  template<typename T>
  friend std::istream& operator>>(std::istream& istr, TTapeMatrix<T>& v);
  template<typename T>
  friend std::ostream& operator<<(std::ostream& ostr, const TTapeMatrix<T>& v);
};

template<typename T>
inline TTapeMatrix<T>::TTapeMatrix(int size, int radius)
{
  if (radius < 1)//если радиус =0, то это нулевая матрица
    throw "Radius < 1";
  if (radius >= size)//если радиус равен размеру, то это обыкновенная матрица и нет смысла рассматривать ее здесь
    throw "Radius >= size";
  if (size < 1)
    throw "size < 1";
  pMem = new TDynamicVector<T>[radius * 2 - 1];
  sz = size;
  rad = radius;
  for (int i = 0; i < rad * 2 - 1; i++)
  {
    int a = 1;
    int b = 0;
    b = sz - rad + a;
    pMem[i] = TDynamicVector<T>(b);
    if (rad - 1 > i)
      a++;
    else
      a--;
  }
}

template<typename T>
inline TTapeMatrix<T>::~TTapeMatrix()
{}

template<typename T>
inline TTapeMatrix<T>& TTapeMatrix<T>::operator*(const TTapeMatrix<T>& p)
{
  
}

template<typename T>
inline TTapeMatrix<T> TTapeMatrix<T>::operator+(const TTapeMatrix<T>& p)
{
  if (sz != p.sz)
    throw "operator+ : sz != p.sz";
}

template<typename T>
inline std::istream& operator>>(std::istream& istr, TTapeMatrix<T>& v)
{
  int i = 0, k = 0, j = 0;
  for (; j < v.rad; j++)
  {
    for (i = 0; i < v.sz; i++)
    {
      istr >> v[v.rad - j + i - 1][k];
      if (k < j)
        k++;
      int b = v.rad - j + i;
      if (b == v.rad * 2 - 1)
        break;
    }
    k = 0;
  }
  int c = 1;
  for (j = v.sz - v.rad; j > 0; )
  {
    k = c;
    for (i = 0; i < v.sz; i++)
    {
      istr >> v[i][k];
      if (k < v.rad)
        k++;
      if (i >= v.rad)
        k--;
      int b = i + 1;
      if (b == 2 * v.rad - k)
        break;
    }
    c++;
    j--;
  }
  return istr;
}

template<typename T>
inline std::ostream& operator<<(std::ostream& ostr, const TTapeMatrix<T>& v)
{
  int i = 0, k = 0, j = 0;
  for (; j < v.rad; j++)
  {
    for (i = 0; i < v.sz; i++)
    {
      ostr << v[v.rad - j + i - 1][k] << ' ';
      if (k < j)
        k++;
      int b = v.rad - j + i;
      if (b == v.rad * 2 - 1)
        break;
    }
    ostr << std::endl;
    k = 0;
  }
  int c = 1;
  for (j = v.sz - v.rad; j > 0; )
  {
    k = c;
    for (int a = 0; a < k; a++)
      ostr << ' ' << ' ';
    for (i = 0; i < v.sz; i++)
    {
      ostr << v[i][k] << ' ';
      if (k < v.rad)
        k++;
      if (i >= v.rad)
        k--;
      int b = i + 1;
      if (b == 2 * v.rad - k)
        break;
    }
    ostr << std::endl;
    c++;
    j--;
  }
  return ostr;
}
