#include <cstdio>
#include <cstring>

using namespace std;

int n;
char s1[1024], s2[1024];

int main() {

    scanf("%d",&n);
    scanf("%s %s",s1,s2);
    int p1, p2;
    p1=p2=0;
    int tot=0;
    for (int i=0;i<n;i++) {
        if (s1[i]=='o') p1++;
        tot++;
        // 1 ganha se p1+0 > p2+(n-i)
        if (p1+0 > p2+(n-i)) {
            printf("%d\n",tot);
            return 0;
        }
        // 2 ganha se p2+0 > p1+(n-i-1)
        if (p2+0 > p1+(n-i-1)) {
            printf("%d\n",tot);
            return 0;
        }
        if (s2[i]=='o') p2++;
        tot++;
        // 1 ganha se p1+0 > p2+(n-i-1)
        if (p1+0 > p2+(n-i-1)) {
            printf("%d\n",tot);
            return 0;
        }
        // 2 ganha se p2+0 > p1+(n-i-1)
        if (p2+0 > p1+(n-i-1)) {
            printf("%d\n",tot);
            return 0;
        }
    }
    printf("Empate\n");

    return 0;

}
