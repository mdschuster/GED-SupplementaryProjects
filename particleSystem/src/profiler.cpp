#include "profiler.hpp"

Profiler::Profiler(){
    fout=std::ofstream(outputFileName);
    writeHeader();
}
Profiler::~Profiler(){
    writeFooter();
}
void Profiler::writeProfile(const ProfileResult& r){
    std::lock_guard<std::mutex> lock(myLock);
    if(profileCount++>0){
        fout<<",";
    }
    std::string name = r.name;
    std::replace(name.begin(),name.end(),'"','\'');

    fout<<"\n{";
    fout<<"\"cat\":\"function\",";
    fout<<"\"dur\":"<<(r.end-r.start)<<",";
    fout<<"\"name\":\""<<name<<"\",";
    fout<<"\"ph\":\"X\",";
    fout<<"\"pid\":0,";
    fout<<"\"tid\":"<<r.tid<<",";
    fout<<"\"ts\":"<<r.start;
    fout<<"}";
}
void Profiler::writeHeader(){
    fout<<"{\"traceEvents\":[";
}
void Profiler::writeFooter(){
    fout<<"]}";
}


ProfileTimer::ProfileTimer(const std::string& name): result({name,0,0,0}){
    start();
}
ProfileTimer::~ProfileTimer(){
    stop();
}
void ProfileTimer::start(){
    static long long lastStartTime=0;
    startPoint=std::chrono::high_resolution_clock::now();
    result.start=std::chrono::time_point_cast<std::chrono::microseconds> (startPoint).time_since_epoch().count();
    result.start+=((result.start==lastStartTime?1:0));
    lastStartTime=result.start;
    stopped=false;
}
void ProfileTimer::stop(){
    if(stopped) return;
    auto stopPoint=std::chrono::high_resolution_clock::now();
    result.end=std::chrono::time_point_cast<std::chrono::microseconds> (stopPoint).time_since_epoch().count();
    result.tid=std::hash<std::thread::id>{}(std::this_thread::get_id());
    Profiler::instance().writeProfile(result);
}
