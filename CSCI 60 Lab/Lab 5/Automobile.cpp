#include "Automobile.h"
using namespace std;
Automobile::Automobile(){
    make_ = "";
    model_="";
    year_=0;
    price_=0;
    stall_=-1;
}

Automobile::Automobile(string imake, string imodel, int iyear, double iprice, int istall){
    make_ = imake;
    model_=imodel;
    year_=iyear;
    price_=iprice;
    stall_=istall;
}

bool Automobile::park(bool lot[], int size){
    int spot=size;
    for(int i=0; i<size; i++){
        if(!lot[i])
            spot = i;
    }
    if(spot>=size)
       return false;
    else{
        lot[spot] = true;
        stall_ = spot;
        return true;
    }
}
