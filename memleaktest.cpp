#include <libsolidity/interface/CompilerStack.h>

using namespace std;
using namespace dev;

int main(void)
{
	string sol{
		"contract C {\n"
		"	function f(C c) pure public returns (C) {\n"
		"		return c;\n"
		"	}\n"
		"	function g() pure public returns (bytes4) {\n"
		"		return f(this).f;\n"
		"	}\n"
		"}\n"
	};
	string sourceCode = "pragma solidity >=0.0;\n" + sol;

	solidity::CompilerStack compiler;
	compiler.reset(false);
	compiler.addSource("<input>", sourceCode);
	compiler.compile();

	return 0;
}
