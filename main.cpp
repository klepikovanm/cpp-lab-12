#include <iostream>
#include <vector>
#include <list>
#include <deque>
using namespace std;

//Итераторы в C++ - это объекты, которые используются для обхода элементов внутри контейнеров или последовательностей. Они предоставляют абстракцию, позволяющую оперировать элементами в контейнерах без необходимости знать внутреннюю структуру данных.

template <typename T>
class Range_iterator{
private:
    typename T::iterator begin; //необходимо использовать ключевое слово typename, чтобы сообщить компилятору, что iterator является типом внутри шаблона T
    typename T::iterator end;
public:
    Range_iterator(typename T::iterator r_begin, typename T::iterator r_end) {
        begin = r_begin;
        end = r_end;
    }
    Range_iterator& operator++() {//символ & используется для перегрузки операторов, которые требуют возвращения ссылки на объект
        ++begin;
        return *this;//возвращаем измененный объект-итератор
    }
    Range_iterator& operator--() {
        --begin;
        return *this;

    }
    //используем typename T::value_type для обращения к типу элемента: который хранится в контейнере типа Т. Для контейнеров правильным типом элементов является T::value_type
    typename T::value_type& operator*() {//В перегрузке оператора разыменования operator*, возвращается ссылка (используется символ &), чтобы точно указать, что возвращается не копия значения, на которое указывает итератор, а само значение по этому указателю.
        return *begin;
    }
    void print(){
        typename T::iterator start = begin;//чтоб begin не изменял значение; можно выводить много раз
        while(start != end){
            cout << *start << " ";
            ++start;
        }
        cout << endl;
    }
    bool operator!=(const Range_iterator & other) {
        return begin != other.begin;
    }

};

int main() {
    vector<string> first = {"one", "two", "three", "four", "five"};
    cout << '\v';
    Range_iterator<vector<string>> first_one(first.begin(), first.end());
    first_one.print();
    cout << '\v';
   
    list<float> second = {2.9, -10.1, 7.9, 2, 0.1, -8};
    Range_iterator<list<float>> second_start(second.begin(), second.end());
    Range_iterator<list<float>> second_finish(second.end(), second.end());
    second_start.print();
    int k=2;
    --second_finish;
    while (k!=0) {
        ++second_start;
        k--;
    }
    second_start.print();//вывод с третьего элемента
    while (second_start != second_finish) {//вывод с третьего элемента до предпоследнего
        cout << *second_start << " ";
        ++second_start;
    }
    cout << endl << '\v';

    deque<int> third = {2, 3, 9};
    Range_iterator<deque<int>> third_start(third.begin(), third.end());
    Range_iterator<deque<int>> third_finish(third.end(), third.end());
    third_start.print();
    while(third_start != third_finish) {
        *third_start+=2;
        cout << *third_start << " ";
        ++third_start;
    }
    cout << endl << '\v';
    

    return 0;
}