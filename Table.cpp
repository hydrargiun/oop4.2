#include <iostream>
#include "Table.h"
#include "Lux.h"

namespace oop4 {

    void Table::Display() {
        btree * tr = tree;
        tr->preorder_print();
    }



    Table &Table::Del(int key) {
        try {
            tree->search(key);
        }
        catch (std::exception &ex) {
            std::cout << "Exception detected: " << ex.what() << std::endl;
        }

        return *this;
    }





    Table::ConstIterator Table::find(int key) {
       ConstIterator it = tree->search(key);
        return ConstIterator(it);
    }

    Table::ConstIterator Table::begin(){
        return ConstIterator(tree->get_root()); //вернуть объект класса итератора от реального итератора мапа, который указвал на начало
    }

    Table::ConstIterator Table::end() const {
        return ConstIterator(nullptr);
    }

    Table &Table::operator=(const Table &tab) {
        ConstIterator it(tab.tree->get_root());
        if (this != &tab){
            tree->destroy_tree();  //очищяем наш
            tree->set_root(it.Get_node());
        }
        return *this;
    }

    Room* &Table::operator[]( int key) {
       ConstIt it = tree->search(key);// m_search - поиск по мапу
        if(it == end()) {
           tree->insert(key);
            it = tree->search(key); //вставили новый и присволили итератору поиска
        }
        return it->room;  //m_search итератор мапа => вернем мы * room

    }

    Room* Table::operator[](int key) const {
          btree * tr = tree;
          ConstIt it =  tr->search(key);
        if (it == end())
            throw std::invalid_argument("illegal index");
        return it->room; //возврат комнаты // работает как в мапе
    }

    std::ostream &operator<<(std::ostream &out, const Table &tab) {
        out << tab.tree;

        return out;
       }



    Table::Table(){
        tree = new btree();
    }


    node& ConstIt::operator * () {
        return *Node;
    }

    node *ConstIt::operator->() {
        return &(*Node);
    }

    int ConstIt::operator==(const ConstIt &iter) const {
        return Node == iter.Node;
    }

    int ConstIt::operator!=(const ConstIt &iter) const {
        return Node != iter.Node;
    }

    ConstIt &ConstIt::operator++() {
        this->Node = Node->right;
        return *this;
    }

    ConstIt ConstIt::operator++(int) {
        ConstIt res(*this);
        ++Node;
        return res;
    }

    ConstIt::ConstIt(node *n) {
    this->Node = n;
    }
}
