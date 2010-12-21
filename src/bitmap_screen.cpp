/////////////////////////////////////////////////////////////////////////////
// This file is part of EasyRPG Player.
//
// EasyRPG Player is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// EasyRPG Player is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with EasyRPG Player. If not, see <http://www.gnu.org/licenses/>.
/////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "bitmap_screen.h"

#if defined(USE_SDL) && !defined(USE_OPENGL)
	#include "sdl_bitmap_screen.h"
#elif defined(USE_OPENGL)
	#include "gl_bitmap_screen.h"
#endif

////////////////////////////////////////////////////////////
BitmapScreen* BitmapScreen::CreateBitmapScreen(Bitmap* source) {
	#ifdef USE_SDL
		return (BitmapScreen*)new SdlBitmapScreen(source);
	#elif USE_OPENGL
		return (BitmapScreen*)new GlBitmapScreen(source);
	#endif
}

////////////////////////////////////////////////////////////
BitmapScreen* BitmapScreen::CreateBitmapScreen(bool delete_bitmap) {
	#ifdef USE_SDL
		return (BitmapScreen*)new SdlBitmapScreen(delete_bitmap);
	#elif USE_OPENGL
		return (BitmapScreen*)new GlBitmapScreen(delete_bitmap);
	#endif
}
