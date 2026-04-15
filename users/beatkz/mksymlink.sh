#! /bin/bash

TARGET=$1 # キーボードフォルダーまでのフルパスが入る

ln -s ${PWD}/nicola.h $1/nicola.h
ln -s ${PWD}/nicola.c $1/nicola.c
ln -s ${PWD}/key_duration.h $1/key_duration.h
ln -s ${PWD}/key_duration.c $1/key_duration.c
ln -s ${PWD}/key_duration_arm.c $1/key_duration_arm.c

