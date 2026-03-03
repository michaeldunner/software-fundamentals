#include <array>
#include <cstdlib>
#include <ctime>
#include <iostream>

int sumArray(std::array<int, 20> testArray, size_t size);

void stringReverse(std::string testString, int startingSubscript);

int recursiveMinimum(std::array<size_t, 20> testArray, int startingSubscript,
                     int endingSubscript);

int main() {
    // 1
    // int integers[20];
    // int number;
    // bool duplicate;
    // int differentNumbers = 0;
    // std::cout << "Enter 20 integers: ";
    // for (int i = 0; i < 20; ++i) {
    //     while (true) {
    //         std::cin >> number;
    //         if (number >= 10 && number <= 100) {
    //             break;
    //         }
    //         std::cout << "Invalid input. Please enter an integer between 10 "
    //                      "and 100: ";
    //     }
    //     duplicate = false;
    //     for (int j = 0; j < differentNumbers; ++j) {
    //         if (integers[j] == number) {
    //             duplicate = true;
    //             break;
    //         }
    //     }
    //     if (!duplicate) {
    //         integers[differentNumbers] = number;
    //         differentNumbers++;
    //     }
    // }
    // for (int i = 0; i < differentNumbers; ++i) {
    //     std::cout << integers[i] << " ";
    // }
    // std::cout << std::endl;

    // 2
    std::srand(std::time(nullptr));
    int results[13] = {0};
    for (int i = 1; i < 36000; ++i) {
        int roll1 = std::rand() % 6 + 1;
        int roll2 = std::rand() % 6 + 1;
        results[roll1 + roll2]++;
    }
    std::cout << "Sum\tFrequency\tPercentage" << std::endl;
    for (int i = 2; i <= 12; ++i) {
        std::cout << i << "\t" << results[i] << "\t"
                  << (double)results[i] / 36000 * 100 << "%" << std::endl;
    }

    // 3
    const size_t arraySize{20};
    std::array<int, arraySize> a{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    std::cout << "Sum of array: " << sumArray(a, arraySize) << std::endl;

    // 4
    std::array<std::array<double, 4>, 5> sales{};
    int salesperson, product;
    double amount;
    std::cout << "Enter a slip from the last month. Enter a salesperson from 1 "
                 "to 4, a product from 1-5, and an amount. Enter 0 for "
                 "saleperson to quit: ";
    while (std::cin >> salesperson && salesperson != 0) {
        std::cin >> product >> amount;
        sales[product - 1][salesperson - 1] += amount;
        std::cout << "Enter a slip from the last month. Enter a salesperson "
                     "from 1 to 4, a product from 1-5, and an amount. Enter 0 "
                     "for saleperson to quit: ";
    }
    std::cout
        << "\tSalesperson 1\tSalesperson 2\tSalesperson 3\tSalesperson 4\tTotal"
        << std::endl;
    for (int product = 0; product < 5; ++product) {
        std::cout << "Product " << product + 1 << "\t";
        double total = 0;
        for (int salesperson = 0; salesperson < 4; ++salesperson) {
            std::cout << sales[product][salesperson] << "\t\t";
            total += sales[product][salesperson];
        }
        std::cout << total << std::endl;
    }
    std::cout << "Total\t";
    double grandTotal = 0;
    for (int salesperson = 0; salesperson < 4; ++salesperson) {
        double total = 0;
        for (int product = 0; product < 5; ++product) {
            total += sales[product][salesperson];
        }
        std::cout << total << "\t\t";
        grandTotal += total;
    }
    std::cout << grandTotal << std::endl;

    // 5
    std::array<int, 1000> primes{};
    for (int i = 1; i < 1000; ++i) {
        primes[i] = 1;
    }
    for (int i = 2; i < 1000; ++i) {
        if (primes[i]) {
            for (int j = i * i; j < 1000; j += i) {
                primes[j] = 0;
            }
        }
    }
    std::cout << "Prime numbers less than 1000: ";
    for (int i = 2; i < 1000; ++i) {
        if (primes[i]) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;

    // 6
    std::string testString;
    std::cout << "Enter a string: ";
    std::getline(std::cin, testString);
    std::cout << "Reversed string: ";
    stringReverse(testString, 0);
    std::cout << std::endl;

    // 7
    std::array<size_t, 20> testArray{5,  3,  8,  1,  4,  7,  2,  6,  9,  7,
                                     15, 13, 18, 11, 14, 17, 12, 16, 19, 10};
    std::cout << "Minimum value in the array: "
              << recursiveMinimum(testArray, 0, testArray.size() - 1)
              << std::endl;
}

int sumArray(std::array<int, 20> testArray, size_t size) {
    if (size == 0) {
        return 0;
    } else {
        return sumArray(testArray, size - 1) + testArray[size - 1];
    }
}

void stringReverse(std::string testString, int startingSubscript) {
    if (startingSubscript >= testString.length()) {
        return;
    } else {
        stringReverse(testString, startingSubscript + 1);
        std::cout << testString[startingSubscript];
        return;
    }
}

int recursiveMinimum(std::array<size_t, 20> testArray, int startingSubscript,
                     int endingSubscript) {
    if (startingSubscript == endingSubscript) {
        return testArray[startingSubscript];
    } else {
        int minimumOfRest =
            recursiveMinimum(testArray, startingSubscript + 1, endingSubscript);

        if (minimumOfRest < testArray[startingSubscript]) {
            return minimumOfRest;
        } else {
            return testArray[startingSubscript];
        }
    }
}