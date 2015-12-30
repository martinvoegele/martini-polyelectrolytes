/*
 * =============================================================================
 *
 * Constructs a MARTINI topology for PSS
 *
 * Author:  Martin Voegele (martinvoegele1989@gmail.com)
 * Version: 16.03.2014
 * 
 * Compile: g++ -lm -o topgen-martini-pss topgen-martini-pss.cpp
 * Call:    ./topgen-martini-pss [number of monomers] [output file (.itp)]
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
    cout<<endl<<"Usage: ./topgen-martini-pss [number of monomers] [output file (.itp)]"<<endl<<endl;
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

  fprintf( outfile, ";\n; POLYSTYRENE SULFONATE (A-mapping) \n;\n" );
  fprintf( outfile, "; NUMBER OF MONOMERS:           %u\n;\n",n );
  fprintf( outfile, ";\n; If you use those parameters, please cite:\n; \n; M. Voegele, J. Smiatek, C. Holm \n; Coarse-grained simulations of polyelectrolyte complexes: MARTINI models for poly(styrene sulfonate) and poly(diallyldimethylammonium) \n; The Journal of Chemical Physics 143(24):243151, December 2015.\n; DOI: 10.1063/1.4937805 \n;\n\n" );


  /* write moleculetype */

  fprintf( outfile, "\n[ moleculetype ]\n" );
  fprintf( outfile, "; molname  nrexcl\n" );
  fprintf( outfile, "PSS%u	    3\n",n );



  /* write atoms */


  fprintf( outfile, "\n[ atoms ]\n" );
  fprintf( outfile, ";  nr    type       resnr  residu    atom    cgnr        charge\n" );

  numatom = 1;
  numunit = 1;

  // first monomer
  
  fprintf( outfile, "    1     SCY           1  STYR       B         1     0.00000E+00 \n" );
  fprintf( outfile, "    2     STY           1  STYR       R1        2     0.00000E+00 \n" );
  fprintf( outfile, "    3     STY           1  STYR       R2        3     0.00000E+00 \n" );
  fprintf( outfile, "    4     STY           1  STYR       R3        4     0.00000E+00 \n" );
  fprintf( outfile, "    5     Qa            1  STYR       S         5    -1.00000E+00 \n" );

 

  // middle monomers

  while( numunit < n-1 ) {

       numunit++;

       numatom = (numunit-2)*5 + 6;
       fprintf( outfile, "%5u     SCY       %5u  STYR       B     %5u     0.00000E+00 \n", numatom, numunit, numatom );
       numatom = (numunit-2)*5 + 7;
       fprintf( outfile, "%5u     STY       %5u  STYR       R1    %5u     0.00000E+00 \n", numatom, numunit, numatom );
       numatom = (numunit-2)*5 + 8;
       fprintf( outfile, "%5u     STY       %5u  STYR       R2    %5u     0.00000E+00 \n", numatom, numunit, numatom );
       numatom = (numunit-2)*5 + 9;
       fprintf( outfile, "%5u     STY       %5u  STYR       R3    %5u     0.00000E+00 \n", numatom, numunit, numatom );
       numatom = (numunit-2)*5 + 10; 
       fprintf( outfile, "%5u     Qa        %5u  STYR       S     %5u    -1.00000E+00 \n", numatom, numunit, numatom );
  }



  // last monomer

  numunit++;

  numatom = (numunit-3)*5 + 11;
  fprintf( outfile, "%5u     SCY       %5u  STYR       B     %5u     0.00000E+00 \n", numatom, numunit, numatom );
  numatom = (numunit-3)*5 + 12;
  fprintf( outfile, "%5u     STY       %5u  STYR       R1    %5u     0.00000E+00 \n", numatom, numunit, numatom );
  numatom = (numunit-3)*5 + 13;
  fprintf( outfile, "%5u     STY       %5u  STYR       R2    %5u     0.00000E+00 \n", numatom, numunit, numatom );
  numatom = (numunit-3)*5 + 14;
  fprintf( outfile, "%5u     STY       %5u  STYR       R3    %5u     0.00000E+00 \n", numatom, numunit, numatom );
  numatom = (numunit-3)*5 + 15;
  fprintf( outfile, "%5u     Qa        %5u  STYR       S     %5u    -1.00000E+00 \n", numatom, numunit, numatom );



  /* write bonds */

  fprintf( outfile, "\n[ bonds ]\n" );
  fprintf( outfile, ";   ai     aj funct   r             k\n" );

  numunit = 1;

  // first monomer

  fprintf( outfile, "    1     2    1     0.270000 8000.000000\n" );
  fprintf( outfile, "    1     7    1     0.270000 8000.000000\n" );
  fprintf( outfile, "    3     5    1     0.278000 8000.000000\n" );
  fprintf( outfile, "    4     5    1     0.278000 8000.000000\n" );


  // middle monomers

  while( numunit < n-1 ) {

    numunit++;

    ai = (numunit-2)*5 + 6;
    aj = (numunit-2)*5 + 7;
    fprintf( outfile, "%5u %5u    1     0.270000 8000.000000\n" , ai, aj );
    ai = (numunit-2)*5 + 6;
    aj = (numunit-2)*5 + 12;
    fprintf( outfile, "%5u %5u    1     0.270000 8000.000000\n" , ai, aj );
    ai = (numunit-2)*5 + 8;
    aj = (numunit-2)*5 + 10;
    fprintf( outfile, "%5u %5u    1     0.270000 8000.000000\n" , ai, aj );
    ai = (numunit-2)*5 + 9;
    aj = (numunit-2)*5 + 10;
    fprintf( outfile, "%5u %5u    1     0.270000 8000.000000\n" , ai, aj );

  }

  // last monomer

  numunit++;

  ai = (numunit-3)*5 + 11;
  aj = (numunit-3)*5 + 12;
  fprintf( outfile, "%5u %5u    1     0.270000 8000.000000\n" , ai, aj );
  ai = (numunit-3)*5 + 13;
  aj = (numunit-3)*5 + 15;
  fprintf( outfile, "%5u %5u    1     0.270000 8000.000000\n" , ai, aj );
  ai = (numunit-3)*5 + 14;
  aj = (numunit-3)*5 + 15;
  fprintf( outfile, "%5u %5u    1     0.270000 8000.000000\n" , ai, aj );



  /* write constraints */

  fprintf( outfile, "\n[ constraints ]\n" );
  fprintf( outfile, ";  ai  aj  funct length\n" );

  // first monomer

  numunit = 1;

  fprintf( outfile, "    2     3    1     0.270000 \n" );
  fprintf( outfile, "    3     4    1     0.270000 \n" );
  fprintf( outfile, "    4     2    1     0.270000 \n" );

  // middle monomers

  while( numunit < n-1 ) {

    numunit++;

    ai = (numunit-2)*5 + 7;
    aj = (numunit-2)*5 + 8;
    fprintf( outfile, "%5u %5u    1     0.270000 \n" , ai, aj );
    ai = (numunit-2)*5 + 8;
    aj = (numunit-2)*5 + 9;
    fprintf( outfile, "%5u %5u    1     0.270000 \n" , ai, aj );
    ai = (numunit-2)*5 + 9;
    aj = (numunit-2)*5 + 7;
    fprintf( outfile, "%5u %5u    1     0.270000 \n" , ai, aj );

  }

  // last monomer

  numunit++;

  ai = (numunit-3)*5 + 12;
  aj = (numunit-3)*5 + 13;
  fprintf( outfile, "%5u %5u    1     0.270000 \n" , ai, aj );
  ai = (numunit-3)*5 + 13;
  aj = (numunit-3)*5 + 14;
  fprintf( outfile, "%5u %5u    1     0.270000 \n" , ai, aj );
  ai = (numunit-3)*5 + 14;
  aj = (numunit-3)*5 + 12;
  fprintf( outfile, "%5u %5u    1     0.270000 \n" , ai, aj );



  /* write angles */

  fprintf( outfile, "\n[ angles ]\n" );
  fprintf( outfile, ";   ai     aj     ak    funct   theta         cth\n" );

  numunit = 1;

  fprintf( outfile, "    1      2      3    1   136.000000  100.000000 \n" );
  fprintf( outfile, "    1      2      4    1   136.000000  100.000000 \n" );
  fprintf( outfile, "    1      7      8    1   136.000000  100.000000 \n" );
  fprintf( outfile, "    1      7      9    1   136.000000  100.000000 \n" );
  fprintf( outfile, "    2      1      7    1   120.000000   25.000000 \n" );
  fprintf( outfile, "    1      7      6    1    52.000000  550.000000 \n" );


  while( numunit < n-1 ) {

       numunit++;

       ai = (numunit-2)*5 + 6; aj = (numunit-2)*5 + 7; ak = (numunit-2)*5 + 8; fprintf( outfile, "%5u  %5u  %5u    1   136.000000  100.000000 \n", ai, aj, ak );
       ai = (numunit-2)*5 + 6; aj = (numunit-2)*5 + 7; ak = (numunit-2)*5 + 9; fprintf( outfile, "%5u  %5u  %5u    1   136.000000  100.000000 \n", ai, aj, ak );
       ai = (numunit-2)*5 + 6; aj = (numunit-2)*5 + 12; ak = (numunit-2)*5 + 13; fprintf( outfile, "%5u  %5u  %5u    1   136.000000  100.000000 \n", ai, aj, ak );
       ai = (numunit-2)*5 + 6; aj = (numunit-2)*5 + 12; ak = (numunit-2)*5 + 14; fprintf( outfile, "%5u  %5u  %5u    1   136.000000  100.000000 \n", ai, aj, ak );
       ai = (numunit-2)*5 + 7; aj = (numunit-2)*5 + 6; ak = (numunit-2)*5 + 12; fprintf( outfile, "%5u  %5u  %5u    1   120.000000   25.000000 \n", ai, aj, ak );
       ai = (numunit-2)*5 + 6; aj = (numunit-2)*5 + 12; ak = (numunit-2)*5 + 11; fprintf( outfile, "%5u  %5u  %5u    1    52.000000  550.000000 \n", ai, aj, ak );
  }

  // last monomer

  numunit++;

  ai = (numunit-3)*5 + 11; aj = (numunit-3)*5 + 12; ak = (numunit-3)*5 + 13; fprintf( outfile, "%5u  %5u  %5u    1   136.000000  100.000000 \n", ai, aj, ak );
  ai = (numunit-3)*5 + 11; aj = (numunit-3)*5 + 12; ak = (numunit-3)*5 + 14; fprintf( outfile, "%5u  %5u  %5u    1   136.000000  100.000000 \n", ai, aj, ak );




  /* write dihedrals */


  fprintf( outfile, "\n[ dihedrals ]\n" );
  fprintf( outfile, "; ai aj ak al funct q0 cq\n" );

  // first monomer

  numunit = 1;
  fprintf( outfile, "    2      3      4      5   2   180.0000e+00 1.673600e+02 \n" );

  // middle monomers

  while( numunit < n-1 ) {

       numunit++;
       ai = (numunit-2)*5 + 7; aj = (numunit-2)*5 + 8; ak = (numunit-2)*5 + 9; al = (numunit-2)*5 + 10;
       fprintf( outfile, "%5u  %5u  %5u  %5u   2   180.0000e+00 1.673600e+02 \n", ai, aj, ak, al );

  }

  // last monomer

  numunit++;
  ai = (numunit-3)*5 + 12; aj = (numunit-3)*5 + 13; ak = (numunit-3)*5 + 14; al = (numunit-3)*5 + 15;
  fprintf( outfile, "%5u  %5u  %5u  %5u   2   180.0000e+00 1.673600e+02 \n", ai, aj, ak, al );



  /* close the stream */

  fclose (outfile);
  

  return 0;

}
