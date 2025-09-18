@echo off
SET TARGET=%1

del %TARGET%\keymaps\nicola_via\nicola.h
del %TARGET%\keymaps\nicola_via\nicola.c
del %TARGET%\keymaps\nicola_via\key_duration.h
del %TARGET%\keymaps\nicola_via\key_duration.c
del %TARGET%\keymaps\nicola_via\key_duration_arm.c
mklink /h %TARGET%\keymaps\nicola_via\nicola.h .\nicola.h > NUL
mklink /h %TARGET%\keymaps\nicola_via\nicola.c .\nicola.c > NUL
mklink /h %TARGET%\keymaps\nicola_via\key_duration.h .\key_duration.h > NUL
mklink /h %TARGET%\keymaps\nicola_via\key_duration.c .\key_duration.c > NUL
mklink /h %TARGET%\keymaps\nicola_via\key_duration_arm.c .\key_duration_arm.c > NUL
