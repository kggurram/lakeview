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
void convertToDDMM(int day, int *MM, int *DD){
    /*Store the length of each month*/
    int mday[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int months = 12;
    int sum = 0;
    for(int i = 1; i <= months; i++){
        /*if there are days left to account for, account for them*/
        if (day >= sum && day <= sum+mday[i] && i<months){
            *MM = i;
            *DD = day-sum;
            break;
        }
        /*if its december, account for the last few days*/
        else if (i ==months){
            *MM = months;
            *DD = day-sum;
            break;
        }
        sum += mday[i-1];
    }
}
void perDayHotnCold(char *nameData[6], double data[365][8], double coldestDays[6], double hottestDays[6], char *monthName[12]){
    int coldest = 0, hottest = 0;

    printf("Lake\t\tWarmest\t  Date\t\tColdest\t  Date\n");

    for(int i = 0; i < 6; i++){
        int MM=0, MM2=0, DD=0, DD2=0;
        for(int j = 0; j<365; j++){
            if(data[coldest][i+2] > data[j][i+2]) coldest = j;
            else if(data[hottest][i+2] < data[j][i+2]) hottest = j;
        }
        coldestDays[i]=coldest;
        hottestDays[i]=hottest;

        convertToDDMM(hottest, &MM, &DD);
        convertToDDMM(coldest, &MM2, &DD2);

        printf("Lake %s:\t%5.2lf  \t%s %d\t\t%5.2lf  \t%s %d\n", nameData[i], data[hottest][i+2], monthName[MM], DD, data[coldest][i+2], monthName[MM2], DD2);
    }
}

int main() {
    /* Initialize 2D Array for name Strings */
    char *nameData[6] = {"Superior", "Michigan", "Huron", "Erie","Ontario","St. Clair"};
    char *monthName[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    /* Initialize 2D Array for data*/
    double data[365][8];
    /* Initialize data for every question*/
    double averageData[6] = {0}, coldestDays[6] = {0}, hottestDays[6] = {0};

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
    perDayHotnCold(nameData, data, coldestDays, hottestDays, monthName);

    return 0;
}