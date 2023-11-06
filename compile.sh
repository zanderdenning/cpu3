#!/bin/bash
verilator --trace -cc src/${1}.sv
make -C obj_dir -f V${1}.mk > /dev/null
g++ -I /mnt/c/Users/Zander/Desktop/verilator/include -I /mnt/c/Users/Zander/Desktop/verilator/include/vltstd -I obj_dir test/${1}_tb.cpp /mnt/c/Users/Zander/Desktop/verilator/include/verilated.cpp /mnt/c/Users/Zander/Desktop/verilator/include/verilated_vcd_c.cpp /mnt/c/Users/Zander/Desktop/verilator/include/verilated_threads.cpp /mnt/c/Users/Zander/Desktop/verilator/include/verilated_dpi.cpp obj_dir/V${1}__ALL.cpp -o tb