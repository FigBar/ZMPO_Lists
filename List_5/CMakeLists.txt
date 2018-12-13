cmake_minimum_required(VERSION 3.12)
project(List_5)

set(CMAKE_CXX_STANDARD 14)

add_executable(List_5 main.cpp src/knapsack_problem/Item.cpp src/knapsack_problem/Item.h src/knapsack_problem/KnapsackProblem.h src/genetic_algorithm/Individual.cpp src/genetic_algorithm/Individual.h src/genetic_algorithm/GeneticAlgorithm.cpp src/genetic_algorithm/GeneticAlgorithm.h src/genetic_algorithm/utils/Tools.cpp src/genetic_algorithm/utils/Tools.h)