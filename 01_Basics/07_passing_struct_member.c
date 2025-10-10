#include <stdio.h>

// passing structure member as argument (without address)

struct std
{
    char name[50];
    int age;
};

void print(char name[], int age)
{
    printf("%s %d", name, age);
}

int main()
{
    struct std s1 = {"Riku", 19};
    print(s1.name, s1.age);
}