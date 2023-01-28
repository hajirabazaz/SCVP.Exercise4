#ifndef TRANSITION_H
#define TRANSITION_H

#include <systemc.h>

#include "place.h"

// Transition:
template <unsigned int N = 1, unsigned int M = 1>
SC_MODULE(transition){

    sc_port<placeInterface, N, SC_ALL_BOUND> in;
    sc_port<placeInterface, M, SC_ALL_BOUND> out;

    public:
    SC_CTOR(transition){};

    void fire(){
        int k = 0;
        for (int i = 0; i < N; i++) {
            if(in[i]->testTokens() == 0)
                k = 1;
        }

        if (k)
            std::cout << this->name() << ": NOT Fired" << std::endl;
        else {
            std::cout << this->name() << ": Fired" << std::endl;
            for (int i = 0; i < N; i++)
                in[i]->removeTokens(1);
            for (int j = 0; j < M; j++)
                out[j]->addTokens(1);
        }
    }


};


#endif // TRANSITION_H
