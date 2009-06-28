#!/bin/bash

#
# variables from arguments string in jdl
#
# format:
#
# 1: condor cluster number
# 2: condor process number
# 3: CMSSW_DIR
# 4: RUN_DIR
# 5: PARAMETER_SET (full path, has to contain all needed files in PoolSource and filled following variables with keywords:
#                   maxEvents = CONDOR_MAXEVENTS, output fileName = CONDOR_OUTPUTFILENAME)


CONDOR_CLUSTER=$1
CONDOR_PROCESS=$2
RUN_DIR=$3
PREFIX_NAME=$4

#
# header 
#

echo ""
echo "CMSSW on Condor"
echo ""

START_TIME=`/bin/date`
echo "started at $START_TIME"

echo ""
echo "parameter set:"
echo "CONDOR_CLUSTER: $CONDOR_CLUSTER"
echo "CONDOR_PROCESS: $CONDOR_PROCESS"
echo "RUN_DIR: $RUN_DIR"
echo "PARAMETER_SET: $PREFIX_NAME"

#
# setup software environment at FNAL for the given CMSSW release
#
source /uscmst1/prod/sw/cms/shrc uaf
export SCRAM_ARCH=slc4_ia32_gcc345
cd $RUN_DIR
eval `scramv1 runtime -sh`

#
# change to output directory
#
cd $RUN_DIR

#
# modify parameter-set
#

PARAMETER_SET_TEMPLATE=`echo ${PREFIX_NAME}_template_cfg.py`
PARAMETER_SET=`echo ${PREFIX_NAME}_cfg.py`
LOG=`echo ${PREFIX_NAME}.log`
SCRATCH_DIR=`echo ${_CONDOR_SCRATCH_DIR}`
echo ""
echo "Writing final parameter-set: $FINAL_PARAMETER_SET to RUN_DIR: $RUN_DIR"
echo ""

cat $PARAMETER_SET_TEMPLATE \
| sed -e s~CONDOR_SCRATCH_DIR~$SCRATCH_DIR~ \
> $PARAMETER_SET

#
# run cmssw
#

echo "run: time cmsRun $PARAMETER_SET > $LOG 2>&1"
cmsRun $PARAMETER_SET >> $LOG 2>&1
exitcode=$?

#
# end run
#

echo ""
END_TIME=`/bin/date`
echo "finished at $END_TIME"
exit $exitcode