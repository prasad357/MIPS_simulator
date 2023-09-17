The following program use an interger stack. Which value the function int pop() can return when the stack is empty, if I  want to avoid using isEmpty() before calling the pop() ?

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define STK_SIZE 100
#define INSTR_SIZE 5
int push(int * stack,int * stk_top,int operand);
int pop(int * stack,int * stk_top);

int main()
{
    
    int n_instr=0;
    int operand=0;
    int stack[STK_SIZE];
    int stk_top = -1;
    char line[INSTR_SIZE+5];

    FILE * fp = fopen("instructions.txt", "r");
            
    fgets(line, sizeof(line), stdin);
    n_instr = atoi(line);
        
    for(int i=0;i<n_instr;i++)
    {
     fgets(line, sizeof(line), stdin);
     char * opcode = strtok(line, " \n");
           
    if(!strcmp(opcode,"PUSH")){
        
        operand = atoi(strtok(NULL, " "));
        push(stack,&stk_top,operand);
                }
    else if(!strcmp(opcode,"POP")){
        
        printf("%d\n",pop(stack,&stk_top));
        
        }
    
    else if(!strcmp(opcode,"ADD")){
        
        int n1 = pop(stack,&stk_top);
        int n2 = pop(stack,&stk_top);
        push(stack,&stk_top,n1 + n2);
        
        }

    else if(!strcmp(opcode,"SUB")){
        
        int n1 = pop(stack,&stk_top);
        int n2 = pop(stack,&stk_top);
        push(stack,&stk_top,n2 - n1);
        
        }
    
    }
     fclose(fp);
     
    while(stk_top>=0)printf("%d\n",pop(stack,&stk_top));
   
    return 0;

}

int push(int * stack,int * stk_top,int operand){

if(*stk_top<STK_SIZE-1){
            (*stk_top)++;
            stack[*stk_top]=operand;
            return 0;
            }
return 1;

}

int pop(int * stack,int *stk_top){
if(*stk_top>-1){
            int n = stack[*stk_top];
            (*stk_top)--;
            return n;
            }
return 0;
}

