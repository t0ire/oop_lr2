#pragma once


#include <iostream>
#include <string>
#include <initializer_list>
#include <stdexcept>
#include <algorithm> 

class Eleven{
private:
    unsigned char* massiv;
    size_t size;

    bool numberCheck(unsigned char num) const;
    void pruning();
    
public:
    Eleven(); // пустой массив
    Eleven(const size_t & n, unsigned char t = 0); // массив из n эл-в заполненный t //если n будет  отриц преобразует в огромное положительное) int?
    Eleven(const std::initializer_list< unsigned char> &t); // {}
    Eleven(const std::string &t); // массив из кодов символов строки 
    Eleven(const Eleven& other); // копия с новой памятью
    Eleven(Eleven&& other) noexcept; // перемещение
    //virtual ~Eleven() noexcept; // чистка, virtual чистка объектов производных классов

    ~Eleven() noexcept;

    Eleven add(const Eleven& other) const; // возвращаем новый обхъект, передаем желемент по ссылке, неменяется исходник
    Eleven sub(const Eleven& other) const;
    Eleven copy(const Eleven& other) const; // использует конструктор копирования

    bool eq(const Eleven& other) const;
    bool lt(const Eleven& other) const;
    bool gt(const Eleven& other) const;

    std::string print() const; //выводит строку 
    size_t getSize() const;

};

