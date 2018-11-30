#include <assert.h>
#include <math.h>
#include "lib_mat.h"
#include "lib_scene3d.h"

/*
 * GESTION DES SCENES
 */

t_scene3d *definirScene3d_etu(t_objet3d * pt_objet)
{

	return NULL;
}

t_scene3d *ajouter_relation_etu(t_scene3d * pt_feuille, t_objet3d * pt_objet)	// ajout de l'objet en tete des fils
{

	return NULL;
}

t_point3d *centreGraviteScene3d_etu(t_scene3d * pt_scene)
{

	return NULL;
}

void dessinerScene3d_etu(t_surface * surface, t_scene3d * scn_camera)
{
}

void libererScene3d_etu(t_scene3d * scene)
{
}

/*
 * TRANSFORMATIONS DES SCENES
 */

void translationScene3d_etu(t_scene3d * pt_scene, t_point3d * vecteur)
{
}

void rotationScene3d_etu(t_scene3d * pt_scene, t_point3d * centre, float degreX, float degreY, float degreZ)
{
}
