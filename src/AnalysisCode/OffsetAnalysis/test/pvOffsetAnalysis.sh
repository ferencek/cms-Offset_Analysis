#!/bin/bash

# setup software environment
export SCRAM_ARCH=slc4_ia32_gcc345
eval `scramv1 runtime -sh`

CONFIG_FILE_TEMPLATE=`echo offsetAnalysis_template_cfg.py`
CONFIG_FILE=`echo offsetAnalysis_cfg.py`

# echo ""
echo ">> `date +'%b %d %Y %T %Z'` Starting Offset analysis on $HOST:"
#==========================================================
# echo ">> `date +'%b %d %Y %T %Z'` Noise-only analysis started..."
# 
# cat $CONFIG_FILE_TEMPLATE \
# | sed -e s/MAX_EVTS/-1/ \
# | sed -e s/INPUT_POOLSOURCE/NeutrinoGun/ \
# | sed -e s/OUTPUT_FILENAME/offlinePrimaryVertices_Noise-only/ \
# | sed -e s/DO_OFFSET/True/ \
# | sed -e s/DO_PVS/True/ \
# | sed -e s/MAX_NPVS/0/ \
# | sed -e s/PV_COLLECTION/offlinePrimaryVertices/ \
# > $CONFIG_FILE
# 
# cmsRun $CONFIG_FILE >& offlinePrimaryVertices_Noise-only.log 
# 
# echo ">> `date +'%b %d %Y %T %Z'` Noise-only analysis completed!"
#==========================================================
echo ">> `date +'%b %d %Y %T %Z'` 1PU_InTime_Fixed analysis started..."

cat $CONFIG_FILE_TEMPLATE \
| sed -e s/MAX_EVTS/20000/ \
| sed -e s/INPUT_POOLSOURCE/1PU_InTime_Fixed/ \
| sed -e s/OUTPUT_FILENAME/offlinePrimaryVertices_1PU_InTime_Fixed/ \
| sed -e s/DO_OFFSET/True/ \
| sed -e s/DO_PVS/True/ \
| sed -e s/MAX_NPVS/5/ \
| sed -e s/PV_COLLECTION/offlinePrimaryVertices/ \
> $CONFIG_FILE

cmsRun $CONFIG_FILE >& offlinePrimaryVertices_1PU_InTime_Fixed.log 

echo ">> `date +'%b %d %Y %T %Z'` 1PU_InTime_Fixed analysis completed!"
#==========================================================
# echo ">> `date +'%b %d %Y %T %Z'` 1PU_Full_Poisson analysis started..."
# 
# cat $CONFIG_FILE_TEMPLATE \
# | sed -e s/MAX_EVTS/-1/ \
# | sed -e s/INPUT_POOLSOURCE/1PU_Full_Poisson/ \
# | sed -e s/OUTPUT_FILENAME/offlinePrimaryVertices_1PU_Full_Poisson/ \
# | sed -e s/DO_OFFSET/True/ \
# | sed -e s/DO_PVS/True/ \
# | sed -e s/MAX_NPVS/5/ \
# | sed -e s/PV_COLLECTION/offlinePrimaryVertices/ \
# > $CONFIG_FILE
# 
# cmsRun $CONFIG_FILE >& offlinePrimaryVertices_1PU_Full_Poisson.log 
# 
# echo ">> `date +'%b %d %Y %T %Z'` 1PU_Full_Poisson analysis completed!"
#==========================================================
# echo ">> `date +'%b %d %Y %T %Z'` 2PU_Full_Poisson analysis started..."
# 
# cat $CONFIG_FILE_TEMPLATE \
# | sed -e s/MAX_EVTS/-1/ \
# | sed -e s/INPUT_POOLSOURCE/2PU_Full_Poisson/ \
# | sed -e s/OUTPUT_FILENAME/offlinePrimaryVertices_2PU_Full_Poisson/ \
# | sed -e s/DO_OFFSET/True/ \
# | sed -e s/DO_PVS/True/ \
# | sed -e s/MAX_NPVS/6/ \
# | sed -e s/PV_COLLECTION/offlinePrimaryVertices/ \
# > $CONFIG_FILE
# 
# cmsRun $CONFIG_FILE >& offlinePrimaryVertices_2PU_Full_Poisson.log 
# 
# echo ">> `date +'%b %d %Y %T %Z'` 2PU_Full_Poisson analysis completed!"
#==========================================================
# echo ">> `date +'%b %d %Y %T %Z'` 5PU_Full_Poisson analysis started..."
# 
# cat $CONFIG_FILE_TEMPLATE \
# | sed -e s/MAX_EVTS/-1/ \
# | sed -e s/INPUT_POOLSOURCE/5PU_Full_Poisson/ \
# | sed -e s/OUTPUT_FILENAME/offlinePrimaryVertices_5PU_Full_Poisson/ \
# | sed -e s/DO_OFFSET/True/ \
# | sed -e s/DO_PVS/True/ \
# | sed -e s/MAX_NPVS/11/ \
# | sed -e s/PV_COLLECTION/offlinePrimaryVertices/ \
# > $CONFIG_FILE
# 
# cmsRun $CONFIG_FILE >& offlinePrimaryVertices_5PU_Full_Poisson.log 
# 
# echo ">> `date +'%b %d %Y %T %Z'` 5PU_Full_Poisson analysis completed!"
#==========================================================
# echo ">> `date +'%b %d %Y %T %Z'` Noise-only_and_PU_Full_Poisson analysis started..."
# 
# cat $CONFIG_FILE_TEMPLATE \
# | sed -e s/MAX_EVTS/-1/ \
# | sed -e s/INPUT_POOLSOURCE/NeutrinoGun_and_PU_Full_Poisson/ \
# | sed -e s/OUTPUT_FILENAME/offlinePrimaryVertices_Noise-only_and_PU_Full_Poisson/ \
# | sed -e s/DO_OFFSET/True/ \
# | sed -e s/DO_PVS/True/ \
# | sed -e s/MAX_NPVS/11/ \
# | sed -e s/PV_COLLECTION/offlinePrimaryVertices/ \
# > $CONFIG_FILE
# 
# cmsRun $CONFIG_FILE >& offlinePrimaryVertices_Noise-only_and_PU_Full_Poisson.log 
# 
# echo ">> `date +'%b %d %Y %T %Z'` Noise-only_and_PU_Full_Poisson analysis completed!"
#==========================================================
echo ">> `date +'%b %d %Y %T %Z'` Offset analysis completed!"
exit