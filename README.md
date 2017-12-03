# C-Fiber-simulation-code
A NERUON model to simulate the firing of a C-Fiber with a uniform and clustering of sodium channels.
Created by Nabeel Chowdhury on 12/1/17

This code is set to produce an action potential across a 2mm C-fiber. This length was chosen to make the calculation of speed easier.
The model is set to produce the shape and speed of a typical C-Fiber action potential.

There are two difference sets of code. One for a uniform concentration of sodium channels and another for clusters of sodium channels
to make a C-Fiber that is technically able to perform Saltatory conduction. This latter code was inspired by a theory developed by Ali Neishabouri.
The model parameters were found and modified from the following papers:
Neishabouri A, Faisal AA. Saltatory conduction in unmyelinated axons: clustering of Na+ channels on lipid rafts enables micro-saltatory conduction in C-fibers.
Tigerholm J, Petersson ME, Oberja O, et al. Modeling activity-dependent changes of axonal spike in primary afferent C-nociceptors. Journal of Neurophysiology.

The modifiable files for the uniform distribution code is as follows:
AXNODE.mod (This file contains the definitions of the channel properties)
Uniformaxon.hoc (This is the file that is run and contains the parameters that define the neuron)
Uniformaxon.ses (This calls the figures that I was using in testing)
uniforminit.hoc (This calls the other files to run together. this is the file you want to run for the simulation)

The modifiable files for the clustered distribution code is as follows:
SAXNODE.mod (This is a modified version of AXNODE.mod to get saltatory conduction to work)
AXBLANK.mod (this is the file that defines the channel properties in the spaces between the clusters of sodium channels)
Saltatoryaxon.hoc (This is the file that is run and contains the parameters that define the neuron and allows you to change the size of clusters and internode lengths)
Saltatoryaxon.ses (This calls the figures that I was using in testing)
saltatoryinit.hoc (This calls the other files to run together. this is the file you want to run for the simulation)

If you want to change the channel properties of either system, you must run the mknrndll function that comes with NEURON to recompile the files.
If you want to change the axon's physical properties in the Uniformaxon.hoc or Saltatoryaxon.hoc files, you will not need to recompile.

If you change the cluster sizes and/or the internodal sizes in the Saltatoryaxon.hoc file, the figures that come up will no longer work correctly and you will need to 
make a new voltage and space plot yourself.
