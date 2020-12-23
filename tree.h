//
// Created by sasha on 23.12.2020.
//

#ifndef MAIN_CPP_TREE_H
#define MAIN_CPP_TREE_H
//
// Created by sasha on 23.12.2020.
//

#include <iostream>
#include "Room.h"
using namespace std;


struct node{
    int value;
    oop4::Room * room;
    node *left;
    node *right;
};

class btree{
public:
    btree();
    ~btree();

    oop4::Room* insert(int key);
    node *search(int key);
    void destroy_tree();
    void inorder_print( std::ostream &);
    void postorder_print();
    void preorder_print();
    node* get_one_bigger(node *);
    friend std::ostream & operator <<(std::ostream &, btree tr);
    friend  node;
    node * get_root(){
        return root;
    }
    btree& set_root(node* a){
        this->root = a;
        return *this;
    };


private:
    void destroy_tree(node *leaf);
    node* insert(int key, node *leaf) ;
    node *search(int key, node *leaf);
    void inorder_print(node *leaf);
    std::ostream & inorder_print(node *leaf, std::ostream &);
    void preorder_print(node *leaf);
    void postorder_print(node *leaf);

    node *root;
};
#endif //MAIN_CPP_TREE_H
