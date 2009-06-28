#!/bin/bash

# setup software environment
export SCRAM_ARCH=slc4_ia32_gcc345
eval `scramv1 runtime -sh`

CONFIG_FILE_TEMPLATE=`echo closureAnalysis_kt4_template_cfg.py`
CONFIG_FILE=`echo closureAnalysis_kt4_cfg.py`

echo ""
echo "`/bin/date` >> Starting Closure Analysis on $HOST:"
#==========================================================
echo "`/bin/date` >> QCDpt15_NN analysis started..."

cat $CONFIG_FILE_TEMPLATE \
| sed -e s/MAX_EVTS/-1/ \
| sed -e s/INPUT_POOLSOURCE/QCDpt15_NN/ \
| sed -e s/OUTPUT_FILENAME/closureAnalysis_kt4_QCDpt15_NN/ \
| sed -e s/DO_CORR/False/ \
| sed -e s/DO_PVS/False/ \
| sed -e s/MAX_NPVS/4/ \
| sed -e s/PV_COLLECTION/offlinePrimaryVertices/ \
| sed -e s/CORRECTION_FILE/offlinePrimaryVertices_1PU_Full_Poisson/ \
> $CONFIG_FILE

cmsRun $CONFIG_FILE >& QCDpt15_NN.log 

echo "`/bin/date` >> QCDpt15_NN analysis completed!"
#==========================================================
# echo "`/bin/date` >> QCDpt15_plus_1PU_InTime_Poisson analysis started..."
# 
# cat $CONFIG_FILE_TEMPLATE \
# | sed -e s/MAX_EVTS/-1/ \
# | sed -e s/INPUT_POOLSOURCE/QCDpt15_plus_1PU_InTime_Poisson/ \
# | sed -e s/OUTPUT_FILENAME/closureAnalysis_kt4_QCDpt15_plus_1PU_InTime_Poisson/ \
# | sed -e s/DO_CORR/False/ \
# | sed -e s/DO_PVS/False/ \
# | sed -e s/MAX_NPVS/4/ \
# | sed -e s/PV_COLLECTION/offlinePrimaryVertices/ \
# | sed -e s/CORRECTION_FILE/1PU_InTime_Poisson_ET0.5/ \
# > $CONFIG_FILE
# 
# cmsRun $CONFIG_FILE >& QCDpt15_plus_1PU_InTime_Poisson.log 
# 
# echo "`/bin/date` >> QCDpt15_plus_1PU_InTime_Poisson analysis completed!"
#==========================================================
# echo "`/bin/date` >> QCDpt15_plus_1PU_InTime_Poisson_corrected_Avg_Lumi analysis started..."
# 
# cat $CONFIG_FILE_TEMPLATE \
# | sed -e s/MAX_EVTS/-1/ \
# | sed -e s/INPUT_POOLSOURCE/QCDpt15_plus_1PU_InTime_Poisson/ \
# | sed -e s/OUTPUT_FILENAME/closureAnalysis_kt4_QCDpt15_plus_1PU_InTime_Poisson_corrected_Avg_Lumi/ \
# | sed -e s/DO_CORR/True/ \
# | sed -e s/DO_PVS/False/ \
# | sed -e s/MAX_NPVS/4/ \
# | sed -e s/PV_COLLECTION/offlinePrimaryVertices/ \
# | sed -e s/CORRECTION_FILE/1PU_InTime_Poisson_ET0.5/ \
# > $CONFIG_FILE
# 
# cmsRun $CONFIG_FILE >& QCDpt15_plus_1PU_InTime_Poisson_corrected_Avg_Lumi.log 
# 
# echo "`/bin/date` >> QCDpt15_plus_1PU_InTime_Poisson_corrected_Avg_Lumi analysis completed!"
#==========================================================
echo "`/bin/date` >> QCDpt15_plus_1PU_Full_Poisson analysis started..."

cat $CONFIG_FILE_TEMPLATE \
| sed -e s/MAX_EVTS/-1/ \
| sed -e s/INPUT_POOLSOURCE/QCDpt15_plus_1PU_Full_Poisson/ \
| sed -e s/OUTPUT_FILENAME/closureAnalysis_kt4_QCDpt15_plus_1PU_Full_Poisson/ \
| sed -e s/DO_CORR/False/ \
| sed -e s/DO_PVS/False/ \
| sed -e s/MAX_NPVS/4/ \
| sed -e s/PV_COLLECTION/offlinePrimaryVertices/ \
| sed -e s/CORRECTION_FILE/1PU_Full_Poisson_ET0.5/ \
> $CONFIG_FILE

cmsRun $CONFIG_FILE >& QCDpt15_plus_1PU_Full_Poisson.log 

echo "`/bin/date` >> QCDpt15_plus_1PU_Full_Poisson analysis completed!"
#==========================================================
echo "`/bin/date` >> QCDpt15_plus_1PU_Full_Poisson_corrected_Avg_Lumi analysis started..."

cat $CONFIG_FILE_TEMPLATE \
| sed -e s/MAX_EVTS/-1/ \
| sed -e s/INPUT_POOLSOURCE/QCDpt15_plus_1PU_Full_Poisson/ \
| sed -e s/OUTPUT_FILENAME/closureAnalysis_kt4_QCDpt15_plus_1PU_Full_Poisson_corrected_Avg_Lumi/ \
| sed -e s/DO_CORR/True/ \
| sed -e s/DO_PVS/False/ \
| sed -e s/MAX_NPVS/4/ \
| sed -e s/PV_COLLECTION/offlinePrimaryVertices/ \
| sed -e s/CORRECTION_FILE/1PU_Full_Poisson_ET0.5/ \
> $CONFIG_FILE

cmsRun $CONFIG_FILE >& QCDpt15_plus_1PU_Full_Poisson_corrected_Avg_Lumi.log 

echo "`/bin/date` >> QCDpt15_plus_1PU_Full_Poisson_corrected_Avg_Lumi analysis completed!"
#==========================================================
# echo "`/bin/date` >> QCDpt15_plus_2PU_InTime_Poisson analysis started..."
# 
# cat $CONFIG_FILE_TEMPLATE \
# | sed -e s/MAX_EVTS/-1/ \
# | sed -e s/INPUT_POOLSOURCE/QCDpt15_plus_2PU_InTime_Poisson/ \
# | sed -e s/OUTPUT_FILENAME/closureAnalysis_kt4_QCDpt15_plus_2PU_InTime_Poisson/ \
# | sed -e s/DO_CORR/False/ \
# | sed -e s/DO_PVS/False/ \
# | sed -e s/MAX_NPVS/4/ \
# | sed -e s/PV_COLLECTION/offlinePrimaryVertices/ \
# | sed -e s/CORRECTION_FILE/2PU_InTime_Poisson_ET0.5/ \
# > $CONFIG_FILE
# 
# cmsRun $CONFIG_FILE >& QCDpt15_plus_2PU_InTime_Poisson.log 
# 
# echo "`/bin/date` >> QCDpt15_plus_2PU_InTime_Poisson analysis completed!"
#==========================================================
# echo "`/bin/date` >> QCDpt15_plus_2PU_InTime_Poisson_corrected_Avg_Lumi analysis started..."
# 
# cat $CONFIG_FILE_TEMPLATE \
# | sed -e s/MAX_EVTS/-1/ \
# | sed -e s/INPUT_POOLSOURCE/QCDpt15_plus_2PU_InTime_Poisson/ \
# | sed -e s/OUTPUT_FILENAME/closureAnalysis_kt4_QCDpt15_plus_2PU_InTime_Poisson_corrected_Avg_Lumi/ \
# | sed -e s/DO_CORR/True/ \
# | sed -e s/DO_PVS/False/ \
# | sed -e s/MAX_NPVS/4/ \
# | sed -e s/PV_COLLECTION/offlinePrimaryVertices/ \
# | sed -e s/CORRECTION_FILE/2PU_InTime_Poisson_ET0.5/ \
# > $CONFIG_FILE
# 
# cmsRun $CONFIG_FILE >& QCDpt15_plus_2PU_InTime_Poisson_corrected_Avg_Lumi.log 
# 
# echo "`/bin/date` >> QCDpt15_plus_2PU_InTime_Poisson_corrected_Avg_Lumi analysis completed!"
#==========================================================
echo "`/bin/date` >> QCDpt15_plus_2PU_Full_Poisson analysis started..."

cat $CONFIG_FILE_TEMPLATE \
| sed -e s/MAX_EVTS/-1/ \
| sed -e s/INPUT_POOLSOURCE/QCDpt15_plus_2PU_Full_Poisson/ \
| sed -e s/OUTPUT_FILENAME/closureAnalysis_kt4_QCDpt15_plus_2PU_Full_Poisson/ \
| sed -e s/DO_CORR/False/ \
| sed -e s/DO_PVS/False/ \
| sed -e s/MAX_NPVS/4/ \
| sed -e s/PV_COLLECTION/offlinePrimaryVertices/ \
| sed -e s/CORRECTION_FILE/2PU_Full_Poisson_ET0.5/ \
> $CONFIG_FILE

cmsRun $CONFIG_FILE >& QCDpt15_plus_2PU_Full_Poisson.log 

echo "`/bin/date` >> QCDpt15_plus_2PU_Full_Poisson analysis completed!"
#==========================================================
echo "`/bin/date` >> QCDpt15_plus_2PU_Full_Poisson_corrected_Avg_Lumi analysis started..."

cat $CONFIG_FILE_TEMPLATE \
| sed -e s/MAX_EVTS/-1/ \
| sed -e s/INPUT_POOLSOURCE/QCDpt15_plus_2PU_Full_Poisson/ \
| sed -e s/OUTPUT_FILENAME/closureAnalysis_kt4_QCDpt15_plus_2PU_Full_Poisson_corrected_Avg_Lumi/ \
| sed -e s/DO_CORR/True/ \
| sed -e s/DO_PVS/False/ \
| sed -e s/MAX_NPVS/4/ \
| sed -e s/PV_COLLECTION/offlinePrimaryVertices/ \
| sed -e s/CORRECTION_FILE/2PU_Full_Poisson_ET0.5/ \
> $CONFIG_FILE

cmsRun $CONFIG_FILE >& QCDpt15_plus_2PU_Full_Poisson_corrected_Avg_Lumi.log 

echo "`/bin/date` >> QCDpt15_plus_2PU_Full_Poisson_corrected_Avg_Lumi analysis completed!"
#==========================================================
# echo "`/bin/date` >> QCDpt15_plus_5PU_InTime_Poisson analysis started..."
# 
# cat $CONFIG_FILE_TEMPLATE \
# | sed -e s/MAX_EVTS/-1/ \
# | sed -e s/INPUT_POOLSOURCE/QCDpt15_plus_5PU_InTime_Poisson/ \
# | sed -e s/OUTPUT_FILENAME/closureAnalysis_kt4_QCDpt15_plus_5PU_InTime_Poisson/ \
# | sed -e s/DO_CORR/False/ \
# | sed -e s/DO_PVS/False/ \
# | sed -e s/MAX_NPVS/4/ \
# | sed -e s/PV_COLLECTION/offlinePrimaryVertices/ \
# | sed -e s/CORRECTION_FILE/5PU_InTime_Poisson_ET0.5/ \
# > $CONFIG_FILE
# 
# cmsRun $CONFIG_FILE >& QCDpt15_plus_5PU_InTime_Poisson.log 
# 
# echo "`/bin/date` >> QCDpt15_plus_5PU_InTime_Poisson analysis completed!"
#==========================================================
# echo "`/bin/date` >> QCDpt15_plus_5PU_InTime_Poisson_corrected_Avg_Lumi analysis started..."
# 
# cat $CONFIG_FILE_TEMPLATE \
# | sed -e s/MAX_EVTS/-1/ \
# | sed -e s/INPUT_POOLSOURCE/QCDpt15_plus_5PU_InTime_Poisson/ \
# | sed -e s/OUTPUT_FILENAME/closureAnalysis_kt4_QCDpt15_plus_5PU_InTime_Poisson_corrected_Avg_Lumi/ \
# | sed -e s/DO_CORR/True/ \
# | sed -e s/DO_PVS/False/ \
# | sed -e s/MAX_NPVS/4/ \
# | sed -e s/PV_COLLECTION/offlinePrimaryVertices/ \
# | sed -e s/CORRECTION_FILE/5PU_InTime_Poisson_ET0.5/ \
# > $CONFIG_FILE
# 
# cmsRun $CONFIG_FILE >& QCDpt15_plus_5PU_InTime_Poisson_corrected_Avg_Lumi.log 
# 
# echo "`/bin/date` >> QCDpt15_plus_5PU_InTime_Poisson_corrected_Avg_Lumi analysis completed!"
#==========================================================
echo "`/bin/date` >> QCDpt15_plus_5PU_Full_Poisson analysis started..."

cat $CONFIG_FILE_TEMPLATE \
| sed -e s/MAX_EVTS/-1/ \
| sed -e s/INPUT_POOLSOURCE/QCDpt15_plus_5PU_Full_Poisson/ \
| sed -e s/OUTPUT_FILENAME/closureAnalysis_kt4_QCDpt15_plus_5PU_Full_Poisson/ \
| sed -e s/DO_CORR/False/ \
| sed -e s/DO_PVS/False/ \
| sed -e s/MAX_NPVS/4/ \
| sed -e s/PV_COLLECTION/offlinePrimaryVertices/ \
| sed -e s/CORRECTION_FILE/5PU_Full_Poisson_ET0.5/ \
> $CONFIG_FILE

cmsRun $CONFIG_FILE >& QCDpt15_plus_5PU_Full_Poisson.log 

echo "`/bin/date` >> QCDpt15_plus_5PU_Full_Poisson analysis completed!"
#==========================================================
echo "`/bin/date` >> QCDpt15_plus_5PU_Full_Poisson_corrected_Avg_Lumi analysis started..."

cat $CONFIG_FILE_TEMPLATE \
| sed -e s/MAX_EVTS/-1/ \
| sed -e s/INPUT_POOLSOURCE/QCDpt15_plus_5PU_Full_Poisson/ \
| sed -e s/OUTPUT_FILENAME/closureAnalysis_kt4_QCDpt15_plus_5PU_Full_Poisson_corrected_Avg_Lumi/ \
| sed -e s/DO_CORR/True/ \
| sed -e s/DO_PVS/False/ \
| sed -e s/MAX_NPVS/4/ \
| sed -e s/PV_COLLECTION/offlinePrimaryVertices/ \
| sed -e s/CORRECTION_FILE/5PU_Full_Poisson_ET0.5/ \
> $CONFIG_FILE

cmsRun $CONFIG_FILE >& QCDpt15_plus_5PU_Full_Poisson_corrected_Avg_Lumi.log 

echo "`/bin/date` >> QCDpt15_plus_5PU_Full_Poisson_corrected_Avg_Lumi analysis completed!"
#==========================================================
echo "`/bin/date` >> Offset analysis batch queue completed!"