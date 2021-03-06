// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vleft__Syms.h"


//======================

void Vleft::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vleft* t=(Vleft*)userthis;
    Vleft__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
	t->traceChgThis (vlSymsp, vcdp, code);
    }
}

//======================


void Vleft::traceChgThis(Vleft__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vleft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
			       | (vlTOPp->__Vm_traceActivity 
				  >> 1U))))) {
	    vlTOPp->traceChgThis__2(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((4U & vlTOPp->__Vm_traceActivity))) {
	    vlTOPp->traceChgThis__3(vlSymsp, vcdp, code);
	}
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vleft::traceChgThis__2(Vleft__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vleft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+1,(vlTOPp->__Vcellinp__left__in));
	vcdp->chgBit  (c+2,(vlTOPp->__Vcellinp__left__clr));
	vcdp->chgBit  (c+3,(vlTOPp->__Vcellinp__left__clk));
    }
}

void Vleft::traceChgThis__3(Vleft__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vleft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus  (c+4,(vlTOPp->__Vcellout__left__out),8);
    }
}
