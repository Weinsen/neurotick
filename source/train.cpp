#include "train.hpp"

Trainer::Trainer(Model& model) : model(model)
{
	
}

Trainer& Trainer::randomizeVector(Model& model)
{
	std::vector<double> w;

	std::random_device r;
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(-sigma, sigma);
    for (auto v : model.getConnections()) {
        w.push_back(v + uniform_dist(e1));
    }  

    model.setConnections(w);

	return *this;
}

Trainer& Trainer::setBatch(int size)
{
	batch_size = size;
	return *this;
}

Trainer& Trainer::setSigma(int s)
{
	sigma = s;
	return *this;
}

Trainer& Trainer::run()
{
	Connector linker;
	
	int q = batch_size;
	std::cout << "<<<<TEST>>>>>>" << std::endl;
	while (q) {
		models.push_back(new Model(model));
		randomizeVector(*(models.back()));
		linker.connect(*(models.back()));
		models.back()->calculate();
		std::cout << models.back()->getLayer("l3") << std::endl;
		q--;
	}
	std::cout << "<<<<TEST>>>>>>" << std::endl;

	return *this;
}