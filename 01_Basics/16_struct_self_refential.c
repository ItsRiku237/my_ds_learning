#include <stdio.h>

//self refential structures

struct self
{
    int x;
    char y;
    struct self *ptr;
};

int main(){
    struct self s1;
    struct self s2;

    s1.x = 23;
    s1.y = 'R';
    s1.ptr = NULL;

    s2.x = 32 ;
    s2.y = 'S';
    s2.ptr = NULL;

    s1.ptr = &s2;

    printf("%d %c",s1.ptr->x,s1.ptr->y);
    return 0 ;

}
