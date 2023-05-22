#pragma once
#include "Verbose.h"
#include <string_view>
using namespace std;

constexpr int INF = 1000000;

constexpr bool GENERATE_MATRIX = false;
constexpr bool SERIALIZE_MATRIX = false;
constexpr Verbose VERBOSE = Low;

constexpr double EDGE_CHANCE = 0.8;
constexpr int MIN_NEGATIVE_VALUE = -5;
constexpr int MAX_NEGATIVE_VALUE = 0;
constexpr int MIN_POSITIVE_VALUE = 1;
constexpr int MAX_POSITIVE_VALUE = 50000;

constexpr int VERTICES = 500;
constexpr int NUMBER_OF_PROCESSORS = 12;
constexpr int NUMBER_OF_TESTS = 5;

constexpr string_view PATH = "M:\\study\\Bellman-Ford\\Bellman-Ford\\samples";