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

            double getElement(int index) const {
                return elements[index];
            }

            void reduce(double reducer) {
                for (int i = 0; i < numberOfCols; ++i) {
                    elements[i] = elements[i] / reducer;
                }
                return;
            }

            void eliminate(double row) {
                // this will subtract each row by the given row, and continue in loop if row is given row
            }

            // might need a swap row

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
        
            void reduce() {
                // this is function where it will run the row reduce function but it needs to determine if leading value is 0 and stuff
            }
        
        private:
            int numberOfRows;
            int numberOfCols;
            std::vector<Row> matrix;
    };


    Matrix test (3, 4);
    test.createMatrix();
    test.printMatrix();
}
