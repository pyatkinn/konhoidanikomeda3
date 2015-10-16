//
//  main.cpp
//  konhoidanikomeda3
//
//  Created by Никита Пяткин on 12.10.15.
//  Copyright © 2015 Никита Пяткин. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>

using std::cin;
using std::cout;
using std::endl;

class konhoida{
private:
    double a,l;
public:
    konhoida(double a=1,double l=1);
    ~konhoida();
    double get() const;
    void set(double a,double l);
    double yValue(double x);
    double distination(double angle);
    double rKriv1();
    double rKriv2();
    double rKriv3();
    double sPetl();
    double tPereg11();
    double tPereg21();
    double tPereg22();
    double tPereg23();
    double tPereg31();
    double tPereg32();
    double tPereg33();
};


konhoida::konhoida(double a,double l)
{
    this->a=a;
    this->l=l;
}

konhoida::~konhoida()
{
}

double konhoida:: get() const
{
    return a;
}

void konhoida::set(double a,double l)
{
    this->a=a;
    this->l=l;
}

double konhoida::yValue(double x)
{
    return (sqrt((l*l*x*x)/(x-a)*(x-a)-x*x));
}

double konhoida::distination(double angle)
{
    return (a/cos(angle)+l);
}

double konhoida::rKriv1()
{
    return (((l+a)*(l+a))/2);
}

double konhoida::rKriv2()
{
    return (((l-a)*(l-a))/2);
}

double konhoida::rKriv3()
{
    return ((l*sqrt(l*l-a*a))/(2*a));
}

double konhoida::sPetl()
{
    return (a*sqrt(l*l-a*a)-2*a*l*log((1+sqrt(l*l-a*a))/a)+l*l*acos(a/l));
}

double konhoida::tPereg11()
{
    return (2.35*a);
}

double konhoida::tPereg21()
{
    return (a*sqrt(3));
}

double konhoida::tPereg22()
{
    return 0;
}

double konhoida::tPereg23()
{
    return (-a*sqrt(3));
}

double konhoida::tPereg31()
{
    return (1.38*a);
}

double konhoida::tPereg32()
{
    return (0.57*a);
}

double konhoida::tPereg33()
{
    return (-1.9*a);
}




int getNum(int& a,char *info);
double getNum(double& a,char *info);
void menu();


int getNum(int& a,char *info);
double getNum(double& a,char *info);
void menu();

int getNum(int& a,char *info)
{
    int data;
    std::cout<<info<<endl;
    std::cin>>data;
    if (!std::cin.good())
    {
        std::cout<<"error"<<std::endl;
        std::cin.clear();
        return -1;
    }
    a=data;
    return 0;
    
}

double getNum(double& a,char *info)
{
    double data;
    std::cout<<info<<endl;
    std::cin>>data;
    if (!std::cin.good())
    {
        std::cout<<"error"<<std::endl;
        std::cin.clear();
        return -1;
    }
    a=data;
    return 0;
    
}

void menu()
{
    
}

































