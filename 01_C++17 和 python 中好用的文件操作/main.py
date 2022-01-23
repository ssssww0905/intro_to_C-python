import os
import shutil

def eg1_1():
    """判断是否为绝对路径"""
    # abs_path = "C:\\Users"
    abs_path = "/usr/local"
    print("os.path.isabs({}) : {}".format(abs_path, os.path.isabs(abs_path)))
    rel_path = "../"
    print("os.path.isabs({}) : {}".format(rel_path, os.path.isabs(rel_path)))

def eg1_2():
    """路径分割"""
    path = "../test_dir/1.txt"
    print("os.path.split(path) : {}".format(os.path.split(path)))
    print("os.path.dirname(path) : {}".format(os.path.dirname(path)))
    print("os.path.basename(path) : {}".format(os.path.basename(path)))

def eg1_3():
    """路径拼接"""
    path = "../test_dir"
    txt1_path = os.path.join(path, "1.txt")
    txt2_path = os.path.join(path, "1_dir", "2.txt")
    print("txt1_path : {}".format(txt1_path))
    print("txt2_path : {}".format(txt2_path))

def eg2_1():
    """获取当前路径"""
    current_path = os.getcwd()
    print("current_path : {}".format(current_path))

def eg2_2():
    """返回指定目录下的所有文件/文件夹"""
    for i in os.listdir("./test_dir"):
        print(i)

def eg2_3():
    """递归返回指定目录下的所有文件/文件夹"""
    for root, dirs, files in os.walk("./test_dir"):
        print("root : {}, dirs : {}, files : {}".format(root, dirs, files))

def eg2_4():
    """判断路径是否存在"""
    path = "C:\\Users"
    print("os.path.exists({}) : {}".format(path, os.path.exists(path)))

def eg2_5():
    """判断路径是文件还是目录"""
    file_path = "./test_dir/1.txt"
    dir_path = "./test_dir/1_dir"
    print("os.path.isfile({}) : {}".format(file_path, os.path.isfile(file_path)))
    print("os.path.isdir({}) : {}".format(dir_path, os.path.isdir(dir_path)))

def eg2_6():
    """返回绝对路径"""
    path = "../../-PyTorch-"
    abs_path = os.path.abspath(path)
    print("abs_path : {}".format(abs_path))
    print("os.path.exists({}) : {}".format(abs_path, os.path.exists(abs_path)))

def eg3_1():
    """文件拷贝"""
    print("~~~~~~before copy_file~~~~~~")
    for i in os.listdir("./test_dir"):
        print(i)
    src_path = "./test_dir/1.txt"
    dst_path = "./test_dir/eg3_1.txt"
    shutil.copyfile(src_path, dst_path)
    print("~~~~~~after copy_file~~~~~~")
    for i in os.listdir("./test_dir"):
        print(i)

def eg3_2():
    """文件删除"""
    print("~~~~~~before remove~~~~~~")
    for i in os.listdir("./test_dir"):
        print(i)
    rm_path = "./test_dir/eg3_1.txt"
    os.remove(rm_path)
    print("~~~~~~after remove~~~~~~")
    for i in os.listdir("./test_dir"):
        print(i)

def eg3_3():
    """路径拷贝"""
    print("~~~~~~before copy[1_dir]~~~~~~")
    for i in os.listdir("./test_dir/1_dir"):
        print(i)
    src_path = "./test_dir/1_dir"
    dst_path = "./test_dir/eg3_3_dir"
    shutil.copytree(src_path, dst_path)
    print("~~~~~~after copy[eg3_3_dir]~~~~~~")
    for i in os.listdir("./test_dir/eg3_3_dir"):
        print(i)

def eg3_4():
    """路径删除"""
    dir_path = "./test_dir/eg3_3_dir"
    print("os.path.exists({}) : {}".format(dir_path, os.path.exists(dir_path)))
    shutil.rmtree(dir_path)
    print("os.path.exists({}) : {}".format(dir_path, os.path.exists(dir_path)))

if __name__ == "__main__":
    # `filesystem::path` vs. `os.path`
    # eg1_1()
    # eg1_2()
    # eg1_3()

    # `filesystem` vs. `os`
    # eg2_1()
    # eg2_2()
    # eg2_3()
    # eg2_4()
    # eg2_5()
    # eg2_6()

    # `filesystem` vs. `shutil`
    # eg3_1()
    # eg3_2()
    eg3_3()
    # eg3_4()
    #
    # print("~~~~~~下课~~~~~~")
