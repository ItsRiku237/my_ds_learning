#include <stdio.h>

// returning a pointer to a structure from a function

struct student
{
    int x;
    int y;
};

void edit(struct student *std)
{
    std->x += 1;
    std->y = std->y + 1;
}

void print(struct student *s)
{
    printf("%d %d\n", s->x, s->y);
}

int main()
{
    // Two actual struct student objects (a and b) are created on the stack.
    struct student a = {19, 99};
    struct student b = {199, 999};
    // s1 and s2 are pointers that hold the addresses &a and &b.
    struct student *s1 = &a;
    struct student *s2 = &b;
    // edit(s1) receives the address s1 and increments the members in-place (a.x and a.y).
    edit(s1);
    edit(s2);

    // print(s1) prints the updated values by dereferencing s1.
    print(s1);
    print(s2);
}
