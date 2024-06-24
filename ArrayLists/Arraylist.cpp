#include "./ArrayList.h"
// Copyright 2021 Andrew Garcia

template <class U>
ostream& operator<<(ostream & os, ArrayList<U> a) {
    os << "[";
    for (int i = 0; i < a.getSize(); i++) {
        os << a.getData(i) << " ";
    }
    os << "]";
    return os;
}

template <class T>
ArrayList<T>::ArrayList() {
    size = 0;
    data = new T[size];
}

template <class T>
ArrayList<T>::ArrayList(int size, T val) {
    this->size = size;
    data = new T[size];
    for (int i = 0; i <size; i++) {
        data[i] = val;
    }
}

template <class T>
ArrayList<T>::ArrayList(const ArrayList<T> & copy) {
    setSize(copy.getSize());
    data = new T[size];
    for (int i = 0; i < size; i++) {
        data[i] = copy[i];
    }
}

template <class T>
ArrayList<T>::~ArrayList() {
    delete [] data;
}

template <class T>
void ArrayList<T>::setSize(int size) {
    if (size >= 0) {
        this->size = size;
    } else {
        std::cout << "Incorrect size\n";
        exit(1);
    }
}

template <class T>
int ArrayList<T>::getSize() const {
    return size;
}

template <class T>
T ArrayList<T>::getData(int index) const {
    if (index >= 0 && index < size) {
        return data[index];
    } else {
        std::cout << "Invalid Index\n";
        exit(0);
    }
}

template <class T>
T ArrayList<T>::operator[](int index) const {
    if (index >= 0 && index < size) {
        return data[index];
    } else {
        std::cout << "Invalid Index\n";
        exit(0);
    }
}

template <class T>
T& ArrayList<T>::operator[](int index) {
    return data[index];
}

template <class T>
const ArrayList<T> & ArrayList<T>::operator=(const ArrayList<T> rhs) {
    size = rhs.getSize();
    delete [] data;
    data = new T[size];
    for (int i = 0; i < size; i++) {
        data[i] = rhs[i];
    }
    return *this;
}

template <class T>
void ArrayList<T>::print() const {
    for (int i = 0; i < size; i++) {
        std::cout << data[i] << " ";
    }
    std::cout << "\n";
}

// Start of new functions

template <class T>
bool ArrayList<T>::operator!=(const ArrayList<T> & rhs) const {
    for (int i = 0; i < size; i++) {
        if (size != rhs.getSize()) {
            return true;
        } else if (data[i] != rhs[i]) {
            return true;
        } else {
            return false;
        }
    }
    return false;
}

template <class T>
ArrayList<T> ArrayList<T>::operator+(T val) const {
    ArrayList<T> c(*this);
    for (int i = 0; i < size; i++) {
        c[i] = data[i];
        c[i] += val;
    }
    return c;
}

template <class T>
ArrayList<T> ArrayList<T>::operator+(const ArrayList<T> & rhs) const {
    ArrayList<T> a(*this);
    for (int i = 0; i < size; i++) {
        if (a.getSize() == rhs.getSize()) {
            a[i] += rhs[i];
        }
    }
    return a;
}

template <class T>
ArrayList<T> & ArrayList<T>::operator--() {
    ArrayList<T> a(*this);
    if (a.getSize() == 0) {
            return *this;
    } else {
        for (int i = 1; i < size; i++) {
            data[i] -= 1;
            size--;
        }
    }
    return *this;
}

template <class T>
ArrayList<T> ArrayList<T>::operator--(int) {
    ArrayList<T> a(*this);
    if (a.getSize() == 0) {
            return *this;
    } else {
        for (int i = 1; i < size; i++) {
            a[i] = data[i];
            data[i] -= 1;
            size--;
        }
    }
    return a;
}

template <class T>
void ArrayList<T>::operator+=(T val) {
    int sizeA = size + 1;
    int *a = new int[sizeA];
    for (int i = 0; i < size; i++) {
        a[i] = data[i];
    }
    a[size] = val;
    size++;
    data = a;
    ArrayList();
    return;
}

template <class T>
void ArrayList<T>::operator+=(const ArrayList<T> & rhs) {
    int sizeA = size + rhs.getSize();
    int *a = new int[sizeA];
    int sA = size;
    for (int i = 0; i < size; i++) {
        a[i] = data[i];
    }
    for (int i = 0; i < rhs.getSize(); i++) {
        a[size] = rhs.data[i];
        size++;
    }
    data = a;
    ArrayList();
    return;
}

template <class T>
ArrayList<T> ArrayList<T>::operator*(int val) const {
    int sizeA = size * val;
    int sA = size;
    ArrayList<T> intA(*this);
    intA.setSize(sizeA);
    for (int i = 0; i < size; i++) {
        intA[i] = data[i];
    }
    for (int i = 0; i < sizeA; i++) {
        intA[sA] += data[i];
        sA++;
    }
    return intA;
}

template <class T>
ArrayList<T> ArrayList<T>::operator/(int val) const {
    int sizeB = size / val;
    ArrayList<T> intB(*this);
    intB.setSize(sizeB);
    for (int i = 0; i < size; i++) {
        intB[i] = data[i];
    }
    return intB;
}
