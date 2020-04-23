#include <iostream>
#include <queue>
#include <random>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;

const int32_t MAX_COUNTER = 50;

queue<int32_t> collection;
mutex simple_mutex;
int32_t counter;

void prepare_data()
{

	default_random_engine random_engine(rand() % 10);
	uniform_int_distribution<int32_t> int_distribution(10, 1000);
	int32_t value = int_distribution(random_engine);
	unique_lock<mutex> lock(simple_mutex);

	collection.push(value);
	this_thread::sleep_for(chrono::milliseconds(value));
	lock.unlock();

	++counter;

	if (counter >= MAX_COUNTER)
	{
		return;
	}

	prepare_data();

}

void extract_data()
{

	while (collection.empty())
	{
	}

	unique_lock<mutex> lock(simple_mutex);

	cout << "Value: " << collection.back() << endl;

	collection.pop();
	lock.unlock();

	if (counter >= MAX_COUNTER)
	{
		return;
	}

	extract_data();

}

int32_t main(const int32_t argc, const char* const argv[])
{
	
	thread prepare_thread(prepare_data);
	thread extract_thread(extract_data);

	prepare_thread.join();
	extract_thread.join();

	return EXIT_SUCCESS;

}
