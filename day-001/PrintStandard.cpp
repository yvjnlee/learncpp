// this program lets u know which cpp standard ur running

#include <iostream>

const int numStandards = 7;

// c++26 stdCode is just a placeholder since standard isnt finalized yet
const long stdCode[numStandards] = { 199711L, 201103L, 201402L, 201703L, 202302L, 202612L };
const char* stdName[numStandards] = { "Pre-C++11", "C++11", "C++14", "C++17", "C++20", "C++23", "C++26" };

long getCPPStandard()
{
	// mostly for visual studio since visual studio doesnt support __cplusplus
#if defined (_MSVC_LANG)
	return (_MSVC_LANG);
#elif defined (_MSC_VER)
	return -1;
#else
	return __cplusplus;
#endif
}

int main()
{
	long standard = getCPPStandard();
	
	// if the user is using a version of visual studio older than 2015
	if (standard == -1)
	{
		std::cout << "Error: Unable to detect ur language standard cause ur using an old version of visual studio u bozo. L + ratio.\n";
		return 0;
	}
	
	for (int i = 0; i < numStandards; ++i)
	{
		// if we find the exact version
		if (standard == stdCode[i])
		{
			std::cout << "ur compiler is using " << stdName[i] << " (language standard code " << standard << "L)\n";
			break;
		}
		
		// if the standard is some in between one then we know its a pre-release or preview
		if (standard < stdCode[i])
		{
			std::cout << "ur compiler is using a preview/pre-release of " << stdName[i] << " (language standard code " << standard << "L\n";
			break;
		}
	}

	return 0;
}
