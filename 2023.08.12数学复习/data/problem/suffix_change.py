import os

work_dir = 'E:/信竞资料/2022/7月 暑期/day4/problem/problem'

old_ext, new_ext = '.ans', '.out'
for filename in os.listdir(work_dir):
    split_file = os.path.splitext(filename)
    # print(split_file)
    file_ext = split_file[1]
    if old_ext == file_ext:     # 如果文件属性是 .docx 执行
        newfile = split_file[0] + new_ext  # 修改后的文件完整名称
        os.rename( # 实现重命名操作
            os.path.join(work_dir, filename ), # 文件路径不变
            os.path.join(work_dir, newfile)) # 文件后缀变为 [new_ext]值