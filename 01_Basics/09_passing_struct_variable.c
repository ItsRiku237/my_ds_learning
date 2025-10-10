#include <stdio.h>

// Passsing structur variable as argument

struct std
{
    char name[50];
    int age;
};

void print(struct std student)
{
    printf("%s %d\n", student.name, student.age);
}

int main()
{
    struct std s1 = {"Riku", 19};
    struct std s2 = {"Rohit", 20};

    print(s1);
    print(s2);
}