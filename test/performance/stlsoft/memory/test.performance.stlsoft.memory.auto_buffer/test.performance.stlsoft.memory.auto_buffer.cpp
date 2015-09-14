
#include <stlsoft/memory/auto_buffer.hpp>

#include <platformstl/performance/performance_counter.hpp>

#include <stdio.h>
#include <stdlib.h>

struct blah_t
{
	int	ar[10];
};

typedef stlsoft::auto_buffer<blah_t, 10>		ab_small_t;
typedef stlsoft::auto_buffer<blah_t, 1000>	ab_large_t;

size_t const	NUM_ITERATIONS = 10000;

int main()
{
	platformstl::performance_counter counter;

	char const* casename;


	casename = "small::smaller.swap(small::larger)";
	{ for(size_t WARMUPS = 2; 0 != WARMUPS; --WARMUPS)
	{
		counter.start();
		{ for(size_t i = 0; i != 10000; ++i)
		{
			ab_small_t	smaller(1);
			ab_small_t	larger(9);
	
			smaller.swap(larger);
		}}
		counter.stop();
		if(1 == WARMUPS)
		{
			fprintf(stdout, "%s: %lu\n", casename, static_cast<unsigned long>(counter.get_microseconds()));
		}
	}}

	casename = "small::larger.swap(small::smaller)";
	{ for(size_t WARMUPS = 2; 0 != WARMUPS; --WARMUPS)
	{
		counter.start();
		{ for(size_t i = 0; i != 10000; ++i)
		{
			ab_small_t	smaller(1);
			ab_small_t	larger(9);
	
			larger.swap(smaller);
		}}
		counter.stop();
		if(1 == WARMUPS)
		{
			fprintf(stdout, "%s: %lu\n", casename, static_cast<unsigned long>(counter.get_microseconds()));
		}
	}}


	casename = "large::smaller.swap(large::larger)";
	{ for(size_t WARMUPS = 2; 0 != WARMUPS; --WARMUPS)
	{
		counter.start();
		{ for(size_t i = 0; i != 10000; ++i)
		{
			ab_large_t	smaller(1);
			ab_large_t	larger(9);
	
			smaller.swap(larger);
		}}
		counter.stop();
		if(1 == WARMUPS)
		{
			fprintf(stdout, "%s: %lu\n", casename, static_cast<unsigned long>(counter.get_microseconds()));
		}
	}}

	casename = "large::larger.swap(large::smaller)";
	{ for(size_t WARMUPS = 2; 0 != WARMUPS; --WARMUPS)
	{
		counter.start();
		{ for(size_t i = 0; i != 10000; ++i)
		{
			ab_large_t	smaller(1);
			ab_large_t	larger(9);
	
			larger.swap(smaller);
		}}
		counter.stop();
		if(1 == WARMUPS)
		{
			fprintf(stdout, "%s: %lu\n", casename, static_cast<unsigned long>(counter.get_microseconds()));
		}
	}}



	return EXIT_SUCCESS;
}

