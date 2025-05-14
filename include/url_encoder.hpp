#pragma once

#include <string>
#include <stdexcept>

/**
 * @brief Класс для кодирования и декодирования URL
 * 
 * Предоставляет статические методы для преобразования строк в URL-формат
 * и обратно. Поддерживает работу со строками std::string и C-строками.
 */
class UrlEncoder {
public:
    /**
     * @brief Кодирует строку в URL-формат
     * @param input Исходная строка
     * @return Закодированная строка
     */
    static std::string encode(const std::string& input);

    /**
     * @brief Кодирует C-строку в URL-формат
     * @param input Исходная C-строка
     * @return Закодированная строка
     * @throw std::invalid_argument если input == nullptr
     */
    static std::string encode(const char* input);

    /**
     * @brief Кодирует массив символов в URL-формат
     * @param input Исходный массив символов
     * @param length Длина массива
     * @return Закодированная строка
     * @throw std::invalid_argument если input == nullptr
     */
    static std::string encode(const char* input, size_t length);

    /**
     * @brief Декодирует URL-строку
     * @param input Закодированная строка
     * @return Декодированная строка
     */
    static std::string decode(const std::string& input);

    /**
     * @brief Декодирует URL-строку из C-строки
     * @param input Закодированная C-строка
     * @return Декодированная строка
     * @throw std::invalid_argument если input == nullptr
     */
    static std::string decode(const char* input);

    /**
     * @brief Декодирует URL-строку из массива символов
     * @param input Закодированный массив символов
     * @param length Длина массива
     * @return Декодированная строка
     * @throw std::invalid_argument если input == nullptr
     * @throw std::runtime_error при некорректном кодировании
     */
    static std::string decode(const char* input, size_t length);

private:
    /**
     * @brief Проверяет, является ли символ безопасным для URL
     * @param c Проверяемый символ
     * @return true если символ безопасен (буква, цифра, - или _)
     */
    static bool isUrlSafe(char c);

    /**
     * @brief Преобразует шестнадцатеричное представление в символ
     * @param hex Указатель на два шестнадцатеричных символа
     * @return Декодированный символ
     */
    static char hexToChar(const char* hex);

    /**
     * @brief Преобразует символ в его URL-кодированное представление (%XX)
     * @param c Исходный символ
     * @return Строка с закодированным символом
     */
    static std::string charToHex(char c);
}; 