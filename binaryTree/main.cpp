//**********************************************************************************
//a programme to implement a binary search tree using c++ programming language
//written using  the idecodeblocks
//programed by harisu fanyui

//**********************************************************************************

#include <iostream>

using namespace std;
template<class Object>
class treenode{
private:
    treenode* right;
    treenode* left;
    Object *object;
public:
    treenode(){//constructor with no argument
    this->right=NULL;
    this->left=NULL;
    this->object=NULL;
    }
    treenode(Object *object){//constructor to take an object of type templete
        this->right=NULL;
        this->left=NULL;
        this->object=object;

    }
    void setLeft(treenode* left){this->left=left;}//holds the address of the left node
    treenode* getLeft(){return left;}
    void setRight(treenode* right){//holds the address of the right node
        this->right=right;
    }
    treenode* getRight(){return right;}//returns the address of the right node
    int isleaf(){
    if (this->left==NULL&&this->right=NULL)
        return 1;
    else return 0;
    }
    void setObject(Object* object){this->object=object;}
    Object* getObject(){return this->object;}//returns the address of object
friend void traverseLeft(treenode * node);//friend function to traverse left subtree
friend void traverseRight(treenode* node);//friend to traverse right subtree
friend void preorder(treenode* tree);
//friend void inOrder(treenode* tree);
friend void postOrder(treenode* tree);
};
void postOrder(treenode<int>* tree){
    if(tree!=NULL){
        postOrder(tree->getLeft());
        postOrder(tree->getRight());
        cout<<*(tree->getObject())<<endl;
    }
}
void inOrder(treenode<int>* tree){
    if(tree!=NULL){
        inOrder(tree->getLeft());
        cout<<*(tree->getObject())<<endl;
        inOrder(tree->getRight());
    }
}
void preorder(treenode<int>* tree){
    if (tree!=NULL){
        cout<<*(tree->getObject())<<endl;
        preorder(tree->getLeft());
        preorder(tree->getRight());
    }
}
void traverseRight(treenode<int>* node){//function to traverse the right subtree
    treenode<int>*p;
    p=node;
    while(p->getRight()!=NULL)
        cout<< *(p->getObject()) <<endl;
    p=p->getRight();

}
//function to traverse left subtree
void traverseLeft(treenode<int>* node){
    treenode<int>* p;
    p=node;
while ((p->getLeft())!=NULL){
    cout<<*(p->getObject())<<endl;
p=p->getLeft();
}
}
void inset(treenode<int>*,int*);//function to insert and item into the ttee

int main(int argc,char* argv[])
{
    int i=0;
    int object[20];
  treenode<int>*root=new treenode<int>();
  cout<<"enter the root of the tree"<<endl;
  cin>>object[0];
  root->setObject(&object[0]);
  while(object[i]!=-1){
    cout<<"enter and element or -1 to exit"<<endl;
    cin>>object[++i];
      inset(root,&object[i]);

  }
cout<<"traversing the left subtree"<<endl;
traverseLeft(root);
cout<<"traversing using preorder traversal "<<endl;
preorder(root);
cout<<"traversing using inorder traversal"<<endl;
inOrder(root);
cout<<"traversing using postOrder traversal"<<endl;
postOrder(root);
    return 0;
}
//insert fucntion to insert a node into the tree
void inset(treenode<int>* root,int* item){
treenode<int>* node=new treenode<int>(item);
treenode<int> *p,*q;
p=q=root;
while(*item != *(p->getObject()) && q!=NULL){
    p=q;
if(*item<*(p->getObject()))
   q= p->getLeft();
else q=p->getRight();
}
if(*item==*(p->getObject()))
    cout<<"error repetition occurred"<<endl;
else if(*item<*(p->getObject()))
    p->setLeft(node);
else
    p->setRight(node);
cout<<"object added successfully"<<endl;

}
