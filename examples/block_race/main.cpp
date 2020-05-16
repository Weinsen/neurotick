#include "neural.hpp"
#include "racer.hpp"
#include "track.hpp"

int main() 
{ 

    // Game parameters
    Track track;
    track.width(55).height(33).capacity(26).newGoal();

    // Create model
    Model model;
    model.addLayer("l1").addLayer("l2");
    model.getLayer("l1").addNeurons(3);
    model.getLayer("l2").addNeurons(2);
  
    // Model engines
    Trainer engine(model);
    engine.setBatch(track.capacity());
    engine.randomizeVectors();
    track.engine(&engine);
    std::vector<Racer *> racers;

    std::cout << "RACERS JOIN THE COMPETITION!" << std::endl;

    // Create racers, run only once
    track.populate();

    std::cout << "RACE START" << std::endl;

    while (1) {

    	// Set winner genetic code and its allowed variation
    	engine.setSigma(track.getBestDistance());
        engine.genetic(engine.getModel(track.getWinner()));

        // Set new goal
        track.newGoal();

        // Reset them to start position
        track.resetRacers();

        // Race lasts 100 iterations
        track.race(100);

    }

    return 0; 
} 
