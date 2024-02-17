# My Custom Preonic layout

Trying callum mods

-   implementation: https://github.com/qmk/qmk_firmware/pull/16174
-   referring blog: https://blog.ffff.lt/posts/callum-layers/
-   original implementation: https://github.com/qmk/qmk_firmware/blob/user-keymaps-still-present/users/callum/readme.md

## motivation

I've liked my current setup for a long time, but there is frustration with the odd accidental enter when I wanted my modifer - and that's based on timers of what is and isn't a hold/tap in QMK's eyes. This on the other hand seems to focus on allowing key presses to be deterministic - if a little more complex. I like vim modal editing, so this should start to feel similar over time in theory. It also unlocks more use of modifiers like alt and smaller form keyboards in the future

### plan

-   start with the bare minimum changes just to get the idea working
-   slowly incorporate more fancy things

## thoughts

I don'tunderstand the meaning of the OS\_\* key variants... something for later

---

test comit

## Philosophy

## features

## notes

### Alt / Meta

want somewhere better for this

backspace under right thumb, so need alt on left?

moved under right thumb and put cmd+enter + alt+backspace on dedicated keys

### removing right mod

-   can't do dash with shift under thumb

### Mod tap

from the docs on tap term:

> If you find that you frequently trigger the modifier of your mod-tap(s) by accident, for example, that's a sign that your tapping term may be too low so tap DT_UP a few times to increase the tapping term until that no longer happens. On the flip side, if you get superfluous characters when you actually intended to momentarily activate a layer, tap DT_DOWN to lower the tapping term.

## Setup for future

```sh
brew install qmk/qmk/qmk
```

From root of qmk_firmware

```sh
qmk setup
```

```sh
qmk config user.keymap=codethread
qmk config user.keyboard=preonic/rev3_drop
```

```sh
qmk compile
```

This can be done in one step, but it is better to preconfigure above

```sh
qmk compile -kb preonic/rev3_drop -km codethread
```

```sh
# put keyboard in boot mode
qmk compile && qmk flash
```

## Links

-   [key macros](https://getreuer.info/posts/keyboards/macros/index.html)
