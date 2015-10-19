# martini-polyelectrolytes
Generate Martini polyelectrolyte topology files for use with Gromacs

###Usage:
 - Run ./compile.sh (make sure it is executable)
 - You get two binary files: topgen-martini-pdadma, topgen-martini-pss
 - Run the binary files providing the number of monomers and the name of the .itp file to be created, e.g:
   ./topgen-martini-pdadma 30 pdadma.itp
   ./topgen-martini-pss 30 pss.itp

###Requirements:
 - Linux 
 - g++
