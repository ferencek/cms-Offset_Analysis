#!/bin/bash

# setup software environment
export SCRAM_ARCH=slc4_ia32_gcc345
eval `scramv1 runtime -sh`

CONFIG_FILE_TEMPLATE=`echo closureAnalysis_template_cfg.py`
CONFIG_FILE=`echo closureAnalysis_cfg.py`

echo ""
echo "`/bin/date` >> Starting Closure Analysis on $HOST:"
#==========================================================
# echo "`/bin/date` >> QCDpt15_plus_1PU_Full_Poisson analysis started..."
# 
# cat $CONFIG_FILE_TEMPLATE \
# | sed -e s/MAX_EVTS/-1/ \
# | sed -e s/INPUT_POOLSOURCE/QCDpt15_plus_1PU_Full_Poisson/ \
# | sed -e s/OUTPUT_FILENAME/closureAnalysis_QCDpt15_plus_1PU_Full_Poisson/ \
# | sed -e s/DO_CORR/False/ \
# | sed -e s/DO_PVS/True/ \
# | sed -e s/MAX_NPVS/7/ \
# | sed -e s/PV_COLLECTION/offlinePrimaryVertices/ \
# | sed -e s/CORRECTION_FILE/offlinePrimaryVertices_1PU_Full_Poisson/ \
# > $CONFIG_FILE
# 
# cmsRun $CONFIG_FILE >& QCDpt15_plus_1PU_Full_Poisson.log 
# 
# echo "`/bin/date` >> QCDpt15_plus_1PU_Full_Poisson analysis completed!"
#==========================================================
# echo "`/bin/date` >> QCDpt15_plus_1PU_Full_Poisson_corrected_Avg_Lumi analysis started..."
# 
# cat $CONFIG_FILE_TEMPLATE \
# | sed -e s/MAX_EVTS/-1/ \
# | sed -e s/INPUT_POOLSOURCE/QCDpt15_plus_1PU_Full_Poisson/ \
# | sed -e s/OUTPUT_FILENAME/closureAnalysis_QCDpt15_plus_1PU_Full_Poisson_corrected_Avg_Lumi/ \
# | sed -e s/DO_CORR/True/ \
# | sed -e s/DO_PVS/False/ \
# | sed -e s/MAX_NPVS/4/ \
# | sed -e s/PV_COLLECTION/offlinePrimaryVertices/ \
# | sed -e s/CORRECTION_FILE/offlinePrimaryVertices_1PU_Full_Poisson/ \
# > $CONFIG_FILE
# 
# cmsRun $CONFIG_FILE >& QCDpt15_plus_1PU_Full_Poisson_corrected_Avg_Lumi.log 
# 
# echo "`/bin/date` >> QCDpt15_plus_1PU_Full_Poisson_corrected_Avg_Lumi analysis completed!"
#==========================================================
# echo "`/bin/date` >> QCDpt15_plus_1PU_Full_Poisson_corrected_PV_Lumi analysis started..."
# 
# cat $CONFIG_FILE_TEMPLATE \
# | sed -e s/MAX_EVTS/-1/ \
# | sed -e s/INPUT_POOLSOURCE/QCDpt15_plus_1PU_Full_Poisson/ \
# | sed -e s/OUTPUT_FILENAME/closureAnalysis_QCDpt15_plus_1PU_Full_Poisson_corrected_PV_Lumi/ \
# | sed -e s/DO_CORR/True/ \
# | sed -e s/DO_PVS/True/ \
# | sed -e s/MAX_NPVS/4/ \
# | sed -e s/PV_COLLECTION/offlinePrimaryVertices/ \
# | sed -e s/CORRECTION_FILE/offlinePrimaryVertices_1PU_Full_Poisson/ \
# > $CONFIG_FILE
# 
# cmsRun $CONFIG_FILE >& QCDpt15_plus_1PU_Full_Poisson_corrected_PV_Lumi.log 
# 
# echo "`/bin/date` >> QCDpt15_plus_1PU_Full_Poisson_corrected_PV_Lumi analysis completed!"
#==========================================================
# echo "`/bin/date` >> QCDpt15_plus_1PU_Full_Poisson_corrected_PV analysis started..."
# 
# cat $CONFIG_FILE_TEMPLATE \
# | sed -e s/INPUT_POOLSOURCE/QCDpt15_plus_1PU_Full_Poisson/ \
# | sed -e s/OUTPUT_FILENAME/closureAnalysis_QCDpt15_plus_1PU_Full_Poisson_corrected_PV/ \
# | sed -e s/DO_CORR/True/ \
# | sed -e s/DO_PVS/True/ \
# | sed -e s/MAX_NPVS/8/ \
# | sed -e s/PV_COLLECTION/offlinePrimaryVertices/ \
# | sed -e s/CORRECTION_FILE/offlinePrimaryVertices_Noise-only_and_PU_Full_Poisson/ \
# > $CONFIG_FILE
# 
# cmsRun $CONFIG_FILE >& QCDpt15_plus_1PU_Full_Poisson_corrected_PV.log 
# 
# echo "`/bin/date` >> QCDpt15_plus_1PU_Full_Poisson_corrected_PV analysis completed!"
#==========================================================
# echo "`/bin/date` >> QCDpt15_plus_2PU_Full_Poisson analysis started..."
# 
# cat $CONFIG_FILE_TEMPLATE \
# | sed -e s/MAX_EVTS/-1/ \
# | sed -e s/INPUT_POOLSOURCE/QCDpt15_plus_2PU_Full_Poisson/ \
# | sed -e s/OUTPUT_FILENAME/closureAnalysis_QCDpt15_plus_2PU_Full_Poisson/ \
# | sed -e s/DO_CORR/False/ \
# | sed -e s/DO_PVS/True/ \
# | sed -e s/MAX_NPVS/9/ \
# | sed -e s/PV_COLLECTION/offlinePrimaryVertices/ \
# | sed -e s/CORRECTION_FILE/offlinePrimaryVertices_2PU_Full_Poisson/ \
# > $CONFIG_FILE
# 
# cmsRun $CONFIG_FILE >& QCDpt15_plus_2PU_Full_Poisson.log 
# 
# echo "`/bin/date` >> QCDpt15_plus_2PU_Full_Poisson analysis completed!"
#==========================================================
# echo "`/bin/date` >> QCDpt15_plus_2PU_Full_Poisson_corrected_Avg_Lumi analysis started..."
# 
# cat $CONFIG_FILE_TEMPLATE \
# | sed -e s/MAX_EVTS/-1/ \
# | sed -e s/INPUT_POOLSOURCE/QCDpt15_plus_2PU_Full_Poisson/ \
# | sed -e s/OUTPUT_FILENAME/closureAnalysis_QCDpt15_plus_2PU_Full_Poisson_corrected_Avg_Lumi/ \
# | sed -e s/DO_CORR/True/ \
# | sed -e s/DO_PVS/False/ \
# | sed -e s/MAX_NPVS/5/ \
# | sed -e s/PV_COLLECTION/offlinePrimaryVertices/ \
# | sed -e s/CORRECTION_FILE/offlinePrimaryVertices_2PU_Full_Poisson/ \
# > $CONFIG_FILE
# 
# cmsRun $CONFIG_FILE >& QCDpt15_plus_2PU_Full_Poisson_corrected_Avg_Lumi.log 
# 
# echo "`/bin/date` >> QCDpt15_plus_2PU_Full_Poisson_corrected_Avg_Lumi analysis completed!"
#==========================================================
# echo "`/bin/date` >> QCDpt15_plus_2PU_Full_Poisson_corrected_PV_Lumi analysis started..."
# 
# cat $CONFIG_FILE_TEMPLATE \
# | sed -e s/MAX_EVTS/-1/ \
# | sed -e s/INPUT_POOLSOURCE/QCDpt15_plus_2PU_Full_Poisson/ \
# | sed -e s/OUTPUT_FILENAME/closureAnalysis_QCDpt15_plus_2PU_Full_Poisson_corrected_PV_Lumi/ \
# | sed -e s/DO_CORR/True/ \
# | sed -e s/DO_PVS/True/ \
# | sed -e s/MAX_NPVS/5/ \
# | sed -e s/PV_COLLECTION/offlinePrimaryVertices/ \
# | sed -e s/CORRECTION_FILE/offlinePrimaryVertices_2PU_Full_Poisson/ \
# > $CONFIG_FILE
# 
# cmsRun $CONFIG_FILE >& QCDpt15_plus_2PU_Full_Poisson_corrected_PV_Lumi.log 
# 
# echo "`/bin/date` >> QCDpt15_plus_2PU_Full_Poisson_corrected_PV_Lumi analysis completed!"
#==========================================================
# echo "`/bin/date` >> QCDpt15_plus_2PU_Full_Poisson_corrected_PV analysis started..."
# 
# cat $CONFIG_FILE_TEMPLATE \
# | sed -e s/INPUT_POOLSOURCE/QCDpt15_plus_2PU_Full_Poisson/ \
# | sed -e s/OUTPUT_FILENAME/closureAnalysis_QCDpt15_plus_2PU_Full_Poisson_corrected_PV/ \
# | sed -e s/DO_CORR/True/ \
# | sed -e s/DO_PVS/True/ \
# | sed -e s/MAX_NPVS/8/ \
# | sed -e s/PV_COLLECTION/offlinePrimaryVertices/ \
# | sed -e s/CORRECTION_FILE/offlinePrimaryVertices_Noise-only_and_PU_Full_Poisson/ \
# > $CONFIG_FILE
# 
# cmsRun $CONFIG_FILE >& QCDpt15_plus_2PU_Full_Poisson_corrected_PV.log 
# 
# echo "`/bin/date` >> QCDpt15_plus_2PU_Full_Poisson_corrected_PV analysis completed!"
#==========================================================
# echo "`/bin/date` >> QCDpt15_plus_5PU_Full_Poisson analysis started..."
# 
# cat $CONFIG_FILE_TEMPLATE \
# | sed -e s/MAX_EVTS/-1/ \
# | sed -e s/INPUT_POOLSOURCE/QCDpt15_plus_5PU_Full_Poisson/ \
# | sed -e s/OUTPUT_FILENAME/closureAnalysis_QCDpt15_plus_5PU_Full_Poisson/ \
# | sed -e s/DO_CORR/False/ \
# | sed -e s/DO_PVS/True/ \
# | sed -e s/MAX_NPVS/12/ \
# | sed -e s/PV_COLLECTION/offlinePrimaryVertices/ \
# | sed -e s/CORRECTION_FILE/offlinePrimaryVertices_5PU_Full_Poisson/ \
# > $CONFIG_FILE
# 
# cmsRun $CONFIG_FILE >& QCDpt15_plus_5PU_Full_Poisson.log 
# 
# echo "`/bin/date` >> QCDpt15_plus_5PU_Full_Poisson analysis completed!"
#==========================================================
# echo "`/bin/date` >> QCDpt15_plus_5PU_Full_Poisson_corrected_Avg_Lumi analysis started..."
# 
# cat $CONFIG_FILE_TEMPLATE \
# | sed -e s/MAX_EVTS/-1/ \
# | sed -e s/INPUT_POOLSOURCE/QCDpt15_plus_5PU_Full_Poisson/ \
# | sed -e s/OUTPUT_FILENAME/closureAnalysis_QCDpt15_plus_5PU_Full_Poisson_corrected_Avg_Lumi/ \
# | sed -e s/DO_CORR/True/ \
# | sed -e s/DO_PVS/False/ \
# | sed -e s/MAX_NPVS/8/ \
# | sed -e s/PV_COLLECTION/offlinePrimaryVertices/ \
# | sed -e s/CORRECTION_FILE/offlinePrimaryVertices_5PU_Full_Poisson/ \
# > $CONFIG_FILE
# 
# cmsRun $CONFIG_FILE >& QCDpt15_plus_5PU_Full_Poisson_corrected_Avg_Lumi.log 
# 
# echo "`/bin/date` >> QCDpt15_plus_5PU_Full_Poisson_corrected_Avg_Lumi analysis completed!"
#==========================================================
echo "`/bin/date` >> QCDpt15_plus_5PU_Full_Poisson_corrected_PV_Lumi analysis started..."

cat $CONFIG_FILE_TEMPLATE \
| sed -e s/MAX_EVTS/-1/ \
| sed -e s/INPUT_POOLSOURCE/QCDpt15_plus_5PU_Full_Poisson/ \
| sed -e s/OUTPUT_FILENAME/closureAnalysis_QCDpt15_plus_5PU_Full_Poisson_corrected_PV_Lumi_new/ \
| sed -e s/DO_CORR/True/ \
| sed -e s/DO_PVS/True/ \
| sed -e s/MAX_NPVS/8/ \
| sed -e s/PV_COLLECTION/offlinePrimaryVertices/ \
| sed -e s/CORRECTION_FILE/offlinePrimaryVertices_5PU_Full_Poisson/ \
> $CONFIG_FILE

cmsRun $CONFIG_FILE >& QCDpt15_plus_5PU_Full_Poisson_corrected_PV_Lumi_new.log 

echo "`/bin/date` >> QCDpt15_plus_5PU_Full_Poisson_corrected_PV_Lumi analysis completed!"
#==========================================================
# echo "`/bin/date` >> QCDpt15_plus_5PU_Full_Poisson_corrected_PV analysis started..."
# 
# cat $CONFIG_FILE_TEMPLATE \
# | sed -e s/INPUT_POOLSOURCE/QCDpt15_plus_5PU_Full_Poisson/ \
# | sed -e s/OUTPUT_FILENAME/closureAnalysis_QCDpt15_plus_5PU_Full_Poisson_corrected_PV/ \
# | sed -e s/DO_CORR/True/ \
# | sed -e s/DO_PVS/True/ \
# | sed -e s/MAX_NPVS/8/ \
# | sed -e s/PV_COLLECTION/offlinePrimaryVertices/ \
# | sed -e s/CORRECTION_FILE/offlinePrimaryVertices_Noise-only_and_PU_Full_Poisson/ \
# > $CONFIG_FILE
# 
# cmsRun $CONFIG_FILE >& QCDpt15_plus_5PU_Full_Poisson_corrected_PV.log 
# 
# echo "`/bin/date` >> QCDpt15_plus_5PU_Full_Poisson_corrected_PV analysis completed!"
#==========================================================
echo "`/bin/date` >> Offset analysis batch queue completed!"