/******************************************************************************
 * The MIT License (MIT)
 *
 * Copyright (c) 2019-2023 Baldur Karlsson
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 ******************************************************************************/

// By default this is generated by calling out to git directly as long as the build is running from
// within a git clone. Windows users will need VS2015 or above to invoke git.
//
// On windows if you're not running from within git, you can set the hash manually here. On
// non-windows it's recommended to set BUILD_VERSION_HASH in the cmake build command.
//
// On distributed builds this should be set to the last upstream git commit where the build comes
// from. If any later commits are cherry-picked or local patches are applied, this should still
// point to the hash of the tree that the build was based on.
#if !defined(GIT_COMMIT_HASH)
#define GIT_COMMIT_HASH "NO_GIT_COMMIT_HASH_DEFINED_AT_BUILD_TIME"
#endif

// Note the hash should be precisely 40 characters, as comes from git rev-parse.
extern "C" const char GitVersionHash[41] = GIT_COMMIT_HASH;

#if defined(WIN64)
#pragma comment(linker, "/include:GitVersionHash")
#elif defined(WIN32)
#pragma comment(linker, "/include:_GitVersionHash")
#endif
