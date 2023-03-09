#include <iostream>
#include <fstream>
#include <string>

int main() {
    char c;
    std::string file;
    int lineNumber = 0;
    do {
        std::cout << "Give the first file : ";
        std::cin >> file;
        std::ifstream influx(file);
        if(influx) {
            while (getline(influx, file)) {
                lineNumber++;
            }
        } else std::cout << "err" << std::endl;
        std::cout << "continue : ";
        std::cin >> c;
    } while(c == 'o');
    std::cout << lineNumber << " Lines counted" << std::endl;
    return 0;
}
