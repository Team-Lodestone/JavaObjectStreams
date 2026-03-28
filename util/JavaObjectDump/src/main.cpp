/** @file main.cpp
*
 * @author Zero_DSRS_VX
 * @date 3/26/26
 *
 * @device mac-8
 *
 * @copyright Copyright (c) 2026 Team Lodestone
 * @license This project is licensed under the MIT license, see the LICENSE file for details.
 */

#include "JavaObject/stream/ObjectInputStream.h"

#include <iostream>
#include <fstream>

void print_help() {
    std::cout << "Copyright (c) 2026 Team Lodestone" << std::endl;
    std::cout << "This project is licensed under the terms of the MIT license." << std::endl;

    std::cout << "Options:" << std::endl;
    std::cout << "[input_file] (required)" << std::endl;
    std::cout << "[output file]" << std::endl;

    std::cout << "Example usage(s):" << std::endl;
    std::cout << "jobjdump JOSTestClass.obj" << std::endl;
    std::cout << std::endl;
    std::cout << "jobjdump JOSTestClass.obj JOSTestClass.txt" << std::endl;
}

int main(const int argc, char** argv) {
    if (argc == 0) {
        print_help();
    }

    const std::ifstream input_path(argv[0]);
    if (!input_path) {
        throw std::runtime_error(std::format("File does not exist at specified path: {}", argv[0]));
    }

    javaobject::stream::ObjectInputStream ois(input_path);
    auto obj = ois.readObject();

    return 0;
}