#include "Room.h"
#include <iostream>
#include <string>
namespace oop4 {




    std::ostream& operator << (std::ostream& out, const Room& room){
        out << "Room num -> ";
        out <<" "<< room.num<<"\n";
        out << "Room type -> ";
        out <<" "<< room.type<<"\n";
        (room.busy == 1)?(out << "Room is -> busy\n"):(out << "Room is -> free\n");
        out << "Room cost -> ";
        out <<" "<<room.cost_per_day<<"\n";
        room.show(out);
        return out;

    }





    int Room::Get_number() const {
        return this->num;
    }

    Room &Room::Set_first(int n, int c, const std::string& t)  {
        this->num = n;
        this->cost_per_day = c;
        this->busy = 0;
        this->type = t;
        return *this;
    }
    Room &Room::Set_busy(int b)  {
        this->busy = b;
        return *this;
    }

    int Room::Get_busy() const{
        return this->busy;
    }

    int Room::Get_people() const {
        return this->people;
    }

    Room &Room::Set_people(int p) {
        this->people = p;
        return *this;
    }

    std::string Room::Get_type() {
        return this->type;
    }

    int Room::Get_cost() const {
        return this->cost_per_day;
    }


}
