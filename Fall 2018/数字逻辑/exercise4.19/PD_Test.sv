module PD_Test();
    logic[3:0] a;
    logic p, d;
    PD pd(a, p, d); //�����ļ������ģ������
    logic[4:0] b;
    initial
        for (b = 0; b < 16; b = b+1) #10 a = b; //��Ϊaֻ��4λ������a == 15ʱ a = a+1�ͻ��Ϊ0���Ӷ���ѭ��
endmodule
