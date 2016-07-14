#ifndef MUX4MOD_H
#define MUX4MOD_H

/**
 *
 * 4:1 Mux4 module template.
 */

#include <systemc.h>

/**
 * Mux4 module.
 * Mux4 module models a generic 4:1 multiplexor of template type T. 
 * Implementation based on a template class.
 *
 *   - input ports
 *   	- \c T \c din0		- input 
 *   	- \c T \c din1		- input
 *   	- \c T \c din2		- input
 *   	- \c T \c din3		- input
 *   	- \c sc_uint<2> \c sel	- select 
 *   - output ports
 *   	- \c T \c dout		- output
 */

template <class T> class mux4: public sc_module
{
public:
  sc_in< T >  din0;
  sc_in< T >  din1;
  sc_in< T >  din2;
  sc_in< T >  din3;
  sc_in< sc_uint<2> >  sel;        
  sc_out< T > dout;

  SC_CTOR(mux4)
     {      
      SC_METHOD(entry);
      sensitive << din0 << din1 << din2 << din3 << sel;
    }
  
  void entry();
};


template <class T> void mux4<T>::entry()
{
    switch (sel.read())
    {
       case 0: dout.write(din0.read());
               break;
       case 1: dout.write(din1.read());
               break;
       case 2: dout.write(din2.read());
               break;
       case 3: dout.write(din3.read());
               break;
    }
}

#endif
