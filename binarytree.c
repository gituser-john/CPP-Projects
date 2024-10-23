#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* right ;
    struct node* left ;
};


struct node* createnode(int data)
{
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = data ;
    n->right = NULL ;
    n->left = NULL ;
    
    return n;
}

struct node* insert(struct node* root , int data)
{
     if(root == NULL)
     {
          return createnode(data);
     }
     else if(data > root->data)
     {
          root->right = insert(root->right,data);
     }
     else if(data < root->data)
     {
          root->left = insert(root->left,data);
     }    
     
     return root;
}

void preorder(struct node* root)
{
    if(root!=NULL)
    {
       printf(" %d",root->data);
       preorder(root->left);
       preorder(root->right);
    }
}


void inorder(struct node* root)
{
    if(root!=NULL)
    {
       inorder(root->left);
       printf(" %d",root->data);
       inorder(root->right);
    }
}

void postorder(struct node* root)
{
     if(root!=NULL)
     {
        postorder(root->left);
        postorder(root->right);
        printf(" %d",root->data);
     }
}

int main()
{

     struct node* root = NULL ;
     
     int data , c;
     
     while(1)
     {
          printf("\n1.insert\n2.preoder\n3.inorder\n4.postorder\n5.exit\n");
          printf("\nenter choice : ");
          scanf("%d",&c);
          
          switch(c)
          {
               case 1:printf("\nenter data : ");
                      scanf ("%d",&data);
                      root = insert(root,data);
                      break ;
               case 2: preorder(root);
                       break ;
               case 3: inorder(root);
                       break ;
               case 4: postorder(root);
                       break ;
               case 5:exit(0);
               default : printf("invalid");
           }
      }
     

}


     
     
     
     
     
































