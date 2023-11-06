module alu (
	input signed [31:0] a,
	input signed [31:0] b,
	input [2:0] op,
	output reg signed [31:0] out
);
	
	always @(a or b or op) begin
		out <= a;
		case (op)
			3'b000 : out <= a + b;
			3'b001 : out <= a - b;
			3'b010 : out <= a << b;
			3'b011 : out <= a >> b;
			3'b100 : out <= a & b;
			3'b101 : out <= a >>> b;
			3'b110 : out <= a | b;
			3'b111 : out <= a ^ b;
		endcase
	end

endmodule