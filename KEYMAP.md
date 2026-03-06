# Ferris Sweep Keymap

QMK firmware for a wired Ferris Sweep (34 keys).
7-layer layout with no home row mods — uses Callum-style one-shot modifiers instead.

## Design Principles

- **No home row mods** — eliminates accidental modifier triggers during prose
- **Callum-style one-shot modifiers** on a dedicated layer (hold Bksp)
- **Hold-modifiers on NAV/NUM layers** for sustained combos (Shift+Arrow, Ctrl+Arrow)
- **Space on left thumb** (most natural resting position)
- **True numpad** on right hand, activated from opposite (left) hand
- **Dedicated Sway layer** with vim-style focus (h/j/k/l)
- **Caps Word** for CONSTANT_NAMES (activate from FUNC layer)

## How Layers Work

| Activation | Tap | Hold |
|---|---|---|
| Left outer thumb | Escape | **NUM** layer (numpad on opposite hand) |
| Left inner thumb | Space | **NAV** layer (arrows, navigation) |
| Right inner thumb | Backspace | **MOD** layer (one-shot Ctrl/Alt/Super/Shift) |
| Right outer thumb | Enter | **SWAY** layer (window management) |
| Right home pinky | Tab | **SYM** layer (symbols) |
| Right bottom pinky | Shift | Shift (dedicated) |
| Both inner thumbs | — | **FUNC** layer (F-keys, media, Caps Word) |

## Combos

| Keys | Action |
|---|---|
| Q + P (simultaneous) | Types `nodemadic` |

## Layer 0: BASE (QWERTY)

```
 ┌───────┬───────┬───────┬───────┬───────┐   ┌───────┬───────┬───────┬───────┬───────┐
 │   Q   │   W   │   E   │   R   │   T   │   │   Y   │   U   │   I   │   O   │   P   │
 ├───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┤
 │   A   │   S   │   D   │   F   │   G   │   │   H   │   J   │   K   │   L   │  Tab  │
 ├───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┤
 │   Z   │   X   │   C   │   V   │   B   │   │   N   │   M   │   ,   │   .   │ Shift │
 └───────┴───────┴───────┼───────┼───────┤   ├───────┼───────┼───────┴───────┴───────┘
                         │  Esc  │ Space │   │ Bksp  │ Enter │
                         │ (NUM) │ (NAV) │   │ (MOD) │(SWAY) │
                         └───────┴───────┘   └───────┴───────┘
```

## Layer 1: NAV (Hold Space)

Left hand home row has hold-modifiers for combos like Shift+Arrow (select text),
Ctrl+Arrow (word jump), or Ctrl+Shift+Arrow (select word).
Bottom row has common clipboard shortcuts (Undo, Cut, Copy, Paste).

```
 ┌───────┬───────┬───────┬───────┬───────┐   ┌───────┬───────┬───────┬───────┬───────┐
 │       │       │       │       │       │   │       │       │       │       │       │
 ├───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┤
 │ Shift │  Alt  │ Ctrl  │ Super │       │   │   ←   │   ↓   │   ↑   │   →   │       │
 ├───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┤
 │ Ctl+Z │ Ctl+X │ Ctl+C │ Ctl+V │  Del  │   │ Home  │ PgDn  │ PgUp  │  End  │       │
 └───────┴───────┴───────┼───────┼───────┤   ├───────┼───────┼───────┴───────┴───────┘
                         │       │▓▓▓▓▓▓▓│   │       │       │
                         └───────┴───────┘   └───────┴───────┘
                                  (held)
```

## Layer 2: NUM (Hold Esc)

True numpad on right hand (7-8-9 / 4-5-6 / 1-2-3) with 0 on the right outer thumb.
Left hand provides hold-modifiers for combos with numbers.

```
 ┌───────┬───────┬───────┬───────┬───────┐   ┌───────┬───────┬───────┬───────┬───────┐
 │       │       │       │       │       │   │   /   │   7   │   8   │   9   │   -   │
 ├───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┤
 │ Shift │  Alt  │ Ctrl  │ Super │   =   │   │   *   │   4   │   5   │   6   │   +   │
 ├───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┤
 │       │       │       │       │       │   │       │   1   │   2   │   3   │   .   │
 └───────┴───────┴───────┼───────┼───────┤   ├───────┼───────┼───────┴───────┴───────┘
                         │▓▓▓▓▓▓▓│       │   │       │   0   │
                         └───────┴───────┘   └───────┴───────┘
                          (held)
```

## Layer 3: MOD (Hold Bksp) — Callum One-Shot Modifiers

Tap a modifier to arm it, then release Bksp and press the target key.
The modifier applies to the next keypress only, then clears.
Tap a modifier twice to lock it (tap again to unlock).
Mirrored on both hands so you can always use the opposite hand for the target key.

```
 ┌───────┬───────┬───────┬───────┬───────┐   ┌───────┬───────┬───────┬───────┬───────┐
 │       │       │       │       │       │   │       │       │       │       │       │
 ├───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┤
 │ Shift │  Alt  │ Ctrl  │ Super │Sup+G  │   │       │ Super │ Ctrl  │  Alt  │ Shift │
 ├───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┤
 │       │       │       │       │       │   │       │       │       │       │       │
 └───────┴───────┴───────┼───────┼───────┤   ├───────┼───────┼───────┴───────┴───────┘
                         │       │       │   │▓▓▓▓▓▓▓│       │
                         └───────┴───────┘   └───────┴───────┘
                                              (held)
```

**Example — Ctrl+C:**
1. Hold Bksp (MOD layer active)
2. Tap K position (one-shot Ctrl armed — use right hand to avoid same-finger with C)
3. Release Bksp
4. Tap C → sends Ctrl+C, one-shot clears

**Example — Ctrl+Shift+V:**
1. Hold Bksp (MOD layer active)
2. Tap Ctrl position, then tap Shift position (both armed)
3. Release Bksp
4. Tap V → sends Ctrl+Shift+V, both clear

## Layer 4: SWAY (Hold Enter) — Window Manager

Hold Shift (right bottom pinky) to modify actions:
- Workspace keys + Shift = **move window** to that workspace
- Focus keys + Shift = **move window** in that direction

```
 ┌───────┬───────┬───────┬───────┬───────┐   ┌───────┬───────┬───────┬───────┬───────┐
 │  WS1  │  WS2  │  WS3  │  WS4  │  WS5  │   │  WS6  │  WS7  │  WS8  │  WS9  │       │
 ├───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┤
 │ Kill  │Launch │ Full  │ Float │Resize │   │Foc ←  │Foc ↓  │Foc ↑  │Foc →  │ Exit  │
 ├───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┤
 │Reload │ Lock  │ Clip  │SplitV │SplitH │   │       │       │       │       │ Shift │
 └───────┴───────┴───────┼───────┼───────┤   ├───────┼───────┼───────┴───────┴───────┘
                         │ Term  │       │   │       │▓▓▓▓▓▓▓│
                         └───────┴───────┘   └───────┴───────┘
                                                      (held)
```

| Key | Action | + Shift |
|---|---|---|
| WS1-WS9 | Switch to workspace | Move window to workspace |
| Foc ←↓↑→ | Focus window (Super+h/j/k/l) | Move window (Super+Shift+h/j/k/l) |
| Kill | Kill focused window (Super+Shift+Q) | — |
| Launch | App launcher (Super+D) | — |
| Full | Toggle fullscreen (Super+F) | — |
| Float | Toggle floating (Super+Shift+Space) | — |
| Resize | Enter resize mode (Super+R) | — |
| SplitV/H | Split vertical/horizontal | — |
| Term | Open terminal (Super+Enter) | — |
| Reload | Reload sway config (Super+Shift+C) | — |
| Lock | Lock screen (Super+Escape → swaylock) | — |
| Clip | Clipboard history (Super+P → cliphist) | — |
| Exit | Exit Sway (Super+Shift+E) | — |

## Layer 5: SYM (Hold Tab) — Symbols

Left home row has the most-used symbols: `'`, `"`, `(`, `)`.
Brackets `[ ] { }` are on the bottom row (less frequent).

```
 ┌───────┬───────┬───────┬───────┬───────┐   ┌───────┬───────┬───────┬───────┬───────┐
 │   !   │   @   │   #   │   $   │   %   │   │   ^   │   &   │   *   │   `   │   ~   │
 ├───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┤
 │   '   │   "   │   (   │   )   │   ;   │   │   /   │   -   │   =   │   :   │▓▓▓▓▓▓▓│
 ├───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┤
 │   [   │   ]   │   {   │   }   │       │   │   \   │   _   │   +   │   ?   │   |   │
 └───────┴───────┴───────┼───────┼───────┤   ├───────┼───────┼───────┴───────┴───────┘
                         │       │       │   │       │       │
                         └───────┴───────┘   └───────┴───────┘
                                                      (held)
```

## Layer 6: FUNC (Hold Space + Bksp — Tri-Layer)

Activated by holding both inner thumb keys simultaneously.

```
 ┌───────┬───────┬───────┬───────┬───────┐   ┌───────┬───────┬───────┬───────┬───────┐
 │  F1   │  F2   │  F3   │  F4   │  F5   │   │  F6   │  F7   │  F8   │  F9   │  F10  │
 ├───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┤
 │  F11  │  F12  │ PrtSc │CapsWd │       │   │       │BRI UP │VOL UP │       │ Play  │
 ├───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┤
 │       │       │       │       │ BOOT  │   │       │BRI DN │VOL DN │ Mute  │       │
 └───────┴───────┴───────┼───────┼───────┤   ├───────┼───────┼───────┴───────┴───────┘
                         │       │▓▓▓▓▓▓▓│   │▓▓▓▓▓▓▓│       │
                         └───────┴───────┘   └───────┴───────┘
                                  (held)      (held)
```

## Common Operations Cheat Sheet

| Action | How |
|---|---|
| Capital letter (left hand) | Shift (right pinky) + letter |
| Capital letter (right hand) | Shift + letter (same hand, different finger) |
| Capital P | MOD: hold Bksp → tap Shift → release → tap P |
| Esc (Vim normal mode) | Tap left outer thumb |
| Arrow keys | Hold Space + h/j/k/l |
| Select text | Hold Space + A(Shift) + arrow |
| Word jump | Hold Space + D(Ctrl) + arrow |
| Select word | Hold Space + A(Shift) + D(Ctrl) + arrow |
| Ctrl+C | MOD: hold Bksp → tap K(Ctrl) → release → tap C |
| Ctrl+S | MOD: hold Bksp → tap K(Ctrl) → release → tap S |
| Ctrl+Z | MOD: hold Bksp → tap K(Ctrl) → release → tap Z |
| Undo/Cut/Copy/Paste | Hold Space + Z/X/C/V (NAV bottom row) |
| Type `:` (Vim command) | Hold Tab + L |
| Type `/` (Vim search) | Hold Tab + H |
| Type `'` or `"` | Hold Tab + A or S |
| Type `(` or `)` | Hold Tab + D or F |
| Switch workspace 3 | Hold Enter + E |
| Move window to WS 3 | Hold Enter + Shift + E |
| Focus window left | Hold Enter + H |
| Move window left | Hold Enter + Shift + H |
| Open terminal | Hold Enter + Esc |
| Kill window | Hold Enter + A |
| App launcher | Hold Enter + S |
| Resize mode | Hold Enter + G |
| Lock screen | Hold Enter + X |
| Clipboard history | Hold Enter + C |
| Exit Sway | Hold Enter + Tab |
| Numbers | Hold Esc + right hand numpad (0 on right outer thumb) |
| Type username combo | Tap Q + P simultaneously |
| F-keys | Hold Space + Bksp + top row |
| Print Screen | Hold Space + Bksp + D |
| Caps Word | Hold Space + Bksp + F |
| Bootloader | Hold Space + Bksp + B |

## Matching Sway Config

This keymap assumes vim-style Sway bindings. Add to `~/.config/sway/config`:

```
set $mod Mod4

# Focus (vim-style)
bindsym $mod+h focus left
bindsym $mod+j focus down
bindsym $mod+k focus up
bindsym $mod+l focus right

# Move window (vim-style)
bindsym $mod+Shift+h move left
bindsym $mod+Shift+j move down
bindsym $mod+Shift+k move up
bindsym $mod+Shift+l move right

# Workspaces
bindsym $mod+1 workspace number 1
bindsym $mod+2 workspace number 2
bindsym $mod+3 workspace number 3
bindsym $mod+4 workspace number 4
bindsym $mod+5 workspace number 5
bindsym $mod+6 workspace number 6
bindsym $mod+7 workspace number 7
bindsym $mod+8 workspace number 8
bindsym $mod+9 workspace number 9

# Move window to workspace
bindsym $mod+Shift+1 move container to workspace number 1
bindsym $mod+Shift+2 move container to workspace number 2
bindsym $mod+Shift+3 move container to workspace number 3
bindsym $mod+Shift+4 move container to workspace number 4
bindsym $mod+Shift+5 move container to workspace number 5
bindsym $mod+Shift+6 move container to workspace number 6
bindsym $mod+Shift+7 move container to workspace number 7
bindsym $mod+Shift+8 move container to workspace number 8
bindsym $mod+Shift+9 move container to workspace number 9

# Window management
bindsym $mod+Shift+q kill
bindsym $mod+d exec wofi --show drun
bindsym $mod+f fullscreen toggle
bindsym $mod+Shift+space floating toggle
bindsym $mod+t splitv
bindsym $mod+b splith
bindsym $mod+r mode "resize"
bindsym $mod+Shift+e exec swaynag -t warning -m 'Exit Sway?' -B 'Yes' 'swaymsg exit'
bindsym $mod+Return exec foot
bindsym $mod+Shift+c reload

# Lock screen
bindsym $mod+Escape exec swaylock -f -c 000000

# Clipboard history (requires: exec wl-paste --watch cliphist store)
bindsym $mod+p exec cliphist list | wofi --dmenu | cliphist decode | wl-copy

# Screenshots
bindsym Print exec grimshot save screen
bindsym $mod+Print exec grimshot save area
```

### Key Notes

- **BOOT** = Enter bootloader mode for flashing firmware (no need to short pins)
- **CapsWd** = Toggle Caps Word (types in CAPS until you hit space or punctuation)
- **▓▓▓▓▓▓▓** = the thumb key being held to activate this layer
- Blank keys are transparent — they pass through to the layer below
