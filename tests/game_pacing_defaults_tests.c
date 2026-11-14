#include <assert.h>

#include "common/game_pacing_defaults.h"

int main(void)
{
#if defined(PS2)
    /* PS2 needs the software 60 Hz limiter to hold emulation speed on 480i;
     * VBlank waiting only paces presentation, not the emulated machine. */
    assert(NJEMU_DEFAULT_VSYNC == VSYNC_MODE_ON);
    assert(NJEMU_DEFAULT_FRAME_LIMIT == 1);
#elif defined(PSP)
    /* PSP keeps the legacy synchronized flips without a software throttle. */
    assert(NJEMU_DEFAULT_VSYNC == VSYNC_MODE_ON);
    assert(NJEMU_DEFAULT_FRAME_LIMIT == 0);
#elif defined(BUILD_CPS2)
    /* Desktop/Vita keep the CPS2-specific VSync-on default. */
    assert(NJEMU_DEFAULT_VSYNC == VSYNC_MODE_ON);
    assert(NJEMU_DEFAULT_FRAME_LIMIT == 1);
#else
    /* Other Desktop/Vita cores retain their historical defaults. */
    assert(NJEMU_DEFAULT_VSYNC == VSYNC_MODE_OFF);
    assert(NJEMU_DEFAULT_FRAME_LIMIT == 1);
#endif
    return 0;
}
