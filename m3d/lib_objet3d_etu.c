#include <assert.h>
#include <math.h>
#include <float.h>
#include "lib_mat.h"
#include "lib_objet3d.h"

int nb_faces = 0;

t_maillon *__cree_maillon_etu(t_triangle3d * face, Uint32 couleur){ //Attention au malloc !!
	t_maillon* m=(t_maillon *)malloc(sizeof(t_maillon));

	m->face=face;
	m->couleur=couleur;
	m->pt_suiv=NULL;

	return m;
}

void __insere_tete_etu(t_objet3d * pt_objet, t_maillon * pt_maillon){
	pt_maillon->pt_suiv=pt_objet->tete;
	pt_objet->tete=pt_maillon;
}

/*
 * CREATION DES OBJETS
 */

t_objet3d *objet_vide_etu(){
	t_objet3d * obj=(t_objet3d *)malloc(sizeof(t_objet3d)); //Attention au malloc !!

	obj->est_trie=false;
	obj->est_camera=false;
	obj->largeur=0.0;
	obj->hauteur=0.0;
	obj->proche=0.0;
	obj->loin=0.0;
	obj->distance_ecran=0.0;
	obj->possede_texture=false;
	obj->texture=NULL;
	obj->tete=NULL;

	return obj;
}

t_objet3d *camera_etu(double l, double h, double n, double f, double d)
{
	t_objet3d *pt_objet = objet_vide();
	pt_objet->est_camera=true;
	pt_objet->largeur=l;
	pt_objet->hauteur=h;
	pt_objet->proche=n;
	pt_objet->loin=f;
	pt_objet->distance_ecran=d;

	return pt_objet;
}

t_objet3d *objet_fichier_etu(char *fn, Uint32 c1, Uint32 c2)
{
	t_objet3d *pt_objet = objet_vide();
	return pt_objet;
}

t_objet3d *parallelepipede_etu(double lx, double ly, double lz)
{
	t_objet3d *pt_objet = objet_vide();
	return pt_objet;
}

t_objet3d *tore_etu(double r1, double r2, double nlat, double nlong)
{
	t_objet3d *pt_objet = objet_vide();
	return pt_objet;
}

t_objet3d *sphere_etu(double r, double nlat, double nlong)
{
	t_objet3d *pt_objet = objet_vide();
	return pt_objet;
}

t_objet3d *sphere_amiga_etu(double r, double nlat, double nlong)
{
	t_objet3d *pt_objet = objet_vide();
	return pt_objet;
}

t_objet3d *arbre_etu(double lx, double ly, double lz)
{
	t_objet3d *pt_objet = objet_vide();
	return pt_objet;
}

t_objet3d *sinc_etu(double lx, double lz, double nx, double nz)
{
	t_objet3d *pt_objet = objet_vide();
	return pt_objet;
}

t_objet3d *damier_etu(double lx, double lz, double nx, double nz)
{
	t_objet3d *pt_objet = objet_vide();
	return pt_objet;
}

t_objet3d *sierpinski_etu(double lx, double ly, double lz, int n)
{
	t_objet3d *pt_objet = objet_vide();
	return pt_objet;
}

void creerCarre3d(t_objet3d *obj, Uint32 couleur, double x, double y, double z){
	//Face avant
	__insere_tete_etu(obj, __cree_maillon_etu(definirTriangle3d(definirPoint3d(x+0.0, y+0.0, z+0.0), definirPoint3d(x+0.0, y+1.0, z+0.0), definirPoint3d(x+1.0, y+0.0, z+0.0)), couleur));
	__insere_tete_etu(obj, __cree_maillon_etu(definirTriangle3d(definirPoint3d(x+1.0, y+1.0, z+0.0), definirPoint3d(x+0.0, y+1.0, z+0.0), definirPoint3d(x+1.0, y+0.0, z+0.0)), couleur));
	//Face arrière
	__insere_tete_etu(obj, __cree_maillon_etu(definirTriangle3d(definirPoint3d(x+0.0, y+0.0, z+1.0), definirPoint3d(x+0.0, y+1.0, z+1.0), definirPoint3d(x+1.0, y+0.0, z+1.0)), couleur));
	__insere_tete_etu(obj, __cree_maillon_etu(definirTriangle3d(definirPoint3d(x+1.0, y+1.0, z+1.0), definirPoint3d(x+0.0, y+1.0, z+1.0), definirPoint3d(x+1.0, y+0.0, z+1.0)), couleur));
	//Face dessous
	__insere_tete_etu(obj, __cree_maillon_etu(definirTriangle3d(definirPoint3d(x+0.0, y+0.0, z+0.0), definirPoint3d(x+0.0, y+0.0, z+1.0), definirPoint3d(x+1.0, y+0.0, z+0.0)), couleur));
	__insere_tete_etu(obj, __cree_maillon_etu(definirTriangle3d(definirPoint3d(x+1.0, y+0.0, z+0.0), definirPoint3d(x+1.0, y+0.0, z+1.0), definirPoint3d(x+0.0, y+0.0, z+1.0)), couleur));
	//Face dessus
	__insere_tete_etu(obj, __cree_maillon_etu(definirTriangle3d(definirPoint3d(x+0.0, y+1.0, z+0.0), definirPoint3d(x+0.0, y+1.0, z+1.0), definirPoint3d(x+1.0, y+1.0, z+0.0)), couleur));
	__insere_tete_etu(obj, __cree_maillon_etu(definirTriangle3d(definirPoint3d(x+1.0, y+1.0, z+0.0), definirPoint3d(x+1.0, y+1.0, z+1.0), definirPoint3d(x+0.0, y+1.0, z+1.0)), couleur));
	//Face droite
	__insere_tete_etu(obj, __cree_maillon_etu(definirTriangle3d(definirPoint3d(x+0.0, y+0.0, z+0.0), definirPoint3d(x+0.0, y+0.0, z+1.0), definirPoint3d(x+0.0, y+1.0, z+0.0)), couleur));
	__insere_tete_etu(obj, __cree_maillon_etu(definirTriangle3d(definirPoint3d(x+0.0, y+1.0, z+0.0), definirPoint3d(x+0.0, y+1.0, z+1.0), definirPoint3d(x+0.0, y+0.0, z+1.0)), couleur));
	//Face gauche
	__insere_tete_etu(obj, __cree_maillon_etu(definirTriangle3d(definirPoint3d(x+1.0, y+0.0, z+0.0), definirPoint3d(x+1.0, y+0.0, z+1.0), definirPoint3d(x+1.0, y+1.0, z+1.0)), couleur));
	__insere_tete_etu(obj, __cree_maillon_etu(definirTriangle3d(definirPoint3d(x+1.0, y+0.0, z+0.0), definirPoint3d(x+1.0, y+1.0,z+0.0), definirPoint3d(x+1.0, y+1.0, z+1.0)), couleur));
}

t_objet3d *monObjet(Uint32 couleur){
	t_objet3d *obj=objet_vide();
	FILE *fichier=NULL;
	double coordonnees[3]={0};
	int res_fscanf=0;

	fichier=fopen("mon_objet.txt", "r");

	if(fichier!=NULL){
		while(res_fscanf!=EOF){
		res_fscanf=fscanf(fichier, "%le %le %le", &coordonnees[0], &coordonnees[1], &coordonnees[2]);
		creerCarre3d(obj, couleur, coordonnees[0], coordonnees[1], coordonnees[2]);
		creerCarre3d(obj, couleur, coordonnees[0], coordonnees[1], coordonnees[2]+1);
		}
		fclose(fichier);
	}
	return obj;
}

/*
 * GESTION DES OBJETS
 */

t_objet3d *copierObjet3d_etu(t_objet3d * o)	// retourne une copie de o
{
	t_objet3d *pt_objet = objet_vide();
	return pt_objet;
}

void composerObjet3d_etu(t_objet3d * o, t_objet3d * o2)
{				/* o = o+o2, o2 ne signifiera plus rien */
}

void libererObjet3d_etu(t_objet3d * o){
	t_maillon* tmp=o->tete;
	t_maillon* tmp2;
	while(tmp!=NULL){
		tmp2=tmp->pt_suiv;
		libererTriangle3d(tmp->face);
		free(tmp);
		tmp=tmp2;
	}
	free(o);
}

t_point3d *centreGraviteObjet3d_etu(t_objet3d * o)	//attention malloc (definirVecteur)
{
	return NULL;
}

void trierObjet3d_etu(t_objet3d * pt_objet)
{
}

void dessinerObjet3d_etu(t_surface * surface, t_objet3d * pt_objet, t_objet3d * camera)
{
}

/*
 * TRANSFORMATION DES OBJETS
 */

void translationObjet3d_etu(t_objet3d * pt_objet, t_point3d * vecteur){
}

void homothetieObjet3d_etu(t_objet3d * pt_objet, float facteurX, float facteurY, float facteurZ)
{
}

void rotationObjet3d_etu(t_objet3d * pt_objet, t_point3d * centre, float degreX, float degreY, float degreZ)
{
}

void transformationObjet3d_etu(t_objet3d * pt_objet, double mat[4][4]){
	
}
