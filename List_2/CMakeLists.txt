cmake_minimum_required(VERSION 3.12)
project(List_2)

set(CMAKE_CXX_STANDARD 11)

add_executable(List_2 src/Menu_Package/main.cpp src/Menu_Package/MenuItem.h src/Menu_Package/Menu.cpp src/Menu_Package/Menu.h src/Menu_Package/Command_Package/Command.h src/Menu_Package/MenuCommand.cpp src/Menu_Package/MenuCommand.h src/Menu_Package/TableHandler_Package/TableHandler.cpp src/Menu_Package/TableHandler_Package/TableHandler.h src/Table_Package/Table.cpp src/Table_Package/Table.h src/Table_Package/Tools.cpp src/Table_Package/Tools.h src/Menu_Package/Command_Package/Command.cpp src/Menu_Package/Command_Package/Utils.cpp src/Menu_Package/Command_Package/Utils.h src/Menu_Package/Command_Package/List_1_Commands_Package/createSingleTable.cpp src/Menu_Package/Command_Package/List_1_Commands_Package/createSingleTable.h src/Menu_Package/Command_Package/List_1_Commands_Package/createMultipleTables.cpp src/Menu_Package/Command_Package/List_1_Commands_Package/createMultipleTables.h)