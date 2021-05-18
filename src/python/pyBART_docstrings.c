
#if PY_MAJOR_VERSION >= 3
#define add_doc(name, string) PyDoc_STRVAR(name, string)
#else
#define add_doc(name, string) static const char name[] = string;
#endif /* PY_MAJOR_VERSION >= 3 */

add_doc(pyBART_module_name, "pyBART");
add_doc(pyBART_module_doc,
	"pyBART\n"
	"======\n"
	"\n"
	"Provides easy access to BART's functionalities from within Python\n"
	"\n"
	"How to use the documentation\n"
	"----------------------------\n"
	"Documentation is available through docstrings provided with the\n"
	"code.\n"
	"\n"
	"Use the built-in ``help`` function to view a function's docstring::\n"
	"\n"
	"  >>> help(pyBART.bart)\n"
	"\n"
	"The docstring examples assume that `numpy` has been imported as `np`::\n"
	"\n"
	"  >>> import numpy as np\n"
	"\n"
	"Code snippets are indicated by three greater-than signs::\n"
	"\n"
	"  >>> x = 42\n"
	"  >>> x = x + 1\n"
	"\n"
	"Cleaning up in-memory data\n"
	"--------------------------\n"
	"After doing some processing using pyBART, some data may remain in\n"
	"'in-memory' CFL files and/or some memory may be mapped from\n"
	"locations on disk (from regular CFL files).\n"
	"In order to properly cleanup and free those memory locations, you\n"
	"need to call the cleanup_memory() function from pyBART::\n"
	"\n"
	"  >>> pyBART.cleanup_memory()\n"
	"\n"
	"Useful constants\n"
	"----------------\n"
	"\n"
	"Constants related to debug levels:\n"
	"  - DP_UNSET (-1)\n"
	"  - DP_ERROR\n"
	"  - DP_WARN\n"
	"  - DP_INFO\n"
	"  - DP_DEBUG1\n"
	"  - DP_DEBUG2\n"
	"  - DP_DEBUG3\n"
	"  - DP_DEBUG4\n"
	"  - DP_TRACE\n"
	"  - DP_ALL\n");

add_doc(call_bart_docstring,
	"pyBART.bart(command_line) -> string or int\n"
	"--\n\n"
	"Execute a BART command\n"
	"\n"
	"Parameters\n"
	"----------\n"
	"command_line : str\n"
	"    BART command line to execute\n"
	"\n"
	"Returns\n"
	"-------\n"
	"result : string or int\n"
	"    Output of the command or return value of the BART main function\n"
	"    The list of functions outputting strings is listed below:\n"
	"      - bitmask\n"
	"      - estdelay\n"
	"      - estdims\n"
	"      - estshift\n"
	"      - estvar\n"
	"      - nrmse\n"
	"      - sdot\n"
	"      - show\n"
	"      - version\n"
	"\n"
	"All other commands will result in an int being returned.\n"
	"\n"
	"Examples\n"
	"--------\n"
	">>> pyBART.bart('phantom -x 64 output')");
add_doc(bart_subcommand_docstring,
	"pyBART.<command>(command_line) -> string or int\n"
	"--\n\n"
	"Execute the <command> BART command\n"
	"This is effectively identical to calling pyBART.bart('<command> ...')\n"
	"\n"
	"See also help for pyBART.bart()");
add_doc(cleanup_memory_docstring,
	"pyBART.cleanup_memory()\n"
	"--\n\n"
	"Cleanup pyBART's internal memory database as well as close any \n"
	"remaining mapped memory locations (from CFL files on disk).\n"
	"\n"
	"Parameters\n"
	"----------\n"
	"None\n"
	"\n"
	"Note\n"
	"----\n"
	"After calling this function, all Python object pointing to any CFL\n"
	"files (in-memory or not) will be invalidated!\n");
add_doc(load_cfl_python_docstring,
	"pyBART.load_cfl(name) -> numpy.ndarray\n"
	"--\n\n"
	"Load some CFL file and return the data as an NumPy.ndarray.\n"
	"\n"
	"Parameters\n"
	"----------\n"
	"name : str\n"
	"    Name of CFL file (see Note below)\n"
	"\n"
	"Returns\n"
	"-------\n"
	"out : numpy.ndarray\n"
	"    Data contained in the CFL file\n"
	"\n"
	"\n"
	"Note\n"
	"----\n"
	"If pyBART is compiled with -DMEMONLY_CFL (CMake option: BART_MEMONLY_CFL)\n"
	"only in-memory CFL files can be read using this function.\n"
	"\n"
	"Raises\n"
	"------\n"
	"RuntimeError\n"
	"    Raised if the file does not exist or an error occurs while reading it.\n"
	"      \n"
	"Examples\n"
	"--------\n"
	">>> a = np.array([ [0,1,2], [3,4,5] ])\n"
	">>> pyBART.register_memory('test.mem', a.astype(np.complex64))\n"
	">>> b = pyBART.load_cfl('test.mem')\n");
add_doc(register_python_memory_docstring,
	"pyBART.register_memory(name, data)\n"
	"--\n\n"
	"Register some NumPy data for later use with pyBART\n"
	"\n"
	"Parameters\n"
	"----------\n"
	"name : str\n"
	"    Name of in-memory CFL file\n"
	"data : numpy.ndarray (with dtype=numpy.complex64)\n"
	"    Data to transfer to pyBART\n"
	"\n"
	"Raises\n"
	"------\n"
	"TypeError\n"
	"    Raised when:\n"
	"      - `data` is not of type numpy.ndarray\n"
	"      - `data` is not an array of complex floats (dtype = numpy.complex64)\n"
	"        In that case, use a.asstype(numpy.complex64)\n"
	"\n"
	"RuntimeError\n"
	"    Raised if `name` is empty or if getting the data from NumPy fails\n"
	"\n"
	"Examples\n"
	"--------\n"
	">>> a = np.array([ [0,1,2], [3,4,5] ])\n"
	">>> pyBART.register_memory('test.mem', a.astype(np.complex64))");
add_doc(get_debug_level_docstring,
	"pyBART.get_debug_level() -> int\n"
	"--\n\n"
	"Returns the current debug level\n"
	"\n"
	"Parameters\n"
	"----------\n"
	"None\n"
	"\n"
	"Returns\n"
	"-------\n"
	"result : int\n"
	"    The value of result is one of:\n"
	"      - pyBART.DP_UNSET\n"
	"      - pyBART.DP_ERROR\n"
	"      - pyBART.DP_WARN\n"
	"      - pyBART.DP_INFO\n"
	"      - pyBART.DP_DEBUG1\n"
	"      - pyBART.DP_DEBUG2\n"
	"      - pyBART.DP_DEBUG3\n"
	"      - pyBART.DP_DEBUG4\n"
	"      - pyBART.DP_TRACE\n"
	"      - pyBART.DP_ALL\n"
	"\n"
	"Note\n"
	"----\n"
	"DP_UNSET is only returned if no value was previously set\n"
	"\n"
	"Examples\n"
	"--------\n"
	">>> d = pyBART.get_debug_level()");
add_doc(set_debug_level_int_docstring,
	"pyBART.set_debug_level(level)\n"
	"--\n\n"
	"Sets the current debug level\n"
	"\n"
	"Parameters\n"
	"----------\n"
	"level : int or pyBART constant\n"
	"    New value for the debug level\n"
	"\n"
	"Note\n"
	"----\n"
	"To reset the debug level, pass pyBART.DP_UNSET or -1 to this function\n"
	"\n"
	"List of available pyBART constants for the debug level:\n"
	"  - pyBART.DP_UNSET\n"
	"  - pyBART.DP_ERROR\n"
	"  - pyBART.DP_WARN\n"
	"  - pyBART.DP_INFO\n"
	"  - pyBART.DP_DEBUG1\n"
	"  - pyBART.DP_DEBUG2\n"
	"  - pyBART.DP_DEBUG3\n"
	"  - pyBART.DP_DEBUG4\n"
	"  - pyBART.DP_TRACE\n"
	"  - pyBART.DP_ALL\n"
	"\n"
	"Examples\n"
	"--------\n"
	">>> pyBART.set_debug_level(2)\n"
	">>> pyBART.set_debug_level(pyBART.DP_INFO)");
add_doc(set_debug_level_float_docstring,
	"pyBART.set_debug_level(level)\n"
	"--\n\n"
	"Sets the current debug level\n"
	"\n"
	"Parameters\n"
	"----------\n"
	"level : float\n"
	"    New value for the debug level (must be a whole number)\n"
	"\n"
	"Note\n"
	"----\n"
	"To reset the debug level, pass -1 to this function\n"
	"\n"
	"Examples\n"
	"--------\n"
	">>> pyBART.set_debug_level(-1.0)");
add_doc(set_debug_level_str_docstring,
	"pyBART.set_debug_level(level)\n"
	"--\n\n"
	"Sets the current debug level\n"
	"\n"
	"Parameters\n"
	"----------\n"
	"level : str\n"
	"    New value for the debug level. Must be one of:\n"
	"      - 'DP_UNSET'\n"
	"      - 'DP_ERROR'\n"
	"      - 'DP_WARN'\n"
	"      - 'DP_INFO'\n"
	"      - 'DP_DEBUG1'\n"
	"      - 'DP_DEBUG2'\n"
	"      - 'DP_DEBUG3'\n"
	"      - 'DP_DEBUG4'\n"
	"      - 'DP_TRACE'\n"
	"      - 'DP_ALL'\n"
	"\n"
	"Note\n"
	"----\n"
	"To reset the debug level, pass pyBART.DP_UNSET or -1 to this function\n"
	"\n"
	"Examples\n"
	"--------\n"
	">>> pyBART.set_debug_level('DP_INFO')");