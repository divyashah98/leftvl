module left(output reg[7:0] out,input in,clr,clk);

always @(negedge clk)
begin

if(clr)
begin
out<=0;
end

else
begin
out<={out[6:0],in};
end

end

endmodule





