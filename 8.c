#include <stdbool.h>

#define MAX 2147483647 // 2^31 - 1
#define MIN 2147483648 // 2^31

int myAtoi(char *s) {
	unsigned int result = 0;
	bool isNeg = false;
	int max = MAX;

	while (*s == ' ') s++;
	switch (*s) {
		case '-': isNeg = true; max = MIN;
		case '+': s++;
		default: break;
	}
	while (*s == '0') s++;

	char *p = s;
	for (; true; p++) {
		switch (*p) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				continue;
		};
		p--;
		break;
	}

	if ((p - s) > 9)
		// 2^31 has only 10 digits
		goto overflow;

	for (; s <= p; s++) {
		switch (*s) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				if (result > 214748364)
					// will overflow when multiplied by 10
					goto overflow;

				result *= 10;
				result += (*s - '0');
				if (result >= max)
					goto overflow;

				continue;
			default:
				goto end;
		}
	}

end:
	return isNeg ? -result : result;

overflow:
	result = max;
	goto end;
}
