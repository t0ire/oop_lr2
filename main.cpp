#include "eleven.h"


int main() {

   std::string s1;
   std::cin >> s1;

    try {
        Eleven eleven(s1);  
        std::cout << eleven.print() << std::endl;
    } catch (const std::exception& e) {
        std::cout <<  e.what() << std::endl;
    }
    
    try {
        Eleven s2 = {1, 10, 3};  
        std::cout << s2.print() << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        Eleven s3("1A3");  
        std::cout << s3.print() << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        Eleven s1("25");  
        Eleven s3("1A3");  
        
        std::cout << "s1 = " << s1.print() << std::endl;
        std::cout << "s3 = " << s3.print() << std::endl;
        std::cout << "s3 < s1: " << (s3.lt(s1) ? "true" : "false") << std::endl;
        
    } catch (const std::exception& e) {
        std::cout << "Ошибка: " << e.what() << std::endl;
    }
    
    return 0;
}