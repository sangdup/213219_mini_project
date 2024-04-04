#include<stdio.h>
#include<math.h>

double f(double x)
{
 return 1/(1+x);
}

double trapezoidal(double f(double x), double a, double b, int n)	//n = number of intervals
{
 double h, x,sum=0,integral;
 h = fabs(a+b)/n;
 for(int i=1;i<n;i++)
  {
   // printf("%d",i);
   x=a+i*h;
   sum=sum+f(x);
  }
  integral=((h/2)*(f(a)+f(b)))+(h*sum);
  return integral;
}

double simpsons(double f(double x), double a, double b, int n)
{
 double h,integral,x,sum=0;
  h=fabs(b-a)/n;
  for(int i=1;i<n;i++)
  {
    x=a+i*h;
    if(i%2==0){
      sum=sum+2*f(x);
    }
    else{
      sum=sum+4*f(x);
    }
  }
  integral=(h/3)*(f(a)+f(b)+sum);
  return integral;

}

int main()
{
 int n=2;
    double a, b, eps, integral, new_integral;

    printf("\nEnter the lower limit: ");
    scanf("%lf",&a);
    printf("\nEnter the upper limit: ");
    scanf("%lf",&b);
    printf("\nEnter the desired accuracy: ");
    scanf("%lf",&eps);
    new_integral=trapezoidal(f,a,b,n);  
    do{
        integral=new_integral;
        n++;
        new_integral=trapezoidal(f,a,b,n);
    }while(fabs(new_integral-integral)>=eps);   //error is being found inside while loop

     printf("The integral using Trapezoidal Rule is: %lf with %d intervals\n",new_integral,n);

    new_integral=simpsons(f,a,b,n);
     do{
        integral=new_integral;
        n=n+2;
        new_integral=simpsons(f,a,b,n);
    }while(fabs(new_integral-integral)>=eps);
 
    printf("The integral using Simpsons Rule is: %lf with %d intervals\n",new_integral,n);
}

