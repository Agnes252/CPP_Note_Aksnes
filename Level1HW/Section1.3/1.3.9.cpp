/* Conditional expressions

Ruochen Bao
*/

#include <stdio.h>

int main()
{
    int x=1;
    int y=1;
    int z=1;
    
    x+=y+=x; // x=3, y=2, z=1
    printf("%d\n", (x<y)?y:x); // 3
    printf("%d\n", (x<y)?x++:y++); // 2 (y = 3, x = 3)
    printf("%d\n", x); // 3
    printf("%d\n", y); // 3
    return 0;
}