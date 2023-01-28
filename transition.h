#ifndef TRANSITION_H
#define TRANSITION_H

#include <systemc.h>

#include "place.h"

// Transition:
template <unsigned int N = 1, unsigned int M = 1, unsigned int L = 0>
SC_MODULE(transition){

    sc_port<placeInterface, N, SC_ALL_BOUND> in;
    sc_port<placeInterface, M, SC_ALL_BOUND> out;
    sc_port<placeInterface, L, SC_ZERO_OR_MORE_BOUND> inhibitors;

    public:
    SC_CTOR(transition){};

    void fire(){
        int k = 0;
        for (int i = 0; i < N; i++) {
            if(in[i]->testTokens() == 0)
                k = 1;
        }
        for (int l = 0; l < L; l++) {
            if (inhibitors[l]->testTokens() != 0)
                k = 1;
        }

        if (k)
            std::cout << this->name() << ": NOT Fired" << std::endl;
        else {
            std::cout << this->name() << ": Fired" << std::endl;
            for (int i = 0; i < N; i++)
                in[i]->removeTokens();
            for (int j = 0; j < M; j++)
                out[j]->addTokens();
        }
    }
};


#endif // TRANSITION_H
