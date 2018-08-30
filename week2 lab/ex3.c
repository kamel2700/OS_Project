int main(int argc, const char * argv[]) {

    int n=6,pow=1, i, j, k;

    char gap = ' ';

    sscanf(argv[1],"%d", &n);*/


    for(i = 0; i < n; i++){

        for(j = 1; j < n-i; j++){

            printf("%c", gap);

        }
        for(k=0; k<pow; k++){

            printf("%c",'*');

        }

        pow = pow+2;

        for(j = 1; j < n-i; j++){

            printf("%c", gap);

        }

        printf("\n");
    }

    return 0;
}
