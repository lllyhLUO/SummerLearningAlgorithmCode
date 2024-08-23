#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;

    printf("请输入字符的个数: ");
    scanf("%d", &n);
    int a[n];
    a[n] = {2, 3, 4};
    printf("%d", a[n]);
    printf("Hello world!\n");
    return 0;
}
