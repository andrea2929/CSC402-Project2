//
// Created by Andrea Halenkamp on 10/1/16.
//

#include "OO_Comparison.h"

bool IntWrapper::isLessThan(IComparable* rhs) const{
    IntWrapper* comparable = dynamic_cast<IntWrapper *>(rhs);
    return (storedValue < comparable->getValue());
}

int IntWrapper::getValue() {
    return storedValue;
}

IntWrapper::IntWrapper(int initialValue) {
    storedValue = initialValue;
}

bool StringWrapper::isLessThan(IComparable* rhs) const{
    StringWrapper* comparable = dynamic_cast<StringWrapper *>(rhs);
    return (storedValue < comparable->getValue());
}

string StringWrapper::getValue() {
    return storedValue;
}

StringWrapper::StringWrapper(string initialValue) {
    storedValue = initialValue;
}

vector<IComparable*> sortingFunctions::sorting(vector<IComparable*> input) {

    for (int x = 0; x < vectorSize; x++) {

        if(dynamic_cast<IntWrapper *>(input[x])) {
            IntWrapper* beginning = dynamic_cast<IntWrapper *>(input[x]);
            IntWrapper* minValue = beginning;
            int old = x;

            for (int y = x; y < vectorSize; y++) {
                if(minValue->isLessThan(dynamic_cast<IntWrapper *>(input[y]))) {
                    minValue = dynamic_cast<IntWrapper *>(input[y]);
                    old = y;
                }
            }


            input[x] = minValue;
            input[old] = beginning;
        }

        if(dynamic_cast<StringWrapper *>(input[x])) {
            StringWrapper* beginning = dynamic_cast<StringWrapper *>(input[x]);
            StringWrapper* minValue = beginning;
            int old = x;

            for (int y = x; y < vectorSize; y++) {
                if(minValue->isLessThan(dynamic_cast<StringWrapper *>(input[y]))) {
                    minValue = dynamic_cast<StringWrapper *>(input[y]);
                    old = y;
                }
            }


            input[x] = minValue;
            input[old] = beginning;
        }

    }

    return input;
}

bool sortingFunctions::sortingVerifications(vector<IComparable *> input) {
    bool isRight = 1; // Innocent until proven guilty!!!

    for (int i = 0; i < vectorSize-1; i++) {
        if(input[i]->isLessThan(input[i+1]))
            isRight = false;
    }

    return isRight;
}

void sortingFunctions::print(vector<IComparable *> input) {
    for(IComparable* i : input) {
        IntWrapper* intw = dynamic_cast<IntWrapper *>(i);
        if(intw)
            cout << intw->getValue() << endl;
        StringWrapper* stringw = dynamic_cast<StringWrapper *>(i);
        if(stringw)
            cout << stringw->getValue() << endl;
    }
}