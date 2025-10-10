#include <stdio.h>
#include <string.h>

// returning a structure variable from a function

struct student
{
    char Name[50];
    int age;
    int mark;
};

struct student edit(struct student std)
{
    strcpy(std.Name, "ItsRiku"); // it not change the value
    std.age += 1;
    std.mark = std.mark + 1;
    return std;
}

// void print(struct student *s){
//     printf("%s %d %d\n",s->Name,s->age,s->mark);
// }
void print(struct student s)
{
    printf("%s %d %d\n", s.Name, s.age, s.mark);
}

int main()
{
    struct student s1 = {"Riku237", 18, 99};
    struct student s2 = {"suv", 19, 89};

    s1 = edit(s1); // pass a copy, get modified copy back (return is used)
    s2 = edit(s2);

    // print(&s1);
    // print(&s2);

    print(s1); // prints updated s1
    print(s2);
}
