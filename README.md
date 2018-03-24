# martini-polyelectrolytes
Generate Martini polyelectrolyte topology files for use with Gromacs.

Background information on the models can be found in [J. Chem. Phys. 143, 243151 (2015)](http://scitation.aip.org/content/aip/journal/jcp/143/24/10.1063/1.4937805).
Please cite this article if you use the Martini polyelectrolyte models in a publication.

## Usage:
 - Run `./compile.sh` (make sure it is executable)
 - You get two binary files: topgen-martini-pdadma, topgen-martini-pss
 - Run the binary files providing the number of monomers and the name of the .itp file to be created, e.g:
```
   ./topgen-martini-pdadma 30 pdadma.itp 
   ./topgen-martini-pss 30 pss.itp
```
 - Coordinates can be created from those topologies with molmaker.py by Manuel Melo (available at the 
[Martini homepage](http://cgmartini.nl/index.php/tools2/proteins-and-bilayers)).

 - Instead of the standard MArtini itp file, please include the Martini .itp file martini_v2.2P_PS_corr.itp provided here to your Gromacs topology.

## Requirements:
 - Linux 
 - g++
