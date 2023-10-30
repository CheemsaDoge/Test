'''
Author: ltt
Date: 2023-08-11 17:37:44
LastEditors: ltt
LastEditTime: 2023-08-11 17:44:09
FilePath: generator.py
'''
from cyaron import *

_n = ati([10] * 2 + [100] + [1e5] * 7)
_m = ati([10] * 3 + [1e5] * 7)

for i in range(len(_n)):
    print(f"generate {i+1}")
    data = IO(file_prefix="lca", data_id=i+1)
    n = _n[i]
    m = _m[i]
    tree = Graph.tree(n)
    data.input_writeln(n, m)
    data.input_writeln(tree.to_str(output=Edge.unweighted_edge, shuffle=True))
    for _ in range(m):
        l = randint(1, n-1)
        r = randint(l+1, n)
        data.input_writeln(l, r)
    data.output_gen("std.exe")
    # Compare.program("std2.exe", input=data, std_program="std.exe")