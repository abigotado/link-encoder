#include "url_encoder/url_encoder.hpp"
#include <iostream>
#include <string>
#include <limits>

/**
 * @brief Выводит меню программы
 */
void printMenu() {
    std::cout << "\nМеню URL Кодировщика/Декодировщика:\n"
              << "1. Закодировать строку\n"
              << "2. Декодировать строку\n"
              << "3. Выход\n"
              << "Введите ваш выбор (1-3): ";
}

/**
 * @brief Очищает буфер ввода
 */
void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

/**
 * @brief Точка входа в программу
 * @return 0 при успешном завершении, 1 при ошибке
 */
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
            std::cout << "Введите строку: ";
            std::getline(std::cin, input);

            try {
                switch (choice) {
                    case 1: {
                        std::string encoded = UrlEncoder::encode(input);
                        std::cout << "Закодированный результат: " << encoded << std::endl;
                        break;
                    }
                    case 2: {
                        std::string decoded = UrlEncoder::decode(input);
                        std::cout << "Декодированный результат: " << decoded << std::endl;
                        break;
                    }
                    default:
                        std::cout << "Неверный выбор. Пожалуйста, попробуйте снова.\n";
                }
            } catch (const std::exception& e) {
                std::cerr << "Ошибка: " << e.what() << std::endl;
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "Критическая ошибка: " << e.what() << std::endl;
        return 1;
    }

    return 0;
} 