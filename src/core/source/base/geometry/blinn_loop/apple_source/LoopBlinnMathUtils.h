/*
 * Copyright (C) 2010 Google Inc. All rights reserved.
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

#ifndef LoopBlinnMathUtils_h
#define LoopBlinnMathUtils_h

#include <math.h>
#include "include/core/SkPoint.h"
#include "include/core/SkPoint3.h"

namespace WebCore {

// Use a namespace for these so we can easily import them.
namespace LoopBlinnMathUtils {

float roundToZero(float val);
bool approxEqual(const SkPoint& v0, const SkPoint& v1);
bool approxEqual(const SkPoint3& v0, const SkPoint3& v1);
bool approxEqual(float f0, float f1);

// Determines whether the line segment between (p1, q1) intersects
// that between (p2, q2).
bool linesIntersect(const SkPoint& p1,
                    const SkPoint& q1,
                    const SkPoint& p2,
                    const SkPoint& q2);

// Determines whether "point" is inside the 2D triangle defined by
// vertices a, b, and c. This test defines that points exactly on an
// edge are not considered to be inside the triangle.
bool pointInTriangle(const SkPoint& point,
                     const SkPoint& a,
                     const SkPoint& b,
                     const SkPoint& c);

// Determines whether the triangles defined by the points (a1, b1, c1)
// and (a2, b2, c2) overlap. The definition of this function is that
// if the two triangles only share an adjacent edge or vertex, they
// are not considered to overlap.
bool trianglesOverlap(const SkPoint& a1,
                      const SkPoint& b1,
                      const SkPoint& c1,
                      const SkPoint& a2,
                      const SkPoint& b2,
                      const SkPoint& c2);

// Given a src cubic bezier, chops it at the specified t value,
// where 0 < t < 1, and returns the two new cubics in dst[0..3]
// and dst[3..6].
void chopCubicAt(const SkPoint src[4], SkPoint dst[7], float t);

// "X-Ray" queries. An XRay is a half-line originating at the given
// point and extending to x=+infinity.
typedef SkPoint XRay;

// Given an arbitrary cubic bezier, return the number of times an XRay
// crosses the cubic. Valid return values are [0..3].
//
// By definition the cubic is open at the starting point; in other
// words, if pt.fY is equivalent to cubic[0].fY, and pt.fX is to the
// left of the curve, the line is not considered to cross the curve,
// but if it is equal to cubic[3].fY then it is considered to
// cross.
//
// Outgoing "ambiguous" argument indicates whether the answer is ambiguous
// because the query occurred exactly at one of the endpoints' y
// coordinates or at a tangent point, indicating that another query y
// coordinate is preferred for robustness.
int numXRayCrossingsForCubic(const XRay& xRay,
                             const SkPoint cubic[4],
                             bool& ambiguous);

// Given a line segment from lineEndpoints[0] to lineEndpoints[1], and an
// XRay, returns true if they intersect. Outgoing "ambiguous" argument
// indicates whether the answer is ambiguous because the query occurred
// exactly at one of the endpoints' y coordinates, indicating that another
// query y coordinate is preferred for robustness.
bool xRayCrossesLine(const XRay& xRay,
                     const SkPoint lineEndpoints[2],
                     bool& ambiguous);


bool isConvex(const SkPoint* vertices, int nVertices);

} // namespace LoopBlinnMathUtils

} // namespace WebCore

#endif // LoopBlinnMathUtils_h
