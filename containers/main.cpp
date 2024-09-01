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

int main () {
    // vector<point, Stack_alloc<point>> vec = {{0, 0}, {1, 2}, {3, 4}, {5, 6}};
    // print_vec(vec);
    // vec.emplace_back(10, 100);
    // print_vec(vec);
	my_deque<int> deq(10, 111);
    // std::for_each(deq.begin(), deq.end(), [](const int val) {std::cout << val << ' ';});
    // std::cout << '\n';
    vector<int, Stack_alloc<int>> vec = {1, 2, 3, 4, 5, 6, 7, 8};
    print_vec(vec);
    vec.push_back(1000);
    print_vec(vec);
    vec.pop_back();
    vec.pop_back();
    vec.pop_back();
    print_vec(vec);
}

void __attribute__((destructor)) __exit__ () {
	system("leaks a.out");
}