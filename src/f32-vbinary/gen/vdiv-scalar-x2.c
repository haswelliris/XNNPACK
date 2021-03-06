// Auto-generated file. Do not edit!
//   Template: src/f32-vbinary/vop-scalar.c.in
//   Generator: tools/xngen
//
// Copyright 2019 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>

#include <xnnpack/common.h>
#include <xnnpack/math.h>
#include <xnnpack/vbinary.h>


void xnn_f32_vdiv_ukernel__scalar_x2(
    size_t n,
    const float* a,
    const float* b,
    float* y,
    const union xnn_f32_default_params params[restrict XNN_MIN_ELEMENTS(1)])
{
  assert(n != 0);
  assert(n % sizeof(float) == 0);
  assert(a != NULL);
  assert(b != NULL);
  assert(y != NULL);


  for (; n >= 2 * sizeof(float); n -= 2 * sizeof(float)) {
    const float va0 = a[0];
    const float va1 = a[1];
    a += 2;

    const float vb0 = b[0];
    const float vb1 = b[1];
    b += 2;

    float vy0 = va0 / vb0;
    float vy1 = va1 / vb1;



    y[0] = vy0;
    y[1] = vy1;
    y += 2;
  }
  if XNN_UNLIKELY(n != 0) {
    const float va = *a;
    const float vb = *b;
    float vy = va / vb;
    *y = vy;
  }
}
