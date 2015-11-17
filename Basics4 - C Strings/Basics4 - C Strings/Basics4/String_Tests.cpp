#include "UnitTest.h"
#include <string.h>
#include <stdio.h>
#include "CopyingStrings.h"
#include "ComparingStrings.h"
#include "LengthOfStrings.h"
#include "CopyToBuffer.h"
#include "SortStrings.h"

TEST( compare_strings, StringTests)
{
	char *s1 = "asf;ldj2";
	char *s2 = "asf;ldk2";
	char *s3 = "asf;lde2";
	char *s4 = "asf;lde21";

	CHECK_EQUAL( StringCompare_1( s1, s1 ), 0 );
	CHECK_EQUAL( StringCompare_2( s1, s1 ), 0 );
	CHECK_EQUAL( StringCompare_3( s1, s1 ), 0 );

	CHECK_EQUAL( StringCompare_1( s1, s2 ), -1 );
	CHECK_EQUAL( StringCompare_2( s1, s2 ), -1 );
	CHECK_EQUAL( StringCompare_3( s1, s2 ), -1 );

	CHECK_EQUAL( StringCompare_1( s1, s3 ), 1 );
	CHECK_EQUAL( StringCompare_2( s1, s3 ), 1 );
	CHECK_EQUAL( StringCompare_3( s1, s3 ), 1 );

	CHECK_EQUAL( StringCompare_1( s1, s4 ), 1 );
	CHECK_EQUAL( StringCompare_2( s1, s4 ), 1 );
	CHECK_EQUAL( StringCompare_3( s1, s4 ), 1 );

	// I HATE string.h lack of protection for null
	// --> WOW
	// StringCopy_1( s1, 0 );
	//  StringCopy_1( 0, s2 );

}

TEST( copy_strings, StringTests)
{
	char *d1 = new char[10];
	char *d2 = new char[10];
	char *d3 = new char[10];
	char *s2 = "12480973";
	char *s;

	s = StringCopy_1( d1, s2 );
	CHECK_EQUAL( (int)s, (int) d1);
	CHECK_EQUAL( strcmp( d1, s2 ), 0 );

	s = StringCopy_2( d2, s2 );
	CHECK_EQUAL( (int)s, (int) d2);
	CHECK_EQUAL( strcmp( d2, s2 ), 0 );

	s = StringCopy_3( d3, s2 );
	CHECK_EQUAL( (int)s, (int) d3);
	CHECK_EQUAL( strcmp( d3, s2 ), 0 );

	// I HATE string.h lack of protection for null
	// --> WOW
	// s = StringCopy_1( d1, 0 );
	// s = StringCopy_1( 0, s2 );

}


TEST( strings_len, StringTests)
{
	char *s1 = "12480973";
	char *s0 = "";
	char s4[] = {'\0'};
	char s3[20] = "2233";
	
	CHECK_EQUAL( LengthOfString_1(s1), 8 );
	CHECK_EQUAL( LengthOfString_2(s1), 8 );

	CHECK_EQUAL( LengthOfString_1(s3), 4 );
	CHECK_EQUAL( LengthOfString_2(s3), 4 );

	CHECK_EQUAL( LengthOfString_1(s0), 0 );
	CHECK_EQUAL( LengthOfString_2(s0), 0 );

	CHECK_EQUAL( LengthOfString_1(s4), 0 );
	CHECK_EQUAL( LengthOfString_2(s4), 0 );

	// I HATE string.h lack of protection for null
	// --> WOW
	// strlen( 0 );


}


TEST( Copy_to_Buffer, StringTests)
{
	dog fido;
	char *s1 = "MonkeyBra";
	char *s2 = "Mono";
	char *s3 = "";
	char *s;

	fido.setMessage( "MonkeyBrainsAreYummy");
	s = fido.getMessage();
	CHECK_EQUAL( strcmp(s,s1), 0);
	fido.print();

	fido.setMessage( "Mono");
	s = fido.getMessage();
	CHECK_EQUAL( strcmp(s,s2), 0 );
	fido.print();

	fido.setMessage( 0);
	s = fido.getMessage();
	CHECK_EQUAL( strcmp(s,s3), 0 );
	fido.print();

}

TEST( sort_strings, StringTests)
{
	char *s1 = "everclear cider beer daiquiri bacardi";
	char *s2 = "pug beagle chihuahua akita doberman";
	char *s3 = "blue azul rojo red green verde blanco white negro black";

	char *a1 = "bacardi beer cider daiquiri everclear";
	char *a2 = "akita beagle chihuahua doberman pug";
	char *a3 = "azul black blanco blue green negro red rojo verde white";

	char *r1 = new char[ strlen(s1) + 1 ];
	char *r2 = new char[ strlen(s2) + 1 ];
	char *r3 = new char[ strlen(s3) + 1 ];
	
	ReorderAlphabetical( s1, r1 );
	CHECK_EQUAL( strcmp( r1, a1 ), 0 );
	//printf("\n");
	//printf("orig: %s  len:%d \n",s1);
   // printf(" new: %s  len:%d \n",r1);

	ReorderAlphabetical( s2, r2 );
	CHECK_EQUAL( strcmp( r2, a2 ), 0 );
	//printf("\n");
	//printf("orig: %s\n",s2);
	//printf(" new: %s\n",r2);

	ReorderAlphabetical( s3, r3 );
	CHECK_EQUAL( strcmp( r3, a3 ), 0 );
	//printf("\n");
	//printf("orig: %s\n",s3);
	//printf(" new: %s\n",r3);

}

TEST( sort_strings_wordlength, StringTests)
{
	char *s1 = "everclear cider beer daiquiri bacardi";
	char *s2 = "pug beagle chihuahua akita doberman";
	char *s3 = "blue azul rojo red green verde blanco white negro black";

	char *a1 = "beer cider bacardi daiquiri everclear";
	char *a2 = "pug akita beagle doberman chihuahua";
	char *a3 = "red azul blue rojo black green negro verde white blanco";

	char *r1 = new char[ strlen(s1) + 1 ];
	char *r2 = new char[ strlen(s2) + 1 ];
	char *r3 = new char[ strlen(s3) + 1 ];
	
	ReorderWordLength( s1, r1 );
	CHECK_EQUAL( strcmp( r1, a1 ), 0 );
	//printf("\n");
	//printf("orig: %s  len:%d \n",s1);
    //printf(" new: %s  len:%d \n",r1);
	
	ReorderWordLength( s2, r2 );
	CHECK_EQUAL( strcmp( r2, a2 ), 0 );
	//printf("\n");
	//printf("orig: %s\n",s2);
	//printf(" new: %s\n",r2);

	ReorderWordLength( s3, r3 );
	CHECK_EQUAL( strcmp( r3, a3 ), 0 );
	//printf("\n");
	//printf("orig: %s\n",s3);
	//printf(" new: %s\n",r3);

}