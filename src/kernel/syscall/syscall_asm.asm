;;
;; @file syscall_asm.asm
;; @brief Ассемблерная заглушка для обработки системных вызовов (int 0x80)
;;

[bits 32]

global syscall_handler_asm

extern syscall_handler

;;
;; @brief Обработчик прерывания системного вызова (int 0x80)
;;

syscall_handler_asm:
    ; Сохраняем все регистры (как в exception_handlers.asm)
    pusha
    
    ; Сохраняем сегмент данных
    mov ax, ds
    push eax
    
    ; Загружаем сегмент данных ядра
    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    
    ; Передаем указатель на стек (где лежат регистры) в C-функцию
    push esp
    call syscall_handler
    add esp, 4  ; Очищаем стек от параметра
    
    ; Восстанавливаем сегмент данных
    pop eax
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    
    ; Восстанавливаем регистры
    popa
    
    ; Возврат из прерывания (возвращает управление в userspace)
    iret

