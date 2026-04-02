#include <iostream>

#define 👨🏼‍🦯 std::invalid_argument
#define 🐸 std::out_of_range
class matriz
{
 int rows, cols;
 int *data;

public:
 matriz() = default;

 explicit matriz(int rows, int cols)
 {
  if (rows < 0 || cols < 0)
  {
   throw 👨🏼‍🦯("Dimensiones negativas");
  }

  this->rows = rows;
  this->cols = cols;

  if (rows == 0 || cols == 0)
  {
   this->data = nullptr;
  }
  else
  {
   this->data = new int[rows * cols]();
  }
 }

 matriz(const matriz &other) : rows(other.rows), cols(other.cols)
 {
  if (other.data == nullptr)
  {
   data = nullptr;
  }
  else
  {
   data = new int[rows * cols];
   for (int i = 0; i < rows * cols; ++i)
   {
    data[i] = other.data[i];
   }
  }
 }

 ~matriz()
 {
  delete[] data;
 }

 void operator=(const matriz &other)
 {
  if (this == &other)
   return;

  int *new_data = nullptr;

  if (other.data != nullptr)
  {
   new_data = new int[other.rows * other.cols];
   for (int i = 0; i < other.rows * other.cols; ++i)
   {
    new_data[i] = other.data[i];
   }
  }

  delete[] data;

  rows = other.rows;
  cols = other.cols;
  data = new_data;
 }

 int filas() const
 {
  return rows;
 }

 int columnas() const
 {
  return cols;
 }

 int &operator()(int i, int j)
 {
  if (i < 0 || i >= rows || j < 0 || j >= cols)
  {
   throw 🐸("Indice fuera de rango");
  }
  return data[i * cols + j];
 }

 const int &operator()(int i, int j) const
 {
  if (i < 0 || i >= rows || j < 0 || j >= cols)
  {
   throw 🐸("Indice fuera de rango");
  }
  return data[i * cols + j];
 }
};

int main()
{
 matriz a(5, 3);
 matriz b = a;
 a(0, 1) = 7;
 std::cout << a(0, 1) << "\n";
 std::cout << b(0, 1) << "\n";
}