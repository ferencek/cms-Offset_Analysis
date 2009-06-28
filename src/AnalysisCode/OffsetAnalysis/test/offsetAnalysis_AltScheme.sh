#!/bin/bash

# setup software environment
export SCRAM_ARCH=slc4_ia32_gcc345
eval `scramv1 runtime -sh`

CONFIG_FILE_TEMPLATE=`echo offsetAnalysis_AltScheme_template_cfg.py`
CONFIG_FILE=`echo offsetAnalysis_AltScheme_cfg.py`

# echo ""
echo ">> `date +'%b %d %Y %T %Z'` Starting Offset analysis on $HOST:"
#==========================================================
echo ">> `date +'%b %d %Y %T %Z'` Noise-only analysis started..."

cat $CONFIG_FILE_TEMPLATE \
| sed -e s/MAX_EVTS/-1/ \
| sed -e s/INPUT_POOLSOURCE/NeutrinoGun/ \
| sed -e s/OUTPUT_FILENAME/Noise-only_AltScheme_ET0.5/ \
| sed -e s/DO_OFFSET/True/ \
| sed -e s/DO_PVS/False/ \
| sed -e s/MAX_NPVS/0/ \
| sed -e s/PV_COLLECTION/offlinePrimaryVertices/ \
> $CONFIG_FILE

cmsRun $CONFIG_FILE >& Noise-only_AltScheme.log 

echo ">> `date +'%b %d %Y %T %Z'` Noise-only analysis completed!"
#==========================================================
echo ">> `date +'%b %d %Y %T %Z'` 1PU_InTime_Poisson analysis started..."

cat $CONFIG_FILE_TEMPLATE \
| sed -e s/MAX_EVTS/-1/ \
| sed -e s/INPUT_POOLSOURCE/1PU_InTime_Poisson/ \
| sed -e s/OUTPUT_FILENAME/1PU_InTime_Poisson_AltScheme_ET0.5/ \
| sed -e s/DO_OFFSET/True/ \
| sed -e s/DO_PVS/False/ \
| sed -e s/MAX_NPVS/0/ \
| sed -e s/PV_COLLECTION/offlinePrimaryVertices/ \
> $CONFIG_FILE

cmsRun $CONFIG_FILE >& 1PU_InTime_Poisson_AltScheme.log 

echo ">> `date +'%b %d %Y %T %Z'` 1PU_InTime_Poisson analysis completed!"
#==========================================================
echo ">> `date +'%b %d %Y %T %Z'` 1PU_Full_Poisson analysis started..."

cat $CONFIG_FILE_TEMPLATE \
| sed -e s/MAX_EVTS/-1/ \
| sed -e s/INPUT_POOLSOURCE/1PU_Full_Poisson/ \
| sed -e s/OUTPUT_FILENAME/1PU_Full_Poisson_AltScheme_ET0.5/ \
| sed -e s/DO_OFFSET/True/ \
| sed -e s/DO_PVS/False/ \
| sed -e s/MAX_NPVS/0/ \
| sed -e s/PV_COLLECTION/offlinePrimaryVertices/ \
> $CONFIG_FILE

cmsRun $CONFIG_FILE >& 1PU_Full_Poisson_AltScheme.log 

echo ">> `date +'%b %d %Y %T %Z'` 1PU_Full_Poisson analysis completed!"
#==========================================================
echo ">> `date +'%b %d %Y %T %Z'` 2PU_InTime_Poisson analysis started..."

cat $CONFIG_FILE_TEMPLATE \
| sed -e s/MAX_EVTS/-1/ \
| sed -e s/INPUT_POOLSOURCE/2PU_InTime_Poisson/ \
| sed -e s/OUTPUT_FILENAME/2PU_InTime_Poisson_AltScheme_ET0.5/ \
| sed -e s/DO_OFFSET/True/ \
| sed -e s/DO_PVS/False/ \
| sed -e s/MAX_NPVS/0/ \
| sed -e s/PV_COLLECTION/offlinePrimaryVertices/ \
> $CONFIG_FILE

cmsRun $CONFIG_FILE >& 2PU_InTime_Poisson_AltScheme.log 

echo ">> `date +'%b %d %Y %T %Z'` 2PU_InTime_Poisson analysis completed!"
#==========================================================
echo ">> `date +'%b %d %Y %T %Z'` 2PU_Full_Poisson analysis started..."

cat $CONFIG_FILE_TEMPLATE \
| sed -e s/MAX_EVTS/-1/ \
| sed -e s/INPUT_POOLSOURCE/2PU_Full_Poisson/ \
| sed -e s/OUTPUT_FILENAME/2PU_Full_Poisson_AltScheme_ET0.5/ \
| sed -e s/DO_OFFSET/True/ \
| sed -e s/DO_PVS/False/ \
| sed -e s/MAX_NPVS/0/ \
| sed -e s/PV_COLLECTION/offlinePrimaryVertices/ \
> $CONFIG_FILE

cmsRun $CONFIG_FILE >& 2PU_Full_Poisson_AltScheme.log 

echo ">> `date +'%b %d %Y %T %Z'` 2PU_Full_Poisson analysis completed!"
#==========================================================
echo ">> `date +'%b %d %Y %T %Z'` 5PU_InTime_Poisson analysis started..."

cat $CONFIG_FILE_TEMPLATE \
| sed -e s/MAX_EVTS/-1/ \
| sed -e s/INPUT_POOLSOURCE/5PU_InTime_Poisson/ \
| sed -e s/OUTPUT_FILENAME/5PU_InTime_Poisson_AltScheme_ET0.5/ \
| sed -e s/DO_OFFSET/True/ \
| sed -e s/DO_PVS/False/ \
| sed -e s/MAX_NPVS/0/ \
| sed -e s/PV_COLLECTION/offlinePrimaryVertices/ \
> $CONFIG_FILE

cmsRun $CONFIG_FILE >& 5PU_InTime_Poisson_AltScheme.log 

echo ">> `date +'%b %d %Y %T %Z'` 5PU_InTime_Poisson analysis completed!"
#==========================================================
echo ">> `date +'%b %d %Y %T %Z'` 5PU_Full_Poisson analysis started..."

cat $CONFIG_FILE_TEMPLATE \
| sed -e s/MAX_EVTS/-1/ \
| sed -e s/INPUT_POOLSOURCE/5PU_Full_Poisson/ \
| sed -e s/OUTPUT_FILENAME/5PU_Full_Poisson_AltScheme_ET0.5/ \
| sed -e s/DO_OFFSET/True/ \
| sed -e s/DO_PVS/False/ \
| sed -e s/MAX_NPVS/0/ \
| sed -e s/PV_COLLECTION/offlinePrimaryVertices/ \
> $CONFIG_FILE

cmsRun $CONFIG_FILE >& 5PU_Full_Poisson_AltScheme.log 

echo ">> `date +'%b %d %Y %T %Z'` 5PU_Full_Poisson analysis completed!"
#==========================================================
echo ">> `date +'%b %d %Y %T %Z'` Offset analysis completed!"