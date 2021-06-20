module _74377 (
    input logic clk,
    input logic clr,
    input logic en_b,
    input logic [3:0] D,
    output logic [3:0] Q);
    always_ff @ (posedge clk, posedge clr) //������ֵ��clrΪ1��clkΪXʱִ�����㣬�����ж����첽����
        if (clr)  Q <= '0;
        else if (~en_b) Q <= D;
endmodule
