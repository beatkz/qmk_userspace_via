@echo off
SET TARGET=%1

del %TARGET%\nicola.h
del %TARGET%\nicola.c
del %TARGET%\key_duration.h
del %TARGET%\key_duration.c
del %TARGET%\key_duration_arm.c
mklink /h %TARGET%\nicola.h .\nicola.h > NUL
mklink /h %TARGET%\nicola.c .\nicola.c > NUL
mklink /h %TARGET%\key_duration.h .\key_duration.h > NUL
mklink /h %TARGET%\key_duration.c .\key_duration.c > NUL
mklink /h %TARGET%\key_duration_arm.c .\key_duration_arm.c > NUL
