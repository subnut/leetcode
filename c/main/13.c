#include "debug.h"
#include "src/13.c"

int main(void) {
    const char *str[] = {
        "III",
        "LVIII",
        "MCMXCIV"
    };
    for (int i = 0; i < 3; i++)
        printf("%d\t%s\n", romanToInt(str[i]), str[i]);
}
