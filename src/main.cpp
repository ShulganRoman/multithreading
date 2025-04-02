#include "../src/user/TestUser.h"
#include <iostream>

std::atomic<size_t> TestUser::userId{0};

int main() { std::cout << "hello, world!"; }
