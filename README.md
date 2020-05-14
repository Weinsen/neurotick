# Neurotick

Small project of Neural Networks for education reasons. The main goal is to achieve an easy to use, easy to train Neural Network and then "compile" a static and performatic model, for either run as a stand-alone or to be included in another project.

## Build

cd ./Build
cmake ..
make

## To Do

- Copy model
- Templates
- Save model to file
- Method connect using graph
- Input / output as template
- Transfer functions
- Train method
- Better input classes
- "Compile" into static and more performatic model

## Changelog

### v0.1.3

- 1D Connection vector
- Simpler neuron usage
- Removed NeuronInputValue
- Layer assign operator
- Model assign operator

### v0.1.2

- Hardcoded sigmoid
- Vector and matrix connections (graph)

### v0.1.1

- Better model creation
- Connectors (full connect only)
- Small serialization

### v0.1.0

- Initial release
- Primitive neurons
- Layer structure
- Model