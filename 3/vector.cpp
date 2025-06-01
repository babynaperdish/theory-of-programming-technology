#include <stdio.h>
#include <system_error>
#include "vector.h"

vector::vector(int s) {
    if (s <= 0) perror("123");
    vptr = new myfloat[s];
    if (vptr == nullptr) perror("456");
    size = s;
}
vector::~vector() {
    delete[]vptr;
    vptr=nullptr;
}
vector::vector(vector& a) : vector(a.size){
    int s = size;
    for(int i = 0; i < s; i++) {elem(i) = a.elem(i);}
}
vector::vector(vector&& a) : vector(a.size) {
    if (this == &a) return;
    delete[] vptr;
    vptr = a.vptr; size = a.size;
    a.vptr = nullptr; a.size = 0;
}
myfloat& vector::elem(int i) const {return vptr[i];};
vector vector::operator+ (const vector &a) const{
    if (a.size != size) perror("998");
    int s = size;
    vector b(size);
    for (int i = 0; i < size; i++) {b.elem(i) = elem(i) + a.elem(i);}
    return b;
}
vector operator - (vector &a, vector &b){
    int s = a.size; if (s != b.size) perror("111");
    vector sub(s);
    myfloat *sp = sub.vptr;
    myfloat *ap = a.vptr;
    myfloat *bp = b.vptr;
    while(s--)*sp++ = *ap++ - *bp++;
    return sub;
}
void vector::operator = (const vector &a) {
    if (this == &a) return;
    if (size != a.size) {
        delete[] vptr;
        size = a.size;
        vector d(a.size);
        vptr = d.vptr;
        d.vptr = nullptr; d.size = 0;
    }
    for (int i = 0; i < size; i++) {
        elem(i) = a.elem(i);
    }
}
vector& vector::operator = (vector &&a) noexcept{
    if (this == &a) return *this;
    delete[] vptr;
    vptr = a.vptr; size = a.size;
    a.vptr = nullptr; a.size = 0;
    return *this;
}
myfloat& vector::operator[](int ind) const {
    if (ind < 0 || ind >=size) perror("666");
    return vptr[ind];
}
void vector::print() const{
    for (int i = 0; i < size; i++) {
        vptr[i].print();
    }
}