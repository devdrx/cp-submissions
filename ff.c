#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        char s[n + 1];
        scanf("%s", s);
        
        int ans = 0;
        for (int i = 1; i < n; i += 2) {
            if (s[i] == '(') {
                ans+=3;
            } else {
                ans+=1;
            }
        }
        
        printf("%d\n", ans);
    };
    return 0;
}