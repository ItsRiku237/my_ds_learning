#include<stdio.h>
#include<string.h>

int main(){
    char str[]={"Hello"};
    int len =strlen(str);
    char temp;

    for (int i = 0; i < len/2; i++)
    {
        temp=str[i];
        str[i]=str[len-1-i];
        str[len-1-i]= temp;
    }
    
    for (int i = 0; i < len; i++)
    {
        printf("%c",str[i]);
    }
    
    return 0;
}