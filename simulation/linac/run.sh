#!/bin/bash

#
# script to make vFEL running, generate date stream for high-level usage.
#
# Tong Zhang
# 2015-12-14, 18:31:30
#

ltefile=$1
Q09=$2
Q10=$3
sed -i "s/\(Q09.*L.*\, *K1.*=\)\(.*\)/\1 ${Q09}/i" ${ltefile}
sed -i "s/\(Q10.*L.*\, *K1.*=\)\(.*\)/\1 ${Q10}/i" ${ltefile}

make soft
