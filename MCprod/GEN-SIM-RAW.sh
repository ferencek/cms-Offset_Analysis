#!/bin/bash

#
# variables from arguments string in jdl
#

CONDOR_CLUSTER=$1
CONDOR_PROCESS=$2
RUN_DIR=$3
PREFIX_NAME=$4
RANDOM_NUMBER=$5
NUM_EVENTS_PER_JOB=$6

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
echo "RANDOM_NUMBER: $RANDOM_NUMBER"
echo "NUM_EVENTS_PER_JOB: $NUM_EVENTS_PER_JOB"

#
# setup software environment at FNAL for the given CMSSW release
#
source /uscmst1/prod/sw/cms/shrc prod
export SCRAM_ARCH=slc4_ia32_gcc345
cd $RUN_DIR
eval `scramv1 runtime -sh`

#
# modify parameter-set
#

PARAMETER_SET=`echo ${RUN_DIR}/../${PREFIX_NAME}_cfg.py`
FINAL_NAME=`echo ${PREFIX_NAME}_${CONDOR_CLUSTER}_${CONDOR_PROCESS}`
FINAL_PARAMETER_SET=`echo ${FINAL_NAME}_cfg.py`
FINAL_LOG=`echo $FINAL_NAME.log`
SCRATCH_DIR=`echo ${_CONDOR_SCRATCH_DIR}`
echo ""
echo "Writing final parameter-set: $FINAL_PARAMETER_SET to RUN_DIR: $RUN_DIR"
echo ""

let "FINAL_RANDOMNUMBER = $CONDOR_PROCESS*100 + $RANDOM_NUMBER"
let "SKIP = $CONDOR_PROCESS * NUM_EVENTS_PER_JOB"

cat $PARAMETER_SET \
| sed -e s/CONDOR_MAXEVENTS/$NUM_EVENTS_PER_JOB/ \
| sed -e s/CONDOR_SKIPEVENTS/$SKIP/ \
| sed -e s/CONDOR_RANDOMNUMBER/$FINAL_RANDOMNUMBER/ \
| sed -e s/CONDOR_OUTPUTFILENAME/$FINAL_NAME/ \
| sed -e s~CONDOR_SCRATCH_DIR~$SCRATCH_DIR~ \
> $FINAL_PARAMETER_SET

#
# run cmssw
#

echo "run: time cmsRun $FINAL_PARAMETER_SET > $FINAL_LOG 2>&1"
cmsRun $FINAL_PARAMETER_SET >> $FINAL_LOG 2>&1
exitcode=$?

#
# end run
#

echo ""
END_TIME=`/bin/date`
echo "finished at $END_TIME"
exit $exitcode