/* 
 * Open Source Movement Analysis Library
 * Copyright (C) 2016, Moveck Solution Inc., all rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 
 *     * Redistributions of source code must retain the above
 *       copyright notice, this list of conditions and the following
 *       disclaimer.
 *     * Redistributions in binary form must reproduce the above
 *       copyright notice, this list of conditions and the following
 *       disclaimer in the documentation and/or other materials
 *       provided with the distribution.
 *     * Neither the name(s) of the copyright holders nor the names
 *       of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written
 *       permission.
 *  
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
 
#ifndef __openma_body_utils_h
#define __openma_body_utils_h

#include "openma/body_export.h"
#include "openma/base/macros.h" // _OPENMA_NOEXCEPT
#include "openma/math.h"

#include <unordered_map>
#include <string>

namespace ma
{
  class Trial;
};

namespace ma
{
namespace body
{
  class Point;
  class ReferenceFrame;
  class InertialParameters;
  class LandmarksTranslator;
  class Segment;
  class SkeletonHelper;
  
  OPENMA_BODY_EXPORT std::unordered_map<std::string,math::Map<math::Vector>> extract_landmark_positions(SkeletonHelper* helper, Trial* trial, double* rate = nullptr, double* start = nullptr, bool* ok = nullptr) _OPENMA_NOEXCEPT;
  OPENMA_BODY_EXPORT std::unordered_map<std::string,math::Map<math::Vector>> extract_landmark_positions(LandmarksTranslator* lt, const std::vector<TimeSequence*>& tss, double* rate = nullptr, double* start = nullptr, bool* ok = nullptr) _OPENMA_NOEXCEPT;
  
  OPENMA_BODY_EXPORT TimeSequence* average_marker(const TimeSequence* marker, Node* parent = nullptr);
  
  OPENMA_BODY_EXPORT math::Pose transform_relative_frame(const ReferenceFrame* relframe, const Segment* seg, const math::Pose& pose) _OPENMA_NOEXCEPT;
  OPENMA_BODY_EXPORT math::Position transform_relative_point(const Point* relpoint, const Segment* seg, const math::Pose& pose) _OPENMA_NOEXCEPT;
  OPENMA_BODY_EXPORT math::Array<9> transform_relative_inertia(InertialParameters* relbsip, const Segment* seg, const math::Pose& pose) _OPENMA_NOEXCEPT;
  OPENMA_BODY_EXPORT math::Position transform_relative_com(InertialParameters* relbsip, const Segment* seg, const math::Pose& pose) _OPENMA_NOEXCEPT;
};
};

#endif // __openma_body_utils_h