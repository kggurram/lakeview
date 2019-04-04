#include <stdio.h>

int averages(double data[365][8]){
    /* Initialize Lake Variables */
    double supAvg =0, michAvg=0, huronAvg=0, erieAvg=0, ontAvg=0, stClairAvg=0;

    /* Go through Data array and sum all the values per lake */
    for (int i = 0; i <365; i++){
        supAvg      += data[i][2];
        michAvg     += data[i][3];
        huronAvg    += data[i][4];
        erieAvg     += data[i][5];
        ontAvg      += data[i][6];
        stClairAvg  += data[i][7];
    }

    /* Divide by number of days */
    supAvg      /= 365;
    michAvg     /= 365;
    huronAvg    /= 365;
    erieAvg     /= 365;
    ontAvg      /= 365;
    stClairAvg  /= 365;

    /* Printing (Yay!...)*/
    printf("Lake                    Temperature    \n");
    printf("Lake Superior Average:  %.2lf degrees. \n", supAvg);
    printf("Lake Michigan Average:  %.2lf degrees. \n", michAvg);
    printf("Lake Huron Average:     %.2lf degrees. \n", huronAvg);
    printf("Lake Erie Average:      %.2lf degrees. \n", erieAvg);
    printf("Lake Ontario Average:   %.2lf degrees. \n", ontAvg);
    printf("Lake St. Clair Average: %.2lf degrees. \n", stClairAvg);
    return 0;
}

int main() {
    /* Initialize 2D Array */
    double data[365][8];


    /* Initialize Read-Only File */
    FILE *file;
    file = fopen("LakeTemp2017.dat", "r");

    /* Fill array with values*/
    for (int i = 0; i<365; i++){
        for (int j = 0; j < 8; ++j) {
            double n;
            fscanf(file, "%lf", &n);
            data[i][j] = n;
            /*printf("%lf ", data[i][j]);*/
        }
        /*printf("\n");*/
    }

    averages(data);
    return 0;
}