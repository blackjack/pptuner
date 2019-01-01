#include <iostream>

#include "audio/PulseAudio.hpp"

int main() {
  PulseAudio audio;
  while (true) {
  audio.run();
  }
}
