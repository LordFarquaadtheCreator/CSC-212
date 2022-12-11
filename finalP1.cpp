#include <iostream>
#include <cstdlib>
using namespace std;
const int YEAR(8), MONTH(12); //default global vars


void populate(int *ptr[], int col = YEAR, int row = MONTH){
    unsigned int RV;
    

    for (int i = 0; i < col; i++){ // goes through years
        for (int j = 0; j < row; j++){
            ptr[i][j] = rand()%60; // assigns random number
        }
    }
}

void YearAvrg (int *ptr[], int col = YEAR, int row = MONTH){
    cout << "************* YEARLY AVERAGE *************\n";
    float x = 0;
    for (int i = 0; i < col; i++){//goes through years
        for (int j = 0; j < row; j++){ // goes through months
            x+= ptr[i][j];
        }
        printf("Year %i Rain Total Average: \t%.2fL\n", i+1, x/row);// at the end of each year the average is printed
        x=0; // reset sum
    }
}

void MonthAvrg (int *ptr[], int col = YEAR, int row = MONTH){
    float sum;
    cout << "************* MONTHLY AVERAGE *************\n";
    for (int j = 0; j < row; j++){ // month
        for (int i = 0; i < col; i++){ // year
            sum += ptr[i][j]; // adding each month's val throughout the years
        }
        printf("Month %i Rain Total Average: %.2f\n", j+1, sum/col);
        cout << "******************************************\n";
        sum = 0;
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

    populate(mPtr,8,12);
    YearAvrg(mPtr,8,12);
    MonthAvrg(mPtr,8,12);

    float x = 0;
    cout << "************* YEAR 3 TOTAL *************\n";
    for (int j = 0; j < MONTH; j++){ // goes through every month
        x+= M[2][j]; // index 2 is year 3
    }
    printf("Year 3 Rain Total: \t%.2f L\n", x);
    cout << "******************************************\n";

    return 19;
}