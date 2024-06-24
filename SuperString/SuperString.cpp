// Copyright 2021 Andrew Garcia
#include "./SuperString.h"

// DO NOT MODIFY START
void SuperString::print() {
    if (size != 0) {
        for (int i = 0; i < size; i++) {
            std::cout << data[i];
        }
        std::cout << "\n";
    } else {
        std::cout << "<EMPTY>\n";
    }
}

char SuperString::get(int index) {
    if (index >= 0 && index < size) {
        return data[index];
    }
    return '\0';
}

int SuperString::length() {
    return size;
}
// DO NOT MODIFY END

// PUT YOUR CODE BELOW!

SuperString::SuperString() {
    size = 0;
    data = new char[size];
}

SuperString::SuperString(std::string str) {
    size = str.length();
    data = new char[size];
    for (int i = 0; i < size; i++) {
        data[i] = str.at(i);
    }
}

SuperString::SuperString(int size, char val) {
    this->size = size;
    data = new char[size];
    for (int i = 0; i < size; i++) {
        data[i] = val;
    }
}

SuperString::SuperString(const SuperString& copy) {
    size = copy.size;
    data = new char[size];
    for (int i = 0; i < size; i++) {
        data[i] = copy.data[i];
    }
}

int SuperString::find(char c, int start) {
    for (int i = start; i < size; i++) {
        if (data[i] == c) {
            return i;
        }
    }
    return -1;
}

int SuperString::find(std::string str, int start) {
    int found;
    std::string charAr(data);
    if (start > 0) {
        found = charAr.rfind(str);
    } else {
        found = charAr.find(str);
    }
    return found;
}

SuperString SuperString::substr(int start, int numChar) {
    std::string bruh;
    for (int i = start; i < numChar; i++) {
        bruh += data[i];
    }
    return SuperString(bruh);
}

// Commmit 2

SuperString SuperString::reverse() {
    int temp;
    for (int i = 0; i < size/2; i++) {
        temp = data[size-i-1];
        data[size-i-1] = data[i];
        data[i] = temp;
    }
    return *this;
}

SuperString SuperString::replace(int start, int numChar, std::string sub) {
    std::string bruh, str;
    for (int i = numChar; i < size; i++) {
        str += data[i];
    }
    bruh = sub + str;
    if (start < 0 || start > 2) {
        return SuperString();
    } else {
        return SuperString(bruh);
    }
}

void SuperString::push_back(char c) {
    char *ret = new char[size+1];
    for (int i = 0; i < size; i++) {
        ret[i] = data[i];
    }
    ret[size] = c;
    size++;
    SuperString();
    return;
}

void SuperString::append(std::string str) {
    int sizeS = str.length();
    int sizeR = size + sizeS;
    char *ret = new char[sizeR];
    for (int i = 0; i < size; i++) {
        ret[i] = data[i];
    }
    for (int i = 0; i < sizeS; i++) {
        ret[size] = str.at(i);
        size++;
    }
    data = ret;
    SuperString();
    return;
}

void SuperString::append(const SuperString& obj) {
    int sizeR = obj.size;
    char *ret = new char[size + sizeR];
    for (int i = 0; i < size; i++) {
        ret[i] = data[i];
    }
    for (int i = 0; i < sizeR; i++) {
        ret[size] = obj.data[i];
        size++;
    }
    data = ret;
    return;
}

void SuperString::replace(char find, char rep) {
    for (int i = 0; i < size; i++) {
        if (data[i] == find) {
            data[i] = rep;
        }
    }
    return;
}
