#include <stdio.h>

/*Helper - Uzair - Convert 365 Day format to DDMM*/
void convertToDDMM(int day, int *MM, int *DD){
    int mday[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int months = 12;
    int sum = 0;
    for(int i = 1; i <= months; i++){
        if (day >= sum && day <= sum+mday[i] && i<months){
            *MM = i;
            *DD = day-sum;
            break;
        }
        else if (i ==months){
            *MM = months;
            *DD = day-sum;
            break;
        }
        sum += mday[i-1];
    }
}
/* Part 1 - Uzair*/
void averages(const double data[365][8], const char *nameData[6], double averageData[6]){
    printf("\nQuestion 1\n");
    /*sum all the temperatures for each lake on each day*/
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
void avgAnalysis(const double averageData[6], const char *nameData[6]){
    printf("\nQuestion 2\n");
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
void perLakeHotnCold(const double data[365][8], const char *nameData[6], const char *monthName[12], int hottestDays[6], int coldestDays[6]){
    int coldest = 0, hottest = 0;
    printf("\nQuestion 3\n");
    printf("Warmest and Coldest Temperatures, Per lake and Overall\n");
    printf("Lake\t\tWarmest\t  Date\t\tColdest\t  Date\n");
    /*Go through all the columns in the data (ignore first two)*/
    for(int i = 2; i < 8; i++){
        int MM=0, MM2=0, DD=0, DD2=0;
        /*Go through all the rows to find smallest/largest in each column, then save the index*/
        for(int j = 0; j<365; j++){
            if(data[coldest][i] > data[j][i]) coldest = j;
            else if(data[hottest][i] < data[j][i]) hottest = j;
        }
        /* Save index to an array of vertical indexes for future reference*/
        coldestDays[i-2]=coldest;
        hottestDays[i-2]=hottest;
        /*Convert 365 form to DDMM and print*/
        convertToDDMM((int)data[hottest][1], &MM, &DD);
        convertToDDMM((int)data[coldest][1], &MM2, &DD2);
        printf("Lake %s:\t%5.2lf  \t%s %d\t\t%5.2lf  \t%s %d\n", nameData[i-2], data[hottest][i], monthName[MM-1], DD, data[coldest][i], monthName[MM2-1], DD2);
    }
    printf("\t\t\t--------\n");
}
/* Part 4 - Param*/
void overallHotnCold (const double data[365][8], const char *nameData[6], const char *monthName[12], const int hottestDays[6], const int coldestDays[6]){
    printf("\nQuestion 4\n");
    int hottest = 0, coldest = 0, MM=0,MM2=0,DD=0,DD2=0;
    for (int i = 0; i < 6; i++){
        if(data[coldestDays[coldest]][i+2] > data[coldestDays[i]][i+2]) coldest = i;
        if(data[hottestDays[hottest]][i+2] < data[hottestDays[i]][i+2]) hottest = i;
    }
    convertToDDMM((int)data[hottestDays[hottest]][1], &MM, &DD);
    convertToDDMM((int)data[coldestDays[coldest]][1], &MM2, &DD2);
    printf("Lake %s had the warmest overall temperature of %5.2lf Degrees Celsius on %s %d \n", nameData[hottest], data[hottestDays[hottest]][hottest+2], monthName[MM-1], DD);
    printf("Lake %s had the coldest overall temperature of %5.2lf Degrees Celsius on %s %d \n", nameData[coldest], data[coldestDays[coldest]][coldest+2], monthName[MM2-1], DD2);
    printf("\t\t\t--------\n");
}
/* Part 5 - Param*/
void summerAvgs (const double data[365][8], const char *nameData[6]){
    printf("\nQuestion 5\n");
    printf("Summer Averages (Warmest to Coldest)\n");
    double avgOrdered[6];
    for(int i = 0; i < 6; i++){
        double avg = 0;
        for(int j = 171 ; j < 265; j++) avg += data[j][i+2];
        avgOrdered[i]= (avg/93);
    }
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 6; j++){
            if (avgOrdered[j] < avgOrdered[i]){
                double tmp = avgOrdered[i];
                avgOrdered[i] = avgOrdered[j];
                avgOrdered[j] = tmp;
            }
        }
    }
    for (int i = 0; i < 6; i++) printf("Lake %s:\t%5.2lf Degrees Celsius\n",nameData[i], avgOrdered[i]);
    printf("\t\t\t--------\n");
}
/* Part 6 - Param*/
void winterAvgs (const double data[365][8], const char *nameData[6]){
    printf("\nQuestion 6\n");
    printf("Summer Averages (Warmest to Coldest)\n");
    double avgOrdered [6];
    double average;
    for( int l = 0 ; l < 6 ; l++) {
        double avg = 0;
        double avgt =0;
        for (int k = 0; k < 79; k++) avg += data[k][l + 2];
        for (int d = 354; d < 365; d++) avgt += data[d][l+2];
        average = (avgt + avg)/89;
        avgOrdered[l] = average;
    }
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 6; j++){
            if (avgOrdered[j] < avgOrdered[i]){
                double tmp = avgOrdered[i];
                avgOrdered[i] = avgOrdered[j];
                avgOrdered[j] = tmp;
            }
        }
    }
    for (int i = 0; i < 6; i++) printf("Lake %s:\t%5.2lf Degrees Celsius\n",nameData[i], avgOrdered[i]);
    printf("\t\t\t--------\n");
}
/* Part 7 - Karthik*/

/* Part 8 - Karthik*/

/*Main Function - Uzair*/
int main() {
    /* Initialize Array for name of Strings and Months, average temperatures, and coldest and hottest days. 2D array for all data,*/
    char *nameData[6] = {"Superior","Michigan","Huron","Erie","Ontario","St. Clair"}, *monthName[12] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
    /* Initialize 2D Array for data*/
    double data[365][8],averageData[6] = {0};
    int coldestDays[6] = {0}, hottestDays[6] = {0};
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
    /*Run Per-Question Functions*/
    averages(data, nameData, averageData);
    avgAnalysis(averageData, nameData);
    perLakeHotnCold(data, nameData, monthName, hottestDays, coldestDays);
    overallHotnCold(data, nameData, monthName, hottestDays, coldestDays);
    summerAvgs(data,nameData);
    winterAvgs(data,nameData);
    return 0;
}