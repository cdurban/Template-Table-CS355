/*
 * Chase Urban
 * Homework 1
 * COMPSCI 355-01
 * Due 9/15/2020
 */


#include <iomanip>
#include <cassert>
#include "Table.h"

template<class T>
Table<T>::Table(int rc) {
    rows = cols = rc;
    data = new T*[rows];
    for (int i = 0; i < rows; i++) {
        data[i] = new T[cols];
    }
}

template<class T>
Table<T>::Table(int r, int c) {
    rows = r;
    cols = c;
    data = new T *[rows];
    for (int i = 0; i < rows; i++) {
        data[i] = new T[cols];
    }
}

template<class T>
Table<T>::Table(const Table &orig) {
    rows = orig.rows;
    cols = orig.cols;
    data = new T*[rows];
    for (int i = 0; i < rows; i++){
        data[i] = new T[cols];
        for (int j = 0; j < cols; j++)
            data[i][j] = orig.data[i][j];
    }
}

template<class T>
Table<T>& Table<T>::operator=(const Table &orig) {
    for (int i = 0; i < rows; i++)
        delete[] data[i];
    delete[] data;
    rows = orig.rows;
    cols = orig.cols;
    data = new T*[rows];
    for (int i = 0; i < rows; i++){
        data[i] = new T[cols];
        for (int j = 0; j < cols; j++)
            data[i][j] = orig.data[i][j];
    }
    return *this;
}

template<class T>
Table<T>::~Table() {
    for (int i = 0; i < rows; i++)
        delete[] data[i];
    delete[] data;
}

template<class T>
int Table<T>::get_rows() {
    return rows;
}

template<class T>
int Table<T>::get_cols() {
    return cols;
}

template<class T>
Table<T> Table<T>::append_rows(Table<T> &other) {
    assert(cols == other.get_cols());
    Table<T> newTable = Table<T>(rows + other.get_rows(), cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            newTable(i,j) = data[i][j];
        }
    }
    for(int i = 0; i < other.get_rows(); i++){
        for (int j = 0; j < cols; j++) {
            newTable(rows + i, j) = other.data[i][j];
        }
    }
    return newTable;
}

template<class T>
Table<T> Table<T>::append_cols(Table<T> &other) {
    assert(rows == other.get_rows());
    Table<T> newTable = Table<T>(rows, cols + other.get_cols());
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            newTable(i, j) = data[i][j];
        }
    }
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < other.get_cols(); j++){
            newTable(i, cols + j) = other.data[i][j];
        }
    }
    return newTable;
}

template<class T>
T& Table<T>::operator()(int r, int c) {
    return data[r][c];
}

template<class T>
Table<T> &Table<T>::operator()(int sr, int sc, int er, int ec) {
    Table<T> *newTab = new Table<T>((er-sr+1), (ec-sc+1));
    for (int i = 0; i < er - sr + 1; i++) {
        for (int j = 0; j < ec - sc + 1; j++) {
            newTab->operator()(i,j) = data[i+sr][j+sc];
        }
    }
    return *newTab;
}

template<class T>
Table<T>& Table<T>::operator+(T (*f)(T)) const {
    Table<T> *newTab = new Table<T>(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            newTab->data[i][j] = f(data[i][j]);
        }
    }
    return *newTab;
}
