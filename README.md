# N-Queen CNF Generator for minisat

## How to build and run

	$ make clean
	$ make
	$ n-queen > in.cnf
	$ minisat in.cnf out.cnf

You may edit the number of clauses on the first line. To find out all the possible satisfactional conditions, you need to supply the last satisfactional condition to the `in.cnf`, then run the next round.
