#ifndef BST_H_
#define BST_H_

#include<iostream>
using namespace std;
#include<string>

#include "Node.h"

//BST class
class BST{

    private:
        Node * root;        //root node pointer

    public:
        BST();                                  //constructor
        ~BST();                                 //destructor
        void Insert(int num, string data);                  //Inserts new number in tree
        void inorderPrint();
        void preorderPrint();
        void postorderPrint();


        //private functions used as helper functions in the public operations
    private:
        void inorderPrintHelper(Node *root);
        void preorderPrintHelper(Node *root);
        void postorderPrintHelper(Node *root);
        void InsertHelper(Node* current, Node* newnode);
        void clear(Node *current);
};

#endif