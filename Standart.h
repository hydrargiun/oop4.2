#include "Room.h"
#ifndef OOP4_LENA_STANDART_H
#define OOP4_LENA_STANDART_H

namespace oop4 {
    class Standart : public Room {

    private:
       int date;
       int time;
    public:
        Standart();
        Standart(int, int);
        Room & Take(int d, int t, int p) override;
        Room & Checkout(int p) override;
        std::ostream & show(std::ostream &) const override;
         int Cost(int p) override;

    };
}

#endif //OOP4_LENA_STANDART_H
