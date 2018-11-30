#ifndef LIB_SCENE3D_H_
#define LIB_SCENE3D_H_

#include "lib_objet3d.h"


	
	
	
	
	t_scene3d *pt_fils;	// descendants
	t_scene3d *pt_suiv;	// liste chainee de noeud
};

/*
 * Zone PA
 */ 
    

void translationScene3d_PA(t_scene3d * pt_scene, t_point3d * vecteur);




/*
 * Zone etu
 */ 
    

void translationScene3d_etu(t_scene3d * pt_scene, t_point3d * vecteur);




/*
 * -------------------------------------------
 */ 
    
/* entrée : un objet 3d
 * sortie : une scene 3d ne comportant qu'un seul objet
 */ 
extern t_scene3d *(*definirScene3d) (t_objet3d * pt_objet);

/* entrée : un pointeur sur un noeud (eventuellement feuille) de l'arbre scene 3d, et un objet 3d
 * sortie : le noeud de l'arbre qui contient l'objet 3d
 */ 
extern t_scene3d *(*ajouter_relation) (t_scene3d * pt_feuille, t_objet3d * pt_objet);

/* entrée : une scene 3d (la racine de l'arbre) et un vecteur de translation
 * sortie : void
 */ 
extern void (*translationScene3d) (t_scene3d * pt_scene, t_point3d * vecteur);

/* entrée : une scene 3d (la racine de l'arbre) et un point 3d centre de rotation et les angles de rotation
 * sortie : void
 */ 
extern void (*rotationScene3d) (t_scene3d * pt_scene, t_point3d * centre, float degreX, float degreY, float degreZ);

/* entrée : une scene 3d à afficher sur la surface
 * sortie : void
 */ 
extern void (*dessinerScene3d) (t_surface * surface, t_scene3d * pt_scene);

/* entrée : une scene 3d à libérer de la mémoire
 * sortie : void
 */ 
extern void (*libererScene3d) (t_scene3d * scene);


#endif	/* LIB_SCENE3D_H_ */