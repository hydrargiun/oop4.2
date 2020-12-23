#include <iostream>
#include "dialog.h"
#include "Table.h"
#include "getnum.h"
#include "Lux.h"
#include "Standart.h"
#include "Multiseat.h"

namespace oop4{
    Table* (*fptr[])(Table *) = {NULL, D_Add, D_Del, D_Show,D_Find, D_QShow, D_Take, D_Checkout, D_Cost};
    Table table;
    void dialog() {
        while (true) {
            std::cout << "" << std::endl;
            std::cout << "0. Выход" << std::endl;
            std::cout << "1. Добавить номер " << std::endl;
            std::cout << "2. Удалить номер" << std::endl;
            std::cout << "3. Вывод всего списка" << std::endl;
            std::cout << "4. Вывод номера" << std::endl;
            std::cout << "5. Вывод таблицы типа номер-тип" << std::endl;
            std::cout << "6. Заселить" << std::endl;
            std::cout << "7. Выселить " << std::endl;
            std::cout << "8. Получить цену за проживание" << std::endl;
           // std::cout << "9.  " << std::endl;
          //  std::cout << "10. " << std::endl;
          //  std::cout << "11. " << std::endl;
          //  std::cout << "12. " << std::endl;
            int pt;
            pt = getNum<int>();
            if (!fptr[pt](&table)) {
                break;
            }
        }


    }

    Table* D_Add(Table *tab){
        const Table a= *tab;
        int num = 0;
        int cost = 0;
        std::cout <<"Введите ключ = ";
        std::cin >> num;
        std::cout <<"Введите цену = ";
        std::cin >> cost;
        std::cout << "Выберите тип";
        std::cout << "\n1. Lux\n2. Standart\n3. Multiseat\n";
        int ptr;
        std::cin >> ptr;
            if(ptr == 1)
            {
                Room *c = new Lux(num, cost);
                ++(*tab)[num] = c;

            }
            if(ptr == 2)
            {
                Room *c = new Standart(num, cost);
                ++(*tab)[num] = c;
            }
            if(ptr == 3)
            {   int p = 0;
                std::cout<<"Введите колличество мест ";
                std::cin >> p;
                Room *c = new Multiseat(num, cost,p);
                ++(*tab)[num] = c;
            }

        return tab;

    }
    Table* D_Del(Table* tab){
        std::cout <<"Введите ключ ";
        int key;
        std::cin >> key;
        tab->Del(key);
        return tab;

    }
    Table* D_Show(Table* tab){
        tab->Display();
        return tab;
    }

    Table* D_Find(Table* tab){
        int num;
        std::cin >> num;
        std::cout << *(*tab)[num];
        return tab;
    }

    Table* D_QShow(Table* tab){
       std::cout << *tab;
        return tab;
    }
    Table* D_Cost(Table* tab){
        std::cout <<"Введите ключ ";
        int key;
        std::cin >> key;
        ConstIt it;
        it = tab->find(key);
        if(it->room->Get_type()!= "Multiseat" ) {
            std::cout <<"Цена за номер -> " <<it->room->Cost(it->room->Get_people());
        } else {
            std::cout << "\nВведите id человека\n";
            int id;
            std::cin >> id;
            std::cout << "Цена за номер для человека с id " << id << " -> " << it->room->Cost(id);
        }
        return tab;
    }
    Table* D_Take(Table* tab){
        std::cout <<"Введите ключ ";
        int key;
        std::cin >> key;
        std::cout << tab->find(key)->room->Get_busy();
        if(tab->find(key)->room->Get_busy() == 0) {
            int date;
            int time;
            int people;
            std::cout << "Date of register-> ";
            std::cin >> date;
            std::cout << "Time-> ";
            std::cin >> time;
            std::cout << "People-> ";
            std::cin >> people;
            tab->find(key)->room->Take(date, time, people);
        }
        else
            std::cout << "\nНомер занят\n";
        return tab;
    }
    Table* D_Checkout(Table* tab) {
        std::cout << "Введите ключ ";
        int key;
        std::cin >> key;
        ConstIt it;
        it = tab->find(key);
        if (it->room->Get_type() != "Multiseat") {
            it->room->Checkout(it->room->Get_people());
            std::cout <<"Цена за номер -> " <<it->room->Cost(it->room->Get_people());
        } else {
            int p;
            std::cout<<"Введите индeкс человека ";
            std::cin >> p;

            try {
                std::cout << "Цена за номер для человека с id " << p << " -> " << it->room->Cost(p);
                it->room->Checkout(p);
                            }
            catch (std::exception &ex) {
                std::cout << "Exception detected: " << ex.what() << std::endl;
            }
        }

        return tab;
    }

}
