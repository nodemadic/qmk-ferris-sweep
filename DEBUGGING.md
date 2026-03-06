# Debugging Notes (2026-03-06)

## Known Firmware Bug: LGUI() on LT() Layers

`LGUI(KC_X)` keycodes do NOT work on layers activated by `LT()`. Tested with `wev`:

- **MOD layer** `LGUI(KC_G)` at G position: sends only `Super_L press/release` with no G keycode
- **SWAY layer** `LGUI(KC_M)` at M position: same — only `Super_L`, no M
- **SWAY layer** existing keys like `SW_FOCL = LGUI(KC_H)`: likely same issue (untested individually but all SWAY LGUI macros are suspect)

This means all `LGUI()`, `SGUI()`, `LCTL()` etc. modifier-wrapped keycodes on LT() layers may be broken. Plain keycodes (like F-keys on FUNC layer) work fine.

### What works
- **Base layer keys**: all normal keypresses
- **NAV layer (Hold Space)**: arrows (J/K mapped to Down/Up confirmed), hold-modifiers (KC_LGUI at F position sends real Super hold), clipboard shortcuts
- **NAV hold-modifier combos**: Hold Space + Hold F (Super) + tap G = Super+G. Super is held properly, G arrives while Super is depressed. Sway sees this as $mod+g.
- **FUNC tri-layer (Hold Space + Hold Bksp)**: F10 confirmed via wev. Tri-layer activates correctly.
- **One-shot modifiers (MOD layer)**: fire correctly but as sequential events (Super press/release, then target key), not simultaneous. Sway cannot match these as $mod+key bindings.

### Root cause (suspected)
QMK `LGUI(KC_G)` is a modified basic keycode that embeds the modifier in the upper bits of the 16-bit keycode. When placed on an `LT()` layer, there may be a bit collision or processing issue that strips the base keycode and only sends the modifier. This needs investigation — possibly a QMK version issue or a known limitation.

### Workaround: Voice Dictation Keybind
Since `LGUI(KC_G)` on MOD/SWAY layers doesn't work, dictation uses the NAV layer's real modifier holds:

**Hold Space + Hold F + tap G** = Super+G (works correctly)

Sway config: `bindsym $mod+g exec /home/isaac/.local/bin/dictate-toggle`

This is a 3-key combo on the left hand:
1. Left inner thumb holds Space (NAV layer active)
2. Left index holds F (KC_LGUI = real Super modifier held)
3. Left middle taps G (transparent to base KC_G, sent with Super held)

## Dictation System Setup

### Components
- **Daemon**: `~/.local/share/dictate/dictate_daemon.py` — faster-whisper (base.en model on CPU), listens on Unix socket
- **Config**: `~/.local/share/dictate/config.py` — model size, sample rate, paths
- **Service**: `~/.config/systemd/user/dictate.service` — systemd user service, auto-starts
- **Toggle script**: `~/.local/bin/dictate-toggle` — sends TOGGLE to daemon socket, includes 1-second debounce
- **Launcher**: `~/.local/bin/dictate-daemon` — runs daemon via venv python

### Sway binding
```
bindsym $mod+g exec /home/isaac/.local/bin/dictate-toggle
```

### Fixes applied (2026-03-06)

1. **Sway config: full path** — changed `exec dictate-toggle` to `exec /home/isaac/.local/bin/dictate-toggle` because Sway's exec doesn't inherit shell PATH.

2. **WAYLAND_DISPLAY in service** — added `Environment=WAYLAND_DISPLAY=wayland-1` to `dictate.service`. Without this, `wtype` and `wl-copy` inside the daemon can't connect to the compositor, so transcribed text is never typed or copied.

3. **Debounce in toggle script** — added 1-second lockfile debounce to `dictate-toggle`. The keyboard combo was firing the binding twice in rapid succession, causing an instant start+stop (0.02s recording) with no time to speak.

4. **Notification daemon missing** — `mako` is referenced in Sway config (`exec mako`) but not installed. Dictation notifications (Recording.../Transcribing.../Typed:...) are silently failing. Install mako to see them.

### Firmware changes in keymap.c
- **SWAY layer**: added `LGUI(KC_M)` at M position (right bottom row) — intended for dictate but doesn't work due to the LGUI-on-LT bug above. Left in place for future fix.
- **SYM layer**: `KC_PIPE` and `KC_QUES` swapped positions on bottom-right row.

### TODO
- [ ] Install mako for notifications (`sudo dnf install mako`)
- [ ] Investigate why LGUI() keycodes fail on LT() layers — check QMK version, test with QMK's `tap_code16()` in `process_record_user` as alternative
- [ ] Consider replacing all SWAY layer LGUI() macros with custom keycodes handled in `process_record_user` if the bug affects them too
- [ ] Test if SWAY layer window management actually works (workspace switching, focus, kill) — if not, the entire SWAY layer needs the same fix
