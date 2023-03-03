/* Program 9.1 Pointing to functions */
#include <stdio.h>

/* Function prototypes */
int sum(int, int);
int product(int, int);
int difference(int, int);

int main(void)
{
  int a = 10;                         /* Initial value for a               */
  int b = 5;                          /* Initial value for b               */
  int result = 0;                     /* Storage for results               */
  int (*pfun)(int, int);              /* Function pointer declaration      */

  pfun = sum;                         /* Points to function sum()          */
  result = pfun(a, b);                /* Call sum() through pointer        */
  printf("\npfun = sum             result = %d", result);

  pfun = product;                     /* Points to function product()      */
  result = pfun(a, b);                /* Call product() through pointer    */
  printf("\npfun = product         result = %d", result);

  pfun = difference;                  /* Points to function difference()   */
  result = pfun(a, b);                /* Call difference() through pointer */
  printf("\npfun = difference      result = %d\n", result);
  return 0;
}


int sum(int x, int y)
{
  return x + y;
}


int product(int x, int y)
{
  return x * y;
}


int difference(int x, int y)
{
  return x - y;
}

/*函数指针数组的使用。

#include <stdio.h>

int sum(int, int);
int product(int, int);
int difference(int, int);

int main(void)
{
  int a = 10;                       
  int b = 5;                          
  int result = 0;                     
  int (*pfun[3])(int, int);           


  pfun[0] = sum;
  pfun[1] = product;
  pfun[2] = difference;


  for(int i = 0 ; i < 3 ; i++)
  {
    result = pfun[i](a, b);           
    printf("\nresult = %d", result);  
  }

  
  result = pfun[1](pfun[0](a, b), pfun[2](a, b));
  printf("\n\nThe product of the sum and the difference = %d\n",
                                                           result);
  return 0;
}


int sum(int x, int y)
{
  return x + y;
}


int product(int x, int y)
{
  return x * y;
}


int difference(int x, int y)
{
  return x - y;
}

