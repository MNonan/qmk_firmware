/* Copyright 2021 QMK
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once

#include "compiler_support.h"

// Macro to help make GPIO and other controls atomic.

#ifndef IGNORE_ATOMIC_BLOCK
#    if __has_include_next("atomic_util.h")
#        include_next "atomic_util.h" /* Include the platforms atomic.h */
#    else
#        define ATOMIC_BLOCK STATIC_ASSERT(0, "ATOMIC_BLOCK not implemented")
#        define ATOMIC_BLOCK_RESTORESTATE STATIC_ASSERT(0, "ATOMIC_BLOCK_RESTORESTATE not implemented")
#        define ATOMIC_BLOCK_FORCEON STATIC_ASSERT(0, "ATOMIC_BLOCK_FORCEON not implemented")
#        define ATOMIC_FORCEON STATIC_ASSERT(0, "ATOMIC_FORCEON not implemented")
#        define ATOMIC_RESTORESTATE STATIC_ASSERT(0, "ATOMIC_RESTORESTATE not implemented")
#    endif
#else /* do nothing atomic macro */
#    define ATOMIC_BLOCK(t) for (uint8_t __ToDo = 1; __ToDo; __ToDo = 0)
#    define ATOMIC_FORCEON
#    define ATOMIC_RESTORESTATE
#    define ATOMIC_BLOCK_RESTORESTATE ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
#    define ATOMIC_BLOCK_FORCEON ATOMIC_BLOCK(ATOMIC_FORCEON)
#endif
