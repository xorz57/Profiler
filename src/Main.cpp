#include "Profiler.hpp"

void f0();

void f1();

void f2();

void f0() {
    PROFILE_FUNCTION();
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    f1();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

void f1() {
    PROFILE_FUNCTION();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    f2();
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
}

void f2() {
    PROFILE_FUNCTION();
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
}

int main() {
    PROFILE_FUNCTION();
    std::this_thread::sleep_for(std::chrono::milliseconds(400));
    f0();
    return 0;
}
