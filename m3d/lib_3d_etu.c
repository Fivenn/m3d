#include "lib_3d.h"
#include "lib_mat.h"

t_point3d *definirPoint3d_etu(double x, double y, double z)	// attention malloc
{
	t_point3d *p;

	p = (t_point3d *) malloc(sizeof(t_point3d));
	if (p != NULL) {
		p->xyzt[0] = x;
		p->xyzt[1] = y;
		p->xyzt[2] = z;
		p->xyzt[3] = 1;
	}

	return p;
}

t_point3d *definirVecteur3d_etu(double x, double y, double z)	// attention malloc
{
	t_point3d *p;

	p = (t_point3d *) malloc(sizeof(t_point3d));
	if (p != NULL) {
		p->xyzt[0] = x;
		p->xyzt[1] = y;
		p->xyzt[2] = z;
		p->xyzt[3] = 0;
	}

	return p;
}

t_point3d *copierPoint3d_etu(t_point3d * p)	// attention malloc
{
	return definirPoint3d(p->xyzt[0], p->xyzt[1], p->xyzt[2]);
}

void libererPoint3d_etu(t_point3d * p)
{
	free(p);
}

t_triangle3d *definirTriangle3d_etu(t_point3d * a, t_point3d * b, t_point3d * c){
	t_triangle3d * t=(t_triangle3d *)malloc(sizeof(t_triangle3d));
	t->abc[0]=copierPoint3d_etu(a);
	t->abc[1]=copierPoint3d_etu(b);
	t->abc[2]=copierPoint3d_etu(c);

	return t;
}

t_triangle3d *copierTriangle3d_etu(t_triangle3d * t)	// attention malloc multiples
{
	return definirTriangle3d_etu(t->abc[0], t->abc[1], t->abc[2]);
}

void libererTriangle3d_etu(t_triangle3d * t)
{
	free(t);
}

double xmoyen_etu(t_triangle3d * t){
	double xmoyen=0.0;

	for (int i = 0; i < 3; ++i){
		xmoyen+=t->abc[i]->xyzt[0];
	}
	xmoyen=xmoyen/3;

	return xmoyen;
}

double ymoyen_etu(t_triangle3d * t){
	double ymoyen=0.0;

	for (int i = 0; i < 3; ++i)
	{
		ymoyen+=t->abc[i]->xyzt[1];
	}
	ymoyen=ymoyen/3;

	return ymoyen;
}

double zmoyen_etu(t_triangle3d * t){
	double zmoyen=0.0;

	for (int i = 0; i < 3; ++i){
		zmoyen+=t->abc[i]->xyzt[2];
	}
	zmoyen=zmoyen/3;

	return zmoyen;
}

t_point3d *centreGraviteTriangle3d_etu(t_triangle3d * t)	// attention malloc (definirPoint)
{
	t_point3d * tmp=definirPoint3d_etu((double)t->abc[0],(double)t->abc[1] , zmoyen(t));
	return tmp;
}

void remplirTriangle3d_etu(t_surface * surface, t_triangle3d * triangle, Uint32 couleur, double l, double h, double d)
{
	t_point2d * a=definirPoint2d(surface->x/2+(int)triangle->abc[0]->xyzt[0], surface->y/2-(int)triangle->abc[0]->xyzt[1]);
	t_point2d * b=definirPoint2d(surface->x/2+(int)triangle->abc[1]->xyzt[0], surface->y/2-(int)triangle->abc[1]->xyzt[1]);
	t_point2d * c=definirPoint2d(surface->x/2+(int)triangle->abc[2]->xyzt[0], surface->y/2-(int)triangle->abc[2]->xyzt[1]);
	t_triangle2d * t2d=definirTriangle2d(a, b, c);
	remplirTriangle2d(surface, t2d, couleur);
	libererTriangle2d(t2d);
	libererPoint2d(a);
	libererPoint2d(b);
	libererPoint2d(c);
}

void translationTriangle3d_etu(t_triangle3d * t, t_point3d * vecteur){

}

void rotationTriangle3d_etu(t_triangle3d * t, t_point3d * centre, float degreX, float degreY, float degreZ){
	//double matrice_x[4][4]={{1,0,0,0}, {0, cos(degreX), -sin(degreX), 0}, {0, sin(degreX), cos(degreX), 0}, {0, 0, 0, 1}};
	//double matrice_y[4][4]={{cos(degreY), 0, sin(degreY), 0}, {0,1,0, 0}, {-sin(degreY), 0, cos(degreY), 0}, {0, 0, 0, 1}};
	//double matrice_z[4][4]={{cos(degreZ), -sin(degreZ), 0, 0}, {sin(degreZ), cos(degreZ), 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
}

void transformationTriangle3d_etu(t_triangle3d * t, double mat[4][4]){
	int i;
	t_point3d * tmp=definirPoint3d_etu(0,0,0);

	for(i=0; i<3; ++i){
		multiplication_vecteur(tmp, mat, t->abc[i]);
		t->abc[i]->xyzt[0]=tmp->xyzt[0];
		t->abc[i]->xyzt[1]=tmp->xyzt[1];
		t->abc[i]->xyzt[2]=tmp->xyzt[2];
		t->abc[i]->xyzt[3]=tmp->xyzt[3];
	}
	libererPoint3d_etu(tmp);
}
