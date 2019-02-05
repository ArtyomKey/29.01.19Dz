/********************************
  Объявление класса Double Vector
 ********************************/

#define Doubvec

class double_vector{
  private:
    unsigned int size;
    unsigned int capacity;
    double* data;
    void new_data(unsigned int new_size);
    void move(double* src, double* dst, unsigned int m);
  public:
    double_vector();
    double_vector(const unsigned int s);
    double_vector(double* A, const unsigned int s);
    double_vector(const double_vector& A);
    ~double_vector();
    const double_vector& operator=(const double_vector& A);
    double operator[] (unsigned int n);
    const double_vector& operator+(const double_vector& A);
    void push_back(const double x);
    double pop_back();
    void push_front(const double x);
    double pop_front();
    unsigned int get_size();
    unsigned int get_capacity();
    void resize(const unsigned int s);
    void insert(const double x, const unsigned int pos);
    void erase(const unsigned int pos);
    void erase(const unsigned int a, const unsigned int b);
    bool finder(const double x, unsigned int& d);
};