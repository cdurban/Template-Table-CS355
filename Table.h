/*
 * Chase Urban
 * Homework 1
 * COMPSCI 355-01
 * Due 9/15/2020
 */

#include <cstdlib>
#include <iostream>
using namespace std;

#ifndef HOMEWORK1URBAN_TABLE_H
#define HOMEWORK1URBAN_TABLE_H

template <class T>
class Table {
    public:
        /**
         * One-argument constructor for Table<T>, creates a two-dimensional pointer array with an equal number of
         *   rows and columns
         * @param rc the number of rows and columns
         */
        Table(int rc);

        /**
         * Two-argument constructor for Table<T>, creates a two-dimensional pointer array with an differing number of
         *   rows and columns
         * @param r number of rows
         * @param c number of columns
         */
        Table(int r, int c);

        /**
         * Copy constructor for Table<T>, deletes array from memory if sizes do not match, then copies all values from
         *   orig to the resultant table.
         * @param orig original table to be copied
         */
        Table(const Table& orig);

        /**
         * Overloaded assignment operator, sets the Table<T> equal to an other Table<T> passed on to it. Copies all
         *   values from orig to the new table.
         * @param orig
         */
        Table<T>& operator=(const Table& orig);

        /**
         * Destructor for Table<T>, deletes two-dimensional pointer array of type T.
         */
        ~Table();


        /**
         * Returns the number of rows in this Table<T>
         * @return rows, the number of rows in this Table<T>
         */
        int get_rows();

        /**
         * Returns the number of columns in this Table<T>
         * @return cols, the number of columns in this Table<T>
         */
        int get_cols();


        /**
         * Creates a new table, and copies the content of this Table<T>, followed by the contents of an other given
         *   Table<T>. Returns the new table.
         * @param other an other table to be appended below this table.
         * @return the new table, containing the rows of both tables.
         */
        Table<T> append_rows(Table<T> &other);

        /**
         * Creates a new table, and copies the content of this Table<T>, followed by the contents of an other given
         *   Table<T>. Returns the new table.
         * @param other an other table to be appended to the right of this table.
         * @return the new table, containing the columns of both tables.
         */
        Table<T> append_cols(Table<T> &other);


        /**
         * Overloaded function call operator with two parameters, returns a reference to the data of type T at the
         *   location in the table specified by the parameters r and c
         * @param r row value of the value to be returned
         * @param c column value of the value to be returned
         * @return A reference to a value of type T, at position r, c, in the Table<T>
         */
        T& operator()(int r, int c);

        /**
         * Overloaded function call operator with four parameters, returns a sub-table using the given coordinates of
         *   the first table. Returns a reference to a Table<T> containing the specified rows and columns of the
         *   original table.
         * @param sr Starting Row, first row to be copied
         * @param sc Starting Column, first column to be copied
         * @param er Ending Row, last row to be copied
         * @param ec Ending Column, last column to be copied
         * @return Reference to a Table<T> containing the values from sr, sc, to er, ec from the original Table<T>
         */
        Table<T>& operator()(int sr, int sc, int er, int ec);

        /**
         * Overloaded addition operator, creates a new Table<T> and inserts the values of the calling Table<T> after
         *   they are passed through a function f.
         * @param f a pointer to a function that takes a parameter of type T, and returns a value of type T.
         * @return A pointer of a Table<T> that contains the values of the original Table<T> passed through the
         *   function f
         */
        Table<T>& operator+(T (*f)(T))const;


        /**
         * Overloaded left shift operator to insert the Table<T> into a ostream for output.
         * @param out ostream, likely std::cout
         * @param orig Table<T> to be printed
         * @return ostream with Table<T> inserted
         */
        friend ostream& operator<<(ostream &out, const Table<T> &orig){
            int width = out.width();
            for (int i = 0; i < orig.rows; i++) {
                for (int j = 0; j < orig.cols; j++) {
                    out << std::setw(width) << orig.data[i][j] << " ";
                }
                out << endl;
            }
            return out;
        }

    private:

    int rows;   //number of rows in this Table<T>
    int cols;   //number of cols in this Table<T>
    T** data;   //T-type pointer 2-dimensional array, meant to hold table values.
};

#endif //HOMEWORK1URBAN_TABLE_H
