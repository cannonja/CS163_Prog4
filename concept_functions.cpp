//Jack Cannon
//CS 163
//Program 4
//concept_functions.cpp
//
//This file contains the implementations for the methods of the concept class

#include "prog4.h"

//Constructor
concept::concept()
{
    list_length = LIST_LENGTH;
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


//This function takes a c-string as an argument
//and compares it with the concept.  It returns
//1 if they're a match and 0 otherwise
int concept::match_concept(char to_match[])
{
    if (!strcmp(concept_name, to_match))
        return 1;

    return 0;
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


//This function takes a c-string as an argument
//and compares it with the concept.  It returns
//1 if they're a match and 0 otherwise
int concept::match_structure(char to_match[])
{
    if (!strcmp(structure_name, to_match))
        return 1;

    return 0;
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


//This function takes a concept as an argument and copies
//the contests of its data members to the current instance
//of the concept object
int concept::copy_concept(concept & copy_from)
{
    int index = 0;//Adv-Disadv list index variable

    if (copy_from.list_length < 0)
        return 0;

    //Copy int
    list_length = copy_from.list_length;

    //If any are NULL, method fails
    if (!copy_from.concept_name || !copy_from.structure_name || !copy_from.advantage_list || !copy_from.disadvantage_list)
        return 0;

    if (!set_concept(copy_from.concept_name))
        return 0;

    if (!set_structure(copy_from.structure_name))
        return 0;
    
    //Copy lists
    do
    {
        if (!add_advantage(copy_from.advantage_list[index]))
            return 0;

    } while (copy_from.advantage_list[++index]);
    index = 0;//Reset index
    
    do
    {
        if (!add_disadvantage(copy_from.disadvantage_list[index]))
            return 0;

    } while (copy_from.advantage_list[++index]);


    return 1;
}



//This method displays the contents of the data members
int concept::display()
{
    int index = 0;//For adv/disadv

    if (!concept_name || !structure_name || !advantage_list || !disadvantage_list)
        return 0;

    cout << "List length: " << list_length << endl;
    cout << "Concept: " << concept_name << endl;
    cout << "Data structure: " << structure_name << endl;
   
    //Display numbered list
    cout << "Advantages:\n";
    do 
    {
        cout << "\t" << (index + 1) << ") " << advantage_list[index] << endl;
        
    } while (advantage_list[++index]);
    index = 0;//Reset index for disadvantages


    //Display numbered list
    cout << "Disadvantages:\n";
    do 
    {
        cout << "\t" << (index + 1) << ") " << disadvantage_list[index] << endl;
        
    } while (disadvantage_list[++index]);
   
    return 1;

}


//This function returns the hash value for the concept and 
//data structure names combined
//It returns 0 if it's unsuccessful
int concept::get_hash()
{
    //Variables to calculate average ASCII value
    int sum = 0, count = 0;
    int length;//Loop condition

    if (!concept_name || !structure_name)
        return 0;

    length = strlen(concept_name);
    count += length;
    for (int i = 0; i < length; ++i)
        sum += concept_name[i];

    length = strlen(structure_name);
    count += length;
    for (int i = 0; i < length; ++i)
        sum += structure_name[i];

    return (sum / count);

}

    















