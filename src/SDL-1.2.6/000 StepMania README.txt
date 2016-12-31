Changes:

* These have been upstreamed and are awaiting a reply:

Fix sending a resize event after restoring from a maximize.

Libraries are output to lib/ instead of VisualC/SDL/{Debug,Release}.
That's where it is by default, so that's where the build puts it.

SDL builds "SDLd.dll,lib" for debugging, and we link against it conditionally.  This
makes debugging a lot easier.

* These haven't been upstreamed yet due to complexity:

Added refresh rate support (SDL_SM_SetRefreshRate) and support for
changing video mode without resetting OpenGL (SDL_SM_ChangeVideoMode_OpenGL).
These are platform-specific and SM will use them conditionally.

* These won't be upstreamed:

Turned off incremental links, since it ends up in the SM directory, and it's
just more clutter--the SDL links really fast anyway.

SDL DLLs are output to ../.. (the top-level SM directory).  That's where SM
is, so you don't have to copy the DLL every time you change something
in the SDL source (and possibly forget).

Removed ENABLE_DIRECTX and added DISABLE_JOYSTICK.
Removed all SDL_dx5*.

** Important:
Be careful about runtime linkage.  I've changed all links to use
multithreaded static; this keeps things from pulling in the VC7
runtimes, but adds a bit to each DLL.  The DLL itself is about 300k.
Also, SDL_image has a debug version that links against the SDL debug.  I
havn't actually had to debug it yet, so it's not really important;
however, if that's not done then it'll pull in both the debug and
non-debug version of the SDL (one for SM, one for image), which is
ugly and might cause problems.

-glenn
