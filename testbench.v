module testbench;

/* verilator lint_off UNUSED */

wire[7:0] out;
reg clk,clr,in;

left l(out,in,clr,clk);

initial
begin


/* verilator lint_off STMTDLY */


clr=1;
clk=0;
in=0;
#10 clr=0;

#10 in=1;
#20 in=0;
#20 in=0;
#20 in=1;
#20 in=1;
#20 in=1;
#20 in=1;
#20 in=0;

end

initial
begin
#180 $finish;
end



always
begin
#10 clk=~clk;
end

/* verilator lint_on STMTDLY */

/* verilator lint_on UNUSED */
endmodule

