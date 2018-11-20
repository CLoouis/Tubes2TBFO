#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


bool cekvalid(double bil1, char opr, double bil2){
    double test;
    
    test = pow(bil1,bil2)
    if ((opr == '/') && (bil2 == 0)){
        return false;
    }
    else if ((bil1 == 0) && (opr == '^') && (bil2 == 0)){
        return false;
    }
    else if (test != test){
        return false;
    }
    else {
        return true;
    }

}