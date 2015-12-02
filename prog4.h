//Jack Cannon
//CS 163
//Program 4
//prog4.h
//
//This file contains the prototypes and definitions for the classes, structs
//and methods used in the ADTs

#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>

using namespace std;

const int LIST_LENGTH = 5;

class concept
{
    public:
        concept(int length = LIST_LENGTH);
        ~concept();
        int set_concept(char new_concept[]);
        int set_structure(char new_structure[]);
        int add_advantage(char new_advantage[]);
        int add_disadvantage(char new_disadvantage[]);
        int copy_concept(concept & copy_from);
        int display();
        int get_hash();

    private:
        int list_length;
        char * concept_name;
        char * structure_name;
        char ** advantage_list;
        char ** disadvantage_list;

};


struct node
{
    concept data;
    int traverse;
    node * left;
    node * right;
};


class tree
{
    public:
        tree();
        ~tree();
        int insert_wrapper(concept & to_insert);
        int insert(concept & to_insert, node * & root_ptr);
        int search(char concept_name[]);
        int retrieve(concept & to_fill, char concept_name[]);
        int remove_concept(char concept_name[]);
        int remove_structure(char structure_name[]);
        int destroy();
        int display_in_order();
        int hash_function(char concept_name[]);

    private:
        node * root;

};

























