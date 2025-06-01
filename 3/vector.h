#include "myfloat2.h"
class vector {
public:
    vector(int length = 1);
    vector(vector &);
    vector(vector &&);
    ~vector();
    myfloat& elem(int) const;
    void operator = (const vector &);//???+
    vector& operator = (vector &&) noexcept;//??+
    vector operator + (const vector &) const;
    friend vector operator - (vector &, vector &);
    myfloat& operator [] (int) const;
    void print() const;
private:
    int size;
    myfloat * vptr;
};
