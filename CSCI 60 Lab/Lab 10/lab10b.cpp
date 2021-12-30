#include <iostream>
using namespace std;
void clean() {
    std::size_t size = capacity_;
    for(unsigned short i = capacity_; i > 0; i--) {
        if(i == 0){
            size--;
        }else{
            break;
        }
    }
    unsigned short *temp = new unsigned short[size];
    for(std::size_t i = 0; i < size; i++) {
        temp[i] = data_[i];
    }
    delete [] data_;
    data_ = temp;
    temp = nullptr;
    capacity_ = size;
}