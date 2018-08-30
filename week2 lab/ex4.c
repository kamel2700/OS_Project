#include <stdio.h>

int main() {

    int one, two;

    printf("%s", "Write two integers");

    scanf("%d%d", &one, &two);

    swap(&one, &two);

    printf("%i, %i", one, two);

    return 0;
}
void swap(int *one, int *two){

    int tree;

    tree = *one;

    *one = *two;

    *two = tree;

}
