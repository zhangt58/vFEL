#!../../bin/linux-x86_64/vfel

< envPaths
< envPaths.sim

cd ${TOP}

dbLoadDatabase "dbd/vfel.dbd"
vfel_registerRecordDeviceDriver pdbbase

dbLoadRecords("db/vfel.db",   "fel=sxfel")
dbLoadRecords("db/lattice.db","fel=sxfel")

cd ${TOP}/iocBoot/${IOC}
iocInit
