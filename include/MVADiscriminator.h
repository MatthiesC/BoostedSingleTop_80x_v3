#pragma once

#include "TMVA/Reader.h"

class MVADiscriminator
{
 public:
  MVADiscriminator(const std::string & path_weightfile);
  ~MVADiscriminator();
  float eval(int var0, float var1, float var2, float var3, float var4, float var5, float var6, float var7, float var8, float var9, float var10, float var11);
  
 private:
  TMVA::Reader *reader_;
  int intvars_[1];
  float floatvars_[11];
};
