SDDS1
&description text="Error log--input: dcls.ele  lattice: dcls.lte", contents="error log, elegant output" &end
&associate filename="dcls.ele", path="/home/tong/Programming/projects/vFEL/DCLS", contents="elegant input, parent" &end
&associate filename="dcls.lte", path="/home/tong/Programming/projects/vFEL/DCLS", contents="elegant lattice, parent" &end
&parameter name=Step, type=long, description="simulation step" &end
&parameter name=When, type=string, description="phase of simulation when errors were asserted" &end
&column name=ParameterValue, type=double, description="Perturbed value" &end
&column name=ParameterError, type=double, description="Perturbation value" &end
&column name=ElementParameter, type=string, description="Parameter name" &end
&column name=ElementName, type=string, description="Element name" &end
&column name=ElementOccurence, type=long, description="Element occurence" &end
&column name=ElementType, type=string, description="Element type" &end
&data mode=ascii, lines_per_row=1, no_row_counts=1 &end
0              ! simulation step
pre-correction
-1.282581654870910e-05 -1.282581654870910e-05        FSE        B11 1  CSRCSBEND
7.068659469357893e-05 7.068659469357893e-05        FSE        B12 1  CSRCSBEND
-5.640209350156599e-05 -5.640209350156599e-05        FSE        B13 1  CSRCSBEND
-1.288662128684621e-04 -1.288662128684621e-04        FSE        B14 1  CSRCSBEND

