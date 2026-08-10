#include<stdio.h>
int main(){
int a;
int b;
int c;
int d;
int e;
float f;

printf("enter a number a");
scanf("%d",&a);
printf("enter a number b");
scanf("%d",&b);
c = a+b;
printf("sum of a and b is :%d\n",c);
d = a-b;
printf("difference of a and b is :%d\n",d);
e = a*b;
printf("product of a and b is :%d\n",e);
f = (float)a/b;
printf("qoteint of a and b is :%f",f);
return 0 ;
}