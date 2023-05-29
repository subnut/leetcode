#define c2n(x) (x - 'a')
#define canConstruct check
bool check(char *note, char *mag) {
	/* int because *note might just be 10^4 'a's ("aaa..a") */
	int have[26] = { 0 };
	int need[26] = { 0 };

	size_t len;
	len = strlen(mag);
	for (int i = 0; i < len; i++)
		have[c2n(mag[i])]++;

	len = strlen(note);
	for (int i = 0; i < len; i++)
		need[c2n(note[i])]++;

	for (int i = 0; i < 26; i++)
		if (have[i] < need[i])
			return false;

	return true;
}
