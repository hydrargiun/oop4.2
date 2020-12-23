#include <iostream>
#include "Lux.h"
namespace oop4{

    Lux::Lux(int n, int cost) {
        this->Set_first(n, cost, "Lux");
     this->Set_people(0);
     this->Set_busy(0);
     time = 0;
     date = 0;

    }


    Room &Lux::Checkout(int p) {
        this->Set_people(0);
        this->Set_busy(0);
        this->time= 0;
        this->date = 0;
        return *this;

    }
    std::ostream &Lux::show(std::ostream &out) const {
        out << "Amount of people-> ";
        out << this->Get_people()<<"\n";
        out <<"Living from -> ";
        out <<date<<"\n";
        out << "Living for -> ";
        out << time;
        return out;


    }

    Room &Lux::Take(int d, int t, int p) {
        this->date = d;
        this->time = t;
        this->Set_busy(1);
        this->Set_people(p);
        return *this;
    }

    int Lux::Cost(int p) {
        return (this->Get_people() * (this->Get_cost() * this->time));
    }


}
