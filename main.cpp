#include <iostream>
#include "doubvec.h"
using namespace std;

void ret(double_vector a){
  cout << a.get_capacity() << " " << a.get_size() << " "; 
  for(int i = 0; i < a.get_size(); i++){
    cout << a[i] << ";";
  }
  cout << "\n";
}
int main() {
  double_vector d;
  ret(d);
  d.~double_vector();
  int s;
  cin >> s;
  double_vector a(s);
  ret(a);
  double* A = new double[s];
  double_vector q(A, s);
  ret(q);
  double_vector w(q);
  ret(w);
  a = q;
  ret(a);
  double x;
  q.push_back(x);
  ret(q);
  q.pop_back();
  ret(q);
  q.push_front(x);
  ret(q);
  q.pop_front();
  ret(q);
  cout << q.get_size() << "\n";
  cout << q.get_capacity() << "\n";
  unsigned int cap;
  q.resize(cap);
  cout << q.get_capacity() << "\n";
  unsigned int z;
  q.insert(x, z);
  ret(q);
}