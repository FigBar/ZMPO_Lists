cmake_minimum_required(VERSION 3.12)
project(List_2)

set(CMAKE_CXX_STANDARD 11)

add_executable(List_2 src/Menu_Package/main.cpp src/Menu_Package/MenuItem.cpp src/Menu_Package/MenuItem.h src/Menu_Package/Menu.cpp src/Menu_Package/Menu.h src/Menu_Package/Command.cpp src/Menu_Package/Command.h src/Menu_Package/MenuCommand.cpp src/Menu_Package/MenuCommand.h src/TableHandler_Package/TableHandler.cpp src/TableHandler_Package/TableHandler.h src/TableHandler_Package/Table.cpp src/TableHandler_Package/Table.h src/TableHandler_Package/Tools.cpp src/TableHandler_Package/Tools.h)