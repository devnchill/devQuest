section .data
    msg db "Hello, world!", 0xA  ; message + newline
    len equ $ - msg              ; length of the message

section .text
    global _start

_start:
    mov rax, 1       ; syscall: write
    mov rdi, 1       ; file descriptor: stdout
    mov rsi, msg     ; address of the message
    mov rdx, len     ; length of the message
    syscall

    mov rax, 60      ; syscall: exit
    xor rdi, rdi     ; exit code 0
    syscall
