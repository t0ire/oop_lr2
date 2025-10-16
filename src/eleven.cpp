#include "eleven.h"

bool Eleven::numberCheck(unsigned char num) const{
    return num >= 0 && num <= 10;
}

void Eleven::pruning() {
    if (massiv == nullptr) return;
    
    size_t newSize = size;
    while (newSize > 1 && massiv[newSize - 1] == 0) {
        newSize--;
    }
    
    if (newSize != size) {
        unsigned char* newMassiv = new unsigned char[newSize];
        for (size_t i = 0; i < newSize; ++i) {
            newMassiv[i] = massiv[i];
        }
        delete[] massiv;
        massiv = newMassiv;
        size = newSize;
    }
}

size_t Eleven::getSize() const{
    return size;
}

std::string Eleven::print() const {
    if (size == 0) {
        return "0";
    }

    std::string res;
    for (int i = (int)size - 1; i >= 0; --i) {
        if (massiv[i] == 10) {
            res += 'A';
        }
        else {
            res += (massiv[i] + '0');
        }
    }

    res;
    return res;
}

Eleven::Eleven(): massiv(nullptr), size(0) {}

Eleven::Eleven(const size_t & n, unsigned char t): size(n) {
    if (!numberCheck(t)){
        throw std::invalid_argument("num out of range");
    }

    if (size > 0){
        massiv = new unsigned char[size];
        for (size_t i = 0; i < size; ++i){
            massiv[i] = t;
        }
    }
    else {
        massiv = nullptr;
    }
}

Eleven::Eleven(const std::initializer_list< unsigned char> &t): size(t.size()){
    if (size == 0){
        massiv = nullptr;
        return;
    }

    massiv = new unsigned char [size];
    
    size_t i = size - 1;
    for (unsigned char num : t){
        if (!numberCheck(num)){
            delete[] massiv;
            throw std::invalid_argument("num out of range");
        }
        massiv[i--] = num;
    }
    pruning();
}

Eleven::Eleven(const std::string &t) {
    if (t.empty()){
        size = 0;
        massiv = nullptr;
        return;
    }

    size = t.length();
    massiv = new unsigned char [size];

    for (size_t i = 0; i < size; ++i){
        char s = t[size - 1 - i];
    
        if (s >= '0' && s <= '9'){
        massiv[i] = s - '0';
            }
        else if (s == 'A' || s == 'a'){
            massiv[i] = 10;
        }
        else{
            delete[] massiv;
            throw std::invalid_argument("num out of range");
        }
    }

    pruning();
}

Eleven::Eleven(const Eleven& other): size(other.size){ // забираем размер
    if (size > 0) {
        massiv = new unsigned char [size];
        for (size_t i = 0; i < size; ++i) {
            massiv[i] = other.massiv[i]; // забираем содержимое
        }
    }
    else {
        massiv = nullptr;
    }
}

Eleven::Eleven(Eleven&& other) noexcept : massiv(other.massiv), size(other.size) { // забираем тут у other
    other.massiv = nullptr; // обнуляемся
    other.size = 0;
}

Eleven::~Eleven() noexcept {
    delete [] massiv;
}

Eleven Eleven::add(const Eleven& other) const {
    size_t msize = std::max(size, other.size);
    Eleven res(msize + 1, 0);

    unsigned char dis = 0; //разряд
    unsigned char sum;
    for (size_t i = 0; i < msize || dis > 0; ++i) {
        sum = dis;

        if (i < size){
            sum += massiv[i];
        }
        if (i < other.size) {
            sum += other.massiv[i];
        }

        res.massiv[i] = sum % 11;
        dis = sum / 11;
    }

    res.pruning();  // обрезка 0
    return res;
}

Eleven Eleven::sub(const Eleven& other) const {
    if (this->lt(other)) {
        throw std::invalid_argument("cannot be subtracted");
    }

    if (this->eq(other)) {
        return Eleven();
    }

    Eleven res(size, 0);

    int diff, cur;
    int dis = 0; // разряд 
    for (size_t i = 0; i < size; ++i) {
        cur = massiv[i] - dis;

        if (i < other.size) {
            diff = other.massiv[i];
        }
        else {
            diff = 0;
        }

        if (cur < diff) {
            cur += 11;
            dis = 1;
        }
        else {
            dis = 0;
        }

        res.massiv[i] = cur - diff;
    }

    res.pruning();  // обрезка 0
    return res;  
}

Eleven Eleven::copy(const Eleven& other) const {
    return Eleven(*this);
}

bool Eleven::eq(const Eleven& other) const {
    if (size != other.size) {
        return false;
    }
    
    for (size_t i = 0; i < size; ++i) {
        if (massiv[i] != other.massiv[i]) {
            return false;
        }
    }

    return true;
}

bool Eleven::lt(const Eleven& other) const {
    if (size != other.size) {
        return size < other.size;
    }

    for (int i = (int)size - 1; i >= 0; --i) {
        if (massiv[i] != other.massiv[i]) {
            return massiv[i] < other.massiv[i];
        }
    }

    return false;
}

bool Eleven::gt(const Eleven& other) const {
    if (!this->lt(other) && !this->eq(other)) {
        return true;
    }

    return false;
}

