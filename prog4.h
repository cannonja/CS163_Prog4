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
        concept();
        ~concept();
        int set_concept(char new_concept[]);
        int match_concept(char to_match[]);
        int set_structure(char new_structure[]);
        int match_structure(char to_match[]);
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
        tree();//done
        ~tree();//done
        int import_data(char file_path[]);
        int insert_wrapper(concept & to_insert);//done
        int insert(concept & to_insert, node * & root_ptr);//done
        node** search_wrapper(char concept_name[]);//done
        node** search(char concept_name[], node * root_ptr);//done
        int retrieve_wrapper(concept & to_fill, char concept_name[]);//done
        int retrieve(concept & to_fill, char concept_name[], node * root_ptr);//done
        int remove_concept(char concept_name[]);//done
        int destroy_wrapper();//done
        int destroy(node * & root_ptr);//done
        int display_in_order_wrapper();//done
        int display_in_order(node * root_ptr);//done
        node** inorder_traverse(node * & root_ptr, node * & temp);//done 

    private:
        node * root;
        concept * array;

};

























