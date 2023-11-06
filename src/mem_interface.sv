module mem_interface (
	input write,
	input read,
	input [31:0] addr,
	input [31:0] write_data,
	output reg [31:0] read_data,
	output reg mfc
);

	export "DPI-C" task taskRead;

	always @(negedge(write) or negedge(read) or addr or write_data) begin
		mfc = 1'b0;
	end

	task taskRead;
		input [31:0] data;
		read_data = data;
		mfc = 1'b1;
	endtask

	task taskWrite;
		mfc = 1'b1;
	endtask

endmodule