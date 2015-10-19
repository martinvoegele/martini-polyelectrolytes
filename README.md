# martini-polyelectrolytes
Generate Martini polyelectrolyte topology files for use with Gromacs

###Usage:
 - Run `./compile.sh` (make sure it is executable)
 - You get two binary files: topgen-martini-pdadma, topgen-martini-pss
 - Run the binary files providing the number of monomers and the name of the .itp file to be created, e.g:
```
   ./topgen-martini-pdadma 30 pdadma.itp 
   ./topgen-martini-pss 30 pss.itp
```
- Coordinates can be created from those topologies with molmaker.py by Manuel Melo (available at the 
[Martini homepage](http://cgmartini.nl/index.php/tools2/proteins-and-bilayers)).

###Requirements:
 - Linux 
 - g++
