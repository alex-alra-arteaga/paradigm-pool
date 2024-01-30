/*
** EPITECH PROJECT, 2024
** test.c
** File description:
** Paradigm Seminar, ex02
*/

#include <iostream>
#include <sstream>
#include <iomanip>

int main(void)
{
    std::string line;
    // while there are lines
    while (std::getline(std::cin, line)) {
        // instantiate a stringstream with the line
        std::stringstream stream(line);
        double temperature;
        std::string scale;
        // if the line is not a double followed by a string
        // sets the value of temperature and scale
        if (!(stream >> temperature >> scale)) {
            continue;
        }
        // creates a mask for cout, set the precision to 3 digits, and the width to 16, fixed is used to display the trailing zeros
        // comes from the iomanip library to format the output
        std::cout << std::fixed << std::setprecision(3) << std::setw(16);

        if (scale == "Celsius") {
            double fahrenheit = 9.0 / 5.0 * temperature + 32;
            std::cout << fahrenheit << " Fahrenheit" << std::endl;
        } else if (scale == "Fahrenheit") {
            double celsius = 5.0 / 9.0 * (temperature - 32);
            std::cout << celsius << " Celsius" << std::endl;
        }
    }

    return 0;
}
