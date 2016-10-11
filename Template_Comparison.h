//
// Created by Andrea Halenkamp on 10/5/16.
//

//In order to not have to redeclare templates over and over again I just kept everything
//in the header file.

#ifndef PROJECT2_TEMPLATE_COMPARISON_H
#define PROJECT2_TEMPLATE_COMPARISON_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define vectorSize 10
#define stringSize 4

class Comparables {
    //Best way to be able to make a vector I found was to make the template
    //inherit a class.
public:
    virtual void print() {
        cout << "Empty" << endl;
    }
};

template <class T>
class Comparable : public Comparables{
public:
    Comparable<T>(T newVal) {
        value = newVal;
    }
    bool operator<(const Comparable<T> & rhs) const {
        return value < rhs.value;
    }
    void print() {
        cout << value << endl;
    }
private:
    T value;
};

template <class T>
class templateSort {
public:
    static vector<Comparable<T> *> tSort(vector<Comparable<T> *> input) {

        for (int x = 0; x < vectorSize; x++) {
            Comparable<T>* beginning = input[x];
            Comparable<T>* minValue = input[x];

            int old = x;

            for (int y = x; y < vectorSize; y++) {
                if(*minValue<*input[y]) {
                    minValue = input[y];
                    old = y;
                }
            }

            input[x] = minValue;
            input[old] = beginning;
        }

        return input;
    }

    static bool sortVerifications(vector<Comparables*> input) {
        bool isRight = true; // Innocent until proven guilty!!!

        for (int i = 0; i < vectorSize-1; i++) {
            if(input[i]<input[i+1])
                isRight = false;
        }

        return isRight;
    }

    static void print(vector<Comparable<T> *> input) {
        for(Comparable<T>* i : input) {
            i->print();
        }
    }
};


#endif //PROJECT2_TEMPLATE_COMPARISON_H
