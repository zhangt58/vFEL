TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================


#=============================

#
# Build the IOC application
#

PROD_IOC = vfel
# vfel.dbd will be created and installed
DBD += vfel.dbd

# vfel.dbd will be made up from these files:
vfel_DBD += base.dbd

# Include dbd files from all support applications:
vfel_DBD += vfelSub.dbd

# Add all the support libraries needed by this IOC
vfel_LIBS += vfelSupport

# vfel_registerRecordDeviceDriver.cpp derives from vfel.dbd
vfel_SRCS += vfel_registerRecordDeviceDriver.cpp

vfel_SRCS += vfelSub.c
vfel_SRCS += datautils.cpp

# Build the main IOC entry point on workstation OSs.
vfel_SRCS_DEFAULT += vfelMain.cpp
vfel_SRCS_vxWorks += -nil-

# Add support from base/src/vxWorks if needed
#vfel_OBJS_vxWorks += $(EPICS_BASE_BIN)/vxComLibrary

# Finally link to the EPICS Base libraries
vfel_LIBS += $(EPICS_BASE_IOC_LIBS)

#===========================

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

