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

        double getElement(int index) {
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
            int leadingCol = getLeadingColumn();
            return elements[leadingCol];
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
                for (int column = 0; column < numberOfCols; ++column) {
                    std::cout << matrix[row].getElement(column) << "\t";
                }
                std::cout << std::endl << std::endl;
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
                    for (int col = 0; col < numberOfCols; ++col) {
                        double reducedValue =
                            matrix[reducedRow].getElement(col) * leadingValue;
                        matrix[row].getElement(col) -= reducedValue;
                    }
                }
            }
        }
    

    void
    reduce() {
        // this is function where it will run the row reduce function but it
        // needs to determine if leading value is 0 and stuff
    }

   private:
    int numberOfRows;
    int numberOfCols;
    std::vector<Row> matrix;
};

Matrix test(3, 4);
test.createMatrix();
test.printMatrix();
}
