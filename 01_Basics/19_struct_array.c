#include <stdio.h>

struct student
{
    char Name[50];
    int Roll_no;
    int Marks[3];
};
void display(struct student *p, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", p->Name);
        printf("%d\n", p->Roll_no);
        printf("%d %d %d\n", p->Marks[0], p->Marks[1], p->Marks[2]);
        p++;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    struct student s[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%s", s[i].Name);
        scanf("%d", &s[i].Roll_no);
        scanf("%d %d %d", &s[i].Marks[0], &s[i].Marks[1], &s[i].Marks[2]);
    }
    struct student *ptr = s;
    display(ptr, n);
    return 0;
}