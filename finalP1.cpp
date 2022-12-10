#include <iostream>
#include <cstdlib>
using namespace std;
const int YEAR(8), MONTH(12);


void populate(int *ptr[8], int col = YEAR, int row = MONTH){
    unsigned int RV;
    

    for (int i = 0; i < col; i++){ // goes through years
        for (int j = 0; j < row; j++){
            RV = rand()%60; // sets up RV -> normalizes it
            ptr[i][j] = RV; // assigns random number
        }
    }
}

void YearAvrg (int *ptr[8], int col = YEAR, int row = MONTH){
    cout << "************* YEARLY AVERAGE *************\n";
    float x = 0;
    for (int i = 0; i < col; i++){//goes through years
        for (int j = 0; j < row; j++){ // goes through months
            x+= ptr[i][j];
        }
        printf("Year %i Rain Total Average: \t%.2fL\n", i+1, x/row);
        x=0;
    }
}

void MonthAvrg (int *ptr[8], int col = YEAR, int row = MONTH){
    cout << "************* MONTHLY AVERAGE *************\n";
    for (int i = 0; i < col; i++){
        for (int j = 0; j < row; j++){
            printf("Year %i Month %i Rain Total Average: %i\n", i+1, j+1, ptr[i][j]);
        }
        cout << "******************************************\n";
    }
}

int main(){
    string Name = "Fahad Faruqi";
    cout << "-----------------------------------------\n";
    cout << "Name: " << Name << endl;
    cout << "FILE: " << __FILE__ << "\tDATE: " << __DATE__ << endl;
    cout << "-----------------------------------------\n";

    srand(19);
    
    int M[8][12];
    int *mPtr[8];

    for (int i(0); i < 8; i++){
        mPtr[i] = &M[i][0];
    }

    populate(mPtr);
    YearAvrg(mPtr);
    MonthAvrg(mPtr);

    float x = 0;
    cout << "************* YEAR 3 AVERAGE *************\n";
    for (int j = 0; j < MONTH; j++){ // goes through every month
        x+= M[2][j]; // index 2 is year 3
    }
    printf("Year 3 Rain Total Average: \t%.2f L\n", x/MONTH);
    cout << "******************************************\n";

    return 19;
}