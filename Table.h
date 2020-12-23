#ifndef OOP4_LENA_TABLE_H
#define OOP4_LENA_TABLE_H
#include <map>
#include <vector>
#include "Room.h"
#include "tree.h"
namespace oop4 {
    class ConstIt{
    private:
         node *Node;
    public:
        ConstIt()= default;
        ConstIt(node*);
        node & operator *();
        node * operator ->();
        int operator ==(const ConstIt &) const;
        int operator !=(const ConstIt &) const;
        ConstIt & operator ++();
        ConstIt operator ++(int);
        node * Get_node(){
            return Node;
        }
    };




    class Table {
    private:
      btree * tree;
    public:
        Table();
        Table & operator =(const Table &);
        Room* &operator [](int);
        Room* operator [](int) const;
        friend std::ostream & operator <<(std::ostream &, const Table &);
        friend class ConstIt;
        typedef ConstIt ConstIterator;
        ConstIterator begin();
        ConstIterator end() const;
        void Display();
        Table &Del(int);
        ConstIterator find(int);





};



}

#endif
