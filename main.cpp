#include <systemc.h>

#include "place.h"
#include "transition.h"
#include "subnet.h"

/*// Toplevel (task 3):
SC_MODULE(toplevel){
    transition<1,2> t1;
    transition<2,1> t2;
    transition<1,1> t3;
    place<1,1> p1, p2, p3, p4;
    

    public:
    SC_CTOR(toplevel) : t1("t1"), t2("t2"), t3("t3"), p1(1), p2(0), p3(0), p4(0) {
 
        t1.in.bind(p1);
        t1.out.bind(p2);
        t1.out.bind(p3);
        
        t2.in.bind(p2);
        t2.in.bind(p4);
        t2.out.bind(p1);

        t3.in.bind(p3);
        t3.out.bind(p4);

        SC_THREAD(process);
    }

    void process()
    {
        while (true)
        {
            wait(10, SC_NS);
            t1.fire();
            wait(10, SC_NS);
            t2.fire();
            wait(10, SC_NS);
            t3.fire();
            wait(10, SC_NS);
            t2.fire();
            sc_stop();
        }
    }

};
*/

// Toplevel (task 4 - memory bank):
SC_MODULE(toplevel){
    subnet s1;
    subnet s2;
    
    place<1,1> IDLE; //-------------SHOULDNT THIS BE <2,2> ???

    public:
    SC_CTOR(toplevel) : s1("s1"), s2("s2"), 
    IDLE(2)
    {
 
        s1.ACT.in(IDLE);
        s1.PRE.out(IDLE);
        s2.ACT.in(IDLE);
        s2.PRE.out(IDLE);


        SC_THREAD(process);
    }

    void process()
    {
        while (true)
        {
            wait(10, SC_NS);
            s1.ACT.fire();
            wait(10, SC_NS);
            s1.ACT.fire();
            wait(10, SC_NS);
            s1.RD.fire();
            wait(10, SC_NS);
            s1.WR.fire();
            wait(10, SC_NS);
            s1.PRE.fire();
            wait(10, SC_NS);
            s1.ACT.fire();
            wait(10, SC_NS);
            s2.ACT.fire();
            wait(10, SC_NS);
            s2.ACT.fire();
            wait(10, SC_NS);
            s1.PRE.fire();
            wait(10, SC_NS);
            s2.PRE.fire();
            wait(10, SC_NS);
            sc_stop();
        }
    }

};



int sc_main(int, char**)
{
    toplevel t("t");

    sc_start();
    return 0;
}
