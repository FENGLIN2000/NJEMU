#ifndef COMMON_GAME_PACING_DEFAULTS_H
#define COMMON_GAME_PACING_DEFAULTS_H

#include "common/emulator_options.h"

/* Consoles with fixed display timing default to synchronized presentation.
 * PS2 also needs the software 60 Hz limiter: VBlank waiting is presentation
 * pacing only (see common/frame_pacing.h) and does not reliably hold emulation
 * speed on interlaced 480i output. PSP keeps the legacy no-software-throttle
 * default. Other platforms retain their per-core defaults (CPS2 VSync on;
 * all other cores VSync off).
 * These values apply only when creating/loading a game's default config. */
#if defined(PS2)
#define NJEMU_DEFAULT_VSYNC VSYNC_MODE_ON
#define NJEMU_DEFAULT_FRAME_LIMIT 1
#elif defined(PSP)
#define NJEMU_DEFAULT_VSYNC VSYNC_MODE_ON
#define NJEMU_DEFAULT_FRAME_LIMIT 0
#elif defined(BUILD_CPS2)
#define NJEMU_DEFAULT_VSYNC VSYNC_MODE_ON
#define NJEMU_DEFAULT_FRAME_LIMIT 1
#else
#define NJEMU_DEFAULT_VSYNC VSYNC_MODE_OFF
#define NJEMU_DEFAULT_FRAME_LIMIT 1
#endif

#endif /* COMMON_GAME_PACING_DEFAULTS_H */
