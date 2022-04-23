#include "benchmark/benchmark.h"

#include "algorithmic/string/manacher.h"

using namespace algorithmic;

static void BenchmarkManacher(benchmark::State& state) {
    for (auto _ : state) {
        auto manacher = Manacher(10);
    }
}

BENCHMARK(BenchmarkManacher);
