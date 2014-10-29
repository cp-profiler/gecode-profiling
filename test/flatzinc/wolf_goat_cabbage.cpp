/* -*- mode: C++; c-basic-offset: 2; indent-tabs-mode: nil -*- */
/*
 *  Main authors:
 *     Guido Tack <tack@gecode.org>
 *
 *  Copyright:
 *     Guido Tack, 2014
 *
 *  Last modified:
 *     $Date: 2010-04-08 20:35:31 +1000 (Thu, 08 Apr 2010) $ by $Author: schulte $
 *     $Revision: 10684 $
 *
 *  This file is part of Gecode, the generic constraint
 *  development environment:
 *     http://www.gecode.org
 *
 *  Permission is hereby granted, free of charge, to any person obtaining
 *  a copy of this software and associated documentation files (the
 *  "Software"), to deal in the Software without restriction, including
 *  without limitation the rights to use, copy, modify, merge, publish,
 *  distribute, sublicense, and/or sell copies of the Software, and to
 *  permit persons to whom the Software is furnished to do so, subject to
 *  the following conditions:
 *
 *  The above copyright notice and this permission notice shall be
 *  included in all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 *  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 *  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 *  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 *  LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 *  OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 *  WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#include "test/flatzinc.hh"

namespace Test { namespace FlatZinc {

  namespace {
    /// Helper class to create and register tests
    class Create {
    public:

      /// Perform creation and registration
      Create(void) {
        (void) new FlatZincTest("wolf_goat_cabbage",
"predicate bool_lin_ge(array [int] of int: a, array [int] of var bool: x, var int: c);\n\
predicate bool_lin_gt(array [int] of int: a, array [int] of var bool: x, var int: c);\n\
predicate bool_lin_lt(array [int] of int: a, array [int] of var bool: x, var int: c);\n\
predicate bool_lin_ne(array [int] of int: a, array [int] of var bool: x, var int: c);\n\
var bool: BOOL____00001 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00002 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00003 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00004 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00005 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00006 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00007 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00008 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00009 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00010 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00011 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00012 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00013 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00014 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00015 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00016 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00017 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00018 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00019 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00020 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00021 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00022 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00023 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00024 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00025 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00026 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00027 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00028 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00029 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00030 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00031 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00032 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00033 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00034 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00035 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00036 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00037 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00038 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00039 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00040 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00041 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00042 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00043 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00044 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00045 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00046 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00047 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00048 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00049 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00050 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00051 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00052 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00053 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00054 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00055 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00056 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00057 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00058 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00059 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00060 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00061 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00062 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00063 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00064 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00065 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00066 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00067 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00068 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00069 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00070 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00071 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00072 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00073 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00074 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00075 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00076 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00077 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00078 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00079 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00080 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00081 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00082 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00083 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00084 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00085 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00086 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00087 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00088 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00089 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00090 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00091 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00092 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00093 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00094 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00095 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00096 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00097 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00098 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00099 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00100 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00101 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00102 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00103 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00104 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00105 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00106 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00107 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00108 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00109 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00110 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00111 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00112 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00113 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00114 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00115 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00116 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00117 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00118 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00119 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00120 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00179 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00180 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00181 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00182 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00183 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00184 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00185 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00186 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00187 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00188 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00189 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00190 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00191 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00192 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00193 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00194 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00195 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00196 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00197 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00198 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00199 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00200 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00201 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00202 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00203 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00204 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00205 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00206 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00207 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00208 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00209 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00210 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00211 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00212 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00213 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00214 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00215 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00216 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00217 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00218 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00219 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00220 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00221 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00222 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00223 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00224 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00225 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00226 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00227 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00228 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00229 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00230 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00231 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00232 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00233 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00234 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00235 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00236 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00237 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00238 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00239 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00240 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00241 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00242 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00243 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00244 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00245 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00246 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00247 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00248 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00249 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00250 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00251 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00252 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00253 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00254 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00255 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00256 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00257 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00258 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00259 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00260 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00261 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00262 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00263 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00264 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00265 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00266 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00267 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00268 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00269 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00270 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00271 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00272 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00273 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00274 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00275 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00276 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00277 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00278 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00279 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00280 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00281 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00282 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00283 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00284 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00285 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00286 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00287 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00288 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00289 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00290 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00291 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00292 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00293 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00294 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00295 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00296 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00297 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00298 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00357 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00358 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00359 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00360 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00361 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00362 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00363 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00364 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00365 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00366 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00367 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00368 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00369 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00370 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00371 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00372 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00373 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00374 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00375 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00376 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00377 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00378 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00379 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00380 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00381 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00382 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00383 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00384 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00385 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00386 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00387 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00388 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00389 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00390 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00391 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00392 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00393 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00394 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00395 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00396 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00397 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00398 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00399 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00400 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00401 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00402 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00403 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00404 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00405 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00406 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00407 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00408 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00409 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00410 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00411 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00412 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00413 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00414 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00415 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00416 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00417 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00418 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00419 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00420 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00421 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00422 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00423 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00424 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00425 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00426 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00427 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00428 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00429 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00430 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00431 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00432 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00433 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00434 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00435 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00436 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00437 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00438 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00439 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00440 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00441 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00442 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00443 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00444 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00445 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00446 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00447 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00448 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00449 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00450 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00451 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00452 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00453 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00454 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00455 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00456 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00457 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00458 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00459 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00460 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00461 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00462 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00463 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00464 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00465 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00466 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00467 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00468 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00469 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00470 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00471 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00472 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00473 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00474 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00475 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00476 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00535 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00536 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00537 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00538 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00539 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00540 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00541 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00542 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00543 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00544 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00545 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00546 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00547 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00548 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00549 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00550 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00551 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00552 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00553 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00554 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00555 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00556 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00557 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00558 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00559 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00560 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00561 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00562 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00563 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00564 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00565 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00566 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00567 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00568 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00569 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00570 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00571 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00572 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00573 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00574 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00575 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00576 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00577 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00578 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00579 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00580 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00581 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00582 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00583 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00584 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00585 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00586 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00587 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00588 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00589 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00590 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00591 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00592 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00593 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00594 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00595 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00596 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00597 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00598 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00599 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00600 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00601 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00602 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00603 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00604 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00605 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00606 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00607 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00608 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00609 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00610 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00611 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00612 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00613 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00614 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00615 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00616 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00617 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00618 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00619 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00620 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00621 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00622 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00623 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00624 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00625 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00626 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00627 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00628 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00629 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00630 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00631 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00632 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00633 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00634 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00635 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00636 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00637 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00638 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00639 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00640 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00641 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00642 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00643 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00644 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00645 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00646 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00647 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00648 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00649 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00650 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00651 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00652 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00653 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00654 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00655 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00656 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00657 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00658 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00659 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00660 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00661 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00662 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00663 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00664 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00665 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00666 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00667 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00668 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00669 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00670 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00671 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00672 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00673 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00674 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00675 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00676 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00677 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00678 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00679 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00680 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00681 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00682 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00683 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00684 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00685 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00686 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00687 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00688 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00689 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00690 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00691 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00692 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00693 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00694 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00695 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00696 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00697 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00698 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00699 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00700 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00701 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00702 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00703 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00704 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00705 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00706 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00707 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00708 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00709 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00710 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00711 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00712 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00713 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00714 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00715 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00716 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00717 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00718 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00719 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00720 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00721 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00722 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00723 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00724 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00725 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00726 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00727 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00728 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00729 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00730 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00731 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00732 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00733 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00734 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00735 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00736 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00737 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00738 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00739 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00740 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00741 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00742 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00743 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00744 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00745 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00746 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00747 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00748 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00749 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00750 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00751 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00752 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00753 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00754 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00755 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00756 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00757 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00758 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00759 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00760 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00761 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00762 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00763 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00764 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00765 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00766 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00767 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00768 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00789 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00790 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00791 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00792 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00793 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00794 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00795 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00796 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00797 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00798 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00799 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00800 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00801 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00802 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00803 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00804 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00805 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00806 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00807 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00808 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00809 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00810 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00811 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00812 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00813 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00814 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00815 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00816 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00817 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00818 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00819 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00820 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00821 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00822 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00823 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00824 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00825 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00826 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00827 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00828 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00829 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00830 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00831 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00832 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00833 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00834 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00835 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00836 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00837 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00838 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00839 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00840 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00841 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00842 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00843 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00844 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00845 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00846 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00847 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00848 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00849 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00850 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00851 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00852 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00853 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00854 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00855 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00856 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00857 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00858 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00859 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00860 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00861 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00862 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00863 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00864 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00865 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00866 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00867 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00868 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00869 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00870 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00871 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00872 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00873 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00874 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00875 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00876 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00877 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00878 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00879 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00880 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00881 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00882 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00883 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00884 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00885 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00886 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00887 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00888 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00889 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00890 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00891 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00892 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00893 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00894 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00895 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00896 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00897 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00898 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00899 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00900 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00901 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00902 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00903 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00904 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00905 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00906 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00907 :: is_defined_var :: var_is_introduced;\n\
var bool: BOOL____00908 :: is_defined_var :: var_is_introduced;\n\
array [1..60] of var bool: cabbage :: output_array([1..20, -1..1]);\n\
array [1..60] of var bool: farmer :: output_array([1..20, -1..1]);\n\
array [1..60] of var bool: goat :: output_array([1..20, -1..1]);\n\
array [1..60] of var bool: wolf :: output_array([1..20, -1..1]);\n\
constraint array_bool_and([cabbage[1], cabbage[6]], false);\n\
constraint array_bool_and([cabbage[3], cabbage[4]], false);\n\
constraint array_bool_and([cabbage[4], cabbage[9]], false);\n\
constraint array_bool_and([cabbage[6], cabbage[7]], false);\n\
constraint array_bool_and([cabbage[7], cabbage[12]], false);\n\
constraint array_bool_and([cabbage[9], cabbage[10]], false);\n\
constraint array_bool_and([cabbage[10], cabbage[15]], false);\n\
constraint array_bool_and([cabbage[12], cabbage[13]], false);\n\
constraint array_bool_and([cabbage[13], cabbage[18]], false);\n\
constraint array_bool_and([cabbage[15], cabbage[16]], false);\n\
constraint array_bool_and([cabbage[16], cabbage[21]], false);\n\
constraint array_bool_and([cabbage[18], cabbage[19]], false);\n\
constraint array_bool_and([cabbage[19], cabbage[24]], false);\n\
constraint array_bool_and([cabbage[21], cabbage[22]], false);\n\
constraint array_bool_and([cabbage[22], cabbage[27]], false);\n\
constraint array_bool_and([cabbage[24], cabbage[25]], false);\n\
constraint array_bool_and([cabbage[25], cabbage[30]], false);\n\
constraint array_bool_and([cabbage[27], cabbage[28]], false);\n\
constraint array_bool_and([cabbage[28], cabbage[33]], false);\n\
constraint array_bool_and([cabbage[30], cabbage[31]], false);\n\
constraint array_bool_and([cabbage[31], cabbage[36]], false);\n\
constraint array_bool_and([cabbage[33], cabbage[34]], false);\n\
constraint array_bool_and([cabbage[34], cabbage[39]], false);\n\
constraint array_bool_and([cabbage[36], cabbage[37]], false);\n\
constraint array_bool_and([cabbage[37], cabbage[42]], false);\n\
constraint array_bool_and([cabbage[39], cabbage[40]], false);\n\
constraint array_bool_and([cabbage[40], cabbage[45]], false);\n\
constraint array_bool_and([cabbage[42], cabbage[43]], false);\n\
constraint array_bool_and([cabbage[43], cabbage[48]], false);\n\
constraint array_bool_and([cabbage[45], cabbage[46]], false);\n\
constraint array_bool_and([cabbage[46], cabbage[51]], false);\n\
constraint array_bool_and([cabbage[48], cabbage[49]], false);\n\
constraint array_bool_and([cabbage[49], cabbage[54]], false);\n\
constraint array_bool_and([cabbage[51], cabbage[52]], false);\n\
constraint array_bool_and([cabbage[52], cabbage[57]], false);\n\
constraint array_bool_and([cabbage[54], cabbage[55]], false);\n\
constraint array_bool_and([cabbage[55], cabbage[60]], false);\n\
constraint array_bool_and([cabbage[57], cabbage[58]], false);\n\
constraint array_bool_and([farmer[1], farmer[6]], false);\n\
constraint array_bool_and([farmer[3], farmer[4]], false);\n\
constraint array_bool_and([farmer[4], farmer[9]], false);\n\
constraint array_bool_and([farmer[6], farmer[7]], false);\n\
constraint array_bool_and([farmer[7], farmer[12]], false);\n\
constraint array_bool_and([farmer[9], farmer[10]], false);\n\
constraint array_bool_and([farmer[10], farmer[15]], false);\n\
constraint array_bool_and([farmer[12], farmer[13]], false);\n\
constraint array_bool_and([farmer[13], farmer[18]], false);\n\
constraint array_bool_and([farmer[15], farmer[16]], false);\n\
constraint array_bool_and([farmer[16], farmer[21]], false);\n\
constraint array_bool_and([farmer[18], farmer[19]], false);\n\
constraint array_bool_and([farmer[19], farmer[24]], false);\n\
constraint array_bool_and([farmer[21], farmer[22]], false);\n\
constraint array_bool_and([farmer[22], farmer[27]], false);\n\
constraint array_bool_and([farmer[24], farmer[25]], false);\n\
constraint array_bool_and([farmer[25], farmer[30]], false);\n\
constraint array_bool_and([farmer[27], farmer[28]], false);\n\
constraint array_bool_and([farmer[28], farmer[33]], false);\n\
constraint array_bool_and([farmer[30], farmer[31]], false);\n\
constraint array_bool_and([farmer[31], farmer[36]], false);\n\
constraint array_bool_and([farmer[33], farmer[34]], false);\n\
constraint array_bool_and([farmer[34], farmer[39]], false);\n\
constraint array_bool_and([farmer[36], farmer[37]], false);\n\
constraint array_bool_and([farmer[37], farmer[42]], false);\n\
constraint array_bool_and([farmer[39], farmer[40]], false);\n\
constraint array_bool_and([farmer[40], farmer[45]], false);\n\
constraint array_bool_and([farmer[42], farmer[43]], false);\n\
constraint array_bool_and([farmer[43], farmer[48]], false);\n\
constraint array_bool_and([farmer[45], farmer[46]], false);\n\
constraint array_bool_and([farmer[46], farmer[51]], false);\n\
constraint array_bool_and([farmer[48], farmer[49]], false);\n\
constraint array_bool_and([farmer[49], farmer[54]], false);\n\
constraint array_bool_and([farmer[51], farmer[52]], false);\n\
constraint array_bool_and([farmer[52], farmer[57]], false);\n\
constraint array_bool_and([farmer[54], farmer[55]], false);\n\
constraint array_bool_and([farmer[55], farmer[60]], false);\n\
constraint array_bool_and([farmer[57], farmer[58]], false);\n\
constraint array_bool_and([goat[1], cabbage[1]], BOOL____00790) :: defines_var(BOOL____00790);\n\
constraint array_bool_and([goat[1], goat[6]], false);\n\
constraint array_bool_and([goat[2], cabbage[2]], BOOL____00792) :: defines_var(BOOL____00792);\n\
constraint array_bool_and([goat[3], cabbage[3]], BOOL____00794) :: defines_var(BOOL____00794);\n\
constraint array_bool_and([goat[3], goat[4]], false);\n\
constraint array_bool_and([goat[4], cabbage[4]], BOOL____00796) :: defines_var(BOOL____00796);\n\
constraint array_bool_and([goat[4], goat[9]], false);\n\
constraint array_bool_and([goat[5], cabbage[5]], BOOL____00798) :: defines_var(BOOL____00798);\n\
constraint array_bool_and([goat[6], cabbage[6]], BOOL____00800) :: defines_var(BOOL____00800);\n\
constraint array_bool_and([goat[6], goat[7]], false);\n\
constraint array_bool_and([goat[7], cabbage[7]], BOOL____00802) :: defines_var(BOOL____00802);\n\
constraint array_bool_and([goat[7], goat[12]], false);\n\
constraint array_bool_and([goat[8], cabbage[8]], BOOL____00804) :: defines_var(BOOL____00804);\n\
constraint array_bool_and([goat[9], cabbage[9]], BOOL____00806) :: defines_var(BOOL____00806);\n\
constraint array_bool_and([goat[9], goat[10]], false);\n\
constraint array_bool_and([goat[10], cabbage[10]], BOOL____00808) :: defines_var(BOOL____00808);\n\
constraint array_bool_and([goat[10], goat[15]], false);\n\
constraint array_bool_and([goat[11], cabbage[11]], BOOL____00810) :: defines_var(BOOL____00810);\n\
constraint array_bool_and([goat[12], cabbage[12]], BOOL____00812) :: defines_var(BOOL____00812);\n\
constraint array_bool_and([goat[12], goat[13]], false);\n\
constraint array_bool_and([goat[13], cabbage[13]], BOOL____00814) :: defines_var(BOOL____00814);\n\
constraint array_bool_and([goat[13], goat[18]], false);\n\
constraint array_bool_and([goat[14], cabbage[14]], BOOL____00816) :: defines_var(BOOL____00816);\n\
constraint array_bool_and([goat[15], cabbage[15]], BOOL____00818) :: defines_var(BOOL____00818);\n\
constraint array_bool_and([goat[15], goat[16]], false);\n\
constraint array_bool_and([goat[16], cabbage[16]], BOOL____00820) :: defines_var(BOOL____00820);\n\
constraint array_bool_and([goat[16], goat[21]], false);\n\
constraint array_bool_and([goat[17], cabbage[17]], BOOL____00822) :: defines_var(BOOL____00822);\n\
constraint array_bool_and([goat[18], cabbage[18]], BOOL____00824) :: defines_var(BOOL____00824);\n\
constraint array_bool_and([goat[18], goat[19]], false);\n\
constraint array_bool_and([goat[19], cabbage[19]], BOOL____00826) :: defines_var(BOOL____00826);\n\
constraint array_bool_and([goat[19], goat[24]], false);\n\
constraint array_bool_and([goat[20], cabbage[20]], BOOL____00828) :: defines_var(BOOL____00828);\n\
constraint array_bool_and([goat[21], cabbage[21]], BOOL____00830) :: defines_var(BOOL____00830);\n\
constraint array_bool_and([goat[21], goat[22]], false);\n\
constraint array_bool_and([goat[22], cabbage[22]], BOOL____00832) :: defines_var(BOOL____00832);\n\
constraint array_bool_and([goat[22], goat[27]], false);\n\
constraint array_bool_and([goat[23], cabbage[23]], BOOL____00834) :: defines_var(BOOL____00834);\n\
constraint array_bool_and([goat[24], cabbage[24]], BOOL____00836) :: defines_var(BOOL____00836);\n\
constraint array_bool_and([goat[24], goat[25]], false);\n\
constraint array_bool_and([goat[25], cabbage[25]], BOOL____00838) :: defines_var(BOOL____00838);\n\
constraint array_bool_and([goat[25], goat[30]], false);\n\
constraint array_bool_and([goat[26], cabbage[26]], BOOL____00840) :: defines_var(BOOL____00840);\n\
constraint array_bool_and([goat[27], cabbage[27]], BOOL____00842) :: defines_var(BOOL____00842);\n\
constraint array_bool_and([goat[27], goat[28]], false);\n\
constraint array_bool_and([goat[28], cabbage[28]], BOOL____00844) :: defines_var(BOOL____00844);\n\
constraint array_bool_and([goat[28], goat[33]], false);\n\
constraint array_bool_and([goat[29], cabbage[29]], BOOL____00846) :: defines_var(BOOL____00846);\n\
constraint array_bool_and([goat[30], cabbage[30]], BOOL____00848) :: defines_var(BOOL____00848);\n\
constraint array_bool_and([goat[30], goat[31]], false);\n\
constraint array_bool_and([goat[31], cabbage[31]], BOOL____00850) :: defines_var(BOOL____00850);\n\
constraint array_bool_and([goat[31], goat[36]], false);\n\
constraint array_bool_and([goat[32], cabbage[32]], BOOL____00852) :: defines_var(BOOL____00852);\n\
constraint array_bool_and([goat[33], cabbage[33]], BOOL____00854) :: defines_var(BOOL____00854);\n\
constraint array_bool_and([goat[33], goat[34]], false);\n\
constraint array_bool_and([goat[34], cabbage[34]], BOOL____00856) :: defines_var(BOOL____00856);\n\
constraint array_bool_and([goat[34], goat[39]], false);\n\
constraint array_bool_and([goat[35], cabbage[35]], BOOL____00858) :: defines_var(BOOL____00858);\n\
constraint array_bool_and([goat[36], cabbage[36]], BOOL____00860) :: defines_var(BOOL____00860);\n\
constraint array_bool_and([goat[36], goat[37]], false);\n\
constraint array_bool_and([goat[37], cabbage[37]], BOOL____00862) :: defines_var(BOOL____00862);\n\
constraint array_bool_and([goat[37], goat[42]], false);\n\
constraint array_bool_and([goat[38], cabbage[38]], BOOL____00864) :: defines_var(BOOL____00864);\n\
constraint array_bool_and([goat[39], cabbage[39]], BOOL____00866) :: defines_var(BOOL____00866);\n\
constraint array_bool_and([goat[39], goat[40]], false);\n\
constraint array_bool_and([goat[40], cabbage[40]], BOOL____00868) :: defines_var(BOOL____00868);\n\
constraint array_bool_and([goat[40], goat[45]], false);\n\
constraint array_bool_and([goat[41], cabbage[41]], BOOL____00870) :: defines_var(BOOL____00870);\n\
constraint array_bool_and([goat[42], cabbage[42]], BOOL____00872) :: defines_var(BOOL____00872);\n\
constraint array_bool_and([goat[42], goat[43]], false);\n\
constraint array_bool_and([goat[43], cabbage[43]], BOOL____00874) :: defines_var(BOOL____00874);\n\
constraint array_bool_and([goat[43], goat[48]], false);\n\
constraint array_bool_and([goat[44], cabbage[44]], BOOL____00876) :: defines_var(BOOL____00876);\n\
constraint array_bool_and([goat[45], cabbage[45]], BOOL____00878) :: defines_var(BOOL____00878);\n\
constraint array_bool_and([goat[45], goat[46]], false);\n\
constraint array_bool_and([goat[46], cabbage[46]], BOOL____00880) :: defines_var(BOOL____00880);\n\
constraint array_bool_and([goat[46], goat[51]], false);\n\
constraint array_bool_and([goat[47], cabbage[47]], BOOL____00882) :: defines_var(BOOL____00882);\n\
constraint array_bool_and([goat[48], cabbage[48]], BOOL____00884) :: defines_var(BOOL____00884);\n\
constraint array_bool_and([goat[48], goat[49]], false);\n\
constraint array_bool_and([goat[49], cabbage[49]], BOOL____00886) :: defines_var(BOOL____00886);\n\
constraint array_bool_and([goat[49], goat[54]], false);\n\
constraint array_bool_and([goat[50], cabbage[50]], BOOL____00888) :: defines_var(BOOL____00888);\n\
constraint array_bool_and([goat[51], cabbage[51]], BOOL____00890) :: defines_var(BOOL____00890);\n\
constraint array_bool_and([goat[51], goat[52]], false);\n\
constraint array_bool_and([goat[52], cabbage[52]], BOOL____00892) :: defines_var(BOOL____00892);\n\
constraint array_bool_and([goat[52], goat[57]], false);\n\
constraint array_bool_and([goat[53], cabbage[53]], BOOL____00894) :: defines_var(BOOL____00894);\n\
constraint array_bool_and([goat[54], cabbage[54]], BOOL____00896) :: defines_var(BOOL____00896);\n\
constraint array_bool_and([goat[54], goat[55]], false);\n\
constraint array_bool_and([goat[55], cabbage[55]], BOOL____00898) :: defines_var(BOOL____00898);\n\
constraint array_bool_and([goat[55], goat[60]], false);\n\
constraint array_bool_and([goat[56], cabbage[56]], BOOL____00900) :: defines_var(BOOL____00900);\n\
constraint array_bool_and([goat[57], cabbage[57]], BOOL____00902) :: defines_var(BOOL____00902);\n\
constraint array_bool_and([goat[57], goat[58]], false);\n\
constraint array_bool_and([goat[58], cabbage[58]], BOOL____00904) :: defines_var(BOOL____00904);\n\
constraint array_bool_and([goat[59], cabbage[59]], BOOL____00906) :: defines_var(BOOL____00906);\n\
constraint array_bool_and([goat[60], cabbage[60]], BOOL____00908) :: defines_var(BOOL____00908);\n\
constraint array_bool_and([wolf[1], goat[1]], BOOL____00789) :: defines_var(BOOL____00789);\n\
constraint array_bool_and([wolf[1], wolf[6]], false);\n\
constraint array_bool_and([wolf[2], goat[2]], BOOL____00791) :: defines_var(BOOL____00791);\n\
constraint array_bool_and([wolf[3], goat[3]], BOOL____00793) :: defines_var(BOOL____00793);\n\
constraint array_bool_and([wolf[3], wolf[4]], false);\n\
constraint array_bool_and([wolf[4], goat[4]], BOOL____00795) :: defines_var(BOOL____00795);\n\
constraint array_bool_and([wolf[4], wolf[9]], false);\n\
constraint array_bool_and([wolf[5], goat[5]], BOOL____00797) :: defines_var(BOOL____00797);\n\
constraint array_bool_and([wolf[6], goat[6]], BOOL____00799) :: defines_var(BOOL____00799);\n\
constraint array_bool_and([wolf[6], wolf[7]], false);\n\
constraint array_bool_and([wolf[7], goat[7]], BOOL____00801) :: defines_var(BOOL____00801);\n\
constraint array_bool_and([wolf[7], wolf[12]], false);\n\
constraint array_bool_and([wolf[8], goat[8]], BOOL____00803) :: defines_var(BOOL____00803);\n\
constraint array_bool_and([wolf[9], goat[9]], BOOL____00805) :: defines_var(BOOL____00805);\n\
constraint array_bool_and([wolf[9], wolf[10]], false);\n\
constraint array_bool_and([wolf[10], goat[10]], BOOL____00807) :: defines_var(BOOL____00807);\n\
constraint array_bool_and([wolf[10], wolf[15]], false);\n\
constraint array_bool_and([wolf[11], goat[11]], BOOL____00809) :: defines_var(BOOL____00809);\n\
constraint array_bool_and([wolf[12], goat[12]], BOOL____00811) :: defines_var(BOOL____00811);\n\
constraint array_bool_and([wolf[12], wolf[13]], false);\n\
constraint array_bool_and([wolf[13], goat[13]], BOOL____00813) :: defines_var(BOOL____00813);\n\
constraint array_bool_and([wolf[13], wolf[18]], false);\n\
constraint array_bool_and([wolf[14], goat[14]], BOOL____00815) :: defines_var(BOOL____00815);\n\
constraint array_bool_and([wolf[15], goat[15]], BOOL____00817) :: defines_var(BOOL____00817);\n\
constraint array_bool_and([wolf[15], wolf[16]], false);\n\
constraint array_bool_and([wolf[16], goat[16]], BOOL____00819) :: defines_var(BOOL____00819);\n\
constraint array_bool_and([wolf[16], wolf[21]], false);\n\
constraint array_bool_and([wolf[17], goat[17]], BOOL____00821) :: defines_var(BOOL____00821);\n\
constraint array_bool_and([wolf[18], goat[18]], BOOL____00823) :: defines_var(BOOL____00823);\n\
constraint array_bool_and([wolf[18], wolf[19]], false);\n\
constraint array_bool_and([wolf[19], goat[19]], BOOL____00825) :: defines_var(BOOL____00825);\n\
constraint array_bool_and([wolf[19], wolf[24]], false);\n\
constraint array_bool_and([wolf[20], goat[20]], BOOL____00827) :: defines_var(BOOL____00827);\n\
constraint array_bool_and([wolf[21], goat[21]], BOOL____00829) :: defines_var(BOOL____00829);\n\
constraint array_bool_and([wolf[21], wolf[22]], false);\n\
constraint array_bool_and([wolf[22], goat[22]], BOOL____00831) :: defines_var(BOOL____00831);\n\
constraint array_bool_and([wolf[22], wolf[27]], false);\n\
constraint array_bool_and([wolf[23], goat[23]], BOOL____00833) :: defines_var(BOOL____00833);\n\
constraint array_bool_and([wolf[24], goat[24]], BOOL____00835) :: defines_var(BOOL____00835);\n\
constraint array_bool_and([wolf[24], wolf[25]], false);\n\
constraint array_bool_and([wolf[25], goat[25]], BOOL____00837) :: defines_var(BOOL____00837);\n\
constraint array_bool_and([wolf[25], wolf[30]], false);\n\
constraint array_bool_and([wolf[26], goat[26]], BOOL____00839) :: defines_var(BOOL____00839);\n\
constraint array_bool_and([wolf[27], goat[27]], BOOL____00841) :: defines_var(BOOL____00841);\n\
constraint array_bool_and([wolf[27], wolf[28]], false);\n\
constraint array_bool_and([wolf[28], goat[28]], BOOL____00843) :: defines_var(BOOL____00843);\n\
constraint array_bool_and([wolf[28], wolf[33]], false);\n\
constraint array_bool_and([wolf[29], goat[29]], BOOL____00845) :: defines_var(BOOL____00845);\n\
constraint array_bool_and([wolf[30], goat[30]], BOOL____00847) :: defines_var(BOOL____00847);\n\
constraint array_bool_and([wolf[30], wolf[31]], false);\n\
constraint array_bool_and([wolf[31], goat[31]], BOOL____00849) :: defines_var(BOOL____00849);\n\
constraint array_bool_and([wolf[31], wolf[36]], false);\n\
constraint array_bool_and([wolf[32], goat[32]], BOOL____00851) :: defines_var(BOOL____00851);\n\
constraint array_bool_and([wolf[33], goat[33]], BOOL____00853) :: defines_var(BOOL____00853);\n\
constraint array_bool_and([wolf[33], wolf[34]], false);\n\
constraint array_bool_and([wolf[34], goat[34]], BOOL____00855) :: defines_var(BOOL____00855);\n\
constraint array_bool_and([wolf[34], wolf[39]], false);\n\
constraint array_bool_and([wolf[35], goat[35]], BOOL____00857) :: defines_var(BOOL____00857);\n\
constraint array_bool_and([wolf[36], goat[36]], BOOL____00859) :: defines_var(BOOL____00859);\n\
constraint array_bool_and([wolf[36], wolf[37]], false);\n\
constraint array_bool_and([wolf[37], goat[37]], BOOL____00861) :: defines_var(BOOL____00861);\n\
constraint array_bool_and([wolf[37], wolf[42]], false);\n\
constraint array_bool_and([wolf[38], goat[38]], BOOL____00863) :: defines_var(BOOL____00863);\n\
constraint array_bool_and([wolf[39], goat[39]], BOOL____00865) :: defines_var(BOOL____00865);\n\
constraint array_bool_and([wolf[39], wolf[40]], false);\n\
constraint array_bool_and([wolf[40], goat[40]], BOOL____00867) :: defines_var(BOOL____00867);\n\
constraint array_bool_and([wolf[40], wolf[45]], false);\n\
constraint array_bool_and([wolf[41], goat[41]], BOOL____00869) :: defines_var(BOOL____00869);\n\
constraint array_bool_and([wolf[42], goat[42]], BOOL____00871) :: defines_var(BOOL____00871);\n\
constraint array_bool_and([wolf[42], wolf[43]], false);\n\
constraint array_bool_and([wolf[43], goat[43]], BOOL____00873) :: defines_var(BOOL____00873);\n\
constraint array_bool_and([wolf[43], wolf[48]], false);\n\
constraint array_bool_and([wolf[44], goat[44]], BOOL____00875) :: defines_var(BOOL____00875);\n\
constraint array_bool_and([wolf[45], goat[45]], BOOL____00877) :: defines_var(BOOL____00877);\n\
constraint array_bool_and([wolf[45], wolf[46]], false);\n\
constraint array_bool_and([wolf[46], goat[46]], BOOL____00879) :: defines_var(BOOL____00879);\n\
constraint array_bool_and([wolf[46], wolf[51]], false);\n\
constraint array_bool_and([wolf[47], goat[47]], BOOL____00881) :: defines_var(BOOL____00881);\n\
constraint array_bool_and([wolf[48], goat[48]], BOOL____00883) :: defines_var(BOOL____00883);\n\
constraint array_bool_and([wolf[48], wolf[49]], false);\n\
constraint array_bool_and([wolf[49], goat[49]], BOOL____00885) :: defines_var(BOOL____00885);\n\
constraint array_bool_and([wolf[49], wolf[54]], false);\n\
constraint array_bool_and([wolf[50], goat[50]], BOOL____00887) :: defines_var(BOOL____00887);\n\
constraint array_bool_and([wolf[51], goat[51]], BOOL____00889) :: defines_var(BOOL____00889);\n\
constraint array_bool_and([wolf[51], wolf[52]], false);\n\
constraint array_bool_and([wolf[52], goat[52]], BOOL____00891) :: defines_var(BOOL____00891);\n\
constraint array_bool_and([wolf[52], wolf[57]], false);\n\
constraint array_bool_and([wolf[53], goat[53]], BOOL____00893) :: defines_var(BOOL____00893);\n\
constraint array_bool_and([wolf[54], goat[54]], BOOL____00895) :: defines_var(BOOL____00895);\n\
constraint array_bool_and([wolf[54], wolf[55]], false);\n\
constraint array_bool_and([wolf[55], goat[55]], BOOL____00897) :: defines_var(BOOL____00897);\n\
constraint array_bool_and([wolf[55], wolf[60]], false);\n\
constraint array_bool_and([wolf[56], goat[56]], BOOL____00899) :: defines_var(BOOL____00899);\n\
constraint array_bool_and([wolf[57], goat[57]], BOOL____00901) :: defines_var(BOOL____00901);\n\
constraint array_bool_and([wolf[57], wolf[58]], false);\n\
constraint array_bool_and([wolf[58], goat[58]], BOOL____00903) :: defines_var(BOOL____00903);\n\
constraint array_bool_and([wolf[59], goat[59]], BOOL____00905) :: defines_var(BOOL____00905);\n\
constraint array_bool_and([wolf[60], goat[60]], BOOL____00907) :: defines_var(BOOL____00907);\n\
constraint array_bool_and([cabbage[1], BOOL____00180, BOOL____00179], BOOL____00182) :: defines_var(BOOL____00182);\n\
constraint array_bool_and([cabbage[2], BOOL____00180, BOOL____00181], BOOL____00183) :: defines_var(BOOL____00183);\n\
constraint array_bool_and([cabbage[3], BOOL____00179, BOOL____00181], BOOL____00184) :: defines_var(BOOL____00184);\n\
constraint array_bool_and([cabbage[4], BOOL____00186, BOOL____00185], BOOL____00188) :: defines_var(BOOL____00188);\n\
constraint array_bool_and([cabbage[5], BOOL____00186, BOOL____00187], BOOL____00189) :: defines_var(BOOL____00189);\n\
constraint array_bool_and([cabbage[6], BOOL____00185, BOOL____00187], BOOL____00190) :: defines_var(BOOL____00190);\n\
constraint array_bool_and([cabbage[7], BOOL____00192, BOOL____00191], BOOL____00194) :: defines_var(BOOL____00194);\n\
constraint array_bool_and([cabbage[8], BOOL____00192, BOOL____00193], BOOL____00195) :: defines_var(BOOL____00195);\n\
constraint array_bool_and([cabbage[9], BOOL____00191, BOOL____00193], BOOL____00196) :: defines_var(BOOL____00196);\n\
constraint array_bool_and([cabbage[10], BOOL____00198, BOOL____00197], BOOL____00200) :: defines_var(BOOL____00200);\n\
constraint array_bool_and([cabbage[11], BOOL____00198, BOOL____00199], BOOL____00201) :: defines_var(BOOL____00201);\n\
constraint array_bool_and([cabbage[12], BOOL____00197, BOOL____00199], BOOL____00202) :: defines_var(BOOL____00202);\n\
constraint array_bool_and([cabbage[13], BOOL____00204, BOOL____00203], BOOL____00206) :: defines_var(BOOL____00206);\n\
constraint array_bool_and([cabbage[14], BOOL____00204, BOOL____00205], BOOL____00207) :: defines_var(BOOL____00207);\n\
constraint array_bool_and([cabbage[15], BOOL____00203, BOOL____00205], BOOL____00208) :: defines_var(BOOL____00208);\n\
constraint array_bool_and([cabbage[16], BOOL____00210, BOOL____00209], BOOL____00212) :: defines_var(BOOL____00212);\n\
constraint array_bool_and([cabbage[17], BOOL____00210, BOOL____00211], BOOL____00213) :: defines_var(BOOL____00213);\n\
constraint array_bool_and([cabbage[18], BOOL____00209, BOOL____00211], BOOL____00214) :: defines_var(BOOL____00214);\n\
constraint array_bool_and([cabbage[19], BOOL____00216, BOOL____00215], BOOL____00218) :: defines_var(BOOL____00218);\n\
constraint array_bool_and([cabbage[20], BOOL____00216, BOOL____00217], BOOL____00219) :: defines_var(BOOL____00219);\n\
constraint array_bool_and([cabbage[21], BOOL____00215, BOOL____00217], BOOL____00220) :: defines_var(BOOL____00220);\n\
constraint array_bool_and([cabbage[22], BOOL____00222, BOOL____00221], BOOL____00224) :: defines_var(BOOL____00224);\n\
constraint array_bool_and([cabbage[23], BOOL____00222, BOOL____00223], BOOL____00225) :: defines_var(BOOL____00225);\n\
constraint array_bool_and([cabbage[24], BOOL____00221, BOOL____00223], BOOL____00226) :: defines_var(BOOL____00226);\n\
constraint array_bool_and([cabbage[25], BOOL____00228, BOOL____00227], BOOL____00230) :: defines_var(BOOL____00230);\n\
constraint array_bool_and([cabbage[26], BOOL____00228, BOOL____00229], BOOL____00231) :: defines_var(BOOL____00231);\n\
constraint array_bool_and([cabbage[27], BOOL____00227, BOOL____00229], BOOL____00232) :: defines_var(BOOL____00232);\n\
constraint array_bool_and([cabbage[28], BOOL____00234, BOOL____00233], BOOL____00236) :: defines_var(BOOL____00236);\n\
constraint array_bool_and([cabbage[29], BOOL____00234, BOOL____00235], BOOL____00237) :: defines_var(BOOL____00237);\n\
constraint array_bool_and([cabbage[30], BOOL____00233, BOOL____00235], BOOL____00238) :: defines_var(BOOL____00238);\n\
constraint array_bool_and([cabbage[31], BOOL____00240, BOOL____00239], BOOL____00242) :: defines_var(BOOL____00242);\n\
constraint array_bool_and([cabbage[32], BOOL____00240, BOOL____00241], BOOL____00243) :: defines_var(BOOL____00243);\n\
constraint array_bool_and([cabbage[33], BOOL____00239, BOOL____00241], BOOL____00244) :: defines_var(BOOL____00244);\n\
constraint array_bool_and([cabbage[34], BOOL____00246, BOOL____00245], BOOL____00248) :: defines_var(BOOL____00248);\n\
constraint array_bool_and([cabbage[35], BOOL____00246, BOOL____00247], BOOL____00249) :: defines_var(BOOL____00249);\n\
constraint array_bool_and([cabbage[36], BOOL____00245, BOOL____00247], BOOL____00250) :: defines_var(BOOL____00250);\n\
constraint array_bool_and([cabbage[37], BOOL____00252, BOOL____00251], BOOL____00254) :: defines_var(BOOL____00254);\n\
constraint array_bool_and([cabbage[38], BOOL____00252, BOOL____00253], BOOL____00255) :: defines_var(BOOL____00255);\n\
constraint array_bool_and([cabbage[39], BOOL____00251, BOOL____00253], BOOL____00256) :: defines_var(BOOL____00256);\n\
constraint array_bool_and([cabbage[40], BOOL____00258, BOOL____00257], BOOL____00260) :: defines_var(BOOL____00260);\n\
constraint array_bool_and([cabbage[41], BOOL____00258, BOOL____00259], BOOL____00261) :: defines_var(BOOL____00261);\n\
constraint array_bool_and([cabbage[42], BOOL____00257, BOOL____00259], BOOL____00262) :: defines_var(BOOL____00262);\n\
constraint array_bool_and([cabbage[43], BOOL____00264, BOOL____00263], BOOL____00266) :: defines_var(BOOL____00266);\n\
constraint array_bool_and([cabbage[44], BOOL____00264, BOOL____00265], BOOL____00267) :: defines_var(BOOL____00267);\n\
constraint array_bool_and([cabbage[45], BOOL____00263, BOOL____00265], BOOL____00268) :: defines_var(BOOL____00268);\n\
constraint array_bool_and([cabbage[46], BOOL____00270, BOOL____00269], BOOL____00272) :: defines_var(BOOL____00272);\n\
constraint array_bool_and([cabbage[47], BOOL____00270, BOOL____00271], BOOL____00273) :: defines_var(BOOL____00273);\n\
constraint array_bool_and([cabbage[48], BOOL____00269, BOOL____00271], BOOL____00274) :: defines_var(BOOL____00274);\n\
constraint array_bool_and([cabbage[49], BOOL____00276, BOOL____00275], BOOL____00278) :: defines_var(BOOL____00278);\n\
constraint array_bool_and([cabbage[50], BOOL____00276, BOOL____00277], BOOL____00279) :: defines_var(BOOL____00279);\n\
constraint array_bool_and([cabbage[51], BOOL____00275, BOOL____00277], BOOL____00280) :: defines_var(BOOL____00280);\n\
constraint array_bool_and([cabbage[52], BOOL____00282, BOOL____00281], BOOL____00284) :: defines_var(BOOL____00284);\n\
constraint array_bool_and([cabbage[53], BOOL____00282, BOOL____00283], BOOL____00285) :: defines_var(BOOL____00285);\n\
constraint array_bool_and([cabbage[54], BOOL____00281, BOOL____00283], BOOL____00286) :: defines_var(BOOL____00286);\n\
constraint array_bool_and([cabbage[55], BOOL____00288, BOOL____00287], BOOL____00290) :: defines_var(BOOL____00290);\n\
constraint array_bool_and([cabbage[56], BOOL____00288, BOOL____00289], BOOL____00291) :: defines_var(BOOL____00291);\n\
constraint array_bool_and([cabbage[57], BOOL____00287, BOOL____00289], BOOL____00292) :: defines_var(BOOL____00292);\n\
constraint array_bool_and([cabbage[58], BOOL____00294, BOOL____00293], BOOL____00296) :: defines_var(BOOL____00296);\n\
constraint array_bool_and([cabbage[59], BOOL____00294, BOOL____00295], BOOL____00297) :: defines_var(BOOL____00297);\n\
constraint array_bool_and([cabbage[60], BOOL____00293, BOOL____00295], BOOL____00298) :: defines_var(BOOL____00298);\n\
constraint array_bool_and([farmer[1], BOOL____00002, BOOL____00001], BOOL____00004) :: defines_var(BOOL____00004);\n\
constraint array_bool_and([farmer[2], BOOL____00002, BOOL____00003], BOOL____00005) :: defines_var(BOOL____00005);\n\
constraint array_bool_and([farmer[3], BOOL____00001, BOOL____00003], BOOL____00006) :: defines_var(BOOL____00006);\n\
constraint array_bool_and([farmer[4], BOOL____00008, BOOL____00007], BOOL____00010) :: defines_var(BOOL____00010);\n\
constraint array_bool_and([farmer[5], BOOL____00008, BOOL____00009], BOOL____00011) :: defines_var(BOOL____00011);\n\
constraint array_bool_and([farmer[6], BOOL____00007, BOOL____00009], BOOL____00012) :: defines_var(BOOL____00012);\n\
constraint array_bool_and([farmer[7], BOOL____00014, BOOL____00013], BOOL____00016) :: defines_var(BOOL____00016);\n\
constraint array_bool_and([farmer[8], BOOL____00014, BOOL____00015], BOOL____00017) :: defines_var(BOOL____00017);\n\
constraint array_bool_and([farmer[9], BOOL____00013, BOOL____00015], BOOL____00018) :: defines_var(BOOL____00018);\n\
constraint array_bool_and([farmer[10], BOOL____00020, BOOL____00019], BOOL____00022) :: defines_var(BOOL____00022);\n\
constraint array_bool_and([farmer[11], BOOL____00020, BOOL____00021], BOOL____00023) :: defines_var(BOOL____00023);\n\
constraint array_bool_and([farmer[12], BOOL____00019, BOOL____00021], BOOL____00024) :: defines_var(BOOL____00024);\n\
constraint array_bool_and([farmer[13], BOOL____00026, BOOL____00025], BOOL____00028) :: defines_var(BOOL____00028);\n\
constraint array_bool_and([farmer[14], BOOL____00026, BOOL____00027], BOOL____00029) :: defines_var(BOOL____00029);\n\
constraint array_bool_and([farmer[15], BOOL____00025, BOOL____00027], BOOL____00030) :: defines_var(BOOL____00030);\n\
constraint array_bool_and([farmer[16], BOOL____00032, BOOL____00031], BOOL____00034) :: defines_var(BOOL____00034);\n\
constraint array_bool_and([farmer[17], BOOL____00032, BOOL____00033], BOOL____00035) :: defines_var(BOOL____00035);\n\
constraint array_bool_and([farmer[18], BOOL____00031, BOOL____00033], BOOL____00036) :: defines_var(BOOL____00036);\n\
constraint array_bool_and([farmer[19], BOOL____00038, BOOL____00037], BOOL____00040) :: defines_var(BOOL____00040);\n\
constraint array_bool_and([farmer[20], BOOL____00038, BOOL____00039], BOOL____00041) :: defines_var(BOOL____00041);\n\
constraint array_bool_and([farmer[21], BOOL____00037, BOOL____00039], BOOL____00042) :: defines_var(BOOL____00042);\n\
constraint array_bool_and([farmer[22], BOOL____00044, BOOL____00043], BOOL____00046) :: defines_var(BOOL____00046);\n\
constraint array_bool_and([farmer[23], BOOL____00044, BOOL____00045], BOOL____00047) :: defines_var(BOOL____00047);\n\
constraint array_bool_and([farmer[24], BOOL____00043, BOOL____00045], BOOL____00048) :: defines_var(BOOL____00048);\n\
constraint array_bool_and([farmer[25], BOOL____00050, BOOL____00049], BOOL____00052) :: defines_var(BOOL____00052);\n\
constraint array_bool_and([farmer[26], BOOL____00050, BOOL____00051], BOOL____00053) :: defines_var(BOOL____00053);\n\
constraint array_bool_and([farmer[27], BOOL____00049, BOOL____00051], BOOL____00054) :: defines_var(BOOL____00054);\n\
constraint array_bool_and([farmer[28], BOOL____00056, BOOL____00055], BOOL____00058) :: defines_var(BOOL____00058);\n\
constraint array_bool_and([farmer[29], BOOL____00056, BOOL____00057], BOOL____00059) :: defines_var(BOOL____00059);\n\
constraint array_bool_and([farmer[30], BOOL____00055, BOOL____00057], BOOL____00060) :: defines_var(BOOL____00060);\n\
constraint array_bool_and([farmer[31], BOOL____00062, BOOL____00061], BOOL____00064) :: defines_var(BOOL____00064);\n\
constraint array_bool_and([farmer[32], BOOL____00062, BOOL____00063], BOOL____00065) :: defines_var(BOOL____00065);\n\
constraint array_bool_and([farmer[33], BOOL____00061, BOOL____00063], BOOL____00066) :: defines_var(BOOL____00066);\n\
constraint array_bool_and([farmer[34], BOOL____00068, BOOL____00067], BOOL____00070) :: defines_var(BOOL____00070);\n\
constraint array_bool_and([farmer[35], BOOL____00068, BOOL____00069], BOOL____00071) :: defines_var(BOOL____00071);\n\
constraint array_bool_and([farmer[36], BOOL____00067, BOOL____00069], BOOL____00072) :: defines_var(BOOL____00072);\n\
constraint array_bool_and([farmer[37], BOOL____00074, BOOL____00073], BOOL____00076) :: defines_var(BOOL____00076);\n\
constraint array_bool_and([farmer[38], BOOL____00074, BOOL____00075], BOOL____00077) :: defines_var(BOOL____00077);\n\
constraint array_bool_and([farmer[39], BOOL____00073, BOOL____00075], BOOL____00078) :: defines_var(BOOL____00078);\n\
constraint array_bool_and([farmer[40], BOOL____00080, BOOL____00079], BOOL____00082) :: defines_var(BOOL____00082);\n\
constraint array_bool_and([farmer[41], BOOL____00080, BOOL____00081], BOOL____00083) :: defines_var(BOOL____00083);\n\
constraint array_bool_and([farmer[42], BOOL____00079, BOOL____00081], BOOL____00084) :: defines_var(BOOL____00084);\n\
constraint array_bool_and([farmer[43], BOOL____00086, BOOL____00085], BOOL____00088) :: defines_var(BOOL____00088);\n\
constraint array_bool_and([farmer[44], BOOL____00086, BOOL____00087], BOOL____00089) :: defines_var(BOOL____00089);\n\
constraint array_bool_and([farmer[45], BOOL____00085, BOOL____00087], BOOL____00090) :: defines_var(BOOL____00090);\n\
constraint array_bool_and([farmer[46], BOOL____00092, BOOL____00091], BOOL____00094) :: defines_var(BOOL____00094);\n\
constraint array_bool_and([farmer[47], BOOL____00092, BOOL____00093], BOOL____00095) :: defines_var(BOOL____00095);\n\
constraint array_bool_and([farmer[48], BOOL____00091, BOOL____00093], BOOL____00096) :: defines_var(BOOL____00096);\n\
constraint array_bool_and([farmer[49], BOOL____00098, BOOL____00097], BOOL____00100) :: defines_var(BOOL____00100);\n\
constraint array_bool_and([farmer[50], BOOL____00098, BOOL____00099], BOOL____00101) :: defines_var(BOOL____00101);\n\
constraint array_bool_and([farmer[51], BOOL____00097, BOOL____00099], BOOL____00102) :: defines_var(BOOL____00102);\n\
constraint array_bool_and([farmer[52], BOOL____00104, BOOL____00103], BOOL____00106) :: defines_var(BOOL____00106);\n\
constraint array_bool_and([farmer[53], BOOL____00104, BOOL____00105], BOOL____00107) :: defines_var(BOOL____00107);\n\
constraint array_bool_and([farmer[54], BOOL____00103, BOOL____00105], BOOL____00108) :: defines_var(BOOL____00108);\n\
constraint array_bool_and([farmer[55], BOOL____00110, BOOL____00109], BOOL____00112) :: defines_var(BOOL____00112);\n\
constraint array_bool_and([farmer[56], BOOL____00110, BOOL____00111], BOOL____00113) :: defines_var(BOOL____00113);\n\
constraint array_bool_and([farmer[57], BOOL____00109, BOOL____00111], BOOL____00114) :: defines_var(BOOL____00114);\n\
constraint array_bool_and([farmer[58], BOOL____00116, BOOL____00115], BOOL____00118) :: defines_var(BOOL____00118);\n\
constraint array_bool_and([farmer[59], BOOL____00116, BOOL____00117], BOOL____00119) :: defines_var(BOOL____00119);\n\
constraint array_bool_and([farmer[60], BOOL____00115, BOOL____00117], BOOL____00120) :: defines_var(BOOL____00120);\n\
constraint array_bool_and([goat[1], BOOL____00358, BOOL____00357], BOOL____00360) :: defines_var(BOOL____00360);\n\
constraint array_bool_and([goat[2], BOOL____00358, BOOL____00359], BOOL____00361) :: defines_var(BOOL____00361);\n\
constraint array_bool_and([goat[3], BOOL____00357, BOOL____00359], BOOL____00362) :: defines_var(BOOL____00362);\n\
constraint array_bool_and([goat[4], BOOL____00364, BOOL____00363], BOOL____00366) :: defines_var(BOOL____00366);\n\
constraint array_bool_and([goat[5], BOOL____00364, BOOL____00365], BOOL____00367) :: defines_var(BOOL____00367);\n\
constraint array_bool_and([goat[6], BOOL____00363, BOOL____00365], BOOL____00368) :: defines_var(BOOL____00368);\n\
constraint array_bool_and([goat[7], BOOL____00370, BOOL____00369], BOOL____00372) :: defines_var(BOOL____00372);\n\
constraint array_bool_and([goat[8], BOOL____00370, BOOL____00371], BOOL____00373) :: defines_var(BOOL____00373);\n\
constraint array_bool_and([goat[9], BOOL____00369, BOOL____00371], BOOL____00374) :: defines_var(BOOL____00374);\n\
constraint array_bool_and([goat[10], BOOL____00376, BOOL____00375], BOOL____00378) :: defines_var(BOOL____00378);\n\
constraint array_bool_and([goat[11], BOOL____00376, BOOL____00377], BOOL____00379) :: defines_var(BOOL____00379);\n\
constraint array_bool_and([goat[12], BOOL____00375, BOOL____00377], BOOL____00380) :: defines_var(BOOL____00380);\n\
constraint array_bool_and([goat[13], BOOL____00382, BOOL____00381], BOOL____00384) :: defines_var(BOOL____00384);\n\
constraint array_bool_and([goat[14], BOOL____00382, BOOL____00383], BOOL____00385) :: defines_var(BOOL____00385);\n\
constraint array_bool_and([goat[15], BOOL____00381, BOOL____00383], BOOL____00386) :: defines_var(BOOL____00386);\n\
constraint array_bool_and([goat[16], BOOL____00388, BOOL____00387], BOOL____00390) :: defines_var(BOOL____00390);\n\
constraint array_bool_and([goat[17], BOOL____00388, BOOL____00389], BOOL____00391) :: defines_var(BOOL____00391);\n\
constraint array_bool_and([goat[18], BOOL____00387, BOOL____00389], BOOL____00392) :: defines_var(BOOL____00392);\n\
constraint array_bool_and([goat[19], BOOL____00394, BOOL____00393], BOOL____00396) :: defines_var(BOOL____00396);\n\
constraint array_bool_and([goat[20], BOOL____00394, BOOL____00395], BOOL____00397) :: defines_var(BOOL____00397);\n\
constraint array_bool_and([goat[21], BOOL____00393, BOOL____00395], BOOL____00398) :: defines_var(BOOL____00398);\n\
constraint array_bool_and([goat[22], BOOL____00400, BOOL____00399], BOOL____00402) :: defines_var(BOOL____00402);\n\
constraint array_bool_and([goat[23], BOOL____00400, BOOL____00401], BOOL____00403) :: defines_var(BOOL____00403);\n\
constraint array_bool_and([goat[24], BOOL____00399, BOOL____00401], BOOL____00404) :: defines_var(BOOL____00404);\n\
constraint array_bool_and([goat[25], BOOL____00406, BOOL____00405], BOOL____00408) :: defines_var(BOOL____00408);\n\
constraint array_bool_and([goat[26], BOOL____00406, BOOL____00407], BOOL____00409) :: defines_var(BOOL____00409);\n\
constraint array_bool_and([goat[27], BOOL____00405, BOOL____00407], BOOL____00410) :: defines_var(BOOL____00410);\n\
constraint array_bool_and([goat[28], BOOL____00412, BOOL____00411], BOOL____00414) :: defines_var(BOOL____00414);\n\
constraint array_bool_and([goat[29], BOOL____00412, BOOL____00413], BOOL____00415) :: defines_var(BOOL____00415);\n\
constraint array_bool_and([goat[30], BOOL____00411, BOOL____00413], BOOL____00416) :: defines_var(BOOL____00416);\n\
constraint array_bool_and([goat[31], BOOL____00418, BOOL____00417], BOOL____00420) :: defines_var(BOOL____00420);\n\
constraint array_bool_and([goat[32], BOOL____00418, BOOL____00419], BOOL____00421) :: defines_var(BOOL____00421);\n\
constraint array_bool_and([goat[33], BOOL____00417, BOOL____00419], BOOL____00422) :: defines_var(BOOL____00422);\n\
constraint array_bool_and([goat[34], BOOL____00424, BOOL____00423], BOOL____00426) :: defines_var(BOOL____00426);\n\
constraint array_bool_and([goat[35], BOOL____00424, BOOL____00425], BOOL____00427) :: defines_var(BOOL____00427);\n\
constraint array_bool_and([goat[36], BOOL____00423, BOOL____00425], BOOL____00428) :: defines_var(BOOL____00428);\n\
constraint array_bool_and([goat[37], BOOL____00430, BOOL____00429], BOOL____00432) :: defines_var(BOOL____00432);\n\
constraint array_bool_and([goat[38], BOOL____00430, BOOL____00431], BOOL____00433) :: defines_var(BOOL____00433);\n\
constraint array_bool_and([goat[39], BOOL____00429, BOOL____00431], BOOL____00434) :: defines_var(BOOL____00434);\n\
constraint array_bool_and([goat[40], BOOL____00436, BOOL____00435], BOOL____00438) :: defines_var(BOOL____00438);\n\
constraint array_bool_and([goat[41], BOOL____00436, BOOL____00437], BOOL____00439) :: defines_var(BOOL____00439);\n\
constraint array_bool_and([goat[42], BOOL____00435, BOOL____00437], BOOL____00440) :: defines_var(BOOL____00440);\n\
constraint array_bool_and([goat[43], BOOL____00442, BOOL____00441], BOOL____00444) :: defines_var(BOOL____00444);\n\
constraint array_bool_and([goat[44], BOOL____00442, BOOL____00443], BOOL____00445) :: defines_var(BOOL____00445);\n\
constraint array_bool_and([goat[45], BOOL____00441, BOOL____00443], BOOL____00446) :: defines_var(BOOL____00446);\n\
constraint array_bool_and([goat[46], BOOL____00448, BOOL____00447], BOOL____00450) :: defines_var(BOOL____00450);\n\
constraint array_bool_and([goat[47], BOOL____00448, BOOL____00449], BOOL____00451) :: defines_var(BOOL____00451);\n\
constraint array_bool_and([goat[48], BOOL____00447, BOOL____00449], BOOL____00452) :: defines_var(BOOL____00452);\n\
constraint array_bool_and([goat[49], BOOL____00454, BOOL____00453], BOOL____00456) :: defines_var(BOOL____00456);\n\
constraint array_bool_and([goat[50], BOOL____00454, BOOL____00455], BOOL____00457) :: defines_var(BOOL____00457);\n\
constraint array_bool_and([goat[51], BOOL____00453, BOOL____00455], BOOL____00458) :: defines_var(BOOL____00458);\n\
constraint array_bool_and([goat[52], BOOL____00460, BOOL____00459], BOOL____00462) :: defines_var(BOOL____00462);\n\
constraint array_bool_and([goat[53], BOOL____00460, BOOL____00461], BOOL____00463) :: defines_var(BOOL____00463);\n\
constraint array_bool_and([goat[54], BOOL____00459, BOOL____00461], BOOL____00464) :: defines_var(BOOL____00464);\n\
constraint array_bool_and([goat[55], BOOL____00466, BOOL____00465], BOOL____00468) :: defines_var(BOOL____00468);\n\
constraint array_bool_and([goat[56], BOOL____00466, BOOL____00467], BOOL____00469) :: defines_var(BOOL____00469);\n\
constraint array_bool_and([goat[57], BOOL____00465, BOOL____00467], BOOL____00470) :: defines_var(BOOL____00470);\n\
constraint array_bool_and([goat[58], BOOL____00472, BOOL____00471], BOOL____00474) :: defines_var(BOOL____00474);\n\
constraint array_bool_and([goat[59], BOOL____00472, BOOL____00473], BOOL____00475) :: defines_var(BOOL____00475);\n\
constraint array_bool_and([goat[60], BOOL____00471, BOOL____00473], BOOL____00476) :: defines_var(BOOL____00476);\n\
constraint array_bool_and([wolf[1], BOOL____00668, BOOL____00667], BOOL____00670) :: defines_var(BOOL____00670);\n\
constraint array_bool_and([wolf[2], BOOL____00668, BOOL____00669], BOOL____00671) :: defines_var(BOOL____00671);\n\
constraint array_bool_and([wolf[3], BOOL____00667, BOOL____00669], BOOL____00672) :: defines_var(BOOL____00672);\n\
constraint array_bool_and([wolf[4], BOOL____00673, BOOL____00538], BOOL____00675) :: defines_var(BOOL____00675);\n\
constraint array_bool_and([wolf[5], BOOL____00673, BOOL____00674], BOOL____00676) :: defines_var(BOOL____00676);\n\
constraint array_bool_and([wolf[6], BOOL____00538, BOOL____00674], BOOL____00677) :: defines_var(BOOL____00677);\n\
constraint array_bool_and([wolf[7], BOOL____00678, BOOL____00548], BOOL____00680) :: defines_var(BOOL____00680);\n\
constraint array_bool_and([wolf[8], BOOL____00678, BOOL____00679], BOOL____00681) :: defines_var(BOOL____00681);\n\
constraint array_bool_and([wolf[9], BOOL____00548, BOOL____00679], BOOL____00682) :: defines_var(BOOL____00682);\n\
constraint array_bool_and([wolf[10], BOOL____00683, BOOL____00557], BOOL____00685) :: defines_var(BOOL____00685);\n\
constraint array_bool_and([wolf[11], BOOL____00683, BOOL____00684], BOOL____00686) :: defines_var(BOOL____00686);\n\
constraint array_bool_and([wolf[12], BOOL____00557, BOOL____00684], BOOL____00687) :: defines_var(BOOL____00687);\n\
constraint array_bool_and([wolf[13], BOOL____00688, BOOL____00564], BOOL____00690) :: defines_var(BOOL____00690);\n\
constraint array_bool_and([wolf[14], BOOL____00688, BOOL____00689], BOOL____00691) :: defines_var(BOOL____00691);\n\
constraint array_bool_and([wolf[15], BOOL____00564, BOOL____00689], BOOL____00692) :: defines_var(BOOL____00692);\n\
constraint array_bool_and([wolf[16], BOOL____00693, BOOL____00571], BOOL____00695) :: defines_var(BOOL____00695);\n\
constraint array_bool_and([wolf[17], BOOL____00693, BOOL____00694], BOOL____00696) :: defines_var(BOOL____00696);\n\
constraint array_bool_and([wolf[18], BOOL____00571, BOOL____00694], BOOL____00697) :: defines_var(BOOL____00697);\n\
constraint array_bool_and([wolf[19], BOOL____00698, BOOL____00578], BOOL____00700) :: defines_var(BOOL____00700);\n\
constraint array_bool_and([wolf[20], BOOL____00698, BOOL____00699], BOOL____00701) :: defines_var(BOOL____00701);\n\
constraint array_bool_and([wolf[21], BOOL____00578, BOOL____00699], BOOL____00702) :: defines_var(BOOL____00702);\n\
constraint array_bool_and([wolf[22], BOOL____00703, BOOL____00585], BOOL____00705) :: defines_var(BOOL____00705);\n\
constraint array_bool_and([wolf[23], BOOL____00703, BOOL____00704], BOOL____00706) :: defines_var(BOOL____00706);\n\
constraint array_bool_and([wolf[24], BOOL____00585, BOOL____00704], BOOL____00707) :: defines_var(BOOL____00707);\n\
constraint array_bool_and([wolf[25], BOOL____00708, BOOL____00592], BOOL____00710) :: defines_var(BOOL____00710);\n\
constraint array_bool_and([wolf[26], BOOL____00708, BOOL____00709], BOOL____00711) :: defines_var(BOOL____00711);\n\
constraint array_bool_and([wolf[27], BOOL____00592, BOOL____00709], BOOL____00712) :: defines_var(BOOL____00712);\n\
constraint array_bool_and([wolf[28], BOOL____00713, BOOL____00599], BOOL____00715) :: defines_var(BOOL____00715);\n\
constraint array_bool_and([wolf[29], BOOL____00713, BOOL____00714], BOOL____00716) :: defines_var(BOOL____00716);\n\
constraint array_bool_and([wolf[30], BOOL____00599, BOOL____00714], BOOL____00717) :: defines_var(BOOL____00717);\n\
constraint array_bool_and([wolf[31], BOOL____00718, BOOL____00606], BOOL____00720) :: defines_var(BOOL____00720);\n\
constraint array_bool_and([wolf[32], BOOL____00718, BOOL____00719], BOOL____00721) :: defines_var(BOOL____00721);\n\
constraint array_bool_and([wolf[33], BOOL____00606, BOOL____00719], BOOL____00722) :: defines_var(BOOL____00722);\n\
constraint array_bool_and([wolf[34], BOOL____00723, BOOL____00613], BOOL____00725) :: defines_var(BOOL____00725);\n\
constraint array_bool_and([wolf[35], BOOL____00723, BOOL____00724], BOOL____00726) :: defines_var(BOOL____00726);\n\
constraint array_bool_and([wolf[36], BOOL____00613, BOOL____00724], BOOL____00727) :: defines_var(BOOL____00727);\n\
constraint array_bool_and([wolf[37], BOOL____00728, BOOL____00620], BOOL____00730) :: defines_var(BOOL____00730);\n\
constraint array_bool_and([wolf[38], BOOL____00728, BOOL____00729], BOOL____00731) :: defines_var(BOOL____00731);\n\
constraint array_bool_and([wolf[39], BOOL____00620, BOOL____00729], BOOL____00732) :: defines_var(BOOL____00732);\n\
constraint array_bool_and([wolf[40], BOOL____00733, BOOL____00627], BOOL____00735) :: defines_var(BOOL____00735);\n\
constraint array_bool_and([wolf[41], BOOL____00733, BOOL____00734], BOOL____00736) :: defines_var(BOOL____00736);\n\
constraint array_bool_and([wolf[42], BOOL____00627, BOOL____00734], BOOL____00737) :: defines_var(BOOL____00737);\n\
constraint array_bool_and([wolf[43], BOOL____00738, BOOL____00634], BOOL____00740) :: defines_var(BOOL____00740);\n\
constraint array_bool_and([wolf[44], BOOL____00738, BOOL____00739], BOOL____00741) :: defines_var(BOOL____00741);\n\
constraint array_bool_and([wolf[45], BOOL____00634, BOOL____00739], BOOL____00742) :: defines_var(BOOL____00742);\n\
constraint array_bool_and([wolf[46], BOOL____00743, BOOL____00641], BOOL____00745) :: defines_var(BOOL____00745);\n\
constraint array_bool_and([wolf[47], BOOL____00743, BOOL____00744], BOOL____00746) :: defines_var(BOOL____00746);\n\
constraint array_bool_and([wolf[48], BOOL____00641, BOOL____00744], BOOL____00747) :: defines_var(BOOL____00747);\n\
constraint array_bool_and([wolf[49], BOOL____00748, BOOL____00648], BOOL____00750) :: defines_var(BOOL____00750);\n\
constraint array_bool_and([wolf[50], BOOL____00748, BOOL____00749], BOOL____00751) :: defines_var(BOOL____00751);\n\
constraint array_bool_and([wolf[51], BOOL____00648, BOOL____00749], BOOL____00752) :: defines_var(BOOL____00752);\n\
constraint array_bool_and([wolf[52], BOOL____00753, BOOL____00655], BOOL____00755) :: defines_var(BOOL____00755);\n\
constraint array_bool_and([wolf[53], BOOL____00753, BOOL____00754], BOOL____00756) :: defines_var(BOOL____00756);\n\
constraint array_bool_and([wolf[54], BOOL____00655, BOOL____00754], BOOL____00757) :: defines_var(BOOL____00757);\n\
constraint array_bool_and([wolf[55], BOOL____00758, BOOL____00662], BOOL____00760) :: defines_var(BOOL____00760);\n\
constraint array_bool_and([wolf[56], BOOL____00758, BOOL____00759], BOOL____00761) :: defines_var(BOOL____00761);\n\
constraint array_bool_and([wolf[57], BOOL____00662, BOOL____00759], BOOL____00762) :: defines_var(BOOL____00762);\n\
constraint array_bool_and([wolf[58], BOOL____00764, BOOL____00763], BOOL____00766) :: defines_var(BOOL____00766);\n\
constraint array_bool_and([wolf[59], BOOL____00764, BOOL____00765], BOOL____00767) :: defines_var(BOOL____00767);\n\
constraint array_bool_and([wolf[60], BOOL____00763, BOOL____00765], BOOL____00768) :: defines_var(BOOL____00768);\n\
constraint array_bool_and([BOOL____00013, BOOL____00536, BOOL____00001, BOOL____00535, BOOL____00185, farmer[5], BOOL____00363], BOOL____00537) :: defines_var(BOOL____00537);\n\
constraint array_bool_and([BOOL____00013, BOOL____00540, BOOL____00001, BOOL____00539, BOOL____00538, farmer[5], BOOL____00363], BOOL____00541) :: defines_var(BOOL____00541);\n\
constraint array_bool_and([BOOL____00013, BOOL____00543, BOOL____00001, BOOL____00542, BOOL____00185, farmer[5], BOOL____00538], BOOL____00544) :: defines_var(BOOL____00544);\n\
constraint array_bool_and([BOOL____00019, BOOL____00546, BOOL____00007, BOOL____00545, BOOL____00191, farmer[8], BOOL____00369], BOOL____00547) :: defines_var(BOOL____00547);\n\
constraint array_bool_and([BOOL____00019, BOOL____00550, BOOL____00007, BOOL____00549, BOOL____00548, farmer[8], BOOL____00369], BOOL____00551) :: defines_var(BOOL____00551);\n\
constraint array_bool_and([BOOL____00019, BOOL____00553, BOOL____00007, BOOL____00552, BOOL____00191, farmer[8], BOOL____00548], BOOL____00554) :: defines_var(BOOL____00554);\n\
constraint array_bool_and([BOOL____00025, BOOL____00555, BOOL____00013, BOOL____00536, BOOL____00197, farmer[11], BOOL____00375], BOOL____00556) :: defines_var(BOOL____00556);\n\
constraint array_bool_and([BOOL____00025, BOOL____00558, BOOL____00013, BOOL____00540, BOOL____00557, farmer[11], BOOL____00375], BOOL____00559) :: defines_var(BOOL____00559);\n\
constraint array_bool_and([BOOL____00025, BOOL____00560, BOOL____00013, BOOL____00543, BOOL____00197, farmer[11], BOOL____00557], BOOL____00561) :: defines_var(BOOL____00561);\n\
constraint array_bool_and([BOOL____00031, BOOL____00562, BOOL____00019, BOOL____00546, BOOL____00203, farmer[14], BOOL____00381], BOOL____00563) :: defines_var(BOOL____00563);\n\
constraint array_bool_and([BOOL____00031, BOOL____00565, BOOL____00019, BOOL____00550, BOOL____00564, farmer[14], BOOL____00381], BOOL____00566) :: defines_var(BOOL____00566);\n\
constraint array_bool_and([BOOL____00031, BOOL____00567, BOOL____00019, BOOL____00553, BOOL____00203, farmer[14], BOOL____00564], BOOL____00568) :: defines_var(BOOL____00568);\n\
constraint array_bool_and([BOOL____00037, BOOL____00569, BOOL____00025, BOOL____00555, BOOL____00209, farmer[17], BOOL____00387], BOOL____00570) :: defines_var(BOOL____00570);\n\
constraint array_bool_and([BOOL____00037, BOOL____00572, BOOL____00025, BOOL____00558, BOOL____00571, farmer[17], BOOL____00387], BOOL____00573) :: defines_var(BOOL____00573);\n\
constraint array_bool_and([BOOL____00037, BOOL____00574, BOOL____00025, BOOL____00560, BOOL____00209, farmer[17], BOOL____00571], BOOL____00575) :: defines_var(BOOL____00575);\n\
constraint array_bool_and([BOOL____00043, BOOL____00576, BOOL____00031, BOOL____00562, BOOL____00215, farmer[20], BOOL____00393], BOOL____00577) :: defines_var(BOOL____00577);\n\
constraint array_bool_and([BOOL____00043, BOOL____00579, BOOL____00031, BOOL____00565, BOOL____00578, farmer[20], BOOL____00393], BOOL____00580) :: defines_var(BOOL____00580);\n\
constraint array_bool_and([BOOL____00043, BOOL____00581, BOOL____00031, BOOL____00567, BOOL____00215, farmer[20], BOOL____00578], BOOL____00582) :: defines_var(BOOL____00582);\n\
constraint array_bool_and([BOOL____00049, BOOL____00583, BOOL____00037, BOOL____00569, BOOL____00221, farmer[23], BOOL____00399], BOOL____00584) :: defines_var(BOOL____00584);\n\
constraint array_bool_and([BOOL____00049, BOOL____00586, BOOL____00037, BOOL____00572, BOOL____00585, farmer[23], BOOL____00399], BOOL____00587) :: defines_var(BOOL____00587);\n\
constraint array_bool_and([BOOL____00049, BOOL____00588, BOOL____00037, BOOL____00574, BOOL____00221, farmer[23], BOOL____00585], BOOL____00589) :: defines_var(BOOL____00589);\n\
constraint array_bool_and([BOOL____00055, BOOL____00590, BOOL____00043, BOOL____00576, BOOL____00227, farmer[26], BOOL____00405], BOOL____00591) :: defines_var(BOOL____00591);\n\
constraint array_bool_and([BOOL____00055, BOOL____00593, BOOL____00043, BOOL____00579, BOOL____00592, farmer[26], BOOL____00405], BOOL____00594) :: defines_var(BOOL____00594);\n\
constraint array_bool_and([BOOL____00055, BOOL____00595, BOOL____00043, BOOL____00581, BOOL____00227, farmer[26], BOOL____00592], BOOL____00596) :: defines_var(BOOL____00596);\n\
constraint array_bool_and([BOOL____00061, BOOL____00597, BOOL____00049, BOOL____00583, BOOL____00233, farmer[29], BOOL____00411], BOOL____00598) :: defines_var(BOOL____00598);\n\
constraint array_bool_and([BOOL____00061, BOOL____00600, BOOL____00049, BOOL____00586, BOOL____00599, farmer[29], BOOL____00411], BOOL____00601) :: defines_var(BOOL____00601);\n\
constraint array_bool_and([BOOL____00061, BOOL____00602, BOOL____00049, BOOL____00588, BOOL____00233, farmer[29], BOOL____00599], BOOL____00603) :: defines_var(BOOL____00603);\n\
constraint array_bool_and([BOOL____00067, BOOL____00604, BOOL____00055, BOOL____00590, BOOL____00239, farmer[32], BOOL____00417], BOOL____00605) :: defines_var(BOOL____00605);\n\
constraint array_bool_and([BOOL____00067, BOOL____00607, BOOL____00055, BOOL____00593, BOOL____00606, farmer[32], BOOL____00417], BOOL____00608) :: defines_var(BOOL____00608);\n\
constraint array_bool_and([BOOL____00067, BOOL____00609, BOOL____00055, BOOL____00595, BOOL____00239, farmer[32], BOOL____00606], BOOL____00610) :: defines_var(BOOL____00610);\n\
constraint array_bool_and([BOOL____00073, BOOL____00611, BOOL____00061, BOOL____00597, BOOL____00245, farmer[35], BOOL____00423], BOOL____00612) :: defines_var(BOOL____00612);\n\
constraint array_bool_and([BOOL____00073, BOOL____00614, BOOL____00061, BOOL____00600, BOOL____00613, farmer[35], BOOL____00423], BOOL____00615) :: defines_var(BOOL____00615);\n\
constraint array_bool_and([BOOL____00073, BOOL____00616, BOOL____00061, BOOL____00602, BOOL____00245, farmer[35], BOOL____00613], BOOL____00617) :: defines_var(BOOL____00617);\n\
constraint array_bool_and([BOOL____00079, BOOL____00618, BOOL____00067, BOOL____00604, BOOL____00251, farmer[38], BOOL____00429], BOOL____00619) :: defines_var(BOOL____00619);\n\
constraint array_bool_and([BOOL____00079, BOOL____00621, BOOL____00067, BOOL____00607, BOOL____00620, farmer[38], BOOL____00429], BOOL____00622) :: defines_var(BOOL____00622);\n\
constraint array_bool_and([BOOL____00079, BOOL____00623, BOOL____00067, BOOL____00609, BOOL____00251, farmer[38], BOOL____00620], BOOL____00624) :: defines_var(BOOL____00624);\n\
constraint array_bool_and([BOOL____00085, BOOL____00625, BOOL____00073, BOOL____00611, BOOL____00257, farmer[41], BOOL____00435], BOOL____00626) :: defines_var(BOOL____00626);\n\
constraint array_bool_and([BOOL____00085, BOOL____00628, BOOL____00073, BOOL____00614, BOOL____00627, farmer[41], BOOL____00435], BOOL____00629) :: defines_var(BOOL____00629);\n\
constraint array_bool_and([BOOL____00085, BOOL____00630, BOOL____00073, BOOL____00616, BOOL____00257, farmer[41], BOOL____00627], BOOL____00631) :: defines_var(BOOL____00631);\n\
constraint array_bool_and([BOOL____00091, BOOL____00632, BOOL____00079, BOOL____00618, BOOL____00263, farmer[44], BOOL____00441], BOOL____00633) :: defines_var(BOOL____00633);\n\
constraint array_bool_and([BOOL____00091, BOOL____00635, BOOL____00079, BOOL____00621, BOOL____00634, farmer[44], BOOL____00441], BOOL____00636) :: defines_var(BOOL____00636);\n\
constraint array_bool_and([BOOL____00091, BOOL____00637, BOOL____00079, BOOL____00623, BOOL____00263, farmer[44], BOOL____00634], BOOL____00638) :: defines_var(BOOL____00638);\n\
constraint array_bool_and([BOOL____00097, BOOL____00639, BOOL____00085, BOOL____00625, BOOL____00269, farmer[47], BOOL____00447], BOOL____00640) :: defines_var(BOOL____00640);\n\
constraint array_bool_and([BOOL____00097, BOOL____00642, BOOL____00085, BOOL____00628, BOOL____00641, farmer[47], BOOL____00447], BOOL____00643) :: defines_var(BOOL____00643);\n\
constraint array_bool_and([BOOL____00097, BOOL____00644, BOOL____00085, BOOL____00630, BOOL____00269, farmer[47], BOOL____00641], BOOL____00645) :: defines_var(BOOL____00645);\n\
constraint array_bool_and([BOOL____00103, BOOL____00646, BOOL____00091, BOOL____00632, BOOL____00275, farmer[50], BOOL____00453], BOOL____00647) :: defines_var(BOOL____00647);\n\
constraint array_bool_and([BOOL____00103, BOOL____00649, BOOL____00091, BOOL____00635, BOOL____00648, farmer[50], BOOL____00453], BOOL____00650) :: defines_var(BOOL____00650);\n\
constraint array_bool_and([BOOL____00103, BOOL____00651, BOOL____00091, BOOL____00637, BOOL____00275, farmer[50], BOOL____00648], BOOL____00652) :: defines_var(BOOL____00652);\n\
constraint array_bool_and([BOOL____00109, BOOL____00653, BOOL____00097, BOOL____00639, BOOL____00281, farmer[53], BOOL____00459], BOOL____00654) :: defines_var(BOOL____00654);\n\
constraint array_bool_and([BOOL____00109, BOOL____00656, BOOL____00097, BOOL____00642, BOOL____00655, farmer[53], BOOL____00459], BOOL____00657) :: defines_var(BOOL____00657);\n\
constraint array_bool_and([BOOL____00109, BOOL____00658, BOOL____00097, BOOL____00644, BOOL____00281, farmer[53], BOOL____00655], BOOL____00659) :: defines_var(BOOL____00659);\n\
constraint array_bool_and([BOOL____00115, BOOL____00660, BOOL____00103, BOOL____00646, BOOL____00287, farmer[56], BOOL____00465], BOOL____00661) :: defines_var(BOOL____00661);\n\
constraint array_bool_and([BOOL____00115, BOOL____00663, BOOL____00103, BOOL____00649, BOOL____00662, farmer[56], BOOL____00465], BOOL____00664) :: defines_var(BOOL____00664);\n\
constraint array_bool_and([BOOL____00115, BOOL____00665, BOOL____00103, BOOL____00651, BOOL____00287, farmer[56], BOOL____00662], BOOL____00666) :: defines_var(BOOL____00666);\n\
constraint array_bool_or([BOOL____00006, BOOL____00004, BOOL____00005], true);\n\
constraint array_bool_or([BOOL____00012, BOOL____00010, BOOL____00011], true);\n\
constraint array_bool_or([BOOL____00018, BOOL____00016, BOOL____00017], true);\n\
constraint array_bool_or([BOOL____00024, BOOL____00022, BOOL____00023], true);\n\
constraint array_bool_or([BOOL____00030, BOOL____00028, BOOL____00029], true);\n\
constraint array_bool_or([BOOL____00036, BOOL____00034, BOOL____00035], true);\n\
constraint array_bool_or([BOOL____00042, BOOL____00040, BOOL____00041], true);\n\
constraint array_bool_or([BOOL____00048, BOOL____00046, BOOL____00047], true);\n\
constraint array_bool_or([BOOL____00054, BOOL____00052, BOOL____00053], true);\n\
constraint array_bool_or([BOOL____00060, BOOL____00058, BOOL____00059], true);\n\
constraint array_bool_or([BOOL____00066, BOOL____00064, BOOL____00065], true);\n\
constraint array_bool_or([BOOL____00072, BOOL____00070, BOOL____00071], true);\n\
constraint array_bool_or([BOOL____00078, BOOL____00076, BOOL____00077], true);\n\
constraint array_bool_or([BOOL____00084, BOOL____00082, BOOL____00083], true);\n\
constraint array_bool_or([BOOL____00090, BOOL____00088, BOOL____00089], true);\n\
constraint array_bool_or([BOOL____00096, BOOL____00094, BOOL____00095], true);\n\
constraint array_bool_or([BOOL____00102, BOOL____00100, BOOL____00101], true);\n\
constraint array_bool_or([BOOL____00108, BOOL____00106, BOOL____00107], true);\n\
constraint array_bool_or([BOOL____00114, BOOL____00112, BOOL____00113], true);\n\
constraint array_bool_or([BOOL____00120, BOOL____00118, BOOL____00119], true);\n\
constraint array_bool_or([BOOL____00184, BOOL____00182, BOOL____00183], true);\n\
constraint array_bool_or([BOOL____00190, BOOL____00188, BOOL____00189], true);\n\
constraint array_bool_or([BOOL____00196, BOOL____00194, BOOL____00195], true);\n\
constraint array_bool_or([BOOL____00202, BOOL____00200, BOOL____00201], true);\n\
constraint array_bool_or([BOOL____00208, BOOL____00206, BOOL____00207], true);\n\
constraint array_bool_or([BOOL____00214, BOOL____00212, BOOL____00213], true);\n\
constraint array_bool_or([BOOL____00220, BOOL____00218, BOOL____00219], true);\n\
constraint array_bool_or([BOOL____00226, BOOL____00224, BOOL____00225], true);\n\
constraint array_bool_or([BOOL____00232, BOOL____00230, BOOL____00231], true);\n\
constraint array_bool_or([BOOL____00238, BOOL____00236, BOOL____00237], true);\n\
constraint array_bool_or([BOOL____00244, BOOL____00242, BOOL____00243], true);\n\
constraint array_bool_or([BOOL____00250, BOOL____00248, BOOL____00249], true);\n\
constraint array_bool_or([BOOL____00256, BOOL____00254, BOOL____00255], true);\n\
constraint array_bool_or([BOOL____00262, BOOL____00260, BOOL____00261], true);\n\
constraint array_bool_or([BOOL____00268, BOOL____00266, BOOL____00267], true);\n\
constraint array_bool_or([BOOL____00274, BOOL____00272, BOOL____00273], true);\n\
constraint array_bool_or([BOOL____00280, BOOL____00278, BOOL____00279], true);\n\
constraint array_bool_or([BOOL____00286, BOOL____00284, BOOL____00285], true);\n\
constraint array_bool_or([BOOL____00292, BOOL____00290, BOOL____00291], true);\n\
constraint array_bool_or([BOOL____00298, BOOL____00296, BOOL____00297], true);\n\
constraint array_bool_or([BOOL____00362, BOOL____00360, BOOL____00361], true);\n\
constraint array_bool_or([BOOL____00368, BOOL____00366, BOOL____00367], true);\n\
constraint array_bool_or([BOOL____00374, BOOL____00372, BOOL____00373], true);\n\
constraint array_bool_or([BOOL____00380, BOOL____00378, BOOL____00379], true);\n\
constraint array_bool_or([BOOL____00386, BOOL____00384, BOOL____00385], true);\n\
constraint array_bool_or([BOOL____00392, BOOL____00390, BOOL____00391], true);\n\
constraint array_bool_or([BOOL____00398, BOOL____00396, BOOL____00397], true);\n\
constraint array_bool_or([BOOL____00404, BOOL____00402, BOOL____00403], true);\n\
constraint array_bool_or([BOOL____00410, BOOL____00408, BOOL____00409], true);\n\
constraint array_bool_or([BOOL____00416, BOOL____00414, BOOL____00415], true);\n\
constraint array_bool_or([BOOL____00422, BOOL____00420, BOOL____00421], true);\n\
constraint array_bool_or([BOOL____00428, BOOL____00426, BOOL____00427], true);\n\
constraint array_bool_or([BOOL____00434, BOOL____00432, BOOL____00433], true);\n\
constraint array_bool_or([BOOL____00440, BOOL____00438, BOOL____00439], true);\n\
constraint array_bool_or([BOOL____00446, BOOL____00444, BOOL____00445], true);\n\
constraint array_bool_or([BOOL____00452, BOOL____00450, BOOL____00451], true);\n\
constraint array_bool_or([BOOL____00458, BOOL____00456, BOOL____00457], true);\n\
constraint array_bool_or([BOOL____00464, BOOL____00462, BOOL____00463], true);\n\
constraint array_bool_or([BOOL____00470, BOOL____00468, BOOL____00469], true);\n\
constraint array_bool_or([BOOL____00476, BOOL____00474, BOOL____00475], true);\n\
constraint array_bool_or([BOOL____00672, BOOL____00670, BOOL____00671], true);\n\
constraint array_bool_or([BOOL____00677, BOOL____00675, BOOL____00676], true);\n\
constraint array_bool_or([BOOL____00682, BOOL____00680, BOOL____00681], true);\n\
constraint array_bool_or([BOOL____00687, BOOL____00685, BOOL____00686], true);\n\
constraint array_bool_or([BOOL____00692, BOOL____00690, BOOL____00691], true);\n\
constraint array_bool_or([BOOL____00697, BOOL____00695, BOOL____00696], true);\n\
constraint array_bool_or([BOOL____00702, BOOL____00700, BOOL____00701], true);\n\
constraint array_bool_or([BOOL____00707, BOOL____00705, BOOL____00706], true);\n\
constraint array_bool_or([BOOL____00712, BOOL____00710, BOOL____00711], true);\n\
constraint array_bool_or([BOOL____00717, BOOL____00715, BOOL____00716], true);\n\
constraint array_bool_or([BOOL____00722, BOOL____00720, BOOL____00721], true);\n\
constraint array_bool_or([BOOL____00727, BOOL____00725, BOOL____00726], true);\n\
constraint array_bool_or([BOOL____00732, BOOL____00730, BOOL____00731], true);\n\
constraint array_bool_or([BOOL____00737, BOOL____00735, BOOL____00736], true);\n\
constraint array_bool_or([BOOL____00742, BOOL____00740, BOOL____00741], true);\n\
constraint array_bool_or([BOOL____00747, BOOL____00745, BOOL____00746], true);\n\
constraint array_bool_or([BOOL____00752, BOOL____00750, BOOL____00751], true);\n\
constraint array_bool_or([BOOL____00757, BOOL____00755, BOOL____00756], true);\n\
constraint array_bool_or([BOOL____00762, BOOL____00760, BOOL____00761], true);\n\
constraint array_bool_or([BOOL____00768, BOOL____00766, BOOL____00767], true);\n\
constraint bool_eq(cabbage[3], true);\n\
constraint bool_eq(cabbage[58], true);\n\
constraint bool_eq(goat[3], true);\n\
constraint bool_eq(goat[58], true);\n\
constraint bool_eq(wolf[3], true);\n\
constraint bool_eq(wolf[58], true);\n\
constraint bool_eq_reif(cabbage[1], false, BOOL____00181) :: defines_var(BOOL____00181);\n\
constraint bool_eq_reif(cabbage[2], false, BOOL____00179) :: defines_var(BOOL____00179);\n\
constraint bool_eq_reif(cabbage[3], false, BOOL____00180) :: defines_var(BOOL____00180);\n\
constraint bool_eq_reif(cabbage[3], farmer[3], BOOL____00539) :: defines_var(BOOL____00539);\n\
constraint bool_eq_reif(cabbage[4], false, BOOL____00187) :: defines_var(BOOL____00187);\n\
constraint bool_eq_reif(cabbage[5], false, BOOL____00185) :: defines_var(BOOL____00185);\n\
constraint bool_eq_reif(cabbage[6], false, BOOL____00186) :: defines_var(BOOL____00186);\n\
constraint bool_eq_reif(cabbage[6], farmer[6], BOOL____00549) :: defines_var(BOOL____00549);\n\
constraint bool_eq_reif(cabbage[7], false, BOOL____00193) :: defines_var(BOOL____00193);\n\
constraint bool_eq_reif(cabbage[8], false, BOOL____00191) :: defines_var(BOOL____00191);\n\
constraint bool_eq_reif(cabbage[9], false, BOOL____00192) :: defines_var(BOOL____00192);\n\
constraint bool_eq_reif(cabbage[9], farmer[9], BOOL____00540) :: defines_var(BOOL____00540);\n\
constraint bool_eq_reif(cabbage[10], false, BOOL____00199) :: defines_var(BOOL____00199);\n\
constraint bool_eq_reif(cabbage[11], false, BOOL____00197) :: defines_var(BOOL____00197);\n\
constraint bool_eq_reif(cabbage[12], false, BOOL____00198) :: defines_var(BOOL____00198);\n\
constraint bool_eq_reif(cabbage[12], farmer[12], BOOL____00550) :: defines_var(BOOL____00550);\n\
constraint bool_eq_reif(cabbage[13], false, BOOL____00205) :: defines_var(BOOL____00205);\n\
constraint bool_eq_reif(cabbage[14], false, BOOL____00203) :: defines_var(BOOL____00203);\n\
constraint bool_eq_reif(cabbage[15], false, BOOL____00204) :: defines_var(BOOL____00204);\n\
constraint bool_eq_reif(cabbage[15], farmer[15], BOOL____00558) :: defines_var(BOOL____00558);\n\
constraint bool_eq_reif(cabbage[16], false, BOOL____00211) :: defines_var(BOOL____00211);\n\
constraint bool_eq_reif(cabbage[17], false, BOOL____00209) :: defines_var(BOOL____00209);\n\
constraint bool_eq_reif(cabbage[18], false, BOOL____00210) :: defines_var(BOOL____00210);\n\
constraint bool_eq_reif(cabbage[18], farmer[18], BOOL____00565) :: defines_var(BOOL____00565);\n\
constraint bool_eq_reif(cabbage[19], false, BOOL____00217) :: defines_var(BOOL____00217);\n\
constraint bool_eq_reif(cabbage[20], false, BOOL____00215) :: defines_var(BOOL____00215);\n\
constraint bool_eq_reif(cabbage[21], false, BOOL____00216) :: defines_var(BOOL____00216);\n\
constraint bool_eq_reif(cabbage[21], farmer[21], BOOL____00572) :: defines_var(BOOL____00572);\n\
constraint bool_eq_reif(cabbage[22], false, BOOL____00223) :: defines_var(BOOL____00223);\n\
constraint bool_eq_reif(cabbage[23], false, BOOL____00221) :: defines_var(BOOL____00221);\n\
constraint bool_eq_reif(cabbage[24], false, BOOL____00222) :: defines_var(BOOL____00222);\n\
constraint bool_eq_reif(cabbage[24], farmer[24], BOOL____00579) :: defines_var(BOOL____00579);\n\
constraint bool_eq_reif(cabbage[25], false, BOOL____00229) :: defines_var(BOOL____00229);\n\
constraint bool_eq_reif(cabbage[26], false, BOOL____00227) :: defines_var(BOOL____00227);\n\
constraint bool_eq_reif(cabbage[27], false, BOOL____00228) :: defines_var(BOOL____00228);\n\
constraint bool_eq_reif(cabbage[27], farmer[27], BOOL____00586) :: defines_var(BOOL____00586);\n\
constraint bool_eq_reif(cabbage[28], false, BOOL____00235) :: defines_var(BOOL____00235);\n\
constraint bool_eq_reif(cabbage[29], false, BOOL____00233) :: defines_var(BOOL____00233);\n\
constraint bool_eq_reif(cabbage[30], false, BOOL____00234) :: defines_var(BOOL____00234);\n\
constraint bool_eq_reif(cabbage[30], farmer[30], BOOL____00593) :: defines_var(BOOL____00593);\n\
constraint bool_eq_reif(cabbage[31], false, BOOL____00241) :: defines_var(BOOL____00241);\n\
constraint bool_eq_reif(cabbage[32], false, BOOL____00239) :: defines_var(BOOL____00239);\n\
constraint bool_eq_reif(cabbage[33], false, BOOL____00240) :: defines_var(BOOL____00240);\n\
constraint bool_eq_reif(cabbage[33], farmer[33], BOOL____00600) :: defines_var(BOOL____00600);\n\
constraint bool_eq_reif(cabbage[34], false, BOOL____00247) :: defines_var(BOOL____00247);\n\
constraint bool_eq_reif(cabbage[35], false, BOOL____00245) :: defines_var(BOOL____00245);\n\
constraint bool_eq_reif(cabbage[36], false, BOOL____00246) :: defines_var(BOOL____00246);\n\
constraint bool_eq_reif(cabbage[36], farmer[36], BOOL____00607) :: defines_var(BOOL____00607);\n\
constraint bool_eq_reif(cabbage[37], false, BOOL____00253) :: defines_var(BOOL____00253);\n\
constraint bool_eq_reif(cabbage[38], false, BOOL____00251) :: defines_var(BOOL____00251);\n\
constraint bool_eq_reif(cabbage[39], false, BOOL____00252) :: defines_var(BOOL____00252);\n\
constraint bool_eq_reif(cabbage[39], farmer[39], BOOL____00614) :: defines_var(BOOL____00614);\n\
constraint bool_eq_reif(cabbage[40], false, BOOL____00259) :: defines_var(BOOL____00259);\n\
constraint bool_eq_reif(cabbage[41], false, BOOL____00257) :: defines_var(BOOL____00257);\n\
constraint bool_eq_reif(cabbage[42], false, BOOL____00258) :: defines_var(BOOL____00258);\n\
constraint bool_eq_reif(cabbage[42], farmer[42], BOOL____00621) :: defines_var(BOOL____00621);\n\
constraint bool_eq_reif(cabbage[43], false, BOOL____00265) :: defines_var(BOOL____00265);\n\
constraint bool_eq_reif(cabbage[44], false, BOOL____00263) :: defines_var(BOOL____00263);\n\
constraint bool_eq_reif(cabbage[45], false, BOOL____00264) :: defines_var(BOOL____00264);\n\
constraint bool_eq_reif(cabbage[45], farmer[45], BOOL____00628) :: defines_var(BOOL____00628);\n\
constraint bool_eq_reif(cabbage[46], false, BOOL____00271) :: defines_var(BOOL____00271);\n\
constraint bool_eq_reif(cabbage[47], false, BOOL____00269) :: defines_var(BOOL____00269);\n\
constraint bool_eq_reif(cabbage[48], false, BOOL____00270) :: defines_var(BOOL____00270);\n\
constraint bool_eq_reif(cabbage[48], farmer[48], BOOL____00635) :: defines_var(BOOL____00635);\n\
constraint bool_eq_reif(cabbage[49], false, BOOL____00277) :: defines_var(BOOL____00277);\n\
constraint bool_eq_reif(cabbage[50], false, BOOL____00275) :: defines_var(BOOL____00275);\n\
constraint bool_eq_reif(cabbage[51], false, BOOL____00276) :: defines_var(BOOL____00276);\n\
constraint bool_eq_reif(cabbage[51], farmer[51], BOOL____00642) :: defines_var(BOOL____00642);\n\
constraint bool_eq_reif(cabbage[52], false, BOOL____00283) :: defines_var(BOOL____00283);\n\
constraint bool_eq_reif(cabbage[53], false, BOOL____00281) :: defines_var(BOOL____00281);\n\
constraint bool_eq_reif(cabbage[54], false, BOOL____00282) :: defines_var(BOOL____00282);\n\
constraint bool_eq_reif(cabbage[54], farmer[54], BOOL____00649) :: defines_var(BOOL____00649);\n\
constraint bool_eq_reif(cabbage[55], false, BOOL____00289) :: defines_var(BOOL____00289);\n\
constraint bool_eq_reif(cabbage[56], false, BOOL____00287) :: defines_var(BOOL____00287);\n\
constraint bool_eq_reif(cabbage[57], false, BOOL____00288) :: defines_var(BOOL____00288);\n\
constraint bool_eq_reif(cabbage[57], farmer[57], BOOL____00656) :: defines_var(BOOL____00656);\n\
constraint bool_eq_reif(cabbage[58], false, BOOL____00295) :: defines_var(BOOL____00295);\n\
constraint bool_eq_reif(cabbage[59], false, BOOL____00293) :: defines_var(BOOL____00293);\n\
constraint bool_eq_reif(cabbage[60], false, BOOL____00294) :: defines_var(BOOL____00294);\n\
constraint bool_eq_reif(cabbage[60], farmer[60], BOOL____00663) :: defines_var(BOOL____00663);\n\
constraint bool_eq_reif(farmer[1], false, BOOL____00003) :: defines_var(BOOL____00003);\n\
constraint bool_eq_reif(farmer[2], false, BOOL____00001) :: defines_var(BOOL____00001);\n\
constraint bool_eq_reif(farmer[3], false, BOOL____00002) :: defines_var(BOOL____00002);\n\
constraint bool_eq_reif(farmer[4], false, BOOL____00009) :: defines_var(BOOL____00009);\n\
constraint bool_eq_reif(farmer[5], false, BOOL____00007) :: defines_var(BOOL____00007);\n\
constraint bool_eq_reif(farmer[6], false, BOOL____00008) :: defines_var(BOOL____00008);\n\
constraint bool_eq_reif(farmer[7], false, BOOL____00015) :: defines_var(BOOL____00015);\n\
constraint bool_eq_reif(farmer[8], false, BOOL____00013) :: defines_var(BOOL____00013);\n\
constraint bool_eq_reif(farmer[9], false, BOOL____00014) :: defines_var(BOOL____00014);\n\
constraint bool_eq_reif(farmer[10], false, BOOL____00021) :: defines_var(BOOL____00021);\n\
constraint bool_eq_reif(farmer[11], false, BOOL____00019) :: defines_var(BOOL____00019);\n\
constraint bool_eq_reif(farmer[12], false, BOOL____00020) :: defines_var(BOOL____00020);\n\
constraint bool_eq_reif(farmer[13], false, BOOL____00027) :: defines_var(BOOL____00027);\n\
constraint bool_eq_reif(farmer[14], false, BOOL____00025) :: defines_var(BOOL____00025);\n\
constraint bool_eq_reif(farmer[15], false, BOOL____00026) :: defines_var(BOOL____00026);\n\
constraint bool_eq_reif(farmer[16], false, BOOL____00033) :: defines_var(BOOL____00033);\n\
constraint bool_eq_reif(farmer[17], false, BOOL____00031) :: defines_var(BOOL____00031);\n\
constraint bool_eq_reif(farmer[18], false, BOOL____00032) :: defines_var(BOOL____00032);\n\
constraint bool_eq_reif(farmer[19], false, BOOL____00039) :: defines_var(BOOL____00039);\n\
constraint bool_eq_reif(farmer[20], false, BOOL____00037) :: defines_var(BOOL____00037);\n\
constraint bool_eq_reif(farmer[21], false, BOOL____00038) :: defines_var(BOOL____00038);\n\
constraint bool_eq_reif(farmer[22], false, BOOL____00045) :: defines_var(BOOL____00045);\n\
constraint bool_eq_reif(farmer[23], false, BOOL____00043) :: defines_var(BOOL____00043);\n\
constraint bool_eq_reif(farmer[24], false, BOOL____00044) :: defines_var(BOOL____00044);\n\
constraint bool_eq_reif(farmer[25], false, BOOL____00051) :: defines_var(BOOL____00051);\n\
constraint bool_eq_reif(farmer[26], false, BOOL____00049) :: defines_var(BOOL____00049);\n\
constraint bool_eq_reif(farmer[27], false, BOOL____00050) :: defines_var(BOOL____00050);\n\
constraint bool_eq_reif(farmer[28], false, BOOL____00057) :: defines_var(BOOL____00057);\n\
constraint bool_eq_reif(farmer[29], false, BOOL____00055) :: defines_var(BOOL____00055);\n\
constraint bool_eq_reif(farmer[30], false, BOOL____00056) :: defines_var(BOOL____00056);\n\
constraint bool_eq_reif(farmer[31], false, BOOL____00063) :: defines_var(BOOL____00063);\n\
constraint bool_eq_reif(farmer[32], false, BOOL____00061) :: defines_var(BOOL____00061);\n\
constraint bool_eq_reif(farmer[33], false, BOOL____00062) :: defines_var(BOOL____00062);\n\
constraint bool_eq_reif(farmer[34], false, BOOL____00069) :: defines_var(BOOL____00069);\n\
constraint bool_eq_reif(farmer[35], false, BOOL____00067) :: defines_var(BOOL____00067);\n\
constraint bool_eq_reif(farmer[36], false, BOOL____00068) :: defines_var(BOOL____00068);\n\
constraint bool_eq_reif(farmer[37], false, BOOL____00075) :: defines_var(BOOL____00075);\n\
constraint bool_eq_reif(farmer[38], false, BOOL____00073) :: defines_var(BOOL____00073);\n\
constraint bool_eq_reif(farmer[39], false, BOOL____00074) :: defines_var(BOOL____00074);\n\
constraint bool_eq_reif(farmer[40], false, BOOL____00081) :: defines_var(BOOL____00081);\n\
constraint bool_eq_reif(farmer[41], false, BOOL____00079) :: defines_var(BOOL____00079);\n\
constraint bool_eq_reif(farmer[42], false, BOOL____00080) :: defines_var(BOOL____00080);\n\
constraint bool_eq_reif(farmer[43], false, BOOL____00087) :: defines_var(BOOL____00087);\n\
constraint bool_eq_reif(farmer[44], false, BOOL____00085) :: defines_var(BOOL____00085);\n\
constraint bool_eq_reif(farmer[45], false, BOOL____00086) :: defines_var(BOOL____00086);\n\
constraint bool_eq_reif(farmer[46], false, BOOL____00093) :: defines_var(BOOL____00093);\n\
constraint bool_eq_reif(farmer[47], false, BOOL____00091) :: defines_var(BOOL____00091);\n\
constraint bool_eq_reif(farmer[48], false, BOOL____00092) :: defines_var(BOOL____00092);\n\
constraint bool_eq_reif(farmer[49], false, BOOL____00099) :: defines_var(BOOL____00099);\n\
constraint bool_eq_reif(farmer[50], false, BOOL____00097) :: defines_var(BOOL____00097);\n\
constraint bool_eq_reif(farmer[51], false, BOOL____00098) :: defines_var(BOOL____00098);\n\
constraint bool_eq_reif(farmer[52], false, BOOL____00105) :: defines_var(BOOL____00105);\n\
constraint bool_eq_reif(farmer[53], false, BOOL____00103) :: defines_var(BOOL____00103);\n\
constraint bool_eq_reif(farmer[54], false, BOOL____00104) :: defines_var(BOOL____00104);\n\
constraint bool_eq_reif(farmer[55], false, BOOL____00111) :: defines_var(BOOL____00111);\n\
constraint bool_eq_reif(farmer[56], false, BOOL____00109) :: defines_var(BOOL____00109);\n\
constraint bool_eq_reif(farmer[57], false, BOOL____00110) :: defines_var(BOOL____00110);\n\
constraint bool_eq_reif(farmer[58], false, BOOL____00117) :: defines_var(BOOL____00117);\n\
constraint bool_eq_reif(farmer[59], false, BOOL____00115) :: defines_var(BOOL____00115);\n\
constraint bool_eq_reif(farmer[60], false, BOOL____00116) :: defines_var(BOOL____00116);\n\
constraint bool_eq_reif(goat[1], false, BOOL____00359) :: defines_var(BOOL____00359);\n\
constraint bool_eq_reif(goat[2], false, BOOL____00357) :: defines_var(BOOL____00357);\n\
constraint bool_eq_reif(goat[3], false, BOOL____00358) :: defines_var(BOOL____00358);\n\
constraint bool_eq_reif(goat[3], farmer[3], BOOL____00542) :: defines_var(BOOL____00542);\n\
constraint bool_eq_reif(goat[4], false, BOOL____00365) :: defines_var(BOOL____00365);\n\
constraint bool_eq_reif(goat[5], false, BOOL____00363) :: defines_var(BOOL____00363);\n\
constraint bool_eq_reif(goat[6], false, BOOL____00364) :: defines_var(BOOL____00364);\n\
constraint bool_eq_reif(goat[6], farmer[6], BOOL____00552) :: defines_var(BOOL____00552);\n\
constraint bool_eq_reif(goat[7], false, BOOL____00371) :: defines_var(BOOL____00371);\n\
constraint bool_eq_reif(goat[8], false, BOOL____00369) :: defines_var(BOOL____00369);\n\
constraint bool_eq_reif(goat[9], false, BOOL____00370) :: defines_var(BOOL____00370);\n\
constraint bool_eq_reif(goat[9], farmer[9], BOOL____00543) :: defines_var(BOOL____00543);\n\
constraint bool_eq_reif(goat[10], false, BOOL____00377) :: defines_var(BOOL____00377);\n\
constraint bool_eq_reif(goat[11], false, BOOL____00375) :: defines_var(BOOL____00375);\n\
constraint bool_eq_reif(goat[12], false, BOOL____00376) :: defines_var(BOOL____00376);\n\
constraint bool_eq_reif(goat[12], farmer[12], BOOL____00553) :: defines_var(BOOL____00553);\n\
constraint bool_eq_reif(goat[13], false, BOOL____00383) :: defines_var(BOOL____00383);\n\
constraint bool_eq_reif(goat[14], false, BOOL____00381) :: defines_var(BOOL____00381);\n\
constraint bool_eq_reif(goat[15], false, BOOL____00382) :: defines_var(BOOL____00382);\n\
constraint bool_eq_reif(goat[15], farmer[15], BOOL____00560) :: defines_var(BOOL____00560);\n\
constraint bool_eq_reif(goat[16], false, BOOL____00389) :: defines_var(BOOL____00389);\n\
constraint bool_eq_reif(goat[17], false, BOOL____00387) :: defines_var(BOOL____00387);\n\
constraint bool_eq_reif(goat[18], false, BOOL____00388) :: defines_var(BOOL____00388);\n\
constraint bool_eq_reif(goat[18], farmer[18], BOOL____00567) :: defines_var(BOOL____00567);\n\
constraint bool_eq_reif(goat[19], false, BOOL____00395) :: defines_var(BOOL____00395);\n\
constraint bool_eq_reif(goat[20], false, BOOL____00393) :: defines_var(BOOL____00393);\n\
constraint bool_eq_reif(goat[21], false, BOOL____00394) :: defines_var(BOOL____00394);\n\
constraint bool_eq_reif(goat[21], farmer[21], BOOL____00574) :: defines_var(BOOL____00574);\n\
constraint bool_eq_reif(goat[22], false, BOOL____00401) :: defines_var(BOOL____00401);\n\
constraint bool_eq_reif(goat[23], false, BOOL____00399) :: defines_var(BOOL____00399);\n\
constraint bool_eq_reif(goat[24], false, BOOL____00400) :: defines_var(BOOL____00400);\n\
constraint bool_eq_reif(goat[24], farmer[24], BOOL____00581) :: defines_var(BOOL____00581);\n\
constraint bool_eq_reif(goat[25], false, BOOL____00407) :: defines_var(BOOL____00407);\n\
constraint bool_eq_reif(goat[26], false, BOOL____00405) :: defines_var(BOOL____00405);\n\
constraint bool_eq_reif(goat[27], false, BOOL____00406) :: defines_var(BOOL____00406);\n\
constraint bool_eq_reif(goat[27], farmer[27], BOOL____00588) :: defines_var(BOOL____00588);\n\
constraint bool_eq_reif(goat[28], false, BOOL____00413) :: defines_var(BOOL____00413);\n\
constraint bool_eq_reif(goat[29], false, BOOL____00411) :: defines_var(BOOL____00411);\n\
constraint bool_eq_reif(goat[30], false, BOOL____00412) :: defines_var(BOOL____00412);\n\
constraint bool_eq_reif(goat[30], farmer[30], BOOL____00595) :: defines_var(BOOL____00595);\n\
constraint bool_eq_reif(goat[31], false, BOOL____00419) :: defines_var(BOOL____00419);\n\
constraint bool_eq_reif(goat[32], false, BOOL____00417) :: defines_var(BOOL____00417);\n\
constraint bool_eq_reif(goat[33], false, BOOL____00418) :: defines_var(BOOL____00418);\n\
constraint bool_eq_reif(goat[33], farmer[33], BOOL____00602) :: defines_var(BOOL____00602);\n\
constraint bool_eq_reif(goat[34], false, BOOL____00425) :: defines_var(BOOL____00425);\n\
constraint bool_eq_reif(goat[35], false, BOOL____00423) :: defines_var(BOOL____00423);\n\
constraint bool_eq_reif(goat[36], false, BOOL____00424) :: defines_var(BOOL____00424);\n\
constraint bool_eq_reif(goat[36], farmer[36], BOOL____00609) :: defines_var(BOOL____00609);\n\
constraint bool_eq_reif(goat[37], false, BOOL____00431) :: defines_var(BOOL____00431);\n\
constraint bool_eq_reif(goat[38], false, BOOL____00429) :: defines_var(BOOL____00429);\n\
constraint bool_eq_reif(goat[39], false, BOOL____00430) :: defines_var(BOOL____00430);\n\
constraint bool_eq_reif(goat[39], farmer[39], BOOL____00616) :: defines_var(BOOL____00616);\n\
constraint bool_eq_reif(goat[40], false, BOOL____00437) :: defines_var(BOOL____00437);\n\
constraint bool_eq_reif(goat[41], false, BOOL____00435) :: defines_var(BOOL____00435);\n\
constraint bool_eq_reif(goat[42], false, BOOL____00436) :: defines_var(BOOL____00436);\n\
constraint bool_eq_reif(goat[42], farmer[42], BOOL____00623) :: defines_var(BOOL____00623);\n\
constraint bool_eq_reif(goat[43], false, BOOL____00443) :: defines_var(BOOL____00443);\n\
constraint bool_eq_reif(goat[44], false, BOOL____00441) :: defines_var(BOOL____00441);\n\
constraint bool_eq_reif(goat[45], false, BOOL____00442) :: defines_var(BOOL____00442);\n\
constraint bool_eq_reif(goat[45], farmer[45], BOOL____00630) :: defines_var(BOOL____00630);\n\
constraint bool_eq_reif(goat[46], false, BOOL____00449) :: defines_var(BOOL____00449);\n\
constraint bool_eq_reif(goat[47], false, BOOL____00447) :: defines_var(BOOL____00447);\n\
constraint bool_eq_reif(goat[48], false, BOOL____00448) :: defines_var(BOOL____00448);\n\
constraint bool_eq_reif(goat[48], farmer[48], BOOL____00637) :: defines_var(BOOL____00637);\n\
constraint bool_eq_reif(goat[49], false, BOOL____00455) :: defines_var(BOOL____00455);\n\
constraint bool_eq_reif(goat[50], false, BOOL____00453) :: defines_var(BOOL____00453);\n\
constraint bool_eq_reif(goat[51], false, BOOL____00454) :: defines_var(BOOL____00454);\n\
constraint bool_eq_reif(goat[51], farmer[51], BOOL____00644) :: defines_var(BOOL____00644);\n\
constraint bool_eq_reif(goat[52], false, BOOL____00461) :: defines_var(BOOL____00461);\n\
constraint bool_eq_reif(goat[53], false, BOOL____00459) :: defines_var(BOOL____00459);\n\
constraint bool_eq_reif(goat[54], false, BOOL____00460) :: defines_var(BOOL____00460);\n\
constraint bool_eq_reif(goat[54], farmer[54], BOOL____00651) :: defines_var(BOOL____00651);\n\
constraint bool_eq_reif(goat[55], false, BOOL____00467) :: defines_var(BOOL____00467);\n\
constraint bool_eq_reif(goat[56], false, BOOL____00465) :: defines_var(BOOL____00465);\n\
constraint bool_eq_reif(goat[57], false, BOOL____00466) :: defines_var(BOOL____00466);\n\
constraint bool_eq_reif(goat[57], farmer[57], BOOL____00658) :: defines_var(BOOL____00658);\n\
constraint bool_eq_reif(goat[58], false, BOOL____00473) :: defines_var(BOOL____00473);\n\
constraint bool_eq_reif(goat[59], false, BOOL____00471) :: defines_var(BOOL____00471);\n\
constraint bool_eq_reif(goat[60], false, BOOL____00472) :: defines_var(BOOL____00472);\n\
constraint bool_eq_reif(goat[60], farmer[60], BOOL____00665) :: defines_var(BOOL____00665);\n\
constraint bool_eq_reif(wolf[1], false, BOOL____00669) :: defines_var(BOOL____00669);\n\
constraint bool_eq_reif(wolf[2], false, BOOL____00667) :: defines_var(BOOL____00667);\n\
constraint bool_eq_reif(wolf[3], false, BOOL____00668) :: defines_var(BOOL____00668);\n\
constraint bool_eq_reif(wolf[3], farmer[3], BOOL____00535) :: defines_var(BOOL____00535);\n\
constraint bool_eq_reif(wolf[4], false, BOOL____00674) :: defines_var(BOOL____00674);\n\
constraint bool_eq_reif(wolf[5], false, BOOL____00538) :: defines_var(BOOL____00538);\n\
constraint bool_eq_reif(wolf[6], false, BOOL____00673) :: defines_var(BOOL____00673);\n\
constraint bool_eq_reif(wolf[6], farmer[6], BOOL____00545) :: defines_var(BOOL____00545);\n\
constraint bool_eq_reif(wolf[7], false, BOOL____00679) :: defines_var(BOOL____00679);\n\
constraint bool_eq_reif(wolf[8], false, BOOL____00548) :: defines_var(BOOL____00548);\n\
constraint bool_eq_reif(wolf[9], false, BOOL____00678) :: defines_var(BOOL____00678);\n\
constraint bool_eq_reif(wolf[9], farmer[9], BOOL____00536) :: defines_var(BOOL____00536);\n\
constraint bool_eq_reif(wolf[10], false, BOOL____00684) :: defines_var(BOOL____00684);\n\
constraint bool_eq_reif(wolf[11], false, BOOL____00557) :: defines_var(BOOL____00557);\n\
constraint bool_eq_reif(wolf[12], false, BOOL____00683) :: defines_var(BOOL____00683);\n\
constraint bool_eq_reif(wolf[12], farmer[12], BOOL____00546) :: defines_var(BOOL____00546);\n\
constraint bool_eq_reif(wolf[13], false, BOOL____00689) :: defines_var(BOOL____00689);\n\
constraint bool_eq_reif(wolf[14], false, BOOL____00564) :: defines_var(BOOL____00564);\n\
constraint bool_eq_reif(wolf[15], false, BOOL____00688) :: defines_var(BOOL____00688);\n\
constraint bool_eq_reif(wolf[15], farmer[15], BOOL____00555) :: defines_var(BOOL____00555);\n\
constraint bool_eq_reif(wolf[16], false, BOOL____00694) :: defines_var(BOOL____00694);\n\
constraint bool_eq_reif(wolf[17], false, BOOL____00571) :: defines_var(BOOL____00571);\n\
constraint bool_eq_reif(wolf[18], false, BOOL____00693) :: defines_var(BOOL____00693);\n\
constraint bool_eq_reif(wolf[18], farmer[18], BOOL____00562) :: defines_var(BOOL____00562);\n\
constraint bool_eq_reif(wolf[19], false, BOOL____00699) :: defines_var(BOOL____00699);\n\
constraint bool_eq_reif(wolf[20], false, BOOL____00578) :: defines_var(BOOL____00578);\n\
constraint bool_eq_reif(wolf[21], false, BOOL____00698) :: defines_var(BOOL____00698);\n\
constraint bool_eq_reif(wolf[21], farmer[21], BOOL____00569) :: defines_var(BOOL____00569);\n\
constraint bool_eq_reif(wolf[22], false, BOOL____00704) :: defines_var(BOOL____00704);\n\
constraint bool_eq_reif(wolf[23], false, BOOL____00585) :: defines_var(BOOL____00585);\n\
constraint bool_eq_reif(wolf[24], false, BOOL____00703) :: defines_var(BOOL____00703);\n\
constraint bool_eq_reif(wolf[24], farmer[24], BOOL____00576) :: defines_var(BOOL____00576);\n\
constraint bool_eq_reif(wolf[25], false, BOOL____00709) :: defines_var(BOOL____00709);\n\
constraint bool_eq_reif(wolf[26], false, BOOL____00592) :: defines_var(BOOL____00592);\n\
constraint bool_eq_reif(wolf[27], false, BOOL____00708) :: defines_var(BOOL____00708);\n\
constraint bool_eq_reif(wolf[27], farmer[27], BOOL____00583) :: defines_var(BOOL____00583);\n\
constraint bool_eq_reif(wolf[28], false, BOOL____00714) :: defines_var(BOOL____00714);\n\
constraint bool_eq_reif(wolf[29], false, BOOL____00599) :: defines_var(BOOL____00599);\n\
constraint bool_eq_reif(wolf[30], false, BOOL____00713) :: defines_var(BOOL____00713);\n\
constraint bool_eq_reif(wolf[30], farmer[30], BOOL____00590) :: defines_var(BOOL____00590);\n\
constraint bool_eq_reif(wolf[31], false, BOOL____00719) :: defines_var(BOOL____00719);\n\
constraint bool_eq_reif(wolf[32], false, BOOL____00606) :: defines_var(BOOL____00606);\n\
constraint bool_eq_reif(wolf[33], false, BOOL____00718) :: defines_var(BOOL____00718);\n\
constraint bool_eq_reif(wolf[33], farmer[33], BOOL____00597) :: defines_var(BOOL____00597);\n\
constraint bool_eq_reif(wolf[34], false, BOOL____00724) :: defines_var(BOOL____00724);\n\
constraint bool_eq_reif(wolf[35], false, BOOL____00613) :: defines_var(BOOL____00613);\n\
constraint bool_eq_reif(wolf[36], false, BOOL____00723) :: defines_var(BOOL____00723);\n\
constraint bool_eq_reif(wolf[36], farmer[36], BOOL____00604) :: defines_var(BOOL____00604);\n\
constraint bool_eq_reif(wolf[37], false, BOOL____00729) :: defines_var(BOOL____00729);\n\
constraint bool_eq_reif(wolf[38], false, BOOL____00620) :: defines_var(BOOL____00620);\n\
constraint bool_eq_reif(wolf[39], false, BOOL____00728) :: defines_var(BOOL____00728);\n\
constraint bool_eq_reif(wolf[39], farmer[39], BOOL____00611) :: defines_var(BOOL____00611);\n\
constraint bool_eq_reif(wolf[40], false, BOOL____00734) :: defines_var(BOOL____00734);\n\
constraint bool_eq_reif(wolf[41], false, BOOL____00627) :: defines_var(BOOL____00627);\n\
constraint bool_eq_reif(wolf[42], false, BOOL____00733) :: defines_var(BOOL____00733);\n\
constraint bool_eq_reif(wolf[42], farmer[42], BOOL____00618) :: defines_var(BOOL____00618);\n\
constraint bool_eq_reif(wolf[43], false, BOOL____00739) :: defines_var(BOOL____00739);\n\
constraint bool_eq_reif(wolf[44], false, BOOL____00634) :: defines_var(BOOL____00634);\n\
constraint bool_eq_reif(wolf[45], false, BOOL____00738) :: defines_var(BOOL____00738);\n\
constraint bool_eq_reif(wolf[45], farmer[45], BOOL____00625) :: defines_var(BOOL____00625);\n\
constraint bool_eq_reif(wolf[46], false, BOOL____00744) :: defines_var(BOOL____00744);\n\
constraint bool_eq_reif(wolf[47], false, BOOL____00641) :: defines_var(BOOL____00641);\n\
constraint bool_eq_reif(wolf[48], false, BOOL____00743) :: defines_var(BOOL____00743);\n\
constraint bool_eq_reif(wolf[48], farmer[48], BOOL____00632) :: defines_var(BOOL____00632);\n\
constraint bool_eq_reif(wolf[49], false, BOOL____00749) :: defines_var(BOOL____00749);\n\
constraint bool_eq_reif(wolf[50], false, BOOL____00648) :: defines_var(BOOL____00648);\n\
constraint bool_eq_reif(wolf[51], false, BOOL____00748) :: defines_var(BOOL____00748);\n\
constraint bool_eq_reif(wolf[51], farmer[51], BOOL____00639) :: defines_var(BOOL____00639);\n\
constraint bool_eq_reif(wolf[52], false, BOOL____00754) :: defines_var(BOOL____00754);\n\
constraint bool_eq_reif(wolf[53], false, BOOL____00655) :: defines_var(BOOL____00655);\n\
constraint bool_eq_reif(wolf[54], false, BOOL____00753) :: defines_var(BOOL____00753);\n\
constraint bool_eq_reif(wolf[54], farmer[54], BOOL____00646) :: defines_var(BOOL____00646);\n\
constraint bool_eq_reif(wolf[55], false, BOOL____00759) :: defines_var(BOOL____00759);\n\
constraint bool_eq_reif(wolf[56], false, BOOL____00662) :: defines_var(BOOL____00662);\n\
constraint bool_eq_reif(wolf[57], false, BOOL____00758) :: defines_var(BOOL____00758);\n\
constraint bool_eq_reif(wolf[57], farmer[57], BOOL____00653) :: defines_var(BOOL____00653);\n\
constraint bool_eq_reif(wolf[58], false, BOOL____00765) :: defines_var(BOOL____00765);\n\
constraint bool_eq_reif(wolf[59], false, BOOL____00763) :: defines_var(BOOL____00763);\n\
constraint bool_eq_reif(wolf[60], false, BOOL____00764) :: defines_var(BOOL____00764);\n\
constraint bool_eq_reif(wolf[60], farmer[60], BOOL____00660) :: defines_var(BOOL____00660);\n\
constraint bool_le(BOOL____00789, farmer[1]);\n\
constraint bool_le(BOOL____00790, farmer[1]);\n\
constraint bool_le(BOOL____00791, farmer[2]);\n\
constraint bool_le(BOOL____00792, farmer[2]);\n\
constraint bool_le(BOOL____00793, farmer[3]);\n\
constraint bool_le(BOOL____00794, farmer[3]);\n\
constraint bool_le(BOOL____00795, farmer[4]);\n\
constraint bool_le(BOOL____00796, farmer[4]);\n\
constraint bool_le(BOOL____00797, farmer[5]);\n\
constraint bool_le(BOOL____00798, farmer[5]);\n\
constraint bool_le(BOOL____00799, farmer[6]);\n\
constraint bool_le(BOOL____00800, farmer[6]);\n\
constraint bool_le(BOOL____00801, farmer[7]);\n\
constraint bool_le(BOOL____00802, farmer[7]);\n\
constraint bool_le(BOOL____00803, farmer[8]);\n\
constraint bool_le(BOOL____00804, farmer[8]);\n\
constraint bool_le(BOOL____00805, farmer[9]);\n\
constraint bool_le(BOOL____00806, farmer[9]);\n\
constraint bool_le(BOOL____00807, farmer[10]);\n\
constraint bool_le(BOOL____00808, farmer[10]);\n\
constraint bool_le(BOOL____00809, farmer[11]);\n\
constraint bool_le(BOOL____00810, farmer[11]);\n\
constraint bool_le(BOOL____00811, farmer[12]);\n\
constraint bool_le(BOOL____00812, farmer[12]);\n\
constraint bool_le(BOOL____00813, farmer[13]);\n\
constraint bool_le(BOOL____00814, farmer[13]);\n\
constraint bool_le(BOOL____00815, farmer[14]);\n\
constraint bool_le(BOOL____00816, farmer[14]);\n\
constraint bool_le(BOOL____00817, farmer[15]);\n\
constraint bool_le(BOOL____00818, farmer[15]);\n\
constraint bool_le(BOOL____00819, farmer[16]);\n\
constraint bool_le(BOOL____00820, farmer[16]);\n\
constraint bool_le(BOOL____00821, farmer[17]);\n\
constraint bool_le(BOOL____00822, farmer[17]);\n\
constraint bool_le(BOOL____00823, farmer[18]);\n\
constraint bool_le(BOOL____00824, farmer[18]);\n\
constraint bool_le(BOOL____00825, farmer[19]);\n\
constraint bool_le(BOOL____00826, farmer[19]);\n\
constraint bool_le(BOOL____00827, farmer[20]);\n\
constraint bool_le(BOOL____00828, farmer[20]);\n\
constraint bool_le(BOOL____00829, farmer[21]);\n\
constraint bool_le(BOOL____00830, farmer[21]);\n\
constraint bool_le(BOOL____00831, farmer[22]);\n\
constraint bool_le(BOOL____00832, farmer[22]);\n\
constraint bool_le(BOOL____00833, farmer[23]);\n\
constraint bool_le(BOOL____00834, farmer[23]);\n\
constraint bool_le(BOOL____00835, farmer[24]);\n\
constraint bool_le(BOOL____00836, farmer[24]);\n\
constraint bool_le(BOOL____00837, farmer[25]);\n\
constraint bool_le(BOOL____00838, farmer[25]);\n\
constraint bool_le(BOOL____00839, farmer[26]);\n\
constraint bool_le(BOOL____00840, farmer[26]);\n\
constraint bool_le(BOOL____00841, farmer[27]);\n\
constraint bool_le(BOOL____00842, farmer[27]);\n\
constraint bool_le(BOOL____00843, farmer[28]);\n\
constraint bool_le(BOOL____00844, farmer[28]);\n\
constraint bool_le(BOOL____00845, farmer[29]);\n\
constraint bool_le(BOOL____00846, farmer[29]);\n\
constraint bool_le(BOOL____00847, farmer[30]);\n\
constraint bool_le(BOOL____00848, farmer[30]);\n\
constraint bool_le(BOOL____00849, farmer[31]);\n\
constraint bool_le(BOOL____00850, farmer[31]);\n\
constraint bool_le(BOOL____00851, farmer[32]);\n\
constraint bool_le(BOOL____00852, farmer[32]);\n\
constraint bool_le(BOOL____00853, farmer[33]);\n\
constraint bool_le(BOOL____00854, farmer[33]);\n\
constraint bool_le(BOOL____00855, farmer[34]);\n\
constraint bool_le(BOOL____00856, farmer[34]);\n\
constraint bool_le(BOOL____00857, farmer[35]);\n\
constraint bool_le(BOOL____00858, farmer[35]);\n\
constraint bool_le(BOOL____00859, farmer[36]);\n\
constraint bool_le(BOOL____00860, farmer[36]);\n\
constraint bool_le(BOOL____00861, farmer[37]);\n\
constraint bool_le(BOOL____00862, farmer[37]);\n\
constraint bool_le(BOOL____00863, farmer[38]);\n\
constraint bool_le(BOOL____00864, farmer[38]);\n\
constraint bool_le(BOOL____00865, farmer[39]);\n\
constraint bool_le(BOOL____00866, farmer[39]);\n\
constraint bool_le(BOOL____00867, farmer[40]);\n\
constraint bool_le(BOOL____00868, farmer[40]);\n\
constraint bool_le(BOOL____00869, farmer[41]);\n\
constraint bool_le(BOOL____00870, farmer[41]);\n\
constraint bool_le(BOOL____00871, farmer[42]);\n\
constraint bool_le(BOOL____00872, farmer[42]);\n\
constraint bool_le(BOOL____00873, farmer[43]);\n\
constraint bool_le(BOOL____00874, farmer[43]);\n\
constraint bool_le(BOOL____00875, farmer[44]);\n\
constraint bool_le(BOOL____00876, farmer[44]);\n\
constraint bool_le(BOOL____00877, farmer[45]);\n\
constraint bool_le(BOOL____00878, farmer[45]);\n\
constraint bool_le(BOOL____00879, farmer[46]);\n\
constraint bool_le(BOOL____00880, farmer[46]);\n\
constraint bool_le(BOOL____00881, farmer[47]);\n\
constraint bool_le(BOOL____00882, farmer[47]);\n\
constraint bool_le(BOOL____00883, farmer[48]);\n\
constraint bool_le(BOOL____00884, farmer[48]);\n\
constraint bool_le(BOOL____00885, farmer[49]);\n\
constraint bool_le(BOOL____00886, farmer[49]);\n\
constraint bool_le(BOOL____00887, farmer[50]);\n\
constraint bool_le(BOOL____00888, farmer[50]);\n\
constraint bool_le(BOOL____00889, farmer[51]);\n\
constraint bool_le(BOOL____00890, farmer[51]);\n\
constraint bool_le(BOOL____00891, farmer[52]);\n\
constraint bool_le(BOOL____00892, farmer[52]);\n\
constraint bool_le(BOOL____00893, farmer[53]);\n\
constraint bool_le(BOOL____00894, farmer[53]);\n\
constraint bool_le(BOOL____00895, farmer[54]);\n\
constraint bool_le(BOOL____00896, farmer[54]);\n\
constraint bool_le(BOOL____00897, farmer[55]);\n\
constraint bool_le(BOOL____00898, farmer[55]);\n\
constraint bool_le(BOOL____00899, farmer[56]);\n\
constraint bool_le(BOOL____00900, farmer[56]);\n\
constraint bool_le(BOOL____00901, farmer[57]);\n\
constraint bool_le(BOOL____00902, farmer[57]);\n\
constraint bool_le(BOOL____00903, farmer[58]);\n\
constraint bool_le(BOOL____00904, farmer[58]);\n\
constraint bool_le(BOOL____00905, farmer[59]);\n\
constraint bool_le(BOOL____00906, farmer[59]);\n\
constraint bool_le(BOOL____00907, farmer[60]);\n\
constraint bool_le(BOOL____00908, farmer[60]);\n\
constraint bool_le(cabbage[5], BOOL____00541);\n\
constraint bool_le(cabbage[8], BOOL____00551);\n\
constraint bool_le(cabbage[11], BOOL____00559);\n\
constraint bool_le(cabbage[14], BOOL____00566);\n\
constraint bool_le(cabbage[17], BOOL____00573);\n\
constraint bool_le(cabbage[20], BOOL____00580);\n\
constraint bool_le(cabbage[23], BOOL____00587);\n\
constraint bool_le(cabbage[26], BOOL____00594);\n\
constraint bool_le(cabbage[29], BOOL____00601);\n\
constraint bool_le(cabbage[32], BOOL____00608);\n\
constraint bool_le(cabbage[35], BOOL____00615);\n\
constraint bool_le(cabbage[38], BOOL____00622);\n\
constraint bool_le(cabbage[41], BOOL____00629);\n\
constraint bool_le(cabbage[44], BOOL____00636);\n\
constraint bool_le(cabbage[47], BOOL____00643);\n\
constraint bool_le(cabbage[50], BOOL____00650);\n\
constraint bool_le(cabbage[53], BOOL____00657);\n\
constraint bool_le(cabbage[56], BOOL____00664);\n\
constraint bool_le(goat[5], BOOL____00544);\n\
constraint bool_le(goat[8], BOOL____00554);\n\
constraint bool_le(goat[11], BOOL____00561);\n\
constraint bool_le(goat[14], BOOL____00568);\n\
constraint bool_le(goat[17], BOOL____00575);\n\
constraint bool_le(goat[20], BOOL____00582);\n\
constraint bool_le(goat[23], BOOL____00589);\n\
constraint bool_le(goat[26], BOOL____00596);\n\
constraint bool_le(goat[29], BOOL____00603);\n\
constraint bool_le(goat[32], BOOL____00610);\n\
constraint bool_le(goat[35], BOOL____00617);\n\
constraint bool_le(goat[38], BOOL____00624);\n\
constraint bool_le(goat[41], BOOL____00631);\n\
constraint bool_le(goat[44], BOOL____00638);\n\
constraint bool_le(goat[47], BOOL____00645);\n\
constraint bool_le(goat[50], BOOL____00652);\n\
constraint bool_le(goat[53], BOOL____00659);\n\
constraint bool_le(goat[56], BOOL____00666);\n\
constraint bool_le(wolf[5], BOOL____00537);\n\
constraint bool_le(wolf[8], BOOL____00547);\n\
constraint bool_le(wolf[11], BOOL____00556);\n\
constraint bool_le(wolf[14], BOOL____00563);\n\
constraint bool_le(wolf[17], BOOL____00570);\n\
constraint bool_le(wolf[20], BOOL____00577);\n\
constraint bool_le(wolf[23], BOOL____00584);\n\
constraint bool_le(wolf[26], BOOL____00591);\n\
constraint bool_le(wolf[29], BOOL____00598);\n\
constraint bool_le(wolf[32], BOOL____00605);\n\
constraint bool_le(wolf[35], BOOL____00612);\n\
constraint bool_le(wolf[38], BOOL____00619);\n\
constraint bool_le(wolf[41], BOOL____00626);\n\
constraint bool_le(wolf[44], BOOL____00633);\n\
constraint bool_le(wolf[47], BOOL____00640);\n\
constraint bool_le(wolf[50], BOOL____00647);\n\
constraint bool_le(wolf[53], BOOL____00654);\n\
constraint bool_le(wolf[56], BOOL____00661);\n\
solve  :: bool_search([wolf[1], wolf[2], wolf[3], wolf[4], wolf[5], wolf[6], wolf[7], wolf[8], wolf[9], wolf[10], wolf[11], wolf[12], wolf[13], wolf[14], wolf[15], wolf[16], wolf[17], wolf[18], wolf[19], wolf[20], wolf[21], wolf[22], wolf[23], wolf[24], wolf[25], wolf[26], wolf[27], wolf[28], wolf[29], wolf[30], wolf[31], wolf[32], wolf[33], wolf[34], wolf[35], wolf[36], wolf[37], wolf[38], wolf[39], wolf[40], wolf[41], wolf[42], wolf[43], wolf[44], wolf[45], wolf[46], wolf[47], wolf[48], wolf[49], wolf[50], wolf[51], wolf[52], wolf[53], wolf[54], wolf[55], wolf[56], wolf[57], wolf[58], wolf[59], wolf[60], goat[1], goat[2], goat[3], goat[4], goat[5], goat[6], goat[7], goat[8], goat[9], goat[10], goat[11], goat[12], goat[13], goat[14], goat[15], goat[16], goat[17], goat[18], goat[19], goat[20], goat[21], goat[22], goat[23], goat[24], goat[25], goat[26], goat[27], goat[28], goat[29], goat[30], goat[31], goat[32], goat[33], goat[34], goat[35], goat[36], goat[37], goat[38], goat[39], goat[40], goat[41], goat[42], goat[43], goat[44], goat[45], goat[46], goat[47], goat[48], goat[49], goat[50], goat[51], goat[52], goat[53], goat[54], goat[55], goat[56], goat[57], goat[58], goat[59], goat[60], cabbage[1], cabbage[2], cabbage[3], cabbage[4], cabbage[5], cabbage[6], cabbage[7], cabbage[8], cabbage[9], cabbage[10], cabbage[11], cabbage[12], cabbage[13], cabbage[14], cabbage[15], cabbage[16], cabbage[17], cabbage[18], cabbage[19], cabbage[20], cabbage[21], cabbage[22], cabbage[23], cabbage[24], cabbage[25], cabbage[26], cabbage[27], cabbage[28], cabbage[29], cabbage[30], cabbage[31], cabbage[32], cabbage[33], cabbage[34], cabbage[35], cabbage[36], cabbage[37], cabbage[38], cabbage[39], cabbage[40], cabbage[41], cabbage[42], cabbage[43], cabbage[44], cabbage[45], cabbage[46], cabbage[47], cabbage[48], cabbage[49], cabbage[50], cabbage[51], cabbage[52], cabbage[53], cabbage[54], cabbage[55], cabbage[56], cabbage[57], cabbage[58], cabbage[59], cabbage[60], farmer[1], farmer[2], farmer[3], farmer[4], farmer[5], farmer[6], farmer[7], farmer[8], farmer[9], farmer[10], farmer[11], farmer[12], farmer[13], farmer[14], farmer[15], farmer[16], farmer[17], farmer[18], farmer[19], farmer[20], farmer[21], farmer[22], farmer[23], farmer[24], farmer[25], farmer[26], farmer[27], farmer[28], farmer[29], farmer[30], farmer[31], farmer[32], farmer[33], farmer[34], farmer[35], farmer[36], farmer[37], farmer[38], farmer[39], farmer[40], farmer[41], farmer[42], farmer[43], farmer[44], farmer[45], farmer[46], farmer[47], farmer[48], farmer[49], farmer[50], farmer[51], farmer[52], farmer[53], farmer[54], farmer[55], farmer[56], farmer[57], farmer[58], farmer[59], farmer[60]], input_order, indomain_max, complete) satisfy;\n\
", "cabbage = array2d(1..20, -1..1, [false, false, true, false, false, true, false, false, true, false, false, true, false, false, true, false, false, true, false, false, true, false, false, true, false, false, true, false, false, true, false, false, true, false, false, true, false, false, true, false, false, true, false, true, false, true, false, false, true, false, false, true, false, false, true, false, false, true, false, false]);\n\
farmer = array2d(1..20, -1..1, [false, false, true, false, true, false, true, false, false, false, true, false, false, false, true, false, true, false, true, false, false, true, false, false, true, false, false, true, false, false, true, false, false, true, false, false, false, true, false, false, false, true, false, true, false, true, false, false, false, true, false, false, false, true, false, true, false, true, false, false]);\n\
goat = array2d(1..20, -1..1, [false, false, true, false, true, false, true, false, false, true, false, false, true, false, false, true, false, false, true, false, false, true, false, false, true, false, false, true, false, false, true, false, false, true, false, false, false, true, false, false, false, true, false, false, true, false, false, true, false, false, true, false, false, true, false, true, false, true, false, false]);\n\
wolf = array2d(1..20, -1..1, [false, false, true, false, false, true, false, false, true, false, false, true, false, false, true, false, true, false, true, false, false, true, false, false, true, false, false, true, false, false, true, false, false, true, false, false, true, false, false, true, false, false, true, false, false, true, false, false, true, false, false, true, false, false, true, false, false, true, false, false]);\n\
----------\n\
");
      }
    };

    Create c;
  }

}}

// STATISTICS: test-other
