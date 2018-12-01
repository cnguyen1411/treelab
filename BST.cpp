#include"BST.h"
#include<string>
#include<fstream>

BST::BST()
{
    this->root = NULL;      //root is NULL in the start
}

BST::~BST()
{
    clear(root);            //delete all nodes
}

void BST::clear(Node* current)
{
    if(current == NULL)
        return;

    clear(current->getLeft());          //clear left subtree
    clear(current->getRight());         //clear right subtree
    delete current;                     //delete this node
}

void BST::Insert(int num, string data)
{
    //create new node to be inserted
    Node *n = new Node();
    n->setData(num, data);
    n->setLeft(NULL);
    n->setRight(NULL);


    if(this->root == NULL)      //if root is null, simply add at root
        root = n;

    else
        InsertHelper(root,n);   //call helper to insert
}

void BST::InsertHelper(Node* current, Node* newnode)
{
    if(current == NULL)
        return;

    //node should be inserted at right subtree
    if(current->getNumber() <= newnode->getNumber()){

        //if no node at right
        if(current->getRight() == NULL )
            current->setRight(newnode);     //add at right node

        else
            InsertHelper(current->getRight(), newnode);     //insert in right subtree
    }
    else{

        if(current->getLeft() == NULL){         //if no node at left
            current->setLeft(newnode);          //add at left
        }else{
            InsertHelper(current->getLeft(), newnode);      //insert in left subtree
        }
    }
}



//POST ORDER
void BST::postorderPrint(){
    cout<< "POST ORDER: " << "<br />" << endl;
    postorderPrintHelper(root);
}
void BST::postorderPrintHelper(Node *current){
     if(current == NULL)     //stop if NULL
        return;

    postorderPrintHelper(current->getLeft());
    postorderPrintHelper(current->getRight());
    cout << "<tr>";
    cout << "<td>" << current->getNumber() << "</td>" << "<td>" << current-> getName() << "</td>";
    cout << "</tr>";
}


//PRE ORDER
void BST::preorderPrint(){
    cout<< "PRE ORDER: " << "<br />" << endl;
    preorderPrintHelper(root);
}
void BST::preorderPrintHelper(Node *current){
     if(current == NULL)     //stop if NULL
        return;
    cout << "<tr>";
    cout << "<td>" << current->getNumber() << "</td>" << "<td>" << current-> getName() << "</td>";
    cout << "</tr>";
    preorderPrintHelper(current->getLeft());
    preorderPrintHelper(current->getRight());
}


//IN ORDER
void BST::inorderPrint()
{
    cout<< "IN ORDER: " << "<br />" << endl;
    inorderPrintHelper(root);
}

void BST::inorderPrintHelper(Node *current)
{
    if(current == NULL)     //stop if NULL
        return; 
    inorderPrintHelper(current->getLeft());        //print left tree
    cout << "<tr>";
    cout << "<td>" << current->getNumber() << "</td>" << "<td>" << current-> getName() << "</td>";
    cout << "</tr>";
    inorderPrintHelper(current->getRight());       //print right tree
}