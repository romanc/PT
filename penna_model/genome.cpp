#include "genome.hpp"
#include<cstdlib>
namespace Penna
{
	age_type Genome::mutation_rate_ = 5;

	Genome::Genome(double p) {
		for(age_type i = 0; i < number_of_genes; ++i) {
			if(drand48() > p) genes_.flip(i);
		}
	}

	Genome::gene_type const & Genome::genes() const {
		return genes_;
	}

	bool Genome::is_bad( age_type thisGene ) const {
		return genes_.test(thisGene);
	}

	age_type Genome::count_bad( age_type n ) const {
		age_type bad_genes = 0;
		for(age_type i = 0; i < n; ++i) {
			if( is_bad(i) ) bad_genes++;
		}
		return bad_genes;
	}

	void Genome::mutate() {
		for(age_type i = 0; i <mutation_rate_; ++i) {
			genes_.flip(number_of_genes*drand48());
		}
	}
}
