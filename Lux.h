#include "Room.h"

#ifndef OOP4_LENA_LUX_H
#define OOP4_LENA_LUX_H

namespace oop4 {
    class Lux : public Room {
    private:
        int date;
        int time;


    public:
        Lux(int,int);
        Room& Take(int d, int t, int p) override;
        Room& Checkout(int p) override;
        std::ostream &show(std::ostream &out) const override;
        int Cost(int p) override;
    };
}

#endif //OOP4_LENA_LUX_H
