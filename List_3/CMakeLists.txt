cmake_minimum_required(VERSION 3.12)
project(List_3)

set(CMAKE_CXX_STANDARD 11)

add_executable(List_3 main.cpp lib/user_interface/Command.cpp lib/user_interface/Command.h lib/utils/Utils.cpp lib/utils/Utils.h lib/user_interface/Menu.cpp lib/user_interface/Menu.h lib/user_interface/MenuCommand.cpp lib/user_interface/MenuCommand.h lib/user_interface/MenuItem.cpp lib/user_interface/MenuItem.h)