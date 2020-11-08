#ifndef DISPENSER_H
#define DISPENSER_H

class Beverage;

class Dispenser {

private:
    Beverage& _beverage1;
    Beverage& _beverage2;
    Beverage& _beverage3;
    Beverage& _beverage4;    

    Beverage& getBeverage(int beverageId);

public:
    Dispenser(Beverage& beverage1, Beverage& beverage2, Beverage& beverage3, Beverage& beverage4);
    void addFilling(int beverageId, int durationInSeconds);
    void fill();
};

#endif
