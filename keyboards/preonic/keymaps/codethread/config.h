#pragma once

// If you find that you frequently trigger the modifier of your mod-tap(s) by accident,
// for example, that's a sign that your tapping term may be too low so tap DT_UP a few
// times to increase the tapping term until that no longer happens. On the flip side,
// if you get superfluous characters when you actually intended to momentarily activate
// a layer, tap DT_DOWN to lower the tapping term.
#define TAPPING_TERM \
    140 // default 200
        // 100,pretty darn tough, need to really tap that mofo

// trying this for home mods
#define IGNORE_MOD_TAP_INTERRUPT

#define FLOW_COUNT 7
#define FLOW_LAYERS_COUNT 2
