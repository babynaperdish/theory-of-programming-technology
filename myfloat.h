class myfloat {
protected:
    int mant, exp;
public:
    myfloat();
    myfloat(double value);
    myfloat(int m, int e);
    friend myfloat operator + (myfloat, myfloat);
    friend myfloat operator - (myfloat, myfloat);
    friend myfloat operator * (myfloat, myfloat);
    friend myfloat operator / (myfloat, myfloat);
    void print() const;
};