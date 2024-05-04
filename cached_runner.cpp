#include "cached_runner.h"
#include "task_runner.h"

CachedRunner::CachedRunner(Cache& cache) : cache(cache), cacheHits(0), cacheMisses(0) {}

double CachedRunner::multiply(std::string filename){
    double cachedResult;

    if (cache.get(filename, cachedResult)){
        cacheHits++;
        return cachedResult;
    }
    else {
        double result = TaskRunner::multiply(filename);
        cache.add(filename, result);
        cacheMisses++;
        return result;
    }
}

int CachedRunner::palindrome(std::string filename){
    int cachedResult;

    if (cache.get(filename, cachedResult)){
        cacheHits++;
        return cachedResult;
    }
    else {
        int result = TaskRunner::palindrome(filename);
        cache.add(filename, result);
        cacheMisses++;
        return result;
    }
}

int CachedRunner::hits(){
    return cacheHits;
}

int CachedRunner::misses(){
    return cacheMisses;
}