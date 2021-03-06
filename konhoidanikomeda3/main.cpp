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
    double geta() const;
    double getl() const;
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

double konhoida:: geta() const
{
    return a;
}

double konhoida::getl() const
{
    return l;
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
    std::cout<<"Choose your task"<<endl;
    std::cout<<"1 - get a,l"<<endl;
    std::cout<<"2 - set a,l"<<endl;
    std::cout<<"3 - find y"<<endl;
    std::cout<<"4 - distination to the centre"<<endl;
    std::cout<<"5 - radius of curvature"<<endl;
    std::cout<<"6 - square of kink"<<endl;
    std::cout<<"7 - point of nip"<<endl;
    std::cout<<"0 - quit"<<endl;
}


int main()
{
    konhoida k(1,1);
    while (1)
    {
        menu();
        int res=0;
        int menu=0;
        res = getNum(menu,"");
        if (res<0)
            break;
        else
            switch (menu)
        {
            case 0:
            {
                exit(0);
                break;
            }
            case 1:
            {
                double a= k.geta();
                double l= k.getl();
                cout << "a:  " << a <<"\nl:  "<<l<<endl;
                break;
            }
            case 2:
            {
                int a = 0;
                int l=0;
                getNum(a, "write a: ");
                getNum(l,"write l: ");
                k.set(a,l);
                break;
            }
            case 3:
            {
                double x;
                getNum(x, "X: ");
                cout << "Y:" << k.yValue(x) << endl;
                break;
            }
            case 4:
            {
                double angle;
                getNum(angle, "Angle: ");
                cout << "Distance:" << k.distination(angle) << endl;
                break;
            }
            case 5:
            {
                cout << "Radius 1: " << k.rKriv1() << endl;
                cout<<"Radius 2: "<<k.rKriv2()<<endl;
                cout<<"Radius 3: "<<k.rKriv3()<<endl;
                break;
            }
            case 6:
            {
                cout << "Square: " << k.sPetl()<< endl;
                break;
            }
            case 7:
            {
                double a=k.geta();
                double l=k.getl();
                if (a>l)
                {
                    cout<<"X: "<<k.tPereg11()<<"\nY: "<<k.yValue(k.tPereg11())<<endl;
                }
                if (a==l)
                {
                    cout<<"X1: "<<k.tPereg21()<<"\nY1: "<<k.yValue(k.tPereg21())<<"\nX2: "<<k.tPereg22()<<"\nY2: "<<k.yValue(k.tPereg22())<<"\nX3: "<<k.tPereg23()<<"\nY3: "<<k.yValue(k.tPereg23())<<endl;
                }
                if (a<l)
                {
                    cout<<"X1: "<<k.tPereg31()<<"\nY1: "<<k.yValue(k.tPereg31())<<"\nX2: "<<k.tPereg32()<<"\nY2: "<<k.yValue(k.tPereg32())<<"\nX3: "<<k.tPereg33()<<"\nY3: "<<k.yValue(k.tPereg33())<<endl;
                }

            }
            default:
            {
                menu;
                break;
            }
        }
    }
    system("pause");
    return 0;
}
     

































