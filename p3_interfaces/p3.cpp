#include <iostream>

#include "exceptions.h"
#include "dll.h"
#include "stack.h"
#include "queue.h"

using namespace std;

int main() {
    try {
        char ch;
        cout << "Enter:\n\t- 'l' for list\n\t- 's' for stack\n\t- 'q' for queue\n\t- 'quit' to quit" << endl;
        cin >> ch;

        if (ch == 'l') {
            cout << "Enter:\n\t- 'i #r #v' to insert\n\t- 'r #' to remove\n\t- 'a #' to at\n\t- 's' to get the size\n\t- 'e' to check emptiness\n\t- 'c' to clear\n\t - 'q' to quit" << endl;
            string choice;
            int rank;
            string val;
            Dll<string> list;
            while (1) {
                cout << list << endl << endl;
                cin >> choice;
                Dll<string> list2 = Dll<string>(list);

                cout << list2 << endl;
                cout << "he" << endl;
                cout << list << endl;
                cout << "cs" << endl;
                if (choice == "quit") {
                    break;
                }
                if (choice == "i") {
                    cin >> rank >> val;
                    list.insert(rank, val);
                }
                else if (choice == "r") {
                    cin >> rank;
                    cout << "removed = " << list.remove(rank) << endl;
                }
                else if (choice == "a") {
                    cin >> rank;
                    cout << "at = " << list.at(rank) << endl;
                }
                else if (choice == "s") {
                    cout << "size = " << list.size() << endl;
                }
                else if (choice == "c") {
                    list.clear();
                }
                else if (choice == "e") {
                    cout << "empty = " << boolalpha << list.empty() << endl;
                }
            }
        }
        else if (ch == 's') {
            cout << "Enter:\n\t- 'push #' to push\n\t- 'pop' to pop\n\t- 'peek' to peek\n\t- 's' to get the size\n\t- 'e' to check emptiness\n\t- 'q' to quit" << endl;
            string choice;
            string val;
            Stack<string> stack;
            while (1) {
                cout << stack << endl << endl;
                cin >> choice;
                if (choice == "quit") {
                    break;
                }
                if (choice == "push") {
                    cin >> val;
                    stack.push(val);
                }
                else if (choice == "pop") {
                    cout << "popped " << stack.pop() << endl;
                }
                else if (choice == "peek") {
                    cout << "peeked " << stack.peek() << endl;
                }
                else if (choice == "s") {
                    cout << "size = " << stack.size() << endl;
                }
                else if (choice == "e") {
                    cout << "empty = " << boolalpha << stack.empty() << endl;
                }
            }
        }
        else if (ch == 'q') {
            cout << "Enter:\n\t- 'e #' to enqueue\n\t- 'd' to dequeue\n\t- 'p' to peek\n\t- 's' to get the size\n\t- 'empty' to check emptiness\n\t- 'q' to quit" << endl;
            string choice;
            string val;
            Queue<string> queue;
            while (1) {
                cout << queue << endl << endl;
                cin >> choice;
                if (choice == "quit") {
                    break;
                }
                if (choice == "e") {
                    cin >> val;
                    queue.enqueue(val);
                }
                else if (choice == "d") {
                    cout << "dequeued " << queue.dequeue() << endl;
                }
                else if (choice == "p") {
                    cout << "peeked " << queue.peek() << endl;
                }
                else if (choice == "s") {
                    cout << "size = " << queue.size() << endl;
                }
                else if (choice == "empty") {
                    cout << "empty = " << boolalpha << queue.empty() << endl;
                }
            }
        }
    }
    catch (InvalidOperationException &e) {
        cout << e.getMessage() << endl;
    }
    catch (IndexOutOfRangeException &e) {
        cout << e.getMessage() << " Index=" << e.getIndex() << endl;
    }

    return 0;
}
