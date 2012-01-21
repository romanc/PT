#include<iostream>
#include "genome.hpp"
#include "animal.hpp"


int main() {
	using namespace Penna;

	std::cout << "Testing Genome class" << std::endl;
	age_type n = 10;
	Genome g;
	Genome::gene_type genes = g.genes();
	age_type bad_genes = g.count_bad( n );
	std::cout << "Number of bad genes with default constructor after 10 years: " << bad_genes << std::endl;

	Genome g_(0.5);
	bad_genes = g_.count_bad( n );
	std::cout << "Number of bad genes with 50\%-bad-genes-constructor after 10 years: " << bad_genes << std::endl;


}

