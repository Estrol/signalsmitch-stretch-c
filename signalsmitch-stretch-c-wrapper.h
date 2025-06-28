#ifndef SIGNALSMITH_STRETCH_C_WRAPPER_H
#define SIGNALSMITH_STRETCH_C_WRAPPER_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct signalsmith_stretch signalsmith_stretch;

signalsmith_stretch *signalsmith_stretch_create();
signalsmith_stretch *signalsmith_stretch_create_with_seed(long seed);
void signalsmith_stretch_destroy(signalsmith_stretch *stretch);
void signalsmith_stretch_preset_default(signalsmith_stretch *stretch, int nChannels, float sampleRate);
void signalsmith_stretch_preset_cheaper(signalsmith_stretch *stretch, int nChannels, float sampleRate);
void signalsmith_stretch_configure(signalsmith_stretch *stretch, int nChannels, int blockSamples, int intervalSamples);
void signalsmith_stretch_reset(signalsmith_stretch *stretch);
int signalsmith_stretch_block_samples(const signalsmith_stretch *stretch);
int signalsmith_stretch_interval_samples(const signalsmith_stretch *stretch);
int signalsmith_stretch_input_latency(const signalsmith_stretch *stretch);
int signalsmith_stretch_output_latency(const signalsmith_stretch *stretch);
void signalsmith_stretch_set_transpose_factor(signalsmith_stretch *stretch, float multiplier, float tonalityLimit);
void signalsmith_stretch_set_transpose_semitones(signalsmith_stretch *stretch, float semitones, float tonalityLimit);

typedef float (*signalsmith_stretch_freq_map_func_t)(float input);
void signalsmith_stretch_set_freq_map(signalsmith_stretch *stretch, signalsmith_stretch_freq_map_func_t inputToOutput);

void signalsmith_stretch_process(
    signalsmith_stretch *stretch,
    float *inputs,
    int inputSamples,
    float *outputs,
    int outputSamples);
void signalsmith_stretch_flush(signalsmith_stretch *stretch, float *outputs, int outputSamples);
void signalsmith_stretch_seek(
    signalsmith_stretch *stretch,
    float *inputs,
    int inputSamples,
    float playbackRate);

#ifdef __cplusplus
}
#endif

#endif // SIGNALSMITH_STRETCH_C_WRAPPER_H
