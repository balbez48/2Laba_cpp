
#include <ctime>
#include <cmath>
#include <iostream>
#include <string>


//1 задание
double Fraction(double x) {
  return double(x) - int(x);
}

//3 заданиеa
int CharToNum(char x) {
  return (int(x) - int('0'));
}

//5 задание
bool Is2Digits(int x) {
  return (x > 9 && x < 100 || x > -100 && x < -9);
}

//7 задание
bool IsInRange(int a, int b, int num) {
  int temp = 0;
  if (a > b) {
    temp = a;
    a = b;
    b = temp;
  }

  return (num >= a && num <= b);

}
//9 задание
bool IsEqual(int a, int b, int c) {
  return (a == b && b == c);
}

//1 задание 
int Abs(int x) {
  if (x > 0) {
    return x;
  }
  return -x;
}

//3 задание
bool Is35(int x) {
    return (x % 3 == 0) != (x % 5 == 0);
}

//5 задание
int Max3(int x, int y, int z) {
  int max_num = 0;
  if (x > y && x > z) {
    max_num = x;
  } else if (y > x && y > z) {
    max_num = y;
  } else { 
      max_num = z; 
  }

  return max_num;
}

//7 задание 
int Sum2(int x, int y) {
  int sum = x + y;
  if (sum >= 10 && sum <= 20) {
    return 20;
  }
  return sum;
}

//9 задание 
std::string Day(int x) {
  switch (x) {
  case 1: {
    return "Понедельник";
  }
  case 2: {
    return "Вторник";
  }
  case 3: {
    return "Среда";
  }
  case 4: {
    return "Четверг";
  }
  case 5: {
     return "Пятница";
  }
  case 6: {
    return "Суббота";
  }
  case 7: {
    return "Воскресенье";
  }
  default: {
    return "Это не день недели";
  }
  }
}

//1 задание 
std::string ListNums(int x) {
  std::string str = "";
  for (int i = 0; i <= x; i++) {
    str += std::to_string(i) + " ";
  }
  return str;
}

//3 задание
std::string Chet(int x) {
  std::string str = "";
  for (int i = 0; i <= x; i += 2) {
    str += std::to_string(i) + " ";
  }
  return str;
}

//5 задание
int NumLen(int x) {
  int cnt = 0;
  if (x < 0) {
      x *= -1;
  }
  while (x > 0) {
    x /= 10;
    cnt++;
  }
  return cnt;
}

//7 задание
void Square(int x) {
  std::string str = "";
  for (int i = 0; i < x; i++) {
    if (str == "") {
      for (int j = 0; j < x; j++) {
        str += "* ";
      }
    } 
    std::cout << str << std::endl;
  }
}

//9 задание
void RightTriangle(int x) {
  int cnt = 0;
  std::string str = "";
  for (int i = 0; i < x; i++) {
    cnt++;
    for (int i = 0; i < x - cnt; i++) {
        str += "  ";
    }
    for (int j = 0; j < cnt; j++) {
        str += "* ";
    }
    std::cout << str << std::endl;
    str = "";
  }
}

//1 задание 
int FindFirst(int arr[], int x) {
  for (int i = 0; i < 16; i++) {
    if (arr[i] == x) { 
        return i; 
    }
  }

  return -1;
}

//3 задание 
void MaxAbs(int arr[], int sizeArr) {
  int max_abs = abs(arr[0]);
  int max_elem = arr[0];
  int cur_abs = 0;

  for (int i = 1; i < sizeArr; i++) {
    cur_abs = abs(arr[i]);

    if (cur_abs > max_abs) {
      max_abs = cur_abs;
      max_elem = arr[i];
    }
  }
  std::cout << max_elem << " - maxAbs" << std::endl;
}


float CheckFloat(float x) {
  bool flag = 1;
  while (flag) {
    std::cin >> x;
    if (x < 0) {
      std::cout << "Попробуйте снова - ";
    } else { 
        flag = 0; 
    }
  }
  return x;
}

int CheckInt(int x) {
  bool flag = 1;
  while (flag) {
    std::cin >> x;
    if (x < 0) {
      std::cout << "Попробуйте снова - ";
    } else { 
        flag = 0; 
    }
  }

  return x;
}

//int main() {
//  /*setlocale(LC_ALL, "Rus");
//  srand(time(0));
//
//  int flag = 1;
//  int numTask = 0;
//  std::cout << "Нечетные варианты заданий" << std::endl;
//  std::cout << "Первый блок заданий - 1, 2, 3, 4, 5" << std::endl;
//  std::cout << "Второй блок заданий - 6, 7, 8, 9, 10" << std::endl;
//  std::cout << "Третий блок заданий - 11, 12, 13, 14, 15" << std::endl;
//  std::cout << "Четвертый блок заданий - 16, 17, 18, 19, 20" << std::endl;
//
//  while (flag) {
//        
//    std::cout << "\nЧтобы выйти укажите -1" << std::endl;
//    std::cout << "Введите номер задания - ";
//    std::cin >> numTask;
//        
//    if (numTask == -1) { 
//      break; 
//    }
//
//    switch (numTask) {
//      case 1: {
//        double num = 0;
//        std::cout << "-----------------------------------------------------------" << std::endl;
//        std::cout << "Блок 1, Задание 1: Получить дробную часть от числа с точкой" << std::endl;
//        std::cout << "Введите число с точкой - ";
//        std::cin >> num;
//
//        std::cout << "Результат - " << Fraction(num) << std::endl;
//
//      }; break;
//      case 2: {
//
//      char num = '0';
//      std::cout << "-----------------------------------------------------------------------------" << std::endl;
//      std::cout << "Блок 1, Задание 3: Преобразовать один из символов 0 1 2 3 4 5 6 7 8 9 в число" << std::endl;
//      std::cout << "(char) '3' -> (int) 3" << std::endl;
//      std::cout << "Введите символ из следующего списка (0 1 2 3 4 5 6 7 8 9): ";
//      std::cin >> num;
//      std::cout << "Результат - " << CharToNum(num) << std::endl;
//
//      }; break;
//      case 3: {
//
//        int num = 0;
//        std::cout << "---------------------------------------------------------" << std::endl;
//        std::cout << "Блок 1, Задание 5: Проверить является ли число двузначным" << std::endl;
//        std::cout << "Введите число: ";
//        std::cin >> num;
//        
//        std::cout << "Результат - " << std::boolalpha << Is2Digits(num) << std::endl;
//
//      }; break;
//      case 4: {
//
//        int first_lim = 0, second_lim = 0, num = 0;
//        std::cout << "--------------------------------------------------------------------" << std::endl;
//        std::cout << "Блок 1, Задание 7: Проверить входит ли указанное значение в диапазон" << std::endl;
//
//
//        std::cout << "Введите первую границу: ";
//        std::cin >> first_lim;
//        std::cout << "Введите вторую границу: ";
//        std::cin >> second_lim;
//        std::cout << "Введите число: ";
//        std::cin >> num;
//        std::cout << "Результат - " << std::boolalpha << IsInRange(first_lim, second_lim, num) << std::endl;
//
//      }; break;
//      case 5: {
//
//        int first_num = 0, second_num = 0, third_num = 0;
//        std::cout << "------------------------------------------------------------------" << std::endl;
//        std::cout << "Блок 1, Задание 9: Проверить являются ли все три числа одинаковыми" << std::endl;
//
//
//        std::cout << "Введите первое число: ";
//        std::cin >> first_num;
//        std::cout << "Введите второе число: ";
//        std::cin >> second_num;
//        std::cout << "Введите третье число: ";
//        std::cin >> third_num;
//        std::cout << "Результат - " << std::boolalpha << IsEqual(first_num, second_num, third_num) << std::endl;
//
//      }; break;
//      case 6: {
//
//        int num = 0;
//        std::cout << "---------------------------------------" << std::endl;
//        std::cout << "Блок 2, Задание 1: Вернуть модуль числа" << std::endl;
//
//        std::cout << "Введите число: ";
//        std::cin >> num;
//        std::cout << "Результат - " << Abs(num) << std::endl;
//
//      }; break;
//      case 7: {
//
//        int num = 0;
//        std::cout << "-------------------------------------------------------------------------------------------------------------" << std::endl;
//        std::cout << "Блок 2, Задание 3: Проверить делится число на 3 или 5. Если число делится и на 3, и на 5, тогда вернуть false" << std::endl;
//
//        std::cout << "Введите число: ";
//        std::cin >> num;
//        std::cout << "Результат - " << std::boolalpha << Is35(num) << std::endl;
//
//      }; break;
//      case 8: {
//
//        int first_num = 0, second_num = 0, third_num = 0;
//        std::cout << "---------------------------------------------------------------" << std::endl;
//        std::cout << "Блок 2, Задание 5: Вернуть максимальное число из указанных трех" << std::endl;
//
//        std::cout << "Введите первое число: ";
//        std::cin >> first_num;
//        std::cout << "Введите второе число: ";
//        std::cin >> second_num;
//        std::cout << "Введите третье число: ";
//        std::cin >> third_num;
//        std::cout << "Результат - " << Max3(first_num, second_num, third_num) << std::endl;
//
//      }; break;
//      case 9: {
//
//        int first_num = 0, second_num = 0;
//        std::cout << "---------------------------------------------------------------------------------------------" << std::endl;
//        std::cout << "Блок 2, Задание 7: Вернуть сумму чисел. Если сумма входит в диапазон от 10 до 19, вернуть 20." << std::endl;
//
//        std::cout << "Введите первое число: ";
//        std::cin >> first_num;
//        std::cout << "Введите второе число: ";
//        std::cin >> second_num;
//        std::cout << "Результат - " << Sum2(first_num, second_num) << std::endl;
//
//      }; break;
//      case 10: {
//
//        int num = 0;
//        std::cout << "-------------------------------------------------------------------------------------------" << std::endl;
//        std::cout << "Блок 2, Задание 9: Вернуть дни недели в соответсвии их номеру(Понедельник - 1, Пятница - 5)" << std::endl;
//
//        std::cout << "Введите неотрицательное число: ";
//        std::cin >> num;
//        std::cout << "Результат - " << Day(num) << std::endl;
//
//      }; break;
//      case 11: {
//
//        int num = 0;
//        std::cout << "-------------------------------------------" << std::endl;
//        std::cout << "Блок 3, Задание 1: Вернуть строку от 0 до x" << std::endl;
//
//        std::cout << "Введите неотрицательное число: ";
//        num = CheckInt(num);
//        std::cout << "Результат - " << ListNums(num) << std::endl;
//
//      }; break;
//      case 12: {
//
//        int num = 0;
//        std::cout << "-------------------------------------------------------------" << std::endl;
//        std::cout << "Блок 3, Задание 3: Вернуть строку с четными числами от 0 до x" << std::endl;
//
//        std::cout << "Введите неотрицательное число: ";
//        num = CheckInt(num);
//        std::cout << "Результат - " << Chet(num) << std::endl;
//
//      }; break;
//      case 13: {
//
//        int num = 0;
//        std::cout << "-----------------------------------------------------------" << std::endl;
//        std::cout << "Блок 3, Задание 5: Вернуть длину числа" << std::endl;
//
//        std::cout << "Введите число: ";
//        std::cin >> num;
//        std::cout << "Результат - " << NumLen(num) << std::endl;
//
//      }; break;
//      case 14: {
//
//        int num = 0;
//        std::cout << "-------------------------------------------------------------" << std::endl;
//        std::cout << "Блок 3, Задание 7: Вывести квадрат из зведочек размерностью x" << std::endl;
//
//        std::cout << "Введите неотрицательное число: ";
//        num = CheckInt(num);
//        Square(num);
//
//      }; break;
//      case 15: {
//
//        int num = 0;
//        std::cout << "-----------------------------------------------------------------------------------" << std::endl;
//        std::cout << "Блок 3, Задание 9: Вывести треугольник размерностью x и выровнять по правой стороне" << std::endl;
//
//        std::cout << "Введите неотрицательное число: ";
//        num = CheckInt(num);
//        RightTriangle(num);
//
//      }; break;
//      case 16: {
//
//        int num = 0;
//        int array[16]{ 1,1,-1,2,3,-4,4,4,5,34,1,-5,14,6,90 };
//        std::cout << "---------------------------------------------------------------------" << std::endl;
//        std::cout << "Блок 4, Задание 1: Вернуть индекс первого вхождения числа x в массиве" << std::endl;
//
//        std::string str = "";
//        for (int i = 0; i < 16; i++) {
//          str += std::to_string(array[i]) + "(" + std::to_string(i) + ") ";
//        }
//        std::cout << "Массив - " << str << std::endl;
//
//        std::cout << "Введите число: ";
//        std::cin >> num;
//        std::cout << "Результат - " << FindFirst(array, num) << std::endl;
//
//      }; break;
//      case 17: {
//
//        int num = 0;
//        int array[16]{ 1,1,1,-32,3,4,40,4,5,-34,-1,5,-14,-6,90 };
//        std::cout << "--------------------------------------------------------------------------" << std::endl;
//        std::cout << "Блок 4, Задание 3: Найти максимальное значение по модулю числа x в массиве" << std::endl;
//
//        std::string str = "";
//        for (int i = 0; i < 16; i++) {
//          str += std::to_string(array[i]) + " ";
//        }
//        std::cout << "Массив - " << str << std::endl;
//        MaxAbs(array, 16);
//
//      }; break;
//
//      default: { 
//        std::cout << "Такого задания нет" << std::endl; 
//      };
//
//    }
//  }*/
//}
