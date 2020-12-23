
#include <iostream>
#include "Standart.h"
namespace oop4{
          Standart::Standart(int a, int b) {
              this->Set_first(a, b, "Standart");
              this->Set_busy(0);
              date = 0;
              time = 0;
              this->Set_people(0);
          }

    std::ostream &Standart::show(std::ostream &out) const {
        out << "Amount of people ";
        out <<this->Get_people() << "\n";
        out <<" Living from -> ";
        out <<date<<"\n";
        out << "Living for -> ";
        out << time;
        return out;


    }

    Room &Standart::Take(int d, int t, int p) {
        this->Set_busy(1);
        date = d;
        time = t;
        this->Set_people(p);
        return *this;

    }

    Room &Standart::Checkout(int p) {
              if(p != 1){
                  throw std::invalid_argument("not 1");
              }
       this->Set_busy(0);
       this->Set_people(0);
       date = 0;
       time = 0;
        return *this;
    }

    int Standart::Cost(int p) {
        return (this->Get_people() * (this->Get_cost() * this->time));
    }


    Standart::Standart() = default;







}
