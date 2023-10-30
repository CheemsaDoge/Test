from cyaron import * 

for i in range(1, 4):
    test_data = IO(file_prefix="father", data_id=i) 
    n = 10
    m = 10
    tree = Graph.tree(n)
    test_data.input_writeln(n,m,tree)
    for i in range(1, m): 
        u = randint(1, n) 
        v = randint(1, n)
        test_data.input_writeln(u,v)
        test_data.output_gen("D:\\改题\\2023.8.15\\source\\七枪六马五分钟四把三人两倒下一把\\father.exe")
