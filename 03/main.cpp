//题目内容：编写复数类实现复数的加法，请在/********program********/与/********end********/处将代码补充完整

#include<iostream>
#include<cmath>
using namespace std;
/********program********/
class Complex{
private:
    int R=0;
    int I=0;
public:
    Complex(){};
    Complex(int r,int i);
    void print();
    Complex add(Complex &a);
};

Complex::Complex(int r, int i) {
    R=r;
    I=i;
}

Complex Complex::add(Complex &a) {
    Complex result;
    result.I=I+a.I;
    result.R+=R+a.R;
    return result;
}
/********end********/

void Complex::print()
{
    if(R!=0)
        if(I>0)
            cout<<R<<'+'<<I<<'i'<<endl;
        else if(I<0)
            cout<<R<<'-'<<fabs(I)<<'i'<<endl;
        else
            cout<<R<<endl;
    else
    if(I!=0)
        cout<<I<<'i'<<endl;
    else
        cout<<R<<endl;
}

int main()
{
    double r1,i1,r2,i2;
    cin>>r1>>i1>>r2>>i2;
    Complex A(r1,i1),B(r2,i2),C(0,0);
    C=A.add(B);
    A.print();
    B.print();
    C.print();
    return 0;
}

/*
    输入格式：两个实部和虚部
    输出格式：三个复数
    输入样例：3 4 5 6
    输出样例：
    3+4i
    5+6i
    8+10i
 */