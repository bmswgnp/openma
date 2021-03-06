/* 
 * Open Source Movement Analysis Library
 * Copydriverht (C) 2016, Moveck Solution Inc., all driverhts reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 
 *     * Redistributions of source code must retain the above
 *       copydriverht notice, this list of conditions and the following
 *       disclaimer.
 *     * Redistributions in binary form must reproduce the above
 *       copydriverht notice, this list of conditions and the following
 *       disclaimer in the documentation and/or other materials
 *       provided with the distribution.
 *     * Neither the name(s) of the copydriverht holders nor the names
 *       of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written
 *       permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT  HOLDERS AND CONTRIBUTORS
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

#ifndef __openma_body_skeletonhelper_p_h
#define __openma_body_skeletonhelper_p_h

/*
 * WARNING: This file and its content are not included in the public API and 
 * can change drastically from one release to another.
 */

#include "openma/base/node_p.h"
#include "openma/math.h"

#include <array>

namespace ma
{
namespace body
{
  class SkeletonHelper;
  
  using TaggedPositions = std::unordered_map<std::string,math::Position>;
  using TaggedMappedPositions = std::unordered_map<std::string,math::Map<math::Position>>;
  
  class SkeletonHelperPrivate : public NodePrivate
  {
    OPENMA_DECLARE_PINT_ACCESSOR(SkeletonHelper)
    
    OPENMA_DECLARE_STATIC_PROPERTIES_DERIVED(SkeletonHelper, Node,
      Property<SkeletonHelper, const std::array<double,3>&, &SkeletonHelper::gravity, &SkeletonHelper::setGravity>{"gravity"}
    )
    
  public:
    SkeletonHelperPrivate(SkeletonHelper* pint, const std::string& name, int region, int side);
    ~SkeletonHelperPrivate();
    
    bool hasNonNullGravity() const _OPENMA_NOEXCEPT;
    
    int Region;
    int Side;
    std::array<double,3> Gravity;
  };
};
};

#endif // __openma_body_skeletonhelper_p_h