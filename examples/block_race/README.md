# neurotick::BlockRace

Block Race is an example using neurotick neural network engine. Each letter in the screen represents a racer.
All of them starts at center of the screen, and every race has a new pair of coordenates for the goal.

# Race objectives

- Be the first to reach the goal #
- Do not touch the borders

# Genetic selection

Each race the best fit will be selected. It's features will be applied to all racers with a small variation.
This will allow to carry the best characteristics, avoiding "local best fits".

# Neural configuration



# How it is using neurotick

In main.cpp of this simulation, a neural model is created using neurotick API.

```
Model model;
model.addLayer("l1").addLayer("l2");
model.getLayer("l1").addNeurons(3);
model.getLayer("l2").addNeurons(2);
```

This model is later passed to a training engine, which will manage the genetic passing of code each race.
```
Trainer engine(model);
```

To each racer is passed a new instace of model (track.cpp).
```
r->engine(eng->createModel());
```

Each iteration, the engine is updated, similar to a physics engine tick. In this process, the inputs are given to the engine to calculate its outputs (racer.cpp). In this case, the inputs are relative to the distance to the goal, and the outputs are commands for vertical and horizontal moviments.
```
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
```

