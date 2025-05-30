# URL Encoder/Decoder

Простая утилита на C++23 для кодирования и декодирования строк в формате URL.

## Что умеет

- Кодирует любые строки в URL-формат (заменяет все, кроме латиницы, цифр, `-` и `_` на `%XX`)
- Декодирует обратно в человекочитаемый вид
- Поддерживает три варианта вызова: `std::string`, `const char*`, `const char*, size_t`
- Удобное интерактивное меню в терминале
- Безопасная работа с памятью, обработка ошибок через исключения

## Как собрать

```sh
mkdir build
cd build
cmake ..
make
```

## Как запустить

```sh
./link-encoder
```

## Пример

```
Меню URL Кодировщика/Декодировщика:
1. Закодировать строку
2. Декодировать строку
3. Выход
Введите ваш выбор (1-3): 1
Введите строку: abc ABC&123
Закодированный результат: abc%20ABC%26123

Меню URL Кодировщика/Декодировщика:
1. Закодировать строку
2. Декодировать строку
3. Выход
Введите ваш выбор (1-3): 2
Введите строку: abc%20ABC%26123
Декодированный результат: abc ABC&123
```

## Требования

- C++23
- CMake 3.10+ 