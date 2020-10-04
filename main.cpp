#include <iostream>
#include "Table.cpp"

using namespace std;

// fills table with random numbers in a specified range
void randomize(Table<int>&, int, int);

// fills table with a specified value
void fill(Table<int>&, int );

// returns the square of a number
int square(int);

// fills table with random strings of specified length consisting
// of uppercase letters of the alphabet
void randomize(Table<string>&, int);

// fills table with a specified string
void fill(Table<string>&, const char*);

// returns a string identical to input string except that uppercase
// letters are converted to lowercase
string to_lower_case(string);

int main() {
    // initialize table with random two-digit numbers
    const int ROWS = 5;
    const int COLS = 7;
    const int WIDTH = 4;
    Table<int> it(ROWS, COLS);
    randomize(it, 10, 99);
    cout << setw(WIDTH) << it << endl;

    // replace odd numbers in table with zero
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (it(i, j) % 2 == 1) {
                it(i, j) = 0;
            }
        }
    }
    cout << setw(WIDTH) << it << endl;

    // append 3 columns filled with -1
    Table<int> it2(ROWS, 3);
    fill(it2, -1);
    it = it.append_cols(it2);
    cout << setw(WIDTH) << it << endl;

    // append 2 rows filled with -2
    Table<int> it3(2, it.get_cols());
    fill(it3, -2);
    it = it.append_rows(it3);
    cout << setw(WIDTH) << it << endl;

    // extract a subtable
    it = it(3, 5, 5, 7);
    cout << setw(WIDTH) << it << endl;

    // square the entries in the table
    cout << setw(WIDTH) << it + square << endl;




    // initialize 5x5 table with random 3-letter strings
    Table<string> t1(5);
    randomize(t1, 3);
    cout << t1 << endl;

    // replace middle entry in table with spaces
    t1(2, 2) = "   ";
    cout << t1 << endl;

    // append 3 columns
    Table<string> t2(5, 3); // 5 rows to match t
    fill(t2, "(+)");
    t1 = t1.append_cols(t2); // now t has 8 columns
    cout << t1 << endl;

    // append 3 rows
    Table<string> t3(3, 8); // 8 columns to match t
    fill(t3, "(-)");
    t1 = t1.append_rows(t3);
    cout << t1 << endl;

    // extract 4x4 subtable
    t1 = t1(1, 1, 5, 5);
    cout << t1 << endl;
    cout << t1 + to_lower_case << endl;
    return 0;

    return 0;
}

// fills table with random numbers in [lo, hi].
void randomize(Table<int>& t, int lo, int hi) {
    for (int i = 0; i < t.get_rows(); i++) {
        for (int j = 0; j < t.get_cols(); j++) {
            t(i, j) = lo + rand() % (hi - lo + 1);
        }
    }
}

// fills table with val
void fill(Table<int>& t, int val) {
    for (int i = 0; i < t.get_rows(); i++) {
        for (int j = 0; j < t.get_cols(); j++) {
            t(i, j) = val;
        }
    }
}

int square(int k) {
    return k * k;
}

// fills table with random strings of specified length consisting
// of uppercase letters of the alphabet
void randomize(Table<string>& t, int length) {
    for (int i = 0; i < t.get_rows(); i++) {
        for (int j = 0; j < t.get_cols(); j++) {
            string s = "";
            for (int k = 0; k < length; k++) {
                int offset = rand() % 26;
                t(i, j) += (char) ('A' + offset);
            }
        }
    }
}

// fills table with a specified string
void fill(Table<string>& t, const char* ptr) {
    for (int i = 0; i < t.get_rows(); i++) {
        for (int j = 0; j < t.get_cols(); j++) {
            t(i, j) = ptr;
        }
    }
}

// returns a string identical to input string except that uppercase
// letters are converted to lowercase
string to_lower_case(string s) {
    string t;
    for (char const& c : s) {
        t += isupper(c) ? c + ('a' - 'A') : c;
    }
    return t;
}