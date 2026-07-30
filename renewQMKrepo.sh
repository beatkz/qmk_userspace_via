#! /bin/bash

if [ "$#" -eq 0 ]; then
    echo "usage: ./renewQMKrepo.sh -amdcg"
    echo "-a -> Update Debian based Distro(apt)[for QMK-WSL]"
    echo "-d -> Update RHEL based Distro(dnf)"
    echo "-p -> Update Arch based Distro(pacman)[for QMK-MSYS]"
    echo "-c -> Update QMK CLI"
    echo "-g -> Update Git Repository (auto-detects QMK or VIA userspace from first line of readme.md/README.md; add official repo as 'upstream' first)"
    echo "      QMK: merges upstream/master + make git-submodule"
    echo "      VIA: merges upstream/main"

    exit 1
fi

UPD_APT=FALSE
UPD_DNF=FALSE
UPD_PACMAN=FALSE
UPD_CLI=FALSE
UPD_GIT=FALSE

OPT=
OPTIND=
while getopts adpcg OPT ; do
    case $OPT in
        a) UPD_APT=TRUE; ;;
        d) UPD_DNF=TRUE; ;;
        p) UPD_PACMAN=TRUE; ;;
        c) UPD_CLI=TRUE; ;;
        g) UPD_GIT=TRUE; ;;
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

# Function to auto-detect repo type from first line of readme and update accordingly
# QMK: upstream/master + make git-submodule
# VIA userspace: upstream/main
detect_and_update_repo() {
    # Find root readme file (prefer README.md then readme.md)
    if [ -f "README.md" ]; then
        README_FILE="README.md"
    elif [ -f "readme.md" ]; then
        README_FILE="readme.md"
    else
        echo "Error: No README.md or readme.md found in current directory."
        exit 1
    fi

    # Read first line (title) for detection
    TITLE=$(head -n 1 "$README_FILE")

    echo "Detected readme title: $TITLE"
    echo "Updating repository (upstream must be configured)..."

    # Common fetch
    git fetch --all || { echo "Error: git fetch failed."; exit 1; }

    # Detect using boolean-style variables (as requested)
    IS_QMK=false
    IS_US_VIA=false
    if echo "$TITLE" | grep -qi "Quantum Mechanical Keyboard Firmware"; then
        IS_QMK=true
    elif echo "$TITLE" | grep -qi "VIA's QMK Userspace"; then
        IS_US_VIA=true
    fi

    if [ "$IS_QMK" = true ]; then
        # QMK firmware repo
        echo "QMK repository detected - merging upstream/master and updating submodules..."
        git merge --no-edit upstream/master || { echo "Error: git merge failed."; exit 1; }
        make git-submodule || { echo "Warning: make git-submodule failed."; }
    elif [ "$IS_US_VIA" = true ]; then
        # VIA userspace repo
        echo "VIA userspace repository detected - merging upstream/main..."
        git merge --no-edit upstream/main || { echo "Error: git merge failed."; exit 1; }
    else
        echo "Error: Unknown repository type based on readme title."
        echo "Supported:"
        echo "  - QMK: '# Quantum Mechanical Keyboard Firmware'"
        echo "  - VIA: '# VIA's QMK Userspace'"
        echo "Please check your readme.md or configure upstream manually."
        exit 1
    fi

    echo "Repository update completed successfully."
}

if [ $UPD_GIT = "TRUE" ] ; then
    detect_and_update_repo
fi
