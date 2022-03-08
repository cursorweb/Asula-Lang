#include <iostream>
#include <string>


int main() {
    std::string string;
    std::cout << "Name: ";
    std::getline(std::cin, string);
    std::cout << "'" << string << "'" << std::endl;
}