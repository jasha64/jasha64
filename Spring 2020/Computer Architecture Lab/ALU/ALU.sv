module ALU(
    input logic signed [31:0] op1,  // 1st operand
    input logic signed [31:0] op2,  // 2nd operand
    input logic[2:0] con,  // control signal
    
    output logic signed [31:0] res,  // calculation result
    output logic zf  // zero flag
);
    assign zf = res == '0 ? 1'b1 : 1'b0;
    always_comb
    begin
        case (con)
            3'b000: res = op1 & op2;
            3'b001: res = op1 | op2;
            3'b010: res = op1 + op2;
            3'b011: res = 32'bx;
            3'b100: res = op1 & (~op2);
            3'b101: res = op1 | (~op2);
            3'b110: res = op1 - op2;
            3'b111: res = op1 < op2 ? 1'b1 : 1'b0;  // 若无signed，则此处为无符号比较，是错的
        endcase
    end
endmodule
