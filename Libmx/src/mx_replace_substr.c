#include "libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
	if (!sub || !str || !replace)
		return NULL;

	int sub_len = mx_strlen(sub);
	int replace_len = mx_strlen(replace);
	int count = mx_count_substr(str, sub);
	char *newstr = mx_strnew(mx_strlen(str)
		 - sub_len * count + replace_len * count);
	char *pointer = newstr;

	if (!newstr)
		return NULL;

	while (*str) {
		if (mx_strncmp(str, sub, sub_len) == 0) {
			mx_strcat(pointer, replace);
			str += sub_len;
			pointer += replace_len;
		}
		else
			*pointer++ = *str++;
	}
	return newstr;
}
