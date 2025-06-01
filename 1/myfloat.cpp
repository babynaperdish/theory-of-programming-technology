#include <stdio.h>
#include <cmath>
#include "myfloat.h"

myfloat::myfloat(double val) {
    int m = 0, e = 0;
    while (fabs(val)  >= 1.0){
        val /= 10.0; e++;
    }
    while (fabs(val) < 0.1) {
        val *= 10; e--;
    }
    m = (int)(val * 1000.0); //(3 порядка точность)
    mant = m; exp = e;
}

myfloat::myfloat(){mant = 0, exp = 0;};

myfloat::myfloat(int m = 0, int e = 0) {
    mant = m; exp = e;

    while (abs(mant)  >= 1000){
        mant /= 10;
        exp++;
    }
    while (abs(mant) < 100) {
        mant *= 10; exp--;
    }
}

void myfloat::print() const{
    printf("%d,%d[%f] ", mant, exp, mant/1000.0 * std::pow(10.0, exp));
}

myfloat operator + (myfloat a1, myfloat a2) {
    while (a1.exp < a2.exp) {
        a2.mant *= 10; a2.exp--;
    }
    while (a2.exp < a1.exp) {
        a1.mant *= 10; a1.exp--;
    }
    return myfloat(a1.mant + a2.mant, a1.exp);
}

myfloat operator - (myfloat a1, myfloat a2) {
    while (a1.exp < a2.exp) {
        a2.mant *= 10; a2.exp--;
    }
    while (a2.exp < a1.exp) {
        a1.mant *= 10; a1.exp--;
    }
    return myfloat(a1.mant - a2.mant, a1.exp);
}

myfloat operator * (myfloat a1, myfloat a2) {
    return myfloat(a1.mant * a2.mant/1000, a1.exp + a2.exp);
}

myfloat operator / (myfloat a1, myfloat a2) {
    return myfloat(a1.mant * 1000 / a2.mant, a1.exp - a2.exp);
}






