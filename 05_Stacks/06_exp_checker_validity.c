#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch){
    stack[++top] = ch ;
}

char pop(){
    return stack[top--];
}

int isMatching(char open , char close){
    if(open == '(' && close == ')') return 1;
    if(open == '[' && close == ']') return 1;
    if(open == '{' && close == '}') return 1;
    return 0;
}

int isOperator(char ch){
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%');
}

int isValid(char exp[]){
    int operators = 0;
    int operands =0;
    int n = strlen(exp);
    
    // Expression must not start or end with operator
    if(isOperator(exp[0]))return 0;//that means it false
    if(isOperator(exp[n-1]))return 0;

    for (int i = 0; i < n; i++)
    {   char ch = exp[i];
        if(ch == ' ')continue;
        
        // Parenthesis open
        if(ch == '(' || ch == '[' || ch == '{')push(ch);
        // Parenthesis close
        else if(ch == ')' || ch == ']' || ch == '}'){
            if(top == -1)return 0;
            char last = pop();
            if(!isMatching(last,ch))return 0;
        }
        // Operand (letters or digits)
        else if(isalnum(ch))operands++;
        // Operator
        else if(isOperator(ch)){
            operators++;

            // No two consecutive operators allowed
            if(i>0 && isOperator(exp[i-1]))return 0;
        }
        else
            return 0;// Invalid character come when
    }
    // Parentheses must be balanced
    //no remain parameter in the stack.
    if(top != -1)return 0;
    // Operand count rule: operands = operators + 1
    if(operands != operators + 1)return 0;

    return 1;
}

int main(){
    char exp[MAX];
    printf("Enter an Experation : ");
    scanf("%s",exp);

    if (isValid(exp))
        printf("VALID EXPERATION");
    else
        printf("INVALID EXPERATION");

    return 0;
    
}