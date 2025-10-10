#include <stdio.h>

// passing structure member as argument ( Through address)

struct std
{
  char name[50];
  int age;
};

void scan(char name[], int *age)
{
  scanf("%s %d", name, age);
}

int main()
{
  struct std s1;
  scan(s1.name, &s1.age);
  //(it's already a pointer to the first element of the array).s1.name
  printf("%s %d", s1.name, s1.age);
  return 0;
}