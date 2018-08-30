#include <stdio.h>

int main()
{
    printf("Enter string to reverse\n");
    char str[20];
    scanf("%s", str);
    int i=0;
    for(i=strlen(str)-1;i>=0;i--){
        printf("%c", str[i]);
    }
    return 0;
}
