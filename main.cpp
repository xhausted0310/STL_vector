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
//1)����������� ������ vector � ���������� ���������� ���� � ��������� ��
//����������� ���������� � ��������[-N, N](�������� � ���������);
//2) ��� ������ ���� char � �������� ����� � �������� �[A...Z, a...z] � ��
//����� � ������� ����� ��������;
//3) ���������� ���������� �� ������������� �������� ������ ������ ��
//���� �������� Ĳ�������;
//4) ���������� ������ �� ����������;
//5) ������� �������� � �����ί ����ֲ� � �����;
//6) ��������� �������� � �����ί ����ֲ� � �����;
//7) ���������� �������� Ĳ������� ������ �� ����������;

//8) ���������� �� ������� ����� ��������� ������ ������ vector;
//9) ����������� ��������� ���������� �����������, ��������� �����������
//������ �� �������������, ���� ������� ����� ������������, � ����� ����
//������, � ������������� : ��������� for_each, ����� for �� �������
//(range - based for), � ����� ��������� ��������� ������ ostream_iterator
//TODO:

int main()
{
//1)����������� ������ vector � ���������� ���������� ���� � ��������� ��
//����������� ���������� � ��������[-N, N](�������� � ���������);
//2) ��� ������ ���� char � �������� ����� � �������� �[A...Z, a...z] � ��
//����� � ������� ����� ��������;
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

	//3) ���������� ���������� �� ������������� �������� ������ ������ ��
	//���� �������� Ĳ�������;

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

	//4) ���������� ������ �� ����������;
	std::sort(intVec.begin(), intVec.end());
	cout << "sorted int vec: ";
	PrintVec(intVec);

	std::sort(charVec.begin(), charVec.end());
	cout << "sorted char vec: ";
	PrintVec(charVec);

	//5) ������� �������� � �����ί ����ֲ� � �����;
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
	//6) ��������� �������� � �����ί ����ֲ� � �����;
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