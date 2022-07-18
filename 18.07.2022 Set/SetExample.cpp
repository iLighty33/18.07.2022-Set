#include <iostream>
#include <vector>
#include <set>
#include <type_traits>
#include <unordered_set> // �����, ����� ���� hash() �������. ����� ��� ������.

// ��� ������ ���������, ����� 100, ������� �� ����� ������.
// � ������� set ����� �������

//�������� seta ������ �����������
// �������� ����� contains � 20�� ���������.

struct Coord {
	//bool operator< (int b);
	int a;
	int b;
	size_t hash();
	bool operator == (const Coord& other) const {
		return a == other.a && b == other.b;
	}
};

// ������� ��� 2�� ������� ����.
namespace std {
	template<> struct less<Coord> {
		bool operator()(const Coord& a, const Coord& b) { // ��������� ������������� ������.
			return (a.a < b.a) && (a.b < b.b);
		}
	};
	template<> struct hash<Coord> {
		size_t operator()(const Coord& coord) {
			return (hash<int>()(coord.a)<<1) ^
				hash<int>()(coord.b);
		}
	};
}

int main() {
	//std::set<int> set{ 1, 2, 1, 2, 3, 4, 5, 6 };
	std::set<Coord> set{
		{1,2},
		{1,2},
		{3,4},
		{5,6}
	};
	/*for (int const& el : set) {
		std::cout << el << '\n';
	}*/
	for (auto&& [i, j] : set) {
		std::cout << i << " " << j << '\n';
	}
	//set.find(7); // ���������� set.end(). ���� ������ �� �����
	//set.size();
	//set.insert(157);
	//set.erase(2);
	//set.contains(4); // �������� ������ � 20� ���������. ���� ��� ���� ����� - true. ��� - false.

	set.size();
	std::less<Coord>()(Coord(), Coord());
	set.find({ 3, 8 });
	set.insert({ 1, 2 });
	set.erase({ 5, 6 });
	set.contains({ 1, 2 });
}