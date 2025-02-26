/*
* file			node.hpp
* description 	bağlı listelerle DNA manipülasyonu
* course		veri yapıları 1. öğretim B grubu
* assignment 	1. ödev
* date 			15.11.2024
* author		Sude ANDURMAN , sude.andurman@ogr.sakarya.edu.tr
*/

#ifndef GENEOPERATOR_HPP
#define GENEOPERATOR_HPP

#include "linkedlist.hpp"

class	GeneOperator
{
	public:
		Node*	findChromosome (Node *chrm, int idx);
		void	crossOver (int chr1, int chr2, LinkedList& list);
		void	mutation (int chrm, int gene, LinkedList& list);
		void	taskRunner (const string& filename, LinkedList& list);
		void	getDisplayableGene (LinkedList& list);
		int		chromosomeSize (Node *chrm);
		string	cutChromosome (Node *chrm, int size, int i);
};


#endif