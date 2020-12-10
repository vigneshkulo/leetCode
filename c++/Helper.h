#include <iostream>
#include <unordered_map>

class Helper {
	public:
		template<typename K, typename V>
		static void print_map(std::unordered_map <K, V> const &hash_map) {
			std::cout << "[";
			for (auto item : hash_map) {
				std::cout << "{" << item.first << ": " << item.second << "}";
			}
			std::cout << "]" << std::endl;
		}

		template<typename K>
		static void print_vector(std::vector <K> const &list) {
			std::cout << "[ ";
			for (auto item : list) {
				std::cout << item << " ";
			}
			std::cout << "]" << std::endl;
		}
};

