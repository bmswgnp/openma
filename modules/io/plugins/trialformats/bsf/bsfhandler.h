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

#ifndef __openma_io_bsfandler_h
#define __openma_io_bsfandler_h

#include "openma/io/handler.h"
#include "openma/base/macros.h" // _OPENMA_CONSTEXPR, _OPENMA_NOEXCEPT

namespace ma
{
namespace io
{
  class BSFHandlerPrivate;
  
  class BSFHandler : public Handler
  {
  public:
    BSFHandler();
    ~BSFHandler() _OPENMA_NOEXCEPT;
    
    BSFHandler(const BSFHandler& ) = delete;
    BSFHandler(BSFHandler&& ) _OPENMA_NOEXCEPT = delete;
    BSFHandler& operator=(const BSFHandler& ) = delete;
    BSFHandler& operator=(const BSFHandler&& ) _OPENMA_NOEXCEPT = delete;
    
    static Signature verifySignature(const Device* const device) _OPENMA_NOEXCEPT;

  protected:
    virtual Signature verifySignature() const _OPENMA_NOEXCEPT final;
    virtual void readDevice(ma::Node* output) final;
  };
};
};

#endif // __openma_io_bsfandler_h
