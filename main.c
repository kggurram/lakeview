#include <stdio.h>

/* Part 1 - Uzair*/
void averages(char *nameData[6], double data[365][8], double averageData[6]){
    /* sum all the temperatures for each lake on each day*/
    for (int i = 0; i <365; i++){
        for(int j = 0; j<6; j++) averageData[j] += data[i][j+2];
    }
    /*divide by the number of days and print*/
    printf("Lake\t\t\tTemperature\n");
    for (int i = 0; i<6; i++){
        averageData[i] /= 365;
        printf("Lake %s Average:\t%5.2lf\n", nameData[i], averageData[i]);
    }
    printf("\t\t\t--------\n");
}
/* Part 2 - Uzair*/
void avgAnalysis(char *nameData[6], double averageData[6]){
    /*initialize variables*/
    double avgavg = 0;
    int coldest = 0, hottest = 0;
    /*sum all the numbers and divide by number of terms for average*/
    for (int i = 0; i<6; i++) avgavg+=averageData[i];
    avgavg /= 6;
    printf("Average temperature of all six lakes: %.2lf Degrees Celsius\n", avgavg);
    /*go through the data to locate the coldest and hottest lakes*/
    for(int i = 0; i<6; i++){
        if (averageData[coldest] > averageData[i]) coldest = i;
        if (averageData[hottest] < averageData[i]) hottest = i;
    }
    printf("Lake %s had the warmest average temperature of %5.2lf Degrees Celsius.\n", nameData[hottest], averageData[hottest]);
    printf("Lake %s had the coldest average temperature of %5.2lf Degrees Celsius.\n", nameData[coldest], averageData[coldest]);
    printf("\n");
    /*check if above or below and print immediately*/
    for (int i = 0; i<6; i++){
        if(averageData[i] > avgavg) printf("Lake %s:\tAbove Average Lake Temperature.\n", nameData[i]);
        else if(averageData[i] < avgavg) printf("Lake %s:\tBelow Average Lake Temperature.\n", nameData[i]);
        else if(averageData[i] == avgavg) printf("Lake %s:\tAverage Lake Temperature.\n", nameData[i]);
    }
    printf("\t\t\t--------\n");
}
/* Part 3 - Uzair*/
void perDayHotnCold(char *nameData[6], double data[]){}

int main() {
    /* Initialize 2D Array for name Strings */
    char *nameData[6];
    nameData[0] = "Superior";
    nameData[1] = "Michigan";
    nameData[2] = "Huron";
    nameData[3] = "Erie";
    nameData[4] = "Ontario";
    nameData[5] = "St. Clair";
    /* Initialize 2D Array for data*/
    double data[365][8];
    /* Initialize data for every question*/
    double averageData[6] = {0};

    /* Initialize Read-Only File */
    FILE *file;
    file = fopen("LakeTemp2017.dat", "r");

    /* Fill array with values*/
    for (int i = 0; i<365; i++){
        for (int j = 0; j < 8; ++j) {
            double n;
            fscanf(file, "%lf", &n);
            data[i][j] = n;
        }
    }

    averages(nameData, data, averageData);
    avgAnalysis(nameData, averageData);

    return 0;
}