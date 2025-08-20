#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();

/*
 * Complete the 'isValid' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

/*
 * To return the string from the function, you should either do static allocation or dynamic allocation
 *
 * For example,
 * char* return_string_using_static_allocation() {
 *     static char s[] = "static allocation of string";
 *
 *     return s;
 * }
 *
 * char* return_string_using_dynamic_allocation() {
 *     char* s = malloc(100 * sizeof(char));
 *
 *     s = "dynamic allocation of string";
 *
 *     return s;
 * }
 *
 */
char* isValid(char* s) {
    static char y[] = "YES";
static char n0[] = "NO";

int f[26] = {0};
for (int i = 0; s[i]; i++) {
    if (s[i] >= 'a' && s[i] <= 'z') {
        f[s[i] - 'a']++;
    }
}

int a[26], m = 0;
for (int i = 0; i < 26; i++) {
    if (f[i] > 0) a[m++] = f[i];
}

int mn = a[0], mx = a[0];
for (int i = 1; i < m; i++) {
    if (a[i] < mn) mn = a[i];
    if (a[i] > mx) mx = a[i];
}

if (mn == mx) return y;

int mc = 0, xc = 0;
for (int i = 0; i < m; i++) {
    if (a[i] == mn) mc++;
    else if (a[i] == mx) xc++;
}

if (mn == 1 && mc == 1 && mx == a[(m > 1) ? 1 : 0]) {
    return y;
}

if (mx - mn == 1 && xc == 1) {
    return y;
}

return n0;

}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* s = readline();

    char* result = isValid(s);

    fprintf(fptr, "%s\n", result);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}
