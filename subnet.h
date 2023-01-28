#ifndef SUBNET_H
#define SUBNET_H

#include <systemc.h>

#include "place.h"
#include "transition.h"

// Subnet:
SC_MODULE(subnet){

    public:

    // sc_port<placeInterface> p_in;
    // sc_port<placeInterface> p_out;

    transition<1,1,1> ACT;
    transition<1,1,0> RD;
    transition<1,1,0> PRE;
    transition<1,1,0> WR;
    
    // place<1,1> IDLE;
    place<3,3> ACTIVE;   

    SC_CTOR(subnet) : ACT("ACT"), RD("RD"), PRE("PRE"), WR("WR"), 
    ACTIVE(0)
    {
 
        // ACT.in(p_in);
        ACT.inhibitors(ACTIVE);
        ACT.out(ACTIVE);

        RD.in(ACTIVE);
        RD.out(ACTIVE);

        PRE.in(ACTIVE);
        // PRE.out(p_out);

        WR.in(ACTIVE);
        WR.out(ACTIVE);

    }

};
#endif // SUBNET_H
