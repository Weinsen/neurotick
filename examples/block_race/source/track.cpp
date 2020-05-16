#include "track.hpp"

Track::Track() 
{
	destination = new PointVector();
}

Track& Track::width(int width) 
{
	w = width;
	return *this;
}

Track& Track::height(int height) 
{
	h = height;
	return *this;
}

Track& Track::capacity(int capacity)
{
	cap = capacity;
	return *this;
}

Track& Track::engine(Trainer* engine)
{
	eng = engine;
}

Track& Track::populate()
{
	int i = cap;
    while (i) {
        racers.push_back(new Racer());
        Racer *r = racers.back();
        r->engine(eng->createModel());
        i--;
    }
}

Track& Track::newGoal() 
{
	std::random_device r;
    std::default_random_engine e1(r());
    std::uniform_real_distribution<double> ud1(0, w-1);
    std::uniform_real_distribution<double> ud2(0, h-1);
	destination->set(ud1(e1), ud2(e1));
	return *this;
}

Track& Track::resetRacers()
{
	for (auto r : racers) {
        r->pos->set(27, 17);
        r->target(goal());
        r->setStatus("running");
    }
    return *this;
}

Track& Track::setWinner(int w)
{
	winner = w;
	return *this;
}

Track& Track::race(int iterations)
{
	// Some ugly code ahead
	int it = 0;
	
	gen++;
	bestDistance = 999;

	while (it < iterations) {

        std::vector<std::vector<char>> grid(h, std::vector<char>(w, '.'));

        int count_alive = 0;

        for (auto r : racers) {

            // Dont mind the dead racers
            if (r->getStatus() != "running")
                continue;

            // Update engine
            r->update();
            auto x = round(r->pos->getX());
            auto y = round(r->pos->getY());

            if (x >= w || x < 0 || y >= h || y < 0) {
                r->setStatus("killed");
                continue;
            }

            count_alive++;

            // Print racers on grid
            grid[y][x] = r->getTag();
        }

        // Skip race if they all are dead
        if (!count_alive) {
            break;
        }

        // Print goal
        grid[destination->getY()][destination->getX()] = '#';

        for (auto x : grid[0]) {
            std::cout << std::endl;
        }

        std::cout << "GEN: " << gen << std::endl;
        std::cout << "IT:  " << it << std::endl;
        std::cout << "DIST: " << bestDistance << std::endl;

        for (auto x : grid[0]) {
            std::cout << "==";
        }            
        std::cout << std::endl;
        for (auto y : grid) {
            for (auto x : y) {
                std::cout << x << " ";
            }
            std::cout << std::endl;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        it++;

        for (auto r : racers) {
        	// Get the best racer so far
            double dist = r->pos->distance(*destination);
            if (dist < bestDistance) {
                bestDistance = dist;
                setWinner(r->getId());
            }

            // Set winner and end race
            if (dist < 1) {
                r->setStatus("winner");
                setWinner(r->getId());
                it=iterations;
            }
        }
    }
    return *this;
}

int Track::width() 
{
	return w;
}

int Track::height() 
{
	return h;
}

int Track::capacity() 
{
	return cap;
}

int Track::getWinner()
{
	return winner;
}

double Track::getBestDistance() 
{
	return bestDistance;
}

PointVector& Track::goal() 
{
	return *destination;
}