#include <bits/stdc++.h>
using namespace std;

struct Stack {
    int top;
    int capacity;
    int* array;

    Stack(int cap) {
        capacity = cap;
        top = -1;
        array = new int[capacity];
    }

    ~Stack() {
        delete[] array;
    }

    void push(int item) {
        if (top < capacity - 1) {
            array[++top] = item;
        }
    }

    int pop() {
        if (top == -1) return INT_MIN;
        return array[top--];
    }

    bool isEmpty() {
        return top == -1;
    }
};

void moveDisk(int disk, char fromRod, char toRod) {
    cout << "Move disk " << disk << " from rod " << fromRod << " to rod " << toRod << endl;
}

void iterativeHanoi(int n, char source, char target, char auxiliary) {
    Stack src(n), dest(n), aux(n);


    for (int i = n; i >= 1; i--)
        src.push(i);

    char rods[3] = {source, target, auxiliary};
    Stack* stacks[3] = {&src, &dest, &aux};

    int totalMoves = (1 << n) - 1;
    for (int move = 1; move <= totalMoves; move++) {
        int fromIdx = (move & (move - 1)) % 3;
        int toIdx = ((move | (move - 1)) + 1) % 3;

        Stack* fromStack = stacks[fromIdx];
        Stack* toStack = stacks[toIdx];

        int fromDisk = fromStack->isEmpty() ? INT_MAX : fromStack->pop();
        int toDisk = toStack->isEmpty() ? INT_MAX : toStack->pop();


        if (fromDisk > toDisk) {
            fromStack->push(fromDisk);
            fromStack->push(toDisk);
            moveDisk(toDisk, rods[toIdx], rods[fromIdx]);
        } else {
            toStack->push(toDisk);
            toStack->push(fromDisk);
            moveDisk(fromDisk, rods[fromIdx], rods[toIdx]);
        }
    }
}

int main() {
    int n;
    char source, target, auxiliary;

    cout << "Enter the number of disks: ";
    cin >> n;
    cout << "Enter the names of the rods (source, target, auxiliary): ";
    cin >> source >> target >> auxiliary;

    iterativeHanoi(n, source, target, auxiliary);

    return 0;
}
