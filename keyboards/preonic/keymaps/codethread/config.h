#pragma once

// If you find that you frequently trigger the modifier of your mod-tap(s) by accident,
// for example, that's a sign that your tapping term may be too low so tap DT_UP a few
// times to increase the tapping term until that no longer happens. On the flip side,
// if you get superfluous characters when you actually intended to momentarily activate
// a layer, tap DT_DOWN to lower the tapping term.
// #define TAPPING_TERM 140
// 140 works well, unless using home row mods
// default 200
// 100,pretty darn tough, need to really tap that mofo
#define TAPPING_TERM_PER_KEY
// this should make home row mods better, but i can't jj(hold) and expect to scroll down. Probably a good thing
#define QUICK_TAP_TERM 0
// this seems to feel better but I don't think it should
#define PERMISSIVE_HOLD
