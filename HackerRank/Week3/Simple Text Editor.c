#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct {
    char *x;
    int tp;
} St;

int main() {
    int q;
    scanf("%d", &q);
    char *s = calloc(1000000, sizeof(char));
    int sl = 0;
    St *st = malloc(q * sizeof(St));
    int sp = 0;
    while (q--) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            char w[1000001];
            scanf("%s", w);
            int l = strlen(w);
            strcpy(st[sp].x = malloc(l+1), w);
            st[sp].tp = 1;
            sp++;
            strcpy(s+sl, w);
            sl += l;
        } else if (t == 2) {
            int k;
            scanf("%d", &k);
            char *d = malloc(k+1);
            strncpy(d, s+sl-k, k);
            d[k] = '\0';
            st[sp].x = d;
            st[sp].tp = 2;
            sp++;
            sl -= k;
            s[sl] = '\0';
        } else if (t == 3) {
            int k;
            scanf("%d", &k);
            printf("%c\n", s[k-1]);
        } else if (t == 4) {
            if (sp > 0) {
                sp--;
                if (st[sp].tp == 1) {
                    int l = strlen(st[sp].x);
                    sl -= l;
                    s[sl] = '\0';
                } else {
                    int l = strlen(st[sp].x);
                    strcpy(s+sl, st[sp].x);
                    sl += l;
                }
                free(st[sp].x);
            }
        }
    }
    free(st);
    free(s);
    return 0;
}
