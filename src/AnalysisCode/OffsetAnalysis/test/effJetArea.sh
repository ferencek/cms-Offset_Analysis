#!/bin/bash

# setup software environment
export SCRAM_ARCH=slc4_ia32_gcc345
eval `scramv1 runtime -sh`

CONFIG_FILE_TEMPLATE=`echo effJetArea_template_cfg.py`
CONFIG_FILE=`echo effJetArea_cfg.py`

echo ""
echo "`/bin/date` >> Starting effJetArea on $HOST:"
#==========================================================
echo "`/bin/date` >> QCDpt15_NN analysis started..."

cat $CONFIG_FILE_TEMPLATE \
| sed -e s/MAX_EVTS/-1/ \
| sed -e s/INPUT_POOLSOURCE/QCDpt15_NN/ \
| sed -e s/OUTPUT_FILENAME/effJetArea_QCDpt15_NN/ \
> $CONFIG_FILE

cmsRun $CONFIG_FILE >& effJetArea_QCDpt15_NN.log 

echo "`/bin/date` >> QCDpt15_NN analysis completed!"
#==========================================================
echo "`/bin/date` >> QCDpt15_plus_1PU_InTime_Poisson analysis started..."

cat $CONFIG_FILE_TEMPLATE \
| sed -e s/MAX_EVTS/-1/ \
| sed -e s/INPUT_POOLSOURCE/QCDpt15_plus_1PU_InTime_Poisson/ \
| sed -e s/OUTPUT_FILENAME/effJetArea_QCDpt15_plus_1PU_InTime_Poisson/ \
> $CONFIG_FILE

cmsRun $CONFIG_FILE >& effJetArea_QCDpt15_plus_1PU_InTime_Poisson.log 

echo "`/bin/date` >> QCDpt15_plus_1PU_InTime_Poisson analysis completed!"
#==========================================================
echo "`/bin/date` >> QCDpt15_plus_1PU_Full_Poisson analysis started..."

cat $CONFIG_FILE_TEMPLATE \
| sed -e s/MAX_EVTS/-1/ \
| sed -e s/INPUT_POOLSOURCE/QCDpt15_plus_1PU_Full_Poisson/ \
| sed -e s/OUTPUT_FILENAME/effJetArea_QCDpt15_plus_1PU_Full_Poisson/ \
> $CONFIG_FILE

cmsRun $CONFIG_FILE >& effJetArea_QCDpt15_plus_1PU_Full_Poisson.log 

echo "`/bin/date` >> QCDpt15_plus_1PU_Full_Poisson analysis completed!"
#==========================================================
echo "`/bin/date` >> QCDpt15_plus_2PU_InTime_Poisson analysis started..."

cat $CONFIG_FILE_TEMPLATE \
| sed -e s/MAX_EVTS/-1/ \
| sed -e s/INPUT_POOLSOURCE/QCDpt15_plus_2PU_InTime_Poisson/ \
| sed -e s/OUTPUT_FILENAME/effJetArea_QCDpt15_plus_2PU_InTime_Poisson/ \
> $CONFIG_FILE

cmsRun $CONFIG_FILE >& effJetArea_QCDpt15_plus_2PU_InTime_Poisson.log 

echo "`/bin/date` >> QCDpt15_plus_2PU_InTime_Poisson analysis completed!"
#==========================================================
echo "`/bin/date` >> QCDpt15_plus_2PU_Full_Poisson analysis started..."

cat $CONFIG_FILE_TEMPLATE \
| sed -e s/MAX_EVTS/-1/ \
| sed -e s/INPUT_POOLSOURCE/QCDpt15_plus_2PU_Full_Poisson/ \
| sed -e s/OUTPUT_FILENAME/effJetArea_QCDpt15_plus_2PU_Full_Poisson/ \
> $CONFIG_FILE

cmsRun $CONFIG_FILE >& effJetArea_QCDpt15_plus_2PU_Full_Poisson.log 

echo "`/bin/date` >> QCDpt15_plus_2PU_Full_Poisson analysis completed!"
#==========================================================
echo "`/bin/date` >> QCDpt15_plus_5PU_InTime_Poisson analysis started..."

cat $CONFIG_FILE_TEMPLATE \
| sed -e s/MAX_EVTS/-1/ \
| sed -e s/INPUT_POOLSOURCE/QCDpt15_plus_5PU_InTime_Poisson/ \
| sed -e s/OUTPUT_FILENAME/effJetArea_QCDpt15_plus_5PU_InTime_Poisson/ \
> $CONFIG_FILE

cmsRun $CONFIG_FILE >& effJetArea_QCDpt15_plus_5PU_InTime_Poisson.log 

echo "`/bin/date` >> QCDpt15_plus_5PU_InTime_Poisson analysis completed!"
#==========================================================
echo "`/bin/date` >> QCDpt15_plus_5PU_Full_Poisson analysis started..."

cat $CONFIG_FILE_TEMPLATE \
| sed -e s/MAX_EVTS/-1/ \
| sed -e s/INPUT_POOLSOURCE/QCDpt15_plus_5PU_Full_Poisson/ \
| sed -e s/OUTPUT_FILENAME/effJetArea_QCDpt15_plus_5PU_Full_Poisson/ \
> $CONFIG_FILE

cmsRun $CONFIG_FILE >& effJetArea_QCDpt15_plus_5PU_Full_Poisson.log 

echo "`/bin/date` >> QCDpt15_plus_5PU_Full_Poisson analysis completed!"
#==========================================================
echo "`/bin/date` >> effJetArea batch queue completed!"