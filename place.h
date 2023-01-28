#ifndef PLACE_H
#define PLACE_H

#include <systemc.h>

// Place Interface: 
class placeInterface : public sc_interface{
    public:
    virtual void addTokens() = 0;
    virtual void removeTokens() = 0;
    virtual bool testTokens() = 0;

};

// Place Channel:
template<unsigned int Win = 1, unsigned int Wout = 1>
class place : public placeInterface{ //Win = inp weight of place
    unsigned int tokens;

    public:

    place(unsigned int t = 0) : tokens(t){

    }

    void addTokens(){
        tokens += Win;
    } 

    void removeTokens(){
        tokens -= Wout;
    } 
    
    bool testTokens(){
        return tokens>=Wout;
    }   

};

#endif // PLACE_H
