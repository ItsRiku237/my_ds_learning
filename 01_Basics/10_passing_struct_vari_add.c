#include <stdio.h>

// passing pointer to structure as arguments.

struct std
{
    char name[50];
    int age;
};

void print(struct std *student)
{ // use * bcz it recive address like a pointer
    printf("%s %d\n", student->name, student->age);
}

int main()
{
    struct std s1 = {"Riku", 19};
    struct std s2 = {"Rohit", 20};

    print(&s1);
    print(&s2);
}