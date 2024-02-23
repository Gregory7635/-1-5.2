#include <iostream>
#include <stack>
#include <queue>
using namespace std;

void reverseStack(std::stack<int>& numbers) {
    queue<int> tempqueue;

    while (!numbers.empty()) {
        double value = numbers.top();
        numbers.pop();
        tempqueue.push(value);
    }

    while (!tempqueue.empty()) {
        double value = tempqueue.front();
        tempqueue.pop();
        numbers.push(value);
    }
}

int main() {
    std::stack<int> numbers;
    numbers.push(0);
    numbers.push(2);
    numbers.push(1);
    numbers.push(4);
    numbers.push(50);
    numbers.push(15);
    numbers.push(60);
    numbers.push(15);

    std::stack<int> tempStack;
    reverseStack(numbers);
    bool foundt = false;

    // Удаление первого элемента, большего числа 4
    while (!numbers.empty()) {
        if (numbers.top() > 4 and !foundt) {
            numbers.pop();
            foundt = true;
            continue;
        }

        // Вставить число 10 перед каждым числом, равным 15
        if (numbers.top() == 15) {
            tempStack.push(10);
        }

        tempStack.push(numbers.top());
        numbers.pop();
    }

    // Возвращаем числа из временного стека обратно в основной стек
    while (!tempStack.empty()) {
        numbers.push(tempStack.top());
        tempStack.pop();
    }

    // Выводим обновленный список
    while (!numbers.empty()) {
        std::cout << numbers.top() << " ";
        numbers.pop();
    }

    return 0;
}