#include "header.h"

double f(double x)
{
 return 1/(1+x);
}

double diff(double h, double x)
{
 double d, a, b, f1, f2;
 a=x+h;
 b=x;
 f1=f(a);
 f2=f(b);
 d=(f1-f2)/(h);
 return d;
}

int main()
{
 double x,h, result;
 printf("Enter the value of h:\n");
 scanf("%lf",&h);
 printf("Enter the value of x:\n");
 scanf("%lf",&x);
 result=diff(h,x);
 printf("The result is:%lf\n",result);
 return 0;
}