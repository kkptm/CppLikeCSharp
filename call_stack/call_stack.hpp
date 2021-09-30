/* Copyright (c) 2009, Fredrik Orderud
 License: BSD licence (http://www.opensource.org/licenses/bsd-license.php) */

#pragma once
/// @cond
#include <string>
#include <vector>
#include <sstream>

// Specify the stack frame methods to skip
#if __clang__
static const int StackFrameInternalMethodsToSkip = 4L;
#elif __GNUC__
static const int StackFrameInternalMethodsToSkip = 2L;
#else
static const int StackFrameInternalMethodsToSkip = 4L;
#endif

namespace stacktrace
{
  /** Call-stack entry datastructure. */
  struct entry
  {
    /** Default constructor that clears all fields. */
    entry () : file(""), line(0), function(""), offset(0), column(0)
    {
    }
    
    std::string file;     ///< filename
    size_t      line;     ///< line number
    std::string function; ///< name of function or method
    size_t      offset;   ///< offset
    size_t      column;   ///< column number
    
    /** Serialize entry into a text string. */
    std::string to_string () const
    {
      std::ostringstream os;
      os << file << " (" << line << "): " << function;
      return os.str();
    }
  };
  
  /** Stack-trace base class, for retrieving the current call-stack. */
  class call_stack
  {
  public:
    /** Stack-trace consructor.
     \param num_discard - number of stack entries to discard at the top. */
    explicit call_stack (const size_t num_discard = 0);
    
    virtual ~call_stack () throw();
    
    /** Serializes the entire call-stack into a text string. */
    std::string to_string () const
    {
      std::ostringstream os;
      for (size_t i = 0; i < stack.size(); i++)
        os << stack[i].to_string() << std::endl;
      return os.str();
    }
    
    /** Call stack. */
    std::vector<entry> stack;
  };
} // namespace stacktrace
/// @endcond
