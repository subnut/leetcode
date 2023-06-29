char * longestCommonPrefix(char ** strs, int strsSize) {
	char *ret;
	char *c = *strs;
	for (; *c != '\0'; c++)
		for (int i = 1; i < strsSize; i++) {
			if (strs[i][c - *strs] != *c)	goto a;
			if (strs[i][c - *strs] == '\0')	goto a;
		}

a:
	ret = calloc(c - *strs + 1, sizeof (char));
	strncpy(ret, strs[0], c - *strs);
	ret[c - *strs] = '\0';
	return ret;
}
