#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* left;
	struct node* right;
};


struct node* create_node(int n){
	struct node* ptr = (struct node*)malloc(sizeof(struct node*));
	ptr->data=n;
	ptr->left=NULL;
	ptr->right=NULL;
	return ptr;
}

struct node* insert(struct node* root,int n){
	if(root==NULL){
		return create_node(n);
	}
	else if(n>root->data){
		root->right=insert(root->right,n);
	}
	else{
		root->left=insert(root->left,n);
	}
	return root;
}

void preorder(struct node* root){
	if(root!=NULL){
		printf("%d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void inorder(struct node* root){
	if(root!=NULL){
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}
void postorder(struct node* root){
	if(root!=NULL){
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->data);
	}
}
struct node* minValueNode(struct node* node) {
    struct node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

struct node* deleteNode(struct node* root, int data) {
    if (root == NULL) return root;

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
       
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        
        struct node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main()
{

     struct node* root = NULL ;
     
     int data , c;
     
     while(1)
     {
          printf("\n****************************************\n");
          printf("\n1.insert\n2.preoder\n3.inorder\n4.postorder\n5.Delete\n6.exit\n");
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
               case 5: 
		       printf("\nenter data : ");
                       scanf ("%d",&data);
		       root=deleteNode(root,data);
		       break;
               case 6: exit(0);
               
               default : printf("invalid\n");
           }
      }
}
