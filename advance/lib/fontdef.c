/*
 * This file is part of the Advance project.
 *
 * Copyright (C) 1999, 2000, 2001, 2002, 2003 Andrea Mazzoleni
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details. 
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#if HAVE_CONFIG_H
#include <osconf.h>
#endif

#include "font.h"
#include "fz.h"

#include "fontdef.dat"

/**
 * Return the default font.
 * \param height Height in pixel of the required font. The effective height may differs.
 */
adv_font* adv_font_default(unsigned height) {
	adv_fz* f;
	adv_font* font;

	if (height >= 17) {
		f = fzopenmemory(FONT_HELV17, sizeof(FONT_HELV17));
	} else if (height >= 15) {
		f = fzopenmemory(FONT_HELV15, sizeof(FONT_HELV15));
	} else if (height >= 13) {
		f = fzopenmemory(FONT_HELV13, sizeof(FONT_HELV13));
	} else {
		f = fzopenmemory(FONT_HELV11, sizeof(FONT_HELV11));
	}

	font = adv_font_load(f);

	fzclose(f);

	return font;
}
