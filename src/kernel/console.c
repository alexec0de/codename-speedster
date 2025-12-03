/**
 * @file console.c
 * @brief Простая консольная подсистема libreacronium.
 */

#include "console.h"
#include "video/video.h"
#include "drivers/keyboard.h"

void console_init(void) {
    clear_screen();
}

void console_print(const char *str) {
    if (!str) {
        return;
    }
    print_string(str);
}

void console_println(const char *str) {
    if (str) {
        print_string(str);
    }
    print_string("\n");
}

void console_prompt(void) {
    print_string("$ ");
}

char* console_readline(uint32_t max_length) {
    return read_line(max_length);
}


