tests: clean_test build_tests
unittest: clean_test run_unittest
benchmark: clean_test run_benchmark

build_tests:
	cmake \
	-S. \
	-Bbuild \
	-DCMAKE_BUILD_TYPE=Release \
	-DBENCHMARK_ENABLE_TESTING=OFF \
	-DCMAKE_EXPORT_COMPILE_COMMANDS=1 \
	-DALGORITHMIC_LIBRARY_BUILD_TESTS=ON
	cmake --build build -j

run_unittest:
	./build/bin/unit_test

run_benchmark:
	./build/bin/unit_benchmark

clean:
	rm -rf ./build

clean_test:
	if [ -d ./build/test ]; then \
		find ./build/test -name "*.gcda" -print0 | xargs -0 rm -f; \
	fi

.PHONY: clean clean_test
