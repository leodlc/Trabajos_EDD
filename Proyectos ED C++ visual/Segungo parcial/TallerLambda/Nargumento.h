#pragma once
#include <iostream>
template<typename C,
    typename T = std::decay_t<decltype(*begin(std::declval<C>()))>,
    typename = std::enable_if_t<std::is_convertible_v<T, int>>
>
int calcularMaxDivNargs(C const& list) {
    std::vector<int> vec = { list.begin(), list.end() };
    int result = vec.at(0);

    vec.erase(vec.begin());

    for (auto i : vec) {
        result = (((i * result)) / (gcd(i, result)));
    }

    return result;
}
template <typename... Args>
int calcularMaxDivNargs(Args... args) {
    return calcularMaxDivNargs(vector<int>{args...});
}