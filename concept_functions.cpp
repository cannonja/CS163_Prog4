//Jack Cannon
//CS 163
//Program 4
//concept_functions.cpp
//
//This file contains the implementations for the methods of the concept class

#include "prog4.h"

//Constructor
concept::concept(int length)
{
    list_length = length;
    concept_name = NULL;
    structure_name = NULL;

    advantage_list = new char*[list_length];
    disadvantage_list = new char*[list_length];

    //Set pointers to NULL
    for (int i = 0; i < list_length; ++i)
    {
        advantage_list[i] = NULL;
        disadvantage_list[i] = NULL;
    }
}


concept::~concept()
{
    delete [] concept_name;
    concept_name = NULL;

    delete [] structure_name;
    structure_name = NULL;

    for (int i = 0; i < list_length; ++i)
    {
        delete [] advantage_list[i];
        delete [] disadvantage_list[i];

        advantage_list[i] = NULL;
        disadvantage_list[i] = NULL;
    }

    delete [] advantage_list;
    advantage_list = NULL;

    delete [] disadvantage_list;
    disadvantage_list = NULL;
}



















