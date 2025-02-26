/*
* file			node.cpp
* description 	bağlı listelerle DNA manipülasyonu
* course		veri yapıları 1. öğretim B grubu
* assignment 	1. ödev
* date 			15.11.2024
* author		Sude ANDURMAN , sude.andurman@ogr.sakarya.edu.tr
*/

#include "node.hpp"

Node :: Node (string value)
{
	content = value;
	next = nullptr;
}

Node :: Node ()
{
	content = "";
	next = nullptr;
}

Node :: ~Node ()
{}
