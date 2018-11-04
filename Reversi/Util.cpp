#include "Util.h"

namespace Util{

char* Util::ToCharPtr( const char * str ){
	int&& length = 0;
	while( str[length] != '\0' ){
		++length;
	}

	char* converted = new char[length + 1];
	for( int i = 0; i <= length; ++i ){
		converted[i] = str[i];
	}

	return converted;
}

}