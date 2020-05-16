#include "train.hpp"

Trainer::Trainer(Model& model) : model(model)
{
	
}

Model& Trainer::createModel()
{
	Connector linker;
	std::vector<double> w(model.parameters(), 0);

	models.push_back(new Model(model));

	models.back()->setConnections(w);

	return *(models.back());
}

Trainer& Trainer::createModels()
{
	int q = batch_size;
	while (q) {
		createModel();
		q--;
	}

	return *this;
}

Model& Trainer::getModel(int id)
{
	return *models[id]; 
}

Trainer& Trainer::randomizeVector(Model& model)
{
	std::vector<double> w;

	std::random_device r;
    std::default_random_engine e1(r());
    std::uniform_real_distribution<double> uniform_dist(0, sigma);
    for (auto v : model.getConnections()) {
        w.push_back(v + uniform_dist(e1) -sigma/2);
    }  

    model.setConnections(w);

	return *this;
}

Trainer& Trainer::randomizeVectors()
{
	for (auto m : models) {
		randomizeVector(*m);
	}
}

Trainer& Trainer::setBatch(int size)
{
	batch_size = size;
	return *this;
}

Trainer& Trainer::setSigma(double s)
{
	sigma = s;
	return *this;
}

Trainer& Trainer::run()
{	
	Connector linker;

	int q = batch_size;
	for (auto m : models) {
		randomizeVector(*m);
		linker.connect(*m);
		m->calculate();
	}

	return *this;
}

Trainer& Trainer::genetic(Model& model)
{
	std::vector<double> w = model.getConnections();

	for (auto m : models) {
		m->setConnections(w);
	}

	randomizeVectors();
}

Trainer& Trainer::genetic(Model *model)
{
	std::vector<double> w = model->getConnections();

	for (auto m : models) {
		m->setConnections(w);
	}

	randomizeVectors();
}

std::vector<std::vector<double>> Trainer::output()
{
	std::vector<std::vector<double>> out;
	for (auto m : models) {
		out.push_back(m->output());
	}
	return out;
}

std::vector<double> Trainer::output(int id)
{
	return models[id]->output();
}