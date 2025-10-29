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
  std::cout << "������� �14" << std::endl;
  std::cout << "������ �������: " << std::endl;
  std::cout << "------------------------------------- " << std::endl;
  std::cout << "|#1: 6 |#2: 4 |#3: 9 |#4: 3 |#5:  5 | " << std::endl;
  std::cout << "------------------------------------- " << std::endl;
  std::cout << "|#6: 14|#7: 11|#8: 1 |#9: 1 |#10: 2 | " << std::endl;
  std::cout << "------------------------------------- " << std::endl;

  while (flag) {   
    std::cout << "\n����� ����� ������� -1" << std::endl;
    std::cout << "������� ����� ������� - ";
    std::cin >> numTask;
      
    if (numTask == -1) { 
    break; 
    }

    switch (numTask) {
      case 1: {

        std::cout << "----------------------------------------------------------------------------------------------" << std::endl;
        std::cout << "�������: ���� V, Deq, List, ����������� �������� ����������� ��������� (������� ��� ��������)." << std::endl;
        std::cout << "���������� ������, ��������� � ������� ������� ������� �� ����������� �������� �� 2." << std::endl;

        int n = 0;
        bool f = 1;
        std::cout << "������� �������� ���������� ��������� � ����������: ";
        while (f) {
          std::cin >> n;
          if (n % 2 != 0 && n > 0) {
              f = 0;
          } else {
              std::cout << "���������� �����: ";
          }
        }

        std::vector<int> vect(n);
        std::deque<int> deque(n);
        std::list<int> list(n);

        int el = 0;
        std::cout << "��������� Vector." << std::endl;
        for (auto iter = vect.begin(); iter != vect.end(); iter++) {
            std::cout << "������� �����: ";
            std::cin >> el;
            *iter = el;
        }
        
        std::cout << "��������� Deque." << std::endl;
        for (auto iter = deque.begin(); iter != deque.end(); iter++) {
            std::cout << "������� �����: ";
            std::cin >> el;
            *iter = el;
        }
        
        std::cout << "��������� List." << std::endl;
        for (auto iter = list.begin(); iter != list.end(); iter++) {
            std::cout << "������� �����: ";
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
        std::cout << "�������: ���� V � List, ����������� ������� ����� ����������." << std::endl;
        std::cout << "�������� ����� �������� ������ � ���������� ������� 5 ������ 5 ��������� ������� � �������� �������." << std::endl;

        int n = 0;
        bool f = 1;
        std::cout << "������� ���������� ��������� � ���������� ������� ��� ������ 5: ";
        while (f) {
            std::cin >> n;
            if (n >= 5 && n > 0) {
                f = 0;
            }
            else {
                std::cout << "���������� �����: ";
            }
        }

        std::vector<int> vect(n);
        std::list<int> list(n);

        int el = 0;
        std::cout << "��������� Vector." << std::endl;
        for (auto iter = vect.begin(); iter != vect.end(); iter++) {
            std::cout << "������� �����: ";
            std::cin >> el;
            *iter = el;
        }

        std::cout << "��������� List." << std::endl;
        for (auto iter = list.begin(); iter != list.end(); iter++) {
            std::cout << "������� �����: ";
            std::cin >> el;
            *iter = el;
        }

        InsVectList(vect, list);


      } break;
      case 3: {
        std::cout << "----------------------------------------------------------------------------------------------" << std::endl;
        std::cout << "�������: ���� Deq, ����������� ���������� ����������� ������� 4." << std::endl;
        std::cout << "����� ������� � ������ �������� ��������� ���� ��� �������� � ������� ����������� ��������." << std::endl;

        int n = 0;
        bool f = 1;
        std::cout << "������� ���������� ��������� � ���������� ������� 4: ";
        while (f) {
            std::cin >> n;
            if (n % 4 == 0 && n > 0) {
                f = 0;
            }
            else {
                std::cout << "���������� �����: ";
            }
        }

        std::deque<int> deque(n);
        

        int el = 0;
        std::cout << "��������� Vector." << std::endl;
        for (auto iter = deque.begin(); iter != deque.end(); iter++) {
            std::cout << "������� �����: ";
            std::cin >> el;
            *iter = el;
        }

        DelDeque4(deque);


      } break;
      case 4: {
        std::cout << "--------------------------------------------------------------------------" << std::endl;
        std::cout << "�������: ��� ����� ������������ �����, ���������� �� ����� ���� ���������." << std::endl;
        std::cout << "������� ����� �� ��������� ������ � ������� ����������� ��������." << std::endl;
        
        RemoveCopyIf();
      } break;
      case 5: {
        std::cout << "--------------------------------------------------------------------------------------------------------" << std::endl;
        std::cout << "�������: ��� List." << std::endl;
        std::cout << "�������� ������� ������� ����� ������� �������������� �������� � ����� ��������� ������������� ���������." << std::endl;

        int n = 0;
        bool f = 1;
        std::cout << "������� ���������� ��������� � ����������: ";
        while (f) {
            std::cin >> n;
            if (n > 0) {
                f = 0;
            }
            else {
                std::cout << "���������� �����: ";
            }
        }

        
        std::list<int> list(n);
        int el = 0;
        
        std::cout << "��������� List." << std::endl;
        for (auto iter = list.begin(); iter != list.end(); iter++) {
            std::cout << "������� �����: ";
            std::cin >> el;
            *iter = el;
        }

        InsertElemList(list);
      } break;
      case 6: {
        std::cout << "-----------------------------------------------------------------------------------------" << std::endl;
        std::cout << "�������: ��� Vector � ������ ����������� ���������." << std::endl;
        std::cout << "�� ������ �������� ������� ����������� � ������ ��� ������������� �������� ����� �������." << std::endl;

        int n = 0;
        bool f = 1;
        std::cout << "������� ������ ���������� ��������� � �������: ";
        while (f) {
            std::cin >> n;
            if (n % 2 == 0 && n > 0) {
                f = 0;
            }
            else {
                std::cout << "���������� �����: ";
            }
        }

        std::vector<int> vect(n);
        int el = 0;

        std::cout << "��������� Vector." << std::endl;
        for (auto iter = vect.begin(); iter != vect.end(); iter++) {
            std::cout << "������� �����: ";
            std::cin >> el;
            *iter = el;
        }

        std::cout << "�������� Vector." << std::endl;
        for (auto iter = vect.begin(); iter != vect.end(); iter++) {
           std::cout << *iter << " ";
        }
        std::cout << std::endl;

        VectRemCopIf(vect);
      } break;
      case 7: {
        std::cout << "---------------------------------------------------------------------------------------------------" << std::endl;
        std::cout << "�������: ��� ��� D, ���������� �������� �������� ���������� �����." << std::endl;
        std::cout << "������������� ��� �������� �� �������� �� ����, � �������� ���������� ����� � � ���������� �������." << std::endl;

        std::deque<std::string> deq{ "bbc","baacd","aab","bacc","abcc","aaaac", "abaac" };
        std::cout << "�������� Deq: " << std::endl;
        for (auto iter = deq.begin(); iter != deq.end(); iter++) {
            std::cout << *iter << " ";
        }
        std::cout << std::endl;

        DeqEnglishWords(deq);
      } break;
      case 8: {
        std::cout << "---------------------------------------------------------------------------------------------" << std::endl;
        std::cout << "�������: ��� ������ L." << std::endl;
        std::cout << "�������� ������ V ������������ �����, " << std::endl;
        std::cout << "���������� �������� �������� ��������������� ��� ���� ��� �������� ��������� ��������� ������" << std::endl;

        int n = 0;
        bool f = 1;
        std::cout << "������� ���������� ��������� � ������: ";
        while (f) {
            std::cin >> n;
            if (n % 2 == 0 && n > 0) {
                f = 0;
            }
            else {
                std::cout << "���������� �����: ";
            }
        }

        std::list<int> list(n);
        int el = 0;

        std::cout << "��������� List." << std::endl;
        for (auto iter = list.begin(); iter != list.end(); iter++) {
            std::cout << "������� �����: ";
            std::cin >> el;
            *iter = el;
        }
        AlgoritmAdjDif(list);
      } break;
      default: {
        std::cout << "������ ������� ���." << std::endl;
      }
    }
  }
}