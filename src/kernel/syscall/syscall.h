/**
 * @file syscall.h
 * @brief Системные вызовы ядра - интерфейс между userspace и kernelspace
 */

#ifndef SYSCALL_H
#define SYSCALL_H

#include <stdint.h>
#include "../idt/exceptions.h"

/* Номера системных вызовов */
#define SYS_EXIT    1
#define SYS_WRITE   2
#define SYS_READ    3
#define SYS_OPEN    4
#define SYS_CLOSE   5

/* Максимальное количество системных вызовов */
#define MAX_SYSCALLS 32

/**
 * @brief Тип функции системного вызова
 * @param regs Регистры процессора с параметрами
 * @return Результат системного вызова
 */
typedef uint32_t (*syscall_handler_t)(registers_t *regs);

/**
 * @brief Инициализация подсистемы системных вызовов
 */
void syscall_init(void);

/**
 * @brief Регистрация обработчика системного вызова
 * @param num Номер системного вызова
 * @param handler Функция-обработчик
 */
void syscall_register(uint32_t num, syscall_handler_t handler);

/**
 * @brief Обработчик системного вызова (вызывается из ассемблерной заглушки)
 * @param regs Регистры процессора
 */
void syscall_handler(registers_t *regs);

#endif /* SYSCALL_H */

