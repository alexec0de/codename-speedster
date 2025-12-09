/**
 * @file shell.c
 * @brief Простейший командный интерпретатор ядра libreacronium.
 */

#include "shell.h"
#include "console.h"
#include "video/video.h"
#include "memory/memory.h"
#include "drivers/pit.h"

/* kernel_panic определён в kernel.c */
void kernel_panic(const char* msg);

/* Локальные утилиты работы со строками (без стандартной библиотеки) */
static int str_len(const char *s) {
    int n = 0;
    if (!s) return 0;
    while (s[n] != '\0') n++;
    return n;
}

static int str_eq(const char *a, const char *b) {
    int i = 0;
    if (!a || !b) return 0;
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i]) return 0;
        i++;
    }
    return a[i] == '\0' && b[i] == '\0';
}

static const char* str_skip_spaces(const char *s) {
    if (!s) return s;
    while (*s == ' ' || *s == '\t') {
        s++;
    }
    return s;
}

static void shell_print_help(void) {
    console_println("");
    console_println("libreacronium shell commands:");
    console_println("  help      - show this help");
    console_println("  clear     - clear screen");
    console_println("  meminfo   - show physical memory info");
    console_println("  heapinfo  - show kernel heap info");
    console_println("  timerinfo - show PIT timer info");
    console_println("  panic     - trigger kernel panic");
}

void shell_execute(const char *cmd) {
    cmd = str_skip_spaces(cmd);
    int len = str_len(cmd);
    if (len == 0) {
        /* пустой ввод — ничего не делаем */
        return;
    }

    if (str_eq(cmd, "help")) {
        shell_print_help();
    } else if (str_eq(cmd, "clear")) {
        clear_screen();
    } else if (str_eq(cmd, "meminfo")) {
        pmm_dump_info();
    } else if (str_eq(cmd, "heapinfo")) {
        heap_dump_info();
    } else if (str_eq(cmd, "timerinfo")) {
        pit_dump_info();
    } else if (str_eq(cmd, "panic")) {
        kernel_panic("Manual panic triggered from shell.\n");
    } else {
        console_print("Unknown command: ");
        console_print(cmd);
        console_println("");
        console_println("Type 'help' for list of commands.");
    }
}


