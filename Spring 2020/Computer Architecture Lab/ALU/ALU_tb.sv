module testbench3();
  logic        clk, reset;
  logic [31:0] a, b;
  logic [3:0]  c;
  logic [31:0] y, yexpected;
  logic [3:0]  z, zexpected;
  logic [31:0] vectornum, errors;    // bookkeeping variables
  logic [103:0]  testvectors[10000:0]; // array of testvectors
  
  // instantiate device under test
  ALU alu(a, b, c[2:0], y, z[0]);
  
  // generate clock
  always     // no sensitivity list, so it always executes
    begin
      clk = 1; #5; clk = 0; #5;
    end
  
  // at start of test, load vectors and pulse reset
  initial
    begin
      $readmemh("../Obj/alu_tv.txt", testvectors);
      vectornum = 0; 
      errors = 0;
      reset = 1; #27; 
      reset = 0;
    end
  // Note: $readmemh reads testvector files written in hexadecimal
  
  // apply test vectors on rising edge of clk
  always @(posedge clk)
    begin
      #1; {a, b, c, yexpected, zexpected} = testvectors[vectornum];
    end
 
  // check results on falling edge of clk
  always @(negedge clk)
    if (~reset) begin // skip during reset
      if (y !== yexpected || z[0] !== zexpected[0]) begin  
        $display("Error: inputs = %b, %b, %b", a, b, c[2:0]);
        $display("  outputs = %b, %b (%b, %b expected)", y, z[0], yexpected, zexpected[0]);
        errors = errors + 1;
      end
      // increment array index and read next testvector
      vectornum = vectornum + 1;
      if (testvectors[vectornum] === 'x) begin 
        $display("%d tests completed with %d errors", vectornum, errors);
        $finish;
      end
    end
    
endmodule
