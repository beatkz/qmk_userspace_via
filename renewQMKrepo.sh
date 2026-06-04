#! /bin/bash

if [ "$#" -ne 1 ]; then
    echo "usage: ./renewQMKrepo.sh -amdcg"
    echo "-a -> Update Debian based Distro(apt)[for QMK-WSL]"
    echo "-d -> Update RHEL based Distro(dnf)"
    echo "-p -> Update Arch based Distro(pacman)[for QMK-MSYS]"
    echo "-c -> Update QMK CLI"
    echo "-g -> Update QMK Git Repositry(add official repo as 'upstream' first)"
    echo "-v -> Update VIA's Userspace QMK Git Repositry(add official repo as 'upstream' first)"

    exit 1
fi

UPD_APT=FALSE
UPD_DNF=FALSE
UPD_PACMAN=FALSE
UPD_CLI=FALSE
UPD_GIT=FALSE
UPD_US_VIA=FALSE

OPT=
OPTIND=
while getopts adpcgmv OPT ; do
    case $OPT in
        a) UPD_APT=TRUE; ;;
        d) UPD_DNF=TRUE; ;;
        p) UPD_PACMAN=TRUE; ;;
        c) UPD_CLI=TRUE; ;;
        g) UPD_GIT=TRUE; ;;
        v) UPD_US_VIA=TRUE; ;;
    esac
done
shift $(expr $OPTIND - 1)

if [ $UPD_APT = "TRUE" ] ; then
    #Update for Debian based Distro
    sudo apt update && sudo apt -y upgrade
fi

if [ $UPD_DNF = "TRUE" ] ; then
    #Update for RHEL based Distro
    sudo dnf -y update
fi

if [ $UPD_PACMAN = "TRUE" ] ; then
    #Update for Arch based Distro
    pacman -Syu --noconfirm
fi

if [ $UPD_CLI = "TRUE" ] ; then
    #Update for QMK CLI
    python3 -m pip install -U -r requirements.txt
fi

if [ $UPD_GIT = "TRUE" ] ; then
    #Update for QMK Repo
    git fetch --all
    git merge --no-edit --ff-only upstream/master
    make git-submodule
fi

if [ $UPD_US_VIA = "TRUE" ] ; then
    #Update for VIA's Userspace QMK Git Repo
    git fetch --all
    git merge --no-edit --ff-only upstream/main
fi
