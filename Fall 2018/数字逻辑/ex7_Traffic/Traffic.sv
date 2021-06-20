module Traffic(
    input logic clk1,
    input logic _15s,
    input logic _45s,
    input logic clr,
    output logic [5:0] lights //�����ͨ��״̬
    );
    logic [1:0] state; //��̬
    parameter S0 = 2'b00, S1 = 2'b01, S2 = 2'b10, S3 = 2'b11; //״̬����
    
    //�Զ�������
    always_ff @ (posedge clk1, posedge clr)
        if (clr == 1) state <= S0;
        else
            case (state)
                S0: if (_45s) state <= S1;
                    else state <= S0;
                S1: if (_15s) state <= S2;
                    else state <= S1;
                S2: if (_45s) state <= S3;
                    else state <= S2;
                S3: if (_15s) state <= S0;
                    else state <= S3;
            endcase
    
    //����������
    always_comb           //NS  EW
        case (state)      //GBRGBR
            S0: lights = 6'b100001;
            S1: lights = 6'b101001;
            S2: lights = 6'b001100;
            S3: lights = 6'b001101;
        endcase
endmodule
