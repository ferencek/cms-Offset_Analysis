#!/bin/bash

PRIMARY_VERTICES=$1

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
| sed -e s/OUTPUT_FILENAME/${PRIMARY_VERTICES}_Noise-only/ \
| sed -e s/PV_COLLECTION/$PRIMARY_VERTICES/ \
> $CONFIG_FILE

cmsRun $CONFIG_FILE >& Noise-only.log 

echo ">> `date +'%b %d %Y %T %Z'` Noise-only analysis completed!"
#==========================================================
echo ">> `date +'%b %d %Y %T %Z'` 1PU_InTime_Fixed analysis started..."

cat $CONFIG_FILE_TEMPLATE \
| sed -e s/INPUT_POOLSOURCE/1PU_InTime_Fixed/ \
| sed -e s/OUTPUT_FILENAME/${PRIMARY_VERTICES}_1PU_InTime_Fixed/ \
| sed -e s/PV_COLLECTION/$PRIMARY_VERTICES/ \
> $CONFIG_FILE

cmsRun $CONFIG_FILE >& 1PU_InTime_Fixed.log 

echo ">> `date +'%b %d %Y %T %Z'` 1PU_InTime_Fixed analysis completed!"
#==========================================================
# echo ">> `date +'%b %d %Y %T %Z'` 1PU_InTime_Poisson analysis started..."
# 
# cat $CONFIG_FILE_TEMPLATE \
# | sed -e s/INPUT_POOLSOURCE/1PU_InTime_Poisson/ \
# | sed -e s/OUTPUT_FILENAME/${PRIMARY_VERTICES}_1PU_InTime_Poisson/ \
# | sed -e s/PV_COLLECTION/$PRIMARY_VERTICES/ \
# > $CONFIG_FILE
# 
# cmsRun $CONFIG_FILE >& 1PU_InTime_Poisson.log 
# 
# echo ">> `date +'%b %d %Y %T %Z'` 1PU_InTime_Poisson analysis completed!"
# #==========================================================
# echo ">> `date +'%b %d %Y %T %Z'` 1PU_Full_Poisson analysis started..."
# 
# cat $CONFIG_FILE_TEMPLATE \
# | sed -e s/INPUT_POOLSOURCE/1PU_Full_Poisson/ \
# | sed -e s/OUTPUT_FILENAME/${PRIMARY_VERTICES}_1PU_Full_Poisson/ \
# | sed -e s/PV_COLLECTION/$PRIMARY_VERTICES/ \
# > $CONFIG_FILE
# 
# cmsRun $CONFIG_FILE >& 1PU_Full_Poisson.log 
# 
# echo ">> `date +'%b %d %Y %T %Z'` 1PU_Full_Poisson analysis completed!"
#==========================================================
echo ">> `date +'%b %d %Y %T %Z'` 2PU_InTime_Fixed analysis started..."

cat $CONFIG_FILE_TEMPLATE \
| sed -e s/INPUT_POOLSOURCE/2PU_InTime_Fixed/ \
| sed -e s/OUTPUT_FILENAME/${PRIMARY_VERTICES}_2PU_InTime_Fixed/ \
| sed -e s/PV_COLLECTION/$PRIMARY_VERTICES/ \
> $CONFIG_FILE

cmsRun $CONFIG_FILE >& 2PU_InTime_Fixed.log 

echo ">> `date +'%b %d %Y %T %Z'` 2PU_InTime_Fixed analysis completed!"
#==========================================================
# echo ">> `date +'%b %d %Y %T %Z'` 2PU_InTime_Poisson analysis started..."
# 
# cat $CONFIG_FILE_TEMPLATE \
# | sed -e s/INPUT_POOLSOURCE/2PU_InTime_Poisson/ \
# | sed -e s/OUTPUT_FILENAME/${PRIMARY_VERTICES}_2PU_InTime_Poisson/ \
# | sed -e s/PV_COLLECTION/$PRIMARY_VERTICES/ \
# > $CONFIG_FILE
# 
# cmsRun $CONFIG_FILE >& 2PU_InTime_Poisson.log 
# 
# echo ">> `date +'%b %d %Y %T %Z'` 2PU_InTime_Poisson analysis completed!"
# #==========================================================
# echo ">> `date +'%b %d %Y %T %Z'` 2PU_Full_Poisson analysis started..."
# 
# cat $CONFIG_FILE_TEMPLATE \
# | sed -e s/INPUT_POOLSOURCE/2PU_Full_Poisson/ \
# | sed -e s/OUTPUT_FILENAME/${PRIMARY_VERTICES}_2PU_Full_Poisson/ \
# | sed -e s/PV_COLLECTION/$PRIMARY_VERTICES/ \
# > $CONFIG_FILE
# 
# cmsRun $CONFIG_FILE >& 2PU_Full_Poisson.log 
# 
# echo ">> `date +'%b %d %Y %T %Z'` 2PU_Full_Poisson analysis completed!"
#==========================================================
echo ">> `date +'%b %d %Y %T %Z'` 5PU_InTime_Fixed analysis started..."

cat $CONFIG_FILE_TEMPLATE \
| sed -e s/INPUT_POOLSOURCE/5PU_InTime_Fixed/ \
| sed -e s/OUTPUT_FILENAME/${PRIMARY_VERTICES}_5PU_InTime_Fixed/ \
| sed -e s/PV_COLLECTION/$PRIMARY_VERTICES/ \
> $CONFIG_FILE

cmsRun $CONFIG_FILE >& 5PU_InTime_Fixed.log 

echo ">> `date +'%b %d %Y %T %Z'` 5PU_InTime_Fixed analysis completed!"
#==========================================================
# echo ">> `date +'%b %d %Y %T %Z'` 5PU_InTime_Poisson analysis started..."
# 
# cat $CONFIG_FILE_TEMPLATE \
# | sed -e s/INPUT_POOLSOURCE/5PU_InTime_Poisson/ \
# | sed -e s/OUTPUT_FILENAME/${PRIMARY_VERTICES}_5PU_InTime_Poisson/ \
# | sed -e s/PV_COLLECTION/$PRIMARY_VERTICES/ \
# > $CONFIG_FILE
# 
# cmsRun $CONFIG_FILE >& 5PU_InTime_Poisson.log 
# 
# echo ">> `date +'%b %d %Y %T %Z'` 5PU_InTime_Poisson analysis completed!"
# #==========================================================
# echo ">> `date +'%b %d %Y %T %Z'` 5PU_Full_Poisson analysis started..."
# 
# cat $CONFIG_FILE_TEMPLATE \
# | sed -e s/INPUT_POOLSOURCE/5PU_Full_Poisson/ \
# | sed -e s/OUTPUT_FILENAME/${PRIMARY_VERTICES}_5PU_Full_Poisson/ \
# | sed -e s/PV_COLLECTION/$PRIMARY_VERTICES/ \
# > $CONFIG_FILE
# 
# cmsRun $CONFIG_FILE >& 5PU_Full_Poisson.log 
# 
# echo ">> `date +'%b %d %Y %T %Z'` 5PU_Full_Poisson analysis completed!"
#==========================================================
echo ">> `date +'%b %d %Y %T %Z'` QCDpt15_NN analysis started..."

cat $CONFIG_FILE_TEMPLATE \
| sed -e s/INPUT_POOLSOURCE/QCDpt15_NN/ \
| sed -e s/OUTPUT_FILENAME/${PRIMARY_VERTICES}_QCDpt15_NN/ \
| sed -e s/PV_COLLECTION/$PRIMARY_VERTICES/ \
> $CONFIG_FILE

cmsRun $CONFIG_FILE >& QCDpt15_NN.log 

echo ">> `date +'%b %d %Y %T %Z'` QCDpt15_NN analysis completed!"
#==========================================================
echo ">> `date +'%b %d %Y %T %Z'` QCDpt15+1PU_Full_Poisson analysis started..."

cat $CONFIG_FILE_TEMPLATE \
| sed -e s/INPUT_POOLSOURCE/QCDpt15_plus_1PU_Full_Poisson/ \
| sed -e s/OUTPUT_FILENAME/${PRIMARY_VERTICES}_QCDpt15_plus_1PU_Full_Poisson/ \
| sed -e s/PV_COLLECTION/$PRIMARY_VERTICES/ \
> $CONFIG_FILE

cmsRun $CONFIG_FILE >& QCDpt15_plus_1PU_Full_Poisson.log 

echo ">> `date +'%b %d %Y %T %Z'` QCDpt15+1PU_Full_Poisson analysis completed!"
#==========================================================
echo ">> `date +'%b %d %Y %T %Z'` QCDpt15+2PU_Full_Poisson analysis started..."

cat $CONFIG_FILE_TEMPLATE \
| sed -e s/INPUT_POOLSOURCE/QCDpt15_plus_2PU_Full_Poisson/ \
| sed -e s/OUTPUT_FILENAME/${PRIMARY_VERTICES}_QCDpt15_plus_2PU_Full_Poisson/ \
| sed -e s/PV_COLLECTION/$PRIMARY_VERTICES/ \
> $CONFIG_FILE

cmsRun $CONFIG_FILE >& QCDpt15_plus_2PU_Full_Poisson.log 

echo ">> `date +'%b %d %Y %T %Z'` QCDpt15+2PU_Full_Poisson analysis completed!"
#==========================================================
echo ">> `date +'%b %d %Y %T %Z'` QCDpt15+5PU_Full_Poisson analysis started..."

cat $CONFIG_FILE_TEMPLATE \
| sed -e s/INPUT_POOLSOURCE/QCDpt15_plus_5PU_Full_Poisson/ \
| sed -e s/OUTPUT_FILENAME/${PRIMARY_VERTICES}_QCDpt15_plus_5PU_Full_Poisson/ \
| sed -e s/PV_COLLECTION/$PRIMARY_VERTICES/ \
> $CONFIG_FILE

cmsRun $CONFIG_FILE >& QCDpt15_plus_5PU_Full_Poisson.log 

echo ">> `date +'%b %d %Y %T %Z'` QCDpt15+5PU_Full_Poisson analysis completed!"
#==========================================================
echo ">> `date +'%b %d %Y %T %Z'` Offset analysis batch queue completed!"