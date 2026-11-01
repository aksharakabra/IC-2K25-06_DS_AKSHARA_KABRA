// simplest binary tree with operations
// insert, three types of delete and 
//pre, post, and in order traverse
#include<iostream>
using namespace std;
struct node{
    int data;
node* left;
node* right;
};
node* creation(int x){
    node* new_one= new node;
    new_one->data= x;
    new_one->left= NULL;
    new_one->right= NULL;
    return new_one;
}
node* insert(node* root, int x){
    if(root==NULL){
        return creation(x);
    }
    if(x<root->data){
        root->left=insert(root->left, x);
        cout<<"we inserted "<<x<<endl;
    }
    else{
        root->right= insert(root->right, x);
        cout<<"we inserted "<<x<<endl;
    }
    return root;
}
void inorder(node* root){
    if(root==NULL){
        return;
    }
    else{
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);}
}
void preorder(node* root){
    if(root==NULL)
        return;
    cout<< root->data<<" ";
    preorder(root-> left);
    preorder(root-> right);
}
void postorder(node* root){
    if(root==NULL)
        return;
    postorder(root-> left);
    postorder(root-> right);
    cout<< root->data<<" ";
}
bool search(node* root, int key)
{
    if (root == NULL)
        return false;

    if (root->data == key)
        return true;

    if (key < root->data)
        return search(root->left, key);

    return search(root->right, key);
}
node* findmin(node* root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

node* deleteNode(node* root, int key)
{
    if (root == NULL)
        return NULL;

    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        // Case 1: No child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // Case 2: Only right child
        else if (root->left == NULL)
        {
            node* temp = root->right;
            delete root;
            return temp;
        }

        // Case 2: Only left child
        else if (root->right == NULL)
        {
            node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: Two children
        node* temp = findmin(root->right);

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}
    int main()
{
    node* root = NULL;

    // Insertion
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);

    // Traversals
    cout << "Inorder: ";
    inorder(root);

    cout << "\nPreorder: ";
    preorder(root);

    cout << "\nPostorder: ";
    postorder(root);

    // Searching
    if (search(root, 40))
        cout << "\n40 Found";
    else
        cout << "\n40 Not Found";

    // Deletion
    root = deleteNode(root, 20);

    cout << "\nAfter Deletion: ";
    inorder(root);

    return 0;
}





