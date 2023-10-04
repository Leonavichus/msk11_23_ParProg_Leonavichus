#include <thread>
#include <iostream>

void threadProc()
{
    printf("Inside thread = %d", std::this_thread::get_id());
}

int main()
{
    std::thread t(threadProc);
    t.join();
}