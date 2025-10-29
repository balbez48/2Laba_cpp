
#include "Laba2.h"

//���� ������ V, ��� D � ������ L. ������ �������� ��������� �������� �� ����� ���� ���������, 
//���������� ��������� �������� ��������.������� �������� �������, �������� � ����������
//�������� ������� �� �������� �����������.
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

//���� ������ V � ������ L.������ �������� ��������� �������� �� ����� 5 ���������.
//�������� ����� �������� ������ � ���������� ������� 5 ������ 5 ��������� ������� �
//�������� �������.������������ ���� ����� ������� - ����� insert.
void InsVectList(std::vector<int> ins_vect, std::list<int> &list) {
  auto iter_list = list.begin();
  iter_list = std::next(list.begin(), 5); //���������� �������� �� 6 ���
  
  std::vector<int> left_side(5); //������ ������ �� 5 ���������
  
  //��������� ����� ������ ���������� ������� �� 5 ��������
  for (int i = 0; i < 5; i++) {
      left_side[i] = ins_vect[i];
  }

  //�������� �������� �� 6 ������� � �� ���� ���������� ������� ������� � �������� �������
  list.insert(iter_list, left_side.rbegin(), left_side.rend());
  

  for (auto it_list = list.begin(); it_list != list.end(); it_list++) {
    std::cout << *it_list << " ";
  }
    
}

//��� ��� D � ����������� ���������, ������� 4. ������� � ������ �������� ��������� ���� ���
//�������� � ������� ����������� ��������(������, ��� ��������� ������� ���� �����
//���������� ����� 1).������������ ������� - ���� erase � ����� � �������� ����������.
//��������.����������� ���� � �������� ����������, ������������� N / 4 ���(��� N �
//�������� ������ ����).������� ��������������� �������� i � ������� ����.� �����
//���������� ������� - ���� erase � ����������, ������ ++i, ����������� ����������
//������������ �������� ��������� i.
void DelDeque4(std::deque<int> &deque) {
  int n = deque.size();
  auto iter = deque.begin();

  for (int i = 0; i < n / 4; i++) {
    iter = deque.erase(++iter);
  }

  std::cout << "���������" << std::endl;
  for (auto iter_deq = deque.begin(); iter_deq != deque.end(); iter_deq++) {
    std::cout << *iter_deq << " ";
  }
}

//��� ����� ������������ �����, ���������� �� ����� ���� ���������.������� ����� ��
//��������� ������ � ������� ����������� ��������(�.�.������ �����, ��������� ����� � �.
//�.).������������ �������� remove_copy_if.
void RemoveCopyIf() {

  std::cout << "��� ������ ������� ctrl+z." << std::endl;
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

//��� ������ L, ���������� ��� �������������, ��� � ������������� ��������.��������
//������� ������� ����� ������� �������������� �������� � ����� ��������� �������������
//���������.������������ ��� ������ ��������� find_if � ��� ������ ������� - ����� insert.
//��������. �������� find ����� ���������� �������� ��������, ������ �������-���� erase �� 
//��������� ��� ������������ ��� �������� ��������.���������� ������� �� ���������
//��������� r � ���������� � ��� �������� ���������, ��������� ������� - ���� ���������
//��������� r.base().��� ���� ������� ���������, ��� ������� r.base() ���������� ��������,
//��������� � ���������, ��������� �� ���, � ������� ������ �������� �������� r.������� �
//������� - ����� erase ������� ������� ���� �� ��������� ���������(��������������, ��� r �
//��� �������� ��������, ������� ������ �������� find, � ���� �������� ������� �� rend) : -
//r.base() ���(++r).base().
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



//6.14 ��� ������ V � ������ ����������� ���������.������ ��� ���� ������ 6.13.���������
//�������� ������� � ������ ������� ������ ��� ��� ��������� �����������������, ��� �������
//������ ������������ ��������������� ������ V0.���������������� ������ V0 ������
//��������� ��������� ������� V, ����� ���� ��������� �������� remove_copy_if, ���������
//������ V0 ��� ��������, � ������ V ��� �������� ������.
// 
//6.13 ����������� � ������ ������� ���
//������������� ��������, ������������� � ��� ������ ��������, �������� ��� ��� ��������
//������� ����������.

void VectRemCopIf(std::vector<int>& vect){
  int n = vect.size() / 2;
  std::vector<int> v0(vect.begin() + n, vect.end());//�����������
  
  std::remove_copy_if(v0.begin(),
                      v0.end(),
                      vect.begin(),
                      [](int x) {
                        return x <= 0;
                      }
  );
  
  std::cout << "���������" << std::endl;
  for (auto it_list = vect.begin(); it_list != vect.end(); it_list++) {
      std::cout << *it_list << " ";
  }
  

}


//7.11 ��� ��� D, ���������� �������� �������� ���������� �����.������������� ��� �������� ��
//�������� �� ����, � �������� ���������� ����� � � ���������� �������.������������
//������������ ����� ��������� sort � ���������� � �������������� ��������, ����������
//��� ��������� �����, ��� � ��������� �� ����.
void DeqEnglishWords(std::deque<std::string> &deq) {
    std::sort(deq.begin(), 
              deq.end(), 
              [](std::string left, std::string right) {
              if (left.length() != right.length()) {
                return left.length() > right.length();
              }
              return left < right;
    });

    std::cout << "���������: " << std::endl;
    for (auto it_deq = deq.begin(); it_deq != deq.end(); it_deq++) {
       std::cout << *it_deq << " ";  
    }
}




//8.1
//��� ������ L.�������� ������ V ������������ �����, ���������� �������� ��������
//��������������� ��� ���� ��� �������� ��������� ��������� ������(���������� ���������
//������� V ������ ���� �� 1 ������ ���������� ��������� ������ L).��������, ��� ���������
//������ 1, 3, 4, 6 ���������� ������ ������ ��������� �������� 2.0, 3.5, 5.0.������������
//�������� adjacent_difference � ���������� ������� � �������������� ��������, � �����
//������� - ���� erase ��� ������� V.

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

    V.erase(V.begin()); //������� ������ �������, ������� ������������

    std::cout << "���������: " << std::endl;
    for (auto iter = V.begin(); iter != V.end(); iter++) {
        std::cout << *iter << " ";
    }
}



//9.1. ��� ������ V0, ����� ����� N (> 0) � ����� �������� V1, �, VN. ��������, ��� ������ ������� V0 
//�� ����������� ������� ������ �� �������� V1, �, VN. ����� ���������� �������� VI, I = 1, �, N, 
//� ������� ���������� ��� �������� ������� V0 (��� ����� �� ����������). ������������ 
//�������� includes, �������� ��� � ����� � ���� ����������, ���� �� ������� ������� �� ������ 
//������� V0, � ������ �� ��������� �������� �������� �������� ���������� �� �������� VI, I = 
//1, �, N.
void VectorsIncludeInVect(std::vector<int> v0, std::vector<std::vector<int>> vects) {

  int cnt = 0;
  std::set<int> v0_set(v0.begin(), v0.end());
  for (auto vect : vects) {
    std::set<int> cur_set(vect.begin(), vect.end());
    if (std::includes(cur_set.begin(), cur_set.end(), v0_set.begin(), v0_set.end())) {
      cnt++;
    }
  }

  std::cout << "���������� ��������, ������� ���������� v0 - " << cnt << std::endl;
}


//10.2 ��� ������ V, ���������� �������� �������� ���������� �����, ��������� ����������
//�������.���������� ��������� ����� ����, ������������ � ����� � ��� �� �����, � �������
//��� ��������� �����, � ������� ���������� �������� ������� V, ������ � ��������� ������
//���� ���������(� ���������� ������� ����); ����� �������� ����� ����� ���������������
//�����.������������ ��������������� ����������� M, ������� �������� �������� ���������
//����� ��������� ������� V, � ���������� � ��������� ����� ���� ���������.��� ����������
//����������� M �� ������������ �������� �����������(���������� �������� ��������������
//[], ���������� � ������� - ����� size ��� �����).�������� ������� V(��� ����������
//����������� M) � �������� ����������� M(��� ������ ���������� �����������) ����������
//� ����� � ���������� - ���������� ���������������� ����������.
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