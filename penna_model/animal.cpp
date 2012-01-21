#include "animal.hpp"

namespace Penna
{
	age_type Animal::bad_threshold_;
	age_type Animal::maturity_age_;

	void Animal::set_bad_threshold( age_type T ) {
		bad_threshold_ = T;
	}
	void Animal::set_maturity_age( age_type R ) {
		maturity_age_ = R;
	}

	Animal::Animal() {
		age_ = 0;
	}
	Animal::Animal( const Genome& gen ) {
		age_ = 0;
		gen_ = gen;
	}

	bool Animal::is_dead() const {
		return ( (age() >= maximum_age) || (gen_.count_bad( age() ) >= bad_threshold_) );
	}
	bool Animal::is_mature() const {
		return (age() >= maturity_age_);
	}
	age_type Animal::age() const {
		return age_;
	}

	void Animal::grow() {
		++age_;
	}
	Animal Animal::give_birth() const {
		assert( this->is_mature() );
		Genome child_genome(gen_);
		child_genome.mutate();
		return Animal(child_genome);
	}
}
