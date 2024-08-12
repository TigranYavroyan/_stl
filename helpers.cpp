#include <header.hpp>

std::string __sep () {
    return " ";
}

std::string __end () {
    return "\n";
}

template <fptr SEP = __sep, fptr END = __end, typename... Ts>
void print (Ts... args) {
    ((std::cout << args << SEP()), ...) << END();
}

template <typename... Ts>
int sum (Ts... args) {
    return ((args) + ...);
}

template <typename... Ts>
int mul (Ts... args) {
    return ((args) * ...);
}