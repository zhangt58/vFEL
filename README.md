vFEL
====

Virtual machine for free-electron laser facility, technically, `vFEL` is
an EPICS soft-IOC incorprating LINAC and FEL physics, to simulate the 
real machine's behavior. Up to now, the numerical simulations about 
the LINAC dynamics and FEL generation are handled by calling external
programs --- `Elegant` and `Genesis 1.3`, respectively, however it should 
be more efficient provided that all the external simulating procedures are 
built into C/C++ libraries, (i.e. to built `Elegant` and `Genesis 1.3` into 
standalone libraries which requires much more effect).

Todo
----
1. Complete FEL part;
2. Build template files for EPICS database generation;
3. Combine LINAC and FEL lattice, to build the virtual machine.

