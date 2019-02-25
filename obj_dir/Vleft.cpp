// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vleft.h for the primary calling header

#include "Vleft.h"             // For This
#include "Vleft__Syms.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vleft) {
    Vleft__Syms* __restrict vlSymsp = __VlSymsp = new Vleft__Syms(this, name());
    Vleft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vleft::__Vconfigure(Vleft__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vleft::~Vleft() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void Vleft::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vleft::eval\n"); );
    Vleft__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vleft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    while (VL_LIKELY(__Vchange)) {
	VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
	vlSymsp->__Vm_activity = true;
	_eval(vlSymsp);
	__Vchange = _change_request(vlSymsp);
	if (VL_UNLIKELY(++__VclockLoop > 100)) VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Verilated model didn't converge");
    }
}

void Vleft::_eval_initial_loop(Vleft__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    int __VclockLoop = 0;
    QData __Vchange = 1;
    while (VL_LIKELY(__Vchange)) {
	_eval_settle(vlSymsp);
	_eval(vlSymsp);
	__Vchange = _change_request(vlSymsp);
	if (VL_UNLIKELY(++__VclockLoop > 100)) VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Verilated model didn't DC converge");
    }
}

//--------------------
// Internal Methods

VL_INLINE_OPT void Vleft::_sequent__TOP__1(Vleft__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vleft::_sequent__TOP__1\n"); );
    Vleft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIG8(__Vdly__out,7,0);
    // Body
    __Vdly__out = vlTOPp->out;
    // ALWAYS at left.v:3
    __Vdly__out = ((IData)(vlTOPp->clr) ? 0U : ((0xfeU 
						 & ((IData)(vlTOPp->out) 
						    << 1U)) 
						| (IData)(vlTOPp->in)));
    vlTOPp->out = __Vdly__out;
}

void Vleft::_eval(Vleft__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vleft::_eval\n"); );
    Vleft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((~ (IData)(vlTOPp->clk)) & (IData)(vlTOPp->__Vclklast__TOP__clk))) {
	vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

void Vleft::_eval_initial(Vleft__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vleft::_eval_initial\n"); );
    Vleft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vleft::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vleft::final\n"); );
    // Variables
    Vleft__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vleft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vleft::_eval_settle(Vleft__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vleft::_eval_settle\n"); );
    Vleft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

VL_INLINE_OPT QData Vleft::_change_request(Vleft__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vleft::_change_request\n"); );
    Vleft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vleft::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vleft::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((in & 0xfeU))) {
	Verilated::overWidthError("in");}
    if (VL_UNLIKELY((clr & 0xfeU))) {
	Verilated::overWidthError("clr");}
    if (VL_UNLIKELY((clk & 0xfeU))) {
	Verilated::overWidthError("clk");}
}
#endif // VL_DEBUG

void Vleft::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vleft::_ctor_var_reset\n"); );
    // Body
    out = VL_RAND_RESET_I(8);
    in = VL_RAND_RESET_I(1);
    clr = VL_RAND_RESET_I(1);
    clk = VL_RAND_RESET_I(1);
    __Vclklast__TOP__clk = VL_RAND_RESET_I(1);
    __Vm_traceActivity = VL_RAND_RESET_I(32);
}
