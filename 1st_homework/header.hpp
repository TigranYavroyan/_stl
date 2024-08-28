#ifndef HEADER_HPP
#define HEADER_HPP

#include <iostream>
#include <string>

using fptr = std::string(*)();

std::string __sep ();
std::string __end ();

template <fptr SEP = __sep, fptr END = __end, typename... Ts>
void print (Ts... args);

template <typename... Ts>
int sum (Ts... args);

template <typename... Ts>
int mul (Ts... args);

#include "helpers.cpp"

#endif // HEADER_HPP