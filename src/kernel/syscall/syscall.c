/**
 * @file syscall.c
 * @brief Реализация системы системных вызовов
 */

#include "syscall.h"
#include "../video/video.h"
#include "../memory/memory.h"

/* Таблица обработчиков системных вызовов */
static syscall_handler_t syscall_table[MAX_SYSCALLS];

/**
 * @brief Системный вызов exit - завершение процесса
 * @param regs Регистры: ebx = exit_code
 */
static uint32_t sys_exit(registers_t *regs) {
    uint32_t exit_code = regs->ebx; /* Параметр передается через ebx */
    print_string("\nProcess exited with code: ");
    print_dec(exit_code);
    print_string("\n");
    /* В будущем здесь будет реальное завершение процесса */
    return 0;
}

/**
 * @brief Системный вызов write - запись в файловый дескриптор
 * @param regs Регистры: ebx = fd, ecx = buf, edx = count
 */
static uint32_t sys_write(registers_t *regs) {
    uint32_t fd = regs->ebx;      /* Файловый дескриптор */
    char *buf = (char*)regs->ecx; /* Буфер данных */
    uint32_t count = regs->edx;   /* Количество байт */
    
    if (fd == 1 || fd == 2) { /* stdout или stderr */
        for (uint32_t i = 0; i < count && buf[i] != '\0'; i++) {
            char str[2] = {buf[i], '\0'};
            print_string(str);
        }
        return count;
    }
    return 0;
}

/**
 * @brief Системный вызов read - чтение из файлового дескриптора
 */
static uint32_t sys_read(registers_t *regs) {
    /* Пока не реализовано - будет работать с клавиатурой */
    (void)regs;
    return 0;
}

/**
 * @brief Инициализация подсистемы системных вызовов
 */
void syscall_init(void) {
    /* Очищаем таблицу системных вызовов */
    memory_set(syscall_table, 0, sizeof(syscall_table));
    
    /* Регистрируем базовые системные вызовы */
    syscall_register(SYS_EXIT, sys_exit);
    syscall_register(SYS_WRITE, sys_write);
    syscall_register(SYS_READ, sys_read);
    
    print_string("Syscall subsystem initialized\n");
}

/**
 * @brief Регистрация обработчика системного вызова
 */
void syscall_register(uint32_t num, syscall_handler_t handler) {
    if (num < MAX_SYSCALLS) {
        syscall_table[num] = handler;
    }
}

/**
 * @brief Обработчик системного вызова
 */
void syscall_handler(registers_t *regs) {
    uint32_t syscall_num = regs->eax;
    
    if (syscall_num >= MAX_SYSCALLS || syscall_table[syscall_num] == NULL) {
        /* Неизвестный системный вызов */
        regs->eax = -1; /* Возвращаем ошибку */
        return;
    }
    
    /* Вызываем зарегистрированный обработчик */
    regs->eax = syscall_table[syscall_num](regs);
}

