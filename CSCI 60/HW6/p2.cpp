#include "p2.h"

template <typename T>
tmplt<T>::tmplt() {
    dimension=0;
}


template <typename T>
tmplt<T>::tmplt(int dim) {
    dimension=dim;
    for(int i=0;i<10;i++) {
        arr[i]=T();
    }
}


template <typename T>
tmplt<T>::tmplt(int dim, T a[]) {
    dimension=dim;
    for(int i=0;i<10;i++) {
        arr[i]=a[i];
    }
}
