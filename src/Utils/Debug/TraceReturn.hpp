#ifndef TRACE_DEBUG_HPP
#define TRACE_DEBUG_HPP

#include "Debug.hpp"

// Replacement for standard 'return' statement
// Prints error message if rc != 0

# define TraceReturn(rc, message) do{ \
    if( rc ) Error( "TraceReturn (Code:" << rc << "): " << __FUNCTION__ << " (" << __FILENAME__ << ":" << __LINE__ << "):  " << message ); \
    return rc; \
    }while(0)

// Linetracing debug macro
// Prints error message whenever called
#define TraceError( message) do{ \
    Error( "TraceError: " << __FUNCTION__ << " (" << __FILENAME__ << ":" << __LINE__ << "):  " << message ); \
    }while(0)

#endif // TRACE_DEBUG_HPP 
