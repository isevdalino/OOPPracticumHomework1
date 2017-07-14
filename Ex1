//implementing polynomial with integer coefficients
#include <iostream>
#include <assert.h>
using namespace std;
class Polynomial{
  int k1;
  int k2;
  int k3;
  int k4;
  public:
  Polynomial(){
    k1=1;
    k2=2;
    k3=-1;
    k4=1;
  }
  Polynomial(int k1,int k2,int k3,int k4){
    this->k1=k1;
    this->k2=k2;
    this->k3=k3;
    this->k4=k4;
  }
  double evaluate(double x)const{
    return k1*(x*x*x)+k2*(x*x)+k3*x+k4;
  }
  void printPolinomial(){
    cout<<k1<<"x^3+"<<"("<<k2<<")"<<"x^2+"<<"("<<k3<<")"<<"x+"<<"("<<k4<<")"<<endl;
  }
  void setCoef(int degree, int newCoef){
    assert((degree>=0)&&(degree<=3));
    if(degree==3){
      k1=newCoef;
    }else if(degree==2){
      k2=newCoef;
    }
    else if(degree==1){
      k3=newCoef;
    }else if(degree==0){
      k4=newCoef;
    }
  }
  int getCoef(int degree) const{
    assert(degree>=0&&degree<=3);
    if(degree==3){
      return k1;
    }else if(degree==2){
      return k2;
    }
    else if(degree==1){
      return k3;
    }else if(degree==0){
      return k4;
    }
  }


};
int main()
{
    Polynomial pol;
    pol.printPolinomial();
    cout<<"x=1,the value of the polynomial in x is:"<<pol.evaluate(1)<<endl;
    cout<<"Change the coefficient in front of the 2 degree:"<<endl;
    pol.setCoef(2,4);
    cout<<"Get the coefficient in front of the 2 degree:"<<pol.getCoef(2)<<endl;
    cout<<"x=1,the value of the polynomial in x is:"<<pol.evaluate(1)<<endl;
    //creating new polynomial with parameterized constructor and printing it on the screen
    Polynomial pol2(1,2,3,4);
    pol2.printPolinomial();
    return 0;
}
//implementing polynomial with rational coefficients
/*#include<iostream>
#include<assert.h>

using namespace std;
class Rat{
  int nominator;
  int denominator;
  public:
  Rat(){

  }
  Rat(const Rat& rat2){
    this->denominator=rat2.denominator;
    this->nominator=rat2.nominator;
  }
  void initializeRat(int nominator,int denominator){
    this->nominator=nominator;
    this->denominator=denominator;
  }
  int getNominator(){
    return nominator;
  }
   int getDenominator(){
    return denominator;
  }
  Rat operator+(Rat rat2){
    Rat rat3;
    rat3.nominator=(this->nominator*rat2.denominator)+(this->denominator*rat2.nominator);
    rat3.denominator=this->denominator*rat2.denominator;
    return rat3;
  }
  Rat operator*(Rat rat2){
    Rat rat3;
    rat3.nominator=(this->nominator*rat2.nominator);
    rat3.denominator=this->denominator*rat2.denominator;
    return rat3;
  }
  Rat operator*(double x){
    Rat rat3;
    rat3.nominator=this->nominator*x;
    rat3.denominator=this->denominator;
    return rat3;
  }
  void operator=(Rat rat2){
    this->nominator=rat2.nominator;
    this->denominator=rat2.denominator;
  }
};
class Polynomial{
  Rat k1;
  Rat k2;
  Rat k3;
  Rat k4;
  Rat* resultRat;
  public:
  Polynomial(){
    k1.initializeRat(1,2);
    k2.initializeRat(1,3);
    k3.initializeRat(-1,2);
    k4.initializeRat(4,2);
  }
  Polynomial(Rat k1,Rat k2,Rat k3,Rat k4){
    this->k1=k1;
    this->k2=k2;
    this->k3=k3;
    this->k4=k4;
  }
  ~Polynomial(){
    delete resultRat;
  }
  Rat& evaluate(double x){
    resultRat=new Rat;
    double x3=x*x*x;
    double x2=x*x;
    Rat first=k1*x3;
    Rat second=k2*x2;
    Rat third=k3*x;
    Rat rat1=first+second;
    Rat rat2=rat1+third;
    Rat result=rat2+k4;
    resultRat=&result;
    return *resultRat;
  }
  void printPolinomial(){
    cout<<k1.getNominator()<<"/"<<k1.getDenominator()<<"x^3+"<<"("<<k2.getNominator()<<"/"<<k2.getDenominator()<<")"<<"x^2+"
    <<"("<<k3.getNominator()<<"/"<<k3.getDenominator()<<")"<<"x+"<<"("<<k4.getNominator()<<"/"<<k4.getDenominator()<<")"<<endl;
  }
  void setCoef(int degree, Rat newCoef){
    assert((degree>=0)&&(degree<=3));
    if(degree==3){
      k1=newCoef;
    }else if(degree==2){
      k2=newCoef;
    }
    else if(degree==1){
      k3=newCoef;
    }else if(degree==0){
      k4=newCoef;
    }
  }
  Rat& getCoef(int degree){
    assert(degree>=0&&degree<=3);
    if(degree==3){
      return k1;
    }else if(degree==2){
      return k2;
    }
    else if(degree==1){
      return k3;
    }else if(degree==0){
      return k4;
    }
  }


};
int main()
{
    Polynomial pol;
    Rat newCoef;
    newCoef.initializeRat(4,2);
    Rat newCoef1;
    newCoef1.initializeRat(4,2);
    Rat newCoef2;
    newCoef2.initializeRat(3,2);
    Rat newCoef3;
    newCoef3.initializeRat(2,2);
    Rat newCoef4;
    newCoef4.initializeRat(1,2);
    pol.printPolinomial();
    cout<<"x=1,the value of the polynomial in x is:"<<pol.evaluate(1).getNominator()<<"/"<<pol.evaluate(1).getDenominator()<<endl;
    cout<<"Change the coefficient in front of the 2 degree:"<<endl;
    pol.setCoef(2,newCoef);
    cout<<"Get the coefficient in front of the 2 degree:"<<pol.getCoef(2).getNominator()<<"/"<<pol.getCoef(2).getDenominator()<<endl;
    cout<<"x=1,the value of the polynomial in x is:"<<pol.evaluate(1).getNominator()<<"/"<<pol.evaluate(1).getDenominator()<<endl;
    //creating new polynomial with parameterized constructor and printing it on the screen
    Polynomial pol2(newCoef1,newCoef2,newCoef3,newCoef4);
    pol2.printPolinomial();
    return 0;
}*/

//implementing polynomial with complex coefficients
/*#include<iostream>
#include<assert.h>

using namespace std;
class Complex{
  int re;
  int im;
  public:
  Complex(){
  }
  Complex(const Complex& complex2){
    this->re=complex2.re;
    this->im=complex2.im;
  }
  void initializeComplex(int re,int im){
    this->im=im;
    this->re=re;
  }
  int getRe(){
    return re;
  }
   int getIm(){
    return im;
  }
  Complex operator+(Complex complex2){
    Complex complex3;
    complex3.re=this->re+complex2.re;
    complex3.im=this->im+complex2.im;
    return complex3;
  }
  Complex operator*(double x){
    Complex complex3;
    complex3.re=this->re*x;
    complex3.im=this->im*x;
    return complex3;
  }
  void operator=(Complex complex2){
    this->re=complex2.re;
    this->im=complex2.im;
  }
};
class Polynomial{
  Complex k1;
  Complex k2;
  Complex k3;
  Complex k4;
  Complex* resultComplex;
  public:
  Polynomial(){
    k1.initializeComplex(1,2);
    k2.initializeComplex(1,3);
    k3.initializeComplex(-1,2);
    k4.initializeComplex(4,2);
  }
  Polynomial(Complex k1,Complex k2,Complex k3,Complex k4){
    this->k1=k1;
    this->k2=k2;
    this->k3=k3;
    this->k4=k4;
  }
  ~Polynomial(){
    delete resultComplex;
  }
  Complex& evaluate(double x){
    resultComplex=new Complex;
    double x3=x*x*x;
    double x2=x*x;
    Complex first=k1*x3;
    Complex second=k2*x2;
    Complex third=k3*x;
    Complex Complex1=first+second;
    Complex Complex2=Complex1+third;
    Complex result=Complex2+k4;
    resultComplex=&result;
    return *resultComplex;
  }
  void printPolinomial(){
    cout<<"("<<k1.getRe()<<"+"<<k1.getIm()<<"i)"<<"x^3+"<<"("<<k2.getRe()<<"+"<<k2.getIm()<<"i)"<<"x^2+"
    <<"("<<k3.getRe()<<"+"<<k3.getIm()<<"i)"<<"x+"<<"("<<k4.getRe()<<"+"<<k4.getIm()<<"i)"<<endl;
  }
  void setCoef(int degree, Complex newCoef){
    assert((degree>=0)&&(degree<=3));
    if(degree==3){
      k1=newCoef;
    }else if(degree==2){
      k2=newCoef;
    }
    else if(degree==1){
      k3=newCoef;
    }else if(degree==0){
      k4=newCoef;
    }
  }
  Complex& getCoef(int degree){
    assert(degree>=0&&degree<=3);
    if(degree==3){
      return k1;
    }else if(degree==2){
      return k2;
    }
    else if(degree==1){
      return k3;
    }else if(degree==0){
      return k4;
    }
  }


};
int main()
{
    Polynomial pol;
    Complex newCoef;
    newCoef.initializeComplex(4,2);
    Complex newCoef1;
    newCoef1.initializeComplex(4,2);
    Complex newCoef2;
    newCoef2.initializeComplex(3,2);
    Complex newCoef3;
    newCoef3.initializeComplex(2,2);
    Complex newCoef4;
    newCoef4.initializeComplex(1,2);
    pol.printPolinomial();
    cout<<"x=1,the value of the polynomial in x is:"<<pol.evaluate(1).getRe()<<"+("<<pol.evaluate(1).getIm()<<"i)"<<endl;
    cout<<"Change the coefficient in front of the 2 degree:"<<endl;
    pol.setCoef(2,newCoef);
    cout<<"Get the coefficient in front of the 2 degree:"<<pol.getCoef(2).getRe()<<"+("<<pol.getCoef(2).getIm()<<"i)"<<endl;
     cout<<"x=1,the value of the polynomial in x is:"<<pol.evaluate(1).getRe()<<"+("<<pol.evaluate(1).getIm()<<"i)"<<endl;
    //creating new polynomial with parameterized constructor and printing it on the screen
    Polynomial pol2(newCoef1,newCoef2,newCoef3,newCoef4);
    pol2.printPolinomial();
    return 0;
}*/
