# Makefile for Parallel Computing Lab

CXX = g++
CXXFLAGS = -O3 -std=c++17 -Wall
OMP_FLAGS = -fopenmp

# Directories
OPENMP_DIR = openmp
MPI_DIR = mpi
BUILD_DIR = build
BIN_DIR = bin

# Create directories
$(shell mkdir -p $(BUILD_DIR) $(BIN_DIR))

# OpenMP sources
OPENMP_SOURCES = $(wildcard $(OPENMP_DIR)/*.cpp)
OPENMP_BINARIES = $(patsubst $(OPENMP_DIR)/%.cpp,$(BIN_DIR)/omp_%,$(OPENMP_SOURCES))

# Default target
all: openmp

# Build all OpenMP examples
openmp: $(OPENMP_BINARIES)

# Pattern rule for OpenMP files
$(BIN_DIR)/omp_%: $(OPENMP_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(OMP_FLAGS) $< -o $@

# Run OpenMP examples
run_hello: $(BIN_DIR)/omp_01_hello_parallel
	./$(BIN_DIR)/omp_01_hello_parallel

run_for: $(BIN_DIR)/omp_02_parallel_for
	./$(BIN_DIR)/omp_02_parallel_for

run_reduction: $(BIN_DIR)/omp_03_reduction
	./$(BIN_DIR)/omp_03_reduction

run_gemm: $(BIN_DIR)/omp_05_gemm_openmp
	./$(BIN_DIR)/omp_05_gemm_openmp

# Run all OpenMP examples
run_all_omp: openmp
	@echo "=== Hello Parallel ===" && ./$(BIN_DIR)/omp_01_hello_parallel 2>/dev/null || true
	@echo ""
	@echo "=== Parallel For ===" && ./$(BIN_DIR)/omp_02_parallel_for 2>/dev/null || true

# Clean
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

.PHONY: all openmp clean run_hello run_for run_reduction run_gemm run_all_omp
