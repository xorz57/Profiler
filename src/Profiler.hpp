#pragma once

#include <chrono>
#include <cstdio>

class Profiler {
public:
    Profiler() = delete;

    explicit Profiler(const char *name) : mName(name) {
        mT0 = std::chrono::high_resolution_clock::now();
        std::printf("Entered %s\n", mName);
    }

    Profiler(const Profiler &) = delete;

    Profiler(Profiler &&) = delete;

    ~Profiler() {
        mT1 = std::chrono::high_resolution_clock::now();
        mDuration = std::chrono::duration_cast<std::chrono::microseconds>(mT1 - mT0).count();
        std::printf("Left %s after %llu us\n", mName, mDuration);
    }

    Profiler &operator=(const Profiler &) = delete;

    Profiler &operator=(Profiler &&) = delete;

private:
    const char *mName = nullptr;
    unsigned long long mDuration = 0;
    std::chrono::time_point<std::chrono::high_resolution_clock> mT0;
    std::chrono::time_point<std::chrono::high_resolution_clock> mT1;
};

#define PROFILE_FUNCTION() Profiler profiler(__func__)
