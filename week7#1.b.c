#include<stdio.h>
#include<stdlib.h>
struct nodetype
{ int INFO;
 struct nodetype *NEXT;
};
typedef struct nodetype node;
int isempty(node*top)
{ if(top==NULL)
  return 1;
  else
  return 0;
}
node* push(node*top, int item)
{node *pnew=(node*)malloc(sizeof(node));
 pnew->INFO=item;
 pnew->NEXT=top;
 printf("Node inserted...\n");
 return pnew;
 }
node*pop(node *top)
{node*pdel,*pnxt;
if(isempty(top))
{printf("\nStack empty-Deletion not possible\n");
 return top;
}
pdel=top;
pnxt=top->NEXT;
free(pdel);
printf("Node deleted....\n");
return pnxt;
}
int peek(node*top)
{if(isempty(top))
{printf("\nStack empty\n");
return 0;
}
return top->INFO;
}
void traversal(node*top)
{if(isempty(top))
 printf("\nStack empty\n");
 else
 {node*p=top;
 printf("\ncontents of stack:\n Top->");
 while(p!=NULL)
 { printf("%d",p->INFO);
   p=p -> NEXT;
 }
 printf("\n");
 }
}
void main()
{int choice, item;
 node *top=NULL;
 do
 { printf("\nMENU (stack operation):");
 printf("\n1.Push \n2.Pop \n3.Peek \n4.Traversal\n 5.Exit");
 printf("\nchoice?");
 scanf("%d", &choice);
 switch(choice)
 { 
     case 1:printf("Enter int value to be pushed:");
 	        scanf("%d", &item);
 	        top = push(top,item);
 	         break;
 	case 2: top = pop(top);
 	         break;
 	case 3: if(isempty(top))
 	         printf("\nstack empty\n");
 	         else
 	         { item = peek(top);
 	           printf("\nitem peeked= %d\n", item);
	           }
	         break;
 	case 4: traversal(top);
 	         break;
 	}
  } while(choice!=5);
}
