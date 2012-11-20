#!/bin/bash

echo "Mobile Platform Info Build Script starting"

PListFullPath="${SRCROOT}/iOS-Info.plist"
if [[  $1 ]]; then
	echo "Using PList File ${1}"
	PListFullPath=$1
fi

PListFile=$(/usr/bin/basename ${PListFullPath})
PListDir=$(/usr/bin/dirname ${PListFullPath})
OriginalPath=$(pwd)

function lazyError
{
    if [ "$?" != "0" ]; then
        log.sh "$1"
        exit 1
    fi
}

echo "Pulling latest from git origin"

cd ${PListDir}
lazyError "Unable to switch to ${PListDir} folder"

git pull origin
lazyError "Error pulling from git origin"

# Auto Increment Version Script
CFBundleVersion=$(/usr/libexec/PlistBuddy -c "Print CFBundleVersion" ${PListFile})
lazyError "Error finding old build version"
CFBundleVersion=$(($CFBundleVersion + 1))
CFBuildDate=$(date +%F" "%T%z)

echo "Incrimenting build number to ${CFBundleVersion} created on ${CFBuildDate}"

/usr/libexec/PlistBuddy -c "Set :CFBundleVersion $CFBundleVersion" ${PListFile}
lazyError "Error setting new build version"
/usr/libexec/PlistBuddy -c "Set :CFBuildDate $CFBuildDate" ${PListFile}
lazyError "Error setting new build date"

git add ${PListFile}
lazyError "Error adding ${PListFile} to git stage"
git commit -m "build ${CFBundleVersion}"
lazyError "Error committing to git"

git push origin
lazyError "Error pushing new build version to git origin"