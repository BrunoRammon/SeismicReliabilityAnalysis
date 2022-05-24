#include <iostream>

char* file_name(const char* path) {
    char* file;
    while (*path) {
        if (*path++ == '/') {
            file = (const_cast<char *>(path));
        }
    }
    
    return file;
}

int main() {
    char* file = file_name(__FILE__);
    
    std::string sFile = file;
    sFile = sFile.substr(0, sFile.size()-4);
    std::cout << __FILE__ << std::endl;
    std::cout << file << std::endl;
    std::cout << sFile << std::endl;
    std::cout << std::endl;
    
    const char* file2 = __FILE__;
    std::cout << file2 << std::endl;
    *file2++;
    std::cout << file2 << std::endl;
    *file2++;
    std::cout << file2 << std::endl;
    *file2++;
    std::cout << file2 << std::endl;
    *file2--;
    std::cout << file2 << std::endl;
    *file2--;
    std::cout << file2 << std::endl;
    *file2--;
    std::cout << file2 << std::endl;
    *file2--;
    std::cout << file2 << std::endl;
    
    return 0;
}