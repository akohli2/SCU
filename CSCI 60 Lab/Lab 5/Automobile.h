#ifndef AUTOMOBILE_H
#define AUTOMOBILE_H
#include <string>
using namespace std;
class Automobile
{
public:
    Automobile();
    Automobile(string imake, string imodel, int iyear, double iprice, int istall);
    bool park(bool lot[], int size);
    string make(){return make_;}
    string model(){return model_;}
    int year(){return year_;}
    double price(){return price_;}
    int stall(){return stall_;}
    void set_stall(int s){stall_ = s;}
private:
    string make_;
    string model_;
    int year_;
    double price_;
    int stall_;
};




#endif // AUTOMOBILE_H
