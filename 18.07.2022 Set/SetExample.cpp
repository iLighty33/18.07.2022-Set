#include <iostream>
#include <vector>
#include <set>
#include <type_traits>
#include <unordered_set> // нужно, чтобы была hash() функция. Нужен для поиска.

// чем больше коллекция, более 100, времени на поиск больше.
// с помощью set поиск быстрее

//Элементы seta всегда константные
// содержит метод contains с 20го стандарта.

struct Coord {
	//bool operator< (int b);
	int a;
	int b;
	size_t hash();
	bool operator == (const Coord& other) const {
		return a == other.a && b == other.b;
	}
};

// Сделано для 2ух строчек кода.
namespace std {
	template<> struct less<Coord> {
		bool operator()(const Coord& a, const Coord& b) { // Принимает универсальные ссылки.
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
	//set.find(7); // возвращает set.end(). Если ничего не нашёл
	//set.size();
	//set.insert(157);
	//set.erase(2);
	//set.contains(4); // Работает только в 20м стандарте. Если там есть число - true. Нет - false.

	set.size();
	std::less<Coord>()(Coord(), Coord());
	set.find({ 3, 8 });
	set.insert({ 1, 2 });
	set.erase({ 5, 6 });
	set.contains({ 1, 2 });
}