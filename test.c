#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

/* Declaration of your function */
int ft_printf(const char *s, ...);

int main(void)
{
    int ret_std;
    int ret_ft;
    char *null_str = NULL;
    int num = 42;

    printf("=======================================\n");
    printf("         FT_PRINTF MANDATORY TEST      \n");
    printf("=======================================\n\n");

    /* --- 1. Characters (%c) --- */
    printf("--- 1. Characters (%%c) ---\n");
    ret_std = printf("Standard: %c %c %c\n", 'a', 'Z', '0');
    ret_ft = ft_printf("Custom  : %c %c %c\n", 'a', 'Z', '0');
    printf("[Return] Std: %d | Ft: %d\n\n", ret_std, ret_ft);

    /* --- 2. Strings (%s) --- */
    printf("--- 2. Strings (%%s) ---\n");
    ret_std = printf("Standard: %s\n", "Hello, World!");
    ret_ft = ft_printf("Custom  : %s\n", "Hello, World!");
    printf("[Return] Std: %d | Ft: %d\n\n", ret_std, ret_ft);

    printf("--- 2.1 NULL String (%%s) ---\n");
    ret_std = printf("Standard: %s\n", null_str);
    ret_ft = ft_printf("Custom  : %s\n", null_str);
    printf("[Return] Std: %d | Ft: %d\n\n", ret_std, ret_ft);

    /* --- 3. Pointers (%p) --- */
    printf("--- 3. Pointers (%%p) ---\n");
    ret_std = printf("Standard: %p\n", &num);
    ret_ft = ft_printf("Custom  : %p\n", &num);
    printf("[Return] Std: %d | Ft: %d\n\n", ret_std, ret_ft);

    printf("--- 3.1 NULL Pointer (%%p) ---\n");
    ret_std = printf("Standard: %p\n", NULL);
    ret_ft = ft_printf("Custom  : %p\n", NULL);
    printf("[Return] Std: %d | Ft: %d\n\n", ret_std, ret_ft);
    /* --- 4. Base 10 Integers (%d and %i) --- */
    printf("--- 4. Integers (%%d & %%i) ---\n");
    ret_std = printf("Standard: %d | %i | %d | %i\n", 0, -42, INT_MAX, INT_MIN);
    ret_ft = ft_printf("Custom  : %d | %i | %d | %i\n", 0, -42, INT_MAX, INT_MIN);
    printf("[Return] Std: %d | Ft: %d\n\n", ret_std, ret_ft);

    /* --- 5. Unsigned Integers (%u) --- */
    printf("--- 5. Unsigned (%%u) ---\n");
    ret_std = printf("Standard: %u | %u | %u\n", 0, 4294967295U, -1);
    ret_ft = ft_printf("Custom  : %u | %u | %u\n", 0, 4294967295U, -1);
    printf("[Return] Std: %d | Ft: %d\n\n", ret_std, ret_ft);

    /* --- 6. Hexadecimal (%x and %X) --- */
    printf("--- 6. Hexadecimal (%%x & %%X) ---\n");
    ret_std = printf("Standard: %x | %X | %x | %X\n", 0, 0, 255, 255);
    ret_ft = ft_printf("Custom  : %x | %X | %x | %X\n", 0, 0, 255, 255);
    printf("[Return] Std: %d | Ft: %d\n\n", ret_std, ret_ft);

    /* --- 7. Percent Sign (%%) --- */
    printf("--- 7. Percent Sign (%%%%) ---\n");
    ret_std = printf("Standard: 100%%\n");
    ret_ft = ft_printf("Custom  : 100%%\n");
    printf("[Return] Std: %d | Ft: %d\n\n", ret_std, ret_ft);

    /* --- 8. Mixed Sentence --- */
    printf("--- 8. Mixed Sentence ---\n");
    ret_std = printf("Standard: %s is %d years old, pointer %p, hex %X, 100%% ready.\n", "Soon Li", 25, &num, 255);
    ret_ft = ft_printf("Custom  : %s is %d years old, pointer %p, hex %X, 100%% ready.\n", "Soon Li", 25, &num, 255);
    printf("[Return] Std: %d | Ft: %d\n\n", ret_std, ret_ft);

    return (0);
}
