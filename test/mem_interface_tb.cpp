#include "Vmem_interface.h"
#include "Vmem_interface__Dpi.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <random>

int main(int argc, char **argv) {

	Verilated::commandArgs(argc, argv);
	Verilated::traceEverOn(true);

	VerilatedVcdC *trace = new VerilatedVcdC;

	Vmem_interface *mem_interface = new Vmem_interface;
	mem_interface->trace(trace, 99);
	trace->open("trace.vcd");
	int tick_count = 0;

	std::random_device rd;
	std::mt19937_64 rand_eng(rd());
	std::uniform_int_distribution<uint32_t> rand_int32(0, 0xffffffff);
	
	svSetScope(svGetScopeFromName("TOP.mem_interface"));

	svLogicVecVal value;
	value.aval = 5;
	mem_interface->eval();
	mem_interface->read = 1;
	mem_interface->eval();
	printf("%x\n", mem_interface->read_data);
	printf("%x\n", mem_interface->mfc);
	Vmem_interface::taskRead(&value);
	mem_interface->eval();
	printf("%x\n", mem_interface->read_data);
	printf("%x\n", mem_interface->mfc);
	mem_interface->eval();
	printf("%x\n", mem_interface->read_data);
	printf("%x\n", mem_interface->mfc);
	mem_interface->read = 0;
	mem_interface->eval();
	printf("%x\n", mem_interface->read_data);
	printf("%x\n", mem_interface->mfc);

	// while (!Verilated::gotFinish()) {
	// for (int i = 0; i < 1000; i ++) {
	// 	tick_count ++;
	// 	mem_interface->clk = 0;
	// 	mem_interface->eval();
	// 	trace->dump(10 * tick_count - 2);

	// 	uint32_t a = rand_int32(rand_eng);
	// 	uint32_t b = rand_int32(rand_eng);
	// 	uint32_t op = i / 125;
	// 	if (op == 0b010 || op == 0b011 || op == 0b101) {
	// 		b &= 0x1f;
	// 	}

	// 	mem_interface->clk = 1;
	// 	alu->a = a;
	// 	alu->b = b;
	// 	alu->op = op;
	// 	alu->eval();
	// 	trace->dump(10 * tick_count);

	// 	mem_interface->clk = 0;
	// 	alu->eval();
	// 	trace->dump(10 * tick_count + 5);
	// 	trace->flush();

	// 	uint32_t out = alu->out;

	// 	switch (alu->op) {
	// 		case 0b000:
	// 			assert(out == a + b);
	// 			break;
	// 		case 0b001:
	// 			assert(out == a - b);
	// 			break;
	// 		case 0b010:
	// 			assert(out == a << b);
	// 			break;
	// 		case 0b011:
	// 			assert(out == a >> b);
	// 			break;
	// 		case 0b100:
	// 			assert(out == (a & b));
	// 			break;
	// 		case 0b101:
	// 			assert(out == (((int32_t) a) < 0 ? ~(~a >> b) : a >> b));
	// 			break;
	// 		case 0b110:
	// 			assert(out == (a | b));
	// 			break;
	// 		case 0b111:
	// 			assert(out == (a ^ b));
	// 			break;
	// 	}
	// }

	trace->close();

	printf("All tests passed\n");

	return 0;
}