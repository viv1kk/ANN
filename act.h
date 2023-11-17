#ifndef __ACTIVATION_FUNC
#define __ACTIVATION_FUNC
#include "def.h"
#include "misc.h"

namespace act{
    vec<vec<ld>> relu(const vec<vec<ld>>&);
    vec<vec<ld>> softmax(const vec<vec<ld>>& );
    vec<vec<ld>> d_relu(const vec<vec<ld>>& );
}

namespace mod{
    vec<ld> get_predictions(vec<vec<ld>>);
    ld get_accuracy(vec<ld>, vec<ld>);
}

#endif
