#include "Vleft.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <stdio.h>


Vleft* top = new Vleft;
VerilatedVcdC*  tfp=new VerilatedVcdC;
int mytime;


void my_exit()
{
  
   tfp->close();
   tfp=NULL;
   delete top;
   delete tfp;

}

void my_trace()
{
    Verilated::traceEverOn(true);
    top->trace(tfp,99);
    tfp->open("obj_dir/left.vcd");

}


void init_ckt()
{
    mytime=0;
    top->clr=1;
    top-> eval();
    tfp->dump(mytime);
    printf("\n  time =%d rst = %d out = %d  \n",mytime ,top->clr,top->out); 

    mytime=10;
    top->clr=0;
    top-> eval();
    tfp->dump(mytime);
    printf("\n  time =%d rst = %d out = %d  \n",mytime,top->clr,top->out);   

}


 void tack()
{
    
    mytime=mytime+10;
    top->clk=1;
    top->eval();
    tfp->dump(mytime);
  
    mytime=mytime+10;
    top->clk=0;  
    top-> eval();
    tfp->dump(mytime);

    printf("\n clock = %d time =%d in = %d out = %d  \n", top->clk, mytime,top->in , top->out);
} 



int main(int argc, char** argv , char** env)
{
    
    Verilated::commandArgs(argc,argv);
    
    my_trace();
    
    
    int my_in[]={1,0,0,1,1,1,1,0};
    int i;
    
    
           init_ckt();

           
           for(i=0;i<=7;i++)
           {
               top->in=my_in[i];
               tack();
           }

           my_exit();


    return 0;
   
}


