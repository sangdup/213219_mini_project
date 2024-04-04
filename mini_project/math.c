/**********************************
********PROBLEM 6.4.1**************
**********************************/
#include<stdio.h>
#include<math.h>
double f(double x){
    return 1/(1+x);
}
/*Function definition to perform integration by Trapezoidal Rule */
double trapezoidal(double f(double x), double a, double b, int n){
  double x,h,sum=0,integral;
  int i;
  h=fabs(b-a)/n;
  for(i=1;i<n;i++){
    x=a+i*h;
    sum=sum+f(x);
  }
  integral=(h/2)*(f(a)+f(b)+2*sum);
  return integral;
}
/*Function definition to perform integration by Simpson's 1/3rd Rule */
double simpsons(double f(double x), double a,double b,double n){
  double h,integral,x,sum=0;
  int i;
  h=fabs(b-a)/n;
  for(i=1;i<n;i++){
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
int main(){
    int n,i=2;
    double a,b,h,x,integral,eps,new_integral;
   
    /*Ask the user for necessary input */
    printf("\nEnter the initial limit: ");
    scanf("%lf",&a);
    printf("\nEnter the final limit: ");
    scanf("%lf",&b);
    printf("\nEnter the desired accuracy: ");
    scanf("%lf",&eps);
    new_integral=simpsons(f,a,b,i);
 
    /* Perform integration by simpson's 1/3rd for different number of sub-intervals until they converge to the given accuracy:*/
    do{
        integral=new_integral;
        i=i+2;
        new_integral=simpsons(f,a,b,i);
    }while(fabs(new_integral-integral)>=eps);
   
    /*Print the answer */
    printf("\nThe integral using Simpson's Rule is: %lf for %d sub-intervals.\n",new_integral,i);
     
    i=2;
    /* Perform integration by trapezoidal rule for different number of sub-intervals until they converge to the given accuracy:*/
    do{
        integral=new_integral;
        i++;
        new_integral=trapezoidal(f,a,b,i);
    }while(fabs(new_integral-integral)>=eps);
 
    /*Print the answer */
    printf("The integral using Trapezoidal Rule is: %lf\n with %d intervals",new_integral,i);
}