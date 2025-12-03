/**
 * @file shell.h
 * @brief Простейший командный интерпретатор ядра libreacronium.
 */

#ifndef KERNEL_SHELL_H
#define KERNEL_SHELL_H

/**
 * @brief Выполнить одну команду, введённую пользователем.
 *
 * @param cmd ASCIIZ-строка с командой (может быть NULL или пустой).
 */
void shell_execute(const char *cmd);

#endif /* KERNEL_SHELL_H */


