#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
char stack[20];
int top=-1;
char c,p;
struct node
{
    char c;
    struct node *right;
    struct node *left;
}*nn,*tree,*tpop,*dn,*stacke[20];
void push(char c);
char pop();
int priority(char p);
void pushe(struct node *nn);
struct node * pope();
void inorder(struct node *nn);
void main()
{
     char expr[20],ex=0;
     char post[20];
     int ne,i,p=0;
     char d;
     printf("\n Enter elements");
     i=-1;
     while(ex!='\n')
     {
         ex=getchar();
         i++;
         expr[i]=ex;
      }
     expr[i--]='\0';
     i=0;
     while(expr[i]!='\0')
     {
	 
	 if(expr[i]!='+'&&expr[i]!='-'&&expr[i]!='*'&&expr[i]!='/'&&expr[i]!='('&&expr[i]!=')')
	 {
	     printf("\n print: %c",expr[i]);
             post[p]=expr[i];
             p++;
             post[p]='\0';
             printf("\n o/p: %s",post);
	 }
         else if(expr[i]=='(')
         {
            printf("\n push: (");
	    push(expr[i]);
            post[p]='\0';
             printf("\n o/p: %s",post);
         }
	 else if(expr[i]==')')
	 {
	    while((d=pop())!='(')
            {
	       printf("\n pop and print because ) has read:  %c",d);
               post[p++]=d;
                post[p]='\0';
               printf("\n o/p: %s",post);
             }
             printf("\n pop: (");
	 }
	 else 
         {
            if(expr[i]=='+'||expr[i]=='-'||expr[i]=='*'||expr[i]=='/')
            {
               if(top!=-1)
               {
                if(priority(stack[top])>=priority(expr[i]))
	        {
	           d=pop();
	           printf("\n pop and print:  %c",d);
                   post[p++]=d;
                    post[p]='\0';
                   printf("\n o/p: %s",post);
                   printf("\n push: %c",expr[i]);
	           push(expr[i]); 
                } 
                else
                {
                  printf("\n push: %c",expr[i]);
                  push(expr[i]);
                  post[p]='\0';
                  printf("\n o/p: %s",post);
                }
               }
               else
               {
                  printf("\n push: %c",expr[i]);
	          push(expr[i]);
                  post[p]='\0';
                  printf("\n o/p: %s",post);
                }
            } 
	 }
         i++;
     }
     while(top!=-1)
     {
	 d=pop();
	 printf("\n pop and print: %c",d);
         post[p++]=d;
          post[p]='\0';
         printf("\n o/p: %s",post);
     }
     post[p]='\0';
         printf("\n postfix: %s",post);
     i=0;
     top=-1;
     while(post[i]!='\0')
     {
          nn=(struct node *)malloc(sizeof(struct node));
          nn->c=post[i];
          nn->right=NULL;
          nn->left=NULL;
          if(post[i]!='+'&&post[i]!='-'&&post[i]!='*'&&post[i]!='/'&&post[i]!='('&&post[i]!=')')
              pushe(nn);
          if(post[i]=='+'||post[i]=='-'||post[i]=='*'||post[i]=='/')
          {
                tpop=pope();
                nn->right=tpop;
                tpop=pope();
                nn->left=tpop;
                pushe(nn);
           }
           i++;
     }
     nn=pope();
     printf("\n Tree is created and it's inorder traversal is: ");
     inorder(nn);
     getch();
}
void push(char c)
{
      top=top+1;
      stack[top]=c;
}
char pop()
{
   if(top==-1)
   {
       printf("\n underflow");
   }
   return stack[top--];
}
int priority(char p)
{
    if(p=='(')
       return 0;
    if(p=='+'||p=='-')
       return 1;
    if(p=='*'||p=='/')
       return 2;
    
       
}
void inorder(struct node *nn)
{
    struct node *temp;
    temp=nn;
    if(temp!=NULL)
    {
       inorder(temp->left);
        printf("%c",temp->c);
       inorder(temp->right);
     }
}
void pushe(struct node *nn)
{
    top++;
    stacke[top]=nn;
}
struct node * pope()
{
    struct node *dn;
    if(top==-1)
        printf("\n underflow");
    dn=stacke[top];
    top--;
    return(dn);
}


