#include "PulseAudio.hpp"

#include "config.hpp"

#include <pulse/simple.h>
#include <pulse/error.h>

#include <iostream>

static constexpr auto NUM_CHANNELS = 1u;

namespace {
std::string getErrorString(int error) {
  return pa_strerror(error);
}
} // namespace

PulseAudio::PulseAudio(
  const char* deviceName,
  uint32_t sampleRate,
  const char* /* sinkName */) {
  pa_sample_spec ss;
  ss.format = PA_SAMPLE_FLOAT32;
  ss.channels = NUM_CHANNELS;
  ss.rate = sampleRate;

  pa_buffer_attr bufferAttributes;
  bufferAttributes.maxlength = -1;
  bufferAttributes.fragsize = sizeof(buffer);

  int error;
  pulse = pa_simple_new(NULL,                 // Use the default server.
                        config::PROJECT_NAME, // Our application's name.
                        PA_STREAM_RECORD,     //
                        deviceName,           //
                        config::PROJECT_NAME, // Description of our stream.
                        &ss,                  // sample format.
                        NULL,                 // Use default channel map
                        &bufferAttributes,    //
                        &error);
}

PulseAudio::~PulseAudio() {
  if (pulse != nullptr) {
    pa_simple_free(pulse);
  }
}

void PulseAudio::run() {
  int error;
  int result = pa_simple_read(pulse, buffer.data(), sizeof(buffer), &error);

  if (result < 0) {
    throw PulseAudioError("Read from audio interface failed: " + getErrorString(error));
  }

  // std::cout << "Received " << buffer.size() << " bytes\n";
  int i = 0;
  for (auto val: buffer)
  {
    if (++i == 10)
    {
      break;
    }
    std::cout << val << ' ';
  }
  std::cout << std::endl;

}
