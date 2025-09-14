#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    int ret1, ret2;

    // Teste de caracteres
    ret1 = ft_printf("Meu char: %c\n", 'A');
    ret2 = printf("Meu char: %c\n", 'A');
    printf("ft_printf retornou %d | printf retornou %d\n\n", ret1, ret2);

    // Teste de strings
    ret1 = ft_printf("String: %s\n", "Hello 42!");
    ret2 = printf("String: %s\n", "Hello 42!");
    printf("ft_printf retornou %d | printf retornou %d\n\n", ret1, ret2);

	// Teste de ponteiros
	int x = 42;
    ret1 = ft_printf("Endereco de x: %p\n", &x);
    ret2 = printf("Endereco de x: %p\n", &x);
    printf("ft_printf retornou %d | printf retornou %d\n\n", ret1, ret2);

    // Teste de inteiros
    ret1 = ft_printf("Inteiro: %d %i\n", 42, -42);
    ret2 = printf("Inteiro: %d %i\n", 42, -42);
    printf("ft_printf retornou %d | printf retornou %d\n\n", ret1, ret2);

    // Teste de unsigned
    ret1 = ft_printf("Unsigned: %u\n", 3000000000u);
    ret2 = printf("Unsigned: %u\n", 3000000000u);
    printf("ft_printf retornou %d | printf retornou %d\n\n", ret1, ret2);

    // Teste de hexadecimal
    ret1 = ft_printf("Hex: %x | %X\n", 3735928559u, 3735928559u);
    ret2 = printf("Hex: %x | %X\n", 3735928559u, 3735928559u);
    printf("ft_printf retornou %d | printf retornou %d\n\n", ret1, ret2);

    // Teste de percentual
    ret1 = ft_printf("Percentual: %%\n");
    ret2 = printf("Percentual: %%\n");
    printf("ft_printf retornou %d | printf retornou %d\n\n", ret1, ret2);

    // Teste de string NULL
	char *null_str = NULL;
	ret1 = ft_printf("String NULL: %s\n", null_str);
	ret2 = printf("String NULL: %s\n", null_str);

    return (0);
}
