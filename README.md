# C-Fiber Simulation

A NERUON model to simulate the firing of a C-Fiber with a uniform or clustering of sodium channels. This model was made for a class at Case Western Reserve University for the final project in EBME 421. This code is set to produce an action potential across a 2mm C-fiber. This length was chosen to make the calculation of speed easier. The model is set to produce the shape and speed of a typical C-Fiber action potential.

## Getting Started

The init files of each model are the scprits you want to run and the rest are background files that define the usage of all of the parameters.

### The modifiable files for the uniform distribution code are as follows:

* AXNODE.mod (This file contains the definitions of the channel properties)
* Uniformaxon.hoc (This is the file that is run and contains the parameters that define the neuron)
* Uniformaxon.ses (This calls the figures that I was using in testing)
* uniforminit.hoc (This calls the other files to run together. this is the file you want to run for the simulation)

### The modifiable files for the clustered distribution code are as follows:

* SAXNODE.mod (This is a modified version of AXNODE.mod to get saltatory conduction to work)
* AXBLANK.mod (this is the file that defines the channel properties in the spaces between the clusters of sodium channels)
* Saltatoryaxon.hoc (This is the file that is run and contains the parameters that define the neuron and allows you to change the size of clusters and internode lengths)
* Saltatoryaxon.ses (This calls the figures that I was using in testing)
* saltatoryinit.hoc (This calls the other files to run together. this is the file you want to run for the simulation)

### Prerequisits

NEURON v7.5 or later

## Runnig the Model

Run either the saltatoryinit.hoc or uniforminit.hoc file in the correct directory. If you want to change the channel properties of either system, you must run the mknrndll function that comes with NEURON to recompile the files. If you want to change the axon's physical properties in the Uniformaxon.hoc or Saltatoryaxon.hoc files, you will not need to recompile. If you change the cluster sizes and/or the internodal sizes in the Saltatoryaxon.hoc file, the figures that come up will no longer work correctly and you will need to make a new voltage and space plot yourself.

## Papers for the Parameters in the Saltatory Conduction Model

* Neishabouri A, Faisal AA. Saltatory conduction in unmyelinated axons: clustering of Na+ channels on lipid rafts enables micro-saltatory conduction in C-fibers.
* Tigerholm J, Petersson ME, Oberja O, et al. Modeling activity-dependent changes of axonal spike in primary afferent C-nociceptors. Journal of Neurophysiology.

## Built With

* [NEURON](https://www.neuron.yale.edu/neuron/) - The program used to run
* [Notepad ++](https://notepad-plus-plus.org/) - source code editor used to write the scripts. 
* [Notepad ++ Neuron Library Installation](https://www.neuron.yale.edu/phpBB/viewtopic.php?t=1763)

## Author
* **Nabeel Chowdhury** - Original author on 12/1/17

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details
