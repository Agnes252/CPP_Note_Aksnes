#ifndef PRINT1
#define PRINT1(a) printf("a = %lf\n", a)
#endif 

#ifndef PRINT2
#define PRINT2(a, b) printf("a = %lf, b = %lf\n", a, b)
#endif 

#ifndef MAX2
#define MAX2(x, y) ((x>=y) ? x : y)
#endif

#ifndef MAX3
#define MAX3(x, y, z) (MAX2(MAX2(x, y), z))
#endif

#ifndef PRINT
#define PRINT(a) printf("max = %lf\n", a)
#endif 
