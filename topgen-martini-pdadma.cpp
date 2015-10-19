/*
 * =============================================================================
 *
 * Constructs a MARTINI topology for PDADMA
 *
 * Author:  Martin Voegele (martinvoegele1989@gmail.com)
 * Version: 17.03.2014
 * 
 * Compile: g++ -lm -o topgen-martini-pdadma topgen-martini-pdadma.cpp
 * Call:    ./topgen-martini-pdadma [number of monomers] [output file (.itp)]
 *
 * =============================================================================
 */



#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <ios>
#include <string>
#include <fstream>


using namespace std;



int main(int argc, char **argv){



  unsigned int n;              // total number of monomers
  unsigned int numatom;        // counter for atom number
  unsigned int numunit;        // counter for monomer unit number
  unsigned int ai, aj, ak, al; // atom counters

  FILE * outfile;



  /* check for correct number of arguments */

  if( argc != 3 ){
    cout<<endl<<"Wrong number of arguments!"<<endl;
    cout<<endl<<"Usage: ./topgen-martini-pdadma [number of monomers] [output file (.itp)]"<<endl<<endl;
  }



  /* read number of monomers */

  n = atoi(argv[1]);

  if( n < 3 ){
    cout<<endl<<"Number of monomers must be at least 3."<<endl;
    return 0;
  }



  /* open the stream */

  outfile = fopen (argv[2],"w");



  /* write header */

  fprintf( outfile, ";\n; POLY(DIALLYLDIMETHYLAMMONIUM) \n;\n" );
  fprintf( outfile, "; NUMBER OF MONOMERS:           %u\n;\n",n );



  /* write moleculetype */

  fprintf( outfile, "\n[ moleculetype ]\n" );
  fprintf( outfile, "; molname  nrexcl\n" );
  fprintf( outfile, "PDADMA%u	    2\n",n );



  /* write atoms */


  fprintf( outfile, "\n[ atoms ]\n" );
  fprintf( outfile, ";  nr    type       resnr  residu    atom    cgnr        charge\n" );

  numatom = 1;
  numunit = 1;

  // first monomer
  
  fprintf( outfile, "    1     SC1           1  DADMA      B1        1     0.00000E+00 \n" );
  fprintf( outfile, "    2     SC1           1  DADMA      B2        2     0.00000E+00 \n" );
  fprintf( outfile, "    3     SQd           1  DADMA      N         3     1.00000E+00 \n" );

  // middle monomers

  while( numunit < n-1 ) {

       numunit++;

       numatom = (numunit-2)*3 + 4;
       fprintf( outfile, "%5u     SC1       %5u  DADMA      B1    %5u     0.00000E+00 \n", numatom, numunit, numatom );
       numatom = (numunit-2)*3 + 5;
       fprintf( outfile, "%5u     SC1       %5u  DADMA      B2    %5u     0.00000E+00 \n", numatom, numunit, numatom );
       numatom = (numunit-2)*3 + 6; 
       fprintf( outfile, "%5u     SQd       %5u  DADMA      N     %5u     1.00000E+00 \n", numatom, numunit, numatom );
  }

  // last monomer

  numunit++;

  numatom = (numunit-3)*3 + 7;
  fprintf( outfile, "%5u     SC1       %5u  DADMA      B1    %5u     0.00000E+00 \n", numatom, numunit, numatom );
  numatom = (numunit-3)*3 + 8;
  fprintf( outfile, "%5u     SC1       %5u  DADMA      B2    %5u     0.00000E+00 \n", numatom, numunit, numatom );
  numatom = (numunit-3)*3 + 9;
  fprintf( outfile, "%5u     SQd       %5u  DADMA      N     %5u     1.00000E+00 \n", numatom, numunit, numatom );



  /* write bonds */

  fprintf( outfile, "\n[ bonds ]\n" );
  fprintf( outfile, ";   ai     aj funct   r             k\n" );

  numunit = 1;

  // first monomer

  fprintf( outfile, "    2     4    1     0.270000 8000.000000\n" );

  // middle monomers

  while( numunit < n-1 ) {

    numunit++;

    ai = (numunit-2)*3 + 5;
    aj = (numunit-2)*3 + 7;
    fprintf( outfile, "%5u %5u    1     0.270000 8000.000000\n" , ai, aj );

  }

  // last monomer

  numunit++;





  /* write constraints */

  fprintf( outfile, "\n[ constraints ]\n" );
  fprintf( outfile, ";  ai  aj  funct length\n" );

  // first monomer

  numunit = 1;

  fprintf( outfile, "    1     2    1     0.270000 \n" );
  fprintf( outfile, "    2     3    1     0.270000 \n" );
  fprintf( outfile, "    3     1    1     0.270000 \n" );

  // middle monomers

  while( numunit < n-1 ) {

    numunit++;

    ai = (numunit-2)*3 + 4;
    aj = (numunit-2)*3 + 5;
    fprintf( outfile, "%5u %5u    1     0.270000 \n" , ai, aj );
    ai = (numunit-2)*3 + 5;
    aj = (numunit-2)*3 + 6;
    fprintf( outfile, "%5u %5u    1     0.270000 \n" , ai, aj );
    ai = (numunit-2)*3 + 6;
    aj = (numunit-2)*3 + 4;
    fprintf( outfile, "%5u %5u    1     0.270000 \n" , ai, aj );

  }

  // last monomer

  numunit++;

  ai = (numunit-3)*3 + 7;
  aj = (numunit-3)*3 + 8;
  fprintf( outfile, "%5u %5u    1     0.270000 \n" , ai, aj );
  ai = (numunit-3)*3 + 8;
  aj = (numunit-3)*3 + 9;
  fprintf( outfile, "%5u %5u    1     0.270000 \n" , ai, aj );
  ai = (numunit-3)*3 + 9;
  aj = (numunit-3)*3 + 7;
  fprintf( outfile, "%5u %5u    1     0.270000 \n" , ai, aj );



  /* write angles */

  fprintf( outfile, "\n[ angles ]\n" );
  fprintf( outfile, ";   ai     aj     ak    funct   theta         cth\n" );

  // first monomer

  numunit = 1;

  fprintf( outfile, "    1      2      4    1   136.000000  100.000000 \n" );
  fprintf( outfile, "    2      4      5    1   136.000000  100.000000 \n" );

  // middle monomers

  while( numunit < n-1 ) {

       numunit++;

       ai = (numunit-2)*3 + 4; aj = (numunit-2)*3 + 5; ak = (numunit-2)*3 + 7; fprintf( outfile, "%5u  %5u  %5u    1   136.000000  100.000000 \n", ai, aj, ak );
       ai = (numunit-2)*3 + 5; aj = (numunit-2)*3 + 7; ak = (numunit-2)*3 + 8; fprintf( outfile, "%5u  %5u  %5u    1   136.000000  100.000000 \n", ai, aj, ak );

  }

  // last monomer

  numunit++;




  /* close the stream */

  fclose (outfile);
  

  return 0;

}
