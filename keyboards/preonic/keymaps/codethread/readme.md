# My Custom Preonic layout

## Philosophy

## features

## notes

### Alt / Meta

want somewhere better for this

backspace under right thumb, so need alt on left?

# The default Preonic layout - largely based on the Planck's

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
sleep 5 && qmk flash
```
