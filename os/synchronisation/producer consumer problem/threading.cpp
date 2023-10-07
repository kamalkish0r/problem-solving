#include <iostream>
#include <thread>
#include <chrono>

// using namespace std;
// using namespace std::chrono;

const int n = 1e9;
long long sum_e = 0, sum_o = 0;

void even_sum() {
	for (int i = 2; i <= n; i += 1) {
		sum_e += i;
	}
}

void odd_sum() {
	for (int i = 1; i <= n; i += 1) {
		sum_o += i;
	}
}

int main() {
	std::chrono::high_resolution_clock::time_point start_time = std::chrono::high_resolution_clock::now();
	std::thread t1(even_sum);
	std::thread t2(odd_sum);

	t1.join();
	t2.join();

	std::chrono::high_resolution_clock::time_point end_time = std::chrono::high_resolution_clock::now();
	std::chrono::microseconds duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time); 

	std::cout << "even sum : " << sum_e << "\n";
	std::cout << "odd sum : " << sum_o << "\n";
	std::cout << "Time Taken : " << duration.count() << "\n";

	return 0;
}
