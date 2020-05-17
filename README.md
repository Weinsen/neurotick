# Neurotick

Small project of Neural Networks for education reasons. The main goal is to achieve an easy to use, easy to train Neural Network and then "compile" a static and performatic model, for either run as a stand-alone or to be included in another project.

Whole project compiles as a static lib. Examples and main demonstration compile using static lib into own
executable.

# Build

```
cd ./Build
cmake ..
make
```

# Dependencies

None

# Examples

Examples of use are provided to better demonstrate usage. Each one has a proper README.md file, but the
summary below shows descriptions for them:

## BlockRace

Block Race is an example using neurotick neural network engine. Each letter in the screen represents a racer.
All of them starts at center of the screen, and every race has a new pair of coordenates for the goal. Run 
uniquely on terminal, no GUI.

# To Do

- Genetic method (% ofsprings not similar, multiple parents)
- Save model to file
- Templates
- Check vector size, pointer access
- Transfer functions
- Generate static and more performatic model

# Doxygen use

Doxyfile provided is ready to use. Simply enter:

```
doxygen Doxyfile
```

# Changelog

## v0.1.5

- Better model abstraction
- Documentation
- Namespace neurotick::

## v0.1.4

- Block race example
- Improvments on APIs

## v0.1.3

- 1D Connection vector
- Simpler neuron usage
- Removed NeuronInputValue
- Layer assign operator
- Model assign operator

## v0.1.2

- Hardcoded sigmoid
- Vector and matrix connections (graph)

## v0.1.1

- Better model creation
- Connectors (full connect only)
- Small serialization

## v0.1.0

- Initial release
- Primitive neurons
- Layer structure
- Model