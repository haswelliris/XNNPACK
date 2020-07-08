// Auto-generated file. Do not edit!
//   Template: src/f32-prelu/neon.c.in
//   Generator: tools/xngen
//
// Copyright 2019 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>

#include <arm_neon.h>

#include <xnnpack/math.h>
#include <xnnpack/prelu.h>


void xnn_f32_prelu_ukernel__neon_4x4(
    size_t rows,
    size_t channels,
    const float*restrict input,
    size_t input_stride,
    const float*restrict weights,
    float*restrict output,
    size_t output_stride) XNN_DISABLE_TSAN
{
  assert(rows != 0);
  assert(channels != 0);
  assert(channels % sizeof(float) == 0);

  const float* i0 = input;
  float* o0 = output;
  const float* i1 = (const float*) ((uintptr_t) i0 + input_stride);
  float* o1 = (float*) ((uintptr_t) o0 + output_stride);
  if XNN_UNPREDICTABLE(rows < 2) {
    i1 = i0;
    o1 = o0;
  }
  const float* i2 = (const float*) ((uintptr_t) i1 + input_stride);
  float* o2 = (float*) ((uintptr_t) o1 + output_stride);
  if XNN_UNPREDICTABLE(rows <= 2) {
    i2 = i1;
    o2 = o1;
  }
  const float* i3 = (const float*) ((uintptr_t) i2 + input_stride);
  float* o3 = (float*) ((uintptr_t) o2 + output_stride);
  if XNN_UNPREDICTABLE(rows < 4) {
    i3 = i2;
    o3 = o2;
  }

  const size_t input_increment = input_stride * 4 - channels;
  const size_t output_increment = output_stride * 4 - channels;

  do {
    const float* w = weights;
    size_t c = channels;
    for (; c >= 4 * sizeof(float); c -= 4 * sizeof(float)) {
      const float32x4_t vw0123 = vld1q_f32(w); w += 4;

      const float32x4_t vi0x0123 = vld1q_f32(i0); i0 += 4;
      const float32x4_t vi1x0123 = vld1q_f32(i1); i1 += 4;
      const float32x4_t vi2x0123 = vld1q_f32(i2); i2 += 4;
      const float32x4_t vi3x0123 = vld1q_f32(i3); i3 += 4;

      float32x4_t vacc0x0123 = vmulq_f32(vi0x0123, vw0123);
      const uint32x4_t vm0x0123 = vcltq_s32(vreinterpretq_s32_f32(vi0x0123), vmovq_n_s32(0));
      float32x4_t vacc1x0123 = vmulq_f32(vi1x0123, vw0123);
      const uint32x4_t vm1x0123 = vcltq_s32(vreinterpretq_s32_f32(vi1x0123), vmovq_n_s32(0));
      float32x4_t vacc2x0123 = vmulq_f32(vi2x0123, vw0123);
      const uint32x4_t vm2x0123 = vcltq_s32(vreinterpretq_s32_f32(vi2x0123), vmovq_n_s32(0));
      float32x4_t vacc3x0123 = vmulq_f32(vi3x0123, vw0123);
      const uint32x4_t vm3x0123 = vcltq_s32(vreinterpretq_s32_f32(vi3x0123), vmovq_n_s32(0));

      vacc0x0123 = vbslq_f32(vm0x0123, vacc0x0123, vi0x0123);
      vacc1x0123 = vbslq_f32(vm1x0123, vacc1x0123, vi1x0123);
      vacc2x0123 = vbslq_f32(vm2x0123, vacc2x0123, vi2x0123);
      vacc3x0123 = vbslq_f32(vm3x0123, vacc3x0123, vi3x0123);

      vst1q_f32(o0, vacc0x0123); o0 += 4;
      vst1q_f32(o1, vacc1x0123); o1 += 4;
      vst1q_f32(o2, vacc2x0123); o2 += 4;
      vst1q_f32(o3, vacc3x0123); o3 += 4;
    }
    if XNN_UNLIKELY(c != 0) {
      const float32x4_t vw0123 = vld1q_f32(w); w += 4;

      const float32x4_t vi0x0123 = vld1q_f32(i0);
      i0 = (const float*) ((uintptr_t) i0 + c);
      const float32x4_t vi1x0123 = vld1q_f32(i1);
      i1 = (const float*) ((uintptr_t) i1 + c);
      const float32x4_t vi2x0123 = vld1q_f32(i2);
      i2 = (const float*) ((uintptr_t) i2 + c);
      const float32x4_t vi3x0123 = vld1q_f32(i3);
      i3 = (const float*) ((uintptr_t) i3 + c);

      float32x4_t vacc0x0123 = vmulq_f32(vi0x0123, vw0123);
      const uint32x4_t vm0x0123 = vcltq_s32(vreinterpretq_s32_f32(vi0x0123), vmovq_n_s32(0));
      float32x4_t vacc1x0123 = vmulq_f32(vi1x0123, vw0123);
      const uint32x4_t vm1x0123 = vcltq_s32(vreinterpretq_s32_f32(vi1x0123), vmovq_n_s32(0));
      float32x4_t vacc2x0123 = vmulq_f32(vi2x0123, vw0123);
      const uint32x4_t vm2x0123 = vcltq_s32(vreinterpretq_s32_f32(vi2x0123), vmovq_n_s32(0));
      float32x4_t vacc3x0123 = vmulq_f32(vi3x0123, vw0123);
      const uint32x4_t vm3x0123 = vcltq_s32(vreinterpretq_s32_f32(vi3x0123), vmovq_n_s32(0));

      vacc0x0123 = vbslq_f32(vm0x0123, vacc0x0123, vi0x0123);
      vacc1x0123 = vbslq_f32(vm1x0123, vacc1x0123, vi1x0123);
      vacc2x0123 = vbslq_f32(vm2x0123, vacc2x0123, vi2x0123);
      vacc3x0123 = vbslq_f32(vm3x0123, vacc3x0123, vi3x0123);

      float32x2_t vacc0x01 = vget_low_f32(vacc0x0123);
      float32x2_t vacc1x01 = vget_low_f32(vacc1x0123);
      float32x2_t vacc2x01 = vget_low_f32(vacc2x0123);
      float32x2_t vacc3x01 = vget_low_f32(vacc3x0123);
      if (c & (2 * sizeof(float))) {
        vst1_f32(o0, vacc0x01); o0 += 2;
        vst1_f32(o1, vacc1x01); o1 += 2;
        vst1_f32(o2, vacc2x01); o2 += 2;
        vst1_f32(o3, vacc3x01); o3 += 2;

        vacc0x01 = vget_high_f32(vacc0x0123);
        vacc1x01 = vget_high_f32(vacc1x0123);
        vacc2x01 = vget_high_f32(vacc2x0123);
        vacc3x01 = vget_high_f32(vacc3x0123);
      }
      if (c & (1 * sizeof(float))) {
        vst1_lane_f32(o0, vacc0x01, 0); o0 += 1;
        vst1_lane_f32(o1, vacc1x01, 0); o1 += 1;
        vst1_lane_f32(o2, vacc2x01, 0); o2 += 1;
        vst1_lane_f32(o3, vacc3x01, 0); o3 += 1;
      }
    }
    i0 = (const float*) ((uintptr_t) i0 + input_increment);
    o0 = (float*) ((uintptr_t) o0 + output_increment);
    i1 = (const float*) ((uintptr_t) i1 + input_increment);
    o1 = (float*) ((uintptr_t) o1 + output_increment);
    if XNN_UNPREDICTABLE(rows < 6) {
      i1 = i0;
      o1 = o0;
    }
    i2 = (const float*) ((uintptr_t) i2 + input_increment);
    o2 = (float*) ((uintptr_t) o2 + output_increment);
    if XNN_UNPREDICTABLE(rows <= 6) {
      i2 = i1;
      o2 = o1;
    }
    i3 = (const float*) ((uintptr_t) i3 + input_increment);
    o3 = (float*) ((uintptr_t) o3 + output_increment);
    if XNN_UNPREDICTABLE(rows < 8) {
      i3 = i2;
      o3 = o2;
    }
    rows = doz(rows, 4);
  } while (rows != 0);
}
