#include <stdio.h>

void GetData() {
    FILE *file;
    file = fopen("LakeTemp2017.dat", "r");
    for (int i = 0; i < 365; i++){
        for (int j = 0; j < 8; j++){
            double n;
            fscanf(file, "%lf", &n);

            if (j == 0) printf("%4d ", (int)n);
            else if (j==1) printf("%3d ", (int)n);
            else printf("%lf ", n);
        }
        printf("\n");
    }
    fclose(file);
}

int main() {
    GetData();
    return 0;
}