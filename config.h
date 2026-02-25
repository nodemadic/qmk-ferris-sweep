#pragma once

// How long a key must be held to register as a hold (ms)
#define TAPPING_TERM 200

// If you tap a dual-function key then quickly tap-hold it again,
// it repeats the tap instead of activating the hold.
// Prevents accidental layer activation when double-tapping Space, etc.
#define QUICK_TAP_TERM 120

// One-shot modifier timeout: how long an OSM stays armed (ms)
#define ONESHOT_TIMEOUT 3000

// Number of combos defined in keymap
#define COMBO_COUNT 1
