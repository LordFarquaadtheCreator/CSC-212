#include <iostream>
#include <cstdlib>
using namespace std;

void populate(/*int *Mptr[], int row, int col*/int rain[8][12]){
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 12; j++){
            rain[i][j] = rand(); //randon number
        }
    }
}

void YearAvrg (int rain[8][12]){
    float x = 0;
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 12; j++){
            x+= rain[i][j];
        }
        printf("Year %i Rain Total Average: \t%f.2fL\n", i, x/12);
    }
}

void MonthAvrg (int rain[8][12]){
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 12; j++){
            printf("Year %i Month %i Rain Total Average: %i", i, j, rain[i][j]);
        }
    }
}

int main(){
    srand(19);
    unsigned int RV = rand();
    RV = RV % 60;
    
    int M[8][12];
    populate(M);
    YearAvrg(M);
    MonthAvrg(M);

    float x = 0;
        for (int j = 0; j < 12; j++){
            x+= M[3][j];
        }
        printf("Year 3 Rain Total Average: \t%f.2fL\n", x/12);

        return 19;
}