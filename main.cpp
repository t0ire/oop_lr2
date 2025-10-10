#include "eleven.h"

int main() {

   std::string s1;
   std::cout << "=== ТЕСТ ПРОГРАММЫ ELEVEN ===" << std::endl;
   std::cout << "Введите 11-ричное число (используйте цифры 0-9 и A): ";
   std::cin >> s1;

    try {
        Eleven eleven(s1);  
        std::cout << "Вы ввели: " << eleven.print() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Ошибка: " << e.what() << std::endl;
    }
    
    try {
        Eleven s2 = {1, 10, 3};  
        std::cout << "Число из списка: " << s2.print() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Ошибка: " << e.what() << std::endl;
    }

    try {
        Eleven s3("1A3");  
        std::cout << "Число из строки: " << s3.print() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Ошибка: " << e.what() << std::endl;
    }

    try {
        // Инициализируем s1 каким-то значением
        Eleven s1("25");  // или Eleven s1 = {2, 5};
        Eleven s3("1A3");  
        
        std::cout << "s1 = " << s1.print() << std::endl;
        std::cout << "s3 = " << s3.print() << std::endl;
        std::cout << "s3 < s1: " << (s3.lt(s1) ? "true" : "false") << std::endl;
        
    } catch (const std::exception& e) {
        std::cout << "Ошибка: " << e.what() << std::endl;
    }
    
    return 0;
}