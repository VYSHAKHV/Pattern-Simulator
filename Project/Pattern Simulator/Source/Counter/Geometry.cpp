#include "stdafx.h"
#include "Geometry.h"


Geometry::Geometry(int height, int width, double zp)
{
	this->l = width;
	this->h = height;
	this->zp = zp;

	_prevMousePoint = Point2D(0, 0);
}

Point2D Geometry::PerspectiveProjection(Point3D A)
{
	Point2D p2d;

	double c = zp / (A.z - zp);
	p2d.x = l + c * A.x;
	p2d.y = h - c * A.y;

	return p2d;
}

void Geometry::AddPoint3D(Point3D p)
{
	_3DPoints.push_back(p);
}

void Geometry::AddUnion(Union u)
{
	_unions.push_back(u);
}

void Geometry::SetPrevMousePoint(Point2D newMousePoint)
{
	_prevMousePoint = newMousePoint;
}

Point2D Geometry::GetPrevMousePoint()
{
	return _prevMousePoint;
}

void Geometry::Draw(CPaintDC *dc)
{
	ApplyPerspectiveProjection();

	for (int i = 0; i<(int)_unions.size(); i++)
	{
		dc->MoveTo(_2DPoints[_unions[i].i1].x, _2DPoints[_unions[i].i1].y);
		dc->LineTo(_2DPoints[_unions[i].i2].x, _2DPoints[_unions[i].i2].y);
	}
}

void Geometry::ApplyPerspectiveProjection()
{
	_2DPoints.resize(_3DPoints.size());

	for (int i = 0; i<(int)_3DPoints.size(); i++)
		_2DPoints[i] = PerspectiveProjection(_3DPoints[i]);
}

void Geometry::Rotate(double &x, double &y, double xc, double yc, double cosu, double sinu)
{
	double x0 = x;
	x = (x - xc)*cosu - (y - yc)*sinu + xc;
	y = (x0 - xc)*sinu + (y - yc)*cosu + yc;
}

void Geometry::CalculateUVector(int n, int a, int b)
{
	m_n = n;
	u_Vector.push_back(a);
	for (int i = 1; i <= n; i++)
	{
		double test2 = b - a;
		double m_dDelta = test2 / n;
		//u_Vector.push_back(a + n* ( (b - a) / n) );
		float test = u_Vector[i - 1] + (b - a) / n;
		u_Vector.push_back(u_Vector[i - 1] + m_dDelta);
	}

}


void Geometry::ApplyAllFuncs(int A, int B, int C)
{
	for (int i = 0; i < m_n; i++)
	{
		Point3D temp;
		temp.x = A*u_Vector[i] * cos(u_Vector[i]);
		temp.y = A*u_Vector[i] * sin(u_Vector[i]);
		temp.z = B*u_Vector[i] + C;

		_3DPoints.push_back(temp);
	}

	for (int i = 0; i < m_n - 1; i++)
	{
		_unions.push_back(Union(i, i + 1));
	}
}

void Geometry::Ffunc(float u)
{

}

void Geometry::Gfunc(float u)
{
}

void Geometry::Hfunc(float u)
{
}

void Geometry::RotateOnOY(double u)
{
	if (!_3DPoints.size())
		return;

	double cosu = cos(u), sinu = sin(u);

	double zg = 0, xg = 0;

	for (int i = 0; i<(int)_3DPoints.size(); i++)
	{
		zg += _3DPoints[i].z;
		xg += _3DPoints[i].x;
	}

	zg /= _3DPoints.size();
	xg /= _3DPoints.size();

	for (int i = 0; i<(int)_3DPoints.size(); i++)
		Rotate(_3DPoints[i].z, _3DPoints[i].x, zg, xg, cosu, sinu);
}

void Geometry::RotateOnOZ(double u)
{
	if (!_3DPoints.size())
		return;

	double cosu = cos(u), sinu = sin(u);

	double xg = 0, yg = 0;

	for (int i = 0; i<(int)_3DPoints.size(); i++)
	{
		xg += _3DPoints[i].x;
		yg += _3DPoints[i].y;
	}

	xg /= _3DPoints.size();
	yg /= _3DPoints.size();

	for (int i = 0; i<(int)_3DPoints.size(); i++)
		Rotate(_3DPoints[i].x, _3DPoints[i].y, xg, yg, cosu, sinu);
}

void Geometry::RotateOnOX(double u)
{
	if (!_3DPoints.size())
		return;

	double cosu = cos(u), sinu = sin(u);

	double yg = 0, zg = 0;

	for (int i = 0; i<(int)_3DPoints.size(); i++)
	{
		yg += _3DPoints[i].y;
		zg += _3DPoints[i].z;
	}

	yg /= _3DPoints.size();
	zg /= _3DPoints.size();

	for (int i = 0; i<(int)_3DPoints.size(); i++)
		Rotate(_3DPoints[i].y, _3DPoints[i].z, yg, zg, cosu, sinu);
}

void Geometry::TranslateOnOx(double dx)
{
	if (!_3DPoints.size())
		return;
	for (int i = 0; i<(int)_3DPoints.size(); i++)
	{
		_3DPoints[i].x += dx;
	}
}

void Geometry::TranslateOnOz(double zx)
{
	if (!_3DPoints.size())
		return;

	for (int i = 0; i<(int)_3DPoints.size(); i++)
	{
		_3DPoints[i].z += zx;
	}
}




