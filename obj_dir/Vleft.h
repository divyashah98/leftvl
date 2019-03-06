// Verilated -*- SystemC -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _Vleft_H_
#define _Vleft_H_

#include "systemc.h"
#include "verilated_sc.h"
#include "verilated.h"

class Vleft__Syms;
class VerilatedVcd;

//----------

SC_MODULE(Vleft) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    sc_out<uint32_t> out;
    sc_in<bool> in;
    sc_in<bool> clr;
    sc_in<bool> clk;
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    VL_SIG8(__Vcellinp__left__clk,0,0);
    VL_SIG8(__Vcellinp__left__clr,0,0);
    VL_SIG8(__Vcellinp__left__in,0,0);
    VL_SIG8(__Vcellout__left__out,7,0);
    VL_SIG8(__Vclklast__TOP____Vcellinp__left__clk,0,0);
    VL_SIG(__Vm_traceActivity,31,0);
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vleft__Syms* __VlSymsp;  // Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    Vleft& operator= (const Vleft&);  ///< Copying not allowed
    Vleft(const Vleft&);  ///< Copying not allowed
  public:
    SC_CTOR(Vleft);
    virtual ~Vleft();
    /// Trace signals in the model; called by application code
    void trace (VerilatedVcdC* tfp, int levels, int options=0);
    /// SC tracing; avoid overloaded virtual function lint warning
    virtual void trace (sc_trace_file* tfp) const { ::sc_core::sc_module::trace(tfp); }
    
    // API METHODS
  private:
    void eval();
  public:
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vleft__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vleft__Syms* symsp, bool first);
  private:
    static QData _change_request(Vleft__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__1(Vleft__Syms* __restrict vlSymsp);
    static void _combo__TOP__4(Vleft__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset();
  public:
    static void _eval(Vleft__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif // VL_DEBUG
  public:
    static void _eval_initial(Vleft__Syms* __restrict vlSymsp);
    static void _eval_settle(Vleft__Syms* __restrict vlSymsp);
    static void _sequent__TOP__3(Vleft__Syms* __restrict vlSymsp);
    static void _settle__TOP__2(Vleft__Syms* __restrict vlSymsp);
    static void traceChgThis(Vleft__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__2(Vleft__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__3(Vleft__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceFullThis(Vleft__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceFullThis__1(Vleft__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceInitThis(Vleft__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceInitThis__1(Vleft__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceInit (VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceFull (VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceChg  (VerilatedVcd* vcdp, void* userthis, uint32_t code);
} VL_ATTR_ALIGNED(128);

#endif // guard
