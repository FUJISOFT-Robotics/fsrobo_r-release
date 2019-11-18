/*********************************************************************
* FSRobo-R Package BSDL
* ---------
* Copyright (C) 2019 FUJISOFT. All rights reserved.
* 
* Redistribution and use in source and binary forms, with or without modification,
* are permitted provided that the following conditions are met:
* 1. Redistributions of source code must retain the above copyright notice,
* this list of conditions and the following disclaimer.
* 2. Redistributions in binary form must reproduce the above copyright notice,
* this list of conditions and the following disclaimer in the documentation and/or
* other materials provided with the distribution.
* 3. Neither the name of the copyright holder nor the names of its contributors
* may be used to endorse or promote products derived from this software without
* specific prior written permission.
* 
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
* ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
* IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
* INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
* ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
* OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*********************************************************************/

#include <string>
#include "fsrobo_r_driver/simple_message/sys_stat.h"
#include "fsrobo_r_driver/simple_message/sys_stat_reply.h"
#include "simple_message/shared_types.h"
#include "simple_message/log_wrapper.h"

using industrial::shared_types::shared_int;
namespace sys_stat_reply = fsrobo_r_driver::simple_message::sys_stat_reply;

namespace fsrobo_r_driver
{
namespace simple_message
{
namespace sys_stat_reply
{

SysStatReply::SysStatReply(void)
{
  this->init();
}

SysStatReply::~SysStatReply(void)
{
}

void SysStatReply::init()
{
  this->init(SysStatReplyType::MOTION_REQUEST, 0);
}

void SysStatReply::init(SysStatReplyType stat_type, shared_int result)
{
  this->setStatType(stat_type);
  this->setResult(result);
}

void SysStatReply::copyFrom(SysStatReply &src)
{
  this->setStatType(src.getStatType());
  this->setResult(src.getResult());
}

bool SysStatReply::operator==(SysStatReply &rhs)
{
  bool rslt = this->stat_type_ == rhs.stat_type_ && this->result_ == rhs.result_;

  return rslt;
}

bool SysStatReply::load(industrial::byte_array::ByteArray *buffer)
{
  LOG_COMM("Executing SysStatReply load");

  if (!buffer->load(this->result_))
  {
    LOG_ERROR("Failed to load SysStatReply result_code");
    return false;
  }

  LOG_COMM("SysStatReply data successfully loaded");
  return true;
}

bool SysStatReply::unload(industrial::byte_array::ByteArray *buffer)
{
  LOG_COMM("Executing SysSstatReply unload");

  if (!buffer->unload(this->result_))
  {
    LOG_ERROR("Failed to unload SysStatReply result_code");
    return false;
  }

  LOG_COMM("SysStatReply data successfully unloaded");
  return true;
}

}
}
}
