#include <iostream>
#include <thread>

class Fctor {
public:
	void operator()(std::string&& msg) {
		std::cout << "t1 says: " << msg << std::endl;
		msg = "I just changed my string";
	}
};

int main() {

	std::string s = "Created a string";
	std::cout << std::this_thread::get_id() << std::endl;
	std::thread t1((Fctor()), std::move(s)); //t1 starts running
	std::cout << t1.get_id() << std::endl;

	std::thread t2 = std::move(t1);
	t2.join();

	std::cout << s << std::endl;
}
