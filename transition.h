#ifndef TRANSITION_H
#define TRANSITION_H

#include <systemc.h>

#include "place.h"

// Transition:
SC_MODULE(transition){

    sc_port<placeInterface> in;
    sc_port<placeInterface> out;

    public:
    SC_CTOR(transition){};

    void fire(){
        if(in->testTokens()){
            std::cout << this->name() << ": Fired" << std::endl;
            in->removeTokens(1);
            out->addTokens(1);
        }
        else
            std::cout << this->name() << ": NOT Fired" << std::endl;

    }


};


#endif // TRANSITION_H
