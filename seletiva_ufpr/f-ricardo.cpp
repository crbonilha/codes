#include <cstdio>
#include <cstring>

using namespace std;

char S[100010], s2[100010];
char *s;
int d;

int main() {

    s = S;
    scanf("%s",s);
    scanf("%d",&d);
    int n = strlen(s);
    int r = 0;
    while (n > 0) {
        if (!((s[n-1]-'0')&1))
            r = 1 - r;
        // s2 = s/d
        int resto = 0;
        for (int i=0;i<n;i++) {
            resto = 10*resto + (s[i]-'0');
            s2[i] = (resto/d)+'0';
            resto = resto%d;
        }
        s2[n] = '\0';
        // s = s2
        int offset;
        for (offset=0;offset<n;offset++)
            if (s2[offset] != '0') break;
        n -= offset;
        strcpy(s,s2);
        s = s + offset;
    }

    if (r == 0)
        printf("sobe desce\n");
    else
        printf("desce sobe\n");

    return 0;
}
