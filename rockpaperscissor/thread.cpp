#include <thread>

void callFromThread(int id) {
    int i = 100;
    while(i != 0) {
        printf("%s %d\n", "hi from thread", id);
        i--;
    }
}

int main(void) {
    std::thread t1 (callFromThread, 1);
    std::thread t2 (callFromThread, 2);

    t1.join();
    printf("%s\n", "bye from haha!");

    t2.join();

    printf("%s\n", "bye from main!");
    return 0;
}