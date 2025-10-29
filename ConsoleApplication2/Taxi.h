#pragma once
#include <iostream>

class Taxi {
private:
    std::string mark;
    std::string model;
    int number;
public:
    Taxi();
    Taxi(const Taxi&);
    Taxi(std::string, std::string, int);


    std::string get_mark();
    std::string get_model();
    int get_number();

    void set_mark(std::string);
    void set_model(std::string);

    void BuyCar();
    void PrintCar();


};