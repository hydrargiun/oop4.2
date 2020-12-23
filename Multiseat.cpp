#include <iostream>
#include "Multiseat.h"
namespace oop4 {
        Multiseat::Multiseat(int a, int b,int p) :places(p), free_places(p) {
            this->Set_first(a, b, "Multiseat");
            this->Set_people(0);
            for(int i = 0; i < 4; i++){
                this->hum->time = 0;
                this->hum->date = 0;
                this->hum->number= 0;
            }

    }

    Room &Multiseat::Take(int d, int t, int p) {
        if (p <= free_places) {
            for (int i = 0; i < p; i++) {
                hum[i].number = i + 1;
                hum[i].date = d;
                hum[i].time = t;
            }
            free_places -= p;
            this->Set_busy(1);
            this->Set_people(places  - free_places);
            if(this->Get_people() == places){
                this->Set_busy(1);
            }

        }
        return *this;
    }

    Room &Multiseat::Checkout(int p) {
            for (int i = 0; i < places; i++){
                if (hum[i].number == p) {
                    hum[i].date = 0;
                    hum[i].time = 0;
                    break;
                }
                throw std::invalid_argument("No such man");
            }
        this->Set_people(this->Get_people()-  1);
        this->free_places = free_places + 1;
        if (free_places == places)
           this->Set_busy(0);
        return *this;
    }

    std::ostream &Multiseat::show(std::ostream &out) const {
        out << "Amount of people ";
        out << this->Get_people()<<"\n";
        out << "Free place ";
        out <<free_places<<"\n";
        out <<"All places ";
        out <<places<<"\n";
        out << "Living in that room\n";
        for (int i = 0; i < places-free_places; i++) {
            out << "\nGuest N. ";
            out << hum[i].number;
            out <<" Living from -> ";
            out <<hum[i].date<<"\n";
            out << "Living for -> ";
            out << hum[i].time << " days";
        }
        return out;


    }

    int Multiseat::Cost(int p) {
        return (this->Get_cost() * this->hum[p-1].time);
    }


    Multiseat::Multiseat() = default;


}