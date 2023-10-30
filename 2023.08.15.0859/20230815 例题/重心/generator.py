from cyaron import *

_n = ati([10] * 3 + [100] * 7 + [1e5] * 10)

for i in range(len(_n)):
    print(f"generate {i+1}")
    data = IO(file_prefix="centroid", data_id=i+1)
    n = _n[i]
    tree = Graph.tree(n)
    data.input_writeln(n)
    data.input_writeln(tree.to_str(output=Edge.unweighted_edge, shuffle=True))
    data.output_gen("std.exe")
    # Compare.program("std2.exe", input=data, std_program="std.exe")