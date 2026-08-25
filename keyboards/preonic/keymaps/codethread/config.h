#pragma once

// managed by `get_tapping_term` per key
#define TAPPING_TERM_PER_KEY
// this should make home row mods better, but i can't jj(hold) and expect to
// scroll down. Probably a good thing
#define QUICK_TAP_TERM 150
// this seems to feel better but I don't think it should
#define PERMISSIVE_HOLD
// tries to only hold if opposite hands used (corrects my bad typing habbits)
// #define CHORDAL_HOLD
// if keys typed in quick succession i.e a flow of keys
// assume no mods. This is more comfortable so far than CHORDAL_HOLD
// as that wasn't allowing alt+bspc
#define FLOW_TAP_TERM 150
