#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
#include "Laba2.h"


int main() {
  setlocale(LC_ALL, "Rus");
 

  bool flag = 1;
  int numTask = 0;
  std::cout << "Вариант №14" << std::endl;
  std::cout << "Список заданий: " << std::endl;
  std::cout << "------------------------------------- " << std::endl;
  std::cout << "|#1: 6 |#2: 4 |#3: 9 |#4: 3 |#5:  5 | " << std::endl;
  std::cout << "------------------------------------- " << std::endl;
  std::cout << "|#6: 14|#7: 11|#8: 1 |#9: 1 |#10: 2 | " << std::endl;
  std::cout << "------------------------------------- " << std::endl;

  while (flag) {   
    std::cout << "\nЧтобы выйти укажите -1" << std::endl;
    std::cout << "Введите номер задания - ";
    std::cin >> numTask;
      
    if (numTask == -1) { 
    break; 
    }

    switch (numTask) {
      case 1: {

        std::cout << "----------------------------------------------------------------------------------------------" << std::endl;
        std::cout << "Задание: Даны V, Deq, List, заполненные нечетным количеством элементов (минимум три элемента)." << std::endl;
        std::cout << "Необходимо первый, последний и средний элемент каждого из контейнеров умножить на 2." << std::endl;

        int n = 0;
        bool f = 1;
        std::cout << "Введите НЕЧЕТНОЕ количество элементов в контейнере: ";
        while (f) {
          std::cin >> n;
          if (n % 2 != 0 && n > 0) {
              f = 0;
          } else {
              std::cout << "Попробуйте снова: ";
          }
        }

        std::vector<int> vect(n);
        std::deque<int> deque(n);
        std::list<int> list(n);

        int el = 0;
        std::cout << "Заполните Vector." << std::endl;
        for (auto iter = vect.begin(); iter != vect.end(); iter++) {
            std::cout << "Введите число: ";
            std::cin >> el;
            *iter = el;
        }
        
        std::cout << "Заполните Deque." << std::endl;
        for (auto iter = deque.begin(); iter != deque.end(); iter++) {
            std::cout << "Введите число: ";
            std::cin >> el;
            *iter = el;
        }
        
        std::cout << "Заполните List." << std::endl;
        for (auto iter = list.begin(); iter != list.end(); iter++) {
            std::cout << "Введите число: ";
            std::cin >> el;
            *iter = el;
        }

        MulConteiner(vect, deque, list);

        std::cout << "Vector: ";
        for (auto it_vect = vect.begin(); it_vect != vect.end(); it_vect++) {
            std::cout << *it_vect << " ";
        }
        std::cout << std::endl;
        
        std::cout << "Deque:  ";
        for (auto it_deq = deque.begin(); it_deq != deque.end(); it_deq++) {
            std::cout << *it_deq << " ";
        }
        std::cout << std::endl;

        std::cout << "List:   ";
        for (auto it_list = list.begin(); it_list != list.end(); it_list++) {
            std::cout << *it_list << " ";
        }
        std::cout << std::endl;
      } break;
      case 2: {
        std::cout << "----------------------------------------------------------------------------------------------" << std::endl;
        std::cout << "Задание: Даны V и List, заполненные минимум пятью элементами." << std::endl;
        std::cout << "Вставить после элемента списка с порядковым номером 5 первые 5 элементов вектора в обратном порядке." << std::endl;

        int n = 0;
        bool f = 1;
        std::cout << "Введите количество элементов в контейнере большее или равное 5: ";
        while (f) {
            std::cin >> n;
            if (n >= 5 && n > 0) {
                f = 0;
            }
            else {
                std::cout << "Попробуйте снова: ";
            }
        }

        std::vector<int> vect(n);
        std::list<int> list(n);

        int el = 0;
        std::cout << "Заполните Vector." << std::endl;
        for (auto iter = vect.begin(); iter != vect.end(); iter++) {
            std::cout << "Введите число: ";
            std::cin >> el;
            *iter = el;
        }

        std::cout << "Заполните List." << std::endl;
        for (auto iter = list.begin(); iter != list.end(); iter++) {
            std::cout << "Введите число: ";
            std::cin >> el;
            *iter = el;
        }

        InsVectList(vect, list);


      } break;
      case 3: {
        std::cout << "----------------------------------------------------------------------------------------------" << std::endl;
        std::cout << "Задание: Даны Deq, заполненный элементами количеством кратным 4." << std::endl;
        std::cout << "Нужно удалить в первой половине исходного дека все элементы с четными порядковыми номерами." << std::endl;

        int n = 0;
        bool f = 1;
        std::cout << "Введите количество элементов в контейнере кратным 4: ";
        while (f) {
            std::cin >> n;
            if (n % 4 == 0 && n > 0) {
                f = 0;
            }
            else {
                std::cout << "Попробуйте снова: ";
            }
        }

        std::deque<int> deque(n);
        

        int el = 0;
        std::cout << "Заполните Vector." << std::endl;
        for (auto iter = deque.begin(); iter != deque.end(); iter++) {
            std::cout << "Введите число: ";
            std::cin >> el;
            *iter = el;
        }

        DelDeque4(deque);


      } break;
      case 4: {
        std::cout << "--------------------------------------------------------------------------" << std::endl;
        std::cout << "Задание: Дан набор вещественных чисел, содержащий не менее двух элементов." << std::endl;
        std::cout << "Вывести числа из исходного набора с четными порядковыми номерами." << std::endl;
        
        RemoveCopyIf();
      } break;
      case 5: {
        std::cout << "--------------------------------------------------------------------------------------------------------" << std::endl;
        std::cout << "Задание: Дан List." << std::endl;
        std::cout << "Вставить нулевой элемент после первого отрицательного элемента и перед последним положительным элементом." << std::endl;

        int n = 0;
        bool f = 1;
        std::cout << "Введите количество элементов в контейнере: ";
        while (f) {
            std::cin >> n;
            if (n > 0) {
                f = 0;
            }
            else {
                std::cout << "Попробуйте снова: ";
            }
        }

        
        std::list<int> list(n);
        int el = 0;
        
        std::cout << "Заполните List." << std::endl;
        for (auto iter = list.begin(); iter != list.end(); iter++) {
            std::cout << "Введите число: ";
            std::cin >> el;
            *iter = el;
        }

        InsertElemList(list);
      } break;
      case 6: {
        std::cout << "-----------------------------------------------------------------------------------------" << std::endl;
        std::cout << "Задание: Дан Vector с четным количеством элементов." << std::endl;
        std::cout << "Из второй половины вектора скопировать в начало все положительные элементы этого вектора." << std::endl;

        int n = 0;
        bool f = 1;
        std::cout << "Введите четное количество элементов в векторе: ";
        while (f) {
            std::cin >> n;
            if (n % 2 == 0 && n > 0) {
                f = 0;
            }
            else {
                std::cout << "Попробуйте снова: ";
            }
        }

        std::vector<int> vect(n);
        int el = 0;

        std::cout << "Заполните Vector." << std::endl;
        for (auto iter = vect.begin(); iter != vect.end(); iter++) {
            std::cout << "Введите число: ";
            std::cin >> el;
            *iter = el;
        }

        std::cout << "Исходный Vector." << std::endl;
        for (auto iter = vect.begin(); iter != vect.end(); iter++) {
           std::cout << *iter << " ";
        }
        std::cout << std::endl;

        VectRemCopIf(vect);
      } break;
      case 7: {
        std::cout << "---------------------------------------------------------------------------------------------------" << std::endl;
        std::cout << "Задание: Дан дек D, элементами которого являются английские слова." << std::endl;
        std::cout << "Отсортировать его элементы по убыванию их длин, а элементы одинаковой длины — в алфавитном порядке." << std::endl;

        std::deque<std::string> deq{ "bbc","baacd","aab","bacc","abcc","aaaac", "abaac" };
        std::cout << "Исходный Deq: " << std::endl;
        for (auto iter = deq.begin(); iter != deq.end(); iter++) {
            std::cout << *iter << " ";
        }
        std::cout << std::endl;

        DeqEnglishWords(deq);
      } break;
      case 8: {
        std::cout << "---------------------------------------------------------------------------------------------" << std::endl;
        std::cout << "Задание: Дан список L." << std::endl;
        std::cout << "Получить вектор V вещественных чисел, " << std::endl;
        std::cout << "содержащий значения среднего арифметического для всех пар соседних элементов исходного списка" << std::endl;

        int n = 0;
        bool f = 1;
        std::cout << "Введите количество элементов в списке: ";
        while (f) {
            std::cin >> n;
            if (n % 2 == 0 && n > 0) {
                f = 0;
            }
            else {
                std::cout << "Попробуйте снова: ";
            }
        }

        std::list<int> list(n);
        int el = 0;

        std::cout << "Заполните List." << std::endl;
        for (auto iter = list.begin(); iter != list.end(); iter++) {
            std::cout << "Введите число: ";
            std::cin >> el;
            *iter = el;
        }
        AlgoritmAdjDif(list);
      } break;
      default: {
        std::cout << "Такого задания нет." << std::endl;
      }
    }
  }
}