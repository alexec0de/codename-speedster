/**
 * @file console.h
 * @brief Простая консольная подсистема libreacronium.
 *
 * Оборачивает низкоуровневые функции видео и клавиатуры
 * в более удобный интерфейс для работы с консолью.
 */

#ifndef KERNEL_CONSOLE_H
#define KERNEL_CONSOLE_H

#include <stdint.h>

/**
 * @brief Инициализация консоли.
 *
 * Очищает экран и подготавливает вывод.
 */
void console_init(void);

/**
 * @brief Вывод строки без перевода строки.
 */
void console_print(const char *str);

/**
 * @brief Вывод строки с переводом строки в конце.
 */
void console_println(const char *str);

/**
 * @brief Вывод приглашения командной строки.
 *
 * По умолчанию использует вид `$ `.
 */
void console_prompt(void);

/**
 * @brief Чтение строки из консоли до нажатия Enter.
 *
 * @param max_length Максимальная длина строки (включая завершающий 0).
 * @return Указатель на выделенную в куче строку или NULL при ошибке.
 *
 * @note Освобождение делает вызывающая сторона через kfree().
 */
char* console_readline(uint32_t max_length);

#endif /* KERNEL_CONSOLE_H */


