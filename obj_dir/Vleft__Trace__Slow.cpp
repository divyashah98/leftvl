// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vleft__Syms.h"


//======================

void Vleft::trace (VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback (&Vleft::traceInit, &Vleft::traceFull, &Vleft::traceChg, this);
}
void Vleft::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    Vleft* t=(Vleft*)userthis;
    Vleft__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    vcdp->scopeEscape(' ');
    t->traceInitThis (vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void Vleft::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vleft* t=(Vleft*)userthis;
    Vleft__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    t->traceFullThis (vlSymsp, vcdp, code);
}

//======================


void Vleft::traceInitThis(Vleft__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vleft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    vcdp->module(vlSymsp->name());  // Setup signal names
    // Body
    {
	vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void Vleft::traceFullThis(Vleft__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vleft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vleft::traceInitThis__1(Vleft__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vleft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->declBus  (c+1,"out",-1,7,0);
	vcdp->declBit  (c+2,"in",-1);
	vcdp->declBit  (c+3,"clr",-1);
	vcdp->declBit  (c+4,"clk",-1);
	vcdp->declBus  (c+1,"left out",-1,7,0);
	vcdp->declBit  (c+2,"left in",-1);
	vcdp->declBit  (c+3,"left clr",-1);
	vcdp->declBit  (c+4,"left clk",-1);
    }
}

void Vleft::traceFullThis__1(Vleft__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vleft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->fullBus  (c+1,(vlTOPp->out),8);
	vcdp->fullBit  (c+2,(vlTOPp->in));
	vcdp->fullBit  (c+3,(vlTOPp->clr));
	vcdp->fullBit  (c+4,(vlTOPp->clk));
    }
}
