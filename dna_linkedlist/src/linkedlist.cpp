/*
* file			linkedlist.cpp
* description 	bağlı listelerle DNA manipülasyonu
* course		veri yapıları 1. öğretim B grubu
* assignment 	1. ödev
* date 			15.11.2024
* author		Sude ANDURMAN , sude.andurman@ogr.sakarya.edu.tr
*/

#include "linkedlist.hpp"

LinkedList :: LinkedList()
{
	head = nullptr;
}

LinkedList :: ~LinkedList()
{
	Node*	current;
	Node*	nextNode;

	current = head;
	while (current != nullptr)
	{
		nextNode = current->next;
		delete current;
		current = nextNode;
	}
}

void	LinkedList :: addToLastIndex (string value)
{
	if (value == "")
		return;
	Node*	newNode = new Node(value);
	if (head == nullptr)
		head = newNode;
	else
	{
		Node*	current = head;
		while (current->next != nullptr)
			current = current->next;
		current->next = newNode;
	}
}

void	LinkedList :: getDatasFromFile (const string& filename)
{
	ifstream file(filename);
	if (!file.is_open())
		throw "Dosya açilamadi";
	
	string	line;
	string	value;
	string	chromosome;
	while (getline(file, line))
	{
		chromosome = "";
		stringstream ss(line);
		while (ss >> value)
			chromosome += value;
		addToLastIndex(chromosome);
	}
	file.close();
}

int	LinkedList :: listSize (Node *list)
{
	if (!list)
		return (0);
	return (1 + listSize(list->next));
}
