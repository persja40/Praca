#ifndef EXPRESSIONS
#define EXPRESSIONS
#include <tuple>
#include <array>
#include <functional>
#include <atomic>
#include <iostream>
#include <memory>
#include <vector>
#include <chrono>
#include <thread>
#include <qtconcurrentrun.h>
#include <mutex>

using namespace std;

template<typename T>
using tup3= tuple<T,T,T>;

extern mutex points;
extern vector<vector<tup3<double>>> beginsp;
extern vector<vector<tup3<double>>> endsp;
extern vector<tup3<int>> colorsp;
#endif // EXPRESSIONS

