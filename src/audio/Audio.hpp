#pragma once

#include <stdexcept>

struct AudioError : std::runtime_error
{
  using std::runtime_error::runtime_error;
};
