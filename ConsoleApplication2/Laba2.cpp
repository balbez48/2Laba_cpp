
#include "Laba2.h"

//Даны вектор V, дек D и список L. Каждый исходный контейнер содержит не менее трех элементов, 
//количество элементов является нечетным.Удвоить значения первого, среднего и последнего
//элемента каждого из исходных контейнеров.
void MulConteiner(std::vector<int> &vect, std::deque<int> &deque, std::list<int> &list) {

  int middle_vect = vect.size() / 2;
  for (int i = 0; i < vect.size(); i++) {
    if (i == 0 || i == vect.size() - 1 || i == middle_vect) {
      vect[i] = 2 * vect[i];
    }
  }

  int middle_deq = deque.size() / 2;
  for (int i = 0; i < deque.size(); i++) {
    if (i == 0 || i == deque.size() - 1 || i == middle_deq) {
      deque[i] = 2 * deque[i];
    }
  }

  int middle_list = list.size() / 2;
  int count = 0;
  for (int &value : list) {
    if (count == 0 || count == list.size() - 1 || count == middle_list) {
       value = 2 * value;
    }
    count++;
  }    
}

//Даны вектор V и список L.Каждый исходный контейнер содержит не менее 5 элементов.
//Вставить после элемента списка с порядковым номером 5 первые 5 элементов вектора в
//обратном порядке.Использовать один вызов функции - члена insert.
void InsVectList(std::vector<int> ins_vect, std::list<int> &list) {
  auto iter_list = list.begin();
  iter_list = std::next(list.begin(), 5); //перемещаем итератор на 6 поз
  
  std::vector<int> left_side(5); //пустой вектор на 5 элементов
  
  //заполняем новый вектор значениями старого до 5 элемента
  for (int i = 0; i < 5; i++) {
      left_side[i] = ins_vect[i];
  }

  //итератор указвает на 6 позицию и от туда происходит вставка вектора в обратном порядке
  list.insert(iter_list, left_side.rbegin(), left_side.rend());
  

  for (auto it_list = list.begin(); it_list != list.end(); it_list++) {
    std::cout << *it_list << " ";
  }
    
}

//Дан дек D с количеством элементов, кратным 4. Удалить в первой половине исходного дека все
//элементы с четными порядковыми номерами(считая, что начальный элемент дека имеет
//порядковый номер 1).Использовать функцию - член erase в цикле с числовым параметром.
//Указание.Используйте цикл с числовым параметром, повторяющийся N / 4 раз(где N —
//исходный размер дека).Свяжите вспомогательный итератор i с началом дека.В цикле
//выполняйте функцию - член erase с параметром, равным ++i, обязательно присваивая
//возвращаемое значение итератору i.
void DelDeque4(std::deque<int> &deque) {
  int n = deque.size();
  auto iter = deque.begin();

  for (int i = 0; i < n / 4; i++) {
    iter = deque.erase(++iter);
  }

  std::cout << "Результат" << std::endl;
  for (auto iter_deq = deque.begin(); iter_deq != deque.end(); iter_deq++) {
    std::cout << *iter_deq << " ";
  }
}

//Дан набор вещественных чисел, содержащий не менее двух элементов.Вывести числа из
//исходного набора с четными порядковыми номерами(т.е.второе число, четвертое число и т.
//д.).Использовать алгоритм remove_copy_if.
void RemoveCopyIf() {

  std::cout << "Для выхода нажмите ctrl+z." << std::endl;
  std::istream_iterator<float> start(std::cin);
  std::istream_iterator<float> end;
  std::ostream_iterator<float> output(std::cout, " ");
    
  int position = 1;

  std::remove_copy_if(start,
                      end,
                      output,
                      [&position](float x) {
                        bool remove = position % 2;
                        position++;
                        return remove;
                      }
  );  
  std::cin.clear();
}

//Дан список L, содержащий как отрицательные, так и положительные элементы.Вставить
//нулевой элемент после первого отрицательного элемента и перед последним положительным
//элементом.Использовать два вызова алгоритма find_if и два вызова функции - члена insert.
//Указание. Алгоритм find может возвращать обратный итератор, однако функция-член erase не 
//позволяет его использовать для удаления элемента.Необходимо перейти от обратного
//итератора r к связанному с ним обычному итератору, используя функцию - член обратного
//итератора r.base().При этом следует учитывать, что функция r.base() возвращает итератор,
//связанный с элементом, следующим за тем, с которым связан обратный итератор r.Поэтому в
//функции - члене erase следует указать одно из следующих выражений(предполагается, что r —
//это обратный итератор, который вернул алгоритм find, и этот итератор отличен от rend) : -
//r.base() или(++r).base().
void InsertElemList(std::list<int> &list) {
  int first_elem = list.front();
  auto iter_list_negative = std::find_if(list.begin(), 
                                         list.end(), 
                                         [](int n) { 
                                           return n < 0; 
                                         });
  if (iter_list_negative != list.end()) {
    iter_list_negative++;
    list.insert(iter_list_negative, first_elem);
  }

  auto iter_list_positive = std::find_if(list.rbegin(),
                                         list.rend(),
                                         [](int n) {
                                           return n > 0;
                                         });
  if (iter_list_positive != list.rend()) {
    iter_list_positive++;
    list.insert(iter_list_positive.base(), first_elem);
  }

  for (auto it_list = list.begin(); it_list != list.end(); it_list++) {
      std::cout << *it_list << " ";
  }

}



//6.14 Дан вектор V с четным количеством элементов.Решить для него задачу 6.13.Поскольку
//операция вставки в начало вектора делает все его итераторы недействительными, для решения
//задачи использовать вспомогательный вектор V0.Инициализировать вектор V0 второй
//половиной элементов вектора V, после чего применить алгоритм remove_copy_if, используя
//вектор V0 как источник, а вектор V как приемник данных.
// 
//6.13 Скопировать в начало вектора все
//положительные элементы, расположенные в его второй половине, сохранив для них исходный
//порядок следования.

void VectRemCopIf(std::vector<int>& vect){
  int n = vect.size() / 2;
  std::vector<int> v0(vect.begin() + n, vect.end());//скопировали
  
  std::remove_copy_if(v0.begin(),
                      v0.end(),
                      vect.begin(),
                      [](int x) {
                        return x <= 0;
                      }
  );
  
  std::cout << "Результат" << std::endl;
  for (auto it_list = vect.begin(); it_list != vect.end(); it_list++) {
      std::cout << *it_list << " ";
  }
  

}


//7.11 Дан дек D, элементами которого являются английские слова.Отсортировать его элементы по
//убыванию их длин, а элементы одинаковой длины — в алфавитном порядке.Использовать
//единственный вызов алгоритма sort с параметром — функциональным объектом, включающим
//как сравнение строк, так и сравнение их длин.
void DeqEnglishWords(std::deque<std::string> &deq) {
    std::sort(deq.begin(), 
              deq.end(), 
              [](std::string left, std::string right) {
              if (left.length() != right.length()) {
                return left.length() > right.length();
              }
              return left < right;
    });

    std::cout << "Результат: " << std::endl;
    for (auto it_deq = deq.begin(); it_deq != deq.end(); it_deq++) {
       std::cout << *it_deq << " ";  
    }
}




//8.1
//Дан список L.Получить вектор V вещественных чисел, содержащий значения среднего
//арифметического для всех пар соседних элементов исходного списка(количество элементов
//вектора V должно быть на 1 меньше количества элементов списка L).Например, для исходного
//списка 1, 3, 4, 6 полученный вектор должен содержать значения 2.0, 3.5, 5.0.Использовать
//алгоритм adjacent_difference с итератором вставки и функциональным объектом, а также
//функцию - член erase для вектора V.

void AlgoritmAdjDif(std::list<int>& list) {

    int n = list.size();
    std::vector<float> V(n);

    std::adjacent_difference(list.begin(),
                             list.end(),
                             V.begin(),
                             [](int a, int b) {
                               return (a + b) / 2.0;
                             }
    );

    V.erase(V.begin()); //удалили первый элемент, который скопировался

    std::cout << "Результат: " << std::endl;
    for (auto iter = V.begin(); iter != V.end(); iter++) {
        std::cout << *iter << " ";
    }
}



//9.1. Дан вектор V0, целое число N (> 0) и набор векторов V1, …, VN. Известно, что размер вектора V0 
//не превосходит размера любого из векторов V1, …, VN. Найти количество векторов VI, I = 1, …, N, 
//в которых содержатся все элементы вектора V0 (без учета их повторений). Использовать 
//алгоритм includes, применяя его в цикле к двум множествам, одно из которых создано на основе 
//вектора V0, а другое на очередной итерации содержит элементы очередного из векторов VI, I = 
//1, …, N.
void VectorsIncludeInVect(std::vector<int> v0, std::vector<std::vector<int>> vects) {

  int cnt = 0;
  std::set<int> v0_set(v0.begin(), v0.end());
  for (auto vect : vects) {
    std::set<int> cur_set(vect.begin(), vect.end());
    if (std::includes(cur_set.begin(), cur_set.end(), v0_set.begin(), v0_set.end())) {
      cnt++;
    }
  }

  std::cout << "Количество векторов, которые содержатся v0 - " << cnt << std::endl;
}


//10.2 Дан вектор V, элементами которого являются английские слова, набранные заглавными
//буквами.Определить суммарную длину слов, начинающихся с одной и той же буквы, и вывести
//все различные буквы, с которых начинаются элементы вектора V, вместе с суммарной длиной
//этих элементов(в алфавитном порядке букв); длину выводить сразу после соответствующей
//буквы.Использовать вспомогательное отображение M, ключами которого являются начальные
//буквы элементов вектора V, а значениями — суммарная длина этих элементов.При заполнении
//отображения M не использовать условные конструкции(достаточно операций индексирования
//[], инкремента и функции - члена size для строк).Элементы вектора V(при заполнении
//отображения M) и элементы отображения M(при выводе полученных результатов) перебирать
//в цикле с параметром - итератором соответствующего контейнера.
void CountLetterInWords(std::vector<std::string> vect) {
  std::map<char, int> M;

  for (auto iter = vect.begin(); iter != vect.end(); iter++) {
      char letter = (*iter)[0];
      M[letter] += (*iter).size();
  }
  for (auto iter = M.begin(); iter != M.end(); iter++) {
    std::cout << (*iter).first << " " << (*iter).second << std::endl;
  }
}