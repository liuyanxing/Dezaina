/*
 * Copyright (C) 2011 Google Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1.  Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 * 2.  Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE AND ITS CONTRIBUTORS "AS IS" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL APPLE OR ITS CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "LoopBlinnPathCache.h"

namespace WebCore {

LoopBlinnPathCache::LoopBlinnPathCache()
{
}

LoopBlinnPathCache::~LoopBlinnPathCache()
{
}

void LoopBlinnPathCache::addVertex(float x, float y,
                                   float k, float l, float m)
{
    m_vertices.push_back(x);
    m_vertices.push_back(y);
    m_texcoords.push_back(k);
    m_texcoords.push_back(l);
    m_texcoords.push_back(m);
}

void LoopBlinnPathCache::clear()
{
    m_vertices.clear();
    m_texcoords.clear();
    m_interiorVertices.clear();
#ifdef LOOP_BLINN_PATH_CACHE_DEBUG_INTERIOR_EDGES
    m_interiorEdgeVertices.clear();
#endif // LOOP_BLINN_PATH_CACHE_DEBUG_INTERIOR_EDGES
}

void LoopBlinnPathCache::addInteriorVertex(float x, float y)
{
    m_interiorVertices.push_back(x);
    m_interiorVertices.push_back(y);
}

#ifdef LOOP_BLINN_PATH_CACHE_DEBUG_INTERIOR_EDGES
unsigned LoopBlinnPathCache::numberOfInteriorEdgeVertices() const
{
    return m_interiorEdgeVertices.size() / 2;
}

const float* LoopBlinnPathCache::interiorEdgeVertices() const
{
    if (!numberOfInteriorEdgeVertices())
        return 0;
    return m_interiorEdgeVertices.data();
}

void LoopBlinnPathCache::addInteriorEdgeVertex(float x, float y)
{
    m_interiorEdgeVertices.append(x);
    m_interiorEdgeVertices.append(y);
}
#endif // LOOP_BLINN_PATH_CACHE_DEBUG_INTERIOR_EDGES

} // namespace WebCore