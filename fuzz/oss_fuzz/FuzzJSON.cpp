/*
 * Copyright 2018 Google, LLC
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "include/core/SkStream.h"
#include "src/utils/SkJSON.h"

void FuzzJSON(const uint8_t *data, size_t size) {
    skjson::DOM dom(reinterpret_cast<const char*>(data), size);
    SkDynamicMemoryWStream wstream;
    dom.write(&wstream);
}

// TODO(kjlubick): remove IS_FUZZING... after https://crrev.com/c/2410304 lands
#if defined(SK_BUILD_FOR_LIBFUZZER) || defined(IS_FUZZING_WITH_LIBFUZZER)
extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
    FuzzJSON(data, size);
    return 0;
}
#endif
