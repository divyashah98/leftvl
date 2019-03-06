#include <systemc.h>
#include <Vleft.h>
//#include <verilated_vcd_sc.h>

#include <stdio.h>



int sc_main(int argc, char * argv[])
{


   Verilated::commandArgs(argc,argv);
   //Verilated::traceEverOn(true);
   


   sc_time T(1,SC_NS);
   sc_clock clk("clk",T*20);

   sc_signal<bool> in;
   sc_signal<bool> clr;
   sc_core::sc_signal<uint32_t> out;

   Vleft* top = new Vleft("top");

   top->clk(clk);
   top->in(in);
   top->clr(clr);
   top->out(out);


//VerilatedVcdSc* tfp = new VerilatedVcdSc;
  // top->trace(tfp, 10);
   //tfp->open("obj_dir/simu.vcd");




 clr=1;
   sc_start(10*T);
  printf("\n out=%d",(int)out);

   clr=0;
   sc_start(10*T);
  printf("\n out=%d",(int)out);


   in=1;
   sc_start(20*T);
    printf("\n out=%d",(int)out);


  in=0;
   sc_start(20*T);

 printf("\n out=%d",(int)out);

   in=0;
   sc_start(20*T);
    printf("\n out=%d",(int)out);


   in=1;
   sc_start(20*T);
    printf("\n out=%d",(int)out);


   in=1;
   sc_start(20*T);
 printf("\n out=%d",(int)out);


  in=1;
   sc_start(20*T);
    printf("\n out=%d",(int)out);



   in=1;
   sc_start(20*T);
    printf("\n out=%d",(int)out);



   in=0;
   sc_start(20*T);
    printf("\n out=%d",(int)out);

    

    //tfp->close();
   




   delete top;
   //delete tfp;

   return 0;

}





















