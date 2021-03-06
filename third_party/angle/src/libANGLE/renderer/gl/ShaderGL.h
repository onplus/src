//
// Copyright 2015 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//

// ShaderGL.h: Defines the class interface for ShaderGL.

#ifndef LIBANGLE_RENDERER_GL_SHADERGL_H_
#define LIBANGLE_RENDERER_GL_SHADERGL_H_

#include "libANGLE/renderer/ShaderImpl.h"

namespace rx
{
class FunctionsGL;
struct WorkaroundsGL;
enum class MultiviewImplementationTypeGL;

class ShaderGL : public ShaderImpl
{
  public:
    ShaderGL(const gl::ShaderState &data,
             GLuint shaderID,
             MultiviewImplementationTypeGL multiviewImplementationType);
    ~ShaderGL() override;

    void destroy(const gl::Context *context) override;

    // ShaderImpl implementation
    ShCompileOptions prepareSourceAndReturnOptions(const gl::Context *context,
                                                   std::stringstream *sourceStream,
                                                   std::string *sourcePath) override;
    bool postTranslateCompile(const gl::Context *context,
                              gl::Compiler *compiler,
                              std::string *infoLog) override;
    std::string getDebugInfo(const gl::Context *context) const override;

    GLuint getShaderID() const;

  private:
    GLuint mShaderID;
    MultiviewImplementationTypeGL mMultiviewImplementationType;
};

}

#endif // LIBANGLE_RENDERER_GL_SHADERGL_H_
