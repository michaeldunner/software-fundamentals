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
            return numberOfCols;
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
            for (int column = reducedColumns; column < numberOfCols; ++column) {
                bool topRow = true;
                int currentRow = reducedRows;
                for (int row = reducedRows; row < numberOfRows; ++row) {
                    if (topRow) {
                        if (matrix[row].getElement(column) != 0) {
                            matrix[row].reduce(matrix[row].getLeadingValue());
                            eliminate(row);
                            reducedRows++;
                            reducedColumns++;
                            break;
                        } else {
                            topRow = false;
                            currentRow = row;
                        }
                    } else {
                        if (matrix[row].getElement(column) != 0) {
                            Row temporaryRow = matrix[currentRow];
                            matrix[currentRow] = matrix[row];
                            matrix[row] = temporaryRow;
                            row = currentRow - 1;
                            topRow = true;
                        }
                    }
                }
            }
        }

        void eliminate(int reducedRow) {
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
