#include <iostream>
#include <thread>
#include <mutex>

void function_1() {
	for (int i{}; i > -100; --i)
		std::cout << "From t1 : " << i << std::endl;
}

int main() {
	std::thread t1(function_1);

	for (int i{}; i < 100; ++i)
		std::cout << "From main: " << i << std::endl;

	t1.join();
}