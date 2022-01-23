#include <filesystem>
#include <iostream>

void eg1_1() {
    /*判断是否为绝对路径*/
    // std::filesystem::path abs_path = "C:\\Users";
    std::filesystem::path abs_path = "/usr/local";  // 注意，实例化path的时候可以直接用等号
    std::cout << "abs_path.is_absolute() : " << abs_path.is_absolute() << std::endl;
    std::cout << "abs_path.is_relative() : " << abs_path.is_relative() << std::endl;

    std::filesystem::path rel_path = "../";
    std::cout << "rel_path.is_absolute() : " << rel_path.is_absolute() << std::endl;
    std::cout << "rel_path.is_relative() : " << rel_path.is_relative() << std::endl;
}

void eg1_2() {
    /*路径分割*/
    std::filesystem::path path = "../test_dir/1.txt";
    std::cout << "path.relative_path() : " << path.relative_path() << std::endl;
    std::cout << "path.parent_path() : " << path.parent_path() << std::endl;
    std::cout << "path.filename() : " << path.filename() << std::endl;
    std::cout << "path.stem() : " << path.stem() << std::endl;
    std::cout << "path.extension() : " << path.extension() << std::endl;
}

void eg1_3() {
    /*路径拼接*/
    std::filesystem::path path = "../test_dir";
    std::filesystem::path txt1_path = path / "1.txt";
    std::filesystem::path txt2_path = path / "1_dir" / "2.txt";
    std::cout << "txt1_path : " << txt1_path << std::endl;
    std::cout << "txt2_path : " << txt2_path << std::endl;
    path /= "1.txt";
    std::cout << "path : " << path << std::endl;
}

void eg2_1() {
    /*获取当前路径*/
    std::filesystem::path current_path = std::filesystem::current_path();
    std::cout << "current_path : " << current_path << std::endl;
}

void eg2_2() {
    /*返回指定目录下的所有文件/文件夹*/
    std::filesystem::directory_iterator iter("../test_dir");
    for(const auto &i : iter) {
        std::cout << i.path() <<std::endl;
    }
}

void eg2_3() {
    /*递归返回指定目录下的所有文件/文件夹*/
    std::filesystem::recursive_directory_iterator iter("../test_dir");
    for(const auto &i : iter) {
        std::cout << i.path() <<std::endl;
    }
}

void eg2_4() {
    /*判断路径是否存在*/
    bool exist = std::filesystem::exists("C:\\Users");
    std::cout << "exist : " << exist << std::endl;
}

void eg2_5() {
    /*判断路径是文件还是目录*/
    std::filesystem::path file_path = "../test_dir/1.txt";
    std::filesystem::path dir_path = "../test_dir/1_dir";
    std::cout << "is_regular_file(file_path) : "
              << std::filesystem::is_regular_file(file_path)
              << std::endl;
    std::cout << "is_directory(dir_path) : "
              << std::filesystem::is_directory(dir_path)
              << std::endl;
}

void eg2_6() {
    /*返回绝对路径*/
    std::filesystem::path path = "../test_dir";
    std::filesystem::path abs_path = std::filesystem::absolute(path);
    std::cout << "abs_path : " << abs_path << std::endl;
    std::cout << "exists(abs_path) : " << std::filesystem::exists(abs_path) << std::endl;
}

void eg3_1() {
    /*文件拷贝*/
    std::cout << "~~~~~~before copy_file~~~~~~" << std::endl;
    for (const auto &i :std::filesystem::directory_iterator("../test_dir")) {
        std::cout << i.path() << std::endl;
    }
    std::filesystem::copy_file("../test_dir/1.txt", "../test_dir/eg3_1.txt");
    std::cout << "~~~~~~after copy_file~~~~~~" << std::endl;
    for (const auto &i :std::filesystem::directory_iterator("../test_dir")) {
        std::cout << i.path() << std::endl;
    }
}

void eg3_2() {
    /*文件删除*/
    std::cout << "~~~~~~before remove~~~~~~" << std::endl;
    for (const auto &i :std::filesystem::directory_iterator("../test_dir")) {
        std::cout << i.path() << std::endl;
    }
    std::filesystem::remove("../test_dir/eg3_1.txt");
    std::cout << "~~~~~~after remove~~~~~~" << std::endl;
    for (const auto &i :std::filesystem::directory_iterator("../test_dir")) {
        std::cout << i.path() << std::endl;
    }
}

void eg3_3() {
    /*路径拷贝*/
    std::cout << "~~~~~~before copy[1_dir]~~~~~~" << std::endl;
    for (const auto &i :std::filesystem::directory_iterator("../test_dir/1_dir")) {
        std::cout << i.path() << std::endl;
    }
    std::filesystem::copy("../test_dir/1_dir",
                          "../test_dir/eg3_3_dir",
                          std::filesystem::copy_options::recursive);
    std::cout << "~~~~~~after copy[eg3_3_dir]~~~~~~" << std::endl;
    for (const auto &i :std::filesystem::directory_iterator("../test_dir/eg3_3_dir")) {
        std::cout << i.path() << std::endl;
    }
}

void eg3_4() {
    /*递归删除*/
    std::filesystem::path dir_path = "../test_dir/eg3_3_dir";
    std::cout << "exists(dir_path) : " << std::filesystem::exists(dir_path) << std::endl;
    std::filesystem::remove_all(dir_path);
    std::cout << "exists(dir_path) : " << std::filesystem::exists(dir_path) << std::endl;
}

int main(int argc, char* argv[]) {
    // `filesystem::path` vs. `os.path`
//    eg1_1();
//    eg1_2();
//    eg1_3();

    // `filesystem` vs. `os`
//    eg2_1();
//    eg2_2();
//    eg2_3();
//    eg2_4();
//    eg2_5();
//    eg2_6();

    // `filesystem` vs. `shutil`
//    eg3_1();
//    eg3_2();
//    eg3_3();
//    eg3_4();

    return 0;
}