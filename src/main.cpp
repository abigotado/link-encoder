#include "url_encoder.hpp"
#include <iostream>
#include <string>
#include <limits>

void printMenu() {
    std::cout << "\nURL Encoder/Decoder Menu:\n"
              << "1. Encode string\n"
              << "2. Decode string\n"
              << "3. Exit\n"
              << "Enter your choice (1-3): ";
}

void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    try {
        while (true) {
            printMenu();
            int choice;
            std::cin >> choice;
            clearInputBuffer();

            if (choice == 3) {
                break;
            }

            std::string input;
            std::cout << "Enter the string: ";
            std::getline(std::cin, input);

            try {
                switch (choice) {
                    case 1: {
                        std::string encoded = UrlEncoder::encode(input);
                        std::cout << "Encoded result: " << encoded << std::endl;
                        break;
                    }
                    case 2: {
                        std::string decoded = UrlEncoder::decode(input);
                        std::cout << "Decoded result: " << decoded << std::endl;
                        break;
                    }
                    default:
                        std::cout << "Invalid choice. Please try again.\n";
                }
            } catch (const std::exception& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "Fatal error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
} 