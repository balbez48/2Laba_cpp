#include "Taxi.h"
#include <iostream>

Taxi::Taxi()
{
    mark = "standart";
    model = "classic";
    number = 1;
}

Taxi::Taxi(const Taxi& car)
{
    mark = car.mark;
    model = car.model;
    number = car.number;

}

Taxi::Taxi(std::string mark, std::string model, int number)
{
    set_mark(mark);
    set_model(model);
    this->number = number;

}

std::string Taxi::get_mark()
{
    return mark;
}

std::string Taxi::get_model()
{
    return model;
}

int Taxi::get_number()
{
    return number;
}

void Taxi::set_mark(std::string)
{
    this->mark = mark;
}

void Taxi::set_model(std::string)
{
    this->model = model;
}

void Taxi::BuyCar()
{
    std::cout << "Куплена машина: марка - " << mark << ", модель - " << model << ", номер - " << number;
}

void Taxi::PrintCar()
{
    std::cout << "123";
}




