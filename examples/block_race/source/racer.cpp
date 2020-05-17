#include "racer.hpp"

int Racer::count = 0;

Racer::Racer()
{
	id = count++;
	pos = new PointVector();
	vel = new PointVector();
}

Racer& Racer::engine(Model& engine)
{
	model = &engine;
	return *this;
}

Racer& Racer::update()
{
	// Difference to goal
	std::vector<double> i;
	i.push_back(pos->getX() - goal->getX());
	i.push_back(pos->getY() - goal->getY());
	i.push_back(pos->distance(*goal));
	model->input(i);
	model->calculate();

	auto v = model->output();
	v[0] = 2*v[0] - 1;
	v[1] = 2*v[1] - 1;
	vel->set(v);
	pos->add(vel->get());
	return *this;
}

Racer& Racer::target(PointVector& target)
{
	goal = &target;
	return *this;
}

int Racer::getId() 
{
	return id;
}

char Racer::getTag()
{
	return id + 'A';
}

Racer& Racer::setStatus(std::string status)
{
	this->status = status;
	return *this;
}

std::string Racer::getStatus()
{
	return status;
}