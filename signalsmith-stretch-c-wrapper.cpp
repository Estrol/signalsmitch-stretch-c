#define SIGNALSMITH_STRETCH_IMPLEMENTATION
#include "./signalsmith-stretch/signalsmith-stretch.h"

#include "signalsmith-stretch-c-wrapper.h"

struct signalsmith_stretch {
    signalsmith::stretch::SignalsmithStretch stretch;
};

signalsmith_stretch *signalsmith_stretch_create() {
    return new signalsmith_stretch();
}

signalsmith_stretch *signalsmith_stretch_create_with_seed(long seed) {
    return new signalsmith_stretch{signalsmith::stretch::SignalsmithStretch(seed)};
}

void signalsmith_stretch_destroy(signalsmith_stretch *stretch) {
    delete stretch;
}

void signalsmith_stretch_preset_default(signalsmith_stretch *stretch, int nChannels, float sampleRate) {
    stretch->stretch.presetDefault(nChannels, sampleRate);
}
void signalsmith_stretch_preset_cheaper(signalsmith_stretch *stretch, int nChannels, float sampleRate) {
    stretch->stretch.presetCheaper(nChannels, sampleRate);
}

void signalsmith_stretch_configure(signalsmith_stretch *stretch, int nChannels, int blockSamples, int intervalSamples) {
    stretch->stretch.configure(nChannels, blockSamples, intervalSamples);
}

void signalsmith_stretch_reset(signalsmith_stretch *stretch) {
    stretch->stretch.reset();
}

int signalsmith_stretch_block_samples(const signalsmith_stretch *stretch) {
    return stretch->stretch.blockSamples();
}

int signalsmith_stretch_interval_samples(const signalsmith_stretch *stretch) {
    return stretch->stretch.intervalSamples();
}

int signalsmith_stretch_input_latency(const signalsmith_stretch *stretch) {
    return stretch->stretch.inputLatency();
}

int signalsmith_stretch_output_latency(const signalsmith_stretch *stretch) {
    return stretch->stretch.outputLatency();
}

void signalsmith_stretch_set_transpose_factor(signalsmith_stretch *stretch, float multiplier, float tonalityLimit) {
    stretch->stretch.setTransposeFactor(multiplier, tonalityLimit);
}

void signalsmith_stretch_set_transpose_semitones(signalsmith_stretch *stretch, float semitones, float tonalityLimit) {
    stretch->stretch.setTransposeSemitones(semitones, tonalityLimit);
}

typedef float (*signalsmith_stretch_freq_map_func_t)(float input);

void signalsmith_stretch_set_freq_map(signalsmith_stretch *stretch, signalsmith_stretch_freq_map_func_t inputToOutput) {
    stretch->stretch.setFreqMap([inputToOutput](float input) {
        return inputToOutput(input);
    });
}

void signalsmith_stretch_process(
    signalsmith_stretch *stretch,
    float *inputs,
    int inputSamples,
    float *outputs,
    int outputSamples) {
    stretch->stretch.process(inputs, inputSamples, outputs, outputSamples);
}

void signalsmith_stretch_flush(signalsmith_stretch *stretch, float *outputs, int outputSamples) {
    stretch->stretch.flush(outputs, outputSamples);
}

void signalsmith_stretch_seek(
    signalsmith_stretch *stretch,
    float *inputs,
    int inputSamples,
    float playbackRate) {
    stretch->stretch.seek(inputs, inputSamples, playbackRate);
}