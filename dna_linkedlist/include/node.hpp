/*
* file			node.hpp
* description 	bağlı listelerle DNA manipülasyonu
* course		veri yapıları 1. öğretim B grubu
* assignment 	1. ödev
* date 			15.11.2024
* author		Sude ANDURMAN , sude.andurman@ogr.sakarya.edu.tr
*/

#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
using namespace std;

class	Node
{
	public:
		string	content;
		Node	*next;
		Node (string value);
		Node ();
		~Node ();
};

#endif