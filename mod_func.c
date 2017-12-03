#include <stdio.h>
#include "hocdec.h"
#define IMPORT extern __declspec(dllimport)
IMPORT int nrnmpi_myid, nrn_nobanner_;

extern void _AXBLANK_reg();
extern void _AXNODE_reg();
extern void _SAXNODE_reg();

modl_reg(){
	//nrn_mswindll_stdio(stdin, stdout, stderr);
    if (!nrn_nobanner_) if (nrnmpi_myid < 1) {
	fprintf(stderr, "Additional mechanisms from files\n");

fprintf(stderr," AXBLANK.mod");
fprintf(stderr," AXNODE.mod");
fprintf(stderr," SAXNODE.mod");
fprintf(stderr, "\n");
    }
_AXBLANK_reg();
_AXNODE_reg();
_SAXNODE_reg();
}
