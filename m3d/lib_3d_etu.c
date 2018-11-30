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

t_triangle3d *definirTriangle3d_etu(t_point3d * a, t_point3d * b, t_point3d * c)	// attention malloc
{
	return NULL;
}

t_triangle3d *copierTriangle3d_etu(t_triangle3d * t)	// attention malloc multiples
{
	return NULL;
}

void libererTriangle3d_etu(t_triangle3d * t)
{
}

double xmoyen_etu(t_triangle3d * t)
{
	return 0.0;
}

double ymoyen_etu(t_triangle3d * t)
{
	return 0.0;
}

double zmoyen_etu(t_triangle3d * t)
{
	return 0.0;
}

t_point3d *centreGraviteTriangle3d_etu(t_triangle3d * t)	// attention malloc (definirPoint)
{
	return NULL;
}

void remplirTriangle3d_etu(t_surface * surface, t_triangle3d * triangle, Uint32 c, double l, double h, double d)
{
}

void translationTriangle3d_etu(t_triangle3d * t, t_point3d * vecteur)
{
	double m[4][4]={{1,0,0,vecteur->xyzt[0]}, {0,1,0,vecteur->xyzt[1]}, {0,0,1,vecteur->xyzt[2]}, {0,0,0,1}};

	t_point3d tmp;
	for (int i = 0; i < 3; ++i)
	{
		multiplication_vecteur(&tmp, m, t->abc[1]);
	}
}

void rotationTriangle3d_etu(t_triangle3d * t, t_point3d * centre, float degreX, float degreY, float degreZ)
{
	//3 choix possible en fonction du point centre. Matrice trouvable sur internet.
}

void transformationTriangle3d_etu(t_triangle3d * t, double mat[4][4])
{
}
