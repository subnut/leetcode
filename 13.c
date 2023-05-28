#include <stdio.h>

#ifndef DEBUG
#define DEBUG 0
#endif

#if DEBUG
#define DPRINTF printf
#else
#define DPRINTF(...) {;}
#endif

int char2int(const char c) {
    switch (c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

int romanToInt(const char *s) {
    int result = 0;
    int prev, cur;

    DPRINTF("\nchar\tprev\tcur\tresult\tprev>=cur\n");

    cur = char2int(*s);
    result += cur;
    DPRINTF("%c\t-\t%d\t%d\t-\n", *s, cur, result);

    while (*++s != '\0') {
        prev = cur;
        cur = char2int(*s);
        result += prev >= cur ? cur : cur - prev*2;
        DPRINTF("%c\t%d\t%d\t%d\t%d\n", *s, prev, cur, result, prev>=cur);
    }

    DPRINTF("\n");
    return result;
}

int main(void) {
    const char *str[] = {
        "III",
        "LVIII",
        "MCMXCIV"
    };
    for (int i = 0; i < 3; i++)
        printf("%d\t%s\n", romanToInt(str[i]), str[i]);
}
