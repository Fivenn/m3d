# LIBSDL=SDL ou LIBSDL=SDL2 a definir lors de l'appel :
# LIBSDL=SDL make
# LIBSDL=SDL2 make

LIBSDL=SDL2

#OPT=-g -O0
OPT=-Ofast
#OPT=-O3

# gnu11 au lieu de c11 permet d'avoir (entre autre) la definition de M_PI
OPT_NORME=-Wall -Werror -Wextra -Wconversion -ansi -Wpedantic -Wno-unused-parameter -std=gnu11

prog_${LIBSDL}: prog.c fonctions.c lib_2d.o lib_mat.o lib_surface_${LIBSDL}.o lib_3d_etu.o lib_objet3d_etu.o lib_scene3d_etu.o PA_3d_PIC.o PA_objet3d_PIC.o PA_scene3d_PIC.o
	gcc ${OPT} ${OPT_NORME} -D COMPIL_${LIBSDL} -march=native prog.c fonctions.c lib_2d.o lib_mat.o lib_surface_${LIBSDL}.o lib_3d_etu.o lib_objet3d_etu.o lib_scene3d_etu.o PA_3d_PIC.o PA_objet3d_PIC.o PA_scene3d_PIC.o -o prog_${LIBSDL} -lm -l${LIBSDL}

################### Fichiers a completer
lib_3d_etu.o: lib_3d_etu.c lib_3d.h
	gcc ${OPT} ${OPT_NORME} -D COMPIL_${LIBSDL} -c -march=native lib_3d_etu.c

lib_objet3d_etu.o: lib_objet3d_etu.c lib_objet3d.h
	gcc ${OPT} ${OPT_NORME} -D COMPIL_${LIBSDL} -c -march=native lib_objet3d_etu.c

lib_scene3d_etu.o: lib_scene3d_etu.c lib_scene3d.h
	gcc ${OPT} ${OPT_NORME} -D COMPIL_${LIBSDL} -c -march=native lib_scene3d_etu.c

################### Fichiers a ne pas modifier (a priori)
lib_surface_${LIBSDL}.o: lib_surface_${LIBSDL}.c lib_surface.h
	gcc ${OPT} ${OPT_NORME} -D COMPIL_${LIBSDL} -fPIC -c -march=native lib_surface_${LIBSDL}.c

lib_2d.o: lib_2d.c lib_2d.h
	gcc ${OPT} ${OPT_NORME} -D COMPIL_${LIBSDL} -c -march=native lib_2d.c

lib_mat.o: lib_mat.c lib_mat.h lib_3d.h
	gcc ${OPT} ${OPT_NORME} -D COMPIL_${LIBSDL} -c -march=native lib_mat.c

###################
clean:
	rm -f lib_*.o prog_SDL prog_SDL2
