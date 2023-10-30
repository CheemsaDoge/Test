from cyaron import *

_n = ati([10] * 3 + [100] * 7 + [1e5] * 10)

for i in range(len(_n)):
    print(f"generate {i+1}")
    data = IO(file_prefix="longest", data_id=i+1)
    n = _n[i]
    tree = Graph.tree(n, 0.2, 0.2, weight_limit = (1, 1000))
    data.input_writeln(n)
    data.input_writeln(tree)
    data.output_gen("std.exe")
    Compare.program("std2.exe", input=data, std_program="std.exe")