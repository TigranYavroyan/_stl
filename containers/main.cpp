#include <header.h>

using std::vector;

template <typename T, typename Alloc>
void print_vec(const vector<T, Alloc>& vec) {
    if (vec.empty()) return;
    for (const auto& val : vec) {
        std::cout << val << ' ';
    }
    std::cout << '\n';
}

struct point {
    int x{};
    int y{};
};

std::ostream& operator<< (std::ostream& os, const point& p) {
    return os << p.x << ' ' << p.y;
}

template <typename T>
void print (const T& ob) {
    std::for_each(ob.begin(), ob.end(), [](const int val) {std::cout << val << ' ';});
    std::cout << '\n';
}

int main () {
    // vector<point, Stack_alloc<point>> vec = {{0, 0}, {1, 2}, {3, 4}, {5, 6}};
    // print_vec(vec);
    // vec.emplace_back(10, 100);
    // print_vec(vec);
	my_deque<int> deq = {1, 2, 3, 4, 5, 6, 7};
	my_deque<int> deq2;
    print(deq);
    // print(deq2);
    // vector<int, Stack_alloc<int>> vec = {1, 2, 3, 4, 5, 6, 7, 8};
    // print_vec(vec);
    // vec.push_back(1000);
    // print_vec(vec);
    // vec.pop_back();
    // vec.pop_back();
    // vec.pop_back();
    // print_vec(vec);
}

// void __attribute__((destructor)) __exit__ () {
// 	system("leaks a.out");
// }