#! /bin/bash

TARGET=$1 # キーボードフォルダーまでのフルパスが入る

ln -s ${PWD}/nicola.h $1/keymaps/nicola_via/nicola.h
ln -s ${PWD}/nicola.c $1/keymaps/nicola_via/nicola.c
ln -s ${PWD}/key_duration.h $1/keymaps/nicola_via/key_duration.h
ln -s ${PWD}/key_duration.c $1/keymaps/nicola_via/key_duration.c
ln -s ${PWD}/key_duration_arm.c $1/keymaps/nicola_via/key_duration_arm.c

