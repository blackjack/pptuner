#pragma once

#include "Audio.hpp"

#include <array>

struct pa_simple;

struct PulseAudioError : public AudioError
{
  using AudioError::AudioError;
};

class PulseAudio
{
public:
  PulseAudio(
    const char* deviceName = nullptr,
    uint32_t sampleRate = 44100,
    const char* sinkName = nullptr);

  ~PulseAudio();

  void run();

private:
  pa_simple* pulse = nullptr;

  std::array<float, 1000> buffer;
};
