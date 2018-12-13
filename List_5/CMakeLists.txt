cmake_minimum_required(VERSION 3.12)
project(List_5)

set(CMAKE_CXX_STANDARD 14)

add_executable(List_5 main.cpp src/knapsack_problem/Item.cpp src/knapsack_problem/Item.h src/knapsack_problem/KnapsackProblem.h src/genetic_algorithm/Individual.h src/genetic_algorithm/GeneticAlgorithm.h src/genetic_algorithm/utils/Tools.cpp src/genetic_algorithm/utils/Tools.h lib/user_interface/Command.cpp lib/user_interface/Command.h lib/user_interface/Menu.cpp lib/user_interface/Menu.h lib/user_interface/MenuCommand.cpp lib/user_interface/MenuCommand.h lib/user_interface/MenuItem.cpp lib/user_interface/MenuItem.h lib/user_interface/utils/Utils.cpp lib/user_interface/utils/Utils.h)