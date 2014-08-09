#include <cstdio>
#include <cstring>

using namespace std;

int n, m, a, k;
char s[1024];

int main() {

    scanf("%d %d %d %d",&n,&m,&a,&k);
    scanf("%s",s);
    bool ok=true;
    int tam = strlen(s);
    if (tam < n) ok=false;
    int mai, min, num;
    mai=min=num=0;
    for (int i=0;s[i];i++) {
        if ('a' <= s[i] and s[i] <= 'z') min++;
        if ('A' <= s[i] and s[i] <= 'Z') mai++;
        if ('0' <= s[i] and s[i] <= '9') num++;
    }
    if (min < m or mai < a or num < k) ok=false;
    if (ok)
        printf("Ok =/\n");
    else
        printf("Ufa :)\n");

    return 0;
}
