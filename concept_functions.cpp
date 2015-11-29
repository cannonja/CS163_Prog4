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

//Destructor
concept::~concept()
{
    delete [] concept_name;
    concept_name = NULL;

    delete [] structure_name;
    structure_name = NULL;

    //Deallocate array of char pointers
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


//This function takes a c-string and sets the concept name
int concept::set_concept(char new_concept[])
{
    
    if (!new_concept)
        return 0;

    concept_name = new char[strlen(new_concept) + 1];
    strcpy(concept_name, new_concept);

    return 1;
}


//This function takes a c-string and sets the data structure name
int concept::set_structure(char new_structure[])
{
    
    if (!new_structure)
        return 0;

    structure_name = new char[strlen(new_structure) + 1];
    strcpy(structure_name, new_structure);

    return 1;
}


//This function takes a c-string as an argument and adds
//a new advantage to the list of advantages
int concept::add_advantage(char new_advantage[])
{
    int counter = 0;
    
    //If argument is NULL, method fails
    if (!new_advantage)
        return 0;

    //Iterate to current index
    while (advantage_list[counter] && counter < list_length)
        ++counter;
    
    //If list if full, method fails
    if (counter == list_length)
        return 0;


    advantage_list[counter] = new char[strlen(new_advantage) + 1];
    strcpy(advantage_list[counter], new_advantage);

    return 1;
}


//This function takes a c-string as an argument and adds
//a new disadvantage to the list of disadvantages
int concept::add_disadvantage(char new_disadvantage[])
{
    int counter = 0;
    
    //If argument is NULL, method fails
    if (!new_disadvantage)
        return 0;

    //Iterate to current index
    while (disadvantage_list[counter] && counter < list_length)
        ++counter;
    
    //If list if full, method fails
    if (counter == list_length)
        return 0;


    disadvantage_list[counter] = new char[strlen(new_disadvantage) + 1];
    strcpy(disadvantage_list[counter], new_disadvantage);

    return 1;
}






















