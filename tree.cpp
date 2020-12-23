//
// Created by sasha on 23.12.2020.
//
#include "tree.h"
#include <iostream>
#define NULL nullptr
using namespace std;


btree::btree(){
    root = NULL;
}

btree::~btree(){
    destroy_tree();
}

void btree::destroy_tree(node *leaf){
    if(leaf != NULL){
        destroy_tree(leaf->left);
        destroy_tree(leaf->right);
        delete leaf;
    }
}

 node* btree::insert(int key, node *leaf){

    if(key < leaf->value){
        if(leaf->left != NULL){
            insert(key, leaf->left);
        }else{
            leaf->left = new node;
            leaf->left->value = key;
            leaf->left->left = NULL;
            leaf->left->right = NULL;
            return leaf->left;
        }
    }else if(key >= leaf->value){
        if(leaf->right != NULL){
            insert(key, leaf->right);
        }else{
            leaf->right = new node;
            leaf->right->value = key;
            leaf->right->right = NULL;
            leaf->right->left = NULL;
            return leaf->right;
        }
    }

}

oop4::Room * btree::insert(int key){
    if(root != NULL){
        insert(key, root);
        return insert(key, root)->room;
    }else{
        root = new node;
        root->value = key;
        root->left = NULL;
        root->right = NULL;
        return root->room;
    }
}

node *btree::search(int key, node *leaf){
    if(leaf != NULL){
        if(key == leaf->value){
            return leaf;
        }
        if(key < leaf->value){
            return search(key, leaf->left);
        }else{
            return search(key, leaf->right);
        }
    }else{
        return NULL;
    }
}

node *btree::search(int key){
    return search(key, root);
}

void btree::destroy_tree(){
    destroy_tree(root);
}

void btree::inorder_print(ostream &out){
    inorder_print(root,out);
    out << "\n";
}

ostream & btree::inorder_print(node *leaf,ostream &out ){
    if(leaf != NULL){
        inorder_print(leaf->left, out);
        out << leaf->room<<"\n";
        inorder_print(leaf->right,out);
    }
}

void btree::postorder_print(){
    postorder_print(root);
    cout << "\n";
}

void btree::postorder_print(node *leaf){
    if(leaf != NULL){
        inorder_print(leaf->left);
        inorder_print(leaf->right);
        cout <<leaf->value<<"             "<<leaf->room->Get_type()<< "\n";
    }
}

void btree::preorder_print(){
    preorder_print(root);
    cout << "\n";
}

void btree::preorder_print(node *leaf){
    if(leaf != NULL){
        inorder_print(leaf->left);
        inorder_print(leaf->right);
    }
}

std::ostream &operator<<(ostream &out, btree tr) {
    tr.inorder_print(out);
}

void btree::inorder_print(node *leaf) {

        if(leaf != NULL){
            inorder_print(leaf->left);
            cout <<leaf->value<<"             "<<leaf->room->Get_type()<< "\n";
            inorder_print(leaf->right);
        }

}

node *btree::get_one_bigger(node *Node) {

}
