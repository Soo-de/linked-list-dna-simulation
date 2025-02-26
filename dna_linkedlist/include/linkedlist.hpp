/*
* file			node.hpp
* description 	bağlı listelerle DNA manipülasyonu
* course		veri yapıları 1. öğretim B grubu
* assignment 	1. ödev
* date 			15.11.2024
* author		Sude ANDURMAN , sude.andurman@ogr.sakarya.edu.tr
*/

#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include "node.hpp"
#include <fstream>
#include <sstream>

class	LinkedList
{
	public:
		Node* head;
		
		LinkedList();
		~LinkedList();
		void	addToLastIndex (string value);
		void	getDatasFromFile (const string& filename);
		int		listSize (Node *list);

};

#endif