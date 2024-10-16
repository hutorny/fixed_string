#pragma once

#if __has_include(<gsl/gsl-lite.hpp>)
#include <gsl/gsl-lite.hpp>
#else
# define  gsl_Expects( x ) static_cast<void>(x)
#endif
