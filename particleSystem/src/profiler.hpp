#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <mutex>
#include <chrono>
#include <algorithm>
#include <map>
#include <thread>

//#define PROFILING 1
#ifdef PROFILING
    #define PROFILE_SCOPE(name) ProfileTimer timer##__LINE__(name)
    #define PROFILE_FUNCTION() PROFILE_SCOPE(__FUNCTION__)
#else
    #define PROFILE_FUNCTION()
    #define PROFILE_SCOPE(name)
#endif

struct ProfileResult{
    const std::string name="Default";
    long long start=0;
    long long end=0;
    size_t tid=0;
};

class Profiler{
    std::string outputFileName="results.json";
    int profileCount=0;
    std::ofstream fout;
    std::mutex myLock;
    Profiler();
    public:
        static Profiler& instance(){
            static Profiler _instance; //local static, only visible inside this function (created when first entering this block)
            return _instance;
        }
        void writeProfile(const ProfileResult& r);
        void writeHeader();
        void writeFooter();
        Profiler(const Profiler&) = delete; //remove the copy constructor
        Profiler(Profiler&&) = delete; //remove the move constructor
        //remove assignment operators, assignment is basically a copy
        Profiler& operator=(const Profiler&)=delete;
        Profiler& operator=(Profiler&&)=delete;
        ~Profiler();

};

class ProfileTimer{
    std::chrono::time_point<std::chrono::high_resolution_clock> startPoint;
    ProfileResult result;
    bool stopped=false;

    public:
        ProfileTimer(const std::string& name);
        ~ProfileTimer();
        void start();
        void stop();

};