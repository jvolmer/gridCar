#ifndef DISPENSER_H
#define DISPENSER_H

class Beverage;

class Dispenser {

private:
    Beverage& _beverage0;
    Beverage& _beverage1;
    Beverage& _beverage2;
    Beverage& _beverage3;
    unsigned int _numberOfBeverages = 4;
    
    Beverage* getBeverage(unsigned int beverageId);

public:
    Dispenser(Beverage& beverage1, Beverage& beverage2, Beverage& beverage3, Beverage& beverage4);
    void selectBeverageForDuration(unsigned int beverageId, unsigned int durationInSeconds);
    void draw();
};

#endif
