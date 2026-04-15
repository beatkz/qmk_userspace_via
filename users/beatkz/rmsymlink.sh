#! /bin/bash

TARGET=$1 # キーボードフォルダーまでのフルパスが入る

unlink $1/nicola.h
unlink $1/nicola.c
unlink $1/key_duration.h
unlink $1/key_duration.c
unlink $1/key_duration_arm.c

