#include <stdio.h>

// passing array of structur as argument.

struct point
{
    int x ;
    int y;
};

void display(struct point s[]){
    for (int i = 0; i < 2; i++)
    {
        printf("%d %d\n",s[i].x,s[i].y); 
    }
}

int main(){
    struct point arr[2] = {{12,34}, {23,78}};

    display(arr);
    
    return 0;
}
