#ifndef PLACE_H
#define PLACE_H

#include <systemc.h>

// Place Interface:
class placeInterface : public sc_interface{
    public:
    virtual void addTokens(unsigned int n) = 0;
    virtual void removeTokens(unsigned int n) = 0;
    virtual unsigned int testTokens() = 0;

};

// Place Channel:
class place : public placeInterface{
    unsigned int tokens;

    public:

    place(unsigned int t = 0) : tokens(t){

    }

    void addTokens(unsigned int n){
        tokens += n;
    } 

    void removeTokens(unsigned int n){
        tokens -= n;
    } 
    
    unsigned int testTokens(){
        return tokens;
    }   

};

#endif // PLACE_H
