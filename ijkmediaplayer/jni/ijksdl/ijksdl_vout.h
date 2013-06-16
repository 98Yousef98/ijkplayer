/*****************************************************************************
 * ijksdl_vout.h
 *****************************************************************************
 *
 * copyright (c) 2013 Zhang Rui <bbcallen@gmail.com>
 *
 * This file is part of ijkPlayer.
 *
 * ijkPlayer is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * ijkPlayer is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with ijkPlayer; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#ifndef IJKSDL__IJKSDL_VOUT_H
#define IJKSDL__IJKSDL_VOUT_H

#include "ijksdl_stdinc.h"
#include "ijksdl_mutex.h"

typedef struct SDL_VoutOverlay {
    void *opaque;

    int w;
    int h;
} SDL_VoutOverlay;

typedef struct SDL_VoutSurface_Opaque SDL_VoutSurface_Opaque;
typedef struct SDL_VoutSurface SDL_VoutSurface;
typedef struct SDL_VoutSurface {
    int w;
    int h;
    int format;

    SDL_VoutSurface_Opaque *opaque;
} SDL_VoutSurface;

typedef struct SDL_Vout_Opaque SDL_Vout_Opaque;
typedef struct SDL_Vout SDL_Vout;
typedef struct SDL_Vout {
    SDL_mutex *mutex;

    SDL_Vout_Opaque   *opaque;
    void             (*free_l)(SDL_Vout *vout);
    SDL_VoutSurface *(*set_video_mode)(SDL_Vout *vout, int w, int h, int bpp, int flags);
} SDL_Vout;

void             SDL_Vout_Free(SDL_Vout *vout);
SDL_VoutSurface *SDL_Vout_SetVideoMode(SDL_Vout *vout, int w, int h, int bpp, int flags);

#endif
