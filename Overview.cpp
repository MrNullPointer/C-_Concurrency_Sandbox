#include<iostream>
#include<thread>


void func1() {
	std::cout << "Hello!" << std::endl;
}

int main() {
	std::thread t1(func1); //t1 starts running
	//t1.join(); //main thread waits for t1 to finish
	t1.detach(); //t1 will run freely on its own -- daemon process

	if (t1.joinable()) {
		t1.join(); 
	}
}