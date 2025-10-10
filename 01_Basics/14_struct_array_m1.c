#include <stdio.h>

// passing array of structur as argument.

struct std
{
    char Name[50];
    int Roll_no ;
    int mark[3];
};

void display(struct std s[], int n){
    for (int i = 0; i < n; i++)
    {
        printf("Name of the student is %s\n",s[i].Name);
        printf("Roll no : %d\n",s[i].Roll_no);
        for (int j = 0; j < 3; j++)
        {
            printf("mark sub%d is %d\n",j,s[i].mark[j]);
        }
        
    }
}

int main(){
    int n;
    printf("Enter no. of std. : ");
    scanf("%d",&n);
    struct std s[n];// create a struct array
    for (int i = 0; i < n; i++)
    {
        scanf("%s",s[i].Name);
        scanf("%d",&s[i].Roll_no);
        for (int j = 0; j < 3; j++)
        {
            scanf("%d",&s[i].mark[j]);
        }
        
    }

    display(s,n);

    /*display(s, n);       // array decays to pointer
    display(&s[0], n);   // explicitly pass address of first element
    struct student *ptr = s;
    display(ptr, n);     // pass pointer variable*/
    
    return 0;
}
