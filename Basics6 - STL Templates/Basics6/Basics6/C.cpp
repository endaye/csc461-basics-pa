#include "output.h"
#include <set>
#include <algorithm>

struct ZipCode
{
	char s[4];
	int  zip;
};

ZipCode data[] =
{
	{ "Bug", 0xABCD },
	{ "Dog", 0x1331 },
	{ "Cat", 0x8844 },
	{ "Pig", 0xBB77 },
	{ "Bee", 0xFFEE }
};

struct cmpZip
{
	bool operator() (const ZipCode t1, const ZipCode t2) const
	{
		return t1.s[1] < t2.s[1];
	}
};

bool IsBB77(ZipCode t)
{
	return (t.zip == 0xBB77);
}

void Problem_3()
{
	// create file
	io::create("Yuancheng Zhang", "problem3.txt");

	// Original data
	ZipCode *p = &data[0];
	fprintf(io::getHandle(), "original\n\n");
	for (int i = 0; i < 5; i++)
	{
		fprintf(io::getHandle(), "        zippy[%d]: s:%s  zip:0x%x \n", i, p->s, p->zip);
		p++;
	}

	// a) insert the data into a stl:set in the order given
	//    use a compare function that sorts with the 2nd letter of the string 
	//    print it to the file (begin to end) order
	std::set<ZipCode, cmpZip> zip_set;
	int i = 0;
	for (; i < 5; i++)
	{
		zip_set.insert(data[i]);
	}

	fprintf(io::getHandle(), "\nstl: insert into a set\n");
	fprintf(io::getHandle(), "\t compare function sorts 2nd character of string\n\n");

	std::set<ZipCode, cmpZip>::iterator it;
	i = 0;
	for (it = zip_set.begin(); it != zip_set.end(); ++it, i++)
	{
		fprintf(io::getHandle(), "        zippy[%d]: s:%s  zip:0x%x \n", i, it->s, it->zip);
	}

	// b)  Find node {"Bee", 0xFFEE} in the set
	//     use the complete node in the search
	//     once found print the iterator's address and it's content
	fprintf(io::getHandle(), "\nstl: find node using complete node: {\"Bee\", 0xFFEE } \n\n");
	i = 0;
	it = zip_set.find({ "Bee", 0xFFEE });
	fprintf(io::getHandle(), "\t\tzippy: s:%s\n\t\t\t   zip:0x%x\n\t\t\t   addr: 0x%08X\n", it->s, it->zip, &it);


	// c)  Find the the string name associated with this zip data '0xBB77'
	//     Do not use the complete node, only the zip data
	//     Print the node contents and iterator address
	//
	//     NOTE: you can only use STL: set  - no maps!
	//
	//     hint:  use a custom predicate

	fprintf(io::getHandle(), "\nstl: find node using only the zip data: 0xBB77  \n\n");
	i = 0;
	it = std::find_if(zip_set.begin(), zip_set.end(), IsBB77);
	fprintf(io::getHandle(), "\t\tzippy: s:%s\n\t\t\t   zip:0x%x\n\t\t\t   addr: 0x%08X\n", it->s, it->zip, &it);

	// bye bye
	fprintf(io::getHandle(), "\n");
	io::destroy();
}