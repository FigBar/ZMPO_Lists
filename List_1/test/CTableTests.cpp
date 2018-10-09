//
// Created by fig_bar98 on 09.10.18.
//

#define CATCH_CONFIG_MAIN
#include "../lib/catch.hpp"
#include "../src/CTable.h"

SCENARIO("Test constructor")
{
    GIVEN("CTable object")
    {
        WHEN("default constructor is called")
        {
            CTable table;

            THEN("objects fields should have appropriate values")
            {
                REQUIRE(table.getName() == "Table1");
                REQUIRE(table.getSize() == 10);
            }
        }

        WHEN("parameter constructor is called")
        {
            CTable table("MyTable", 12);

            THEN("objects fields should have appropriate values")
            {
                REQUIRE(table.getName() == "MyTable");
                REQUIRE(table.getSize() == 12);
            }
        }

        AND_GIVEN("Another CTable object")
        {
            CTable cpyThis("Table", 3);
            REQUIRE(cpyThis.setVaule(0, 1));
            REQUIRE(cpyThis.setVaule(1, 2));
            REQUIRE(cpyThis.setVaule(2, 3));

            WHEN("copying constructor is called")
            {
                CTable table(cpyThis);

                THEN("objects fields should have appropriate values")
                {
                    REQUIRE(table.getName() == "Table_copy");
                    REQUIRE(table.getSize() == 3);

                    bool success = false;
                    REQUIRE(table.getValue(0, &success) == 1);
                    REQUIRE(success);
                    REQUIRE(table.getValue(1, &success) == 2);
                    REQUIRE(success);
                    REQUIRE(table.getValue(2, &success) == 3);
                    REQUIRE(success);
                }
            }
        }
    }
}

SCENARIO("Test set name")
{
    GIVEN("CTable object")
    {
        CTable table;

        WHEN("It's name is changed")
        {
            table.setName("MyTable");

            THEN("It should change")
            {
                REQUIRE(table.getName() == "MyTable");
            }
        }
    }
}

SCENARIO("Test set length")
{
    GIVEN("CTable object")
    {
        CTable table("Whatever", 5);

        WHEN("it's fields are set")
        {
            REQUIRE(table.setVaule(0, 1));
            REQUIRE(table.setVaule(1, 2));
            REQUIRE(table.setVaule(2, 3));
            REQUIRE(table.setVaule(3, 4));
            REQUIRE(table.setVaule(4, 5));

            AND_WHEN("it's size is expanded")
            {
                REQUIRE(table.setSize(10));

                GIVEN("success variable")
                {
                    bool success = false;

                    THEN("check new fields are 0")
                    {
                        REQUIRE(table.getValue(5, &success) == 0);
                        REQUIRE(success);
                        REQUIRE(table.getValue(6, &success) == 0);
                        REQUIRE(success);
                        REQUIRE(table.getValue(7, &success) == 0);
                        REQUIRE(success);
                        REQUIRE(table.getValue(8, &success) == 0);
                        REQUIRE(success);
                        REQUIRE(table.getValue(9, &success) == 0);
                        REQUIRE(success);
                    }

                    AND_WHEN("new fields are changed")
                    {
                        REQUIRE(table.setVaule(5, 11));
                        REQUIRE(table.setVaule(6, 12));
                        REQUIRE(table.setVaule(7, 13));
                        REQUIRE(table.setVaule(8, 14));
                        REQUIRE(table.setVaule(9, 15));

                        THEN("make sure all fields have proper values")
                        {
                            REQUIRE(table.getValue(0, &success) == 1);
                            REQUIRE(success);
                            REQUIRE(table.getValue(1, &success) == 2);
                            REQUIRE(success);
                            REQUIRE(table.getValue(2, &success) == 3);
                            REQUIRE(success);
                            REQUIRE(table.getValue(3, &success) == 4);
                            REQUIRE(success);
                            REQUIRE(table.getValue(4, &success) == 5);
                            REQUIRE(success);
                            REQUIRE(table.getValue(5, &success) == 11);
                            REQUIRE(success);
                            REQUIRE(table.getValue(6, &success) == 12);
                            REQUIRE(success);
                            REQUIRE(table.getValue(7, &success) == 13);
                            REQUIRE(success);
                            REQUIRE(table.getValue(8, &success) == 14);
                            REQUIRE(success);
                            REQUIRE(table.getValue(9, &success) == 15);
                            REQUIRE(success);
                        }
                    }
                }
            }

            AND_WHEN("it's size is truncated")
            {
                REQUIRE(table.setSize(3));

                GIVEN("success variable")
                {
                    bool success = true;

                    THEN("left out fields values shouldn't change")
                    {
                        REQUIRE(table.getValue(0, &success) == 1);
                        REQUIRE(table.getValue(1, &success) == 2);
                        REQUIRE(table.getValue(2, &success) == 3);
                    }

                    AND_WHEN("illegal value is accessed")
                    {
                        REQUIRE(table.getValue(3, &success) == -1);

                        THEN("it shouldn't be successful")
                        {
                            REQUIRE_FALSE(success);
                        }
                    }
                }
            }

            AND_WHEN("unreasonable argument is passed to set length method")
            {
                REQUIRE_FALSE(table.setSize(-15));

                THEN("nothing should change")
                {
                    bool success = false;
                    REQUIRE(table.getValue(0, &success) == 1);
                    REQUIRE(success);
                    REQUIRE(table.getValue(1, &success) == 2);
                    REQUIRE(success);
                    REQUIRE(table.getValue(2, &success) == 3);
                    REQUIRE(success);
                    REQUIRE(table.getValue(3, &success) == 4);
                    REQUIRE(success);
                    REQUIRE(table.getValue(4, &success) == 5);
                    REQUIRE(success);
                }
            }
        }
    }
}

SCENARIO("Test accessing elements")
{
    GIVEN("CTable object and variable indicating success")
    {
        CTable table;
        bool success = false;

        WHEN("It's elements are changed")
        {
            AND_WHEN("They are within legal range")
            {
                THEN("They should change")
                {
                    REQUIRE(table.setVaule(0, 15));
                    REQUIRE(table.getValue(0, &success) == 15);
                    REQUIRE(success);
                    REQUIRE(table.setVaule(0, 16));
                    REQUIRE(table.getValue(0, &success) == 16);
                    REQUIRE(success);
                    REQUIRE(table.setVaule(9, 9));
                    REQUIRE(table.getValue(9, &success) == 9);
                    REQUIRE(success);
                }
            }

            AND_WHEN("They aren't within legal range")
            {
                THEN("They shouldn't change")
                {
                    REQUIRE_FALSE(table.setVaule(-12, 14));
                    REQUIRE(table.getValue(-12, &success) == -1);
                    REQUIRE_FALSE(success);
                }
            }
        }
    }
}

SCENARIO("Test clone")
{
    GIVEN("CTable object")
    {
        CTable table("Name", 3);
        REQUIRE(table.setVaule(0, 1));
        REQUIRE(table.setVaule(1, 2));
        REQUIRE(table.setVaule(2, 3));

        WHEN("It's cloned")
        {
            CTable* cloned = table.clone();

            THEN("Those objects should be in different places in memory")
            {
                REQUIRE_FALSE(cloned == &table);
            }

            THEN("Should have all fields same")
            {
                bool success = true;
                REQUIRE(table.getName() + "_copy" == cloned->getName());
                REQUIRE(table.getSize() == cloned->getSize());
                REQUIRE(table.getValue(0, &success) == cloned->getValue(0, &success));
                REQUIRE(table.getValue(1, &success) == cloned->getValue(1, &success));
                REQUIRE(table.getValue(2, &success) == cloned->getValue(2, &success));
            }

            delete cloned; //why do I need to specify this? because it's stored as a pointer?
        }
    }
}

SCENARIO("Test operator =")
{
    GIVEN("CTable object to be copied")
    {
        CTable toCpy("To copy", 3);
        REQUIRE(toCpy.setVaule(0, 1));
        REQUIRE(toCpy.setVaule(1, 2));
        REQUIRE(toCpy.setVaule(2, 3));

        AND_GIVEN("CTable object copying")
        {
            CTable table("Copying", 6);
            REQUIRE(table.setVaule(0, 6));
            REQUIRE(table.setVaule(1, 5));
            REQUIRE(table.setVaule(2, 4));
            REQUIRE(table.setVaule(3, 3));
            REQUIRE(table.setVaule(4, 2));
            REQUIRE(table.setVaule(5, 1));

            WHEN("Using = operator")
            {
                table = toCpy;

                THEN("CTables objects array changes")
                {
                    REQUIRE(table.getName() == "Copying");
                    REQUIRE(table.getSize() == 3);

                    bool success = true;
                    REQUIRE(table.getValue(0, &success) == 1);
                    REQUIRE(table.getValue(1, &success) == 2);
                    REQUIRE(table.getValue(2, &success) == 3);
                }
            }
        }
    }
}

SCENARIO("Test toString")
{
    GIVEN("CTable object")
    {
        CTable table("Name", 3);

        WHEN("It's values are set")
        {
            table.setVaule(0, 1);
            table.setVaule(1, 2);
            table.setVaule(2, 3);

            THEN("It's toString should show everything properly")
            {
                REQUIRE(table.toString() == "[ Name len: 3 values: 1, 2, 3 ]");
            }
        }
    }
}
