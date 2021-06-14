#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <time.h>

using std::vector;
using std::cin; using std::cout; using std::endl;

template <typename T>
void PrintVec(vector<T>& arr)
{
	std::for_each(arr.begin(), arr.end(),
		[](T& el)
	{
		cout << el << " ";
	});
	std::cout << std::endl;
}

int RandInt(int min, int max)
{
	//srand(time(0));
	return (rand() % (max - min)) + min;
}
char RandChar()
{
	//srand(time(0));
	char c = 97 + rand() % 26;
	if (rand() % 2)
		c = toupper(c);

	return c;
}
//DONE:
//1)ініціалізація масиву vector з елементами відповідного типу з клавіатури та
//випадковими значеннями з діапазону[-N, N](задається з клавіатури);
//2) для масивів типу char – випадкові літери з діапазону –[A...Z, a...z] – усі
//великі і маленькі літери англійські;
//3) визначення мінімального та максимального значення ВСЬОГО МАСИВУ та
//його ЗАДАНОГО ДІАПАЗОНУ;
//4) сортування масиву за збільшенням;
//5) вставка елементів З ЗАДАНОЇ ПОЗИЦІЇ у масив;
//6) видалення елементів З ЗАДАНОЇ ПОЗИЦІЇ у масив;
//7) сортування ЗАДАНОГО ДІАПАЗОНУ масиву за зменшенням;

//8) визначення на кожному кроці поточного розміру масиву vector;
//9) забезпечити виконання необхідних перетворень, виведення початкового
//масиву та результуючого, після кожного кроку перетворення, а також його
//розміру, з використанням : алгоритму for_each, циклу for на діапазоні
//(range - based for), а також ітераторів вихідного потоку ostream_iterator
//TODO:

int main()
{
//1)ініціалізація масиву vector з елементами відповідного типу з клавіатури та
//випадковими значеннями з діапазону[-N, N](задається з клавіатури);
//2) для масивів типу char – випадкові літери з діапазону –[A...Z, a...z] – усі
//великі і маленькі літери англійські;
	int N;
	cout << "Write size: ";
	cin >> N;
	vector<int> intVec;
	intVec.reserve(N);
	vector<char> charVec;
	charVec.reserve(N);
	
	for (int i = 0; i < N; i++)
	{
		intVec.push_back(RandInt(-N, N+1));
		charVec.push_back(RandChar());
	}
	PrintVec(intVec);
	PrintVec(charVec);

	//3) визначення мінімального та максимального значення ВСЬОГО МАСИВУ та
	//його ЗАДАНОГО ДІАПАЗОНУ;

	auto minmax_int = std::minmax_element(intVec.begin(), intVec.end());
	auto minmax_char = std::minmax_element(charVec.begin(), charVec.end());
	cout << "Min Integer: " << *minmax_int.first << "; Max Integer: " << *minmax_int.second
		<< "; \nMin character: " << *minmax_char.first << "; Max Character: " << *minmax_char.second << '\n';

	int d0, d1;
	cout << "Choose range for min in int vec: ";
	cin >> d0;
	cin >> d1;

	minmax_int = std::minmax_element(intVec.begin() + d0, intVec.begin() + d1);

	cout << "Min Integer: " << *minmax_int.first << "; Max Integer: " << *minmax_int.second << '\n';

	cout << "Choose range for min in char vec: ";
	cin >> d0;
	cin >> d1;

	minmax_char = std::minmax_element(charVec.begin() + d0, charVec.begin() + d1);

	cout << "\nMin character: " << *minmax_char.first << "; Max Character: " << *minmax_char.second << '\n';

	cout << endl;

	//4) сортування масиву за збільшенням;
	std::sort(intVec.begin(), intVec.end());
	cout << "sorted int vec: ";
	PrintVec(intVec);

	std::sort(charVec.begin(), charVec.end());
	cout << "sorted char vec: ";
	PrintVec(charVec);

	//5) вставка елементів З ЗАДАНОЇ ПОЗИЦІЇ у масив;
	cout << "=======insert=========" << endl;
	auto Intit = intVec.begin();
	auto Charit = charVec.begin();
	int pos;
	cout << "enter position in which insert integer: ";
	cin >> pos;
	std::advance(Intit, pos);
	int number;
	char letter;
	cout << "enter integer which insert: ";
	cin >> number;
	intVec.insert(Intit, number);
	cout << "changed vector" << endl;
	PrintVec(intVec);
	cout << "------------" << endl;
	cout << "enter position in which insert letter: ";
	cin >> pos;
	std::advance(Charit, pos);
	cout << "enter letter which insert: ";
	cin >> letter;
	charVec.insert(Charit, letter);
	cout << "changed vector" << endl;
	PrintVec(charVec);
	//6) видалення елементів З ЗАДАНОЇ ПОЗИЦІЇ у масив;
	cout << "======erase=========" << endl;
	Intit = intVec.begin();
	Charit = charVec.begin();
	cout << "enter position from which erase integer: ";
	cin >> pos;
	std::advance(Intit, pos);
	intVec.erase(Intit);
	cout << "changed vector" << endl;
	PrintVec(intVec);
	cout << "------------" << endl;
	cout << "enter position from which erase letter: ";
	cin >> pos;
	std::advance(Charit, pos);
	charVec.erase(Charit);
	cout << "changed vector" << endl;
	PrintVec(charVec);
	


}