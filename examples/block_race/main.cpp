#include "neural.hpp"
#include "racer.hpp"
#include "track.hpp"

using namespace neurotick;

int main() 
{ 

    // Game parameters
    Track track;
    track.width(55).height(33).capacity(60).newGoal();

    // Create model
    Model model;
    model.addLayer("i", 3).addLayer("o", 2);

    // Model engines
    Trainer engine(model);
    engine.setBatch(track.capacity());
    engine.randomizeVectors();
    track.engine(&engine);


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
