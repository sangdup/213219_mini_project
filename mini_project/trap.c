#include<stdio.h>
#include<math.h>

double f(double x)
{
return 1/(1+x);

}

//function definition to perform integration by trapezoidal rule
double trapezoidal(double f(double x), double a, double b, int n)
{
  double x,h,sum=0,integral;
  int i;
  h=fabs(b-a)/n;
  for(i=1;i<n;i++){
    x=a+i*h;
    sum=sum+f(x);
  }
  //integral=(h/2)*(f(a)+f(b)+2*sum);
    integral=((h/2)*(f(a)+f(b)))+(h*sum);           //both will work
  return integral;
}



int main()
{
 int n,i=2;
    double a, b, eps, integral, integral_new;
   
    /*Ask the user for necessary input */
    printf("\nEnter the lower limit: ");
    scanf("%lf",&a);
    printf("\nEnter the upper limit: ");
    scanf("%lf",&b);
    printf("\nEnter the desired accuracy: ");
    scanf("%lf",&eps);
    integral_new=trapezoidal(f,a,b,i);
    do{
        integral=integral_new;
        i++;
        integral_new=trapezoidal(f,a,b,i);
    }while(fabs(integral_new-integral)>=eps);
 
    /*Print the answer*/
    printf("The integral using Trapezoidal Rule is: %lf with %d intervals\n",integral_new,i);
}

