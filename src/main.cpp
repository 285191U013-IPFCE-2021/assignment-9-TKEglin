extern "C"{
    #include "search.h"
    #include "dfs.h"
    #include <stdio.h>
    #include <stdlib.h>
}

    #include <cstdio>

// File for sandboxing and trying out code
int main(int argc, char **argv) {
    node *groot = make_node (4,
			make_node (7,
				    make_node (28,
						make_node (77,
							NULL,
							NULL),
						make_node (23,
							NULL,
							NULL)),
				    make_node (86,
						make_node (3,
							NULL,
							NULL),
						make_node (9,
					    	NULL,
						   NULL))),
			make_node (98,
				    NULL,
				    NULL));
    
    DFT(groot);

    return 0;
}