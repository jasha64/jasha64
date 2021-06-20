module Adder4(
    input logic [3:0] a,
    input logic [3:0] b,
    input logic c0,
    output logic [3:0] s,
    output logic cf //���λ�ϲ����Ľ�λ
    //ע������nλ����Ӳ�����n+1λ���������������
    //���޷�����������ȼ������λ������λ�����������cfͬʱҲ�����ָʾ����
    //���з��������������λ������λ���͵ڶ�λ����ֵ�����λ�������Ľ�λ�Ƿ���ȣ������ȼ�˵�����������
);
    logic c1, c2, c3;
    FullAdder(a[0], b[0], c0, s[0], c1); FullAdder(a[1], b[1], c1, s[1], c2);
    FullAdder(a[2], b[2], c2, s[2], c3); FullAdder(a[3], b[3], c3, s[3], cf);
endmodule
