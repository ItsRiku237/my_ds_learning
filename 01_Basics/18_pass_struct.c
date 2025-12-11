#include <stdio.h>

struct student
{
    char name[20];
    int roll_no;
};

void display1(char name[], int roll)
{
    puts(name);
    printf("%d\n", roll);
}

void display2(struct student std)
{
    puts(std.name); 
    printf("%d\n", std.roll_no);
}

void display3(struct student *std)
{
    puts(std->name);
    printf("%d\n", std->roll_no);
}

int main()
{
    struct student s1;
    gets(s1.name);
    scanf("%d", &s1.roll_no);
    display1(s1.name, s1.roll_no);//member as argument
    display2(s1);//variable as argument
    struct student *ptr = &s1 ; //in struct we use keyword 'struct student' but in array we use in
    display3(ptr) ;//structure as argument

    return 0;
}