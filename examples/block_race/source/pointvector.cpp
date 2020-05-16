#include "pointvector.hpp"

PointVector::PointVector() : x(0), y(0)
{

}

PointVector::PointVector(double x, double y) : x(x), y(y)
{

}

double PointVector::getX()
{
	return x;
}

double PointVector::getY()
{
	return y;
}

std::vector<double> PointVector::get()
{
	std::vector<double> v;
	v.push_back(x);
	v.push_back(y);
	return v;
}

PointVector& PointVector::set(std::vector<double> v)
{
	this->x = v[0];
	this->y = v[1];
	return *this;
}

PointVector& PointVector::set(double x, double y)
{
	this->x = x;
	this->y = y;
	return *this;
}

PointVector& PointVector::add(std::vector<double> v)
{
	this->x += v[0];
	this->y += v[1];
	return *this;
}

PointVector& PointVector::add(double x, double y)
{
	this->x += x;
	this->y += y;
	return *this;
}

PointVector& PointVector::setX(double x)
{
	this->x = x;
	return *this;
}

PointVector& PointVector::setY(double y)
{
	this->y = y;
	return *this;
}

double PointVector::getR()
{
	return sqrt(x*x + y*y);
}

double PointVector::getTheta()
{
	return atan2(x, y);
}

double PointVector::getDegree()
{
	return atan2(x, y) * 180 / 3.14159265;
}

double PointVector::distance(PointVector& point)
{
	return sqrt(pow(x-point.getX(), 2) + pow(y-point.getY(), 2));
}
