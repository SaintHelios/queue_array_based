#pragma once
#include <iostream>

template <typename T>
class queue {
private:
	T* queue_array;
	T* head;
	T* end;
	size_t array_size;
	size_t next_end_index;
	size_t elements_amount;
public:
	queue(size_t array_size = 10);
	void push(T to_add);
	T pop();
};

template <typename T> queue<T>::queue(size_t array_size) {
	T* head = nullptr;
	T* end = nullptr;
	elements_amount = 0;
	next_end_index = 0;
	this->array_size = array_size;
	queue_array = new T[array_size];
}

template <typename T> void queue<T>::push(T to_add) {
	if (elements_amount == 0) {
		next_end_index = 0;
		queue_array[next_end_index] = to_add;
		head = queue_array;
		end = queue_array;
		++elements_amount;
		++next_end_index;
	}

	else {
		if (end != queue_array + array_size - 1) {
			queue_array[next_end_index] = to_add;
			head = queue_array;
			end = queue_array + next_end_index;
			++elements_amount;
			++next_end_index;
		}
		else {
			if (elements_amount + 1 < array_size) {
				T* copy_to = new T[array_size];
				T* iterator = head;
				for (size_t i = 0; i < elements_amount; ++i) {
					copy_to[i] = *iterator;
					++iterator;
				}
				copy_to[elements_amount] = to_add;
				delete[] queue_array;
				queue_array = copy_to;
				head = queue_array;
				end = queue_array + elements_amount;
				next_end_index = elements_amount + 1;
				++elements_amount;
			}
			else {
				array_size += 20;
				T* copy_to = new T[array_size];
				T* iterator = head;
				for (size_t i = 0; i < elements_amount; ++i) {
					copy_to[i] = *iterator;
					++iterator;
				}
				copy_to[elements_amount] = to_add;
				delete[] queue_array;
				queue_array = copy_to;
				head = queue_array;
				end = queue_array + elements_amount;
				next_end_index = elements_amount + 1;
				++elements_amount;
			}
		}
	}
}

template <typename T> T queue<T>::pop() {
	if (elements_amount == 0) std::cout << "queue is empty " << std::endl;

	else {
		T to_return = *head;
		if (head != end) ++head;
		--elements_amount;
		return to_return;
	}
}