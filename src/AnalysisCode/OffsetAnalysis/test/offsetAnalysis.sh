#!/bin/bash

# setup software environment
export SCRAM_ARCH=slc4_ia32_gcc345
eval `scramv1 runtime -sh`

CONFIG_FILE_TEMPLATE=`echo offsetAnalysis_template_cfg.py`
CONFIG_FILE=`echo offsetAnalysis_cfg.py`

# echo ""
echo ">> `date +'%b %d %Y %T %Z'` Starting Offset analysis batch queue:"
#==========================================================
echo ">> `date +'%b %d %Y %T %Z'` Noise-only analysis started..."

cat $CONFIG_FILE_TEMPLATE \
| sed -e s/INPUT_POOLSOURCE/NeutrinoGun/ \
| sed -e s/OUTPUT_FILENAME/Noise-only/ \
> $CONFIG_FILE

cmsRun $CONFIG_FILE >& Noise-only.log 

echo ">> `date +'%b %d %Y %T %Z'` Noise-only analysis completed!"
#==========================================================
echo ">> `date +'%b %d %Y %T %Z'` 1PU_InTime_Fixed analysis started..."

cat $CONFIG_FILE_TEMPLATE \
| sed -e s/INPUT_POOLSOURCE/1PU_InTime_Fixed/ \
| sed -e s/OUTPUT_FILENAME/1PU_InTime_Fixed/ \
> $CONFIG_FILE

cmsRun $CONFIG_FILE >& 1PU_InTime_Fixed.log 

echo ">> `date +'%b %d %Y %T %Z'` 1PU_InTime_Fixed analysis completed!"
#==========================================================
echo ">> `date +'%b %d %Y %T %Z'` 1PU_InTime_Poisson analysis started..."

cat $CONFIG_FILE_TEMPLATE \
| sed -e s/INPUT_POOLSOURCE/1PU_InTime_Poisson/ \
| sed -e s/OUTPUT_FILENAME/1PU_InTime_Poisson/ \
> $CONFIG_FILE

cmsRun $CONFIG_FILE >& 1PU_InTime_Poisson.log 

echo ">> `date +'%b %d %Y %T %Z'` 1PU_InTime_Poisson analysis completed!"
#==========================================================
echo ">> `date +'%b %d %Y %T %Z'` 1PU_Full_Poisson analysis started..."

cat $CONFIG_FILE_TEMPLATE \
| sed -e s/INPUT_POOLSOURCE/1PU_Full_Poisson/ \
| sed -e s/OUTPUT_FILENAME/1PU_Full_Poisson/ \
> $CONFIG_FILE

cmsRun $CONFIG_FILE >& 1PU_Full_Poisson.log 

echo ">> `date +'%b %d %Y %T %Z'` 1PU_Full_Poisson analysis completed!"
#==========================================================
echo ">> `date +'%b %d %Y %T %Z'` 2PU_InTime_Fixed analysis started..."

cat $CONFIG_FILE_TEMPLATE \
| sed -e s/INPUT_POOLSOURCE/2PU_InTime_Fixed/ \
| sed -e s/OUTPUT_FILENAME/2PU_InTime_Fixed/ \
> $CONFIG_FILE

cmsRun $CONFIG_FILE >& 2PU_InTime_Fixed.log 

echo ">> `date +'%b %d %Y %T %Z'` 2PU_InTime_Fixed analysis completed!"
#==========================================================
echo ">> `date +'%b %d %Y %T %Z'` 2PU_InTime_Poisson analysis started..."

cat $CONFIG_FILE_TEMPLATE \
| sed -e s/INPUT_POOLSOURCE/2PU_InTime_Poisson/ \
| sed -e s/OUTPUT_FILENAME/2PU_InTime_Poisson/ \
> $CONFIG_FILE

cmsRun $CONFIG_FILE >& 2PU_InTime_Poisson.log 

echo ">> `date +'%b %d %Y %T %Z'` 2PU_InTime_Poisson analysis completed!"
#==========================================================
echo ">> `date +'%b %d %Y %T %Z'` 2PU_Full_Poisson analysis started..."

cat $CONFIG_FILE_TEMPLATE \
| sed -e s/INPUT_POOLSOURCE/2PU_Full_Poisson/ \
| sed -e s/OUTPUT_FILENAME/2PU_Full_Poisson/ \
> $CONFIG_FILE

cmsRun $CONFIG_FILE >& 2PU_Full_Poisson.log 

echo ">> `date +'%b %d %Y %T %Z'` 2PU_Full_Poisson analysis completed!"
#==========================================================
echo ">> `date +'%b %d %Y %T %Z'` 5PU_InTime_Fixed analysis started..."

cat $CONFIG_FILE_TEMPLATE \
| sed -e s/INPUT_POOLSOURCE/5PU_InTime_Fixed/ \
| sed -e s/OUTPUT_FILENAME/5PU_InTime_Fixed/ \
> $CONFIG_FILE

cmsRun $CONFIG_FILE >& 5PU_InTime_Fixed.log 

echo ">> `date +'%b %d %Y %T %Z'` 5PU_InTime_Fixed analysis completed!"
#==========================================================
echo ">> `date +'%b %d %Y %T %Z'` 5PU_InTime_Poisson analysis started..."

cat $CONFIG_FILE_TEMPLATE \
| sed -e s/INPUT_POOLSOURCE/5PU_InTime_Poisson/ \
| sed -e s/OUTPUT_FILENAME/5PU_InTime_Poisson/ \
> $CONFIG_FILE

cmsRun $CONFIG_FILE >& 5PU_InTime_Poisson.log 

echo ">> `date +'%b %d %Y %T %Z'` 5PU_InTime_Poisson analysis completed!"
#==========================================================
echo ">> `date +'%b %d %Y %T %Z'` 5PU_Full_Poisson analysis started..."

cat $CONFIG_FILE_TEMPLATE \
| sed -e s/INPUT_POOLSOURCE/5PU_Full_Poisson/ \
| sed -e s/OUTPUT_FILENAME/5PU_Full_Poisson/ \
> $CONFIG_FILE

cmsRun $CONFIG_FILE >& 5PU_Full_Poisson.log 

echo ">> `date +'%b %d %Y %T %Z'` 5PU_Full_Poisson analysis completed!"
#==========================================================
echo ">> `date +'%b %d %Y %T %Z'` Offset analysis batch queue completed!"