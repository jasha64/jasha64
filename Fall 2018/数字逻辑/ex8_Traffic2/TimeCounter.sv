module TimeCounter(
    input logic st,
    input logic clk1,
    output logic ts,
    output logic tl
    );
    integer cnt;
    parameter TS = 5, TL = 15;
    always_ff @ (posedge st, posedge clk1)
        if (st == 1) cnt <= 0;
        else if (cnt < TL-1) cnt <= cnt+1;
            else cnt <= TL-1;
    assign ts = (cnt >= TS-1); //ts��tl�ڵ�ʱ��֮��Ҫһֱ����Ϊtrue�����Բ�����ʱ�����
    assign tl = (cnt >= TL-1);
endmodule
