#include <iostream>
#include "myfloat2.h"
template <typename T> class t_vector {
public:
    explicit t_vector(int s = 1) {
        if (s <= 0) throw s;
        try{// throw
            vptr = new T[s];//???? catch
            if (vptr == nullptr) throw std::bad_alloc();
            size = s;
        }catch (std::bad_alloc&){std::cout<<std::endl<<"Memory allocation failed"<<std::endl;}
    }
    t_vector(t_vector &);
    t_vector(t_vector &&);
    ~t_vector(){
        delete[]vptr;
        vptr = nullptr;
    }
    T& elem(int index) const;
    void operator = (const t_vector &);
    t_vector& operator = (t_vector &&) noexcept;
    t_vector operator + (const t_vector &);
    friend t_vector operator - (t_vector<T> &a, t_vector<T> &b){
        int s = a.size; if (s != b.size) throw s;
        t_vector<T> sub(s);
        myfloat *sp = sub.vptr;
        myfloat *ap = a.vptr;
        myfloat *bp = b.vptr;
        while(s--)*sp++ = *ap++ - *bp++;
        return sub;
    }
    T& operator [] (int) const;
    void print() const;
private:
    int size;
    T * vptr;
};
template <typename T> void t_vector<T>::print() const{
    for (int i = 0; i < size; i++) {
        std::cout<<vptr[i]<<" ";
    }
}
template <> inline void t_vector<myfloat>::print() const{
    for (int i = 0; i < size; i++) {
        vptr[i].print();
    }
}
template <typename T> t_vector<T>::t_vector(t_vector& a) : t_vector(a.size){
    int s = size;
    for(int i = 0; i < s; i++) {elem(i) = a.elem(i);}
}
template <typename T> t_vector<T>::t_vector(t_vector&& a) : t_vector(a.size) {
    if (this == &a) return;
    delete[] vptr;
    vptr = a.vptr; size = a.size;
    a.vptr = nullptr; a.size = 0;
}
template <typename T> T& t_vector<T>::elem(int i) const {return vptr[i];};
template <typename T> t_vector<T> t_vector<T>::operator+ (const t_vector &a){
    if (a.size != size) throw size;
    int s = size;
    t_vector b(s);
    for (int i = 0; i < s; i++) {b.elem(i) = elem(i) + a.elem(i);}
    return b;
}
template <typename T> void t_vector<T>::operator = (const t_vector &a) {
    if (this != &a) {
        if (size != a.size) {
            delete[] vptr;
            size = a.size;
            t_vector d(a.size);
            vptr = d.vptr;
            d.vptr = nullptr; d.size = 0;
        }
        for (int i = 0; i < size; i++) {
            elem(i) = a.elem(i);
        }
    }
}
template <typename T> t_vector<T>& t_vector<T>::operator = (t_vector &&a) noexcept{
    if (this == a) return *this;
    delete[] vptr;//????
    vptr = a.vptr; size = a.size;
    a.vptr = nullptr; a.size = 0;
    return *this;
}
template <typename T> T& t_vector<T>::operator[](int ind) const {
    if (ind < 0 || ind >=size) throw ind;
    return vptr[ind];
}