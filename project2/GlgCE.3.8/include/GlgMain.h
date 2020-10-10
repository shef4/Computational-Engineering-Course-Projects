/*---------------------------------------------------------------------------
| This file defines platform-specific entry point and may be included when
| the generic GLG API is used.
*/

#include "GlgApi.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Prototype for GlgMain */ 
int GlgMain( int argc, char * argv[], GlgAppContext context );

#ifdef __cplusplus
}
#endif

#ifdef MS_WINDOWS

#include <windows.h>

/* MS Windows entry point. */
int WINAPI WinMain( _In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
                    _In_ LPSTR lpCmdLine, _In_ int nCmdShow )
{
   GlgAppContext AppContext;
   GlgObject args_array;
   int rval;
   GlgLong argc;
   char ** argv;
   
   args_array = GlgParseArgs( NULL, lpCmdLine, &argc, &argv );

   AppContext = GlgInit( False, (GlgAppContext)hInstance, (int) argc, argv );

   rval = GlgMain( (int) argc, argv, AppContext );

   GlgDropObject( args_array );
   GlgTerminate();
   return rval;
}

#else   /* X Windows */

/* X Windows entry point. */
int main( int argc, char *argv[] )
{
   return GlgMain( argc, argv, (GlgAppContext)0 );
}

#endif
