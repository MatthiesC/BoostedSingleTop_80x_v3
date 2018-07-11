#!/bin/bash

read -p "Do you really want do delete workdirs and output data? (y/n) " answer

if [ "$answer" == "n" ]
    then
    exit 1
elif [ "$answer" == "y" ]
    then
    rm -r /nfs/dust/cms/user/matthies/BoostedSingleTop/RunII_80X_v3/Analysis/Electron/workdir_analysis_ele/
    rm -r /nfs/dust/cms/user/matthies/BoostedSingleTop/RunII_80X_v3/Analysis/Muon/workdir_analysis_muo/
    rm /nfs/dust/cms/user/matthies/BoostedSingleTop/RunII_80X_v3/Analysis/Electron/uhh2.AnalysisModuleRunner.*
    rm /nfs/dust/cms/user/matthies/BoostedSingleTop/RunII_80X_v3/Analysis/Muon/uhh2.AnalysisModuleRunner.*
    rm -r /nfs/dust/cms/user/matthies/CMSSW_8_0_24_patch1/src/UHH2/BoostedSingleTop/config/workdir_analysis*
else
    echo "No valid answer. Did nothing."
    exit 1
fi

echo "Done."