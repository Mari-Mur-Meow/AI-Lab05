/*������� ����� ��8-25
������� 14. ������������ ������ 5
������� 4 �� 
���������� ����������� ������ ���������� � ������ � ������� ���������
 std::copy. � ����� ���������� �������� � �������� ����������, ��� ������� list ���
 ���������� ������������ ����� list::sort ��� ����������, ��� ������� vector ��� deque
 ��� ���������� ������������ �������� std::sort � ����� �����������: �������� �� ������
 � �������� �� ����� ����������

������-�����(����: ��� ������, ��������, ������������, ��� �������, ����� �������)
���������� �� ���
�������� ��������� deque, �������� � list
*/

#include "Source.cpp"
#include <deque>
#include <list>
#include <fstream>
#include <set>
#include <unordered_set>
#include <algorithm>

int main() {
	//std::deque<Book> book_deq;
	std::list<Book> book_list;
	std::unordered_set<Book,BookHasher> un_setBook;
	std::set<Book> setBook;

	std::ifstream in("input.txt");
	for (int i = 0; i < 4; i++) {
		std::string fio, name, publish;
		int year, pages;
		getline(in, fio);
		getline(in, name);
		getline(in, publish);
		in >> year >> pages;
		in.ignore();
		un_setBook.insert(Book(fio, name, publish, year, pages));
		setBook.insert(Book(fio, name, publish, year, pages));
		//std::cout << fio<< " / "<< name << " / "<< publish << " / " << year << " / " << pages << " / "<< "\n";
	}
	in.close();

	std::ofstream of("output.txt");
	of << " unsetBook" << "\n";
	for (const auto& elem : un_setBook) {
		of << elem;
	}

	of << "\n"<< "setBook" << "\n";
	for (const auto& elem : setBook) {
		of << elem;
	}

	copy(un_setBook.begin(), un_setBook.end(), std::back_inserter(book_list));

	of << "\n" << " List" << "\n";
	for (const auto& elem : book_list) {
		of << elem;
	}
	return 0;

	
}