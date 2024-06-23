# My Custom Preonic layout

test comit

## Philosophy

## features

## notes

### Alt / Meta

24/02/11: currently trying it under the right thumb as a modifer with space - but using a whole layer, which seems to be far more reliable as a layer toggle than a modifer

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

```nu
sleep 3sec; qmk compile; qmk flash
```

## Update

```sh
git remote add upstream git@github.com:qmk/qmk_firmware.git
git fetch upstream
git rebase upstream/master
```

## Links

-   [key macros](https://getreuer.info/posts/keyboards/macros/index.html)
