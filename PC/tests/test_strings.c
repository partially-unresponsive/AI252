#include <stdio.h>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define ABS1(x) (x<0)?-x:x
#define ABS2(x) (((x)<0)?-(x):(x))
#define INTER(type,a,b) {type c; c=a; a=b; b=c;}
