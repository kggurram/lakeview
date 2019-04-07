#include <stdio.h>

/* Part 1 - Uzair*/
void averages(char *nameData[6], double data[365][8], double averageData[6]){
    printf("\nQuestion 1\n");

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
    printf("\n Question 3\n");
    printf("Lake\t\tWarmest\t  Date\t\tColdest\t  Date\n");

    for(int i = 2; i < 8; i++){
        int MM=0, MM2=0, DD=0, DD2=0;
        for(int j = 0; j<365; j++){
            if(data[coldest][i] > data[j][i]) coldest = j;
            else if(data[hottest][i] < data[j][i]) hottest = j;
        }
        coldestDays[i-2]=coldest;
        hottestDays[i-2]=hottest;

        convertToDDMM((int)data[hottest][1], &MM, &DD);
        convertToDDMM((int)data[coldest][1], &MM2, &DD2);

        printf("Lake %s:\t%5.2lf  \t%s %d\t\t%5.2lf  \t%s %d\n", nameData[i-2], data[hottest][i], monthName[MM-1], DD, data[coldest][i], monthName[MM2-1], DD2);
    }
}
/* Part 4 - Param*/
void hot (char *nameData[6], double data[365][8],char *monthName[12]){
    printf("\nQuestion 4\n");
    int g = 0 ;
    int h =0;
    for(int l = 0; l < 365 ; ++l){
        for( int k = 0 ; k < 6 ; ++k){
            if(data[g][h+2] < data[l][k+2]) {
                g = l;
                h = k;
            }
        }
    }
    printf("Hottest = %lf  ",data[g][h+2]);
    printf("%s  ",nameData[h]);

    int mday[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int d = 0;
    for(int f = 0; f < 12; f++){
        if ( g > d)
            d += mday[f];
        else {
            int t = d - mday[f];
            printf("on %s  ", monthName[f-1]);
            printf("%d\n",g - t);
            break;
        }
    }
}
void cold (char *nameData[6], double data[365][8],char *monthName[12]){
    int g = 0 ;
    int h =0;
    for(int l = 0; l < 365 ; ++l){
        for( int k = 0 ; k < 6 ; ++k){
            if(data[g][h+2] > data[l][k+2]) {
                g = l;
                h = k;

            }
        }
    }
    printf("Coldest =  ");
    printf("%lf  ",data[g][h+2]);
    printf("%s  ",nameData[h]);

    int mday[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int d = 0;
    for(int f = 0; f < 12; f++){
        if ( g > d)
            d += mday[f];
        else {
            int t = d - mday[f];
            printf("on %s  ", monthName[f-1]);
            printf("%d\n\n",g - t);
            break;
        }
    }
}
/*Part 5 - Param*/
void temp (char *nameData[6], double data[365][8]){
    printf("\nQuestion 5\n");
    double avgg[6];
    for( int l = 0 ; l < 6 ; l++){
        double avg = 0;
        for( int k = 172 ; k < 266; k++ ){
            avg += data[k][l+2];
        }
        avgg [l]= (avg/93);
        printf(" the avg is %s ",nameData[l]);
        printf("= %lf\n",(avg)/93);
    }
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)             //Loop for comparing other values
        {
            if (avgg[j] < avgg[i])                //Comparing other array elements
            {
                double tmp = avgg[i];         //Using temporary variable for storing last value
                avgg[i] = avgg[j];            //replacing value
                avgg[j] = tmp;             //storing last value
            }
        }
    }
    char *nameDataa[6] = {"St. Clair","Ontario","Erie", "Huron","Michigan","Superior"};
    printf("\n\nWarmest to coldest : ");                    //Printing message
    for (int i = 0; i < 6; i++)                     //Loop for printing array data after sorting
    {
        printf("%s", nameDataa[i]);
        printf(" %lf \n", avgg[i]);//Printing data
    }
}
// Question 6
void questionsix (char *nameData[6], double data[365][8]){

    double avgg [6];
    double average;
    printf("\nQuestion 6\n");
    for( int l = 0 ; l < 6 ; l++) {
        double avg = 0;
        double avgt =0;
        for (int k = 1; k < 80; k++) {

            avg += data[k][l + 2];

        }
        for (int d = 355; d < 366; d++) {

            avgt += data[d][l+2];
        }
        average = (avgt + avg)/88 ;
        avgg[l] = average;
        printf("the avg is: ");
        printf(" %s = ", nameData[l]);
        printf("%lf\n", average);

    }
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)             //Loop for comparing other values
        {
            if (avgg[j] < avgg[i])                //Comparing other array elements
            {
                double tmp = avgg[i];         //Using temporary variable for storing last value
                avgg[i] = avgg[j];            //replacing value
                avgg[j] = tmp;             //storing last value
            }
        }
    }

    char *nameDataa[6] = {"St. Clair","Ontario","Erie", "Huron","Michigan","Superior"};
    printf("\nWarmest to Coldest \n : ");                    //Printing message
    for (int i = 0; i < 6; i++)                     //Loop for printing array data after sorting
    {
        printf("%s", nameDataa[i]);
        printf(" %lf \n", avgg[i]);//Printing data
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

    /*Run Per-Question Functions*/
    averages(nameData, data, averageData);
    avgAnalysis(nameData, averageData);
    perDayHotnCold(nameData, data, coldestDays, hottestDays, monthName);
    hot (nameData,data,monthName);
    cold (nameData,data,monthName);
    temp (nameData,data);
    questionsix (nameData,data);

    return 0;
}