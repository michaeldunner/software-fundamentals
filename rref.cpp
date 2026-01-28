#include <iostream>
#include <vector>

int main() {
    class Row {
       public:
        Row(int cols) {
            numberOfCols = cols;
        }

        void createRow() {
            for (int column = 0; column < numberOfCols; ++column) {
                double value;
                std::cin >> value;
                elements.push_back(value);
            }
        }

        void setElement(int index, double value) {
            if (value == -0) {
                value = 0;
            }
            elements[index] = value;
        }

        double getElement(int index) {
            if (elements[index] == -0) {
                elements[index] = 0;
            }
            return elements[index];
        }

        int getLeadingColumn() {
            for (int column = 0; column < numberOfCols; ++column) {
                if (elements[column] != 0) {
                    return column;
                }
            }
            return numberOfCols;  // all zeros
        }

        double getLeadingValue() {
            int leadingColumn = getLeadingColumn();
            return elements[leadingColumn];
        }

        void reduce(double reducer) {
            for (int i = 0; i < numberOfCols; ++i) {
                elements[i] = elements[i] / reducer;
            }
            return;
        }

       private:
        int numberOfCols;
        std::vector<double> elements;
    };

    class Matrix {
       public:
        Matrix(int rows, int cols) {
            numberOfRows = rows;
            numberOfCols = cols;
        }

        void createMatrix() {
            for (int i = 0; i < numberOfRows; ++i) {
                Row row(numberOfCols);
                row.createRow();
                matrix.push_back(row);
            }
        }

        void printMatrix() {
            for (int row = 0; row < numberOfRows; ++row) {
                std::cout << "[\t";
                for (int column = 0; column < numberOfCols; ++column) {
                    std::cout << matrix[row].getElement(column) << "\t";
                }
                std::cout << "]" << std::endl;
            }
        }

        void reduce() {
            // firstly need to assume all columns to the left of it are reduced
            // then need to know what row the previous leading value is on
            // then move 1 row down in tghat column see if theres a value
            // if there is reduce and eliminate
            // if not keep checking beneath until there is and swap
            for (int column = reducedColumns; column < numberOfCols; ++column) {
                bool topRow = true;
                int currentRow = reducedRows;
                for (int row = reducedRows; row < numberOfRows; ++row) {
                    if (topRow) {
                        if (matrix[row].getElement(column) != 0) {
                            // reduce and then eliminate the rest of the rows
                            matrix[row].reduce(matrix[row].getLeadingValue());
                            eliminate(row);
                            reducedRows++;
                            reducedColumns++;
                            break;
                        } else {
                            // std::cout << "start of row swap";
                            topRow = false;
                            currentRow = row;
                        }
                    }
                    // non top row
                    else {
                        // non zero
                        if (matrix[row].getElement(column) != 0) {
                            // swap rows reset the for loop variable to
                            // currentRow
                            // std::cout << "swapping row";
                            Row temporaryRow = matrix[currentRow];
                            matrix[currentRow] = matrix[row];
                            matrix[row] = temporaryRow;
                            row = currentRow -
                                  1;  // -1 because of for loop increment
                                  topRow = true;
                        } else {
                            // try further down unless at the end of rows
                            // no values were non zero go to next column
                            // std::cout << "no swap possible";
                            // should only break if at the end of the rows
                            
                        }
                    }
                }
            }
        }

        void eliminate(int reducedRow) {
            // eliminate has to go here because it needs to access multiple rows
            // it needs to dtermine whether or not to continue based on if it is
            // the row reducing the others if it is it will skip if it isn't it
            // will subtract the reducing row multiplied by the leading value of
            // the current row this will subtract each row by the given row, and
            // continue in loop if row is given row

            // this is the leading column of row being reduced
            // the row being reduced will be determined in a different method
            int index = matrix[reducedRow].getLeadingColumn();
            for (int row = 0; row < numberOfRows; ++row) {
                if (row == reducedRow) {
                    continue;
                } else {
                    double leadingValue = matrix[row].getElement(index);
                    for (int column = 0; column < numberOfCols; ++column) {
                        double reducedValue =
                            matrix[reducedRow].getElement(column) *
                            leadingValue;
                        double newValue =
                            matrix[row].getElement(column) - reducedValue;
                        matrix[row].setElement(column, newValue);
                    }
                }
            }
        }

       private:
        int numberOfRows;
        int numberOfCols;
        int reducedRows = 0;
        int reducedColumns = 0;
        std::vector<Row> matrix;
    };

    Matrix test(5, 6);
    test.createMatrix();
    test.printMatrix();
    std::cout << std::endl;
    test.reduce();
    test.printMatrix();
}
