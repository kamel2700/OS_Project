#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
    int maxInt = INT_MAX;
    float maxFloat = FLT_MAX;
    double maxDouble = DBL_MAX;
    printf("max int = %i (size = %i)\n", maxInt, sizeof(maxInt));
    printf("max float = %f (size = %i)\n", maxFloat, sizeof(maxFloat));
    printf("max double = %f (size = %i)\n", maxDouble, sizeof(maxDouble));
    return 0;
}
