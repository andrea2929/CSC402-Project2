
#include "OO_Comparison.h"
#include "Template_Comparison.h"

const char alphanum[] = "abcdefghijklmnopqrstuvwxyz";

int main() {

    //OO Comparison
    sortingFunctions f; // I just didn't want to include all those functions in this file
    vector<IComparable*> intVector(vectorSize);
    vector<IComparable*> stringVector(vectorSize);

    for (int x = 0; x < vectorSize; x++) {
        IntWrapper *newInt = new IntWrapper(rand() % 1001);
        intVector[x] = newInt;

        string str;
        for (int y = 0; y < stringSize; y++) {
            str+=alphanum[rand()%26];
        }

        StringWrapper *newString = new StringWrapper(str);
        stringVector[x] = newString;
    }

    cout << "UNSORTED INTVECTOR" << endl;
    f.print(intVector);
    cout << "SORTED INTVECTOR" << endl;
    intVector = f.sorting(intVector);
    f.print(intVector);
    cout << "UNSORTED STRINGVECTOR" << endl;
    f.print(stringVector);
    cout << "SORTED STRINGVECTOR" << endl;
    stringVector = f.sorting(stringVector);
    f.print(stringVector);


    cout << "TEMPLATE COMPARISONS" << endl;
    //Template Comparison
    templateSort<int> intSort;
    vector<Comparable<int> *> intTemplateVector(vectorSize);
    templateSort<string> stringSort;
    vector<Comparable<string> *> stringTemplateVector(vectorSize);

    for (int x = 0; x < vectorSize; x++) {
        Comparable<int> *newInt = new Comparable<int>(rand() % 1001);
        intTemplateVector[x] = newInt;

        string str;
        for (int y = 0; y < stringSize; y++) {
            str+=alphanum[rand()%26];
        }

        Comparable<string> *newString = new Comparable<string>(str);
        stringTemplateVector[x] = newString;
    }

    cout << "UNSORTED INTVECTOR" << endl;
    intSort.print(intTemplateVector);
    cout << "SORTED INTVECTOR" << endl;
    intTemplateVector = intSort.tSort(intTemplateVector);
    intSort.print(intTemplateVector);

    cout << "UNSORTED STRINGVECTOR" << endl;
    stringSort.print(stringTemplateVector);
    cout << "SORTED STRINGVECTOR" << endl;
    stringTemplateVector = stringSort.tSort(stringTemplateVector);
    stringSort.print(stringTemplateVector);
}