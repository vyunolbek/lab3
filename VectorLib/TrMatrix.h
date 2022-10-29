#pragma once
#include "Vector.h"
template<typename T>
class TTrMatrix : public TDynamicVector<TDynamicVector<T>>
{
public:
  TTrMatrix(size_t size = 1);
  virtual ~TTrMatrix();

  TTrMatrix<T> operator*(const TTrMatrix<T>& p);
  TTrMatrix<T> operator+(const TTrMatrix<T>& p);

  template<typename T>
  friend std::istream& operator>>(std::istream& istr, TTrMatrix<T>& v);
  template<typename T>
  friend std::ostream& operator<<(std::ostream& ostr, const TTrMatrix<T>& v);
};

template<typename T>
inline TTrMatrix<T>::TTrMatrix(size_t size)
{
  if (size < 1)
    throw "size < 1";
  pMem = new TDynamicVector<T>[size];
  sz = size;
  for (int i = 0; i < sz; i++)
    pMem[i] = TDynamicVector<T>(i + 1);
}

template<typename T>
inline TTrMatrix<T>::~TTrMatrix()
{
}



template<typename T>
inline TTrMatrix<T> TTrMatrix<T>::operator*(const TTrMatrix<T>& p)
{
  if (sz != p.sz)
    throw "operator* : sz != p.sz";
  TTrMatrix<T> res(sz);
  for (int i = 0; i < sz; i++)
    for (int j = 0; j < sz; j++)
      if (i >= j)
      {
        res[i][j] = 0;
        for (int k = 0; k < sz; k++)
          if ((k <= i) && (k >= j))
            res[i][j] += (*this)[i][k] * p[k][j];
      }
  return res;
}

template<typename T>
inline TTrMatrix<T> TTrMatrix<T>::operator+(const TTrMatrix<T>& p)
{
  if (sz != p.sz)
    throw "operator+ : sz != p.sz";
  TTrMatrix<T> res(sz);
  for (int i = 0; i < sz; i++)
    for (int j = 0; j < sz; j++)
      if (i >= j)
        res[i][j] = (*this)[i][j] + p[i][j];
  return res;
}

template<typename T>
inline std::istream& operator>>(std::istream& istr, TTrMatrix<T>& v)
{
  for (int i = 0; i < v.sz; i++)
    for (int j = 0; j < v.sz; j++)
      if (i >= j)
        istr >> v.pMem[i][j];
  return istr;
}

template<typename T>
inline std::ostream& operator<<(std::ostream& ostr, const TTrMatrix<T>& v)
{
  for (int i = 0; i < v.sz; i++)
  {
    for (int j = 0; j < v.sz; j++)
      if (i >= j)
        ostr << v.pMem[i][j] << ' ';
    ostr << std::endl;
  }
  return ostr;
}