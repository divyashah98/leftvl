// Verilated -*- SystemC -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vleft.h for the primary calling header

#include "Vleft.h"             // For This
#include "Vleft__Syms.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_SC_CTOR_IMP(Vleft)
#if (SYSTEMC_VERSION>20011000)
    : out("out"), in("in"), clr("clr"), clk("clk")
#endif
 {
    Vleft__Syms* __restrict vlSymsp = __VlSymsp = new Vleft__Syms(this, name());
    Vleft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Sensitivities on all clocks and combo inputs
    SC_METHOD(eval);
    sensitive << in;
    sensitive << clr;
    sensitive << clk;
    
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

VL_INLINE_OPT void Vleft::_combo__TOP__1(Vleft__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vleft::_combo__TOP__1\n"); );
    Vleft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__left__clk, vlTOPp->clk);
}

void Vleft::_settle__TOP__2(Vleft__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vleft::_settle__TOP__2\n"); );
    Vleft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__left__clk, vlTOPp->clk);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__left__clr, vlTOPp->clr);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__left__in, vlTOPp->in);
    VL_ASSIGN_SII(8,vlTOPp->out, vlTOPp->__Vcellout__left__out);
}

VL_INLINE_OPT void Vleft::_sequent__TOP__3(Vleft__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vleft::_sequent__TOP__3\n"); );
    Vleft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIG8(__Vdly____Vcellout__left__out,7,0);
    // Body
    __Vdly____Vcellout__left__out = vlTOPp->__Vcellout__left__out;
    // ALWAYS at left.v:3
    __Vdly____Vcellout__left__out = ((IData)(vlTOPp->__Vcellinp__left__clr)
				      ? 0U : ((0xfeU 
					       & ((IData)(vlTOPp->__Vcellout__left__out) 
						  << 1U)) 
					      | (IData)(vlTOPp->__Vcellinp__left__in)));
    vlTOPp->__Vcellout__left__out = __Vdly____Vcellout__left__out;
    VL_ASSIGN_SII(8,vlTOPp->out, vlTOPp->__Vcellout__left__out);
}

VL_INLINE_OPT void Vleft::_combo__TOP__4(Vleft__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vleft::_combo__TOP__4\n"); );
    Vleft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__left__clr, vlTOPp->clr);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__left__in, vlTOPp->in);
}

void Vleft::_eval(Vleft__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vleft::_eval\n"); );
    Vleft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
    vlTOPp->__Vm_traceActivity = (2U | vlTOPp->__Vm_traceActivity);
    if (((~ (IData)(vlTOPp->__Vcellinp__left__clk)) 
	 & (IData)(vlTOPp->__Vclklast__TOP____Vcellinp__left__clk))) {
	vlTOPp->_sequent__TOP__3(vlSymsp);
	vlTOPp->__Vm_traceActivity = (4U | vlTOPp->__Vm_traceActivity);
    }
    vlTOPp->_combo__TOP__4(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP____Vcellinp__left__clk 
	= vlTOPp->__Vcellinp__left__clk;
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
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
    vlTOPp->__Vm_traceActivity = (1U | vlTOPp->__Vm_traceActivity);
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
}
#endif // VL_DEBUG

void Vleft::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vleft::_ctor_var_reset\n"); );
    // Body
    __Vcellinp__left__clk = VL_RAND_RESET_I(1);
    __Vcellinp__left__clr = VL_RAND_RESET_I(1);
    __Vcellinp__left__in = VL_RAND_RESET_I(1);
    __Vcellout__left__out = VL_RAND_RESET_I(8);
    __Vclklast__TOP____Vcellinp__left__clk = VL_RAND_RESET_I(1);
    __Vm_traceActivity = VL_RAND_RESET_I(32);
}
