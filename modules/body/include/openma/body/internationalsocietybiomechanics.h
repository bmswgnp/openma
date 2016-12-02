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

#ifndef __openma_body_internationalsocietybiomechanics_h
#define __openma_body_internationalsocietybiomechanics_h

#include "openma/body_export.h"
#include "openma/body/skeletonhelper.h"
#include "openma/base/macros.h" // _OPENMA_NOEXCEPT

namespace ma
{
  enum class Sex : char;
  
namespace body
{
  class InternationalSocietyBiomechanicsPrivate;
  
  class OPENMA_BODY_EXPORT InternationalSocietyBiomechanics : public SkeletonHelper
  {
    OPENMA_DECLARE_PIMPL_ACCESSOR(InternationalSocietyBiomechanics)
    OPENMA_DECLARE_NODEID(InternationalSocietyBiomechanics, SkeletonHelper)
    
  public:
    InternationalSocietyBiomechanics(int region, int side, Node* parent = nullptr);
    
    Sex sex() const _OPENMA_NOEXCEPT;
    void setSex(Sex value) _OPENMA_NOEXCEPT;
    
    virtual bool calibrate(Node* trials, Subject* subject) override;
    virtual LandmarksTranslator* defaultLandmarksTranslator() override;
    virtual PoseEstimator* defaultPoseEstimator() override;
    virtual InertialParametersEstimator* defaultInertialParametersEstimator() override;
    virtual ExternalWrenchAssigner* defaultExternalWrenchAssigner() override;
    virtual InverseDynamicProcessor* defaultInverseDynamicProcessor() override;
    
    virtual InternationalSocietyBiomechanics* clone(Node* parent = nullptr) const override;
    virtual void copy(const Node* source) _OPENMA_NOEXCEPT override;
    
  protected:
    virtual bool setupModel(Model* model) const override;
    virtual bool reconstructModel(Model* model, Trial* trial) override;
  };
};
};

OPENMA_EXPORT_STATIC_TYPEID(ma::body::InternationalSocietyBiomechanics, OPENMA_BODY_EXPORT);

#endif // __openma_body_internationalsocietybiomechanics_h