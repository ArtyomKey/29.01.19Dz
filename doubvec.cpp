/*******************************
 Реализация класса Double Vector
 *******************************/
 
#include <iostream>
#include "doubvec.h"
using namespace std;
void double_vector::new_data(const unsigned int s){
    delete [] data;
    data = new double[s];
    capacity = s;
}
void double_vector::move(double *src, double *dst, unsigned int m){
  if(src > dst){
    for(unsigned int i = 0; i < m; i++){
      dst[i] = src[i];
    }
  }else{
    for(unsigned int i = m-1; i != 0; i--){
      dst[i] = src[i];
    }
    dst[0] = src[0];
  }
}
//конструктор без аргументов
double_vector::double_vector(){
  size = 1;
  new_data(2);
  data[0] = 0;
}
//конструктор по размеру
double_vector::double_vector(const unsigned int s){
  size = s;
  new_data(s);
    for(unsigned int i = 0; i < size; i++){
      data[i] = 0;
    }
}
//конструктор по массиву и размеру
double_vector::double_vector(double* A, const unsigned int s){
  size = s;
  new_data(s);
  for(unsigned int i = 0; i < s; i++){
    data[i] = A[i];
  }
}
//конструктор копий
double_vector::double_vector(const double_vector& A){
  size = A.size;
  new_data(A.capacity);
  for(unsigned int i = 0; i < size; i++){
    data[i] = A.data[i];
  }
}
double_vector::~double_vector(){
  delete [] data;
  capacity = 0;
  size = 0;
}
//перегрузка присвоения
const double_vector& double_vector::operator=(const double_vector& A){
  if(capacity < A.size){
    new_data(A.size);
  }
  size = A.size;
  for(unsigned int i = 0; i < size; i++){
      data[i] = A.data[i];
    }
  return *this;
}
//перегрузка обращения по индексу
double double_vector::operator[] (unsigned int n){
  return data[n];
}
//добавление в конец
void double_vector::push_back(const double x){
  if(size >= capacity){
    capacity*= 2;
    double* temp = new double[capacity];
    move(data, temp, size);
/*      ^  вместо -> for(unsigned int i = 0; i < size; i++){
                      temp[i] = data[i];
                    }*/
    delete [] data;
    data = temp;
  }
  data[++size] = x;
}
//извлечение из конца
double double_vector::pop_back(){
  return data[size--];
}
//добавление в начало
void double_vector::push_front(const double x){
  size++;
  if(size > capacity){
    capacity*= 2;
    double* temp = new double[capacity];
    move(data, temp+1, size);
    delete [] data;
    data = temp;
  }else{
    move(data, data+1, size);
  }
  data[0] = x;
}
//извлечение из начала
double double_vector::pop_front(){
  double temp = data[0];
  move(data, data+1, size-1);
  size--;
  return temp;
}
//получение размера
unsigned int double_vector::get_size(){
  return size;
}
//получение вместимости
unsigned int double_vector::get_capacity(){
  return capacity;
}
//изменение вместимости
void double_vector::resize(const unsigned int s){
    capacity+= s;
    double* temp = new double[capacity];
    move(data, temp, size);
    delete [] data;
    data = temp;
  }
//вставка на нужное место
void double_vector::insert(const double x, const unsigned int pos){
  size++;
  if(size > capacity){
    capacity*= 2;
    double* temp = new double[capacity];
    move(data, temp, pos);
    for(unsigned int i = pos + 1; i < size; i++){
      temp[i-1] = data[i];
    }
    delete[] data;
    data = temp;
  }else{
    for(unsigned int i = size; i > pos; i++){
      data[i] = data[i-1];
    }
  }
  data[pos] = x;
}
//стереть одно значение
void double_vector::erase(const unsigned int pos){
  size--;
  double* temp = new double[size];
  move(data, temp, pos);
  for(unsigned int i = pos + 1; i < size; i++){
    temp[i-1] = data[i];
  }
  delete[] data;
  data = temp;
}
//стереть значения в промежутке
void double_vector::erase(const unsigned int a, const unsigned int b){
  size-= (b - a + 1);
  double* temp = new double[size];
  move(data, temp, a);
  for(unsigned int i = b + 1; i < size; i++){
    temp[i-(b - a + 1)] = data[i];
  }
  delete[] data;
  data = temp;
}

//поиск значения
bool double_vector::finder(const double x, unsigned int& position){
  for(unsigned int i = 0; i < size; i++){
    if(data[i] == x){
      position = i;
      return 1;
    }
  }
  return 0;
}