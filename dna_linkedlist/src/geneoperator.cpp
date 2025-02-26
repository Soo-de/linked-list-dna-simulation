/*
* file			geneoperator.cpp
* description 	bağlı listelerle DNA manipülasyonu
* course		veri yapıları 1. öğretim B grubu
* assignment 	1. ödev
* date 			15.11.2024
* author		Sude ANDURMAN , sude.andurman@ogr.sakarya.edu.tr
*/

#include "geneoperator.hpp"
#include "linkedlist.hpp"


Node* GeneOperator :: findChromosome (Node *chrm, int idx)
{
	int	size;

	size = -1;
	while (++size < idx)
		chrm = chrm->next;
	return (chrm);
}

int	GeneOperator :: chromosomeSize (Node *chrm)
{
	int	size;

	size = 0;
	if (chrm != nullptr && chrm->content != "")
	{
		while (chrm->content[size] != '\0')
			size++;
	}
	return (size);
}

string	GeneOperator :: cutChromosome(Node *chrm, int size, int i)
{
	int		start_idx;
	string	str;
	cout << "Gelen kromozom :  " << chrm->content << endl;
	str = "";
	if (i == 1) /* for the first chromosome */
	{
		start_idx = -1;
		while (++start_idx < size / 2)
			str += chrm->content[start_idx];
	}
	else if (i == 2) /* for the second chromosome */
	{
		/*find start index*/
		if (size % 2 == 0)
			start_idx = (size / 2) - 1;
		else
			start_idx = size / 2;
		/******************/
		while (++start_idx < size)
			str += chrm->content[start_idx];
	}
	cout << "Bulunan parça kromozom: " << str << endl;
	return (str);
}

void	GeneOperator :: crossOver(int chr1, int chr2, LinkedList& list)
{
	Node*		f_chrm;
	Node*		s_chrm;
	string		new_chrm;
	int			size;
	int			chrm_size1;
	int			chrm_size2;

	f_chrm = list.head;
	s_chrm = list.head;
	size = list.listSize(f_chrm);
	if ((chr1 > size) || (chr2 > size) || (chr1 < 0) || (chr2 < 0))
	{
		cout << endl << size << endl;
		throw "< Geçerisiz gen numarasi >";
	}
	f_chrm = findChromosome(f_chrm, chr1);
	s_chrm = findChromosome(s_chrm, chr2);
	chrm_size1 = chromosomeSize(f_chrm);
	chrm_size2 = chromosomeSize(s_chrm);
	new_chrm = cutChromosome(f_chrm, chrm_size1, 1) + cutChromosome(s_chrm, chrm_size2, 2);
	list.addToLastIndex(new_chrm);
}

void	GeneOperator :: mutation(int chrm, int gene, LinkedList& list)
{
	Node*	chromosome;
	int		size_c;
	int		size_l;

	chromosome = list.head;
	chromosome = findChromosome(chromosome, chrm);
	size_l = list.listSize(chromosome);
	size_c = chromosomeSize(chromosome);
	if (gene < 0 || size_c <= gene || size_l <= chrm || chrm < 0)
		throw "Geçersiz indeks girdiniz";
	else
		chromosome->content[gene] = 'X';
	cout << "Mutasyonlu Kromozom :" << chromosome->content << endl;
}

void	GeneOperator :: getDisplayableGene (LinkedList& list)
{
	Node*	current;
	int		gene_i;
	int		displayable_gene;
	string	display;

	current = list.head;
	display = "";
	if (current == nullptr)
		throw "Gösterilecek bir kromozom bulunmamaktadir.";
	while (current != nullptr)
	{
		displayable_gene = 0;
		gene_i = -1;
		while (current->content[++gene_i] != '\0')
		{
			if (current->content[gene_i] < current->content[0])/*compare with first letter to find early letter*/
				displayable_gene = gene_i;
		}
		display += current->content[displayable_gene];
		current = current->next;
	}
	cout << display << endl;
}

void	GeneOperator :: taskRunner (const string& filename, LinkedList& list)
{
	LinkedList	lst;
	Node* 		current;
	int			idx;

	lst.getDatasFromFile(filename);
	current = lst.head;
	idx = -1;
	if (current == nullptr)
		throw "Herhangibir otomatik işlem bulunmamaktadir";
	while (current != nullptr)
	{
		idx++;
		if (current->content[0] == 'C')
			crossOver (current->content[1] - '0', current->content[2] - '0', list);
		else if (current->content[0] == 'M')
			mutation (current->content[1] - '0', current->content[2] - '0', list);
		else
			cout << idx << ". işlem geçersiz işlem içermektedir." << endl;
		current = current->next;
	}
}
