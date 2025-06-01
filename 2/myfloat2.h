#include "myfloat.h"

class myfloat2 : public myfloat {
private:
    char flag;
public:
    myfloat2(const myfloat& num);
    myfloat2(float num);
    myfloat2(int m, int e);
    void print() const;
};
