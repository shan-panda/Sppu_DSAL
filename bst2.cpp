#include<iostream>
using namespace std;

class node
{
 public:
  int data;
  node *left,*right;
  node()
  {
   data=0;
   left=NULL;
   right=NULL;
  }
};

class btree
{
 public:
  node *root;
  btree()
  {
   root=NULL;
  }
  void create()
  {

   int i,n,ch;

   cout<<"Enter total no. of nodes: ";
   cin>>n;
   for(i=0;i<n;i++)
   {
    node *newnode=new node;
    cout<<"Enter the element: ";
    cin>>ch;

    newnode->data=ch;
    if(root==NULL)
    {
     root = newnode;
    }
    else
    {
     insert(root,newnode);
    }
   }
  }

  void insert(node *temp, node *newnode)
  {
   if(temp->data < newnode->data)
   {
    if(temp->right == NULL)
    {
     temp->right = newnode;
    }
    else
    {
     insert(temp->right,newnode);
    }
   }
   else
   {
    if(temp->left == NULL)
    {
     temp->left = newnode;
    }
    else
    {
     insert(temp->left,newnode);
    }
   }
  }
  void disp_post()
  {
   if(root!=NULL)
   {
    postorder(root);
   }
  }
  void disp_in()
  {
   if(root!=NULL)
   {
    inorder(root);
   }
  }

  void inorder(node *temp)
  {
   if(temp != NULL)
   {
    inorder(temp->left);
    cout<<temp->data<<"\t";
    inorder(temp->right);

   }
  }

  void postorder(node *temp)
  {
   if(temp != NULL)
   {
    postorder(temp->left);
    postorder(temp->right);
    cout<<temp->data<<"\t";
   }
  }
  void swap(node *root)
  {
   node *temp;
          if(root!=NULL)
          {
          temp=root->right;
          root->right=root->left;
          root->left=temp;
          swap(root->right);
          swap(root->left);
          }
  }
  void min_value(node *temp)
  {if(temp!=NULL)
  while(temp->left!=NULL)
          {
          temp=temp->left;
          }
  cout<<temp->data;
  }

  void find(node *root,int key)
  {
  if(root!=NULL)
          {
          if(key==root->data)
                  cout<<" Key found"<<endl;

          else if(key<root->data)
                  find(root->left,key);
          else
                  find(root->right,key);
          }
  }

  int depth(node *root)
  {int hleft,hright;
  if(root==NULL||((root->left==NULL)&&(root->right==NULL)))
          return (0);
  else
          {
          hleft=depth(root->left);
          hright=depth(root->right);
          }
  if(hleft>hright)
          {
          return (hleft+1);
          }
  else
          {
          return (hright+1);
          }
  }
};

int main()
{
btree v;
int n;
char ch;

do{
cout<<"\n\n## MENU ##\n\n1)Create tree\n2)In-order traversal\n3)Post-order traversal\n";
cout<<"\n4)Find minimum value \n5)Create mirror of tree\n6)Find value\n7)Find height of tree\nEnter your choice:";
cin>>n;
switch(n)
{
case 1:v.create();
        cout<<"Binary tree constructed successfully\n";
        break;
case 2:v.disp_in();
        break;
case 3:v.disp_post();
        break;
case 4: cout<<"Minimum value is:";
        v.min_value(v.root);
        break;
case 5:v.swap(v.root);
        cout<<"Inorder before mirrorring"<<endl;
        v.disp_in();
        cout<<"Tree has been mirrorred successfully\nInorder after mirrorring"<<endl;
        v.disp_in();
        break;
case 6:int x;
        cout<<"Enter the value to be searched:";
        cin>>x;
        v.find(v.root,x);
        break;
case 7:cout<<"Height of tree : "<<v.depth(v.root)<<endl;
        break;

}
cout<<"\n\nContinue?(Y/N)"<<endl;
cin>>ch;
}while(ch=='Y'||ch=='y');
 return 0;
return 0;
}
