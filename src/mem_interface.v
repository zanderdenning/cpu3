module mem_interface (
	input clk,
	input write,
	input read,
	input [31:0] addr,
	input [31:0] write_data,
	output reg [31:0] read_data,
	output reg mfc
);

	export "DPI-C" task taskRead;

	task taskRead;
		input [31:0] data;
		read_data = data;
		mfc = 1'b1;
	endtask

endmodule