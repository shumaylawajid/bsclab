/*stack.c*/
#include<stdio.h>
#define N 25
struct stacktype
{ int s[N];
  int top;
};
typedef struct stacktype stack;
int isempty(int top)
{ if(top == -1)
  return 1;
 return 0; 
}

int isfull(int top)
{if(top == N-1)
  return 1;
 return 0;	
}

void push(stack*sp, int item)
{ 
  if(sp ->top == N-1)
  {printf("Stack full/overfull-insertion not possible\n");
   return;
  }
  (sp ->top)++;
  sp ->s[sp -> top]=item;
}
int pop(stack*sp)
{int item;
 if(sp ->top==-1)
 {printf("Stack empty/underflow-Deletion not possible\n");
  return 0;
 }
 item =sp ->s[sp->top];
 (sp->top)--;
 return item;
}

int peek(stack st)
{  if(st.top == -1)
  { printf("\n stack empty\n");
  return ;
  }
  return st.s[st.top];
}
void traversal(stack st)
{ int i=0;
  if(isempty(st.top))
  {printf("\nStack empty\n");
   return;
  }
  printf("\ncontents of stack:\n");
  while(i<=st.top)
  printf("%d", st.s[i++]);
printf(" <-top\n");
}

main()
{int choice, item;
 stack st;
 st.top = -1;
 
do
{ printf("\nMENU (Stack Operations):");
  printf("\n1.Push\n 2.Pop\n 3. Peek\n 4.Traversal\n 5.Exit\n");
  printf("Choice?");
  scanf("%d", &choice);
  switch(choice)
  {
    case 1: printf("Enter an int value to be pushed :");
  	        scanf("%d", &item);
  	        push(&st,item);
  	        break;
	case 2: if(isempty(st.top))
  	        printf("\nStack empty, deletion not possiblr\n");
  	        else
  	        { item = pop(&st);
  	          printf("item popped =%d\n", item);
			}
		  	break;
    case 3: if(isempty(st.top))
            printf("\n Stack empty\n");
            else
			{ item = peek(st);
			  printf("item at the top =%d\n", item);
			}
			break;
    case 4: traversal(st);
	        break;
  }
} while(choice != 5);
}

