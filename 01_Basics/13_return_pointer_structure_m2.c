#include<stdio.h>
#include<stdlib.h>//for malloc function

// returning a pointer to a structure from a function

struct pointer{
    int x;
    int y;
};

// Function returns a pointer to a struct
struct pointer* func(int a , int b){
    // we use malloc bcz it sore in heap after function ended it remain in the heap memory.
    struct pointer *ptr = (struct pointer*)malloc(2*sizeof(struct pointer));
    if (ptr == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    
    ptr->x =a+1;
    ptr->y =b+1;
    return ptr;//returning pointer
}


void print(struct pointer *s){
    printf("%d %d\n",s->x,s->y);
}

int main(){

    struct pointer *ptr1 ;
    struct pointer *ptr2 ;
    
    ptr1 = func(19,1999);
    ptr2 = func(89,899);

   
    print(ptr1);
    print(ptr2);

    free(ptr1);
    free(ptr2);
    return 0;
}



//alternate method
//Return struct by value (no pointer)

/*#include <stdio.h>

struct pointer {
    int x;
    int y;
};

struct pointer func(int a, int b) {
    struct pointer temp;
    temp.x = a + 1;
    temp.y = b + 1;
    return temp;   // returning struct by value
}

void print(struct pointer s) {
    printf("%d %d\n", s.x, s.y);
}

int main() {
    struct pointer ptr1;
    struct pointer ptr2;

    ptr1 = func(19, 1999);
    ptr2 = func(89, 899);

    print(ptr1);
    print(ptr2);

    return 0;
}
*/