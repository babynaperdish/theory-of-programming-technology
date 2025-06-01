#include <stdio.h>
#include "myfloat2.h"

myfloat2::myfloat2(float num) : myfloat(num) {
    if (exp >= 3) {
        flag = 1; mant = 999 * ((mant > 0) ? 1 : -1); exp = 3;
    }
    else {
        flag = 0;
    };
};
myfloat2::myfloat2(int m, int e) : myfloat(m, e) {
    if (exp >= 3) {
        flag = 1; mant = 999 * ((mant > 0) ? 1 : -1); exp = 3;
    }
    else {
        flag = 0;
    };
};

myfloat2::myfloat2(const myfloat& num) : myfloat(num) {
    if (exp >= 3) {
        flag = 1; mant = 999 * ((mant > 0) ? 1 : -1); exp = 3;
    }
    else {
        flag = 0;
    }
}
void myfloat2::print() const {
    myfloat::print();
    if (flag) printf("* ");
}