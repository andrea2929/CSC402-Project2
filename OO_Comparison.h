//
// Created by Andrea Halenkamp on 10/1/16.
//

#ifndef PROJECT2_OO_COMPARISON_H
#define PROJECT2_OO_COMPARISON_H

#include <string>
#include <vector>
#include <iostream>

#define vectorSize 10
#define stringSize 4

using namespace std;

class IComparable {
public:
    virtual bool isLessThan(IComparable* rhs) const = 0;
};

class IntWrapper: public IComparable {
public:
    IntWrapper(int initialValue = 0);
    int getValue();
    bool isLessThan(IComparable* rhs) const;

private:
    int storedValue;
};

class StringWrapper: public IComparable {
public:
    StringWrapper(string initialValue = 0);
    string getValue();
    bool isLessThan(IComparable* rhs) const;
private:
    string storedValue;
};

class sortingFunctions {
public:
    static vector<IComparable*> sorting(vector<IComparable*> input);
    static bool sortingVerifications(vector<IComparable*> input);
    static void print(vector<IComparable*> input);
};


#endif //PROJECT2_OO_COMPARISON_H
