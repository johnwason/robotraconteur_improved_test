/** 
 * @file robotraconteur_test_old_seqgen.h
 * 
 * @author John Wason, PhD
 * 
 * @copyright Copyright 2011-2022 Wason Technology, LLC
 *
 * @par License
 * Software License Agreement (Apache License)
 * @par
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * @par
 * http://www.apache.org/licenses/LICENSE-2.0
 * @par
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#ifdef _WIN32
#ifdef ROBOTRACONTEUR_TEST_OLD_SEQGEN_EXPORTS
#define ROBOTRACONTEUR_TEST_OLD_SEQGEN_API __declspec(dllexport)
#elif ROBOTRACONTEUR_TEST_OLD_SEQGEN_IMPORTS
#define ROBOTRACONTEUR_TEST_OLD_SEQGEN_API __declspec(dllimport)
#else
#define ROBOTRACONTEUR_TEST_OLD_SEQGEN_API
#endif
#else
#define ROBOTRACONTEUR_TEST_OLD_SEQGEN_API
#endif

#include <stdlib.h>
#include <stdint.h>

/**
 * @brief Array data sequences from old testing that doesn't use sequence generators
 * 
 */

#ifdef __cplusplus
extern "C" {
#endif

ROBOTRACONTEUR_TEST_OLD_SEQGEN_API int32_t robotraconteur_test_old_seqgen_len(const char* name, size_t* len);

ROBOTRACONTEUR_TEST_OLD_SEQGEN_API int32_t robotraconteur_test_old_seqgen_type(const char* name, uint16_t* rr_type);

ROBOTRACONTEUR_TEST_OLD_SEQGEN_API int32_t robotraconteur_test_old_seqgen_int8_array(const char* name, int8_t* data, size_t len);
ROBOTRACONTEUR_TEST_OLD_SEQGEN_API int32_t robotraconteur_test_old_seqgen_uint8_array(const char* name, uint8_t* data, size_t len);

ROBOTRACONTEUR_TEST_OLD_SEQGEN_API int32_t robotraconteur_test_old_seqgen_int16_array(const char* name, int16_t* data, size_t len);
ROBOTRACONTEUR_TEST_OLD_SEQGEN_API int32_t robotraconteur_test_old_seqgen_uint16_array(const char* name, uint16_t* data, size_t len);

ROBOTRACONTEUR_TEST_OLD_SEQGEN_API int32_t robotraconteur_test_old_seqgen_int32_array(const char* name, int32_t* data, size_t len);
ROBOTRACONTEUR_TEST_OLD_SEQGEN_API int32_t robotraconteur_test_old_seqgen_uint32_array(const char* name, uint32_t* data, size_t len);

ROBOTRACONTEUR_TEST_OLD_SEQGEN_API int32_t robotraconteur_test_old_seqgen_int64_array(const char* name, int64_t* data, size_t len);
ROBOTRACONTEUR_TEST_OLD_SEQGEN_API int32_t robotraconteur_test_old_seqgen_uint64_array(const char* name, uint64_t* data, size_t len);

ROBOTRACONTEUR_TEST_OLD_SEQGEN_API int32_t robotraconteur_test_old_seqgen_float_array(const char* name, float* data, size_t len);
ROBOTRACONTEUR_TEST_OLD_SEQGEN_API int32_t robotraconteur_test_old_seqgen_double_array(const char* name, double* data, size_t len);

ROBOTRACONTEUR_TEST_OLD_SEQGEN_API int32_t robotraconteur_test_old_seqgen_bool_array(const char* name, uint8_t* data, size_t len);

ROBOTRACONTEUR_TEST_OLD_SEQGEN_API int32_t robotraconteur_test_old_seqgen_cfloat_array(const char* name, float* data, size_t len);
ROBOTRACONTEUR_TEST_OLD_SEQGEN_API int32_t robotraconteur_test_old_seqgen_cdouble_array(const char* name, double* data, size_t len);


#ifdef __cplusplus
}
#endif
