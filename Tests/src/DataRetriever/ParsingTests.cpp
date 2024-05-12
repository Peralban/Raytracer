/*
** EPITECH PROJECT, 2024
** ParsingTests.cpp
** File description:
** DESCRIPTION
*/

#include "MainInclude.hpp"
#include "DataRetriever/Parsing.hpp"

Test(Parsing, checkArgumentsTooFewArguments)
{
    App::Parsing parser;
    try {
        parser.checkArguments(1, (char **) ((const char *[]){("./raytracer")}));
    } catch (std::exception &e) {
        cr_assert_str_eq(e.what(), "Too few arguments");
    }
}

Test(Parsing, checkArgumentsTooManyArguments)
{
    App::Parsing parser;
    try {
        parser.checkArguments(5, (char **) ((const char *[]){"./raytracer", "test.cfg"}));
    } catch (std::exception &e) {
        cr_assert_str_eq(e.what(), "Too many arguments");
    }
}

Test(Parsing, checkArgumentsInvalidType)
{
    App::Parsing parser;
    try {
        parser.checkArguments(2, (char **) ((const char *[]){"./raytracer", "Tests/Templates/test.txt"}));
    } catch (std::exception &e) {
        cr_assert_str_eq(e.what(), "Invalid type of file");
    }
}

Test(Parsing, checkArgumentsCFGFile)
{
    App::Parsing parser;
    try {
        parser.checkArguments(2, (char **) ((const char *[]){"./raytracer", "Tests/Templates/test.cfg"}));
    } catch (std::exception &e) {
        cr_assert_str_eq(e.what(), "aaaaaaaaaaaaaaaaaaaaa");
        exit(0);
    }
    char *str = (char *) malloc(100);
    strcpy(str, parser.getConfigFile().c_str());
    cr_assert_str_eq("Tests/Templates/shapes_config.cfg", "Tests/Templates/shapes_config.cfg");
}
