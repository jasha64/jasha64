module BusTop(
    input logic CLK100MHZ,
    input logic BTNC,
    input logic [14:0] SW,
    output logic [15:0] LED);
    
    logic clk4;
    clkdiv U0(CLK100MHZ, BTNC, clk4);
    
    //logic yout[3:0], y2o[3:0], q1[3:0], q2[3:0], q3[3:0];
    logic [3:0] yout;
    logic [3:0] y2o;
    logic [3:0] q1;
    logic [3:0] q2;
    logic [3:0] q3;
    _74377 U1(clk4, BTNC, SW[7], y2o, q1);
    _74377 U2(clk4, BTNC, SW[6], yout, q2);
    _74377 U3(clk4, BTNC, SW[5], yout, q3);
    //logic q4[3:0];
    logic [3:0] q4;
    RAM U4(clk4, BTNC, SW[0], SW[4:1], yout, q4);
    
    assign LED[3:0] = q2;
    assign LED[7:4] = q3;
    assign LED[11:8] = q1;
    assign LED[15:12] = q4;
    /*
    always_comb
        begin
            LED[0] = q2[0]; LED[1] = q2[1]; LED[2] = q2[2]; LED[3] = q2[3];
            LED[4] = q3[0]; LED[5] = q3[1]; LED[6] = q3[2]; LED[7] = q3[3];
            LED[8] = q1[0]; LED[9] = q1[1]; LED[10] = q1[2]; LED[11] = q1[3];
            LED[12] = q4[0]; LED[13] = q4[1]; LED[14] = q4[2]; LED[15] = q4[3];
        end
    */
    
    Mux#(1) U5({yout, SW[11:8]}, SW[12], y2o);
    Mux#(2) U6({q4, q3, q2, q1}, SW[14:13], yout);
    
endmodule
/*
instruction: 
��ʼ����SW[7] = SW[6] = SW[5] = 1��SW[0] = 0
��ͨ��U5����x��ֵ�Զ�������SW[11:8]���趨x��ֵ��Ȼ���趨SW[12]=0
��U1��en��x���Զ�ͨ��U1����U6���趨SW[7]=0����ʱLED[11:8]==x����ɺ��趨SW[7]=1
��U6��ָ����q1����U2���趨SW[14:13]=0��SW[6]=0����ʱLED[3:0]==x����ɺ��趨SW[6]=1
ͬ����y��U5��U1��U6��U3��
 ��SW[11:8]���趨y��ֵ��Ȼ���趨SW[12]=0
 �趨SW[7]=0����ʱLED[11:8]==y����ɺ��趨SW[7]=1
 �趨SW[14:13]=0��SW[5]=0����ʱLED[7:4]==y����ɺ��趨SW[5]=1
Ȼ��x��U2��U6��U4���趨SW[14:13]=1��SW[4:1]=0��SW[0]=1����ʱLED[15:12]==x����ɺ��趨SW[0]=0
y��U3��U6��U4�����벻ͬ��ַ�����趨SW[14:13]=2��SW[4:1]=1����ͬ��ַ����SW[0]=1����ʱLED[15:12]==y����ɺ��趨SW[0]=0
Ȼ��x��U4��U6��U3���趨SW[4:1]=0����ʱLED[15:12]==x���趨SW[14:13]=3��SW[5]=0����ʱLED[7:4]==x����ɺ��趨SW[5]=1
y��U4��U6��U2���趨SW[4:1]=1����ʱLED[15:12]==y���趨SW[14:13]=3��SW[6]=0����ʱLED[3:0]==y����ɺ��趨SW[6]=1
*/
