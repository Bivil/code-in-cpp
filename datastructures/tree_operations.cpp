
#include <iostream>
#include <stdlib.h>
#include <limits.h>

#define MAX_Q_SIZE 500


using namespace std;

//============================================================================================================

void InOrderTraversal(struct node*);
void PreOrderTraversal(struct node*);
void PostOrderTraversal(struct node*);
int isBST(struct node* root);   int isBSTUtil(struct node* node, int min, int max);
bool isBst(struct node* root);
int MaxDepth(struct node*);
void LevelOrder(struct node *);  void PrintLevel(struct node*, int);
void LevelOrderQ(struct  node * node);void enQueue(struct node **queue, int *rear, struct node *new_node);struct node *deQueue(struct node **queue, int *front);
void printLevelOrder(struct node* root);
struct node ** createQueue(int *front, int *rear);
void enQueue(struct node **queue, int *rear, struct node *new_node);
struct node * deQueue(struct node **queue, int *front);

//===============================================================================================================
struct node
{
    int data;
    struct node * left;
    struct node * right;
};

struct node * NewNode(int data)
{
    struct node * node= (struct node*)malloc(sizeof(struct node));
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    return(node);
}


void InOrderTraversal(struct node* node)
{
    if(node==NULL) return;
    InOrderTraversal(node->left);
    cout<<node->data<<endl;
    InOrderTraversal(node->right);
}

void PreOrderTraversal(struct node* node)
{
    if(node==NULL) return;
    cout<<node->data<<endl;
    PreOrderTraversal(node->left);
    PreOrderTraversal(node->right);
}

void PostOrderTraversal(struct node* node)
{
    if(node==NULL) return;
    PostOrderTraversal(node->left);
    PostOrderTraversal(node->right);
    cout<<node->data<<endl;

}

int isBST(struct node* node)
{
  return(isBSTUtil(node, INT_MIN, INT_MAX));
}
/* Returns true if the given tree is a BST and its
   values are >= min and <= max. */
int isBSTUtil(struct node* node, int min, int max)
{

  /* an empty tree is BST */
  if (node==NULL)
     return 1;

  /* false if this node violates the min/max constraint */
  if (node->data < min || node->data > max)
     return 0;

  /* otherwise check the subtrees recursively,
   tightening the min or max constraint */
  return
    isBSTUtil(node->left, min, node->data-1) &&  // Allow only distinct values
    isBSTUtil(node->right, node->data+1, max);  // Allow only distinct values
}

bool isBst(struct node * root)
{
    static struct node *prev = NULL;

    // traverse the tree in inorder fashion and keep track of prev node
    if (root)
    {
        if (!isBst(root->left))
          return false;

        // Allows only distinct valued nodes
        if (prev != NULL && root->data <= prev->data)
          return false;

        prev = root;

        return isBst(root->right);
    }

    return true;
}

int MaxDepth(struct node * node)
{

    if(node==NULL)  return 0;
    else
    {
       int lDepth=MaxDepth(node->left);
       int rDepth=MaxDepth(node->right);

        if(lDepth>rDepth)   return(lDepth+1);
        else    return(rDepth+1);
    }
}

void LevelOrder(struct node * node)
{
    int h = MaxDepth(node);
    for(int i=1;i<=h;i++)
    {
            PrintLevel(node,i);
            cout<<endl;
    }
}
void PrintLevel(struct node * node, int level)
{
    if(node==NULL)  return;
    if(level==1)    cout<<node->data;
    else
    {
        PrintLevel(node->left, level-1);
        PrintLevel(node->right,level-1);
    }
}


void printLevelOrder(struct node* root)
{
  int rear, front;
  struct node **queue = createQueue(&front, &rear);
  struct node *temp_node = root;

  //while(temp_node)
  while(rear)
  {
    cout<<(temp_node->data);

    /*Enqueue left child */
    if(temp_node->left)
      enQueue(queue, &rear, temp_node->left);

    /*Enqueue right child */
    if(temp_node->right)
      enQueue(queue, &rear, temp_node->right);

    /*Dequeue node and make it temp_node*/
    temp_node = deQueue(queue, &front);
	cout<<endl;
  }
  cout<<"34rq3ft vf3q4ftgv 34wgev ";
}
 /*UTILITY FUNCTIONS*/
struct node** createQueue(int *front, int *rear)
{
  struct node **queue =
   (struct node **)malloc(sizeof(struct node*)*MAX_Q_SIZE);

  *front = *rear = 0;
  return queue;
}
 void enQueue(struct node **queue, int *rear, struct node *new_node)
{
  queue[*rear] = new_node;
  (*rear)++;
}
 struct node * deQueue(struct node **queue, int *front)
{
  (*front)++;
  return queue[*front - 1];
}


int main()
{

    struct node* root;
    root=NewNode(4);
    root->left=NewNode(2);
    root->right=NewNode(5);
    root->left->left=NewNode(1);
    root->left->right=NewNode(3);
 /*
        4
    2       5
1       3

*/
    // cout<<"Inorder : \n";    InOrderTraversal(root);
    // cout<<"Pre order : \n";    PreOrderTraversal(root);
    // cout<<"Post order : \n";    PostOrderTraversal(root);

    // cout<<root->data<<endl;         //4
    // cout<<root->data+1<<endl;       //5
    // cout<<root->data-1<<endl;       //3

    if(isBST(root))        cout<<"The tree is a BST\n";
    else                   cout<<"The tree is not a BST\n";
    if(isBst(root))        cout<<"The tree is a BST\n";
    else                   cout<<"The tree is not a BST\n";

    cout<<"The Depth is: "<<MaxDepth(root)<<endl;

    LevelOrder(root);			//Recursive
	printLevelOrder(root);		//Queue (iterative)
}

