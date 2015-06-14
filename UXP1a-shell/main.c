#include "header.h"
#include "unix.h"

extern int yyparse();

int main(int argc, char **argv, char *envp[])
{
	if ((argc > 1) && (freopen(argv[1], "r", stdin) == NULL)) {
		exit( 1 );
	}
	initShell();
	yyparse();

	return 0;
}


